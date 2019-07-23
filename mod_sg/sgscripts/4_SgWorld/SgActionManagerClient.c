modded class ActionManagerClient
{
	static ref ScriptInvoker Event_OnContActionStart 	= new ScriptInvoker();
	static ref ScriptInvoker Event_OnContActionEnd 		= new ScriptInvoker();
	
	override void OnContinuousStart()
	{
		Event_OnContActionStart.Invoke();
		super.OnContinuousStart();
	}
	
	override void OnActionEnd()
	{
		Event_OnContActionEnd.Invoke();
		super.OnActionEnd();
	}
}