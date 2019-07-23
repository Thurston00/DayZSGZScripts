class SgLobbyData
{
	// STATIC
	private static string _ClientId = "";

	// Prop
	private string 			m_LobbyID;
	private string 			m_RoomName;
	private bool 			m_Password;
	private SgEPlaygrounds	m_PlaygroundID;
	private SgETeamSize		m_TeamSizeID;
	private int 			m_MaxPlayers;
	private string 			m_HostID;
	private ref array<ref SgNetDataLobbyPlayer>	m_LobbyPlayers;	
	// Events
	static ref ScriptInvoker Event_OnLobbyDataUpdated 		= new ScriptInvoker();
	static ref ScriptInvoker Event_OnPlayerLocationUpdated 	= new ScriptInvoker();
	
	// Constructor
	void SgLobbyData(string lobby_id, string room_name, bool password, SgEPlaygrounds pg_id, SgETeamSize team_size, int max_players, string host_id, array<ref SgNetDataLobbyPlayer> lobby_players)
	{		
		m_LobbyID 		= lobby_id;
		m_RoomName		= room_name;
		m_Password		= password;
		m_PlaygroundID	= pg_id;
		m_TeamSizeID	= team_size;
		m_MaxPlayers	= max_players;
		m_HostID 		= host_id;
		m_LobbyPlayers	= lobby_players;	

	}
	
	// ----------------------------------
	// GETTERS
	
	string GetLobbyID()
	{
		return m_LobbyID;
	}
	string GetRoomName()
	{
		return m_RoomName;
	}
	bool GetPassword()
	{
		return m_Password;
	}
	SgCPlayground GetPlayground()
	{
		return SgCPlayground.FindPlaygroundById(m_PlaygroundID);
	}	
	SgCTeamMode GetTeamMode()
	{
		return SgCTeamMode.FindModeById(m_TeamSizeID);
	}
	int GetMaxPlayers()
	{
		return m_MaxPlayers;
	}	
	bool HasPassword()
	{
		return m_Password;
	}	
	array<ref SgNetDataLobbyPlayer> GetLobbyPlayers()
	{
		return m_LobbyPlayers;
	}
	int GetCurrentPlayersCount()
	{
		if(m_LobbyPlayers)
		{
			return m_LobbyPlayers.Count();
		}
		else 
		{
			return 0;
		}
	}	
	int GetTeamCount()
	{
		return m_MaxPlayers / GetTeamMode().GetSize();
	}	
	
	
	// ---------------------------
	// More complex getters
	
	string GetHostName()
	{	
		SgNetDataLobbyPlayer player = FindPlayerByID(m_HostID);
		
		if (player)
		{
			return player.GetSteamName();
		}
		return "";
	}	
	bool IsHost(SgNetDataLobbyPlayer player)
	{
		if (player.GetPlayerUID() == m_HostID)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}	
	bool AmIHost()
	{
		ref SgNetDataLobbyPlayer player = FindPlayerByID(GetClientUID());
		
		if (player)
		{		
			if (player.GetPlayerUID() == m_HostID)
			{
				return true;
			}
		}
		else 
		{
			SgDebug.Error("Client not found in the list", ClassName(), "AmIHost");
		}
		
		return false;
	}		
	bool AmIReady()
	{
		SgNetDataLobbyPlayer player = FindPlayerByID(GetClientUID());
		if(player)
		{
			return player.GetReadyCheck();
		}
		return false;
	}
	bool AmIAssigned()
	{
		
		SgNetDataLobbyPlayer player = FindPlayerByID(GetClientUID());
		if (player)
		{
			if( player.GetSlotId() != -1 )
			{
				return true;
			}
		}
		return false;
	}
	SgNetDataLobbyPlayer GetClientPlayerData()
	{
		return FindPlayerByID(GetClientUID());
	}
	
	SgNetDataLobbyPlayer FindPlayerByID(string uid)
	{
		foreach (SgNetDataLobbyPlayer player : m_LobbyPlayers)
		{
			if (player.GetPlayerUID() == uid)
			{
				return player;
			}
		}
		return null;
	}
	SgNetDataLobbyPlayer FindHost()
	{
		foreach ( SgNetDataLobbyPlayer player : m_LobbyPlayers)
		{
			if (player.GetPlayerUID() == m_HostID)
			{
				return player;
			}
		}
		return null;
	}
	
	static string GetClientUID()
	{
		if (_ClientId == "")
		{
			_ClientId = SgSNetworkServiceWrapper.GetUserUID();
		}
		return _ClientId;
	}
	
	// ------------------------------------
	
	void SetPlayerList(array<ref SgNetDataLobbyPlayer> player_list)
	{
		m_LobbyPlayers = player_list;
	}
	
	void SetHostID(string host_id)
	{
		m_HostID = host_id;
	}
	void RemovePlayerFromList(string player_uid)
	{
		for (int i = 0; i < m_LobbyPlayers.Count(); i++)
		{
			if (m_LobbyPlayers.Get(i).GetPlayerUID() == player_uid)
			{
				m_LobbyPlayers.Remove(i);
				return;
			}
		}
	}
}