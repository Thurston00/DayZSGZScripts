class SgUiFooterPlayPanel extends SgUiMenuPanel
{
	// Consts
	private const string	ROOT_PATH = "mod_sg/gui/layouts/sg_menu/sg_footer/sg_footer_play.layout";
	// Widgets
	private Widget 		m_UiPlayGrid;
	private Widget 		m_UiCancelGrid;
	private TextWidget	m_UiLoadingLabel;
	private TextWidget 	m_UiSearchLabel;
	// Custom Widgets
	private ref SgUiButtonActionHigh	m_UiPlayButton;
	private ref SgUiButtonImage			m_UiCancelButton;
	private ref SgUiSwitch				m_UiGameModeSwitch;
	private ref SgUiSwitchRegion		m_UiRegionSwitch;
	// Data
	private bool 	m_IsLookingForMatch;
	private int	 	m_StopwatchTime;
	private int		m_LoadingDots = 1;
	// Events
	// - Buttons
	private ref ScriptInvoker FooterEvent_OnPlayButtonClicked = new ScriptInvoker();
	private ref ScriptInvoker FooterEvent_OnCancelButtonClicked = new ScriptInvoker();
	private ref ScriptInvoker FooterEvent_OnGameModeSwitchChanged = new ScriptInvoker();
	private ref ScriptInvoker FooterEvent_OnRegionSwitchChanged = new ScriptInvoker();
	
	// ---------------------------
	// Constructor
	void SgUiFooterPlayPanel(Widget parent_widget)
	{		
		super.BuildLayout(parent_widget);
	}
		
	// ------------------------------
	// OVERRIDES --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return ROOT_PATH;
	}
	override protected void FindAllWidgets()
	{
		m_UiPlayGrid = FindPanel("GridPlay");
		m_UiCancelGrid = FindPanel("GridSearch");
		m_UiLoadingLabel = FindLabel("SearchLabelLoading");
		m_UiSearchLabel = FindLabel("SearchLabel");
	}
	override protected void LoadAllWidgets()
	{
		m_UiPlayButton = new SgUiButtonActionHigh(FindPanel("PlayButtonFrame"), SgCMenuButtonStrings.PLAY_C,FooterEvent_OnPlayButtonClicked );
		m_UiCancelButton = new SgUiButtonImage(FindPanel("CancelButtonFrame"), SgCMenuWidgetPaths.CANCEL_ICON, FooterEvent_OnCancelButtonClicked );
		m_UiGameModeSwitch = new SgUiSwitch(FindPanel("GameModSwitchFrame"), SgCMenuSwitchStrings.SOLO_C, SgCMenuSwitchStrings.DUO_C, FooterEvent_OnGameModeSwitchChanged );
		m_UiRegionSwitch = new SgUiSwitchRegion(FindPanel("RegionSwtichFrame"), FooterEvent_OnRegionSwitchChanged );
	}
	override protected void RegisterAllEvents()
	{
		SgUiMenuBase.GetMenuBase().GetMenuEvents().MenuEvent_OnContentMenuOpened.Insert(OnContentMenuOpened);
		
		FooterEvent_OnPlayButtonClicked.Insert(OnPlayButtonClicked);
		FooterEvent_OnCancelButtonClicked.Insert(OnCancelButtonClicked);
		
		SgNetworkService.GetService().GetEvent_OnAddedToMatch().Insert(OnAddedToMatch);
	}
	
	// -----------------------------------
	// Back-end requests
	
	// Play Button
	private void OnPlayButtonClicked()
	{
		
#ifdef DEVELOPER
		string sgConnectToLocalServer;
		if ( GetGame().CommandlineGetParam("sgConnectToLocalServer", sgConnectToLocalServer))
		{
			Print("Connecting to Local Server..");
			GetDayZGame().ConnectFromJoin( "127.0.0.1" , 2302 );
		}
		
		return;
#endif
		
		// If NOT already looking for a match
		if (!m_IsLookingForMatch)
		{
			// Gather request data
			int 			m_GameType = SgEGameMode.NORMAL;					// Game type - Ranked, Normal ... SG_TODO: this
			SgETeamSize 	m_TeamMode;											// Team size - DUO, SOLO ...
			if (m_UiGameModeSwitch.GetSwitchState() == SgESwitchState.LEFT)		// Check which mode is selected with the switch
			{
				m_TeamMode = SgETeamSize.SOLO;									// <-- left solo
			}
			else 
			{
				m_TeamMode = SgETeamSize.DUO;									// <-- right duo
			}
			bool 			m_FillTeam = true;									// Fill the empty teammate slot?  SG_TODO: this
			array<string> 	m_TeammatesUIDs = new array<string>;				// The list of current teammates  SG_TODO: this
			
			SgERegion region = SgERegion.EU;
			if (m_UiRegionSwitch.GetSwitchState() == SgESwitchRegion.EU)
			{
				region = SgERegion.EU;
			}
			else
			if (m_UiRegionSwitch.GetSwitchState() == SgESwitchRegion.US)
			{
				region = SgERegion.AMERICAS;
			}
			
			// Crete the request
			ref SgNetDataSearchForMatchStartRequest request = new SgNetDataSearchForMatchStartRequest(m_GameType, m_TeamMode, m_FillTeam, m_TeammatesUIDs, region);
			// Send the request
			SgEResult result = SgNetworkService.GetService().StartSearchForMatch(request);
			// Handle result
			if (result == SgEResult.OK)
			{
				m_UiSearchLabel.SetText(SgCMenuWidgetStrings.FINDING_MATCH); 
				m_UiCancelButton.Show(true);
				
				// Register the client for "Match found event"
				SgNetworkService.GetService().GetEvent_OnGameServerIsReadied().Insert(OnMatchFound);
				// Set the state to Looking for a Match				
				m_IsLookingForMatch = true;
				// Hide play button
				m_UiPlayGrid.Show(false);
				// Show cancel button
				m_UiCancelGrid.Show(true);
				// Runnable 
				//StartLodingAnimation();	// ... animation
				StartStopwatch();		// Timer 
			}
			else 
			{
				m_IsLookingForMatch = false;
			}
			
		}
	}
	
	// Cancel Button
	private void OnCancelButtonClicked()
	{
		// If looking for a match
		if (m_IsLookingForMatch)
		{			
			// Create a request
			ref SgNetDataSearchForMatchCancelRequest request = new SgNetDataSearchForMatchCancelRequest();
			// Send the request
			SgEResult result = SgNetworkService.GetService().CancelSearchForMatch(request);
			// Handle the response
			if (result == SgEResult.OK)
			{
				// Unregister the client from "Match found event"
				SgNetworkService.GetService().GetEvent_OnGameServerIsReadied().Remove(OnMatchFound);
				// Set the state to not Looking for a Match		
				m_IsLookingForMatch = false;
				// Show Play button
				m_UiPlayGrid.Show(true);
				// Hide Cancel button
				m_UiCancelGrid.Show(false);
				// Stop Runnable 
				//StopLoadingAnimation();
				StopStowatch();
			}
			else 
			{
				SgDebug.Debug("Could not cancel the match search!", this.ClassName(), "OnCancelButtonClicked");
				m_IsLookingForMatch = true;
			}
		}
	}
	
	// -----------------------------------
	// Events Responses
	
	private void OnContentMenuOpened(typename type_name_content)
	{		
		switch(type_name_content)
		{
			case SgUiLobbyBase:
			{
				m_UiPlayButton.Enable(false);
				break;
			}	
			default:
			{
				m_UiPlayButton.Enable(true);
				break;
			}	
		}
	}
	
	private void OnAddedToMatch()
	{
		m_UiCancelButton.Show(false);
		m_UiSearchLabel.SetText(SgCMenuWidgetStrings.WAITING_FOR_SERVER);
		
		StopStowatch();
		StartLodingAnimation();
	}
	
	private void OnMatchFound(ref SgNetServerDataServerReadyResponse resultValue)
	{
		g_Game.ConnectFromJoin(resultValue.GetServerIp() , resultValue.GetServerPort());
	}
	
	// -----------------------------------
	// Stopwatch

	// Start thread
	private void StartStopwatch()
	{
		m_StopwatchTime = 0;
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(UpdateStopwatch, 1000, true);
	}
	// Stop thread
	private void StopStowatch()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(UpdateStopwatch);
	}
	// Thread tick
	private void UpdateStopwatch()
	{
		m_StopwatchTime++;
		
		int min, sec;
		string minS, secS;
		
		min = m_StopwatchTime / 60 % 60;
		sec = m_StopwatchTime % 60;
		
		if (min < 10) 
		{
			minS = "0" + min.ToString();
		}
		else 
		{
			minS = min.ToString();
		}
		
		if (sec < 10)
		{
			secS = "0" + sec.ToString();
		}
		else 
		{
			secS = sec.ToString();
		}
		
		m_UiLoadingLabel.SetText(string.Format("(%1:%2)" , minS, secS));
		
		
		Print("Stopwatch Time: " + string.Format("(%1:%2)" , minS, secS));
	}
	
	// -------------------------------------
	// Loading animation
	
	// Start the loading animation
	private void StartLodingAnimation()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(UpdateLoadingAnimation, 400, true);
	}
	// Stop the loading animation
	private void StopLoadingAnimation()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(UpdateLoadingAnimation);
	}
	// Loading animation tick
	private void UpdateLoadingAnimation()
	{
		string dots;
		
		if (m_LoadingDots <= 3)
		{
			m_LoadingDots++;
		}
		else 
		{
			m_LoadingDots = 1;
		}
		
		for (int i = 0; i < m_LoadingDots; i++)
		{
			dots += ".";
		}
		
		m_UiLoadingLabel.SetText(dots);
	}
}