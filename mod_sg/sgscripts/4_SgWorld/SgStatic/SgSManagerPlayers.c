class SgSManagerPlayers
{
	// Allowed Players UIDs to Join Server
	static protected ref array<string> m_AllowedPlayersUIDs;
	
	// Player Object
	static protected ref array<ref SgPlayer> m_Players;
	
	// Player UID = Player Object
	static protected ref map<string, ref SgPlayer> m_PlayersByPlayerUID;
	
	// Team ID = Team Object
	static protected ref map<int, ref SgTeam> m_Teams;
	
	//==================================
	// Init
	//==================================
	static void InitEvents()
	{
		m_Players 				= new array<ref SgPlayer>;
		m_PlayersByPlayerUID 	= new map<string, ref SgPlayer>;
		m_Teams 				= new map<int, ref SgTeam>;
		
		SgSManagerEventsServer.Event_OnUserConnected.Insert(SgSManagerPlayers.Event_OnUserConnected);
		SgSManagerEventsServer.Event_OnGameServerMatchInfoLoaded.Insert(Event_OnGameServerMatchInfoLoaded);
		SgSManagerEventsServer.Event_OnGameTimeSecond.Insert(Event_OnGameTimeSecond);
		
		string forceCustomPlayers;
		if ( GetGame().CommandlineGetParam("sgForceCustomPlayers", forceCustomPlayers) )
		{
			SgNetServerDataMatchLoadResponse matchInfo = SgSResourceHandler.LoadGameServerMatchInfo();
			
			SgPluginGameServer.GetInstance().SetMatchId( matchInfo.GetMatchId() );
			Event_OnGameServerMatchInfoLoaded( matchInfo );
		}
	}
	
	//==================================
	// InsertPlayer
	//==================================
	protected static void InsertPlayer(SgPlayer sg_player)
	{
		m_Players.Insert( sg_player );
		m_PlayersByPlayerUID.Insert( sg_player.GetPlayerUID(), sg_player );
	}
	
	//==================================
	// Event_OnGameServerMatchInfoLoaded
	//==================================
	static void Event_OnGameServerMatchInfoLoaded( SgNetServerDataMatchLoadResponse matchInfo )
	{
		// SG_TODO: Add/Prepare for data for Casters .. see this commit to see the old logic which was removed.
		m_AllowedPlayersUIDs = new array<string>();
		
		// SG_TODO: Spawn at warm up position
		SgLocation start_location = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PhaseStart );
		vector spawn_pos = start_location.GetPosition();
		
		Print( "Event_OnGameServerMatchInfoLoaded");
		
		array<ref SgNetDataMatchPlayer> players_list = matchInfo.GetPlayerList();
		foreach ( SgNetDataMatchPlayer playerInfo : players_list )
		{
			string player_uid = playerInfo.GetPlayerUID();
			int team_id = playerInfo.GetTeamId();
			
			
			Print( "GetPlayerUID : " + playerInfo.GetPlayerUID() );
			Print( "GetSteamName : " + playerInfo.GetSteamName() );
			Print( "GetTeamId : " + playerInfo.GetTeamId() );
			
			m_AllowedPlayersUIDs.Insert(player_uid);
			
			Entity playerEnt = GetGame().CreatePlayer(null, GetGame().CreateRandomPlayer(), spawn_pos, 0, "NONE");
			PlayerBase player = PlayerBase.Cast(playerEnt);		
			SgPlayer sg_player = new SgPlayer( player, player_uid, playerInfo.GetSteamName() );
		
			player.SetSgPlayer( sg_player );
			
			InsertPlayer( sg_player );

			SgTeam team = GetTeamByID( team_id );
			if ( team == null )
			{
				Print("Event_OnGameServerMatchInfoLoaded Team Create with TeamID: " + team_id.ToString());
				team = SgSManagerPlayers.RegisterTeam( team_id );
				//team_new.SetName( "" ); // SG_TODO
				//team_new.SetColour( 0 ); // SG_TODO
			}
			
			team.PlayerInsert( sg_player );
			sg_player.SetTeamID( team_id );
			
			Print("------------------------------");
		}
		
		SgLocationPhaseStart.Cast(SgSManagerPlayground.GetLocations()[0]).TeleportPlayersAtStartingPosition();
		
		if ( SgEResult.ERROR == SgSNetworkServiceWrapper.GameServerIsReady() )
		{
			// SG_TODO
		}
		
		PlayersWearTeamCloth();
		
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SgPluginGameServer.GetInstance().PrepareForGameStart, SG_TIME_WARM_UP_DURATION); // SG_TODO WarmUp handler
	}
	
	//==================================
	// Event_OnPlayerConnected
	//==================================
	static void Event_OnUserConnected( PlayerIdentity identity )
	{
		SgPlayer sg_player = GetSgPlayerByPlayerUID( identity.GetId() );
		
		if ( sg_player )
		{
			GetGame().SelectPlayer(identity, sg_player.GetPlayerBase());
			sg_player.PostInit();
			
			if ( SgPluginGameServer.GetInstance().GetGameState() == ESgGameState.WarmUp )
			{
				SgSManagerEventsServer.Event_OnWarmUpPlayerJoined(sg_player);
			}
			else
			{
				SgSManagerEventsServer.Event_OnSgPlayerReconnected(sg_player);
			}
		}
		else
		{
			Print("SgSManagerPlayers.Event_OnUserConnected => user: " + identity.GetName() + "with hash ID: " + identity.GetId() + " kicked.");			
			
#ifdef DEVELOPER
			string forceCustomPlayers;
			if ( GetGame().CommandlineGetParam("sgForceCustomPlayers", forceCustomPlayers))
			{
				Error("Player kicked because no matching player found with Hash ID: " + identity.GetId() + "\n\n To play, insert this Hash ID into mod_sg/Server/InitData/SgForceCustomPlayers.json.\n\n");
			}
#endif
			return;
		}
	}
	
	//==================================
	// Event_OnGameTimeSecond
	//==================================
	static void Event_OnGameTimeSecond( int secods_left )
	{
		foreach ( SgPlayer sg_player : m_Players )
		{
			if ( sg_player )
			{
				sg_player.CheckConnectionTimeOut();
			}
		}
		
	}
	
	//==================================
	// Event_OnPlayerConnected
	//==================================
	static void OnUserReconnected( PlayerIdentity identity )
	{
		SgPlayer sg_player = GetSgPlayerByPlayerUID( identity.GetId() );
		PlayerBase player;
		
		if ( sg_player )
		{
			SgSManagerEventsServer.Event_OnSgPlayerReconnected(sg_player);
		}
		else
		{
			Print("SgSManagerPlayers.Event_OnUserReconnected => user: " + identity.GetName() + "with UID: " + identity.GetId() + " kicked.");
			return;
		}
	}
	
	//==================================
	// GetSgPlayerByPlayerUID
	//==================================
	static SgPlayer GetSgPlayerByPlayerUID(string user_uid)
	{		
		if ( m_PlayersByPlayerUID.Contains( user_uid ) )
		{
			return m_PlayersByPlayerUID[ user_uid ];
		}
		
		return null;
	}
	
	//==================================
	// GetSgPlayerByPlayerBase
	//==================================
	static SgPlayer GetSgPlayerByPlayerBase(PlayerBase player_base)
	{	
		foreach ( SgPlayer sg_player : m_Players )
		{
			if ( sg_player.GetPlayerBase() == player_base )
			{
				return sg_player;
			}
		}
		
		return null;
	}
	
	//==================================
	// GetPlayerIdentityByPlayerUID
	//==================================
	static PlayerIdentity GetPlayerIdentityByPlayerUID(string user_uid)
	{		
		if ( m_PlayersByPlayerUID.Contains( user_uid ) )
		{
			return m_PlayersByPlayerUID[ user_uid ].GetPlayerBase().GetIdentity();
		}
		
		return null;
	}
	
	//==================================
	// GetPlayers
	//==================================
	static array<ref SgPlayer> GetSgPlayers()
	{
		return m_Players;
	}
	
	//==================================
	// GetPlayersCount
	//==================================
	static int GetPlayersCount()
	{
		if ( m_Players )
		{
			return m_Players.Count();
		}
		
		return 0;
	}
	
	//==================================
	// GetPlayersAliveCount
	//==================================
	static int GetPlayersAliveCount()
	{
		int count = 0;

		if ( m_Players )
		{
			for ( int i = 0; i < m_Players.Count(); ++i )
			{
				if ( m_Players[i] && m_Players[i].IsAlive() )
				{
					++count;
				}
			}
		}
		
		return count;
	}
	
	//==================================
	// GetConnectedUsersCount
	//==================================
	static int GetConnectedUsersCount()
	{
		int count = 0;

		if ( m_Players )
		{
			for ( int i = 0; i < m_Players.Count(); ++i )
			{
				if ( m_Players[i] && m_Players[i].GetIsUserConnected() )
				{
					++count;
				}
			}
		}
		
		return count;
	}
	
	//===================================
	// GetPlayersStateFormated
	//===================================
	static string GetPlayersStateFormated()
	{
		return "Alive Teams: "+ SgSManagerPlayers.GetTeamsAliveCount() +" Alive Players: "+ SgSManagerPlayers.GetPlayersAliveCount();
	}
	
	//==================================
	// RegisterTeam
	//==================================
	protected static SgTeam RegisterTeam( int team_id )
	{
		if ( m_Teams == NULL )
		{
			m_Teams = new map<int, ref SgTeam>;
		}

		ref SgTeam team = new SgTeam( team_id );
		m_Teams.Insert( team_id, team );
		
		return team;	
	}
	
	//==================================
	// GetTeams
	//==================================
	static map<int, ref SgTeam> GetTeams()
	{
		return m_Teams;
	}
	
	//==================================
	// GetTeamsArr
	//==================================
	static array<ref SgTeam> GetTeamsArr()
	{
		array<ref SgTeam> teams_cpy		= new array<ref SgTeam>;
		map<int, ref SgTeam> teams		= GetTeams();
		
		foreach( SgTeam team_cpy : teams )
		{
			teams_cpy.Insert(team_cpy);
		}
		
		return teams_cpy;
	}
	
	//==================================
	// GetTeam
	//==================================
	static SgTeam GetTeamByID( int id )
	{
		if ( !m_Teams )
		{
			m_Teams = new map<int, ref SgTeam>;
		}
		
		for ( int i = 0; i < m_Teams.Count(); ++i )
		{
			int team_id = m_Teams.GetKey( i );
			
			if ( team_id == id )
			{
				return m_Teams[team_id];
			}
		}
		return null;
	}

	//==================================
	// GetTeamByName
	//==================================
	static SgTeam GetTeamByName( string name )
	{
		if ( !m_Teams )
		{
			m_Teams = new map<int, ref SgTeam>;
		}
		
		for ( int i = 0; i < m_Teams.Count(); ++i )
		{
			int team_id = m_Teams.GetKey( i );
			
			if ( m_Teams[team_id].GetName() == name )
			{
				return m_Teams[team_id];
			}
		}
		return null;
	}
	
	//==================================
	// GetTeamForPlayer
	//==================================
	static SgTeam GetTeamForPlayer( PlayerBase player )
	{		
		foreach ( SgTeam team : m_Teams )
		{
			array<ref SgPlayer> team_players = team.GetPlayers();
			foreach ( SgPlayer sgPlayer : team_players )
			{
				if (sgPlayer.GetPlayerBase() == player)
				{
					return team;
				}
			}
		}
		
		return null;
	}
	
	//==================================
	// GetTeamsAliveCount
	//==================================
	static int GetTeamsAliveCount()
	{
		int count = 0;
		
		for ( int i = 0; i < m_Teams.Count(); ++i )
		{
			int team_id = m_Teams.GetKey( i );
			
			if ( m_Teams[team_id].IsAlive() )
			{
				count++;
			}
		}	
		
		return count;
	}
	
	//----------------------------------
	// PlayersLockMovement 
	//----------------------------------
	// Holds player on place, when inventory is opened during the starting circle
	static void PlayersLockMovement(bool lock)
	{	
		for(int i = 0; i < m_Players.Count(); ++i)
		{
			m_Players[i].LockMovement( lock );
		}
	}
	

	//==================================
	// GetTeamsGear
	//==================================
	static array<string> GetTeamsGear(int team_index)
	{
		ref array<string> gear = new array<string>;
		gear.Insert("JoggingShoes_White");
		//TODO: Add gear for more teams.
		switch( team_index )
		{
			case 0:
			{
				gear.Insert("TShirt_Blue");
				gear.Insert("TrackSuitPants_Green");
				break;
			}
			case 1:
			{
				gear.Insert("TShirt_OrangeWhiteStripes");
				gear.Insert("TrackSuitPants_Blue");
				break;
			}
			case 2:
			{
				gear.Insert("TShirt_Red");
				gear.Insert("TrackSuitPants_LightBlue");
				break;
			}
			case 3:
			{
				gear.Insert("TShirt_RedBlackStripes");
				gear.Insert("TrackSuitPants_Blue");
				break;
			}
			case 4:
			{
				gear.Insert("TShirt_Blue");
				gear.Insert("TrackSuitPants_Red");
				break;
			}
			case 5:
			{
				gear.Insert("TShirt_OrangeWhiteStripes");
				gear.Insert("TrackSuitPants_Green");
				break;
			}
			case 6:
			{
				gear.Insert("TShirt_Red");
				gear.Insert("TrackSuitPants_Green");
				break;
			}
			case 7:
			{
				gear.Insert("TShirt_RedBlackStripes");
				gear.Insert("TrackSuitPants_LightBlue");
				break;
			}
			case 8:
			{
				gear.Insert("TShirt_Blue");
				gear.Insert("TrackSuitPants_Blue");
				break;
			}
			case 9:
			{
				gear.Insert("TShirt_OrangeWhiteStripes");
				gear.Insert("TrackSuitPants_LightBlue");
				break;
			}
			case 10:
			{
				gear.Insert("TShirt_Red");
				gear.Insert("TrackSuitPants_Blue");
				break;
			}
			case 11:
			{
				gear.Insert("TShirt_RedBlackStripes");
				gear.Insert("TrackSuitPants_Red");
				break;
			}
			case 12:
			{
				gear.Insert("TShirt_Blue");
				gear.Insert("TrackSuitPants_LightBlue");
				break;
			}
			case 13:
			{
				gear.Insert("TShirt_OrangeWhiteStripes");
				gear.Insert("TrackSuitPants_Red");
				break;
			}
			case 14:
			{
				gear.Insert("TShirt_Red");
				gear.Insert("TrackSuitPants_Red");
				break;
			}
			case 15:
			{
				gear.Insert("TShirt_RedBlackStripes");
				gear.Insert("TrackSuitPants_Green");
				break;
			}
		}
		
		return gear;
	}
	
	//----------------------------------
	// PlayersWearCloth
	//----------------------------------
	static void PlayersWearTeamCloth()
	{		
		map<int, ref SgTeam> teams = SgSManagerPlayers.GetTeams();
		for(int i = 0; i < teams.Count(); i++)
		{
			SgTeam team = teams.GetElement( i );
			array<string> gear = GetTeamsGear( i );
			array<ref SgPlayer> players = team.GetPlayers();
			
			for(int j = 0; j < players.Count(); j++)
			{
				SgPlayer sg_player = players[j];
				
				if( sg_player )
				{
					for(int k = 0; k < gear.Count(); k++)
					{
						sg_player.GetPlayerBase().CreateInInventory( gear[k] );
					}
				}
			}			
		}
	}
	
	//----------------------------------
	// PlayersAttachCollar
	//----------------------------------
	static void PlayersAttachCollar()
	{				
		for (int p = 0; p < m_Players.Count(); p++)
		{
			SgPlayer sg_player = m_Players[p];
			
			sg_player.GetSG_Collar().AttachOnPlayer();
		}			
	}	
}