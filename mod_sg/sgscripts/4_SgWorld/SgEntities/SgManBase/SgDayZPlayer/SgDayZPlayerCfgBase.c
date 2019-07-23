void SgDayZPlayerTypeRegisterItems()
{		
	DayZPlayerType type = GetDayZGame().GetPlayer().GetDayZPlayerType();
	DayzPlayerItemBehaviorCfg 	twoHanded = new DayzPlayerItemBehaviorCfg;
	twoHanded.SetTwoHanded();
	
	DayzPlayerItemBehaviorCfg 	toolsOneHanded = new DayzPlayerItemBehaviorCfg;
	toolsOneHanded.SetToolsOneHanded();

	//! Medical 
	{
		type.AddItemInHandsProfileIK("SG_Antidote", "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", toolsOneHanded,		"dz/anims/anm/player/ik/gear/morphine.anm");
	}
	
	type.AddItemInHandsProfileIK("SG_BaseballBat", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_bat.asi", twoHanded,				"dz/anims/anm/player/ik/two_handed/baseballbat.anm");
}

