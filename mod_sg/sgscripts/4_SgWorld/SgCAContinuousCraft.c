modded class CAContinuousCraft : CAContinuousTime
{
	override int Execute( ActionData action_data  )
	{
		Event_OnContActionTic.Invoke(GetTimeRemaining());
		return super.Execute(action_data);
	}
}