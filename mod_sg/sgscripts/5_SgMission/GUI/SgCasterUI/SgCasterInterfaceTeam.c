class SgCasterInterfaceTeam extends SgSWEH
{
	private		int											m_TeamID; 
	private ref map<string, ref SgCasterInterfacePlayer>	m_MembersData;
	//private		Widget										m_TeamWidget;
	private		TextWidget									m_TeamName;
	private		TextWidget									m_TeamPlayerCount;
	private		ButtonWidget								m_HideContent;
	private		int											m_PlayersAlive;
	
	private		bool										m_IsVisible;
	private		bool										m_Collapsed;
	
	void SgCasterInterfaceTeam( Widget root, SgCasterGuiTeam team )
	{
		m_MembersData	= new map<string, ref SgCasterInterfacePlayer>;
		
		m_TeamID		= team.GetTeamID();
		
		array<ref SgCasterGuiPlayer> players	= team.GetPlayers();
		// Initialize slots
		for( int i = 0; i < players.Count(); i++ )
		{
			SgCasterGuiPlayer player			= players.Get( i );
			SgPlayerClient player_object		= SgSClientGame.GetPlayerByUID( player.GetPlayerUID() );
			
			if( player_object )
			{
				ref SgCasterInterfacePlayer user	= new SgCasterInterfacePlayer( root, player, player_object, team.GetTeamColor() );
				m_MembersData.Insert( player.GetPlayerUID(), user );
				m_PlayersAlive++;
			}
		}
	}
	
	void ~SgCasterInterfaceTeam()
	{
		delete m_MembersData;
	}
	
	int GetPlayerCount()
	{
		return m_MembersData.Count();
	}
	
	void PlayerHealed( string player_uid, float heal )
	{
		SgCasterInterfacePlayer player = m_MembersData.Get( player_uid );
		if( player )
			player.PlayerHealed( heal );
	}
	
	void PlayerDamaged( string player_uid, float damage )
	{
		SgCasterInterfacePlayer player = m_MembersData.Get( player_uid );
		if( player )
			player.PlayerDamaged( damage );
	}
	
	void PlayerDied( string player_uid )
	{
		m_PlayersAlive--;
		m_TeamPlayerCount.SetText( m_PlayersAlive.ToString() + "/" + m_MembersData.Count() );
		SgCasterInterfacePlayer player = m_MembersData.Get( player_uid );
		if( player )
			player.PlayerDied();
	}
	
	override void Update()
	{
		foreach( string player_uid, SgCasterInterfacePlayer player : m_MembersData )
		{
			if( player )
				player.Update();
		}
	}
	
	override void Show()
	{
		m_IsVisible = true;
		foreach( string player_uid, SgCasterInterfacePlayer player : m_MembersData )
		{
			if( player )
			{
				player.Show();
				player.ShowFollower();
			}
		}
	}
	
	override void Hide()
	{
		m_IsVisible = false;
		foreach( string player_uid, SgCasterInterfacePlayer player : m_MembersData )
		{
			if( player )
			{
				player.Hide();
				player.HideFollower();
			}
		}
	}
	
	override void Toggle()
	{
		if( m_IsVisible )
		{
			m_IsVisible = false;
		}
		else
		{
			m_IsVisible = true;
		}
	}
	
	void TogglePlayers()
	{
		if( !m_Collapsed )
		{
			m_Collapsed = true;
		}
		else
		{
			m_Collapsed = false;
		}
		
		foreach( SgCasterInterfacePlayer player : m_MembersData )
		{
			player.Toggle();
		}
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if ( w == m_HideContent && button == MouseState.LEFT )
		{
			TogglePlayers();
		}
		return 0;
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 
	void ArrangePlayers()
	{
		bool switched = true;
		PlayerBase p1, p2;
		int i;
		Widget pWidget;
		switch( m_Plugin.m_SortingOption )
		{
			case SortingOption.CAST_ELO:
				while( switched && m_Players.Count() > 1 )
				{
					switched = false;
					for( i = 0; i < m_Players.Count() - 1; i++ )
					{
						p1 = m_Players.GetKey( i );
						p2 = m_Players.GetKey( i + 1 );
						if( p1.GetPlayerName() < p2.GetPlayerName() )
						{
							pWidget = m_Players.GetElement( i );
							pWidget.SetSort( pWidget.GetSort() + 1 );
						}
					}
				}
				break;
			case SortingOption.CAST_HEALTH:
				while( switched && m_Players.Count() > 1 )
				{
					switched = false;
					for( i = 0; i < m_Players.Count() - 1; i++ )
					{
						p1 = m_Players.GetKey( i );
						p2 = m_Players.GetKey( i + 1 );
						if( p1.GetDamage() < p2.GetDamage() )
						{
							pWidget = m_Players.GetElement( i );
							pWidget.SetSort( pWidget.GetSort() + 1 );
						}
					}
				}
				break;
			case SortingOption.CAST_NAME:
				while( switched && m_Players.Count() > 1 )
				{
					switched = false;
					for( i = 0; i < m_Players.Count() - 1; i++ )
					{
						p1 = m_Players.GetKey( i );
						p2 = m_Players.GetKey( i + 1 );
						if( p1.GetPlayerName() < p2.GetPlayerName() )
						{
							pWidget = m_Players.GetElement( i );
							pWidget.SetSort( pWidget.GetSort() + 1 );
						}
					}
				}
				break;
			default:
				break;
		}
	}
	*/
}