class SgUiMenuBase extends SgUiMenuPanel
{
	private static ref 	SgUiMenuBase 	m_MenuBase = null;       
	private static 		bool 			m_LoggedIn = false;
	// Widgets Frames
	private	Widget 	m_HeaderFrame;					
	private	Widget 	m_FooterFrame;					
	private Widget 	m_ContentFrame;			
	// Ui Classes
	private	ref SgUiHeaderBase	m_Header;			
	private ref SgUiFooterBase	m_Footer;			
	private ref SgUiMenuPanel 	m_Content;
	private ref SgUiPopup		m_Popup;
	// Events
	private ref SgMenuEvents	m_MenuEvents;
	// Data
	private ref SgNetworkService m_NetService;
	private int counter = -1;
	
	private void SgUiMenuBase()
	{
		m_MenuEvents = new SgMenuEvents();
		BuildLayout();
		
		
		// If not logged in  
		if (!GetNetworkService().IsLoggedIn())
		{
			// Open Connecting popup
			WaitForServerPopup();
		}
	}	
	
	// -----------------------------------------------------------------
	// OVERRIDES --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_menu_base.layout";
	}
	override protected void FindAllWidgets()
	{
		m_ContentFrame 	= FindPanel("ContentFrame");	
	}	
	override protected void RegisterAllEvents()
	{
		
	}
	
	// -----------------------------------------------------------------
	
	void CreateHeader()
	{
		m_Header = new SgUiHeaderBase(FindPanel("HeaderFrame"));
	}
	void CreateFooter()
	{
		m_Footer = new SgUiFooterBase(FindPanel("FooterFrame"));
	}
		
	// ---------------------------------------------------------
	// Popups

	ScriptInvoker OpenLoadingPopup(string header)																								// Only for loading 
	{
		m_Popup = new SgUiPopupLoading(header);
		return m_Popup.GetResponseEvent();
	}
	ScriptInvoker OpenAlertPopup(string message)																								// Show alert popup
	{
		m_Popup = new SgUiPopupOutput(message);
		return m_Popup.GetResponseEvent();
	}
	ScriptInvoker OpenUserResponseInputPopup(string header, string message, string primary_button_text, string secondary_button_text)			// Show question with closed question (Yes/No) 
	{
		m_Popup = new SgUiPopupResponse(header, message, primary_button_text, secondary_button_text);
		return m_Popup.GetResponseEvent();
	}
	ScriptInvoker OpenUserTextInputPopup(string header, string primary_button_text, string secondary_button_text)								// Show popup that promp user input (password so on...)
	{
		m_Popup = new SgUiPopupInput(header, primary_button_text, secondary_button_text);
		return m_Popup.GetResponseEvent();
	}
	void ClosePopup()
	{	
		m_Popup = null;
	}
	
	// ----------------------------------------------------------
	
	void DeleteCurrentContentMenu()
	{
		if ( m_Content )
		{
			delete m_Content;
		}
	}
	void CreateContentMenu(typename type_name_content)
	{		
		DeleteCurrentContentMenu();
		m_Content = SgUiMenuPanel.Cast(type_name_content.Spawn());
		m_Content.BuildLayout( m_ContentFrame );	
		
		// Notify listeners that Content Menu Has been opened
		m_MenuEvents.MenuEvent_OnContentMenuOpened.Invoke(type_name_content);	
	}
	
	// ------------------------------------
	// GETTERS

	static SgUiMenuBase GetMenuBase()
	{
		if (m_MenuBase == null)
		{
			m_MenuBase = new SgUiMenuBase();
		}
		return m_MenuBase;
	}
	
	SgMenuEvents GetMenuEvents()
	{
		return m_MenuEvents;
	}
	
	SgUiHeaderBase GetHeader()
	{
		return m_Header;
	}
	SgUiFooterBase GetFooter()
	{
		return m_Footer;
	}
	SgUiMenuPanel GetCurrentContentMenu()
	{
		return m_Content;
	}
	
	SgNetworkService GetNetworkService()
	{
		if (!m_NetService)
		{
			m_NetService = SgNetworkService.GetService();
		}
		
		if (m_NetService)
		{
			return m_NetService;
		}
		else 
		{
			SgDebug.Error("Network Service could not be load (null)!", ClassName(), "GetNetworkService");
			return null;
		}
	}
	
	// ----------------------------------
	// Services Loggin 
	
	private void WaitForServerPopup()
	{
		if (counter == -1)
		{
			// Register listener
			GetNetworkService().GetEvent_OnLoggedIn().Insert(OnLoggedIn);			
		}
		
		// Reset Countdown counter
		counter = 0;
		// Open connecting popup
		OpenLoadingPopup(SgCPopupHeaderTexts.CONNECTING_TO_SERVICES);
		// Lock popup manual exit
		#ifndef DEVELOPER
			SgUiPopupLoading.Cast(m_Popup).SetLock(true);
		#endif
		
		// Start Waiting 
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(CounterTick, 1000, true);
	}
	
	private void OnLoggedIn()
	{
		// Stop the waiting "thread" 
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(CounterTick);
		// Remove on login 
		GetNetworkService().GetEvent_OnLoggedIn().Remove(OnLoggedIn);
		// Loggin checks 
		m_LoggedIn = true;
		counter = -1;
		// Close the connecting popup
		ClosePopup();
	}
	
	private void CounterTick()
	{
		counter++;
		
		if (GetNetworkService().IsLoggedIn() == true)
		{
			OnLoggedIn();
			return;
		}
		
		if (counter >= 60) // After 60 seconds  
		{
			// Remove the call 
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(CounterTick);
			// Close the connecting popup
			ClosePopup();
			// Prop user to exit the game or try again
			OpenUserResponseInputPopup(SgCPopupHeaderTexts.ALERT, SgCPopupDescTexts.E_SERVICE_CONNECT_FAIL , SgCPopupButtonTexts.RETRY, SgCPopupButtonTexts.EXIT).Insert(OnRetryPopupResponse);
		}
	}
	
	private void OnRetryPopupResponse(SgEPopupButtonType button)
	{
		if (button == SgEPopupButtonType.SECONDARY) // On Exit Button
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(g_Game.RequestExit, IDC_MAIN_QUIT);
		}
		else 										// On Retry Button
		{
			WaitForServerPopup();
		}
	}
}	