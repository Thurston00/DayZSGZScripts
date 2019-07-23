modded class ActionForceConsume
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		if( item.GetQuantity() > item.GetQuantityMin() )
		{
			if(GetGame().IsServer())
			{
				player = PlayerBase.Cast(target.GetObject());
				if (player != null)
				{
					SymptomBase primary_active_symptom = player.GetSymptomManager().GetCurrentPrimaryActiveSymptom();
					if ( primary_active_symptom != null && primary_active_symptom.GetType() == SymptomIDs.SYMPTOM_VOMIT )
					{
						return false;
					}
				}
			}
			
			return true;
		}
		else
		{
			return false;
		}
	}
}