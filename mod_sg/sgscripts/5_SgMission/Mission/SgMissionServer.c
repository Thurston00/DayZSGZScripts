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
		
		Print("Server Event: "+ GetWorldTime() +" OnPreloadEvent");
	}
		
	// Player connected
	override PlayerBase OnClientNewEvent( PlayerIdentity identity, vector pos, ParamsReadContext ctx )
	{
		Print("Server Event: "+ GetWorldTime() +" OnClientNewEvent");
		
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
		Print("Server Event: "+ GetWorldTime() +" OnClientDisconnectedEvent");
		
		if ( SgPluginGameServer.GetInstance().GetGameState() == ESgGameState.WarmUp )
		{
			super.PlayerDisconnected( player, identity, identity.GetId() );
		}
		else
		{
			Print("Server: AddToReconnectCache");
			GetGame().SendLogoutTime(player, 10);
			GetGame().AddToReconnectCache(identity);
		}
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
				Print("["+ GetGame().GetTime() +"]==========> StartupEventTypeID");
				break;
			}
			case MPSessionStartEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> MPSessionStartEventTypeID");
				break;
			}
			case MPSessionEndEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> MPSessionEndEventTypeID");
				break;
			}
			case MPSessionFailEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> MPSessionFailEventTypeID");
				break;
			}
			case MPSessionPlayerReadyEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> MPSessionPlayerReadyEventTypeID");
				
				break;
			}
			case ClientNewEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> ClientNewEventTypeID");
				break;
			}
			case ClientRespawnEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> ClientRespawnEventTypeID");
				break;
			}
			case ClientReconnectEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> ClientReconnectEventTypeID");
				ClientReconnected(params);
				break;
			}
			case ClientReadyEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> ClientReadyEventTypeID");
				break;
			}
			case ClientDisconnectedEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> ClientDisconnectedEventTypeID");
				break;
			}
			case LogoutCancelEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> LogoutCancelEventTypeID");
				break;
			}
			case LoginTimeEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> LoginTimeEventTypeID");
				break;
			}
			case MPConnectionLostEventTypeID :
			{
				Print("["+ GetGame().GetTime() +"]==========> MPConnectionLostEventTypeID");
				break;
			}		
		}
	}
}