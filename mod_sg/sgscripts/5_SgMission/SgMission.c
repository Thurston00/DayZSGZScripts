Mission SgCreateMission( string path )
{
	Print("Creating SG Mission: "+ path);
	
	g_Game.SetMissionPath(path);

	if (g_Game.IsClient())
	{
		SgMap.InitMapResources();
		SgSManagerSounds.InitSoundResources();
	}
	
	if (g_Game.IsMultiplayer() && g_Game.IsServer())
	{
		return new MissionServer;
	}

#ifdef NO_GUI
	return new MissionDummy;
#endif
	
	SgMissionSGMainMenu sg_main_menu;
	if ( path.Contains( "NoCutscene" ) )
	{
		sg_main_menu = new SgMissionSGMainMenu();
		sg_main_menu.m_NoCutscene = true;
		return sg_main_menu;
	}
	
	if ( path.Contains( "intro" ) )
	{
		sg_main_menu = new SgMissionSGMainMenu();
		sg_main_menu.m_NoCutscene = false;
		return sg_main_menu;
	}
	else
	{
#ifndef NO_GUI_INGAME
		return new MissionGameplay;
#else
		return new MissionDummy;
#endif
	}
}
