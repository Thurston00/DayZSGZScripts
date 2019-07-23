// DESIGN_ID: 0001

/*
	"Pseudo abstract" SG network data class for reading a player
*/
class SgNetDataPlayerReady
{
	protected bool m_IsReady;
}

/*
	SG network request data class for reading a player
*/
class SgNetDataPlayerReadyRequest extends SgNetDataPlayerReady 
{	
	private string m_LobbyId;

	// ----------------------------------------
	
	void SgNetDataPlayerReadyRequest(string lobby_id, bool is_ready)
	{
		m_LobbyId = lobby_id;
		m_IsReady = is_ready;
	}
	
	// ----------------------------------------
	// SETTERS
	void SetLobbyId(string lobby_id)
	{
		m_LobbyId = lobby_id;
	}
	void SetReady(bool is_ready)
	{
		m_IsReady = is_ready;
	}
}

/*
	SG network response data class for reading a player
*/
class SgNetDataPlayerReadyResponse extends SgNetDataPlayerReady
{	
	private string m_PlayerUID;

	// --------------------------------------
	// GETTERS
	string GetPlayerUID()
	{
		return m_PlayerUID;
	}
	bool GetReady()
	{
		return m_IsReady;
	}
}