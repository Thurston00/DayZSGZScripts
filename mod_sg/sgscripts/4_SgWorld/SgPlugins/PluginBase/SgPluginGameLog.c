class SgPluginGameLog extends PluginBase
{
	//==================================
	// GetInstance
	//==================================
	static SgPluginGameLog GetInstance()
	{
		return SgPluginGameLog.Cast( GetPlugin( SgPluginGameLog ) );
	}
	
	//==========================================
	// SendLog
	//==========================================
	void SendLog(string msg)
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
		{
			msg = "Server: "+ msg;
			
			ref Param1<string> p1 = new Param1<string>(msg);
			
			//GetGame().RPCSingleParam( null, RPC_SG_GAME_LOG, p1, true, null );
		}
		else
		{
			msg = "Local: "+ msg;
			
			PrintGameLog(msg);
		}
	}
			
	//===========================================
	// OnRPC
	//===========================================
	void OnRPC(int rpc_type, ParamsReadContext ctx)
	{
		switch(rpc_type)
		{
			case RPC_SG_GAME_LOG:	
			{				
				ref Param1<string> game_log = new Param1<string>("");
								
				if ( ctx.Read( game_log ) )
				{
					PrintGameLog(game_log.param1);
				}
				
				break;
			}
		}
	}
	
	//===========================================
	// PrintGameLog
	//===========================================
	protected void PrintGameLog(string msg)
	{			
		ref Param1<string> p2 = new Param1<string>( msg );
		// SG_TODO: Do Something with the log data.
	}
}