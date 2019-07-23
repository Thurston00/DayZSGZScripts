/*
Sync action from client to server
*/
class SgSRpcAction
{
	// Client
	static void SendAction( int action_category, int action_type, SgSyncData data, bool guaranteed )
	{
		ref Param3<int, int, ref SgSyncData> rpc_data = new ref Param3<int, int, ref SgSyncData>( action_category, action_type, data );
		GetGame().RPCSingleParam( null, ESgRPCs.Action, rpc_data, guaranteed );
	}
	
	// Server
	static void OnAction_Received( PlayerIdentity from_player, ParamsReadContext ctx )
	{
		ref Param3<int, int, ref SgSyncData> rpc_data = new ref Param3<int, int, ref SgSyncData>( -1, -1, NULL );
		if ( ctx.Read( rpc_data ) )
		{
			switch ( rpc_data.param1 )
			{
				case ESgActionCategory.WarmUp:
				{
					Error("Lobby was removed and WarmUp is not implemented yet..");
					break;
				}
				case ESgActionCategory.Game:
				{
					SgSSyncActionGame.OnReceived_Action( from_player, rpc_data.param2, rpc_data.param3 );
					break;
				}
			}
		}
	}
}