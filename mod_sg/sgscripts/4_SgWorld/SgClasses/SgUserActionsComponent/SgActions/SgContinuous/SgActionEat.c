modded class ActionEatCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible(UAQuantityConsumed.SG_EAT_NORMAL, UATimeSpent.DEFAULT);
	}
};