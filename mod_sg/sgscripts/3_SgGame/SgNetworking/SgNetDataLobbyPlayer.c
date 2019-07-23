// 	DESIGN_ID: 0001

/*
	SG network data class for lobby player
*/
class SgNetDataLobbyPlayer extends SgNetDataPlayer
{
	private bool m_SlotCheck;
	private bool m_ReadyCheck;			
	private int m_SlotId;
	
	// ----------------------------------------
	// GETTERS
	bool GetSlotCheck()
	{
		return m_SlotCheck;
	}
	bool GetReadyCheck()
	{
		return m_ReadyCheck;
	}
	int GetSlotId()
	{
		return m_SlotId;
	}
	
	// ------------------------------------------
	// FOR CLIENT PREDICTION (when client make a change in a lobby and doesn't want to wait for server response)
	void SetPlayerLocation(int team_index, int slot_index)
	{		
		m_TeamId = team_index;
		m_SlotId = slot_index;
	}
	void SetReadyCheck(bool is_ready)
	{
		m_ReadyCheck = is_ready;
	}
}