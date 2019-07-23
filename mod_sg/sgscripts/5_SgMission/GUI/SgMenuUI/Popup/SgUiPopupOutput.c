class SgUiPopupOutput extends SgUiPopup
{
	// Widgets
	private ref SgUiButtonActionMedium	m_UiPrimaryButton;
	// Data
	private 	string 	m_MessageText;
	private 	string 	m_PrimaryButtonText;
	// Event
	private ref ScriptInvoker DialogEvent_OnPrimaryButtonClicked = new ScriptInvoker();
	
	void SgUiPopupOutput(string msg)
	{
		m_HeaderText 		= SgCPopupHeaderTexts.ALERT;
		m_MessageText 		= msg;
		m_PrimaryButtonText = SgCPopupButtonTexts.OK;
		
		BuildLayout();
	}
	
	// ----------------------------------------------------
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_popup_window/sg_popup_output.layout";
	}
	
	override void LoadAllWidgets()
	{
		super.LoadAllWidgets();
		
		FindMultilineLabel("DescMultiLabel").SetText(m_MessageText);
		m_UiPrimaryButton = new SgUiButtonActionMedium(FindPanel("PrimaryButtonFrame"), m_PrimaryButtonText, DialogEvent_OnPrimaryButtonClicked);
	} 
	override void RegisterAllEvents()
	{
		super.RegisterAllEvents();
		
		DialogEvent_OnPrimaryButtonClicked.Insert(OnPrimaryButtonClicked);
	}	
	override void UnRegisterAllEvents()
	{
		super.UnRegisterAllEvents();
		
		DialogEvent_OnPrimaryButtonClicked.Remove(OnPrimaryButtonClicked);
	}
		
	// ------------------------------------------------------
	
	private void OnPrimaryButtonClicked()
	{
		Event_OnResponse.Invoke(SgEPopupButtonType.PRIMARY);
		SgDebug.Debug("Primary button pressed!",ClassName(), "OnClick");
	}
}