modded class VomitSymptom
{	
	override void OnGetActivatedServer(PlayerBase player)
	{
		int half_of_stomach = player.m_PlayerStomach.GetStomachVolume() / 2;
		float random_volume = Math.RandomIntInclusive( 0,  half_of_stomach);
		
		//player.GetStatStomachVolume().Set(random_volume);
		//player.GetStatStomachWater().Set(0);
		player.GetStatEnergy().Set(0);
		
		PlayAnimationFB(DayZPlayerConstants.CMD_ACTIONFB_VOMIT,DayZPlayerConstants.STANCEMASK_CROUCH, GetDuration() );
	}
}