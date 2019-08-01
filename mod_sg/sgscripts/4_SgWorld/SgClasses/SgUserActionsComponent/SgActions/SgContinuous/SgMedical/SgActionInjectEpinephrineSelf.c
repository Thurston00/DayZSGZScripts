modded class ActionInjectEpinephrineSelf
{
	const int PERCENTAGE_HEAL_COUNSCIOUS = 30;
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		int max_health = player.GetMaxHealth("GlobalHealth", "Health");
		int current_stamina = player.GetStaminaHandler().GetStamina();
		int max_stamina = player.GetStaminaHandler().GetStaminaMax();
		
		if ( player.GetClientHealth() != max_health || current_stamina != max_stamina )
		{
			return true;
		}
		
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{	
		super.OnExecuteServer( action_data );
		
		action_data.m_Player.AddHealthEntirePlayer( PERCENTAGE_HEAL_COUNSCIOUS );	
	}
	
	override void ApplyModifiers( ActionData action_data )
	{
		action_data.m_MainItem.OnApply(action_data.m_Player);
	}
};