modded class MissionServer
{
	void MissionServer()
	{
		Print("MissionServer: Constructor ");
		SetDispatcher(new DispatcherCaller);
	}
		
	// SG_TODO: Would be nice to clear cached data
	/*void ~MissionServer()
+	{
+		Print("MissionServer: Destructor ");
+		GetGame().ClearReconnectCache();
+	}*/
	
	override void OnInit()
	{
		super.OnInit();
		
		Print("SgMissionServer: OnInit");
		
		if ( GetSgGame().SgIsServerMP() )
		{
			int pg_id = GetSgGame().GetPlaygroundID();
			SgPluginGameServer.GetInstance().GameInit( pg_id );
		}
	}
	
	override void OnMissionStart()
	{
		super.OnMissionStart();
		
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(On1SecondAfterMissionStart, 1000);
	}
	
	void On1SecondAfterMissionStart()
	{
		GetGame().GetWorld().SetDate(1990, 6, 24, 17, 30); // ideal time for Severograd because the sun is behind players most of the time, not in front of them. Also, the moon is nicely visible.
	}
	
	// Player connected
	override void OnClientPrepareEvent ( PlayerIdentity identity, out bool useDB, out vector pos, out float yaw )
	{
		super.OnClientPrepareEvent(identity, useDB, pos, yaw);
		
		// Set Preload Position
		SgLocation start_location = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PhaseStart );
		pos = start_location.GetPosition();
		
		Print("[Server Event]["+ GetSgGame().SgGetServerTimeFormated() +"]: OnPreloadEvent (Loading start): "+ identity.GetId() +" "+ SgPluginGameServer.GetGameTimeFormated() +" -> "+ SgSManagerPlayers.GetPlayersStateFormated() );
	}
		
	// Player connected
	override PlayerBase OnClientNewEvent( PlayerIdentity identity, vector pos, ParamsReadContext ctx )
	{
		Print("[Server Event]["+ GetSgGame().SgGetServerTimeFormated() +"]: OnClientNewEvent (Loading finished): "+ identity.GetId() +" "+ SgPluginGameServer.GetGameTimeFormated() +" -> "+ SgSManagerPlayers.GetPlayersStateFormated() );
		
		int top = -1;
		int bottom = -1;
		int shoes = -1;
		int skin = -1;
		
		ProcessLoginData(ctx, top, bottom, shoes, skin);
		
		// Call Event Connected
		SgSManagerEventsServer.Event_OnUserConnected(identity);
				
		return null;
	}

	// Client disconnected from server
	override void OnClientDisconnectedEvent( PlayerIdentity identity, PlayerBase player, int queueTime, bool authFailed )
	{
		Print("[Server Event]["+ GetSgGame().SgGetServerTimeFormated() +"]: OnClientDisconnectedEvent: "+ identity.GetId() +" "+ SgPluginGameServer.GetGameTimeFormated() +" -> "+ SgSManagerPlayers.GetPlayersStateFormated() );
		
		GetGame().SendLogoutTime(player, 10);
		GetGame().AddToReconnectCache(identity);
	}
	
	protected void ClientReconnected(Param params)
	{
		Man player;
		PlayerIdentity identity;
		
		ClientReconnectEventParams reconnectParams;
		Class.CastTo(reconnectParams, params);				
		Class.CastTo(identity, reconnectParams.param1);
		Class.CastTo(player, reconnectParams.param2);
		
		GetGame().RemoveFromReconnectCache(identity.GetId());
		SgSManagerPlayers.OnUserReconnected(identity);
	}
	
	override void OnEvent(EventType eventTypeId, Param params)
	{
		super.OnEvent( eventTypeId, params);
		
		switch(eventTypeId)
		{
			case StartupEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> StartupEventTypeID");
				break;
			}
			case MPSessionStartEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> MPSessionStartEventTypeID");
				break;
			}
			case MPSessionEndEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> MPSessionEndEventTypeID");
				break;
			}
			case MPSessionFailEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> MPSessionFailEventTypeID");
				break;
			}
			case MPSessionPlayerReadyEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> MPSessionPlayerReadyEventTypeID");
				
				break;
			}
			case ClientNewEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> ClientNewEventTypeID");
				break;
			}
			case ClientRespawnEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> ClientRespawnEventTypeID");
				break;
			}
			case ClientReconnectEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> ClientReconnectEventTypeID");
				ClientReconnected(params);
				break;
			}
			case ClientReadyEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> ClientReadyEventTypeID");
				break;
			}
			case ClientDisconnectedEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> ClientDisconnectedEventTypeID");
				break;
			}
			case LogoutCancelEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> LogoutCancelEventTypeID");
				break;
			}
			case LoginTimeEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> LoginTimeEventTypeID");
				break;
			}
			case MPConnectionLostEventTypeID :
			{
				Print("["+ GetSgGame().SgGetServerTimeFormated() +"]==========> MPConnectionLostEventTypeID");
				break;
			}		
		}
	}
}