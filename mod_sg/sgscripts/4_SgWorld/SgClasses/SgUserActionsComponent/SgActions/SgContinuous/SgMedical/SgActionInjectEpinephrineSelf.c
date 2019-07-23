modded class ActionInjectEpinephrineSelf
{
	const int PERCENTAGE_HEAL_COUNSCIOUS = 30;
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		int max_health = player.GetMaxHealth("GlobalHealth", "Health");
		
		if ( player.GetClientHealth() != max_health )
		{
			return true;
		}
		
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{	
		super.OnExecuteServer( action_data );
		
		int max_health = action_data.m_Player.GetMaxHealth("GlobalHealth", "Health");
		
		action_data.m_Player.AddHealth("GlobalHealth", "Health", ( ( max_health / 100 ) * PERCENTAGE_HEAL_COUNSCIOUS ) );
	}
	
	override void ApplyModifiers( ActionData action_data )
	{
		
	}
};