// DESIGN_ID: 0001

/*
	"Pseudo abstract" SG network data class for creating a new lobby 
*/
class SgNetDataLobbyCreate{}

/*
	SG network request data class for creating a new lobby 
*/
class SgNetDataLobbyCreateRequest extends SgNetDataLobbyCreate 
{
	private string m_LobbyName; 
	private SgETeamSize m_TeamSize;					
	private int m_PlaygroundId;						
	private string m_Password;						
	
	// --------------------------------------
	
	void SgNetDataLobbyCreateRequest(string lobby_name, SgETeamSize team_size, int playground_id, string password)
	{
		m_LobbyName = lobby_name;
		m_TeamSize = team_size;
		m_PlaygroundId = playground_id;
		m_Password = password;
	}
	
	// ----------------------------------------
	// SETTERS
	void SetLobbyName(string lobby_name)
	{
		m_LobbyName = lobby_name;
	}
	void SetTeamSize(SgETeamSize team_size)
	{
		m_TeamSize = team_size;
	}
	void SetPlaygroundId(int playground_id)
	{
		m_PlaygroundId = playground_id;
	}
	void SetPassword(string password)
	{
		m_Password = password;
	}
}

/*
	SG network response data class for creating a new lobby 
*/
class SgNetDataLobbyCreateResponse extends SgNetDataLobbyCreate
{
	private string m_LobbyId;
	private SgETeamSize m_TeamSize;
		
	// -------------------------------------------
	// GETTERS
	string GetLobbyId()
	{
		return m_LobbyId;
	}
	SgETeamSize GetTeamSize()
	{
		return m_TeamSize;
	}
}