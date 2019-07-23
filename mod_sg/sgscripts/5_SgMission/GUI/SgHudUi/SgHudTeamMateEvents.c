// DESIGN_ID: 0002

/*
	Class for all the teammate events used in client Hud (such as teammate health, status, trackers...)  
*/
class SgHudTeamMateEvents
{	
	// Teammates Updates	
 	ref ScriptInvoker HudEvent_OnTeammateHealthUpdate				= new ref ScriptInvoker();
	ref ScriptInvoker HudEvent_OnTeammateMicrophoneUpdate			= new ref ScriptInvoker();
	ref ScriptInvoker HudEvent_OnTeammateStatusUpdate				= new ref ScriptInvoker();
	// Marker Updates
	ref ScriptInvoker HudEvent_OnTeammateHUDMarkerLocationUpdate 	= new ref ScriptInvoker();
	ref ScriptInvoker HudEvent_OnTeammateCompassLocationUpdate 		= new ref ScriptInvoker();
	// Data
	private ref SgPlayerClient m_Teammate; 
	// Value Checks (they are used for checking if the values have been changed since last update)
	private float	m_LastHealth		= -1;
	private bool 	m_LastMic			= false;
	private int 	m_LastState			= -1;
	//  check how many times are these methods called pointlessly   SG_TODO: Delete this when hud is complete 
	private int m_RepeatCounterHealth 	= 0;
	private int m_RepeatCounterMic 		= 0;
	private int m_RepeatCounterState 	= 0;
	
	void SgHudTeamMateEvents(SgPlayerClient teammate)
	{
		m_Teammate = teammate;
		RegisterAllEvents();				//SG_60:40 - Hide The Aswesome Stuff Tha tDesigners Don't Want To Have In The Game For Now
	}	
	void ~SgHudTeamMateEvents()
	{
		// SG_TODO: Delete this when hud is complete
		Print("------------- TEAMMATE: " 	+ m_Teammate.GetPlayerUID());	
		Print("m_RepeatCounterHealth: " 	+ m_RepeatCounterHealth.ToString());	
		Print("m_RepeatCounterMic: " 		+ m_RepeatCounterMic.ToString());	
		Print("m_RepeatCounterState: " 		+ m_RepeatCounterState.ToString());	
		Print("-------------------------------------------------------------");	
	}	
	private void RegisterAllEvents()
	{
		// Player info updates
		SgPlayerBaseEvents player_events = m_Teammate.GetPlayerBase().GetPlayerEvents();	// Get PlayerBase events
		
		player_events.GetEvent_OnHealthUpdate().Insert(OnTeammateHealthUpdate);					// Health
		player_events.GetEvent_OnMicrophoneUpdate().Insert(OnTeammateMicrophoneUpdate);			// Microphone	
		player_events.GetEvent_OnStateUpdate().Insert(OnTeammateStatusUpdate);					// Status
	}
	
	// Per-Frame Update
	void UpdateTeammate(vector client_player_position)
	{		
		// Get Data
		vector 	teammate_position 	= m_Teammate.GetPosition();										// Get Teammate position		
		float 	distance			= vector.Distance(client_player_position, teammate_position);	// Distance between teammate and player
		float  	direction			= m_Teammate.GetDirection().VectorToAngles()[0]; 				// Get Teammate direction
		vector 	offset				= teammate_position - client_player_position;					// Calculate offset	
		
		if ( !m_Teammate.IsAlive() )
		{
			OnTeammateStatusUpdate(SgEPlayerStates.DEAD);
		}

		// Invokes
		HudEvent_OnTeammateHUDMarkerLocationUpdate.Invoke(distance, teammate_position);				// Update HUD marker
		HudEvent_OnTeammateCompassLocationUpdate.Invoke(distance, offset, direction);				// Update Compass		//SG_60:40 - Hide The Aswesome Stuff Tha tDesigners Don't Want To Have In The Game For Now
	}
	
	// Event Updates --------------------------------------------
	private void OnTeammateHealthUpdate(float health)
	{
	//	Print("Teammate ID: " 		+ m_Teammate.GetPlayerBase().GetIdentity().GetId() );
	//	Print("Teammate Name: " 	+ m_Teammate.GetUserName() );
	//	Print("Teammate Health: " 	+ health.ToString() );
		
		if (m_LastHealth != health)
		{
			m_LastHealth = health;
			HudEvent_OnTeammateHealthUpdate.Invoke( health );
		}	
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterHealth++;
		}
	}
	private void OnTeammateMicrophoneUpdate(bool is_talking)
	{
		if (m_LastMic != is_talking)
		{
			m_LastMic = is_talking;
			HudEvent_OnTeammateMicrophoneUpdate.Invoke( m_LastMic );
		}	
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterMic++;
		}
	}
	private void OnTeammateStatusUpdate(SgEPlayerStates state)
	{
		//Print("Teammate ID: " 		+ m_Teammate.GetPlayerBase().GetIdentity().GetId() );
		//Print("Teammate Name: " 	+ m_Teammate.GetUserName() );
		//Print("Teammate State: " 	+ state.ToString() );
		
		if (m_LastState != state)
		{
			m_LastState = state;
			HudEvent_OnTeammateStatusUpdate.Invoke( m_LastState );
		}	
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterState++;
		}
	}
	
	SgPlayerClient GetPlayerClient()
	{
		return m_Teammate;
	}
}