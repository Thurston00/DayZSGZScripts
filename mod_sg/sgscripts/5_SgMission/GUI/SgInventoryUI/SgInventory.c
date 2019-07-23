modded class Inventory extends ContainerBase
{
	private static ref ScriptInvoker Event_OnItemInHandsChanged;
	
	void Inventory(LayoutHolder parent)
	{
		GetMainWidget().FindAnyWidget("SpecializationPanelPanel").Show(false);
	}
	
	
	static ScriptInvoker GetEventOnItemInHandsChanged()
	{
		if (!Event_OnItemInHandsChanged)
		{
			Event_OnItemInHandsChanged = new ScriptInvoker();
		}
		
		return Event_OnItemInHandsChanged;
	}
	
	override void UpdateInterval()
	{
		super.UpdateInterval();
		
		if (Event_OnItemInHandsChanged)
		{
			Event_OnItemInHandsChanged.Invoke();
		}
	}
}
