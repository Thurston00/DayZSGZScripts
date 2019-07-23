// DESIGN_ID: 0001

/*
	SG network data class for team results
*/
class SgNetDataTeamResult
{			
	private int m_TeamId;							
	private int m_Rank;
	private ref array<ref SgNetDataPlayerResult> m_PlayerResultList;
	
	void SgNetDataTeamResult( int team_id, array<ref SgNetDataPlayerResult> players_result_list )
	{
		m_TeamId = team_id;
		m_PlayerResultList 	= players_result_list;
	}
	
	// ----------------------------------------
	// SETTERS
	void SetRank( int rank )
	{
		m_Rank = rank;
	}
	
	// ----------------------------------------
	// GETTERS
	int GetTeamId()
	{
		return m_TeamId;
	}
	int GetRank()
	{
		return m_Rank;
	}
	array<ref SgNetDataPlayerResult> GetPlayerResultList()
	{
		return m_PlayerResultList;
	}
	// Count all zombie kills for the team 
	int GetZombieKillsCount()
	{
		int zombie_kills = 0;
		
		foreach (SgNetDataPlayerResult player : m_PlayerResultList)
		{
			zombie_kills += player.GetZombieKills();
		}
		return zombie_kills;
	}
	// Count all player kills for the team
	int GetPlayerKillsCount()
	{
		int player_kills = 0;
		
		foreach (SgNetDataPlayerResult player : m_PlayerResultList)
		{
			player_kills += player.GetPlayerKillsList().Count();
		}
		return player_kills;
	}
	
	SgNetDataPlayerResult GetDataPlayerResult( string player_uid )
	{
		foreach ( SgNetDataPlayerResult player_result : m_PlayerResultList )
		{
			if ( player_result.GetPlayerUID() == player_uid )
			{
				return player_result;
			}
		}
		return null;
	}
}