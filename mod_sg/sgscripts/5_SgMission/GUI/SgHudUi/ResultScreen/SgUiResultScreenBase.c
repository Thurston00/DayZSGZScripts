/* 
	UI base class for result screen
*/
class SgUiResultScreenBase extends SgUiMenuPanel
{
	// Widgets
	private 	TextWidget 		m_UiNameLabel;
	private 	TextWidget 		m_UiWinnerLabel[2];
	private 	TextWidget 		m_UiTeamRankLabel;
	private 	TextWidget 		m_UiCountDownkLabel;

	
	private ref SgUiResultScreenPlayerStatsHeader 	m_UiPlayerStatsHeader;
	private ref array<ref SgUiResultScreenPlayerStatsRow> m_UiPlayerStatsRow = new ref array<ref SgUiResultScreenPlayerStatsRow>;
	private ref SgUiResultScreenTeamStatsHeader 	m_UiTeamStatsHeader;
	private ref SgUiResultScreenTeamStatsRow 		m_UiTeamStatsRow;
	private ref SgUiButton							m_UiExitButton;
	private ref SgUiButton							m_UiSpectateButton;
	// Data
	private		string 					m_PlayerUUID; 
	private 	string 					m_PlayerName;
	private ref SgNetDataTeamResult 	m_PlayerStats;		
	// Countdown
	private 	int 			m_CountdownInterval = 1000;
	private 	int 			m_CountdownTimer 	= 30000;
	// Events
	private ref ScriptInvoker 	Event_ExitButton_Clicked = new ScriptInvoker();
	private ref ScriptInvoker 	Event_SpactateButton_Clicked = new ScriptInvoker();
	
	// ----------------------------------------------------------------
	
	void SgUiResultScreenBase( SgNetDataTeamResult data )
	{
		BiosUserManager user_manager = GetGame().GetUserManager();
       	BiosUser selected_user = user_manager.GetSelectedUser();	
		
		m_PlayerUUID = SgSClientGame.GetPlayerUID();
		
		m_PlayerName = selected_user.GetName();
		
		m_PlayerStats = data;
		BuildLayout();
		
		GetGame().GetUIManager().ShowCursor	(true);
		MissionGameplay.Cast(GetGame().GetMission()).SetControlLock(true);	
	}
	
	// -----------------------------------------------------------------
	// OVERRIDE SgUiMenuPanel
	
