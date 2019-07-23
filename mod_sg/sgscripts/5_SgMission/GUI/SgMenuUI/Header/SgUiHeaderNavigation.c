class SgUiHeaderNavigation extends SgUiMenuPanel
{
	// Custom Widgets
	private ref SgUiButtonMenuPrimary m_UiTutorialButton;
	private ref SgUiButtonMenuPrimary m_UiCustomGameButton;
	// Events
	private ref ScriptInvoker HeaderEvent_OnTutorialButtonClicked 	= new ScriptInvoker();
	private ref ScriptInvoker HeaderEvent_OnCustomGameButtonClicked = new ScriptInvoker();
	
	// ---------------------------------
	
	// Constructor
	void SgUiHeaderNavigation(Widget parent_widget)
	{
		super.BuildLayout(parent_widget);
	}
	
	// -----------------------------------
	// OVERRIDES --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_header/sg_header_navigation.layout";
	}
	override protected void LoadAllWidgets()
	{
		m_UiTutorialButton 		= new SgUiButtonMenuPrimary(FindPanel("TutorialButtonFrame"), SgCMenuButtonStrings.NAVIGATION_TUTORIAL_C, HeaderEvent_OnTutorialButtonClicked);
		m_UiTutorialButton.SetSelected(true);
		
		#ifdef DEVELOPER
		m_UiCustomGameButton 	= new SgUiButtonMenuPrimary(FindPanel("CustomGameButtonFrame"), SgCMenuButtonStrings.NAVIGATION_CUSTOMGAME_C, HeaderEvent_OnCustomGameButtonClicked);
		#endif
	}
	override protected void RegisterAllEvents()
	{
		HeaderEvent_OnTutorialButtonClicked.Insert(OnTutorialButtonClicked);
		HeaderEvent_OnCustomGameButtonClicked.Insert(OnCustomGameButtonClicked);
	}
	
	// ------------------------------------
	// Button OnClick Events
	
	// - Tutorial Button
	private void OnTutorialButtonClicked()
	{
		SgMenuManager.OpenLandingPage();
	}
	// - Custom Game Button 
	private void OnCustomGameButtonClicked()
	{
		SgMenuManager.OpenMenuCustomGame();
	}

}