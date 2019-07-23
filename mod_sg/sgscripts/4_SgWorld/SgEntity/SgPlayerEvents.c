/*
	Desc: 		SG class used as a collection for PlayerBase events
	Purpose: 	It can be used for any event connected to PlayerBase (such as overload, hp update...), separate from PlayerBase to improve readability 
*/
class SgPlayerBaseEvents
{
	private ref ScriptInvoker Event_OnOverloadUpdate;				// 1. Overload 		-> Parameter1: bool 			- Is overloaded?
	private ref ScriptInvoker Event_OnBleedingUpdate;  				// 2. Bleeding 		-> Parameter1: int  			- Bleeding sources
	private ref ScriptInvoker Event_OnHealthUpdate;   				// 3. Health 		-> Parameter1: float			- Health points
	private ref ScriptInvoker Event_OnMicrophoneUpdate; 			// 4. Microphone	-> Parameter1: bool				- Is talking? 			SG_TODO: Register this when the functionality is prepared 
	private ref ScriptInvoker Event_OnStateUpdate;					// 5. State 		-> Parameter1: SgEPlayerStates	- Player state
	private ref ScriptInvoker Event_OnStanceUpdate;					// 6. Stance 		-> Parameter1: int				- Player statnce (prone, croucn .. )
	private ref ScriptInvoker Event_OnItemInHandsUpdate;			// 7. ItemInHands	-> Parameter1: EntityAI			- Player item in hands
	private ref ScriptInvoker Event_OnPlayerHit;					// 8. PlayerHit		-> void					
	private ref ScriptInvoker Event_OnFireModeSwiched;				// 9. Fire mode		-> void  												SG_TODO: What about moving this into Weapon class instead? 
	private ref ScriptInvoker Event_OnStaminaUpdate;				//10. Stamina 		-> Parameter1: float 			- Stamina value , Parameter2: 	- range				
	
	void SgPlayerBaseEvents()
	{
		//RegisterEventsForDebug();
	}
	
	// ---------------------------------------------------------------
	// GETTERS
	ScriptInvoker GetEvent_OnOverloadUpdate()						// 1.
	{
		if (!Event_OnOverloadUpdate)
		{
			Event_OnOverloadUpdate = new ref ScriptInvoker();
		}
		return Event_OnOverloadUpdate;
	}	
	ScriptInvoker GetEvent_OnBleedingUpdate()						// 2.
	{
		if (!Event_OnBleedingUpdate)
		{
			Event_OnBleedingUpdate = new ref ScriptInvoker();
		}
		return Event_OnBleedingUpdate;
	}	
	ScriptInvoker GetEvent_OnHealthUpdate()							// 3.
	{
		if (!Event_OnHealthUpdate)
		{
			Event_OnHealthUpdate = new ref ScriptInvoker();
		}
		return Event_OnHealthUpdate;
	}	
	ScriptInvoker GetEvent_OnMicrophoneUpdate()						// 4.
	{
		if (!Event_OnMicrophoneUpdate)
		{
			Event_OnMicrophoneUpdate = new ref ScriptInvoker();
		}
		return Event_OnMicrophoneUpdate;
	}	
	ScriptInvoker GetEvent_OnStateUpdate()							// 5.
	{
		if (!Event_OnStateUpdate)
		{
			Event_OnStateUpdate = new ref ScriptInvoker();
		}
		return Event_OnStateUpdate;
	}	
	ScriptInvoker GetEvent_OnStanceUpdate()							// 6.
	{
		if (!Event_OnStanceUpdate)
		{
			Event_OnStanceUpdate = new ref ScriptInvoker();
		}
		return Event_OnStanceUpdate;
	}
	ScriptInvoker GetEvent_OnEvent_OnItemInHandsUpdate()			// 7.
	{
		if (!Event_OnItemInHandsUpdate)
		{
			Event_OnItemInHandsUpdate = new ref ScriptInvoker();
		}
		return Event_OnItemInHandsUpdate;
	}	
	ScriptInvoker GetEvent_OnPlayerHit()							// 8.
	{
		if (!Event_OnPlayerHit)
		{
			Event_OnPlayerHit = new ref ScriptInvoker();
		}
		return Event_OnPlayerHit;
	}	
	ScriptInvoker GetEvent_OnFireModeSwiched()						// 9.
	{
		if (!Event_OnFireModeSwiched)
		{
			Event_OnFireModeSwiched = new ref ScriptInvoker();
		}
		return Event_OnFireModeSwiched;
	}		
	ScriptInvoker GetEvent_OnStaminaUpdated()						// 9.
	{
		if (!Event_OnStaminaUpdate)
		{
			Event_OnStaminaUpdate = new ref ScriptInvoker();
		}
		return Event_OnStaminaUpdate;
	}	
	
