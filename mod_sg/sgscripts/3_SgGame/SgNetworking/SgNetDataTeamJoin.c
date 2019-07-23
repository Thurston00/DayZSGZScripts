// DESIGN_ID: 0001

/*
	"Pseudo abstract" SG network data class for joining a team
*/
class SgNetDataTeamJoin
{
	protected int m_TeamIndex;
	protected int m_SlotIndex;					
}

/*
	SG network request data class for joining a team
*/
class SgNetDataTeamJoinRequest extends SgNetDataTeamJoin 
{	
	private string m_LobbyId;
	
	void SgNetDataTeamJoinRequest(string lobby_id, int team_index, int slot_index)
	{
		m_LobbyId = lobby_id;
		m_TeamIndex = team_index;
		m_SlotIndex = slot_index;
	}
	
	// ----------------------------------------
	// SETTERS
	void SetLobbyId(string lobby_id)
	{
		m_LobbyId = lobby_id;
	}	
	void SetTargetIndex(int target_index)
	{
		m_TeamIndex = target_index;
	}	
	void SetSlotIndex(int slot_index)
	{
		m_SlotIndex = slot_index;
	}
}

/*
	SG network response data class for joining a team
*/
class SgNetDataTeamJoinResponse extends SgNetDataTeamJoin
{	
	private string m_PlayerUID;							// Player that joined the team
	
	// --------------------------------------
	// GETTERS
	
	string GetPlayerUID()
	{
		return m_PlayerUID;
	}
	int GetTeamIndex()
	{
		return m_TeamIndex;
	}	
	int GetSlotIndex()
	{
		return m_SlotIndex;
	}
}