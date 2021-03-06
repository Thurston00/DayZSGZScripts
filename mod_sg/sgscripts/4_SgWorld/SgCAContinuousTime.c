modded class CAContinuousTime : CAContinuousBase
{	
	static ref ScriptInvoker Event_OnContActionTic 		= new ScriptInvoker();
	
	override int Execute( ActionData action_data )
	{	
		Event_OnContActionTic.Invoke(GetTimeRemaining());
		
		return super.Execute(action_data);		
	}
	
	float GetTimeRemaining()
	{
		return m_AdjustedTimeToComplete - m_TimeElpased;
	}
}