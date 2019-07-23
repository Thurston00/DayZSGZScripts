// DESIGN_ID: 0001

/*
	"Pseudo abstract" SG network data class for leaving a lobby 
*/
class SgNetDataLobbyLeave{}

/*
	SG network request data class for leaving a lobby 
*/
class SgNetDataLobbyLeaveRequest extends SgNetDataLobbyLeave 
{
	private string m_LobbyId; 				// 	Lobby id from where the client is leaving
	
	// --------------------------------------
	
	void SgNetDataLobbyLeaveRequest(string lobby_id)
	{
		m_LobbyId = lobby_id;
	}
	
	// ----------------------------------------
	// SETTERS
	void SetLobbyId(string lobby_id)
	{
		m_LobbyId = lobby_id;
	}
}

/*
	SG network response data class for leaving a lobby
*/
class SgNetDataLobbyLeaveResponse extends SgNetDataLobbyLeave
{
	private string m_PlayerUID;					// The player that left the lobby

	// --------------------------------------
	// GETTERS
	
	// Get the player id that left the lobby 
	string GetPlayerUID()
	{
		return m_PlayerUID;
	}
}