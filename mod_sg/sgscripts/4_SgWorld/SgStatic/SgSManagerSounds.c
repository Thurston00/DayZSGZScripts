class SgSManagerSounds
{	
	protected static bool m_IsCountDownSheduled;
	protected static bool m_AreResourcesLoaded;
	protected static ref EffectSound m_EffectSound10to1;
	protected static ref EffectSound m_EffectSound03to1;
	protected static ref EffectSound m_EffectSoundAirSiren;
	
	static void Init()
	{
		m_IsCountDownSheduled = false;
		
		SgSClientTimer.ClientEvent_OneSecondTimerUpdate.Insert(SgSManagerSounds.ClientEvent_OneSecondTimerUpdate);
		SgSSyncEvents.SyncEvent_OnGamePhaseChanged.Insert(SgSManagerSounds.SyncEvent_OnGamePhaseChanged);
	}
	
	static void InitSoundResources()
	{
		if ( !m_AreResourcesLoaded )
		{			
			m_EffectSound10to1 		= SEffectManager.CreateSound( SgAudioManager.TimeLeft10to01, "0 0 0" );
			m_EffectSound03to1 		= SEffectManager.CreateSound( SgAudioManager.TimeLeft03to01, "0 0 0" );
			m_EffectSoundAirSiren	= SEffectManager.CreateSound( SgAudioManager.AirSiren, "0 0 0", 0, 0, false, true );
			
			m_AreResourcesLoaded 	= true;
		}
	}
	
	//++++++++++++++++++++++++++++++++++
	// ClientEvent_OneSecondTimerUpdate
	//++++++++++++++++++++++++++++++++++
	static void ClientEvent_OneSecondTimerUpdate( int time_left )
	{
		PlayVOTimer( time_left, true );
	}
	
	//============================================
	// SyncEvent_OnGamePhaseChanged
	//============================================
	static void SyncEvent_OnGamePhaseChanged( ESgGameState game_state, ESgLocationType location_type, int duration_time, vector currentPhasePosition )
	{
		vector vo_position = SgSClientGame.GetCurrentPhasePosition();
		
		if ( game_state == ESgGameState.Phase || game_state == ESgGameState.Transition )
		{
			switch (location_type)
			{
				case ESgLocationType.PhaseFirst:
				case ESgLocationType.PhaseSecond:
				case ESgLocationType.PhaseEnd:
				{
					m_EffectSoundAirSiren.SetPosition( SgSClientGame.GetCurrentPhasePosition() );
					m_EffectSoundAirSiren.SoundPlay();
					break;
				}
			}
		}
	}
	
	//----------------------------------
	// PlayVOTimer
	//----------------------------------
	static protected void PlayVOTimer( int time_left, bool ignore_beginning )
	{
		ESgLocationType location_type = SgSClientGame.GetLocationType();
		switch (location_type)
		{
			case ESgLocationType.PhaseStart:
			{
				if ( m_IsCountDownSheduled ) { return; }
				
				switch ( time_left )
				{
					case 10:
					{
						m_EffectSound10to1.SetPosition( SgSClientGame.GetCurrentPhasePosition() );
						m_EffectSound10to1.SoundPlay();
						m_IsCountDownSheduled = true;
						
						break;
					}
					case 3:
					{
						m_EffectSound03to1.SetPosition( SgSClientGame.GetCurrentPhasePosition() );
						m_EffectSound03to1.SoundPlay();
						m_IsCountDownSheduled = true;
						
						break;
					}
				}
				
				break;
			}
		}
	}
}