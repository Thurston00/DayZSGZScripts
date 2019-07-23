// DESIGN_ID: 0001

/*
	"Pseudo abstract" SG network data class for leaving a team
*/
class SgNetDataTeamLeave{}

/*
	SG network request data class for leaving a team
*/
class SgNetDataTeamLeaveRequest extends SgNetDataTeamLeave 
{	
	private string m_LobbyId;

	// ----------------------------------------
	
	void SgNetDataTeamLeaveRequest(string lobby_id)
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
	SG network response data class for leaving a team
*/
class SgNetDataTeamLeaveResponse extends SgNetDataTeamLeave
{	
	private string m_PlayerUID;

	// --------------------------------------
	// GETTERS
	
	string GetPlayerUID()
	{
		return m_PlayerUID;
	}
}