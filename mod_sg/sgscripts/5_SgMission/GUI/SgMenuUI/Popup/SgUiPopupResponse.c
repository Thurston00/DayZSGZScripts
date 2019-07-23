class SgUiPopupResponse extends SgUiPopup
{
	// Widgets
	private ref SgUiButtonActionMedium	m_UiPrimaryButton;
	private ref SgUiButtonActionMedium	m_UiSecondaryButton;
	// Data
	private string 	m_MessageText;
	private string 	m_PrimaryButtonText;
	private string 	m_SecondaryButtonText;
	// Events
	private ref ScriptInvoker DialogEvent_OnPrimaryButtonClicked = new ScriptInvoker();
	private ref ScriptInvoker DialogEvent_OnSecondaryButtonClicked = new ScriptInvoker();
	
	void SgUiPopupResponse(string header, string msg, string primary_button_text, string secondary_button_text)
	{
		m_HeaderText 			= header;
		m_MessageText 			= msg;
		m_PrimaryButtonText 	= primary_button_text;
		m_SecondaryButtonText 	= secondary_button_text;
		
		BuildLayout();
	}
	
	// ----------------------------------------------------
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_popup_window/sg_popup_response.layout";
	}
	
	override void LoadAllWidgets()
	{
		super.LoadAllWidgets();
		
		FindMultilineLabel("DescMultiLabel").SetText(m_MessageText);
		m_UiPrimaryButton = new SgUiButtonActionMedium(FindPanel("PrimaryButtonFrame"), m_PrimaryButtonText, DialogEvent_OnPrimaryButtonClicked);
		m_UiSecondaryButton = new SgUiButtonActionMedium(FindPanel("SecondaryButtonFrame"), m_SecondaryButtonText, DialogEvent_OnSecondaryButtonClicked);
	} 
	override void RegisterAllEvents()
	{
		super.RegisterAllEvents();
		
		DialogEvent_OnPrimaryButtonClicked.Insert(OnPrimaryButtonClicked);
		DialogEvent_OnSecondaryButtonClicked.Insert(OnSecondaryButtonClicked);
	}	
	override void UnRegisterAllEvents()
	{
		super.UnRegisterAllEvents();
		
		DialogEvent_OnPrimaryButtonClicked.Remove(OnPrimaryButtonClicked);
		DialogEvent_OnSecondaryButtonClicked.Remove(OnSecondaryButtonClicked);
	}
		
	// ------------------------------------------------------
	
	private void OnPrimaryButtonClicked()
	{
		Event_OnResponse.Invoke(SgEPopupButtonType.PRIMARY);
		SgDebug.Debug("Primary button pressed!",ClassName(), "OnClick");
	}	
	private void OnSecondaryButtonClicked()
	{
		Event_OnResponse.Invoke(SgEPopupButtonType.SECONDARY);
		SgDebug.Debug("Secondary button pressed!",ClassName(), "OnClick");
	}
}