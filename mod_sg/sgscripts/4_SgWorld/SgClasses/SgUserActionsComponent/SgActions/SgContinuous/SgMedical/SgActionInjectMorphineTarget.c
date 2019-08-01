modded class ActionInjectMorphineTarget
{
	const int PERCENTAGE_HEAL_HEALTH = 75;
	
	void ActionInjectMorphineTarget()
	{		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INJECTIONTARGET;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
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
				
		PlayerBase player_target = PlayerBase.Cast( action_data.m_Target.GetObject() );
		player_target.AddHealthEntirePlayer( PERCENTAGE_HEAL_HEALTH );
	}
};