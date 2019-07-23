// DESIGN_ID: 0001

/*
	"Pseudo abstract" SG network data class to start the game
*/
class SgNetDataLobbyGameStart{}

/*
	SG network request data class to start the game
*/
class SgNetDataLobbyGameStartRequest extends SgNetDataLobbyGameStart 
{	
	private string m_LobbyId;

	// ----------------------------------------
	
	void SgNetDataLobbyGameStartRequest(string lobby_id)
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
	SG network response data class to start the game
*/
class SgNetDataLobbyGameStartResponse extends SgNetDataLobbyGameStart{}