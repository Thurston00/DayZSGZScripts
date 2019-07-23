class SgPluginGameServer extends PluginBase
{
	static const int SPAWN_DAG_COUNT = 2;
	static const int SPAWN_RADIUS = 15;
	
	protected string								m_MatchId;
	protected ESgGameState							m_GameState;
	protected ref Timer								m_TimerServer;
	protected int									m_TimerTime;
	protected bool									m_IsTimerRunning;
	protected bool									m_IsWarmUpFinished;
	protected ref Timer								m_TimerWait;
	protected ref Timer								m_TimerWait2;
	
	//==================================
	// GetInstance
	//==================================
	static SgPluginGameServer GetInstance()
	{
		return SgPluginGameServer.Cast( GetPlugin( SgPluginGameServer ) );
	}
	
	//==================================
	// Event_OnWarmUpPlayerJoined
	//==================================
	void Event_OnWarmUpPlayerJoined( SgPlayer sg_player )
	{		
		array<ref SgPlayer> players = SgSManagerPlayers.GetSgPlayers();
		foreach ( SgPlayer player : players )
		{
			if ( player.GetIsShell() == true) { return; }
		}
		
		PrepareForGameStart();
	}
	
	//==================================
	// Event_OnPlayerLocationEnter
	//==================================
	void Event_OnSgPlayerLocationEnter(PlayerBase player)
	{
		player.SetLeaveAreaTime( GetServerTimer() );
	}
	
	//==================================
	// Event_OnPlayerLocationLeave
	//==================================
	void Event_OnSgPlayerLocationLeave(PlayerBase player)
	{
		player.SetLeaveAreaTime( GetServerTimer() );
	}
	
	//==================================
	// Event_OnPlayerCollarDeactivated
	//==================================
	void Event_OnSgPlayerCollarDeactivated( SgPlayer sg_player )
	{
		map<int, ref SgTeam> teams = SgSManagerPlayers.GetTeams();
		int alive_count = 0;
		
		for ( int i = 0; i < teams.Count(); ++i )
		{
			teams.GetElement( i ).CollarDamageBlock( false );
		}
			
		sg_player.GetTeam().CollarDamageBlock( true );
	}
	
	//==================================
	// GameInit
	//==================================
	void GameInit( int pg_id )
	{
		m_TimerWait					= new Timer(CALL_CATEGORY_GAMEPLAY);
		m_TimerWait2				= new Timer(CALL_CATEGORY_GAMEPLAY);
		m_TimerServer				= new Timer(CALL_CATEGORY_GAMEPLAY);
		
		SgSManagerEventsServer.Event_OnWarmUpPlayerJoined.Insert(Event_OnWarmUpPlayerJoined);
		SgSManagerEventsServer.Event_OnSgPlayerCollarDeactivated.Insert(Event_OnSgPlayerCollarDeactivated);
		
		SgJsonPlayground playground = SgSResourceHandler.PlaygroundSetupLoad( pg_id );		
		if( playground )
		{
			SgSManagerPlayground.Setup( playground );
			
			SgSManagerEventsServer.InitStaticEvents();
			SgSManagerEventsServer.Event_OnGameInitialized( pg_id );
			
			SetGamePhase( ESgGameState.WarmUp, ESgLocationType.None, -1 );
		}
		else
		{
			Error("[GameServer]: Cant load PlayGround id: "+ pg_id);
		}
		
		Weather weather = GetGame().GetWeather();
		weather.MissionWeather(true);
		weather.GetOvercast().SetLimits(0.4, 0.4);
		weather.GetRain().SetLimits(0.0, 0.3);
		weather.GetFog().SetLimits(0, 0.1);	// disable fog
		weather.GetOvercast().SetForecastTimeLimits(0, 900); 
		weather.GetOvercast().SetForecastChangeLimits(0.2, 0.5); 
	}
	
	//==================================
	// PrepareForGameStart
	//==================================
	void PrepareForGameStart()
	{
		if ( m_IsWarmUpFinished ) { return; }
		m_IsWarmUpFinished = true;
		
		SgSManagerEventsServer.Event_OnWarmUpFinishedInvoke();
		SgSMatchRecorder.Start();
		
		m_TimerWait.Run( 1.5, this, "GameStart", null, false );
	}
	
	//==================================
	// GameStart
	//==================================
	void GameStart()
	{
		SgLocation start_location = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PhaseStart );
		SetGamePhase( ESgGameState.Phase, ESgLocationType.PhaseStart, start_location.GetTimePhase() );
		
		SgSManagerEventsServer.Event_OnGameStarted();
		
		m_TimerServer.Run( 1, this, "OnServerTimer", null, true );
	}
	
	//==================================
	// SetMatchId
	//==================================
	void SetMatchId( string match_id )
	{		
		m_MatchId = match_id;
	}
	
	//==================================
	// GetMatchId
	//==================================
	string GetMatchId()
	{
		return m_MatchId;
	}
	
	//==================================
	// SetGameState
	//==================================
	private void SetGameState( ESgGameState state )
	{		
		m_GameState = state;
	}
	
	//==================================
	// GetGameState
	//==================================
	ESgGameState GetGameState()
	{
		return m_GameState;
	}
	
	//==================================
	// GetLocationType
	//==================================
	ESgLocationType GetLocationType()
	{
		SgLocation location = SgSManagerPlayground.GetActivePhaseLocation();
		
		if ( location )
		{
			return location.GetLocationType();
		}
		
		return ESgLocationType.None;
	}
		
	//==================================
	// GetServerTimer
	//==================================
	int GetServerTimer()
	{
		return m_TimerTime;
	}
	
	//==================================
	// GetServerTimer
	//==================================
	float GetAbsoluteServerTimer()
	{
		return m_TimerTime - m_TimerServer.GetTime();
	}
	
	//==================================
	// SetServerTimer
	//==================================
	void SetServerTimer(int time)
	{
		m_TimerTime = time;
			
		SgSMatchRecorder.OnTimerSet(m_TimerTime);
		
		SgSSyncEvents.Event_OnGameSyncTimer( GetServerTimer() );
		
		//PlayVOTimer();
			
		if ( time > 0 )
		{
			int mins = Math.Floor(time / 60);
			int secs = time - (60 * mins);
				
			GameLog("Current round time is set "+ mins.ToString() +"min "+ secs.ToString() +"sec." );
		}
		else
		{
			GameLog("Current round time is turned off. (-1)");
		}
	}
	
	//==================================
	// ServerTimerStart
	//==================================
	void ServerTimerStart()
	{
		m_IsTimerRunning = true;
	}
	
	//==================================
	// ServerTimerPause
	//==================================
	void ServerTimerPause()
	{
		m_IsTimerRunning = false;
	}
	
	//==================================
	// ServerTimerResume
	//==================================
	void ServerTimerResume()
	{
		m_IsTimerRunning = true;
	}
	
	//==================================
	// ServerTimerStop
	//==================================
	void ServerTimerStop()
	{
		m_TimerTime = 0;
	}
	
	//==================================
	// IsGameRunning
	//==================================
	bool IsGameRunning()
	{
		return ( m_GameState == ESgGameState.Phase || m_GameState == ESgGameState.Transition );
	}
	
	//==================================
	// IsGameRunning
	//==================================
	bool IsServerTimerRunning()
	{
		return m_IsTimerRunning;
	}

	//==================================
	// GameLog
	//==================================
	void GameLog(string msg)
	{
		//Print("["+ GetGame().GetTime() +"]"+ msg);
	}
	
	//----------------------------------
	// OnServerTimer 
	//----------------------------------
	protected void OnServerTimer()
	{
		SgSManagerEventsServer.Event_OnGameUpdate();
		
		if ( m_TimerTime > 0 )
		{
			SgSManagerEventsServer.Event_OnGameTimeSecond( --m_TimerTime );
			
		 	if ( m_TimerTime == 0 )
			{
				OnGameTimeOut();
			}
			else if ( (m_TimerTime % 10) == 0) // Every 10 sec synch of timer
			{
				SgSManagerEventsServer.Event_OnGameSyncTimer( GetServerTimer() );
			}
		}
	}
	
	//==================================
	// OnGameTimeOut
	//==================================
	protected void OnGameTimeOut()
	{
		ESgLocationType	active_location_type = GetLocationType();
		SgLocation location;
		
		if ( active_location_type == ESgLocationType.PhaseStart )
		{
			// Phase 1 Phase
			location = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PhaseFirst );
			SetGamePhase( ESgGameState.Phase, ESgLocationType.PhaseFirst, location.GetTimePhase() );
			
			// Analytics
			GetSgGame().GetAnalyticsServer().SendPhaseStartEvent( ESgLocationType.PhaseFirst );
			
			// Match Recorder
			SgSMatchRecorder.OnPhaseActiveSet( ESgLocationType.PhaseFirst );
		}
		else if ( active_location_type == ESgLocationType.PhaseFirst )
		{
			if ( GetGameState() == ESgGameState.Phase )
			{
				// Phase 2 Transition
				location = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PhaseSecond );
				SetGamePhase( ESgGameState.Transition, ESgLocationType.PhaseSecond, location.GetTimeTransition() );
				
				// Analytics
				GetSgGame().GetAnalyticsServer().SendPhaseEndEvent();
				GetSgGame().GetAnalyticsServer().SendTransitionStartEvent( ESgLocationType.PhaseFirst );
				
				// Match Recorder
				SgSMatchRecorder.OnTransitionSet( ESgLocationType.PhaseSecond );
			}
		}
		else if ( active_location_type == ESgLocationType.PhaseSecond )
		{
			if ( GetGameState() == ESgGameState.Transition )
			{
				// Phase 2 Phase
				location = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PhaseSecond );
				SetGamePhase( ESgGameState.Phase, ESgLocationType.PhaseSecond, location.GetTimePhase() );
				
				// Analytics
				GetSgGame().GetAnalyticsServer().SendTransitionEndEvent();
				GetSgGame().GetAnalyticsServer().SendPhaseStartEvent( ESgLocationType.PhaseSecond );
				
				// Match Recorder
				SgSMatchRecorder.OnPhaseActiveSet( ESgLocationType.PhaseSecond );
			}
			else if ( GetGameState() == ESgGameState.Phase )
			{
				// Phase End Transition
				location = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PhaseEnd );
				SetGamePhase( ESgGameState.Transition, ESgLocationType.PhaseEnd, location.GetTimeTransition() );
				
				// Analytics
				GetSgGame().GetAnalyticsServer().SendPhaseEndEvent();
				GetSgGame().GetAnalyticsServer().SendTransitionStartEvent( ESgLocationType.PhaseSecond );	
				
				// Match Recorder
				SgSMatchRecorder.OnTransitionSet( ESgLocationType.PhaseEnd );
			}
		}
		else if ( active_location_type == ESgLocationType.PhaseEnd )
		{
			if ( GetGameState() == ESgGameState.Transition )
			{
				// End Game Collar Beeping
				location = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PhaseEnd );
				SetGamePhase( ESgGameState.Phase, ESgLocationType.PhaseEnd, location.GetTimeTransition() );
				
				// Analytics
				GetSgGame().GetAnalyticsServer().SendTransitionEndEvent();
				GetSgGame().GetAnalyticsServer().SendPhaseStartEvent( ESgLocationType.PhaseEnd );	
				
				// Match Recorder
				SgSMatchRecorder.OnPhaseActiveSet( ESgLocationType.PhaseEnd );
			}
		}
	}	
	
	//==================================
	// SetGamePhase
	//==================================
	void SetGamePhase(ESgGameState game_state, ESgLocationType location_type, int timer_time )
	{
		SgLocation active_location = SgSManagerPlayground.GetActivePhaseLocation();
		if ( active_location )
		{
			active_location.Deactivate();
		}	
		
		SgLocation location = SgSManagerPlayground.GetLocationByLocationType( location_type );
		if ( location )
		{
			location.Activate();
		}
		
		SetGameState( game_state );
		
		SgSManagerEventsServer.Event_OnGamePhaseChanged( game_state, location_type, timer_time );
		
		if ( timer_time > -1 )
		{
			SetServerTimer( timer_time );
			ServerTimerStart();
		}
	}
	
	//----------------------------------
	// SnapToGround
	//----------------------------------
	static void SnapToGround( out vector pos )
	{
		pos[1] = GetGame().SurfaceY( pos[0], pos[2] );
	}
	
	//==================================
	// GetLocationName
	//==================================
	static string GetLocationName( ESgLocationType location_type, int area_id )
	{
		switch ( location_type )
		{
			case ESgLocationType.PhaseStart:
			{
				return "PhaseStart";
			}
			case ESgLocationType.PhaseFirst:
			{
				return "Phase1";
			}
			case ESgLocationType.PhaseSecond:
			{
				return "Phase2";
			}
			case ESgLocationType.PhaseEnd:
			{
				return "PhaseEnd";
			}
			case ESgLocationType.PoIHeli:
			{
				return "PoIHeliCrash" + area_id.ToString();
			}
			case ESgLocationType.PoICar:
			{
				return "PoICarCrash" + area_id.ToString();
			}
		}
	
		return "UknowLocation";
	}
}