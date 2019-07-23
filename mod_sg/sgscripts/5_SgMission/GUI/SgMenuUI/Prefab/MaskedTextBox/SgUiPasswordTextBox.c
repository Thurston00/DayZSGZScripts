class SgUiPasswordTextBox extends SgUiMenuPanel
{
	// Widget
	protected 		Widget					m_UiPasswordTextBoxFrame;
	protected 		Widget	 				m_UiShowPassFrame;
	protected ref	SgUiMaskedTextBox		m_UiPasswordTextBox; 
	protected ref 	SgUiCheckBoxRowSmall 	m_UiShowPasswordCheckBox;
	// Data
	private 		string 					m_Hint;
	// Event
	protected ref ScriptInvoker 			Event_OnCheckboxChanged = new ref ScriptInvoker;
	
	// Constructor
	void SgUiPasswordTextBox(Widget parrent_widget, string hint = "")
	{
		this.m_Hint = hint;
		super.BuildLayout(parrent_widget);
	}
	
	// ----------------------------------------------------
	// Overrides --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_masked_text/sg_password_textbox.layout";
	}
	override void FindAllWidgets()
	{
		this.m_UiPasswordTextBoxFrame	= FindPanel("PasswordFrame");
		this.m_UiShowPassFrame			= FindPanel("ShowPasswordFrame");
	}	
	override void LoadAllWidgets()
	{
		this.SetPasswordTextBox();
		this.SetShowPasswordCheckBox();
		this.SwitchPasswordMask();
	}	
	override void RegisterAllEvents()
	{
		Event_OnCheckboxChanged.Insert(SwitchPasswordMask);
	}
	override void UnRegisterAllEvents()
	{
		Event_OnCheckboxChanged.Remove(SwitchPasswordMask);
	}
	
	// ------------------------------------------------------
	
	string GetText()
	{
		return this.m_UiPasswordTextBox.GetText();
	}
	
	// ------------------------------------------------------
	
	private void SetPasswordTextBox()
	{
		this.m_UiPasswordTextBox = new ref SgUiMaskedTextBox( this.m_UiPasswordTextBoxFrame, this.m_Hint );	
	}
	private void SetShowPasswordCheckBox()
	{
		this.m_UiShowPasswordCheckBox = new ref SgUiCheckBoxRowSmall( this.m_UiShowPassFrame, SgCMenuWidgetStrings.SHOW_PASSWORD, SgCMenuWidgetStrings.SHOW_PASSWORD, this.Event_OnCheckboxChanged );
	}

	// ------------------------------------------------------

	private void SwitchPasswordMask()
	{
		this.m_UiPasswordTextBox.SwitchMasked();
	}
}