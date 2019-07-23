// DESIGN_ID: 0001

/*
	SG network data class for player results
*/
class SgNetDataPlayerResult
{			
	private string m_PlayerUID;							
	private int m_ZombieKills 											= 0;
	private ref array<ref SgNetDataPlayerKillResult> m_PlayerKillsList 	= new array<ref SgNetDataPlayerKillResult>;
	
	void SgNetDataPlayerResult( string player_uid )
	{
		m_PlayerUID = player_uid;
	}
	
	// ----------------------------------------
	// SETTERS
	void AddKilledPlayer( SgNetDataPlayerKillResult kill_result )
	{
		m_PlayerKillsList.Insert(kill_result);
	}
	
	void AddZombieKill()
	{
		m_ZombieKills++;
	}

	// ----------------------------------------
	// GETTERS
	string GetPlayerUID()
	{
		return m_PlayerUID;
	}
	int GetZombieKills()
	{
		return m_ZombieKills;
	}
	array<ref SgNetDataPlayerKillResult> GetPlayerKillsList()
	{
		return m_PlayerKillsList;
	}
}