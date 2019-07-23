class SgMenuManager
{	
	private static ref SgUiMenuBase m_SgUiMenuBase;
	
	// Initiate HUD 
	static void Init()
	{
		m_SgUiMenuBase = SgUiMenuBase.GetMenuBase();
		
		m_SgUiMenuBase.CreateHeader();
		m_SgUiMenuBase.CreateFooter();
		OpenLandingPage();
	}
	
	// ----------------------------------
	// POPUPS
	
	// Open popup with loading animation
	static ScriptInvoker OpenLoadingPopup(string header)
	{
		return m_SgUiMenuBase.OpenLoadingPopup(header);
	}
	// Open alert popup
	static ScriptInvoker OpenAlertPopup(string message)
	{
		return m_SgUiMenuBase.OpenAlertPopup(message);
	}
	// Open popup with response options
	static ScriptInvoker OpenUserResponseInputPopup(string header, string message, string primary_button, string secondary_button)
	{
		return m_SgUiMenuBase.OpenUserResponseInputPopup(header, message, primary_button, secondary_button);
	}
	// Open popup with edit box input 
	static ScriptInvoker OpenUserTextInputPopup(string header, string primary_button, string secondary_button)
	{
		return m_SgUiMenuBase.OpenUserTextInputPopup(header, primary_button, secondary_button);
	}
	// Close open popup
	static void ClosePopup()
	{
		m_SgUiMenuBase.ClosePopup();
	}
	
	// ---------------------------------
	// CONTENT MANAGEMENT
	
	static void CloseActiveContentMenu()
	{
		OpenMenuCustomGame();
	}
	private static void OpenMenu(typename type_name_content)
	{
		m_SgUiMenuBase.CreateContentMenu( type_name_content );
	}
	
	// -----------------------------------
	// CONTENT MENUS
	
	// Open Custom Game Screen
	static void OpenMenuCustomGame()
	{
		#ifdef DEVELOPER
		OpenMenu(SgUiCustomGameBase);
		#endif
	}
	// Open Lobby room screen
	static void OpenMenuLobby(SgLobbyData data)
	{		
		OpenMenu(SgUiLobbyBase);
		SgUiLobbyBase.Cast(m_SgUiMenuBase.GetCurrentContentMenu()).SetLobbyData(data);
	}
	static void OpenLandingPage()
	{
		OpenMenu(SgUiLandingPageBase);
	}
	static void OpenSettingMenu()
	{
		OpenMenu(SgUiSettingsBase);
	}
}