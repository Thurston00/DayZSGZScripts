class SgLocationPoICar : SgLocationPoI
{	
	void SgLocationPoICar()
	{
		SgSManagerEventsServer.Event_OnGamePhaseChanged.Insert( Event_OnGamePhaseChanged );
	}
	
	//-------------------------------
	// Event_OnGamePhaseChanged
	//-------------------------------
	protected void Event_OnGamePhaseChanged( ESgGameState game_state, ESgLocationType location_type, int duration_time )
	{		
		if ( location_type == ESgLocationType.PhaseFirst && game_state == ESgGameState.Phase )
		{
			m_PreviousLocationDuration = duration_time;			
			SgSManagerEventsServer.Event_OnGamePhaseChanged.Remove( Event_OnGamePhaseChanged );
			SgSManagerEventsServer.Event_OnGameSyncTimer.Insert( Event_OnGameSyncTimer );
		}
	}
	
	//-------------------------------
	// SyncEvent_OnGameSyncTimer
	//-------------------------------
	protected void Event_OnGameSyncTimer( int seconds_left )
	{
		if ( seconds_left == m_PreviousLocationDuration - SG_TIME_IN_PHASE_TO_SHOW_POI_EFFECT ) 
		{		
			SgSManagerEventsServer.Event_OnGameSyncTimer.Remove( Event_OnGameSyncTimer );
			SgSManagerEventsServer.Event_OnGameShowPoI( ESgLocationType.PoICar, GetPosition() );
			
			SgSMatchRecorder.OnActivateObject(m_LocationType);
			
			m_DidSendToClients = true;
		}
	}
	
	override protected void GenerateLoot()
	{
		AddLootItem("Mosin9130_Camo");
		AddLootItem("Ammo_762x54");
		AddLootItem("VitaminBottle");
		
		switch ( Math.RandomIntInclusive(1, 2) )
		{
			case 1:
			{
				AddLootItem("BallisticHelmet_Green");	
				break
			}
			case 2:
			{
				AddLootItem("PlateCarrierVest");	
				break
			}
		}
	}
}

