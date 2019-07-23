modded class ActionDrinkCB
{	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible(UAQuantityConsumed.SG_DRINK_NORMAL, UATimeSpent.DEFAULT);
	}
};