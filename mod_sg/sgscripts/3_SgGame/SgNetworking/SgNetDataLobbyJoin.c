// DESIGN_ID: 0001

/*
	"Pseudo abstract" SG network data class for joining a lobby 
*/
class SgNetDataLobbyJoin{}

/*
	SG network request data class for joining a lobby 
*/
class SgNetDataLobbyJoinRequest extends SgNetDataLobbyJoin 
{
	private string m_LobbyId; 					
	private string m_Password; 					
	
	// --------------------------------------
	
	void SgNetDataLobbyJoinRequest(string lobby_id, string password)
	{
		m_LobbyId = lobby_id;
		m_Password = password;
	}
	
	// ----------------------------------------
	// SETTERS
	void SetLobbyId(string lobby_id)
	{
		m_LobbyId = lobby_id;
	}
	void SetPassword(string password)
	{
		m_Password = password;
	}
}

/*
	SG network response data class for joining a lobby 
*/
class SgNetDataLobbyJoinResponse extends SgNetDataLobbyJoin
{
	private string m_JoinedPlayerUID;									// Player that entered the lobby
	private ref SgNetDataLobbyDetails m_LobbyDetails;					// Lobby details 
	
	// --------------------------------------
	// GETTERS
	string GetJoinedPlayerUID()
	{
		return m_JoinedPlayerUID;
	}	
	SgNetDataLobbyDetails GetLobbyDetails()
	{
		return m_LobbyDetails;
	}
	
}