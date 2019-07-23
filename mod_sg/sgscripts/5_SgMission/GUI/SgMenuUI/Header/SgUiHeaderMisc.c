class SgUiHeaderMisc  extends SgUiMenuPanel
{
	// Widget	
	private ref SgUiButtonMenuPrimaryImage m_SettingsButton;		
	private ref SgUiButtonImage	m_ExitButton;
	// Events
	private ref ScriptInvoker 	HeaderEvent_OnExitGameButtonClicked = new ScriptInvoker();
	private ref ScriptInvoker	HeaderEvent_OnOptionsButtonClicked 	= new ScriptInvoker();
	
	// -----------------------------------
	// Constructor
	void SgUiHeaderMisc(Widget root)
	{
		super.BuildLayout(root);
		
		root.SetHandler(this);
	}
	
	// ----------------------------------
	// OVERRIDES --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return  "mod_sg/gui/layouts/sg_menu/sg_header/sg_header_misc.layout";
	}
	override protected void LoadAllWidgets()
	{
		m_SettingsButton 	= new SgUiButtonMenuPrimaryImage(FindPanel("OptionsFrame"),SgCMenuWidgetPaths.SETTINGS_ICON,  HeaderEvent_OnOptionsButtonClicked);
		m_ExitButton 		= new SgUiButtonImage(FindPanel("ExitFrame"), SgCMenuWidgetPaths.EXIT_CROSS_ICON, HeaderEvent_OnExitGameButtonClicked);
	}
	override protected void RegisterAllEvents()
	{
		HeaderEvent_OnExitGameButtonClicked.Insert(OnExitButtonPressed);
		HeaderEvent_OnOptionsButtonClicked.Insert(OnOptionsButtonPressed);
	}
	
	// ----------------------------------------------------------------
	// Button OnClick Event
	// - Options Button
	private void OnOptionsButtonPressed()
	{
		SgMenuManager.OpenSettingMenu();
		SgUiButtonMenuPrimary.UnselectAll();
	}	
	// - Exit Button
	private void OnExitButtonPressed()
	{
		SgMenuManager.OpenUserResponseInputPopup(SgCPopupHeaderTexts.EXIT_GAME, SgCPopupDescTexts.EXIT_GAME, SgCPopupButtonTexts.EXIT, SgCPopupButtonTexts.CANCEL).Insert(ExitGame);								
	}
	private void ExitGame( SgEPopupButtonType response)
	{
		if (response == SgEPopupButtonType.PRIMARY)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(g_Game.RequestExit, IDC_MAIN_QUIT);
		}
	}
}