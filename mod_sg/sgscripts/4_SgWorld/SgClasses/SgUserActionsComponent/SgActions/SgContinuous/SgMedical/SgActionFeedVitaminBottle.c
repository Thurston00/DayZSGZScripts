modded class ActionFeedVitaminBottleCB
{
	private const float SG_EAT_VITAMIN_BOTTLE_QUANTITY = 2;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible( SG_EAT_VITAMIN_BOTTLE_QUANTITY, UATimeSpent.DEFAULT );
	}
}

modded class ActionFeedVitaminBottle
{
	void ActionFeedVitaminBottle()
	{
		m_CallbackClass = ActionFeedVitaminBottleCB;
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
}