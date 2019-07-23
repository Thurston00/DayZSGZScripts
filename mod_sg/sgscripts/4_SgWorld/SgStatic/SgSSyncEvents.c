class SgSSyncEvents
{
	static ref ScriptInvoker SyncEvent_OnWarmUpJoined			= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnWarmUpFinished			= new ScriptInvoker();
	
	static ref ScriptInvoker SyncEvent_OnGameStarted			= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnGameUpdate				= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnGameFinished			= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnGamePhaseChanged		= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnGameSyncTimer			= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnGameShowPoI			= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnPlayerInitialized		= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnPlayerReconnected		= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnPlayerDied				= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnPlayerUnconscious		= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnPlayerWokeUp			= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnPlayerMoveLockChanged	= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnCollarBlockChanged		= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnCollarDamage			= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnCollarExplode			= new ScriptInvoker();
	static ref ScriptInvoker SyncEvent_OnTeamDeadStats			= new ScriptInvoker();
	
	//==================================
	// InitEvents
	//==================================
	static void InitEvents()
	{
		SgSManagerEventsServer.Event_OnWarmUpPlayerJoined.Insert( Event_OnWarmUpPlayerJoined );
		SgSManagerEventsServer.Event_OnWarmUpFinished.Insert( Event_OnWarmUpFinished );
		SgSManagerEventsServer.Event_OnGameStarted.Insert( Event_OnGameStarted );
		SgSManagerEventsServer.Event_OnGameUpdate.Insert( Event_OnGameUpdate );
		SgSManagerEventsServer.Event_OnGameFinished.Insert( Event_OnGameFinished );
		SgSManagerEventsServer.Event_OnGamePhaseChanged.Insert( Event_OnGamePhaseChanged );
		SgSManagerEventsServer.Event_OnGameSyncTimer.Insert( Event_OnGameSyncTimer );
		SgSManagerEventsServer.Event_OnGameShowPoI.Insert( Event_OnGameShowPoI );
		SgSManagerEventsServer.Event_OnSgPlayerReconnected.Insert( Event_OnSgPlayerReconnected );
		SgSManagerEventsServer.Event_OnSgPlayerDied.Insert( Event_OnSgPlayerDied );
		SgSManagerEventsServer.Event_OnSgPlayerMoveLockChanged.Insert( Event_OnSgPlayerMoveLockChanged );
		SgSManagerEventsServer.Event_OnSgPlayerCollarBlockChanged.Insert( Event_OnSgPlayerCollarBlockChanged );
		SgSManagerEventsServer.Event_OnSgPlayerCollarDamage.Insert( Event_OnSgPlayerCollarDamage );
		SgSManagerEventsServer.Event_OnSgPlayerCollarExplode.Insert( Event_OnSgPlayerCollarExplode );
		SgSManagerEventsServer.Event_OnTeamDeadStats.Insert( Event_OnTeamDeadStats );
	}
	
	//==================================
	// OnSyncEvent
	//==================================
	static void OnSyncEvent( ESgSyncEvent event_type, SgSyncData data, Object target )
	{		
		switch ( event_type )
		{
			case ESgSyncEvent.WarmUpJoined:
			{
				SyncEvent_OnWarmUpJoined.Invoke();				
				break;
			}
			
			case ESgSyncEvent.WarmUpFinished:
			{
				SyncEvent_OnWarmUpFinished.Invoke();
				break;
			}
			case ESgSyncEvent.GameStarted:
			{
				SyncEvent_OnGameStarted.Invoke( data.m_DataGameStarted );
				SyncEvent_OnGameSyncTimer.Invoke( data.m_Int[0], true );
				break;
			}
			case ESgSyncEvent.GameUpdate:
			{
				SyncEvent_OnGameUpdate.Invoke( data.m_DataGameUpdate );
				break;
			}
			case ESgSyncEvent.GameFinished:
			{
				SyncEvent_OnGameFinished.Invoke( data.m_DataGameResult );
				break;
			}
			case ESgSyncEvent.GamePhaseChanged:
			{
				ESgGameState game_state = data.m_Int[0];
				ESgLocationType location_type = data.m_Int[1];
				int duration_time = data.m_Int[2];
				vector currentPhasePosition = data.m_Vector[0];
				
				SyncEvent_OnGamePhaseChanged.Invoke( game_state, location_type, duration_time, currentPhasePosition );
				
				break;
			}
			case ESgSyncEvent.GameSyncTimer:
			{
				SyncEvent_OnGameSyncTimer.Invoke( data.m_Int[0], false );
				break;
			}
			case ESgSyncEvent.GameShowPoI:
			{
				SyncEvent_OnGameShowPoI.Invoke( data.m_Int[0], data.m_Vector[0] );
				break;
			}
			case ESgSyncEvent.PlayerReconnected:
			{
				currentPhasePosition = data.m_Vector[0];
				
				SyncEvent_OnPlayerReconnected.Invoke( data.m_DataReconnected, currentPhasePosition );
				SyncEvent_OnGameSyncTimer.Invoke( data.m_DataReconnected.m_LocationTimeLeft, true );
				
				break;
			}
			case ESgSyncEvent.PlayerDied:
			{
				SgDeathDetails details = new SgDeathDetails;
				details.m_Reason = data.m_Int[0];
				details.m_KillerUID = data.m_String[1];
				
				string player_uid = data.m_String[0];
				int players_alive_count = data.m_Int[1];
				
				SyncEvent_OnPlayerDied.Invoke( player_uid, details, players_alive_count );
				break;
			}
			case ESgSyncEvent.PlayerMoveLockChanged:
			{
				SyncEvent_OnPlayerMoveLockChanged.Invoke( data.m_Int[0] );
				break;
			}
			case ESgSyncEvent.CollarBlockChanged:
			{
				SyncEvent_OnCollarBlockChanged.Invoke( data.m_Int[0] );
				break;
			}
			case ESgSyncEvent.CollarDamage:
			{
				SyncEvent_OnCollarDamage.Invoke( data.m_String[0] );
				break;
			}
			case ESgSyncEvent.CollarExplosion:
			{
				SyncEvent_OnCollarExplode.Invoke( data.m_String[0] );
				break;
			}
			case ESgSyncEvent.TeamDeadStats:
			{				
				SyncEvent_OnTeamDeadStats.Invoke( data.m_DataTeamResult );
				break;
			}
		}
	}
	
	//==================================
	// Event_OnWarmUpPlayerJoined
	//==================================
	static void Event_OnWarmUpPlayerJoined( SgPlayer sg_player )
	{		
		PlayerIdentity identity = sg_player.GetIdentity();
		if ( identity != null )
		{
			SgSRpcEvent.SendSyncEvent( ESgSyncEvent.WarmUpJoined, null, true, identity );
		}
		else
		{
			Print("[RPC Error] Event_OnWarmUpPlayerJoined: No Identity");
		}
	}
	
	//==================================
	// Event_OnWarmUpFinished
	//==================================
	static void Event_OnWarmUpFinished()
	{
		GameLog( "Event_OnWarmUpFinished" );
		SgSRpcEvent.SendSyncEvent( ESgSyncEvent.WarmUpFinished );
	}
	
	//==================================
	// Event_OnGameStarted
	//==================================
	static void Event_OnGameStarted()
	{
		array<ref SgPlayer> players = SgSManagerPlayers.GetSgPlayers();
		
		GameLog( "Event_OnGameStarted players count: " + players.Count() );
		for ( int i = 0; i < players.Count(); ++i )
		{
			SgPlayer sg_player = players[i];
			ref SgSyncData data = new SgSyncData;
			data.m_DataGameStarted = GetGameStartedData( sg_player );
			data.m_Int.Insert( SgPluginGameServer.GetInstance().GetServerTimer() );
			
			PlayerIdentity identity = sg_player.GetIdentity();
			if ( identity != null )
			{
				SgSRpcEvent.SendSyncEvent( ESgSyncEvent.GameStarted, data, true, identity );
			}
			else
			{
				Print("[RPC Error] Event_OnGameStarted: No Identity");
			}
		}
		
		/*
		array<ref SgCaster> casters = SgSManagerCasters.GetCasters();
		
		for ( i = 0; i < casters.Count(); ++i )
		{
			SgCaster sg_caster = casters[i];
			ref SgSyncData caster_data = new SgSyncData;
			caster_data.m_DataGameStarted = GetGameStartedData( null );
			SgSRpcEvent.SendSyncEvent( ESgSyncEvent.GameStarted, caster_data, true, sg_caster.GetIdentity() );
		}
		*/
	}
	
	//==================================
	// Event_OnGameUpdate
	//==================================
	static void Event_OnGameUpdate()
	{
		array<ref SgPlayer> players = SgSManagerPlayers().GetSgPlayers();
		
		for ( int j = 0; j < players.Count(); ++j )
		{
			SgPlayer player = players[j];
			
			if ( SgPluginGameServer.GetInstance().GetGameState() != ESgGameState.WarmUp )
			{
				if ( player.IsAlive() )
				{
					ref array<ref SgPlayer> teammates = player.GetTeam().GetPlayers();
					
					ref SgSyncData data = new SgSyncData();
					
					GameLog( "SyncEvent_OnTeammateData teammates.Count() = " + teammates.Count() );
					
					for ( int i = 0; i < teammates.Count(); ++i )
					{
						SgPlayer team_member = teammates[i];
						
						GameLog( "SyncEvent_OnTeammateData " + team_member.GetPlayerUID()  +" / " + player.GetPlayerUID() );
						
						if ( team_member.GetPlayerUID() != player.GetPlayerUID() )
						{
							data.m_DataGameUpdate = new SgSyncGameUpdate();
							data.m_DataGameUpdate.AddPlayer( team_member );
						}
					}
					
					if ( data.m_DataGameUpdate )
					{
						GameLog( "SyncEvent_OnTeammateData PlayerUID: " + player.GetPlayerUID() + " Teammate update data");
						
						PlayerIdentity identity = player.GetIdentity();
						if ( identity != null )
						{
							SgSRpcEvent.SendSyncEvent( ESgSyncEvent.GameUpdate, data, true, identity );
						}
						else
						{
							Print("[RPC Error] Event_OnGameUpdate: No Identity");
						}
					}
				}
			}
		}
	}

	//==================================
	// Event_OnGamePhaseChanged
	//==================================
	static void Event_OnGamePhaseChanged( ESgGameState game_state, ESgLocationType location_type, int duration_time )
	{
		ref SgSyncData data = new SgSyncData;
		data.m_Int.Insert( game_state );
		data.m_Int.Insert( location_type );
		data.m_Int.Insert( duration_time );
		data.m_Vector.Insert( GetCurrentPhasePosition() );
		
		GameLog( "Event_OnGamePhaseChanged GameState: " + game_state + " LocationType: "+ location_type );
		SgSRpcEvent.SendSyncEvent( ESgSyncEvent.GamePhaseChanged, data );
	}
	
	//==================================
	// Event_OnGameSyncTimer
	//==================================
	static void Event_OnGameSyncTimer( int time_left )
	{
		ref SgSyncData data = new SgSyncData;		
		data.m_Int.Insert( time_left );
		
		GameLog( "Event_OnGameSyncTimer TimeLeft: " + time_left );
		SgSRpcEvent.SendSyncEvent( ESgSyncEvent.GameSyncTimer, data );
	}
	
	//==================================
	// SyncEvent_OnGameShowPoI
	//==================================
	static void Event_OnGameShowPoI( ESgLocationType type, vector location_position )
	{
		ref SgSyncData data = new SgSyncData;		
		data.m_Vector.Insert( location_position );
		data.m_Int.Insert( type );
		
		GameLog( "SyncEvent_OnGameShowPoI type: " + type.ToString() + " Position: " + location_position.ToString() );
		SgSRpcEvent.SendSyncEvent( ESgSyncEvent.GameShowPoI, data );
	}
	
	//==================================
	// Event_OnGameFinished
	//==================================
	static void Event_OnGameFinished( int team_id )
	{
		ref SgSyncData data = new SgSyncData;		
		data.m_DataGameResult = new SgSyncGameResultData();
		data.m_DataGameResult.m_WinnerTeamID = team_id;
		
		GameLog( "Event_OnGameFinished WinnerTeamID: " + team_id );
		SgSRpcEvent.SendSyncEvent( ESgSyncEvent.GameFinished, data );
	}
	
	//==================================
	// Call from Client Player Base after Initialized Player Identity
	// ClientEvent_OnPlayerBaseInitialized
	//==================================
	static void ClientEvent_OnPlayerBaseInitialized( PlayerBase player )
	{
		SgSSyncEvents.SyncEvent_OnPlayerInitialized.Invoke( player.GetIdentity().GetId() );
	}
	
	//==================================
	// Event_OnSgPlayerDied
	//==================================
	static void Event_OnSgPlayerDied( SgPlayer sg_player, SgDeathDetails details )
	{
		ref SgSyncData data = new SgSyncData;		
		data.m_String.Insert( sg_player.GetPlayerUID() );
		data.m_String.Insert( details.m_KillerUID );
		data.m_Int.Insert( details.m_Reason );
		data.m_Int.Insert( SgSManagerPlayers.GetPlayersAliveCount() );
		
		GameLog( "Event_OnSgPlayerDied PlayerUID: " + sg_player.GetPlayerUID() );
		SgSRpcEvent.SendSyncEvent( ESgSyncEvent.PlayerDied, data );
	}
	
	//==================================
	// Event_OnSgPlayerCollarDamage
	//==================================
	static void Event_OnSgPlayerCollarDamage( SgPlayer sg_player )
	{
		ref SgSyncData data = new SgSyncData;		
		data.m_String.Insert( sg_player.GetPlayerUID() );
		
		PlayerIdentity identity = sg_player.GetIdentity();
		if ( identity != null )
		{
			SgSRpcEvent.SendSyncEvent( ESgSyncEvent.CollarDamage, data );
		}
		else
		{
			Print("[RPC Error] Event_OnSgPlayerCollarDamage: No Identity");
		}	
	}
	
	//==================================
	// Event_OnSgPlayerCollarExplode
	//==================================
	static void Event_OnSgPlayerCollarExplode( SgPlayer sg_player )
	{
		ref SgSyncData data = new SgSyncData;		
		data.m_String.Insert( sg_player.GetPlayerUID() );
		
		PlayerIdentity identity = sg_player.GetIdentity();
		if ( identity != null )
		{
			SgSRpcEvent.SendSyncEvent( ESgSyncEvent.CollarExplosion, data  );
		}
		else
		{
			Print("[RPC Error] Event_OnSgPlayerCollarExplode: No Identity");
		}		
	}
	
	//==================================
	// Event_OnTeamDeadStats
	//==================================
	static void Event_OnTeamDeadStats( SgNetDataTeamResult teamStats )
	{
		ref SgSyncData data = new SgSyncData;		
		data.m_DataTeamResult = teamStats;
		
		GameLog( "Event_OnTeamDeadStats Rank: " + teamStats.GetRank().ToString() );
		
		for (int i = 0; i < teamStats.GetPlayerResultList().Count(); i++)
		{
			PlayerIdentity identity = SgSManagerPlayers.GetPlayerIdentityByPlayerUID( teamStats.GetPlayerResultList()[i].GetPlayerUID() );
			if (identity != null)
			{				
				SgSRpcEvent.SendSyncEvent( ESgSyncEvent.TeamDeadStats, data, true, identity );
			}
			else
			{
				Print("[RPC Error] Event_OnTeamDeadStats: No Identity");
			}
		}
	}
	
	//==================================
	// Event_OnSgPlayerMoveLockChanged
	//==================================
	static void Event_OnSgPlayerMoveLockChanged( SgPlayer sg_player, bool lock )
	{
		ref SgSyncData data = new SgSyncData;		
		data.m_Int.Insert( lock );
		
		GameLog( "Event_OnSgPlayerMoveLockChanged PlayerUID: " + sg_player.GetPlayerUID() + " Lock: " + lock );
		
		PlayerIdentity identity = sg_player.GetIdentity();
		if ( identity != null )
		{
			SgSRpcEvent.SendSyncEvent( ESgSyncEvent.PlayerMoveLockChanged, data, true, identity );
		}
		else
		{
			Print("[RPC Error] Event_OnSgPlayerMoveLockChanged: No Identity");
		}
	}	
	
	//==================================
	// Event_OnSgPlayerCollarBlockChanged
	//==================================
	static void Event_OnSgPlayerCollarBlockChanged( SgPlayer sg_player, bool block )
	{
		ref SgSyncData data = new SgSyncData;
		data.m_Int.Insert( block );
		
		GameLog( "Event_OnSgPlayerCollarBlockChanged PlayerUID: " + sg_player.GetPlayerUID() + " Block: " + block );
		
		PlayerIdentity identity = sg_player.GetIdentity();
		if ( identity != null )
		{
			SgSRpcEvent.SendSyncEvent( ESgSyncEvent.CollarBlockChanged, data, true, identity );
		}
		else
		{
			Print("[RPC Error] Event_OnSgPlayerCollarBlockChanged: No Identity");
		}
	}
	
	//==================================
	// GetGameStartedData
	//==================================
	private static SgSyncGameStarted GetGameStartedData( SgPlayer sg_player )
	{
		ref SgSyncGameStarted game_data = new SgSyncGameStarted();
		
		// PgID
		game_data.m_PgID = SgSManagerPlayground.GetPgID();
		
		// Players IDs
		game_data.m_PlayersUIDs = new array<ref SgSyncPlayerInfo>;
		ref array<ref SgPlayer> sg_all_players = SgSManagerPlayers.GetSgPlayers();
		for ( int i = 0; i < sg_all_players.Count(); ++i )
		{
			SgPlayer player = sg_all_players[i];
			game_data.m_PlayersUIDs.Insert( new SgSyncPlayerInfo( player.GetPlayerUID(), player.GetUserName(), player.GetTeam().GetTeamID(), player.GetPlayerLowBits(), player.GetPlayerHighBits() ) );
		}
		
		// Teammate IDs
		game_data.m_TeammateUIDs = new array<string>;
		
		// If he is caster, not teamate info
		
		if ( sg_player )
		{
			SgTeam team = sg_player.GetTeam();
			if ( team )
			{
				game_data.m_TeammateUIDs.Copy( team.GetTeammatesUsersID() );
				
				Print("User Name: " + sg_player.GetUserName() + " player UID: " + sg_player.GetPlayerUID() );
				Print("Teammates:");
				game_data.m_TeammateUIDs.Debug();
			}
		}
		
		return game_data;
	}
	
	//==================================
	// Event_OnSgPlayerReconnected
	//==================================
	static void Event_OnSgPlayerReconnected( SgPlayer sg_player )
	{
		ref SgSyncReconnected reconnect_data = new SgSyncReconnected();
		
		reconnect_data.m_PgID				= SgSManagerPlayground.GetPgID();
		reconnect_data.m_PlayersAliveCount	= SgSManagerPlayers.GetPlayersAliveCount();
		reconnect_data.m_GameState			= SgPluginGameServer.GetInstance().GetGameState();
		reconnect_data.m_LocationType		= SgPluginGameServer.GetInstance().GetLocationType();
		reconnect_data.m_LocationTimeLeft	= SgPluginGameServer.GetInstance().GetAbsoluteServerTimer();
		reconnect_data.m_LocationDuration	= SgSManagerPlayground.GetActivePhaseLocation().GetTimeTransition();
		
		SgLocation poi_car_location = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PoICar );
		if ( SgLocationPoICar.Cast( poi_car_location ).GetDidSentToClients() )
		{
			reconnect_data.m_PoICarPositions = new array<vector>;
			reconnect_data.m_PoICarPositions.Insert( poi_car_location.GetPosition() );
		}
		
		SgLocation poi_heli_location = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PoIHeli );
		if ( SgLocationPoIHeli.Cast( poi_heli_location ).GetDidSentToClients() )
		{
			reconnect_data.m_PoIHeliPositions = new array<vector>;
			reconnect_data.m_PoIHeliPositions.Insert( poi_heli_location.GetPosition() );
		}
		
		// Players IDs
		reconnect_data.m_PlayersUIDs = new array<ref SgSyncPlayerInfo>;
		ref array<ref SgPlayer> sg_all_players = SgSManagerPlayers.GetSgPlayers();
		for ( int i = 0; i < sg_all_players.Count(); ++i )
		{
			SgPlayer player = sg_all_players[i];
			
			reconnect_data.m_PlayersUIDs.Insert( new SgSyncPlayerInfo( player.GetPlayerUID(), player.GetUserName(), player.GetTeam().GetTeamID(), player.GetPlayerLowBits(), player.GetPlayerHighBits() ) );
		}
		
		// Teammate IDs
		reconnect_data.m_TeammateUIDs = new array<string>;
		SgTeam team = sg_player.GetTeam();
		if ( team )
		{
			reconnect_data.m_TeammateUIDs.Copy( team.GetTeammatesUsersID() );
		}
		
		PlayerIdentity identity = sg_player.GetIdentity();
		if (identity != null)
		{
			ref SgSyncData data = new SgSyncData;
			data.m_DataReconnected = reconnect_data;
			data.m_Vector.Insert( GetCurrentPhasePosition() );
			
			SgSRpcEvent.SendSyncEvent( ESgSyncEvent.PlayerReconnected, data, true, identity );
		}
		else
		{
			Print("[RPC Error] Event_OnSgPlayerReconnected: No Identity");
		}
		
		//return reconnect_data;
	}
	
	//----------------------------------
	// GameLog
	//----------------------------------
	protected static void GameLog(string log_msg)
	{
		log_msg = "SYNC EVENT: " + log_msg;
		
		SgPluginGameServer.GetInstance().GameLog(log_msg);
	}
	
	protected static vector GetCurrentPhasePosition()
	{
		SgLocation location = SgSManagerPlayground.GetActivePhaseLocation();
		if ( location != null )
		{
			if ( location.GetLocationType() == ESgLocationType.PhaseEnd )
			{
				SgLocationPhaseEnd loc_end = SgLocationPhaseEnd.Cast( location );
				return loc_end.GetEndPosition();
			}
			else
			{
				return location.GetPosition();
			}
		}
		
		return "0 0 0"; // SG_TODO: Not sure what will happen, but has historic origins
	}
}