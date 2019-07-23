class SgUiPopup extends SgUiMenuPanel
{
	protected 		TextWidget		m_UiHeaderLabel;
	protected 		string 			m_HeaderText;
	protected ref 	ScriptInvoker	Event_OnResponse = new ref ScriptInvoker();

	// ---------------------------------------------
	// Override --> SgUiMenuPanel
	override void FindAllWidgets()
	{
		m_UiHeaderLabel = FindLabel("HeaderLabel");
	}	
	override void LoadAllWidgets()
	{
		m_UiHeaderLabel.SetText(m_HeaderText);
	}
	override void RegisterAllEvents()
	{
		Event_OnResponse.Insert(OnResponseSelected);
	}
	override void UnRegisterAllEvents()
	{
		Event_OnResponse.Remove(OnResponseSelected);
	}
	
	// ---------------------------------------------
	// Getters
	
	ScriptInvoker GetResponseEvent()
	{
		return Event_OnResponse;		
	}

	// ---------------------------------------------
	// PopUp Reponse management
	
	// Close popup after a reponse
	private void OnResponseSelected()
	{
		SgMenuManager.ClosePopup();
	}
}