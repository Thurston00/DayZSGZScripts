class SGMainMenu extends UIScriptedMenu
{

	protected ref SgObsoletePlayerNameHandler 	m_player_name_handler;
	protected SgIntroScene 				m_scene;

	protected TextListboxWidget 		m_GlobalStatsTextListBox;
	protected ref Timer 				m_statisticsUpdateTimer;
	protected Widget 					m_connection_warning_widget;
	protected bool 						m_statisticsLoadedSuccessfully;

	bool 								m_disableClick;

	//============================================
	// Init
	//============================================
	void SGMainMenu()
	{
		//m_fade_timer = new WidgetFadeTimer;
		m_statisticsUpdateTimer = new Timer( CALL_CATEGORY_GUI );
		m_statisticsLoadedSuccessfully = false;
	}

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_main_menu.layout", NULL );

		string version;
		string player_name;
		g_Game.GetVersion(version);
		g_Game.GetPlayerName(player_name);

		version = "SG Prototype 0.63";

		TextWidget version_widget = TextWidget.Cast( layoutRoot.FindAnyWidget("VersionTextWidget") );
		version_widget.SetText("#main_menu_version " + version);

		EditBoxWidget name_widget = EditBoxWidget.Cast( layoutRoot.FindAnyWidget("NameEditBoxWidget") );
		name_widget.SetText(player_name);

		m_GlobalStatsTextListBox = TextListboxWidget.Cast( layoutRoot.FindAnyWidget("StatisticsTextListboxWidget") );

		m_player_name_handler = new SgObsoletePlayerNameHandler;
		name_widget.SetHandler(m_player_name_handler);

		SgMissionSGMainMenu mission = SgMissionSGMainMenu.Cast( g_Game.GetMission() );
		m_scene = mission.GetIntroScene();

		return layoutRoot;
	}

	//============================================
	// Events
	//============================================
	override void OnShow()
	{
		super.OnShow();

		g_Game.EarlyAccessDialog(this);

		if (!m_statisticsLoadedSuccessfully && m_statisticsUpdateTimer.IsRunning() == false)
		{
			UpdateStats(); // hotfix: on steamversion calling of StatInvokeUpdate freeze the game for 15+ seconds everytime player enters main menu
		}
	}

	override void OnHide()
	{
		//super.OnHide();
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick( w, x, y, button);

		if (m_disableClick)
		{
			return false;
		}

		if (w.GetUserID() != IDC_MAIN_PLAY)
		{
			switch (w.GetUserID())
			{
				case IDC_MAIN_NEXT_CHARACTER:
					m_scene.ChangeCharacter(m_scene.NextCharacterID());
					if (m_scene.m_demoUnit)
					{
						m_disableClick = true;
						GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(SceneCharacterSetPos, 250);
					}
					return true;
				break;

				case IDC_MAIN_PREV_CHARACTER:
					m_scene.ChangeCharacter(m_scene.PrevCharacterID());
					if (m_scene.m_demoUnit)
					{
						m_disableClick = true;
						GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(SceneCharacterSetPos, 250);
					}
					return true;
				break;

				case IDC_MAIN_MULTIPLAYER:
					g_Game.GetUIManager().EnterServerBrowser(this);
					//saves demounit for further use
					if (m_scene && m_scene.m_demoUnit && m_scene.m_demoUnit.GetInventory().FindAttachment(InventorySlots.BODY) && m_scene.CurrentCharacterID() == -1)
					{
						SetCharacterInfo();
					}
					return true;
				break;

				case IDC_MAIN_OPTIONS:
					EnterScriptedMenu(MENU_OPTIONS);
					return true;
				break;

				case IDC_MAIN_QUIT:
					GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(g_Game.RequestExit, IDC_MAIN_QUIT);
					return true;
				break;
			}
		}
		else if (w.GetUserID() == IDC_MAIN_PLAY)
		{
			if (m_scene && !m_scene.m_demoUnit)
			{
				EnterScriptedMenu(MENU_CHARACTER);
			}
			else if (m_scene && m_scene.m_demoUnit)
			{
				//saves demounit for further use
				if (m_scene && m_scene.m_demoUnit && m_scene.m_demoUnit.GetInventory().FindAttachment(InventorySlots.BODY) && m_scene.CurrentCharacterID() == -1)
				{
					SetCharacterInfo();
				}

				GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "ConnectLastSession");
			}

			return true;
		}

		return false;
	}

	override bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		super.OnMouseButtonDown(w, x, y, button);

		if (w.GetName() == "CharacterRotationFrame")
		{
			if (m_scene) m_scene.CharacterRotationStart();
			return true;
		}

		return false;
	}

	override bool OnMouseButtonUp(Widget w, int x, int y, int button)
	{
		super.OnMouseButtonUp(w, x, y, button);

		if (m_scene) m_scene.CharacterRotationStop();
		return true;
	}

	override bool OnController(Widget w, int control, int value)
	{
		super.OnController(w, control, value);

#ifdef PLATFORM_XBOX
		if (control == ControlID.CID_BACK && value != 0)
		{
			ResetGamepads();
			return true;
		}
#endif

		return false;
	}

	void ConnectLastSession()
	{
		//TODO fix code-side
		if ( !g_Game.ConnectLastSession(this, m_scene.CurrentCharacterID()) )
		{
			g_Game.GetUIManager().EnterServerBrowser(this);
		}
	}

	//============================================
	// Menu data
	//============================================
	void UpdateStats()
	{
		m_GlobalStatsTextListBox.ClearItems();

		// NEW STATS API
		if ( m_scene && m_scene.m_demoUnit )
		{
			string lvalue = "";
			string lname = "";

			lname = "Play time";
			m_scene.m_demoUnit.StatGetAsTime("playtime", lvalue);
			int line_index = m_GlobalStatsTextListBox.AddItem(lname, NULL, 0);
			m_GlobalStatsTextListBox.SetItem(line_index, lvalue, NULL, 1);

			string debug_string = "";
			float fvalue = m_scene.m_demoUnit.StatGet("playtime");
			debug_string = "playtime: " + fvalue.ToString();

			lname = "Distance traveled";
			m_scene.m_demoUnit.StatGetCounter("dist", lvalue);
			line_index = m_GlobalStatsTextListBox.AddItem(lname, NULL, 0);
			m_GlobalStatsTextListBox.SetItem(line_index, lvalue, NULL, 1);

			debug_string = "dist: " + lvalue;

			m_statisticsLoadedSuccessfully = true;
		}
	}

	void SetCharacterInfo()
	{
		TStringArray topsArray = {"TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_Red","TShirt_White","TShirt_Grey"};
		TStringArray pantsArray = {"Jeans_Black","Jeans_BlueDark","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey","CanvasPants_Beige","CanvasPants_Blue","CanvasPants_Grey"};
		TStringArray shoesArray = {"AthleticShoes_Black","AthleticShoes_Blue","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey"};

		int topIndex = topsArray.Find(m_scene.m_demoUnit.GetInventory().FindAttachment(InventorySlots.BODY).GetType());
		int bottomIndex = pantsArray.Find(m_scene.m_demoUnit.GetInventory().FindAttachment(InventorySlots.LEGS).GetType());
		int shoesIndex = shoesArray.Find(m_scene.m_demoUnit.GetInventory().FindAttachment(InventorySlots.FEET).GetType());
		int characterIndex = GetGame().ListAvailableCharacters().Find(m_scene.m_demoUnit.GetType());

		//saves player' type and clothes to g_Game to sync with server
		GetGame().SetCharacterInfo(topIndex, bottomIndex, shoesIndex, characterIndex);
	}

	void SceneCharacterSetPos()
	{
		m_scene.m_demoUnit.SetPosition(m_scene.m_demoPos);
		m_scene.m_demoUnit.SetOrientation(m_scene.m_demoRot);
		m_disableClick = false;
	}
}
