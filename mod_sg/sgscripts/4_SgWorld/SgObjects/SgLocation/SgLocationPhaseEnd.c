class SgLocationPhaseEnd : SgLocation
{	
	ref array<vector>					m_EndPositions;
	private vector						m_EndPosition;
	private int							m_EndPositionId;
	private SG_StaticCollarDeactivator 	m_CollarDeactivator;

	void SgLocationPhaseEnd()
	{
		m_EndPositions = new array<vector>;
		
		SgSManagerEventsServer.Event_OnGamePhaseChanged.Insert( Event_OnGamePhaseChanged );
		SgSManagerEventsServer.Event_OnGameTimeSecond.Insert( Event_OnGameTimeSecond );
	}
	
	//===============================
	// Event_OnGameInitialized
	//===============================
	protected override void Event_OnGameInitialized( int pg_id )
	{
		super.Event_OnGameInitialized( pg_id );
		
		m_EndPosition 	= m_EndPositions.GetRandomElement();
		m_EndPositionId = m_EndPositions.Find(m_EndPosition);
	}
	
	//-------------------------------
	// Event_OnGamePhaseChanged
	//-------------------------------
	protected void Event_OnGamePhaseChanged( ESgGameState game_state, ESgLocationType location_type, int duration_time )
	{		
		if ( location_type == ESgLocationType.PhaseEnd )
		{
			if ( m_CollarDeactivator == null )
			{
				Object obj = GetGame().CreateObject( "SG_StaticCollarDeactivator", m_EndPosition );
				m_CollarDeactivator = SG_StaticCollarDeactivator.Cast( obj );
				
				SgSMatchRecorder.OnActivateObject(m_LocationType);
			}
		
			if ( game_state == ESgGameState.Phase )
			{
				SetPhaseBorderLocked(true);
				m_CollarDeactivator.SetIteractible( true );
			}
		}
	}
		
	//===============================
	// IsPhaseLocation
	//===============================
	override bool IsPhaseLocation()
	{
		return true;
	}
	
	//===============================
	// SetEndPositions
	//===============================
	void SetEndPositions( ref array<vector> points )
	{
		for ( int i = 0; i < points.Count() ; ++i )
		{
			m_EndPositions.Insert( points[i] );
		}
	}
	
	//===============================
	// GetEndPosition
	//===============================
	vector GetEndPosition()
	{
		return m_EndPosition;
	}
	
	//===============================
	// GetEndPositionId
	//===============================
	int GetEndPositionId()
	{
		return m_EndPositionId;
	}
	
	//-------------------------------
	// Event_OnGameTimeSecond
	//-------------------------------
	protected void Event_OnGameTimeSecond( int time_left )
	{
		if ( IsPhaseBorderLocked() )
		{
			CheckPlayersBorderCross();
		}
	}
}

