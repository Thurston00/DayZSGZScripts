class SgLocationPhaseSecond : SgLocationBordered
{	
	void SgLocationPhaseSecond()
	{
		m_OuterTextures = "phase2Textures";
		
		SgSManagerEventsServer.Event_OnGameTimeSecond.Insert( Event_OnGameTimeSecond );
		SgSManagerEventsServer.Event_OnGamePhaseChanged.Insert( Event_OnGamePhaseChanged );
	}
	
	//===============================
	// IsPhaseLocation
	//===============================
	override void Activate()
	{
		super.Activate();
	}
	
	//===============================
	// Deactivate
	//===============================
	override void Deactivate()
	{
		super.Deactivate();
		
		SetPhaseBorderLocked(false);
	}
	
	//===============================
	// IsPhaseLocation
	//===============================
	override bool IsPhaseLocation()
	{
		return true;
	}

	//-------------------------------
	// Event_OnGamePhaseChanged
	//-------------------------------
	protected void Event_OnGamePhaseChanged( ESgGameState game_state, ESgLocationType location_type, int duration_time )
	{		
		if ( IsActive() && game_state == ESgGameState.Phase )
		{
			SetPhaseBorderLocked(true);
		}		
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