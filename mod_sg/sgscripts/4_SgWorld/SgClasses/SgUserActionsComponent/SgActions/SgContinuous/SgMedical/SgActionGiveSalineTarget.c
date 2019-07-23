modded class ActionGiveSalineTargetCB
{
	protected const int TIME_TO_REGAIN_CONSCIOUSNESS = 7;
	protected const float HEAL_QUANTITY = 12.5; // Saline has 250 units, so 5% healing value to the player is 12.5 saline quantity
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new SgCAContinuousQuantityRepeatAndTime( HEAL_QUANTITY, UATimeSpent.DEFAULT, TIME_TO_REGAIN_CONSCIOUSNESS );
	}
};

modded class ActionGiveSalineTarget
{	
	void ActionGiveSalineTarget()
	{
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		PlayerBase player_target = PlayerBase.Cast( target.GetObject() );
		int max_health = player_target.GetMaxHealth("GlobalHealth", "Health");
		
		if ( player_target.GetClientHealth() != max_health )
		{
			return true;
		}
		
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{		
		
	}
};