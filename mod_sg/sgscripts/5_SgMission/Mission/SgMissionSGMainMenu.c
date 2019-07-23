class SgMissionSGMainMenu extends MissionBase
{
	//protected UIScriptedMenu 		m_mainmenu;
	protected ref SgIntroScene		m_intro_scene;
	bool 							m_NoCutscene;

	//============================================
	// Init
	//============================================	
	SgIntroScene GetIntroScene()
	{
		return m_intro_scene;
	}

	override void OnInit()
	{
		if ( !m_NoCutscene )
		{
			CreateIntroScene();
		}

		SgMenuManager.Init();
		
		/*
		if ( !m_mainmenu )
		{
			//m_mainmenu = UIScriptedMenu.Cast( g_Game.GetUIManager().EnterScriptedMenu( MENU_SG_MAIN_MENU, NULL ) );
		}
		*/
	}

	void CreateIntroScene()
	{
		m_intro_scene = new SgIntroScene;
	}

	//============================================
	// Events
	//============================================	
	override void OnMissionStart()
	{
		g_Game.GetUIManager().ShowCursor(true);
		g_Game.SetMissionState( DayZGame.MISSION_STATE_MAINMENU );
	}
	
	override void OnMissionFinish()
	{
		//m_mainmenu.Cleanup();
		GetGame().GetUIManager().CloseAll();
		//m_mainmenu = NULL;
		m_intro_scene = NULL;
		g_Game.GetUIManager().ShowCursor(false);
		
		SgMenuManager.Init();
	}

	override void OnUpdate(float timeslice)
	{
		if (g_Game.IsLoading()) return; 
		
		if (m_intro_scene)
		{
			m_intro_scene.Update();
		}

		/*
		if( m_mainmenu )
		{
			m_mainmenu.Update(timeslice);
		}

		
		if (GetGame().GetInput().GetActionPress( "UAUIBack" , false))
		{
			if (GetGame().GetUIManager().GetMenu() != m_mainmenu)
			{
				GetGame().GetUIManager().Back();
			}		
		}
		
		if (GetGame().GetUIManager().GetMenu() == m_mainmenu)
		{
			if ((!g_Game.GetUIManager().GetLoginQueueDialog()) && (g_Game.GetUIManager().GetLoginQueuePosition() > 0))
			{
				g_Game.GetUIManager().SetLoginQueueDialog(true);
				//GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(g_Game.GetUIManager().EnterLoginQueueScript, m_mainmenu);
			}
		}
		*/
	}
}