	override void OnDestroy()
	{
		MissionGameplay mission = MissionGameplay.Cast(GetGame().GetMission());
		if (mission)
		{
			mission.SetControlLock(false);	
		}
	}
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_result_screen/sg_result_screen_base.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiNameLabel	 	= FindLabel("PlayerNameLabel");
		m_UiWinnerLabel[0] 	= FindLabel("WinnerLabel");
		m_UiWinnerLabel[1] 	= FindLabel("SlashLabel");
		m_UiTeamRankLabel	= FindLabel("TeamRankValueLabel");
		m_UiCountDownkLabel	= FindLabel("CountDownLabel");
	}
	override protected void LoadAllWidgets()
	{
		LoadTeamStats();
		LoadPlayerStats();
		LoadButtons();
		LoadRanking();
				
		StartExitGameCountDown();
	}	
	override protected void RegisterAllEvents()
	{
		Event_ExitButton_Clicked.Insert(ExitGame);
		Event_SpactateButton_Clicked.Insert(SpectateGame);
	}
	override protected void UnRegisterAllEvents()
	{
		Event_ExitButton_Clicked.Remove(ExitGame);
		Event_SpactateButton_Clicked.Remove(SpectateGame);
	}
	// ----------------------------------------------------------------
	
	private void LoadRanking()
	{
		int rank = m_PlayerStats.GetRank();	
		string result_text = SgSStringControl.PositionToString(rank);		// Get ordinal position string and add it at the end of the text
		
		if (rank == 1)														// Add winner text at the beginning of the text if the team is 1st 
		{
			m_UiWinnerLabel[0].Show(true);
			m_UiWinnerLabel[1].Show(true);
		}
		else 
		{
			m_UiWinnerLabel[0].Show(false);
			m_UiWinnerLabel[1].Show(false);
		}
		
		if (rank == 1 || rank == 2) 
		{
			m_UiSpectateButton.Visible(false);
		}
		
		m_UiNameLabel.SetText(m_PlayerName);
		m_UiTeamRankLabel.SetText(result_text); 
	}
	
	private void LoadButtons()
	{
		Widget parent 			= FindPanel("HorizontalGrid");
		m_UiSpectateButton 		= new SgUiButton(parent, SgCMenuButtonStrings.SPECTATE ,Event_SpactateButton_Clicked);
		m_UiExitButton			= new SgUiButton(parent, SgCPopupButtonTexts.EXIT /*SgCMenuButtonStrings.EXIT*/ ,Event_ExitButton_Clicked);
	}
	
	private void LoadTeamStats()
	{
		m_UiTeamStatsHeader 	= new SgUiResultScreenTeamStatsHeader(FindPanel("TeamStatsHeader"));
		m_UiTeamStatsRow 		= new SgUiResultScreenTeamStatsRow(FindPanel("TeamStatsContent"), m_PlayerStats);
	}
	
	private void LoadPlayerStats()
	{
		m_UiPlayerStatsHeader 	= new SgUiResultScreenPlayerStatsHeader(FindPanel("PlayerStatsContentGrid"));
		
		for ( int i = 0; i < m_PlayerStats.GetPlayerResultList().Count(); i++ )
		{
			bool is_player = false;
			string uuid 		= m_PlayerStats.GetPlayerResultList()[i].GetPlayerUID();
			string name 		= SgSClientGame.GetPlayerByUID(uuid).GetUserName();	// Get Player name SG_TODO: Pato --> Get an actual nick name instead this!!! Note: Waiting for backend
			int zombie_kills 	= m_PlayerStats.GetPlayerResultList()[i].GetZombieKills();												// Get zombie kills
			int player_kills 	= m_PlayerStats.GetPlayerResultList()[i].GetPlayerKillsList().Count();									// Get pllayer kills
			
			if (uuid == m_PlayerUUID)
			{
				
				is_player = true;	
				name = m_PlayerName;	// Temporarly until I have finally the freaking  usernames !!!! 			
			}
			
			// Temporarly until I have finally the freaking  usernames !!!! 			
			if (name == "")
			{
				name = uuid;
			}
			
			m_UiPlayerStatsRow.Insert(new SgUiResultScreenPlayerStatsRow(FindPanel("PlayerStatsContentGrid"), name, zombie_kills, player_kills, 0 /*SG_TODO: Pato --> this NOTE: Waiting for backend */, is_player));
		}
	}

	// ------------------------------------------------------------------
	// BUTTON EVENTS
	
	private void ExitGame()
	{
		//GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(g_Game.RequestExit, IDC_MAIN_QUIT);
		GetGame().GetMission().AbortMission();
	}	
	private void SpectateGame()
	{
		StopExitGameCountDown();
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(SgSManagerGui.CloseResult, 500);
	}
	
	// -------------------------------------------------------------------
	// Exit Game 
	
	private void StartExitGameCountDown()
	{		
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(ExitGameCountDownTick, m_CountdownInterval, true);
	}
	private void ExitGameCountDownTick()
	{
		if (m_CountdownTimer <= 0)
		{
			StopExitGameCountDown();
			ExitGame();
		}
		else 
		{
			m_CountdownTimer -= m_CountdownInterval;
			m_UiCountDownkLabel.SetText(string.Format("*You will exit to  main menu in %1 seconds.", (m_CountdownTimer / 1000)));
		}
	}
	private void StopExitGameCountDown()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(ExitGameCountDownTick);
		m_CountdownTimer = 30000;
	}
	
}


















