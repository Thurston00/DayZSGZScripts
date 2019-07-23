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
	
	// send additional information to server (must be called)
	override ref array<ref Param> GetLoginData()
	{
		int top = -1;
		int bottom = -1;
		int shoes = -1;
		int skin = -1;
		
		if (demounit.Count() > 0)
		{
			top = demounit.Get(0);
			bottom = demounit.Get(1);
			shoes = demounit.Get(2);
			skin = demounit.Get(3);
		}
		
		ref array<ref Param> params = new array<ref Param>;
			
		ref Param topParam = new Param1<int>(top);
		params.Insert(topParam);
			
		ref Param bottomParam = new Param1<int>(bottom);
		params.Insert(bottomParam);

		ref Param shoesParam = new Param1<int>(shoes);
		params.Insert(shoesParam);
		
		ref Param skinParam = new Param1<int>(skin);
		params.Insert(skinParam);
		
		return params;
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