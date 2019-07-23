class SgUiButtonMenuPrimary extends SgUiButtonSelection
{
	// Events
	static private ref ScriptInvoker Event_OnNavigationButtonSetUpdated = new ScriptInvoker();	// Event shared by all the buttons in navigation button set 
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_button/sg_button_menu_primary.layout";
	}	
	
	// ---------------------------------
	// Overrides --> SgUiMenuPanel
	override void RegisterAllEvents()
	{
		super.RegisterAllEvents();
		Event_OnNavigationButtonSetUpdated.Insert(OnNavigationUpdated);
	}
	override void UnRegisterAllEvents()
	{
		super.UnRegisterAllEvents();
		Event_OnNavigationButtonSetUpdated.Remove(OnNavigationUpdated);
	}	
		
	override protected void CallButtonSetEvent(Widget w)
	{
		if (Event_OnNavigationButtonSetUpdated)
		{
			Event_OnNavigationButtonSetUpdated.Invoke(w);
		}
	}
	
	static void UnselectAll()
	{
		Event_OnNavigationButtonSetUpdated.Invoke();
	}
}