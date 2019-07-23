class SgPlayer
{
	protected string				m_PlayerUID;
	protected int					m_LowBits;
	protected int					m_HighBits;
	protected string				m_UserName;
	protected int					m_TeamID;
	protected PlayerBase			m_PlayerBase;
	protected ref SG_Collar			m_Collar;
	
	//SG_TODO: termporary solution for vertical slice
	protected bool		 			m_IsShell = true;

	//==================================
	// SgPlayer Constructor
	//==================================
	void SgPlayer( PlayerBase player, string player_uid, string steam_name )
	{
		m_PlayerBase	= player;
		m_PlayerUID		= player_uid;
		m_UserName		= steam_name;
		
		m_PlayerBase.SetLeaveAreaTime( -1 );
		m_PlayerBase.GetNetworkID(m_LowBits,m_HighBits );
		
		// Init Collar logic
		m_Collar = new SG_Collar( this );
		
		SgSManagerEventsServer.Event_OnSgPlayerDied.Insert( Event_OnSgPlayerDied );		
	}
	
	//==================================
	// PostInit
	//==================================
	void PostInit()
	{	
		PlayerIdentity identity = m_PlayerBase.GetIdentity();
		m_IsShell				= false;

		m_PlayerBase.SetCanBeDestroyed(false);
	}
	
	//==================================
	// GetPlayerUID
	//==================================
	string GetPlayerUID()
	{
		return m_PlayerUID;
	}
	
	//==================================
	// GetPlayerLowBits
	//==================================
	int GetPlayerLowBits()
	{
		return m_LowBits;
	}
	
	//==================================
	// GetPlayerHighBits
	//==================================
	int GetPlayerHighBits()
	{
		return m_HighBits;
	}
	
	//===================================
	// GetPlayerBase
	//===================================
	PlayerBase GetPlayerBase()
	{
		return m_PlayerBase;
	}
	
	//==================================
	// GetUserName
	//==================================
	string GetUserName()
	{
		return m_UserName;
	}
	
	//===================================
	// GetIdentity
	//===================================
	PlayerIdentity GetIdentity()
	{
		return m_PlayerBase.GetIdentity();
	}
	
	//===================================
	// GetIsShell
	//===================================
	bool GetIsShell()
	{
		return m_IsShell;
	}
	
	//===================================
	// GetPosition
	//===================================
	vector GetPosition()
	{
		return GetPlayerBase().GetPosition();
	}
	
	//===================================
	// GetDirection
	//===================================
	vector GetDirection()
	{
		return GetPlayerBase().GetDirection();
	}
	
	//===================================
	// SetTeamID
	//===================================
	void SetTeamID( int team_id )
	{
		m_TeamID = team_id;
	}
	
	//===================================
	// GetTeamID
	//===================================
	int GetTeamID()
	{
		return m_TeamID;
	}
	
	//===================================
	// GetTeam
	//===================================
	SgTeam GetTeam()
	{
		return SgSManagerPlayers.GetTeamByID( m_TeamID );
	}
	
	//===================================
	// GetCollar
	//===================================
	SG_Collar GetSG_Collar()
	{
		return m_Collar;
	}

	//==================================
	// IsAlive
	//==================================
	bool IsAlive()
	{
		if ( m_PlayerBase )
		{
			return m_PlayerBase.IsAlive();
		}
		
		return false;
	}
	
	//==================================
	// SetPosition
	//==================================
	void SetPosition(vector pos)
	{
		m_PlayerBase.SetPosition( pos );
	}
	
	//==================================
	// SetDirection
	//==================================
	void SetDirection(vector dir)
	{
		m_PlayerBase.SetDirection( dir );
	}
	
	//==================================
	// SetGodMod
	//==================================
	void SetGodMod(bool god_mod)
	{
		m_PlayerBase.SetGodMod( god_mod );
	}
	
	//==================================
	// LockMovement
	//==================================
	void LockMovement(bool lock)
	{
		if ( m_PlayerBase )
		{
			m_PlayerBase.LockMovement(lock);
			
			SgSManagerEventsServer.Event_OnSgPlayerMoveLockChanged(this, lock);
		}
	}
	
	//==================================
	// Event_OnSgPlayerDied
	//==================================
	void Event_OnSgPlayerDied( SgPlayer sg_player, SgDeathDetails details )
	{
		if ( sg_player.GetPlayerUID() == GetPlayerUID() )
		{
			if ( SgSManagerPlayers.GetPlayersAliveCount() > 0 )
			{
				DeadcamStart();
			}
		}
	}
	
	//==================================
	// DeadcamStart
	//==================================
	protected void DeadcamStart()
	{
		if ( GetIdentity() )
		{
			GetGame().SelectSpectator( GetIdentity(), "SgDeadcam", GetPosition() );
		}
	}
}