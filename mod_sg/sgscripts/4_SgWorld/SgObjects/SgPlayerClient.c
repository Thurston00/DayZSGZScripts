class SgPlayerClient
{
	protected string				m_PlayerUID;
	protected string				m_UserName;
	protected int					m_TeamID;
	protected PlayerBase			m_PlayerBase;
	protected bool					m_IsAlive;
		
	protected EntityAI 				m_Helmet;
	protected EntityAI				m_Vest;
	private ref ScriptInvoker 		Event_OnHelmetChanged;
	private ref ScriptInvoker 		Event_OnVestChanged; 
	
	//==================================
	// SgPlayer Constructor
	//==================================
	void SgPlayerClient( string player_uid, string player_name, int team_id)
	{	
		PlayerBase player = SgSClientGame.GetPlayerBaseByPlayerUID(player_uid);
		
		m_PlayerUID		= player_uid;
		m_UserName		= player_name;
		m_TeamID		= team_id;
		
		m_IsAlive 		= true;
	
		SetPlayerBase(player);
		RegisterEventsForDebug();
	}
	
	//==================================
	// GetPlayerUID
	//==================================
	string GetPlayerUID()
	{
		return m_PlayerUID;
	}
	
	//==================================
	// GetUserName
	//==================================
	string GetUserName()
	{
		return m_UserName;
	}
	
	//===================================
	// GetPlayerBase
	//===================================
	PlayerBase GetPlayerBase()
	{
		if (!m_PlayerBase)
		{
			SetPlayerBase(SgSClientGame.GetPlayerBaseByPlayerUID(m_PlayerUID));
		}
		return m_PlayerBase;
	}
	
	void SetPlayerBase(PlayerBase player)
	{	
		m_PlayerBase = player;
		
		if (m_PlayerBase)
		{
			m_PlayerBase.GetOnItemAttached().Insert(OnItemEquipped);
			m_PlayerBase.GetOnItemDetached().Insert(OnItemRemoved);
		}
	}
	
	//===================================
	// GetTeamID
	//===================================
	int GetTeamID()
	{
		return m_TeamID;
	}
	
	//===================================
	// GetPosition
	//===================================
	vector GetPosition()
	{		
		return GetPlayerBase().GetPosition();
	}
	
	//===================================
	// GetPosition
	//===================================
	vector GetDirection()
	{
		return GetPlayerBase().GetDirection();
	}
	
	//==================================
	// GetHealth
	//==================================
	float GetHealth()
	{
		return ( 1 - GetPlayerBase().GetDamage() );
	}
		
	//==================================
	// IsAlive
	//==================================
	bool IsAlive()
	{
		return m_IsAlive;
	}
	
	//==================================
	// GetVirtualHud
	//==================================
	VirtualHud GetVirtualHud()
	{
		if ( GetPlayerBase() )
		{
			return GetPlayerBase().GetVirtualHud();
		}
		
		return null;
	}
	
	//==================================
	// GetHumanInventory
	//==================================
	HumanInventory GetHumanInventory()
	{
		if ( GetPlayerBase() )
		{
			return GetPlayerBase().GetHumanInventory();
		}
		
		return null;
	}
	
	//==================================
	// GetTeamColor
	//==================================
	int GetTeamColor()
	{
		return Colors.GetTeamColor( GetTeamID() );
	}
	
	//==================================
	// Died
	//==================================
	void Died()
	{
		m_IsAlive = false;
	}
	
	//==================================
	// Update
	//==================================
	void Update()
	{
		PlayerBase player1 = GetPlayerBase();
		
		/*
		if ( player1 )
		{
			vector pos1 = player1.GetPosition();
			vector pos2 = GetGame().GetPlayer().GetPosition();
			
			float dist = vector.Distance( pos1, pos2 );
			
			Print("PlayerDistance: "+ dist);
		}
		else
		{
			Print("PlayerDistance: OUT OF REACH");
		}
		*/
	}
	
	private void OnItemRemoved(EntityAI item, string slot_name)
	{		
		switch (slot_name)
		{	
			case "Headgear":
			{
				SetEquippedHelmet(null);
				break;
			}
			case "Vest":
			{
				SetEquippedVest(null);
				break;
			}
		}
	}
	private void OnItemEquipped(EntityAI item, string slot_name)
	{
		// Find Vest or Headgear items
		switch (slot_name)
		{
			case "Vest":
			{
				SetEquippedVest(item);
				break;
			}
			case "Headgear":
			{	
				SetEquippedHelmet(item);
				break;
			}	
		}		
	}
	void SetEquippedVest(EntityAI vest)
	{
		m_Vest = vest;
		if (Event_OnVestChanged)
		{
			Event_OnVestChanged.Invoke(m_Vest);
		}
	}
	void SetEquippedHelmet(EntityAI helmet)
	{
		m_Helmet = helmet;
		
		if (Event_OnHelmetChanged)
		{
			Event_OnHelmetChanged.Invoke(m_Helmet);
		}
	}
	EntityAI GetEquippedVest()
	{
		return m_Vest;
	}	
	EntityAI GetEquippedHelmet()
	{
		return m_Helmet;
	}
	ScriptInvoker GetOnHelmetChangedEvent()
	{
		if (!Event_OnHelmetChanged)
		{
			Event_OnHelmetChanged = new ScriptInvoker()
		}
		return Event_OnHelmetChanged;
	}	
	ScriptInvoker GetOnVestChangedEvent()
	{
		if (!Event_OnVestChanged)
		{
			Event_OnVestChanged = new ScriptInvoker()
		}
		return Event_OnVestChanged;
	}
	
	
	
	
	
	
	
	
	
	
	
	// DEBUG 
	private void RegisterEventsForDebug()
	{
		this.GetOnHelmetChangedEvent().Insert(Event_OnHelmetChangedDebug);
		this.GetOnVestChangedEvent().Insert(Event_OnVestChangedDebug);
	}
	private void Event_OnHelmetChangedDebug(EntityAI item)			// 1.
	{
		string item_name = "EMPTY"; 
		if (item)
		{
			item_name = item.GetDisplayName();
		}
		Print(string.Format("%1: %2 has been invoked. Param1: %3", ClassName(), "Event_OnHelmetChanged", item_name ));
	}
	private void Event_OnVestChangedDebug(EntityAI item)			// 2.
	{	
		string item_name = "EMPTY"; 
		if (item)
		{
			item_name = item.GetDisplayName();
		}
		Print(string.Format("%1: %2 has been invoked. Param1: %3", ClassName(), "Event_OnVestChanged", item_name));
	}
}