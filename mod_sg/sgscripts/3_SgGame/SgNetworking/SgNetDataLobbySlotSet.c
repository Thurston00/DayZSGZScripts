// DESIGN_ID: 0001

/*
	"Pseudo abstract" SG network data class for setting a lobby slot
*/
class SgNetDataLobbySlotSet
{
	protected SgEAction m_Action;
	protected SgETarget m_Target;
	protected int m_TargetIndex;
	protected int m_SlotIndex;
}

/*
	SG network request data class for setting a lobby slot
*/
class SgNetDataLobbySlotSetRequest extends SgNetDataLobbySlotSet 
{	
	private string m_LobbyId;
	
	void SgNetDataLobbySlotSetRequest(string lobby_id, SgEAction action, SgETarget target, int target_index, int slot_index)
	{
		m_LobbyId = lobby_id;
		m_Action = action;
		m_Target = target;
		m_TargetIndex = target_index;
		m_SlotIndex = slot_index;
	}
	
	// ----------------------------------------
	// SETTERS
	void SetLobbyId(string lobby_id)
	{
		m_LobbyId = lobby_id;
	}
	void SetAction(SgEAction action)
	{
		m_Action = action;
	}
	void SetTarget(SgETarget target)
	{
		m_Target = target;
	}
	void SetTargetIndex(int target_index)
	{
		m_TargetIndex = target_index;
	}	
	void SetSlotIndex(int slot_index)
	{
		m_SlotIndex = slot_index;
	}
}

/*
	SG network response data class for setting a lobby slot
*/
class SgNetDataLobbySlotSetResponse extends SgNetDataLobbySlotSet
{	
	// --------------------------------------
	// GETTERS
	SgEAction GetAction()
	{
		return m_Action;
	}
	SgETarget GetTarget()
	{
		return m_Target;
	}
	int GetTargetIndex()
	{
		return m_TargetIndex;
	}	
	int GetSlotIndex()
	{
		return m_SlotIndex;
	}
}