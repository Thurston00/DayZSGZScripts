class SgSWEH extends ScriptedWidgetEventHandler
{
	void Update()
	{
		
	}
	
	void Show()
	{
		
	}
	
	void Hide()
	{
		
	}
	
	void Toggle()
	{
		
	}
	
	void LockControls()
	{
		GetGame().GetInput().ChangeGameFocus(1, INPUT_DEVICE_MOUSE);
		GetGame().GetUIManager().ShowUICursor(true);

		GetGame().GetInput().ChangeGameFocus(1, INPUT_DEVICE_KEYBOARD);
		
		GetGame().GetInput().ChangeGameFocus(1, INPUT_DEVICE_GAMEPAD);
	}
	
	void UnlockControls()
	{
		GetGame().GetInput().ChangeGameFocus(-1, INPUT_DEVICE_MOUSE);
		GetGame().GetUIManager().ShowUICursor(true);
		
		GetGame().GetUIManager().ShowUICursor(false);
		
		GetGame().GetInput().ChangeGameFocus(-1, INPUT_DEVICE_KEYBOARD);
		GetGame().GetInput().ChangeGameFocus(-1, INPUT_DEVICE_GAMEPAD);
	}
}