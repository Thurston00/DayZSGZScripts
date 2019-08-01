modded class ActionGiveSalineSelfCB : ActionContinuousBaseCB
{
	protected const int TIME_TO_REGAIN_CONSCIOUSNESS = 0;
	protected const float HEAL_QUANTITY = 12.5; // Saline has 250 units, so 5% healing value to the player is 12.5 saline quantity
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new SgCAContinuousQuantityRepeatAndTime( HEAL_QUANTITY, UATimeSpent.DEFAULT, TIME_TO_REGAIN_CONSCIOUSNESS );
	}
};

modded class ActionGiveSalineSelf
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		int max_health = player.GetMaxHealth("GlobalHealth", "Health");
		
		if ( player.GetClientHealth() != max_health )
		{
			return true;
		}
		
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{			
		
	}
};