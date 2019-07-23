// DESIGN_ID: 0001

/*
	"Pseudo abstract" SG network data class for deleting a lobby 
*/
class SgNetDataLobbyDelete{}

/*
	SG network request data class for deleting a lobby 
*/
class SgNetDataLobbyDeleteRequest extends SgNetDataLobbyDelete 
{
	private string m_LobbyId; 					
	
	// --------------------------------------
	
	void SgNetDataLobbyDeleteRequest(string lobby_id)
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
	SG network response data class for deleting a lobby 
*/
class SgNetDataLobbyDeleteResponse extends SgNetDataLobbyDelete{}