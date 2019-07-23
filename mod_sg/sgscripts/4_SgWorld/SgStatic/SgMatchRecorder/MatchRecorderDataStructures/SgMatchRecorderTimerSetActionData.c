// Timer Set Action
class SgMatchRecorderTimerSetActionData
{
	protected int 					timer; 		// SG_TODO: m_Timer
	protected float 				timerStart; // SG_TODO: m_TimerStart
	
	void SgMatchRecorderTimerSetActionData(int timer, float timerStart)
	{
		this.timer 		= timer;
		this.timerStart = timerStart;
	}
}