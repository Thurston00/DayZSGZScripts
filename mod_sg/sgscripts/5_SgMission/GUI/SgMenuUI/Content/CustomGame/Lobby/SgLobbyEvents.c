class SgLobbyEvents
{	
	private ref SgUiLobbyBase m_Lobby;
	
	static ref ScriptInvoker Event_UnassignePlayer 				= new ScriptInvoker();
	static ref ScriptInvoker Event_AssignePlayer 				= new ScriptInvoker();
	static ref ScriptInvoker Event_OnDestroyLobbyByttonClicked 	= new ScriptInvoker();	
	static ref ScriptInvoker Event_OnStartGameButtonClicked 	= new ScriptInvoker();
	static ref ScriptInvoker Event_OnReadyGameButtonClicked 	= new ScriptInvoker();
	static ref ScriptInvoker Event_OnLeaveLobbyButtonClicked 	= new ScriptInvoker();
	static ref ScriptInvoker Event_OnPrimaryButtonEnabled 		= new ScriptInvoker();
	
	private SgNetworkService m_NetService;
	
	void SgLobbyEvents(SgUiLobbyBase lobby)
	{
		m_NetService = SgNetworkService.GetService();
		m_Lobby = lobby; 
		RegisterAllEvents();
	}	
	
	void ~SgLobbyEvents()
	{
		UnRegisterAllEvents();
	}
	
	protected void RegisterAllEvents()
	{	
		// Network Events
		m_NetService.GetEvent_OnLobbyJoined().Insert(Event_OnLobbyJoined);						// Join lobby
		m_NetService.GetEvent_OnLobbyLeft().Insert(Event_OnLobbyLeft);							// Leave lobby
		m_NetService.GetEvent_OnLobbyPlayerReadied().Insert(Event_OnLobbyPlayerReadied);		// Ready players update
		m_NetService.GetEvent_OnTeamJoined().Insert(Event_OnTeamJoined);						// Update player location
		m_NetService.GetEvent_OnTeamLeft().Insert(Event_OnTeamLeft);							// Update unassigned players
		m_NetService.GetEvent_OnGameServerIsReadied().Insert(Event_OnGameServerIsReadied);		// Start Game
		m_NetService.GetEvent_OnLobbyStarted().Insert(Event_OnLobbyStarted);					// Waiting for server to initialize 
		// Buttons
		Event_OnStartGameButtonClicked.Insert(StartLobbyGameRequest);
		Event_OnReadyGameButtonClicked.Insert(ChangePlayerReadinessRequest);
		Event_OnLeaveLobbyButtonClicked.Insert(LeaveLobbyWindowThread);
		Event_OnDestroyLobbyByttonClicked.Insert(DestroyLobby);
		// Player Location Events
		Event_UnassignePlayer.Insert(LeaveTeamRequest);
		Event_AssignePlayer.Insert(JoinTeamRequest);
		// Button Events
	}
	
	protected void UnRegisterAllEvents()
	{	
		// Network Events
		m_NetService.GetEvent_OnLobbyJoined().Remove(Event_OnLobbyJoined);						// Join lobby
		m_NetService.GetEvent_OnLobbyLeft().Remove(Event_OnLobbyLeft);							// Leave lobby
		m_NetService.GetEvent_OnLobbyPlayerReadied().Remove(Event_OnLobbyPlayerReadied);		// Ready players update
		m_NetService.GetEvent_OnTeamJoined().Remove(Event_OnTeamJoined);						// Update player location
		m_NetService.GetEvent_OnTeamLeft().Remove(Event_OnTeamLeft);							// Update unassigned players
		m_NetService.GetEvent_OnGameServerIsReadied().Remove(Event_OnGameServerIsReadied);		// Start Game
		m_NetService.GetEvent_OnLobbyStarted().Remove(Event_OnLobbyStarted);					// Waiting for server to initialize 
		// Buttons
		Event_OnStartGameButtonClicked.Remove(StartLobbyGameRequest);
		Event_OnReadyGameButtonClicked.Remove(ChangePlayerReadinessRequest);
		Event_OnLeaveLobbyButtonClicked.Remove(LeaveLobbyWindowThread);
		// Player Location Events
		Event_UnassignePlayer.Remove(LeaveTeamRequest);
		Event_AssignePlayer.Remove(JoinTeamRequest);
		// Button Events
		Event_OnDestroyLobbyByttonClicked.Remove(DestroyLobby);
	}
	
	// -----------------------------------------------------------------------------------
	// Server Input methods
	
	private void LeaveTeamRequest()
	{
		//SgDebug.Debug("Requesting Unassigne player event.", this.ClassName(), "LeaveTeamRequest");
		
		// If client is assigned
		if (m_Lobby.GetLobbyData().AmIAssigned())
		{
			// Prepare data
			string match_id = m_Lobby.GetLobbyData().GetLobbyID();
			// Create server request
			SgNetDataTeamLeaveRequest request = new SgNetDataTeamLeaveRequest(match_id);
			// Send the request
			SgEResult result = SgSNetworkServiceWrapper.UnJoinTeam(request);
		
			if (result == SgEResult.OK)
			{
				// Unassigne player
				m_Lobby.GetLobbyData().GetClientPlayerData().SetPlayerLocation(-1,-1); 
				// Unready player
				UnReadyLobbyPlayerRequest();
				// Update widget
				SgLobbyData.Event_OnPlayerLocationUpdated.Invoke();
				// Update ready button
				Event_OnPrimaryButtonEnabled.Invoke(false);	
			}
		}
		else 
		{
			SgDebug.Error("Already unassigned", this.ClassName(), "LeaveTeamRequest");
		}
	}
		
	// Request server to join client into this slot
	private void JoinTeamRequest(int team_index, int slot_index)
	{
		//SgDebug.Debug("Requesting Assigne player event.", this.ClassName(), "JoinTeamRequest");
		
		// Prepare data
		string lobby_id = m_Lobby.GetLobbyData().GetLobbyID();
		// Create Request
		SgNetDataTeamJoinRequest request = new ref SgNetDataTeamJoinRequest(lobby_id, team_index, slot_index);
		// Send request
		SgEResult result = SgSNetworkServiceWrapper.JoinTeam(request);
		
		if (result == SgEResult.OK)
		{
			// Update player location data
			m_Lobby.GetLobbyData().GetClientPlayerData().SetPlayerLocation(team_index, slot_index);
			// Unready player because of the change 
			UnReadyLobbyPlayerRequest();
			// Update widgets
			SgLobbyData.Event_OnPlayerLocationUpdated.Invoke();
			// Update ready button
			Event_OnPrimaryButtonEnabled.Invoke(true);		
		}
		
	}
	
	// Send request to ready client
	private void ChangePlayerReadinessRequest()
	{
		//SgDebug.Debug("Requesting Ready Client event.", this.ClassName(), "ChangePlayerReadinessRequest");
			
		// Prepare data
		string lobby_id = m_Lobby.GetLobbyData().GetLobbyID();	// get lobby id
		bool is_ready	= !m_Lobby.GetLobbyData().AmIReady();	// revert current state
		// Create request
		SgNetDataPlayerReadyRequest request = new SgNetDataPlayerReadyRequest(lobby_id, is_ready);
		// Send request
		SgEResult result = SgSNetworkServiceWrapper.PlayerReady(request);
		
		// Handle request result
		if (result == SgEResult.OK)
		{
			// Update ready data
			m_Lobby.GetLobbyData().GetClientPlayerData().SetReadyCheck(is_ready);
			// Update lobby widgets
			SgLobbyData.Event_OnPlayerLocationUpdated.Invoke();
		}
	}
	
	// Send request to unready client
	private void UnReadyLobbyPlayerRequest()
	{
		//SgDebug.Debug("Requesting UnReady Client event.", this.ClassName(), "UnReadyLobbyPlayerRequest");
			
		// Prepare data
		string lobby_id = m_Lobby.GetLobbyData().GetLobbyID();	// get lobby id
		bool is_ready	= false;
		// Create request
		SgNetDataPlayerReadyRequest request = new SgNetDataPlayerReadyRequest(lobby_id, is_ready);
		// Send request
		SgEResult result = SgSNetworkServiceWrapper.PlayerReady(request);
		
		// Handle request result
		if (result == SgEResult.OK)
		{
			// Update ready data
			m_Lobby.GetLobbyData().GetClientPlayerData().SetReadyCheck(is_ready);
			// Update lobby widgets
			SgLobbyData.Event_OnPlayerLocationUpdated.Invoke();
		}
	}
	
	private void StartLobbyGameRequest()
	{
		//SgDebug.Debug("Requesting Start Game event.", this.ClassName(), "StartLobbyGameRequest");
		
		// Prepare Data
		string lobby_id = m_Lobby.GetLobbyData().GetLobbyID();	// get lobby id
		// Create request
		SgNetDataLobbyGameStartRequest request 	= new ref SgNetDataLobbyGameStartRequest(lobby_id);
		// Send request
		SgEResult result 						= SgSNetworkServiceWrapper.CustomGamePlayButton(request);
		
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(WaitForResponsePopup);
		
		if (result == SgEResult.OK)
		{	
			Print("Start Game Request Sent!");
		}
	}
	
	private void WaitForResponsePopup()
	{
		SgMenuManager.OpenLoadingPopup( SgCPopupHeaderTexts.WAIT_FOR_RESPONSE);
	}
	
	private void WaitForServerPopup()
	{
		SgMenuManager.OpenLoadingPopup( SgCPopupHeaderTexts.WAIT_FOR_SERVER);
	}
	
	// On Destroy Lobby Button Clicked
	private void DestroyLobby()
	{
		//SgDebug.Debug("Requesting Destroy Lobby event.", this.ClassName(), "DestroyLobby");
		
		// If client is host 
		if (m_Lobby.GetLobbyData().AmIHost())
		{
			// Create destroy button popup
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(DestroyLobbyWindowThread);
		}
		else 
		{
			SgDebug.Error("Access denied: Your are not a host", this.ClassName(), "DestroyLobby");
		}
	}
	
	// On Footer secondary button click	--> Leave Lobby
	private void LeaveLobby()
	{
		// Create leave lobby popup
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(LeaveLobbyWindowThread);
	}
	
	// On Footer Primary button click -> Start Game/ Ready Player 
	private void EventResponse_OnPrimaryFooterButtonClicked()
	{		
		// If player is assigned to a slot
		if (m_Lobby.GetLobbyData().AmIAssigned())
		{		
			// If player is host
			if (m_Lobby.GetLobbyData().AmIHost())
			{
				// Start Game
				StartLobbyGameRequest();
			}
			else 
			{
				// Ready/UnReady Player
				ChangePlayerReadinessRequest();
			}
		}
		else 
		{
			SgDebug.Error("Client need to be joined in a team before setting a ready state or starting the game", this.ClassName(), "EventResponse_OnEventRequest_OnReadyClient");
		}
	}
		
	// Create Destroy lobby popup
	private void DestroyLobbyWindowThread()
	{
		// Create the popup
		ScriptInvoker response = SgMenuManager.OpenUserResponseInputPopup(SgCPopupHeaderTexts.LOBBY_DESTROY, SgCPopupDescTexts.LOBBY_DESTROY, SgCPopupButtonTexts.DESTROY, SgCPopupButtonTexts.CANCEL);
		response.Insert(DeleteLobbyRequest);	
	}	
	
	// Destroy lobby event --> called after destroy lobby popup response selected
	private void DeleteLobbyRequest(SgEPopupButtonType button)
	{
		// If confirm button clicked
		if (button == SgEPopupButtonType.PRIMARY)
		{
			// Prepare data
			string lobby_id = m_Lobby.GetLobbyData().GetLobbyID();
			// Crete destroy lobby request
			SgNetDataLobbyDeleteRequest request = new SgNetDataLobbyDeleteRequest(lobby_id);
			// Send request
			SgEResult result = SgSNetworkServiceWrapper.DeleteLobby(request);
			// If request OK 
			if ( result == SgEResult.OK)
			{
				// Go back to main screen
				SgMenuManager.CloseActiveContentMenu();
			}
		}
	}
	
	// Create Leave Lobby popup 
	private void LeaveLobbyWindowThread()
	{
		// Create the popup
		ScriptInvoker response = SgMenuManager.OpenUserResponseInputPopup(SgCPopupHeaderTexts.LEAVE_LOBBY, SgCPopupDescTexts.LEAVE_LOBBY, SgCPopupButtonTexts.LEAVE, SgCPopupButtonTexts.CANCEL);	
		response.Insert(LeaveLobbyRequest);	
	}
	
	// Leave lobby method --> called after leave lobby popup response selected
	void LeaveLobbyRequest(SgEPopupButtonType button)
	{		
		// If clicked on confirm button
		if (button == SgEPopupButtonType.PRIMARY)
		{
			// Prepare data
			string lobby_id = m_Lobby.GetLobbyData().GetLobbyID();
			// Create request to leave lobby
			SgNetDataLobbyLeaveRequest request = new SgNetDataLobbyLeaveRequest(lobby_id);
			// Send the request
			SgEResult result = SgSNetworkServiceWrapper.LeaveLobby(request);
			
			// If request OK
			if (result == SgEResult.OK)
			{
				// Go back to main screen
				SgMenuManager.CloseActiveContentMenu();
			}
		}
	}
		
	// ----------------------------------------------------------------------------------------------
	// Server Output methods
	
	// Event method when recieved lobby data
	private void Event_OnLobbyJoined(SgEResult resultStatus, ref SgNetDataLobbyJoinResponse resultValue)
	{
		//SgDebug.Debug("Join Lobby event executed.", this.ClassName(), "Event_OnLobbyJoined");

		// Set new player list
		m_Lobby.GetLobbyData().SetPlayerList(resultValue.GetLobbyDetails().GetLobbyPlayers());
		// Update player widget
		SgLobbyData.Event_OnLobbyDataUpdated.Invoke();
	}
	
	// Event method when leave lobby
	private void Event_OnLobbyLeft(SgEResult resultStatus, ref SgNetDataLobbyLeaveResponse resultValue)
	{
		//SgDebug.Debug("Leave Lobby event executed.", this.ClassName(), "Event_OnLobbyLeft");
		
		// Remove player from a list
		m_Lobby.GetLobbyData().RemovePlayerFromList(resultValue.GetPlayerUID());
		// Update lobby widget
		SgLobbyData.Event_OnLobbyDataUpdated.Invoke();
	}
	
	private void Event_OnLobbyPlayerReadied(SgEResult resultStatus, ref SgNetDataPlayerReadyResponse resultValue)
	{
		//SgDebug.Debug("Update Player Readiness event executed.", this.ClassName(), "Event_OnLobbyPlayerReadied");
		
		if (resultValue.GetPlayerUID() != m_Lobby.GetLobbyData().GetClientUID())
		{
			// Find player
			SgNetDataLobbyPlayer player = m_Lobby.GetLobbyData().FindPlayerByID(resultValue.GetPlayerUID());			
			// Update player ready data
			player.SetReadyCheck(resultValue.GetReady());
			// Update lobby widgets
			SgLobbyData.Event_OnPlayerLocationUpdated.Invoke();
		}
	}
	
	private void Event_OnTeamJoined(SgEResult resultStatus, ref SgNetDataTeamJoinResponse resultValue)
	{
		//SgDebug.Debug("Update Player Location event executed.", this.ClassName(), "Event_OnTeamJoined");
		
		// If change is not in client 
		if (resultValue.GetPlayerUID() != m_Lobby.GetLobbyData().GetClientUID())
		{
			// Update player's location
			m_Lobby.GetLobbyData().FindPlayerByID(resultValue.GetPlayerUID()).SetPlayerLocation(resultValue.GetTeamIndex(), resultValue.GetSlotIndex());
			// Update lobby widgets
			SgLobbyData.Event_OnPlayerLocationUpdated.Invoke();
		}
	}
	
	private void Event_OnTeamLeft(SgEResult resultStatus, ref SgNetDataTeamLeaveResponse resultValue)
	{
		//SgDebug.Debug("Unassigne player event executed.", this.ClassName(), "Event_OnTeamLeft");
	
		// If change is not in client 
		if (resultValue.GetPlayerUID() != m_Lobby.GetLobbyData().GetClientUID())
		{
			// Udpate player's location data
			m_Lobby.GetLobbyData().FindPlayerByID(resultValue.GetPlayerUID()).SetPlayerLocation(-1, -1);	
			// Update lobby widgets
			SgLobbyData.Event_OnPlayerLocationUpdated.Invoke();
		}
	}
	
	private void Event_OnLobbyStarted()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(WaitForServerPopup);
	}
	
	private void Event_OnGameServerIsReadied(ref SgNetServerDataServerReadyResponse resultValue)
	{	
		g_Game.ConnectFromJoin(resultValue.GetServerIp() , resultValue.GetServerPort());
	}
}