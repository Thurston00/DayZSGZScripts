class SgUiWarmUpBase extends SgUiHudPanel
{
	private static ref SgUiWarmUpBase m_UiWarmUpBase; 
	// Widgets
	private 	TextWidget				m_UiCountdownLane1Label;			// Line 1
	private 	TextWidget				m_UiCountdownLane2Label;			// Line 2
	private 	ImageWidget				m_UiImage;
	private 	MultilineTextWidget		m_UiDescLabel;
	private ref SgUiButtonImage			m_UiNextButton;  
	private ref SgUiButtonImage			m_UiPreviousButton;
	private ref SgUiWarmUpPageControl	m_UiPageControl;
	// Data
	private ref SgWarmUpContent  		m_ContentList 						= new SgWarmUpContent();
	private 	int 					m_PageIndex							= 0;
	private 	const int 				m_SlideShowDelay					= 25000;
	private 	int 					m_Countdown							= 5000;
	// Events	
	private ref ScriptInvoker			Event_NextButtonClicked_Left 		= new ScriptInvoker();
	private ref ScriptInvoker			Event_PreviousButtonClicked_Left 	= new ScriptInvoker();
	private ref ScriptInvoker			Event_OnContentChange 				= new ScriptInvoker();
	
	// ----------------------------------------
	
	static SgUiWarmUpBase GetWarmUpBase()
	{
		if (!m_UiWarmUpBase)
		{
			m_UiWarmUpBase = new ref SgUiWarmUpBase();
		}
		
		return m_UiWarmUpBase;
	}
	
	private void SgUiWarmUpBase()
	{
		if ( SgSClientGame.GetGameState() == ESgGameState.WarmUp)
		{
			MissionGameplay mission_gameplay = MissionGameplay.Cast( GetGame().GetMission() );
			if ( mission_gameplay != null )
			{
				mission_gameplay.PlayerControlDisable(INPUT_EXCLUDE_ALL);
			}
			
			GetGame().GetMission().GetHud().Show(false);
		
			GetGame().GetUIManager().ShowUICursor(true);
			
			GetGame().GetInput().ChangeGameFocus(1, INPUT_DEVICE_MOUSE);
			GetGame().GetInput().ChangeGameFocus(1, INPUT_DEVICE_KEYBOARD);
			GetGame().GetInput().ChangeGameFocus(1, INPUT_DEVICE_GAMEPAD);
			
			BuildLayout();
		}
		else 
		{
			SgSManagerGui.SyncEvent_OnWarmUpFinished();
		}
	}
	
	void ~SgUiWarmUpBase()
	{
		StopSlideShow();
		
		if ( SgSClientGame.GetGameState() != ESgGameState.WarmUp )
		{
			GetGame().GetMission().GetHud().Show(true);
			GetGame().GetUIManager().ShowUICursor(false);
		}
	}
	
	static void ClearWarmUpBase()
	{
		delete m_UiWarmUpBase;
		m_UiWarmUpBase = null;
	}
	
	static bool IsNull()
	{
		return m_UiWarmUpBase == null;
	}
	
	// ----------------------------------------------

	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_warm_up/sg_warm_up_base.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiCountdownLane1Label		= FindLabel("CountDownLabel1");
		m_UiCountdownLane2Label		= FindLabel("CountDownLabel2");
		m_UiImage					= FindImage("ContentImage");
		m_UiDescLabel				= FindMultilineLabel("DescMultiLineLabel");
	}
	override protected void LoadAllWidgets()
	{
		LoadContentList();
		
		m_UiNextButton			= new ref SgUiButtonImage(FindPanel("RightButtonFrame"), SgCMenuWidgetPaths.ARROW_RIGHT, Event_NextButtonClicked_Left);
		m_UiPreviousButton		= new ref SgUiButtonImage(FindPanel("LeftButtonFrame"), SgCMenuWidgetPaths.ARROW_LEFT, Event_PreviousButtonClicked_Left);
		m_UiPageControl			= new ref SgUiWarmUpPageControl(FindPanel("NavigationFrame"), m_ContentList.m_Hints.Count(), Event_OnContentChange );
		
		WaitForPlayers();
	}
	override protected void RegisterAllEvents()
	{
		Event_NextButtonClicked_Left.Insert(ShowNextPage);
		Event_PreviousButtonClicked_Left.Insert(ShowPreviousPage);
		Event_OnContentChange.Insert(SetPageIndex);
	}
	override protected void UnRegisterAllEvents()
	{
		Event_NextButtonClicked_Left.Remove(ShowNextPage);
		Event_PreviousButtonClicked_Left.Remove(ShowPreviousPage);
		Event_OnContentChange.Remove(SetPageIndex);
	}
	
	// -----------------------------------------
	private void LoadContentList()
	{
		m_ContentList = SgSResourceHandler.LoadHintInfo();
		
		for (int i = 0; i < m_ContentList.m_Hints.Count(); i++)
		{
			m_UiImage.LoadImageFile(i, m_ContentList.m_Hints.Get(i).m_Image);
		}
		
		SetContent();
	}	
	
	private void SetPageIndex(int index)
	{
		m_PageIndex = index;
		SetContent();
	}
	
	private void SetContent()
	{
		if (m_ContentList.m_Hints.Get(m_PageIndex))
		{
			m_UiDescLabel.SetText(m_ContentList.m_Hints.Get(m_PageIndex).m_Text);
			m_UiImage.SetImage(m_PageIndex);
		}
		
		RestartSlideShow();
	}
	
	private void ShowNextPage()
	{
		int index;
		
		if ( m_PageIndex < m_ContentList.m_Hints.Count() - 1 )
		{
			index = m_PageIndex + 1;
		}
		else 
		{
			index = 0;
		}
		
		Event_OnContentChange.Invoke(index);
	}	
	
	private void ShowPreviousPage()
	{
		int index;
		
		if ( m_PageIndex == 0 )
		{
			index = m_ContentList.m_Hints.Count() - 1;
		}
		else 
		{
			index = m_PageIndex - 1;
		}
		Event_OnContentChange.Invoke(index);
	}
	
	// -------------------------------------------
	// Time countdown
	private void StartCountdown()
	{
		m_UiCountdownLane1Label.SetText(SgCMenuWidgetStrings.WARMUP_STARTING);
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(CounterTick, m_Countdown, true);
	}
	
	private void StopCounter()
	{
		m_Countdown = 5;
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(CounterTick);
	}
	
	private void CounterTick()
	{
		m_UiCountdownLane2Label.SetText((m_Countdown--).ToString() + "s");
		
		if (m_Countdown == 0)
		{
			StopCounter();
		}
	}
	
	// -------------------------------------------
	// Slideshow 
	private void StartSlideshow()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(SlideshowThread, m_SlideShowDelay);
	}
	
	private void SlideshowThread()
	{
		ShowNextPage();
	}
	
	private void StopSlideShow()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(SlideshowThread);
	}
	
	private void RestartSlideShow()
	{
		StopSlideShow();
		StartSlideshow();
	}
	
	// ------------------------------------------
	
	private void WaitForPlayers()
	{
		m_UiCountdownLane1Label.SetText(SgCMenuWidgetStrings.WARMUP_WAITING);
	}
	
	private void UpdatePlayerLoginProgress(int current_player_count, int max_player_count)
	{
		m_UiCountdownLane2Label.SetText( string.Format( "%1/$2", current_player_count.ToString(), max_player_count.ToString() ) );
	}
	
}








