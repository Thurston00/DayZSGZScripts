modded class InGameMenu
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("mod_sg/gui/layouts/sg_ingame_menu.layout", NULL);
		
		string version;
		GetGame().GetVersion(version);
		
		TextWidget version_widget = TextWidget.Cast( layoutRoot.FindAnyWidget("VersionTextWidget") );
		version_widget.SetText("#main_menu_version " + version);

		ButtonWidget restart_btn = ButtonWidget.Cast( layoutRoot.FindAnyWidgetById(IDC_INT_RETRY) );
		
		m_ContinueButton	= layoutRoot.FindAnyWidget( "continuebtn" );
		m_ExitButton		= layoutRoot.FindAnyWidget( "exitbtn" );
		m_RestartButton		= layoutRoot.FindAnyWidget( "restartbtn" );
		m_RestartDeadButton	= layoutRoot.FindAnyWidget( "restartdeadbtn" );
		m_OptionsButton		= layoutRoot.FindAnyWidget( "optionsbtn" );
		
		Man player = GetGame().GetPlayer();
		bool player_is_alive = false;
		if (player)
		{
			int life_state = player.GetPlayerState();

			if (life_state == EPlayerStates.ALIVE)
			{
				player_is_alive = true;
			}
		}

		if (GetGame().IsMultiplayer())
		{
			restart_btn.SetText("#main_menu_respawn");
		}
		else
		{
			restart_btn.SetText("#main_menu_restart");
		}

		if (GetGame().IsMultiplayer() && GetGame().CanRespawnPlayer() == false)
		{
			restart_btn.Enable(false);
		}
		
		HudShow( false );
		
		return layoutRoot;
	}
	
	override void HudShow(bool show)		 
	{
		Mission mission = GetGame().GetMission();
		
		if (mission)
		{
			IngameHud hud_dayz = IngameHud.Cast(mission.GetHud());
			SgUiHudBase hud_sgz = SgSManagerGui.GetSgHud();
			
			if (hud_dayz)
			{
				hud_dayz.ToggleQuickBar(show);
			}
			if (hud_sgz)
			{
				if (show)
				{
					hud_sgz.ShowAllHUD();
				}
				else 
				{
					hud_sgz.HideAllHUD();
				}
			}				
		}
	}
	
	override protected void OnClick_Exit()
	{
		//GetGame().GetUIManager().ShowDialog("EXIT", "Are you sure you want to exit?", IDC_MAIN_QUIT, DBT_YESNO, DBB_YES, DMT_QUESTION, NULL);
		
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(g_Game.RequestExit, IDC_MAIN_QUIT);
	}
	
}
