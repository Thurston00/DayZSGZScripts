/*
class SgPlayGround
{
	protected static const int PHASE_COUNT = 3;
	protected static const int TRANSITION_COUNT = 3;
	
	protected int 					m_PgID;
	protected int 					m_PhaseTimes[PHASE_COUNT];
	protected float					m_TransitionTimes[TRANSITION_COUNT];
	protected SG_StaticTransmitter	m_Phase[PHASE_COUNT];	
	
	//======================================
	// SgPlayGround
	//======================================
	void SgPlayGround(int id)
	{
		m_PgID = id;
	}
	
	//======================================
	// GetID
	//======================================
	int GetID()
	{
		return m_PgID;
	}	
	
	//======================================
	// GetStartPosition
	//======================================
	vector GetStartPosition()
	{
		return GetPhase(0).GetStartPosition();
	}
	
	//======================================
	// GetStartTeamPositions
	//======================================
	array<vector> GetStartTeamPositions()
	{
		return GetPhase(0).GetStartTeamPositions();
	}
	
	//======================================
	// SetPhaseTime
	//======================================
	void SetPhaseTime(int phase_index, int phase_time)
	{
		m_PhaseTimes[phase_index] = phase_time + 1;
	}
	
	//======================================
	// GetPhaseTime
	//======================================
	int GetPhaseTime(int phase_index)
	{
		return m_PhaseTimes[phase_index];
	}
	
	//======================================
	// SetTransitionSpeed
	//======================================
	void SetTransitionTime(int transition_index, float transition_time)
	{		
		m_TransitionTimes[transition_index] = transition_time;
	}
	
	//======================================
	// GetTransitionSpeed
	//======================================
	float GetTransitionTime(int transition_index)
	{
		return m_TransitionTimes[transition_index];
	}
	
	//======================================
	// GetPhase
	//======================================
	SG_StaticTransmitter GetPhase(int index)
	{
		return m_Phase[index];
	}
	
	//======================================
	// GetPhaseActive
	//======================================
	SG_StaticTransmitter GetPhaseActive()
	{
		for ( int i = 0; i < PHASE_COUNT; ++i )
		{
			if ( m_Phase[i] && m_Phase[i].IsAreaActive() )
			{
				return m_Phase[i];
			}
		}
		
		return NULL;
	}
	
	//==================================
	// GetPhaseTransition
	//==================================
	SG_StaticTransmitter GetPhaseTransition()
	{
		for ( int i = 0; i < PHASE_COUNT; ++i )
		{
			if ( m_Phase[i] && m_Phase[i].IsAreaTransition() )
			{
				return m_Phase[i];
			}
		}
		
		return NULL;
	}
	
	//======================================
	// SetPhase
	//======================================
	void SetPhase(int order, SG_StaticTransmitter transmitter)
	{
		if ( order >= 0 && order < PHASE_COUNT )
		{
PrintString("SetPhase => ["+ order.ToString() +"] = "+ transmitter.GetAreaID().ToString());
			
			m_Phase[order] = transmitter;
		}
		else
		{
PrintString("SgPlayGround.c => SetTransmitter => int order parameter is bad.");
		}
	}
	
	//==================================
	// GetPhaseNumber
	//==================================
	int GetPhaseIndex()
	{
		for ( int i = 0; i < PHASE_COUNT; ++i )
		{
			if ( m_Phase[i].IsAreaActive() || m_Phase[i].IsAreaTransition() )
			{
				return i;
			}
		}
		
		return 0;
	}
	
	//==================================
	// IsReady
	//==================================
	bool IsReady()
	{
		for ( int i = 0; i < PHASE_COUNT; ++i )
		{
			if ( m_Phase[i] == NULL )
			{
				return false;
			}
		}
		
		return true;
	}
}
*/