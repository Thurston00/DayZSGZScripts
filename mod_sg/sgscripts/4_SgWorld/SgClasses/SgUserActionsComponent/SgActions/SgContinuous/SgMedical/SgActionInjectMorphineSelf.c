modded class ActionInjectMorphineSelf
{
	const int PERCENTAGE_HEAL_HEALTH = 75;
	
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
			
		action_data.m_Player.AddHealthEntirePlayer( PERCENTAGE_HEAL_HEALTH );	
	}
};