modded class UnconsciousnessMdfr
{
	const int UNCONSCIOUS_TIME_TO_DIE = 60; // in seconds
	
	override void Init()
	{
		m_TrackActivatedTime 	= false;
		m_ID 					= eModifiers.MDF_UNCONSCIOUSNESS;
		m_TickIntervalInactive 	= 0.5;
		m_TickIntervalActive 	= 0.1;
	}	
	
	override bool ActivateCondition(PlayerBase player)
	{	
		return player.IsUnconscious();
	}
	
	override void OnActivate(PlayerBase player)
	{
		
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		if ( player.GetHealth("GlobalHealth", "Health") == 0 )
		{
			player.SetHealth("GlobalHealth", "Health", 0.01); // Next 2 lines of code will not take effect if this would not be called first.
			player.SetCanBeDestroyed(true);
			player.SetHealth("GlobalHealth", "Health", 0);
		}
		else
		{
			player.m_BleedingManagerServer.EnableAddingNewBleedingSources(true);
		}
	}
	
	override void OnReconnect(PlayerBase player)
	{
		
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		return !player.IsUnconscious() || player.GetHealth("GlobalHealth", "Health") == 0;
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		player.AddHealth("GlobalHealth", "Health", ( player.GetMaxHealth("GlobalHealth", "Health") / UNCONSCIOUS_TIME_TO_DIE ) * deltaT * -1 );
	}
};