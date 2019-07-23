class SgTeam
{
	protected		int						m_TeamID;
	protected 		string					m_Name;	
	protected		int						m_TeamColour;
	protected		bool					m_IsCasterTeam;
	protected ref 	array<string>			m_PlayerUIDs;
	protected ref 	array<ref SgPlayer>		m_Players;
	
	//==================================
	// SgTeam
	//==================================
	void SgTeam( int id )
	{
		m_TeamID		= id;
		m_PlayerUIDs	= new array<string>;
		m_Players		= new array<ref SgPlayer>;
		m_Name			= "";
		m_TeamColour	= 0;
	}
	
	//==================================
	// GetTeamID
	//==================================
	int GetTeamID()
	{
		return m_TeamID;
	}
	
	//==================================
	// SetName
	//==================================
	void SetName(string name)
	{
		m_Name = name;
	}
	
	//==================================
	// GetName
	//==================================
	string GetName()
	{
		return m_Name;
	}
	
	//==================================
	// SetColour
	//==================================
	void SetColour( int colour )
	{
		m_TeamColour = colour;
	}
	
	//==================================
	// GetColour
	//==================================
	int GetColour()
	{
		return m_TeamColour;
	}
	
	//==================================
	// GetTeammatesUsersID
	//==================================
	array<string> GetTeammatesUsersID()
	{
		ref array<string> teammates = new array<string>;
		
		foreach( string p_uid : m_PlayerUIDs )
		{
			SgPlayer sg_player = SgSManagerPlayers.GetSgPlayerByPlayerUID( p_uid );
			teammates.Insert( sg_player.GetPlayerUID() );
		}
		
		return teammates;
	}
	
	//==================================
	// PlayerInsert
	//==================================
	void PlayerInsert( SgPlayer sg_player )
	{
		m_PlayerUIDs.Insert( sg_player.GetPlayerUID() );
		m_Players.Insert( sg_player );
	}
	
	//==================================
	// GetPlayerUIDs
	//==================================
	array<string> GetPlayerUIDs()
	{
		return m_PlayerUIDs;
	}
	
	//==================================
	// GetPlayers
	//==================================
	array<ref SgPlayer> GetPlayers()
	{
		return m_Players;
	}
	
	//==================================
	// CollarTurnOff
	//==================================
	void CollarDamageBlock(bool block)
	{		
		for ( int i = 0; i < m_Players.Count(); ++i )
		{
			SgPlayer player = m_Players[i];
							
			if ( player && player.IsAlive() )
			{
				player.GetSG_Collar().SetDamageBlock( block );
			}
		}		
	}
	
	//==================================
	// IsAlive
	//==================================
	bool IsAlive()
	{
		for ( int i = 0; i < m_Players.Count(); ++i )
		{
			SgPlayer player = m_Players[i];
							
			if ( player && player.IsAlive() )
			{
				return true;
			}
		}
		
		return false;
	}
	
	//==================================
	// GetTeamSlotBySgPlayer
	//==================================
	int GetTeamSlotBySgPlayer(SgPlayer sg_player)
	{
		return m_Players.Find( sg_player );
	}
	
	//==================================
	// GetTeamPlayers
	//==================================
	array<string> GetTeamPlayers()
	{
		ref array<string> teammates = new array<string>;
		
		foreach( SgPlayer sg_player: m_Players )
		{
			teammates.Insert( sg_player.GetPlayerUID() );
		}
		return teammates;
	}
	
	//==================================
	// OnTeamPlayerDied
	//==================================
	bool CanPlayerGoUnconscious()
	{
		int disabledPlayersCount = 0;
		foreach( SgPlayer sg_player: m_Players )
		{
			if ( sg_player.GetPlayerBase().IsUnconscious() || sg_player.IsAlive() == false )
			{
				disabledPlayersCount++;
			}
		}
		
		if ( m_Players.Count() - disabledPlayersCount <= 1 )
		{
			return false;
		}
		
		return true;
	}
	
	//==================================
	// OnTeamPlayerDied
	//==================================
	void OnTeamPlayerDied(PlayerBase player)
	{
		if ( CanPlayerGoUnconscious() )
		{
			return;
		}
		
		foreach( SgPlayer sg_player: m_Players )
		{
			if ( sg_player.GetPlayerBase().IsUnconscious() )
			{
				sg_player.GetPlayerBase().SetHealth("GlobalHealth", "Health", 0);
			}
		}
	}
}