class SgSRpcEvent
{
	// Server
	static void SendSyncEvent( ESgSyncEvent sync_event_type, ref SgSyncData data = null, bool guaranteed = true, PlayerIdentity player_target = null )
	{
		ref Param2<int, ref SgSyncData> rpc_data = new ref Param2<int, ref SgSyncData>( sync_event_type, data );
		
		GetGame().RPCSingleParam( null, ESgRPCs.SyncEvent, rpc_data, guaranteed, player_target );
	}
	
	// Client
	static void OnReceivedSyncEvent( ParamsReadContext ctx, Object target = null )
	{		
		ref Param2<int, ref SgSyncData> event_data = new ref Param2<int, ref SgSyncData>( -1, NULL );
		
		if ( ctx.Read(event_data) )
		{
			SgSSyncEvents.OnSyncEvent( event_data.param1, event_data.param2, target );
		}
	}	
}