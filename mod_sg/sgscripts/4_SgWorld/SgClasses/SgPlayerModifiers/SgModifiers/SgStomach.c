modded class StomachMdfr
{
	protected const float STOMACH_EMPTIED_PER_SEC = 2;
	protected const float OPTIMAL_HEALING_COEF = 5;
	protected const float DEFAULT_HEALING_COEF = 2;
	
	protected float m_HealingRate;
	
	override void OnTick(PlayerBase player, float deltaT)
	{
		// Ivo -
		float stomach_volume = player.m_PlayerStomach.GetStomachVolume();
		//Print( "************************************" );
		
		Print("stomach_volume" + stomach_volume.ToString());
		if ( stomach_volume > 0 )
		{	
			
			float min_optimal_range = ( SG_STOMACH_CAPACITY / 100 ) * SG_MIN_OPTIMAL_HEAL_RANGE;
			float max_optimal_range = ( SG_STOMACH_CAPACITY / 100 ) * SG_MAX_OPTIMAL_HEAL_RANGE;
			
			if ( stomach_volume >= min_optimal_range && stomach_volume <= max_optimal_range )
			{
				float optimal_digest_rate = deltaT * OPTIMAL_HEALING_COEF;
				//Print("optimal health: " + ( GetRegenRateHealth( player, optimal_digest_rate ) * OPTIMAL_HEALING_COEF ) );
				player.AddHealth("GlobalHealth", "Health" , ( GetRegenRateHealth( player, optimal_digest_rate ) ) );
			}
			else
			{
				float default_digest_rate = deltaT * DEFAULT_HEALING_COEF;
				//Print("default health: " + ( GetRegenRateHealth( player, default_digest_rate ) * DEFAULT_HEALING_COEF ) );
				player.AddHealth("GlobalHealth", "Health" , ( GetRegenRateHealth( player, default_digest_rate ) ) );
			} 
		}
		
		player.m_PlayerStomach.Update( deltaT * STOMACH_EMPTIED_PER_SEC );
		float new_stomach_volume = player.m_PlayerStomach.GetStomachVolume();

		if ( new_stomach_volume > SG_STOMACH_CAPACITY )
		{
			return;
		}
		
		player.SetStomachVolume( new_stomach_volume );
				
		//Print("Digest rate: " + digest_rate);
		//Print("Stomach full to: " + ( ( stomach_volume / SG_STOMACH_CAPACITY ) * 100 ) + " percent" );
	}
	
	float GetRegenRateHealth( PlayerBase player, float digest_rate )
	{
		float player_health_max = player.GetMaxHealth( "GlobalHealth", "Health" );
		float stomach_to_health = SG_STOMACH_CAPACITY / player_health_max;
		float regen_health = digest_rate / stomach_to_health;
	
		return regen_health;
	}	
};