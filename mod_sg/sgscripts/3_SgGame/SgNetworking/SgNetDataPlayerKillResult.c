// DESIGN_ID: 0001

/*
	SG network data class for player kill result. Basically holds information about the victim that died by the player that holds/has an instance of this class
*/
class SgNetDataPlayerKillResult
{			
	private string m_PlayerUID;							// Id of the killed player 		
	private ESgDeathReason m_DeathReason;				// The source of player death
	private SgEKillType m_KillType;						// The way how the player was killed when by source
	private string m_Weapon;							// The weapon used to kill the player
	
	void SgNetDataPlayerKillResult( string player_uid, ESgDeathReason death_reason, SgEKillType kill_type, string weapon )
	{
		m_PlayerUID	 	= player_uid;
		m_DeathReason 	= death_reason;
		m_KillType		= kill_type;
		m_Weapon		= weapon;
	}
	
	// ----------------------------------------
	// GETTERS
	string GetPlayerUID()
	{
		return m_PlayerUID;
	}
	SgEKillType GetKillType()
	{
		return m_KillType;
	}
	string GetWeapon()
	{
		return m_Weapon;
	}
}