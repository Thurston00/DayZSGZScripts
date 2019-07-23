modded class ActionForceFeedMeatCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible(UAQuantityConsumed.SG_EAT_NORMAL, UATimeSpent.DEFAULT);
	}
};

modded class ActionForceFeedMeat
{
	override void OnStartAnimationLoop( ActionData action_data )
	{		
		super.OnStartAnimationLoop( action_data );
		
		if(GetGame().IsServer())
		{
			Edible_Base food_item = Edible_Base.Cast( action_data.m_MainItem );
			if ( food_item )
			{			
				if ( food_item.IsMeat() && food_item.IsFoodRaw() )
				{				
					PlayerBase.Cast(action_data.m_Target.GetObject()).GetSymptomManager().QueueUpPrimarySymptom( SymptomIDs.SYMPTOM_VOMIT );
				}
			}
		}
	}
}