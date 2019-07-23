class SgActionEatVitaminBottleCB : ActionContinuousBaseCB
{
	protected const float SG_EAT_VITAMIN_BOTTLE_QUANTITY = 2;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible( SG_EAT_VITAMIN_BOTTLE_QUANTITY, UATimeSpent.DEFAULT );
	}
}

modded class ActionEatVitaminBottle
{
	void ActionEatVitaminBottle()
	{
		m_CallbackClass = SgActionEatVitaminBottleCB;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		int max_health = player.GetMaxHealth("GlobalHealth", "Health");
		if ( player.GetClientHealth() != max_health )
		{
			return true;
		}
		
		return false;
	}
}