modded class DispatcherCaller
{	
	//====================================
	// SgRpcCall
	//====================================
	private void SgRpcCall( Param params )
	{
		ref Param4<ref PlayerIdentity, Object, int, ref Serializer> data = Param4<ref PlayerIdentity, Object, int, ref Serializer>.Cast( params );
		if( data )
		{
			int rpc_type = data.param3;
			PlayerIdentity sender = data.param1;
			ParamsReadContext ctx = data.param4;
			if ( GetSgGame().SgIsClientMP() )
			{
				if ( rpc_type == ESgRPCs.SyncEvent )
				{
					SgSRpcEvent.OnReceivedSyncEvent( ctx, data.param2 );
				}
				else
				{
					SgPluginGameLog.GetInstance().OnRPC(rpc_type, ctx);
				}
				
			}
			else if ( GetSgGame().SgIsServerMP() && rpc_type == ESgRPCs.Action )
			{
				SgSRpcAction.OnAction_Received( sender, ctx );
			}
		}
		
	}

	override void SceneEditorCommand(Param params)
	{
		/*
		UIScriptedMenu ui_menu = GetGame().GetUIManager().GetMenu();
		if ( ui_menu && ui_menu.GetID() == MENU_SG_SCENE_EDITOR )
		{
			SgSceneEditorMenu editor_menu = SgSceneEditorMenu.Cast( ui_menu );
			editor_menu.SceneEditorCommand( params );
		}*/
	}
	
	//====================================
	// CallMethod
	//====================================
	override Param CallMethod( CallID call_id, Param params )
	{		
		super.CallMethod( call_id, params );
			
		switch( call_id )
		{
			case CALL_ID_SG_RPC_CALL:
				SgRpcCall( params );
				break;
		}
		return null;
	}
}
