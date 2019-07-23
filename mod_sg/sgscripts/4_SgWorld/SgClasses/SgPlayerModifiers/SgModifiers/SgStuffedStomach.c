modded class StuffedStomachMdfr
{	
	override bool ActivateCondition(PlayerBase player)
	{
		float stomachs = player.m_PlayerStomach.GetStomachVolume();
		if ( stomachs >= SG_FATALLY_STUFFED_TRESHOLD )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		float stomachs = player.m_PlayerStomach.GetStomachVolume();
		if ( stomachs < SG_FATALLY_STUFFED_TRESHOLD )
		{
			return false;
		}
		else
		{
			return true;
		}
	}

};