class SgCaster
{
	protected string				m_PlayerUID;
	protected string				m_UserName;
	protected int					m_TeamID;
	protected PlayerBase			m_PlayerBase;
	protected PlayerIdentity		m_Identity;
	
	//==================================
	// SgPlayer Constructor
	//==================================
	void SgCaster( PlayerIdentity identity )
	{	
		m_PlayerUID	= identity.GetId();
		m_UserName		= identity.GetName();
		m_Identity		= identity;
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
	// GetIdentity
	//===================================
	PlayerIdentity GetIdentity()
	{
		return m_Identity;
	}
	
	//===================================
	// GetTeam
	//===================================
	SgTeam GetTeam()
	{
		return SgSManagerPlayers.GetTeamByID(m_TeamID);
	}

	//==================================
	// LockMovement
	//==================================
	void LockMovement(bool lock)
	{
		if ( m_PlayerBase )
		{
			m_PlayerBase.LockMovement(lock);
		}
	}
}