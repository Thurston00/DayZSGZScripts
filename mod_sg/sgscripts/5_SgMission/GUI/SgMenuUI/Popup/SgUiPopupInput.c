class SgUiPopupInput extends SgUiPopup
{
	// Widgets
	private ref SgUiPasswordTextBox		m_UiPassTextBox;
	private ref SgUiButtonActionMedium	m_UiPrimaryButton;
	private ref SgUiButtonActionMedium	m_UiSecondaryButton;
	// Data
	private 	string 	m_PrimaryButtonText;
	private 	string 	m_SecondaryButtonText;
	// Event
	private ref ScriptInvoker DialogeEvent_OnPrimaryButtonClicked = new ScriptInvoker();
	private ref ScriptInvoker DialogeEvent_OnSecondaryButtonClicked = new ScriptInvoker();
	
	void SgUiPopupInput(string header, string primary_button_text, string secondary_button_text)
	{
		m_HeaderText 				= header;
		m_PrimaryButtonText 		= primary_button_text;
		m_SecondaryButtonText 		= secondary_button_text;
		BuildLayout();
	}
	
	// ----------------------------------------------------
	// Overrides --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_popup_window/sg_popup_input.layout";
	}
	override void FindAllWidgets()
	{
		super.FindAllWidgets();		
	}	
	override void LoadAllWidgets()
	{
		super.LoadAllWidgets();
		
		m_UiPrimaryButton = new SgUiButtonActionMedium(FindPanel("PrimaryButtonFrame"), m_PrimaryButtonText, DialogeEvent_OnPrimaryButtonClicked );
		m_UiSecondaryButton = new SgUiButtonActionMedium(FindPanel("SecondaryButtonFrame"), m_SecondaryButtonText, DialogeEvent_OnSecondaryButtonClicked );
		m_UiPassTextBox = new SgUiPasswordTextBox(FindPanel("InputFrame"));
	}
	override void RegisterAllEvents()
	{
		super.RegisterAllEvents();
		DialogeEvent_OnPrimaryButtonClicked.Insert(OnPrimaryButtonClicked);
		DialogeEvent_OnSecondaryButtonClicked.Insert(OnSecondaryButtonClicked);
	}
	override void UnRegisterAllEvents()
	{
		super.RegisterAllEvents();
		DialogeEvent_OnPrimaryButtonClicked.Remove(OnPrimaryButtonClicked);
		DialogeEvent_OnSecondaryButtonClicked.Remove(OnSecondaryButtonClicked);
	}
		
	// ------------------------------------------------------
		
	private void OnPrimaryButtonClicked() 
	{
		Event_OnResponse.Invoke(SgEPopupButtonType.PRIMARY, m_UiPassTextBox.GetText());
		SgDebug.Debug("Primary button pressed!",ClassName(), "OnClick");
	}
	private void OnSecondaryButtonClicked()
	{
		Event_OnResponse.Invoke(SgEPopupButtonType.SECONDARY, "");
		SgDebug.Debug("Secondary button pressed!",ClassName(), "OnClick");
	}
}