class SgSClientTimer
{	
	protected bool 		m_IsRunning;
	protected int 		m_PreviousTimeStamp;
	protected int 		m_LastRoundTime;
	protected float 	m_CurrentTime;
	
	protected ref Timer	m_Timer;
	
	static ref ScriptInvoker ClientEvent_OneSecondTimerUpdate = new ScriptInvoker();	
	
	void SgSClientTimer()
	{
		SgSSyncEvents.SyncEvent_OnGameSyncTimer.Insert( SyncEvent_OnGameSyncTimer );
	}
	
	void ~SgSClientTimer()
	{
		if ( m_Timer != null )
		{
			m_Timer.Stop();
		}
		
		SgSSyncEvents.SyncEvent_OnGameSyncTimer.Remove( SyncEvent_OnGameSyncTimer );
	}
	
	static void CleanUp()
	{
		ClientEvent_OneSecondTimerUpdate.Clear();
	}
	
	//============================================
	// SyncEvent_OnGameSyncTimer
	//============================================
	void SyncEvent_OnGameSyncTimer( float time_left )
	{
		m_CurrentTime = time_left;
		
		if ( !m_IsRunning )
		{
			m_IsRunning 		= true;
			m_PreviousTimeStamp = GetGame().GetTime();
			m_LastRoundTime		= -1;
			m_Timer				= new Timer(CALL_CATEGORY_SYSTEM);
			
			m_Timer.Run( 0.1, this, "OnClientTimer", null, true );
		}
		
		OnClientTimer();
	}
	
	//----------------------------------
	// OnClientTimer 
	//----------------------------------
	protected void OnClientTimer()
	{
		int time_stamp = GetGame().GetTime();
		int delta_time = time_stamp - m_PreviousTimeStamp;
		
		m_CurrentTime -= (float)delta_time / 1000;
		m_PreviousTimeStamp = time_stamp;
		
		OneSecondNotifier();
	}
	
	//----------------------------------
	// OnClientTimer 
	//----------------------------------
	protected void OneSecondNotifier()
	{
		if ( !GetSgGame().GetClientIsLoaded() ) { return; }
		
		int round_time = Math.Ceil(m_CurrentTime);
		if ( m_LastRoundTime != round_time )
		{
			m_LastRoundTime = round_time;
			
			ClientEvent_OneSecondTimerUpdate.Invoke(round_time);
		}
	}
}