	// --------------------------------------------------------------
	// DEBUG
	private void RegisterEventsForDebug()
	{	
		GetEvent_OnOverloadUpdate().Insert(Event_OnOverloadUpdateDebug);				// 1.
		GetEvent_OnBleedingUpdate().Insert(Event_OnBleedingUpdateDebug);				// 2.
		//GetEvent_OnHealthUpdate().Insert(Event_OnHealthUpdateDebug);					// 3.
		GetEvent_OnMicrophoneUpdate().Insert(Event_OnMicrophoneUpdateDebug);			// 4.
		GetEvent_OnStateUpdate().Insert(Event_OnStateUpdateDebug);						// 5.
		//GetEvent_OnStanceUpdate().Insert(Event_OnStanceUpdateDebug);					// 6.		<-- disabled as it's per-frame and spam the debug output
		GetEvent_OnEvent_OnItemInHandsUpdate().Insert(Event_OnItemInHandsUpdateDebug);	// 7.
		GetEvent_OnPlayerHit().Insert(Event_OnPlayerHitDebug);							// 8.
		GetEvent_OnFireModeSwiched().Insert(Event_OnFireModeSwichedDebug);				// 9.
	}
	
	private void Event_OnOverloadUpdateDebug(bool is_overloaded )						// 1.
	{
		Print(string.Format("%1: %2 has been invoked. Param1: %3", ClassName(), "Event_OnOverloadUpdateDebug", is_overloaded.ToString()));
	}	
	private void Event_OnBleedingUpdateDebug(int bleeding_source)						// 2.
	{
		Print(string.Format("%1: %2 has been invoked. Param1: %3", ClassName(), "Event_OnBleedingUpdateDebug", bleeding_source.ToString()));
	}	
	private void Event_OnHealthUpdateDebug(float hp )									// 3.
	{
		Print(string.Format("%1: %2 has been invoked. Param1: %3", ClassName(), "Event_OnHealthUpdateDebug", hp.ToString()));
	}
	private void Event_OnMicrophoneUpdateDebug(bool mic )								// 4.
	{
		Print(string.Format("%1: %2 has been invoked. Param1: %3", ClassName(), "Event_OnMicrophoneUpdate", mic.ToString()));
	}
	private void Event_OnStateUpdateDebug(int state)									// 5.
	{
		Print(string.Format("%1: %2 has been invoked. Param1: %3", ClassName(), "Event_OnStateUpdate", state.ToString()));
	}	
	private void Event_OnStanceUpdateDebug(int stance)									// 6.
	{
		Print(string.Format("%1: %2 has been invoked. Param1: %3", ClassName(), "Event_OnStanceUpdate", stance.ToString()));
	}	
	private void Event_OnItemInHandsUpdateDebug(EntityAI item)							// 7.
	{
		Print(string.Format("%1: %2 has been invoked. Param1: %3", ClassName(), "Event_OnItemInHandsUpdate", item.GetDisplayName()));
	}	
	private void Event_OnPlayerHitDebug()												// 8.
	{
		Print(string.Format("%1: %2 has been invoked.", ClassName(), "Event_OnPlayerHit"));
	}
	private void Event_OnFireModeSwichedDebug()											// 9.
	{
		Print(string.Format("%1: %2 has been invoked.", ClassName(), "Event_OnFireModeSwiched"));
	}
}