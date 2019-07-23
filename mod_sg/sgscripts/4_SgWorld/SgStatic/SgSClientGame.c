class SgSClientGame
{
	private static ESgGameState									m_GameState;
	private static ESgLocationType								m_LocationType;
	private static int											m_LocationDuration;
	private static int											m_PlayersAliveCount;
	private static bool											m_IsCollarDamageBlocked;
	private static ref array<PlayerBase>						m_UserPlayers;
	private static ref array<ref SgSyncPlayerInfo>				m_PlayerUIDsTeams;
	private static ref array<string>							m_TeamPlayersUIDs;
	private static ref SgJsonPlayground							m_JsonPgData;
	private static ref array<int>								m_PoIEffects;
	private static ref array<vector>							m_CarPositions;
	private static ref array<vector>							m_HeliPositions;
	private static vector										m_CurrentPhasePosition;
	private	static SgDeadcam									m_Deadcam;
	private static string										m_PlayerUID = SG_UID_PLACEHOLDER;
	private static ref SgPlayerClient							m_DeadCamNextTarget;
	private static ref SgPlayerClient							m_Player;
	private static ref array<ref SgPlayerClient>				m_Players;

//	private static SG_StaticBalloon								m_BallonFirst;  // SG_TODO: SG-929
//	private static SG_StaticBalloon								m_BallonSecond;  // SG_TODO: SG-929
	
	private static ref EffectSound 								m_CollarBeep;
	private static SG_StaticCollarDeactivator 					m_CollarDeactivator;

	static ref ScriptInvoker Event_OnGamePlayersAliveCount		= new ScriptInvoker();
	static ref ScriptInvoker Event_OnDeadcamStart				= new ScriptInvoker();
	static ref ScriptInvoker Event_OnCasterCameraCreated		= new ScriptInvoker();
	static ref ScriptInvoker Event_OnClientPlayerDied 			= new ScriptInvoker();

	static void Init()
	{
		if ( !m_UserPlayers )
		{
			m_UserPlayers = new array<PlayerBase>;
		}

		m_Players = new array<ref SgPlayerClient>;
		m_PlayerUIDsTeams = new array<ref SgSyncPlayerInfo>;
		m_TeamPlayersUIDs = new array<string>;
		m_PoIEffects = new array<int>;
		m_CarPositions = new array<vector>;
		m_HeliPositions = new array<vector>;

		SgSSyncEvents.SyncEvent_OnGameStarted.Insert( SyncEvent_OnGameStarted );
		SgSSyncEvents.SyncEvent_OnGamePhaseChanged.Insert( SyncEvent_OnGamePhaseChanged );
		SgSSyncEvents.SyncEvent_OnGameShowPoI.Insert( SyncEvent_OnGameShowPoI );
		SgSSyncEvents.SyncEvent_OnPlayerReconnected.Insert( SyncEvent_OnPlayerReconnected );
		SgSSyncEvents.SyncEvent_OnPlayerDied.Insert( SyncEvent_OnPlayerDied );
		SgSSyncEvents.SyncEvent_OnCollarBlockChanged.Insert( SyncEvent_OnCollarBlockChanged );
		SgSSyncEvents.SyncEvent_OnCollarDamage.Insert( SyncEvent_OnCollarDamage );
		SgSSyncEvents.SyncEvent_OnCollarExplode.Insert( SyncEvent_OnCollarExplode );
	}

	static void DebugUpdate()
	{
Print("GetPlayerBySgID Count: "+ m_Players.Count());

		for ( int i = 0; i < m_Players.Count(); ++i )
		{
Print("GetPlayerBySgID i: " + i);

			SgPlayerClient player = m_Players[i];

			// Debug Input only for teammates, since other players could be out of network bubble but there is no sync for them from server side right now(also this would require client check for distance to switch between network bubble and server sync)
			if ( m_TeamPlayersUIDs.Find(player.GetPlayerUID()) < 0 ) { continue; }

			if ( player )
			{
				vector pos1 = player.GetPosition();
				vector pos2 = GetPlayer().GetPosition();

				float dist = vector.Distance( pos1, pos2 );

				Print("PlayerDistance: "+ dist);
			}
			else
			{
				Print("PlayerDistance: OUT OF REACH");
			}
		}
	}

	//============================================
	// SyncEvent_OnPlayerReconnected
	//============================================
	static void SyncEvent_OnPlayerReconnected( SgSyncReconnected game_data_reconnect, vector currentPhasePosition )
	{
		SetPgID( game_data_reconnect.m_PgID );
		SetPlayersAliveCount( game_data_reconnect.m_PlayersAliveCount );
		SetPlayerUIDs( game_data_reconnect.m_PlayersUIDs );
		SetTeammateUIDs( game_data_reconnect.m_TeammateUIDs );
		SetGamePhase( game_data_reconnect.m_GameState, game_data_reconnect.m_LocationType, game_data_reconnect.m_LocationDuration );
		SetCurrentPhasePosition(currentPhasePosition);
		
		switch ( game_data_reconnect.m_LocationType )
		{
			case ESgLocationType.PhaseStart:
			{
				GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_MOVEMENT);
				break;
			}
		}
		
		foreach ( vector car_pos : game_data_reconnect.m_PoICarPositions )
		{
			SetPoI( ESgLocationType.PoICar, car_pos );

			if ( m_LocationType == ESgLocationType.PhaseFirst || m_LocationType == ESgLocationType.PhaseSecond && m_GameState == ESgGameState.Transition && m_LocationDuration - SG_TIME_IN_TRANSITION_TO_REMOVE_POI_EFFECT < game_data_reconnect.m_LocationTimeLeft )
			{
				ref Effect effect = new SgEffGenericSmokeWreck();
				m_PoIEffects.Insert( SEffectManager.PlayInWorld( effect, car_pos ) );

				SgSSyncEvents.SyncEvent_OnGameSyncTimer.Insert( SyncEvent_OnGameSyncTimer );
			}
		}

		foreach ( vector heli_pos : game_data_reconnect.m_PoIHeliPositions )
		{
			SetPoI( ESgLocationType.PoIHeli, heli_pos );

			if ( m_LocationType == ESgLocationType.PhaseSecond || m_LocationType == ESgLocationType.PhaseEnd && m_GameState == ESgGameState.Transition && m_LocationDuration - SG_TIME_IN_TRANSITION_TO_REMOVE_POI_EFFECT < game_data_reconnect.m_LocationTimeLeft )
			{
				effect = new SgEffGenericSmokeWreck();
				m_PoIEffects.Insert( SEffectManager.PlayInWorld( effect, heli_pos ) );

				SgSSyncEvents.SyncEvent_OnGameSyncTimer.Insert( SyncEvent_OnGameSyncTimer );
			}
		}
	}

	//============================================
	// SyncEvent_OnGameStarted
	//============================================
	static void SyncEvent_OnGameStarted( SgSyncGameStarted game_data )
	{
		SetPlayerUIDs( game_data.m_PlayersUIDs );
		SetTeammateUIDs( game_data.m_TeammateUIDs );
		SetPgID( game_data.m_PgID );
		SetPlayersAliveCount( game_data.m_PlayersUIDs.Count() );
	}

	//============================================
	// SyncEvent_OnGameSyncTimer
	//============================================
	static void SyncEvent_OnGameSyncTimer( int time_left )
	{
		if ( GetGameState() == ESgGameState.Transition && ( GetLocationType() == ESgLocationType.PhaseSecond || GetLocationType() == ESgLocationType.PhaseEnd ) && m_LocationDuration - time_left == SG_TIME_IN_TRANSITION_TO_REMOVE_POI_EFFECT )
		{
			foreach ( int eff : m_PoIEffects )
			{
				if ( SEffectManager.IsEffectExist( eff ) )
				{
					SEffectManager.Stop( eff );
				}
			}

			SgSSyncEvents.SyncEvent_OnGameSyncTimer.Remove( SyncEvent_OnGameSyncTimer );
		}
	}

	//============================================
	// SyncEvent_OnGameShowPoI
	//============================================
	static void SyncEvent_OnGameShowPoI( ESgLocationType type, vector location_position )
	{
		ref Effect effect = new SgEffGenericSmokeWreck();
		m_PoIEffects.Insert( SEffectManager.PlayInWorld( effect, location_position ) );

		SetPoI( type, location_position );
	}

	//============================================
	// SyncEvent_OnGamePhaseChanged
	//============================================
	static void SyncEvent_OnGamePhaseChanged( ESgGameState game_state, ESgLocationType location_type, int duration_time, vector currentPhasePosition )
	{
		SetGamePhase( game_state, location_type, duration_time );
		SetCurrentPhasePosition(currentPhasePosition);
		
		if ( game_state == ESgGameState.Transition )
		{
			SgSSyncEvents.SyncEvent_OnGameSyncTimer.Insert( SyncEvent_OnGameSyncTimer );
		}

		if ( location_type == ESgLocationType.PhaseEnd && m_CollarDeactivator )
		{
			m_CollarDeactivator.ShowAlarm( game_state, location_type );
		}
		
		// SG_TODO: SG-929
		switch (location_type) // SG_TODO: use GetPhaseTowerPositions/m_JsonPgData/SpawnInsideLocationLogic to spawn right away and not on zone start :)
		{
			case ESgLocationType.PhaseStart:
			{
				GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_MOVEMENT);
				break;
			}
			case ESgLocationType.PhaseFirst:
			{
				GetGame().GetMission().PlayerControlEnable();
				//m_BallonFirst = SG_StaticBalloon.Cast( GetGame().CreateObject( "SG_StaticBalloon", currentPhasePosition, true, false, false ) );				
				break;
			}
			case ESgLocationType.PhaseSecond:
			{
				/*if (!m_BallonSecond)
				{
					m_BallonSecond = SG_StaticBalloon.Cast( GetGame().CreateObject( "SG_StaticBalloon", currentPhasePosition, true, false, false ) );				
				}*/
				break;
			}
		}
	}
	
	//============================================
	// SyncEvent_OnPlayerDied
	//============================================
	static void SyncEvent_OnPlayerDied( string player_uid, SgDeathDetails details, int players_alive_count )
	{
		SetPlayersAliveCount( players_alive_count );

		SgPlayerClient player = GetPlayerByUID( player_uid );
		player.Died();
		
		if (GetGame().GetPlayer().GetIdentity().GetId() == player_uid)			// SG_TODO reduce getters 
		{
			Event_OnClientPlayerDied.Invoke();
		}

		Print("Your Team:");
		for ( int i = 0; i < m_TeamPlayersUIDs.Count(); ++i )
		{
			string p_uid =  m_TeamPlayersUIDs[i];
			SgPlayerClient playerClient = GetPlayerByUID( p_uid ); // SG_TODO: mayeb remove this callings

			if ( playerClient.GetPlayerUID() == GetPlayerUID() )
			{
				Print("Player ID: "+ p_uid +" IS ALIVE: "+ playerClient.IsAlive() +" <- YOU" );
			}
			else
			{
				Print("Player ID: "+ p_uid +" IS ALIVE: "+ playerClient.IsAlive());
			}
		}

		//
		if ( player_uid == GetPlayerUID() || ( SgDeadcam.GetTarget() && SgDeadcam.GetTarget().GetPlayerUID() == player_uid ) || (m_DeadCamNextTarget && m_DeadCamNextTarget.GetPlayerUID() == player_uid ));
		{
			SgPlayerClient teammate = GetRandomAliveTeammate();

			if ( teammate )
			{
				// Team Is Alive - spactating random player
				m_DeadCamNextTarget = teammate;
			}
			else if ( details.m_Reason == ESgDeathReason.Player )
			{
				// Team is dead - spactating killer
				m_DeadCamNextTarget = GetPlayerByUID( details.m_KillerUID );
			}
			else
			{
				// Team is dead - spactating random enemy player
				SgPlayerClient enemy = GetRandomAliveEnemy();
				if ( enemy )
				{
					m_DeadCamNextTarget = enemy;
				}
			}

			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater( SgSClientGame.SnapDeathCamOnNextPlayer, 5000 );
		}
	}

	//========================================
	// SnapDeathCamOnNextPlayer
	//========================================
	static void SnapDeathCamOnNextPlayer()
	{
		if ( m_DeadCamNextTarget )
		{
			SgDeadcam.SetTarget( m_DeadCamNextTarget );
			m_DeadCamNextTarget = null;
		}
	}

	//============================================
	// SyncEvent_OnCollarBlockChanged
	//============================================
	static void SyncEvent_OnCollarBlockChanged( bool is_blocked )
	{
		m_IsCollarDamageBlocked = is_blocked;
	}

	//============================================
	// SyncEvent_OnCollarDamage
	//============================================
	static void SyncEvent_OnCollarDamage( string player_uid )
	{
		SgPlayerClient player = GetPlayerByUID( player_uid );

		if ( !player )
		{
			return;
		}
			
		if ( player_uid == m_Player.GetPlayerUID() )
		{
			float alfa = 0.01;
			float overlay = 0.05;

			PPEffects.SetColorCollar(alfa, overlay);
			PPEffects.SetBlurCollar(overlay);

			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater( PPEffects.ResetColorCollar, 100 );
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater( PPEffects.ResetBlurCollar, 100 );
		}

		if ( m_CollarBeep != null && m_CollarBeep.IsSoundPlaying() )
		{
			m_CollarBeep.SoundStop();
		}
				
		m_CollarBeep = SEffectManager.PlaySound(SgAudioManager.CollarTimer1sec, player.GetPlayerBase().GetPosition());
		m_CollarBeep.SetSoundAutodestroy(true);
	}

	//============================================
	// SyncEvent_OnCollarExplode
	//============================================
	static void SyncEvent_OnCollarExplode( string player_uid )
	{
		SgPlayerClient player = GetPlayerByUID( player_uid );

		if ( player.GetPlayerBase() )
		{
			vector head_position;
			MiscGameplayFunctions.GetHeadBonePos( player.GetPlayerBase(), head_position);

			SEffectManager.PlayInWorld( new SgEffCollarExplosion(), head_position );
		}
	}

	//============================================
	// Event_OnCasterCameraCreated
	//============================================
	static void Event_OnCasterCameraCreated( SgCasterCamera camera )
	{
		Event_OnCasterCameraCreated.Invoke( camera );
	}

	// SG_TODO: SG-929
	static void PostFrameUpdate()
	{
		/*switch (m_LocationType)
		{
			case ESgLocationType.PhaseFirst:
			{
				if (m_BallonFirst)
				{
					m_BallonFirst.PostFrameUpdate(true);		
				}	
					
				break;
			}
			case ESgLocationType.PhaseSecond:
			{
				if (m_BallonSecond)
				{
					m_BallonSecond.PostFrameUpdate(true);		
				}
				
				break;
			}
		}*/
		
		/*if ( m_GameState == ESgGameState.Transition )
		{
			if ( m_BallonFirst && m_LocationType == ESgLocationType.PhaseSecond )
			{				
				m_BallonFirst.PostFrameUpdate(false);
			}
			else if ( m_BallonSecond && m_LocationType == ESgLocationType.PhaseEnd )
			{
				m_BallonSecond.PostFrameUpdate(false);	
			}
		}*/
	}
	
	//============================================
	// GetPlayer
	//============================================
	static SgPlayerClient GetPlayer()
	{
		return m_Player;
	}

	//============================================
	// GetPlayerUID
	//============================================
	static string GetPlayerUID()
	{
		if ( m_PlayerUID == SG_UID_PLACEHOLDER )
		{
			m_PlayerUID = GetGame().GetPlayer().GetIdentity().GetId();
		}

		return m_PlayerUID;
	}

	//============================================
	// GetTeamID
	//============================================
	static int GetTeamID()
	{
		foreach ( SgSyncPlayerInfo player_info : m_PlayerUIDsTeams )
		{
			if ( player_info.m_PlayerUID == GetPlayerUID() )
			{
				return player_info.m_TeamId;
			}
		}
		
		return -1;
	}

	//============================================
	// GetSgPlayers
	//============================================
	static array<ref SgPlayerClient> GetPlayers()
	{
		return m_Players;
	}

	//============================================
	// GetAlivePlayers
	//============================================
	static array<SgPlayerClient> GetAlivePlayers()
	{
		ref array<SgPlayerClient> alive_players = new array<SgPlayerClient>();

		for ( int i = 0; i < m_Players.Count(); ++i )
		{
			if ( m_Players[i] && m_Players[i].IsAlive() )
			{
				alive_players.Insert( m_Players[i] );
			}
		}

		return alive_players;
	}
	
	//============================================
	// GetSgPlayers
	//============================================
	static array<string> GetTeammates()
	{
		return m_TeamPlayersUIDs;
	}

	//============================================
	// ImAlive
	//============================================
	static bool ImAlive()
	{
		return GetPlayer().IsAlive();
	}

	//============================================
	// RegisterClientPlayer
	//============================================
	static void RegisterClientPlayer(PlayerBase player)
	{
		m_UserPlayers.Insert(player);
	}

	//============================================
	// GetPlayerBaseByPlayerUID
	//============================================
	static PlayerBase GetPlayerBaseByPlayerUID(string player_uid)
	{
		for ( int i = 0; i < m_UserPlayers.Count(); ++i )
		{
			PlayerBase player = m_UserPlayers[i];
			PlayerIdentity identity = player.GetIdentity();
			
			if ( identity == null)
			{
				foreach ( SgSyncPlayerInfo playerInfo : m_PlayerUIDsTeams )
				{
					if ( playerInfo.m_PlayerUID == player_uid )
					{
						return PlayerBase.Cast( GetGame().GetObjectByNetworkId( playerInfo.m_LowBits, playerInfo.m_HighBits ) );	
					}
				}
				
				return null;
			}
			
			if ( identity.GetId() == player_uid )
			{
				return player;
			}
		}

		return null;
	}

	//============================================
	// GetPlayerByUID
	//============================================
	static SgPlayerClient GetPlayerByUID(string user_uid)
	{
		for ( int i = 0; i < m_Players.Count(); ++i )
		{
			SgPlayerClient player = m_Players[i];

			if ( player.GetPlayerUID() == user_uid )
			{
				return player;
			}
		}

		return null;
	}

	//============================================
	// GetGameState
	//============================================
	static ESgGameState GetGameState()
	{
		return m_GameState;
	}

	//============================================
	// GetLocationType
	//============================================
	static ESgLocationType GetLocationType()
	{
		return m_LocationType;
	}

	//============================================
	// GetPlayersAliveCount
	//============================================
	static int GetPlayersAliveCount()
	{
		return m_PlayersAliveCount;
	}

	//============================================
	// IsCollarDamageBlocked
	//============================================
	static bool IsCollarDamageBlocked()
	{
		return m_IsCollarDamageBlocked;
	}

	//============================================
	// GetPhaseTowerPositions
	//============================================
	static array<vector> GetPhaseTowerPositions( int phase_id )
	{
		SgJsonLocation location = m_JsonPgData.GetSetupLocation( phase_id );
		return location.m_BorderPositions;
	}
	
	//============================================
	// GetCollarDeactivator
	//============================================
	static SG_StaticCollarDeactivator GetCollarDeactivator()
	{
		return m_CollarDeactivator;
	}

	//============================================
	// SetCollarDeactivator
	//============================================
	static void SetCollarDeactivator( SG_StaticCollarDeactivator deactivator )
	{
		m_CollarDeactivator = deactivator;
		m_CollarDeactivator.ShowAlarm( GetGameState(), GetLocationType() );
	}

	//============================================
	// SetCurrentPhasePosition
	//============================================
	private static void SetCurrentPhasePosition( vector position )
	{
		m_CurrentPhasePosition = position;
	}

	//============================================
	// GetCurrentPhasePosition
	//============================================
	static vector GetCurrentPhasePosition()
	{
		return m_CurrentPhasePosition;
	}

	//============================================
	// SetDeadcam
	//============================================
	static void SetDeadcam( SgDeadcam dead_cam )
	{
		m_Deadcam = dead_cam;

		Event_OnDeadcamStart.Invoke();
	}


	//============================================
	// GetRandomAliveEnemy
	//============================================
	static SgPlayerClient GetRandomAliveEnemy()
	{
		for ( int i = 0; i < m_Players.Count(); ++i )
		{
			SgPlayerClient player = m_Players[i];

			for ( int j = 0; j < m_TeamPlayersUIDs.Count(); ++j )

			if ( m_TeamPlayersUIDs[j] != player.GetPlayerUID() )
			{
				if ( player.IsAlive() )
				{
					return player;
				}
			}
		}

		return null;
	}

	//============================================
	// GetRandomAliveTeammate
	//============================================
	static SgPlayerClient GetRandomAliveTeammate()
	{
		for ( int i = 0; i < m_Players.Count(); ++i )
		{
			SgPlayerClient player = m_Players[i];

			for ( int j = 0; j < m_TeamPlayersUIDs.Count(); ++j )
			{
				Print("player: " + player.GetUserName() + " teammate id:: " + m_TeamPlayersUIDs[j] );

				if ( m_TeamPlayersUIDs[j] == player.GetPlayerUID() && player.IsAlive() )
				{
					Print("This is your alive teammate: " + m_TeamPlayersUIDs[j]);
					return player;
				}
			}
		}

		return null;
	}

	//============================================
	// IsTeamAlive
	//============================================
	static bool IsTeamAlive()
	{
		return ( GetRandomAliveTeammate() != null );
	}

	//============================================
	// SetPgID
	//============================================
	private static void SetPgID( int pg_id )
	{
		GetSgGame().SetPlaygroundID( pg_id );

		m_JsonPgData = SgSResourceHandler.PlaygroundSetupLoad( pg_id );
	}

	//============================================
	// SetPlayersAliveCount
	//============================================
	private static void SetPlayersAliveCount( int players_alive_count )
	{
		m_PlayersAliveCount = players_alive_count;
		Event_OnGamePlayersAliveCount.Invoke( m_PlayersAliveCount );
	}

	//============================================
	// SetPlayerUIDs
	//============================================
	private static void SetPlayerUIDs( array<ref SgSyncPlayerInfo> player_ids_team_ids )
	{
		PlayerBase local_player = PlayerBase.Cast( GetGame().GetPlayer() );
		string local_player_uid = local_player.GetIdentity().GetId();

		foreach ( SgSyncPlayerInfo playerInfo : player_ids_team_ids )
		{
			m_PlayerUIDsTeams.Insert( playerInfo );
			
			string p_uid = playerInfo.m_PlayerUID;
			int t_id = playerInfo.m_TeamId;
			
			ref SgPlayerClient sg_player = new SgPlayerClient( p_uid, playerInfo.m_PlayerName, t_id );
			m_Players.Insert( sg_player );

			if ( p_uid == local_player_uid )
			{
				m_Player = sg_player;
			}
		}
	}
	
	//============================================
	// SetTeammateIDs
	//============================================
	private static void SetTeammateUIDs( array<string> teammate_uids )
	{
		Print("Client User Name: "+ GetPlayer().GetUserName() +" player UID: "+ GetPlayer().GetPlayerUID() );
		Print("Teammates:");
		teammate_uids.Debug();

		m_TeamPlayersUIDs.Copy( teammate_uids );
	}

	//============================================
	// SetGamePhase
	//============================================
	private static void SetGamePhase( ESgGameState game_state, ESgLocationType location_type, int duration_time )
	{
		m_GameState = game_state;
		m_LocationType = location_type;
		m_LocationDuration = duration_time;
	}

	//============================================
	// SetPoI
	//============================================
	private static void SetPoI( ESgLocationType type, vector location_position )
	{
		switch (type)
		{
			case ESgLocationType.PoICar:
			{
				m_CarPositions.Insert( location_position );
				break;
			}
			case ESgLocationType.PoIHeli:
			{
				m_HeliPositions.Insert( location_position );
				break;
			}
		}
	}
}
