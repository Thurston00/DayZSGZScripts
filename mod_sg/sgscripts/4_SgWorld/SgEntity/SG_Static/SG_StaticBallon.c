class SG_StaticBalloon extends SG_Static
{	
	protected ESgLocationType 	m_LocationType = ESgLocationType.None;
	protected int 				m_SmokeEffect  = -1;
	
	void SG_StaticBalloon()
	{
		RegisterNetSyncVariableInt("m_LocationType");
		
		if ( GetGame().IsClient() )
        {
			SgSSyncEvents.SyncEvent_OnGamePhaseChanged.Insert( SyncEvent_OnGamePhaseChanged );
			SgSSyncEvents.SyncEvent_OnPlayerReconnected.Insert( SyncEvent_OnPlayerReconnected );
		}
	}
	
	void SetLocationType( ESgLocationType location_type )
	{
		m_LocationType = location_type;
		SetSynchDirty();
	}

	protected void UpdateState( ESgLocationType currently_active_location, ESgGameState game_state )
	{
		if ( currently_active_location == m_LocationType )
		{
            if ( m_LocationType == ESgLocationType.PhaseFirst && ESgGameState.Phase == game_state )
			{
				CreateAndStartSmokeEffect();
			}
			else if ( m_LocationType == ESgLocationType.PhaseSecond && ESgGameState.Transition == game_state )
			{
				CreateAndStartSmokeEffect();
			}
		}
		else if ( m_SmokeEffect != -1 )
		{
			StopSmokeEffect();
		}
	}
	
	protected void CreateAndStartSmokeEffect()
	{
		vector particle_pos = GetMemoryPointPos("smoke");
			
		ref Effect effect = new SgEffBalloonSmokeGreen();
		m_SmokeEffect = SEffectManager.PlayOnObject( effect, this, particle_pos );
	}
	
	protected void StopSmokeEffect()
	{
		SEffectManager.Stop( m_SmokeEffect );
		m_SmokeEffect == -1;
	}
	
	//============================================
	// SyncEvent_OnPlayerReconnected
	//============================================
	protected void SyncEvent_OnPlayerReconnected( SgSyncReconnected game_data_reconnect, vector currentPhasePosition )
	{
 		UpdateState( game_data_reconnect.m_LocationType, game_data_reconnect.m_GameState );
	}
	
	//============================================
	// SyncEvent_OnGamePhaseChanged
	//============================================
	protected void SyncEvent_OnGamePhaseChanged( ESgGameState game_state, ESgLocationType location_type, int duration_time, vector currentPhasePosition )
	{
		UpdateState( location_type, game_state );
	}
}