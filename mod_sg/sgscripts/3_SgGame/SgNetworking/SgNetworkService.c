// DESIGN_ID: 0001

/*
	- Singleton 
	- This class is a middle man between code back-end and script for all the accessible network services and calls 
*/
class SgNetworkService
{	
	// -------------------------------------------------------------------------
	// Client menu Response Events only
	static private ref ScriptInvoker Event_OnLoggedIn;
	static private ref ScriptInvoker Event_OnLobbyListLoaded;
	static private ref ScriptInvoker Event_OnLobbyCreated;
	static private ref ScriptInvoker Event_OnLobbyDeleted;
	static private ref ScriptInvoker Event_OnLobbyJoined;
	static private ref ScriptInvoker Event_OnLobbyLeft;
	static private ref ScriptInvoker Event_OnLobbySlotSet;
	static private ref ScriptInvoker Event_OnTeamJoined;
	static private ref ScriptInvoker Event_OnTeamLeft;
	static private ref ScriptInvoker Event_OnLobbyPlayerReadied;
	static private ref ScriptInvoker Event_OnLobbyStarted;
	static private ref ScriptInvoker Event_OnGameServerIsReadied;
	
	// Server Events only 
	static private ref ScriptInvoker Event_OnGameServerMatchInfoLoaded;	
	
	// ------------------------------------------

	proto native owned string GetUserUID();
	proto static native SgNetworkService GetService();
	
	// ------------------------------------------------------------------------
	// REQUESTS 
	
	// Client Menu Only
	// - Menu
	proto native SgEResult StartSearchForMatch(SgNetDataSearchForMatchStartRequest inputValue);		
	proto native SgEResult CancelSearchForMatch(SgNetDataSearchForMatchCancelRequest inputValue);		
	// - Lobby
	proto native SgEResult LoadLobbyList(SgNetDataLobbyListLoadRequest inputValue);
	proto native SgEResult CreateLobby(SgNetDataLobbyCreateRequest inputValue);
	proto native SgEResult DeleteLobby(SgNetDataLobbyDeleteRequest inputValue);
	proto native SgEResult JoinLobby(SgNetDataLobbyJoinRequest inputValue);
	proto native SgEResult LeaveLobby(SgNetDataLobbyLeaveRequest inputValue);
	proto native SgEResult SetLobbySlot(SgNetDataLobbySlotSetRequest inputValue);
	proto native SgEResult JoinTeam(SgNetDataTeamJoinRequest inputValue);
	proto native SgEResult LeaveTeam(SgNetDataTeamLeaveRequest inputValue);
	proto native SgEResult ReadyLobbyPlayer(SgNetDataPlayerReadyRequest inputValue);
	proto native SgEResult StartLobbyGame(SgNetDataLobbyGameStartRequest inputValue);		
	
	//Server Only Calls
	proto native SgEResult GameServerLoadMatchInfo();
	proto native SgEResult GameServerReadyServer();
	//proto native SgEResult GameServerRecordMatch(SgNetServerDataMatchRecordRequest inputValue);
	proto native SgEResult GameServerFinishGame(SgNetServerDataGameFinishRequest inputValue);
	
	static private bool m_IsLoggedIn = false;
	
	// ----------------------------------------------------------------------------
	// GETTERS
	
	bool IsLoggedIn()
	{
		return m_IsLoggedIn;
	}
	
	ScriptInvoker GetEvent_OnLoggedIn()
	{
		if (!Event_OnLoggedIn)
		{
			Event_OnLoggedIn = new ScriptInvoker();
		}
		return Event_OnLoggedIn;
	}	
	
	ScriptInvoker GetEvent_OnLobbyListLoaded()
	{
		if (!Event_OnLobbyListLoaded)
		{
			Event_OnLobbyListLoaded = new ScriptInvoker();
		}
		return Event_OnLobbyListLoaded;
	}
	ScriptInvoker GetEvent_OnLobbyCreated()
	{
		if (!Event_OnLobbyCreated)
		{
			Event_OnLobbyCreated = new ScriptInvoker();
		}
		return Event_OnLobbyCreated;
	}	
	ScriptInvoker GetEvent_OnLobbyDeleted()
	{
		if (!Event_OnLobbyDeleted)
		{
			Event_OnLobbyDeleted = new ScriptInvoker();
		}
		return Event_OnLobbyDeleted;
	}
	ScriptInvoker GetEvent_OnLobbyJoined()
	{
		if (!Event_OnLobbyJoined)
		{
			Event_OnLobbyJoined = new ScriptInvoker();
		}
		return Event_OnLobbyJoined;
	}	
	ScriptInvoker GetEvent_OnLobbyLeft()
	{
		if (!Event_OnLobbyLeft)
		{
			Event_OnLobbyLeft = new ScriptInvoker();
		}
		return Event_OnLobbyLeft;
	}	
	ScriptInvoker GetEvent_OnLobbySlotSet()
	{
		if (!Event_OnLobbySlotSet)
		{
			Event_OnLobbySlotSet = new ScriptInvoker();
		}
		return Event_OnLobbySlotSet;
	}	
	ScriptInvoker GetEvent_OnTeamJoined()
	{
		if (!Event_OnTeamJoined)
		{
			Event_OnTeamJoined = new ScriptInvoker();
		}
		return Event_OnTeamJoined;
	}	
	ScriptInvoker GetEvent_OnTeamLeft()
	{
		if (!Event_OnTeamLeft)
		{
			Event_OnTeamLeft = new ScriptInvoker();
		}
		return Event_OnTeamLeft;
	}	
	ScriptInvoker GetEvent_OnLobbyPlayerReadied()
	{
		if (!Event_OnLobbyPlayerReadied)
		{
			Event_OnLobbyPlayerReadied = new ScriptInvoker();
		}
		return Event_OnLobbyPlayerReadied;
	}	
	ScriptInvoker GetEvent_OnLobbyStarted()
	{
		if (!Event_OnLobbyStarted)
		{
			Event_OnLobbyStarted = new ScriptInvoker();
		}
		return Event_OnLobbyStarted;
	}	
	ScriptInvoker GetEvent_OnGameServerIsReadied()
	{
		if (!Event_OnGameServerIsReadied)
		{
			Event_OnGameServerIsReadied = new ScriptInvoker();
		}
		return Event_OnGameServerIsReadied;
	}	
	ScriptInvoker GetEvent_OnGameServerMatchInfoLoaded()
	{
		if (!Event_OnGameServerMatchInfoLoaded)
		{
			Event_OnGameServerMatchInfoLoaded = new ScriptInvoker();
		}
		return Event_OnGameServerMatchInfoLoaded;
	}
	
