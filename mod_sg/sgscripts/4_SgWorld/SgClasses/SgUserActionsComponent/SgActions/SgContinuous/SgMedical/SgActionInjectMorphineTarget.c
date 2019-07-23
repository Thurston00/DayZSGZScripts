modded class ActionInjectMorphineTarget
{
	const int PERCENTAGE_HEAL_HEALTH = 75;
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		PlayerBase player_target = PlayerBase.Cast( target.GetObject() );
		int max_health = player_target.GetMaxHealth("GlobalHealth", "Health");
		
		if ( player_target.GetClientHealth() != max_health && !player_target.IsUnconscious() )
		{
			return true;
		}
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{	
		super.OnExecuteServer( action_data );
		
		int max_health = action_data.m_Player.GetMaxHealth("GlobalHealth", "Health");
		
		PlayerBase player_target = PlayerBase.Cast( action_data.m_Target.GetObject() );
		player_target.AddHealth("GlobalHealth", "Health", ( ( max_health / 100 ) * PERCENTAGE_HEAL_HEALTH ) );
	}
};