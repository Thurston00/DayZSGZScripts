// ---------------------
modded class DayZGame
{
	protected ref SgSWEH	m_CurrentMenu;
	protected int			m_LoadedPlaygroundID;
	protected string		m_LoadedMissionName;
	protected bool			m_IsServerRecovery;
	protected bool 			m_ClientIsLoaded;
	
	//===================================
	// Constructor
	//===================================
	void DayZGame()
	{
		m_LoadedPlaygroundID = -1;
		
		string tmp;
		if ( CommandlineGetParam("sgPgId", tmp) )
		{
			PrintString("sgPgId => "+tmp);
			m_LoadedPlaygroundID = tmp.ToInt();
		}
	}
	
	//===================================
	// Destructor
	//===================================
	void ~DayZGame()
	{
		g_Game = NULL;
	}
	
	//===================================
	// SgGetMenu
	//===================================
	void SgSetMenu( SgSWEH menu )
	{
		m_CurrentMenu = menu;
	}
	
	//===================================
	// SgGetMenu
	//===================================
	SgSWEH SgGetMenu()
	{
		return m_CurrentMenu;
	}
	
	//===================================
	// SgGetServerTimeFormated
	//===================================
	string SgGetServerTimeFormated()
	{
		int time_mil = GetGame().GetTime();
		int time_sec = Math.Round( time_mil * 0.001 );
		int time_min = Math.Floor( time_sec / 60 );
		time_sec = time_sec % 60;
		
		return "Server Time: "+ time_min +"min "+ time_sec +"sec";
	}
	
	//===================================
	// SgIsServerMP
	//===================================
	bool SgIsServerMP()
	{
		if ( IsMultiplayer() && IsServer() )
		{
			return true;
		}
		
		return false;
	}
	
	//===================================
	// SgIsClientMP
	//===================================
	bool SgIsClientMP()
	{
		if ( IsMultiplayer() && IsClient() )
		{
			return true;
		}
		
		return false;
	}
	
	//===================================
	// SgIsServerLocal
	//===================================
	bool SgIsServerLocal()
	{
		if ( !GetGame().IsMultiplayer() && GetGame().IsServer() )
		{
			return true;
		}
		
		return false;
	}
	
	//===================================
	// SetPlaygroundID
	//===================================
	void SetPlaygroundID( int pg_id )
	{
		m_LoadedPlaygroundID = pg_id;
	}
	
	//===================================
	// GetPlaygroundID
	//===================================
	int GetPlaygroundID()
	{
		return m_LoadedPlaygroundID;
	}
	
	//===================================
	// SetLoadedMission
	//===================================
	void SetLoadedMission( string mission )
	{
		m_LoadedMissionName = mission;
	}
	
	//===================================
	// GetLoadedMission
	//===================================
	string GetLoadedMission()
	{
		return m_LoadedMissionName;
	}
	
	//===================================
	// GetClientIsLoaded
	//===================================
	bool GetClientIsLoaded()
	{
		return m_ClientIsLoaded;
	}
	
	//===================================
	// OnRPC
	//===================================
	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC( sender, target, rpc_type, ctx );
		
		ref Param4<ref PlayerIdentity, Object, int, ref ParamsReadContext> data;
		data = new Param4<ref PlayerIdentity, Object, int, ref ParamsReadContext>( sender, target, rpc_type, ctx );
		CallMethod( CALL_ID_SG_RPC_CALL, data );
	}
	
	// ------------------------------------------------------------
	void LoadingHide(bool force = false)
	{
		super.LoadingHide(force);
		m_ClientIsLoaded = true;
	}
};

DayZGame GetSgGame()
{
	return g_Game;
}