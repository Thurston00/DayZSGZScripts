modded class ActionInjectEpinephrineTarget
{
	const int PERCENTAGE_HEAL_COUNSCIOUS = 30;
	const int PERCENTAGE_HEAL_UNCOUNSCIOUS = 10;
	
	void ActionInjectEpinephrineTarget()
	{
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		PlayerBase player_target = PlayerBase.Cast( target.GetObject() );
		int max_health = player_target.GetMaxHealth("GlobalHealth", "Health");
		
		if ( player_target.GetClientHealth() != max_health || player_target.IsUnconscious() )
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
		
		if ( player_target.IsUnconscious() )
		{
			player_target.SetHealth("GlobalHealth", "Health", ( ( max_health / 100 ) * PERCENTAGE_HEAL_UNCOUNSCIOUS ) );
			
			DayZPlayerSyncJunctures.SendPlayerUnconsciousness( DayZPlayer.Cast( action_data.m_Target.GetObject() ), false );
		}
		else
		{
			player_target.AddHealth("GlobalHealth", "Health", ( ( max_health / 100 ) * PERCENTAGE_HEAL_COUNSCIOUS ) );
		}
	}
};