	// ----------------------------------------------------------------------------
	// CALLBACKS - Event methods / invokes 
	
	void OnLoggedIn(SgEResult resultStatus)
	{
		m_IsLoggedIn = true;

		if (Event_OnLoggedIn)
		{
			Event_OnLoggedIn.Invoke(resultStatus);
		}
	}
	
	void OnAddedToMatch()
	{
		
	}

	void OnLobbyListLoaded(SgEResult resultStatus, ref SgNetDataLobbyListLoadResponse resultValue)
	{
		if (Event_OnLobbyListLoaded)
		{
			Event_OnLobbyListLoaded.Invoke(resultStatus, resultValue);
		}
	}

	void OnLobbyCreated(SgEResult resultStatus, ref SgNetDataLobbyCreateResponse resultValue)
	{		
		if (Event_OnLobbyCreated)
		{
			Event_OnLobbyCreated.Invoke(resultStatus, resultValue);
		}
	}

	void OnLobbyDeleted(SgEResult resultStatus, ref SgNetDataLobbyDeleteResponse resultValue)
	{
		if (Event_OnLobbyDeleted)
		{
			Event_OnLobbyDeleted.Invoke(resultStatus, resultValue);
		}
	}

	void OnLobbyJoined(SgEResult resultStatus, ref SgNetDataLobbyJoinResponse resultValue)
	{		
		if (Event_OnLobbyJoined)
		{
			Event_OnLobbyJoined.Invoke(resultStatus, resultValue);
		}
	}

	void OnLobbyLeft(SgEResult resultStatus, ref SgNetDataLobbyLeaveResponse resultValue)
	{
		if (Event_OnLobbyLeft)
		{
			Event_OnLobbyLeft.Invoke(resultStatus, resultValue);
		}
	}

	void OnSlotSet(SgEResult resultStatus, ref SgNetDataLobbySlotSetResponse resultValue)
	{
		if (Event_OnLobbySlotSet)
		{
			Event_OnLobbySlotSet.Invoke(resultStatus, resultValue);
		}
	}

	void OnTeamJoined(SgEResult resultStatus, ref SgNetDataTeamJoinResponse resultValue)
	{
		if (Event_OnTeamJoined)
		{
			Event_OnTeamJoined.Invoke(resultStatus, resultValue);
		}
	}

	void OnTeamLeft(SgEResult resultStatus, ref SgNetDataTeamLeaveResponse resultValue)
	{
		if (Event_OnTeamLeft)
		{
			Event_OnTeamLeft.Invoke(resultStatus, resultValue);
		}
	}

	void OnPlayerReadied(SgEResult resultStatus, ref SgNetDataPlayerReadyResponse resultValue)
	{
		if (Event_OnLobbyPlayerReadied)
		{
			Event_OnLobbyPlayerReadied.Invoke(resultStatus, resultValue);
		}
	}

	void OnLobbyStarted(SgEResult resultStatus, ref SgNetDataLobbyGameStartResponse resultValue)
	{
		if (Event_OnLobbyStarted)
		{
			Event_OnLobbyStarted.Invoke(resultValue);
		}
	}
	
	void OnGameServerMatchInfoLoaded(SgEResult resultStatus, ref SgNetServerDataMatchLoadResponse resultValue)
	{
		if (Event_OnGameServerMatchInfoLoaded)
		{
			Event_OnGameServerMatchInfoLoaded.Invoke(resultValue);
		}
	}
	
	void OnGameServerServerReadied(SgEResult resultStatus, ref SgNetServerDataServerReadyResponse resultValue)
	{
		if (Event_OnGameServerIsReadied)
		{
			Event_OnGameServerIsReadied.Invoke(resultValue);
		}
	}
};