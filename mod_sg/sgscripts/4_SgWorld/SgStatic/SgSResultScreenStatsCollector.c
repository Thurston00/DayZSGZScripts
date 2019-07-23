class SgSResultScreenStatsCollector
{
	protected static ref SgNetServerDataGameFinishRequest m_StatsData 		= new SgNetServerDataGameFinishRequest();
	protected static ref array<int> m_TeamIds								= new array<int>();
	
	//==================================
	// Init
	//==================================
	static void InitEvents()
	{
		SgSManagerEventsServer.Event_OnGameStarted.Insert( Event_OnGameStarted );
		SgSManagerEventsServer.Event_OnSgPlayerDied.Insert( Event_OnSgPlayerDied );
		SgSManagerEventsServer.Event_OnZombieDied.Insert( Event_OnZombieDied );
	}
	
	//============================================
	// SyncEvent_OnGameStarted
	//============================================
	static void Event_OnGameStarted()
	{
		map<int, ref SgTeam> teams = SgSManagerPlayers.GetTeams();
		foreach ( SgTeam team : teams )
		{
			array<ref SgNetDataPlayerResult> players_result_list = new array<ref SgNetDataPlayerResult>();
			
			array<ref SgPlayer> players = team.GetPlayers();
			foreach ( SgPlayer player : players )
			{
				players_result_list.Insert( new SgNetDataPlayerResult( player.GetPlayerUID() ) );
			}
			
			m_StatsData.GetTeamResultList().Insert( team.GetTeamID(), new SgNetDataTeamResult( team.GetTeamID(), players_result_list ) );
			m_TeamIds.Insert( team.GetTeamID() );
		}
	}
	
	//==================================
	// Event_OnSgPlayerDied
	//==================================
	static void Event_OnSgPlayerDied( SgPlayer sg_player, SgDeathDetails details )
	{		
		if (details.m_Reason == ESgDeathReason.Player && details.m_KillerUID.Length() > 0) // Checking lenght since zombie in script IsPlayer() method returns true..
		{
			string killer_uid = details.m_KillerUID;
			int team_id = SgSManagerPlayers.GetSgPlayerByPlayerUID(killer_uid).GetTeamID();
			
			SgNetDataPlayerResult player_result = m_StatsData.GetTeamResultList()[team_id].GetDataPlayerResult(killer_uid);
			player_result.AddKilledPlayer( new SgNetDataPlayerKillResult( sg_player.GetPlayerUID(), details.m_Reason, SgEKillType.NORMAL, "" ) );
		}
		
		CheckIfTeamIsDead( SgSManagerPlayers.GetSgPlayerByPlayerUID( sg_player.GetPlayerUID() ).GetTeamID() );
	}
	
	//==================================
	// Event_OnSgPlayerDied
	//==================================
	static void Event_OnZombieDied( ZombieBase zombie, string killer_uid )
	{
		if ( killer_uid != SG_UID_PLACEHOLDER )
		{
			int team_id = SgSManagerPlayers.GetSgPlayerByPlayerUID(killer_uid).GetTeamID();
			
			SgNetDataPlayerResult player_result = m_StatsData.GetTeamResultList()[team_id].GetDataPlayerResult(killer_uid);
			player_result.AddZombieKill();
		}
	}
	
	//----------------------------------
	// CheckIfTeamIsDead
	//----------------------------------
	protected static void CheckIfTeamIsDead(int team_id)
	{		
		SgTeam team = SgSManagerPlayers.GetTeamByID(team_id);
		
		array<ref SgPlayer> players = team.GetPlayers();
		foreach ( SgPlayer player : players )
		{
			if (player.IsAlive() == true)
			{
				return;
			}
		}
		
		if ( m_TeamIds.Find(team_id) != -1 )
		{
			SendTeamStats(team_id);
			
			if ( m_TeamIds.Count() == 1 )
			{
				team_id = m_TeamIds[0];
				SendTeamStats(team_id);
				
				SgSManagerEventsServer.Event_OnGameFinished( team_id );
			}
		}
	}
	
	//----------------------------------
	// CheckIfTeamIsDead
	//----------------------------------
	protected static void SendTeamStats(int team_id)
	{	
		SgNetDataTeamResult team_result = m_StatsData.GetTeamResultList()[team_id];
		team_result.SetRank( m_TeamIds.Count() );
		
		m_TeamIds.RemoveItem(team_id);
		
		SgSManagerEventsServer.Event_OnTeamDeadStats(team_result);
	}
	
	//==================================
	// GetStatsData
	//==================================
	static SgNetServerDataGameFinishRequest GetStatsData()
	{
		return m_StatsData;
	}
}

//==================================
// Debug
//==================================
static void Debug(SgNetDataTeamResult stats)
{
	Print( "Rank: " + stats.GetRank().ToString() );
	
	array<ref SgNetDataPlayerResult> player_list = stats.GetPlayerResultList();
	foreach ( SgNetDataPlayerResult player : player_list )
	{		
		Print( "Player UID: " + player.GetPlayerUID() );
		Print( "Zombie Kills: " + player.GetZombieKills().ToString() );	
		
		array<ref SgNetDataPlayerKillResult> players_kill_lists = player.GetPlayerKillsList();
		foreach ( SgNetDataPlayerKillResult player_kill_list : players_kill_lists )
		{
			Print( "Killed: " + player_kill_list.GetPlayerUID() );	
		}
	}
}