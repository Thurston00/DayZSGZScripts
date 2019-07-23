enum SgNetworkServiceMethod
{
	// Common Calls
	GET_USER_ID,
	
	// Client Menu Only Calls
	CREATE_CUSTOM_MATCH,
	JOIN_CUSTOM_GAME,
	SET_SLOT,
	JOIN_TEAM,
	GET_LIST_OF_CUSTOM_LOBBIES,
	UN_JOIN_TEAM,
	PLAYER_READY,
	LEAVE_LOBBY,
	DELETE_LOBBY,
	CUSTOM_GAME_PLAY_BUTTON,
	
	// Server Only Calls
	GAME_SERVER_GET_MATCH_INFO,
	GAME_SERVER_IS_READY,
	GAME_SERVER_GAME_FINISHED,
	GAME_SERVER_MATCH_RECORD
}

class SgSNetworkServiceWrapper
{
	protected static SgNetworkService service;
	
	protected static string TryToExecuteNetworkCallWithStringResponse( SgNetworkServiceMethod methodToExecute, Class param1 = null )
	{
		if ( service != null )
		{
			switch (methodToExecute)
			{
				// Common Calls
				case SgNetworkServiceMethod.GET_USER_ID:     				return service.GetUserUID();
			}
		}
		
		return "";
	}
	
	protected static SgEResult TryToExecuteNetworkCall( SgNetworkServiceMethod methodToExecute, Class param1 = null )
	{
		if ( service == null )
		{
			service = SgNetworkService.GetService();
		}
		
		if ( service != null )
		{
			switch (methodToExecute)
			{				
				// Client Menu Only Calls
				case SgNetworkServiceMethod.CREATE_CUSTOM_MATCH:     		return service.CreateLobby(SgNetDataLobbyCreateRequest.Cast(param1));
				case SgNetworkServiceMethod.JOIN_CUSTOM_GAME:     			return service.JoinLobby(SgNetDataLobbyJoinRequest.Cast(param1));
				case SgNetworkServiceMethod.SET_SLOT:     					return service.SetLobbySlot(SgNetDataLobbySlotSetRequest.Cast(param1));
				case SgNetworkServiceMethod.JOIN_TEAM:     					return service.JoinTeam(SgNetDataTeamJoinRequest.Cast(param1));
				case SgNetworkServiceMethod.GET_LIST_OF_CUSTOM_LOBBIES:     return service.LoadLobbyList(SgNetDataLobbyListLoadRequest.Cast(param1));
				case SgNetworkServiceMethod.UN_JOIN_TEAM:                   return service.LeaveTeam(SgNetDataTeamLeaveRequest.Cast(param1));
				case SgNetworkServiceMethod.PLAYER_READY:                   return service.ReadyLobbyPlayer(SgNetDataPlayerReadyRequest.Cast(param1));
				case SgNetworkServiceMethod.LEAVE_LOBBY:                    return service.LeaveLobby(SgNetDataLobbyLeaveRequest.Cast(param1));
				case SgNetworkServiceMethod.DELETE_LOBBY:                   return service.DeleteLobby(SgNetDataLobbyDeleteRequest.Cast(param1));
				case SgNetworkServiceMethod.CUSTOM_GAME_PLAY_BUTTON:        return service.StartLobbyGame(SgNetDataLobbyGameStartRequest.Cast(param1));
				
				// Server Only Calls
				case SgNetworkServiceMethod.GAME_SERVER_GET_MATCH_INFO: 	return service.GameServerLoadMatchInfo();
				case SgNetworkServiceMethod.GAME_SERVER_IS_READY:			return service.GameServerReadyServer();
				case SgNetworkServiceMethod.GAME_SERVER_GAME_FINISHED:      return service.GameServerFinishGame(SgNetServerDataGameFinishRequest.Cast(param1));
				//case SgNetworkServiceMethod.GAME_SERVER_MATCH_RECORD:  		return service.GameServerRecordMatch(SgNetServerDataMatchRecordRequest.Cast(param1));
			}
		}
		
		return SgEResult.ERROR;
	}
	
	// Common Calls
	static string GetUserUID()																{ return TryToExecuteNetworkCallWithStringResponse( SgNetworkServiceMethod.GET_USER_ID ); }

	// Client Menu Only Calls
	static SgEResult CreateCustomMatch(SgNetDataLobbyCreateRequest inputValue)				{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.CREATE_CUSTOM_MATCH, inputValue ); }
	static SgEResult JoinCustomGame(SgNetDataLobbyJoinRequest inputValue)					{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.JOIN_CUSTOM_GAME, inputValue ); }
	static SgEResult SetSlot(SgNetDataLobbySlotSetRequest inputValue)						{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.SET_SLOT, inputValue ); }
	static SgEResult JoinTeam(SgNetDataTeamJoinRequest inputValue)							{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.JOIN_TEAM, inputValue ); }
	static SgEResult GetListOfCustomLobbies(SgNetDataLobbyListLoadRequest inputValue)		{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.GET_LIST_OF_CUSTOM_LOBBIES, inputValue ); }
	static SgEResult UnJoinTeam(SgNetDataTeamLeaveRequest inputValue)						{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.UN_JOIN_TEAM, inputValue ); }
	static SgEResult PlayerReady(SgNetDataPlayerReadyRequest inputValue)					{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.PLAYER_READY, inputValue ); }
	static SgEResult LeaveLobby(SgNetDataLobbyLeaveRequest inputValue)						{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.LEAVE_LOBBY, inputValue ); }
	static SgEResult DeleteLobby(SgNetDataLobbyDeleteRequest inputValue) 					{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.DELETE_LOBBY, inputValue ); }
	static SgEResult CustomGamePlayButton(SgNetDataLobbyGameStartRequest inputValue) 		{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.CUSTOM_GAME_PLAY_BUTTON, inputValue ); }
	
	// Server Only Calls
	static SgEResult GameServerGetMatchInfo() 												{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.GAME_SERVER_GET_MATCH_INFO ); }
	static SgEResult GameServerIsReady() 													{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.GAME_SERVER_IS_READY ); }
	static SgEResult GameServerGameFinished(SgNetServerDataGameFinishRequest inputValue) 	{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.GAME_SERVER_GAME_FINISHED, inputValue ); }
	//static SgEResult GameServerMatchRecord(SgNetServerDataMatchRecordRequest inputValue)	{ return TryToExecuteNetworkCall( SgNetworkServiceMethod.GAME_SERVER_MATCH_RECORD, inputValue ); }
}