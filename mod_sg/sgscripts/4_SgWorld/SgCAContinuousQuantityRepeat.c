modded class CAContinuousQuantityRepeat : CAContinuousBase
{	
	static ref ScriptInvoker Event_OnContActionTic 		= new ScriptInvoker();
	
	override int Execute( ActionData action_data )
	{	
		Event_OnContActionTic.Invoke(GetTimeRemaining());
		
		return super.Execute(action_data);		
	}
	
	float GetTimeRemaining()
	{
		float time = ((m_ItemQuantity) / m_QuantityUsedPerSecond);
		return time - m_TimeElpased;
	}
}