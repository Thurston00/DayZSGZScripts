class SgSManagerEventsServer
{	
	static ref ScriptInvoker Event_OnUserConnected				= new ScriptInvoker();
		
	static ref ScriptInvoker Event_OnWarmUpPlayerJoined			= new ScriptInvoker();
	static ref ScriptInvoker Event_OnWarmUpFinished				= new ScriptInvoker();
	
	static ref ScriptInvoker Event_OnSgPlayerConnectionTimeOut	= new ScriptInvoker();
	static ref ScriptInvoker Event_OnSgPlayerReconnected		= new ScriptInvoker();
	
	static ref ScriptInvoker Event_OnSgPlayerDied				= new ScriptInvoker();
	static ref ScriptInvoker Event_OnSgPlayerMoveLockChanged	= new ScriptInvoker();
	static ref ScriptInvoker Event_OnSgPlayerCollarDeactivated	= new ScriptInvoker();
	static ref ScriptInvoker Event_OnSgPlayerCollarBlockChanged	= new ScriptInvoker();
	static ref ScriptInvoker Event_OnSgPlayerLocationEnter		= new ScriptInvoker();
	static ref ScriptInvoker Event_OnSgPlayerLocationLeave		= new ScriptInvoker();	
	
	static ref ScriptInvoker Event_OnGameInitialized			= new ScriptInvoker();	
	static ref ScriptInvoker Event_OnGameStarted				= new ScriptInvoker();
	static ref ScriptInvoker Event_OnGameUpdate					= new ScriptInvoker();
	static ref ScriptInvoker Event_OnGameTimeSecond				= new ScriptInvoker();
	static ref ScriptInvoker Event_OnGameSyncTimer				= new ScriptInvoker();
	static ref ScriptInvoker Event_OnGameShowPoI				= new ScriptInvoker();
	static ref ScriptInvoker Event_OnGamePhaseChanged			= new ScriptInvoker();
	static ref ScriptInvoker Event_OnGameFinished				= new ScriptInvoker();
	
	static ref ScriptInvoker Event_OnZombieDied					= new ScriptInvoker();
	
	static ref ScriptInvoker Event_OnLocationActivated			= new ScriptInvoker();	
	static ref ScriptInvoker Event_OnLocationDeactivated		= new ScriptInvoker();
	
	static ref ScriptInvoker Event_OnSgPlayerCollarDamage		= new ScriptInvoker();
	static ref ScriptInvoker Event_OnSgPlayerCollarExplode		= new ScriptInvoker();
	
	static ref ScriptInvoker Event_OnTeamDeadStats				= new ScriptInvoker();
	
	static ref ScriptInvoker Event_OnGameServerInit				= new ScriptInvoker();
	static ref ScriptInvoker Event_OnGameServerMatchInfoLoaded	= new ScriptInvoker();
	
	static void InitStaticEvents()
	{
		SgSSyncEvents.InitEvents();
		SgSManagerPlayers.InitEvents();
		SgSResultScreenStatsCollector.InitEvents();
		
		SgNetworkService.GetService().GetEvent_OnGameServerMatchInfoLoaded().Insert(Event_OnGameServerMatchInfoLoaded);
	}
	
	//==================================
	// Event_OnUserConnected
	//==================================
	static void Event_OnUserConnected( PlayerIdentity identity)
	{
		GameLog("[" + identity.GetName() + "]: Event_OnUserConnected");
		Event_OnUserConnected.Invoke( identity );
	}
	
	//==================================
	// Event_OnWarmUpPlayerJoined
	//==================================
	static void Event_OnWarmUpPlayerJoined( SgPlayer sg_player )
	{
		Print("WarmUp Player Joined");
		GameLog("[WarmUp]: Event_OnWarmUpPlayerJoined");
		Event_OnWarmUpPlayerJoined.Invoke( sg_player );
	}
	
	//==================================
	// Event_OnWarmUpFinishedInvoke
	//==================================
	static void Event_OnWarmUpFinishedInvoke()
	{
		Print("WarmUp finished");
		GameLog("[WarmUp]: Event_OnWarmUpFinished");
		Event_OnWarmUpFinished.Invoke( );
	}
	
	//==================================
	// Event_OnPlayerConnectionTimeOut
	//==================================
	static void Event_OnSgPlayerConnectionTimeOut( SgPlayer sg_player )
	{
		GameLog("[" + sg_player.GetUserName() + "]: Event_OnPlayerConnectionTimeOut");
		Event_OnSgPlayerConnectionTimeOut.Invoke( sg_player );
	}
	
	//==================================
	// Event_OnSgPlayerReconnected
	//==================================
	static void Event_OnSgPlayerReconnected( SgPlayer sg_player )
	{
		GameLog("[" + sg_player.GetUserName() + "]: Event_OnSgPlayerReconnected");
		Event_OnSgPlayerReconnected.Invoke( sg_player );
	}
	
	//==================================
	// Event_OnPlayerDied
	//==================================
	static void Event_OnSgPlayerDied( SgPlayer sg_player, SgDeathDetails details )
	{
		if ( sg_player )
		{
			GameLog( "[" + sg_player.GetUserName() + "]: Event_OnPlayerDied by: " + details.m_KillerUID );
			Event_OnSgPlayerDied.Invoke( sg_player, details );
		}
	}
	
	//==================================
	// Event_OnSgPlayerMoveLockChanged
	//==================================
	static void Event_OnSgPlayerMoveLockChanged( SgPlayer sg_player, bool lock )
	{
		GameLog( "[" + sg_player.GetUserName() + "]: Event_OnSgPlayerMoveLockChanged: " );
		Event_OnSgPlayerMoveLockChanged.Invoke(sg_player, lock);
	}
	
	//==================================
	// Event_OnPlayerCollarDeactivated
	//==================================
	static void Event_OnSgPlayerCollarDeactivated( SgPlayer sg_player )
	{
		GameLog( "[" + sg_player.GetUserName() + "]: Event_OnPlayerCollarDeactivated" );
		Event_OnSgPlayerCollarDeactivated.Invoke(sg_player);
	}
	
	//==================================
	// Event_OnSgPlayerCollarBlockChanged
	//==================================
	static void Event_OnSgPlayerCollarBlockChanged( SgPlayer sg_player, bool block )
	{
		GameLog( "[" + sg_player.GetUserName() + "]: Event_OnSgPlayerCollarBlockChanged" );
		Event_OnSgPlayerCollarBlockChanged.Invoke(sg_player, block);
	}
	
	//==================================
	// Event_OnPlayerLocationEnter
	//==================================
	static void Event_OnSgPlayerLocationEnter( SgPlayer sg_player )
	{
		GameLog( "[" + sg_player.GetUserName() + "]: Event_OnPlayerLocationEnter" );
		Event_OnSgPlayerLocationEnter.Invoke(sg_player);
	}
	
	//==================================
	// Event_OnPlayerLocationLeave
	//==================================
	static void Event_OnSgPlayerLocationLeave( SgPlayer sg_player )
	{
		GameLog( "[" + sg_player.GetUserName() + "]: Event_OnPlayerLocationLeave" );
		Event_OnSgPlayerLocationLeave.Invoke(sg_player);
	}	
	
	//==================================
	// Event_OnGameUpdate
	//==================================
	static void Event_OnGameUpdate()
	{
		//GameLog( "[Game]: Event_OnGameTimeSecond seconds left: "+ seconds_left );
		Event_OnGameUpdate.Invoke();
	}
	
	//==================================
	// Event_OnGameTimeSecond
	//==================================
	static void Event_OnGameTimeSecond(int seconds_left)
	{
		//GameLog( "[Game]: Event_OnGameTimeSecond seconds left: "+ seconds_left );
		Event_OnGameTimeSecond.Invoke( seconds_left );
	}

	//==================================
	// Event_OnGameSyncTimer
	//==================================
	static void Event_OnGameSyncTimer(int seconds_left)
	{
		//GameLog( "[Game]: Event_OnGameSyncTimer seconds left: "+ seconds_left );
		Event_OnGameSyncTimer.Invoke( seconds_left );
	}
	
	//==================================
	// Event_OnGameShowPoI
	//==================================
	static void Event_OnGameShowPoI( ESgLocationType type, vector location_position )
	{
		GameLog( "[Game]: Event_OnGameShowPoI  type: " + type.ToString() + " Position: " + location_position.ToString() );
		Event_OnGameShowPoI.Invoke( type, location_position );
	}
	
	//==================================
	// Event_OnGameInitialized
	//==================================
	static void Event_OnGameInitialized( int pg_id )
	{
		GameLog( "[Game]: Event_OnGameInitialized" );
		Event_OnGameInitialized.Invoke( pg_id );
	}
	
	//==================================
	// Event_OnGameStarted
	//==================================
	static void Event_OnGameStarted()
	{
		GameLog( "[Game]: Event_OnGameStarted" );
		Event_OnGameStarted.Invoke();
		
		//analytics
		GetGame().GetAnalyticsServer().SendMatchStartEvent( SgPluginGameServer.GetInstance().GetMatchId(), SgSManagerPlayers.GetSgPlayers().Count() );
	}
	
	//==================================
	// Event_OnGamePhaseChanged
	//==================================
	static void Event_OnGamePhaseChanged( ESgGameState game_state, ESgLocationType location_type, int duration_time )
	{
		GameLog( "[Game]: Event_OnGamePhaseChanged game_state: " + game_state + " location_type: " + location_type );
		Event_OnGamePhaseChanged.Invoke( game_state, location_type, duration_time );
	}
	
	//==================================
	// Event_OnGameFinished
	//==================================
	static void Event_OnGameFinished( int team_id )
	{
		GameLog( "[Game]: Event_OnGameFinished" );
		Event_OnGameFinished.Invoke( team_id );
		
		SgNetServerDataGameFinishRequest gameFinishedInput = new SgNetServerDataGameFinishRequest();
		gameFinishedInput.SetTeamResultList( SgSResultScreenStatsCollector.GetStatsData().GetTeamResultList() );
		if ( SgEResult.ERROR == SgSNetworkServiceWrapper.GameServerGameFinished(gameFinishedInput) )
		{
			Print("[Error] GameServerGameFinished");
		}
		else
		{
			Print("[Success] GameServerGameFinished");
		}
		
		//analytics
		GetGame().GetAnalyticsServer().SendMatchEndEvent();
		
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( GetGame().RequestExit, 90000, false, 0);
	}
	
	
	//==================================
	// Event_OnZombieDied
	//==================================
	static void Event_OnZombieDied( SG_InfectedBase zombie, string killerUID )
	{
		GameLog( "[Game]: Event_OnZombieDied" );
		Event_OnZombieDied.Invoke( zombie, killerUID );
	}
	
	//==================================
	// Event_OnLocationActivated
	//==================================
	static void Event_OnLocationActivated( SgLocation location )
	{
		GameLog( "[Game]: Event_OnLocationActivated" );
		Event_OnLocationActivated.Invoke( location );
	}
	
	//==================================
	// Event_OnLocationDeactivated
	//==================================
	static void Event_OnLocationDeactivated( SgLocation location )
	{
		GameLog( "[Game]: Event_OnLocationDeactivated" );
		Event_OnLocationDeactivated.Invoke( location );
	}
	
	//==================================
	// Event_OnSgPlayerCollarDamage
	//==================================
	static void Event_OnSgPlayerCollarDamage( SgPlayer sg_player )
	{
		GameLog( "[Game]: Event_OnSgPlayerCollarDamage" );
		Event_OnSgPlayerCollarDamage.Invoke( sg_player );
	}
	
	//==================================
	// Event_OnSgPlayerCollarExplode
	//==================================
	static void Event_OnSgPlayerCollarExplode( SgPlayer sg_player )
	{
		GameLog( "[Game]: Event_OnSgPlayerCollarExplode" );
		Event_OnSgPlayerCollarExplode.Invoke( sg_player );
	}
	
	//==================================
	// Event_OnTeamDeadStats
	//==================================
	static void Event_OnTeamDeadStats( SgNetDataTeamResult team_stats )
	{
		GameLog( "[Game]: Event_OnTeamDeadStats" );
		Event_OnTeamDeadStats.Invoke( team_stats );
	}	
	
	//==================================
	// Event_OnGameServerInit
	//==================================
	static void Event_OnGameServerInit()
	{
		GameLog( "[Server]: Event_OnGameServerInit" );
		Event_OnGameServerInit.Invoke();
		
		if ( SgEResult.ERROR == SgSNetworkServiceWrapper.GameServerGetMatchInfo() )
		{
			Print("[Error] GameServerGetMatchInfo");
		}
		else
		{
			Print("[Success] GameServerGetMatchInfo");
		}
	}
	
	//==================================
	// Event_OnGameServerMatchInfoLoaded
	//==================================
	static void Event_OnGameServerMatchInfoLoaded( SgNetServerDataMatchLoadResponse resultValue )
	{
		Print("[Event_OnGameServerMatchInfoLoaded] Event_OnGameServerMatchInfoLoaded");
		GameLog( "[Network]: Event_OnGameServerMatchInfoLoaded" );
	
		SgPluginGameServer.GetInstance().SetMatchId( resultValue.GetMatchId() ); 
			
		Event_OnGameServerMatchInfoLoaded.Invoke( resultValue );
	}
	
	//----------------------------------
	// GameLog
	//----------------------------------
	protected static void GameLog(string log_msg)
	{
		log_msg = "EVENT: " + log_msg;
		
		SgPluginGameServer.GetInstance().GameLog(log_msg);
	}
}