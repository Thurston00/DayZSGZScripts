modded class VomitStuffedMdfr
{
	override bool ActivateCondition(PlayerBase player)
	{
		float stomachs = player.m_PlayerStomach.GetStomachVolume();
		if ( stomachs >= SG_STOMACH_VOMIT_THRESHOLD )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}