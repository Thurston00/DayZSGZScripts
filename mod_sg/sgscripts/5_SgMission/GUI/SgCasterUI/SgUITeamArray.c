 /*! \class SgUITeamArray
 *	\brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
class SgUITeamArray extends ScriptedWidgetEventHandler
{
		string					m_Team;
		Widget					m_ParentPanel;
		Widget					m_TeamRoot_Wide;
		Widget					m_TeamRoot;
		TextWidget				m_TeamName;
		TextWidget				m_TeamPlayerCount;
		Widget					m_TeamCollapse;
		Widget					m_TeamLabel;
		bool					m_Collapsed;
	ref map<SgPlayerClient, Widget>	m_Players;
	ref map<Widget, SgPlayerClient>	m_PlayersReverse;
		int						m_TeamColor;
		int						m_TeamColorSelected;
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void SgUITeamArray( string team, Widget parent )
	{
		m_Team				=	team;
		m_ParentPanel		=	parent;
		m_TeamRoot_Wide		=	GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_caster/leftpanel/teaminfo_wide.layout", m_ParentPanel );
		m_TeamRoot			=	GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_caster/leftpanel/teaminfo_short.layout", m_ParentPanel );
		m_TeamLabel			=	m_TeamRoot_Wide.FindWidget( "Label" );
		m_TeamName			=	TextWidget.Cast( m_TeamLabel.FindWidget( "Name" ) );
		m_TeamPlayerCount	=	TextWidget.Cast( m_TeamLabel.FindWidget( "Playercount" ) );
		m_TeamCollapse		=	m_TeamLabel.FindWidget( "Collapse" );
		m_Players			=	new map<SgPlayerClient, Widget>;
		m_PlayersReverse	=	new map<Widget, SgPlayerClient>;
		m_TeamRoot_Wide.SetHandler( this );
		UpdateTeam();
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void UpdateTeam()
	{
		ShowPlayerWidgets( !SgSClientCaster.IsTeamMinimized( m_Team ) );
		
		SgPlayerClient temp = m_Players.GetKey( 0 );
		if( temp )
		{
			m_TeamColor = temp.GetTeamColor();
			m_TeamColorSelected = m_TeamColor | 0xFD000000;
		}
			
		if( SgSClientCaster.GetSelectedPlayer() )
		{
			SgSClientCaster.SetSelectedPlayerWidget( ButtonWidget.Cast( m_Players.Get( SgSClientCaster.GetSelectedPlayer() ) ) );
			if( SgSClientCaster.GetSelectedPlayerWidget() )
			{
				SgSClientCaster.GetSelectedPlayerWidget().SetState( true );
				SgSClientCaster.GetSelectedPlayerWidget().FindAnyWidget( "Background" ).SetColor( m_TeamColorSelected );
			}
		}
		
		m_TeamName.SetText( m_Team );
		m_TeamRoot_Wide.SetName( m_Team );
		string total = "" + SgSClientGame.GetPlayersAliveCount() + "/" + m_Players.Count();
		m_TeamPlayerCount.SetText( total );
	}
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void UpdatePlayer( SgPlayerClient player )
	{
		Widget		root_w;
		Widget		root;
		Widget		content;
		TextWidget	healthText;
		TextWidget	weaponText;
		ImageWidget healthIcon;
		ImageWidget weaponIcon;
		TextWidget	nameText;

		if( m_Players.Contains( player ) )
		{
			root_w = m_Players.Get( player );
		}
		else
		{
			Widget parent = m_TeamRoot_Wide.FindAnyWidget( "Players" );
			
			root_w = GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_caster/leftpanel/playerinfo_wide.layout", m_TeamRoot_Wide.FindAnyWidget( "Players" ) );
			root = GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_caster/leftpanel/playerinfo_short.layout", m_TeamRoot.FindAnyWidget( "Players" ) );
			root_w.FindAnyWidget( "Background" ).SetColor( player.GetTeamColor() );
			
			m_Players.Insert( player, root_w );
			m_PlayersReverse.Insert( root_w, player );
		}
		
		content		=	root_w.FindAnyWidget( "Content" );
		nameText	=	TextWidget.Cast( content.FindAnyWidget( "Name" ).FindAnyWidget( "nameText" ) );
		nameText.SetText( player.GetUserName() );
		
		healthIcon	=	ImageWidget.Cast( content.FindAnyWidget( "Health" ).FindAnyWidget( "healthIcon" ) );
		healthIcon.SetColor( GetHealthColor( player ) );
		
		weaponIcon	=	ImageWidget.Cast( content.FindAnyWidget( "Weapon" ).FindAnyWidget( "weaponIcon" ) );
		//weaponIcon.LoadImageFile();
		if( SgSClientGame.ImAlive() )
		{
			content.FindAnyWidget( "Health" ).FindAnyWidget( "healthIcon" ).Show(false);
			content.FindAnyWidget( "Health" ).FindAnyWidget( "deathIcon" ).Show(true);
		}
	}
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void ArrangePlayers()
	{
		bool switched = true;
		SgPlayerClient p1, p2;
		int i;
		Widget pWidget;
		switch(SgSClientCaster.GetCasterSortingOption() )
		{
			case ESgCasterSortingOption.ELO:
				while( switched && m_Players.Count() > 1 )
				{
					switched = false;
					for( i = 0; i < m_Players.Count() - 1; i++ )
					{
						p1 = m_Players.GetKey( i );
						p2 = m_Players.GetKey( i + 1 );
						if( p1.GetUserName() < p2.GetUserName() )
						{
							pWidget = m_Players.GetElement( i );
							pWidget.SetSort( pWidget.GetSort() + 1 );
						}
					}
				}
				break;
			case ESgCasterSortingOption.HEALTH:
				while( switched && m_Players.Count() > 1 )
				{
					switched = false;
					for( i = 0; i < m_Players.Count() - 1; i++ )
					{
						p1 = m_Players.GetKey( i );
						p2 = m_Players.GetKey( i + 1 );
						if( p1.GetHealth() > p2.GetHealth() )
						{
							pWidget = m_Players.GetElement( i );
							pWidget.SetSort( pWidget.GetSort() + 1 );
						}
					}
				}
				break;
			case ESgCasterSortingOption.NAME:
				while( switched && m_Players.Count() > 1 )
				{
					switched = false;
					for( i = 0; i < m_Players.Count() - 1; i++ )
					{
						p1 = m_Players.GetKey( i );
						p2 = m_Players.GetKey( i + 1 );
						if( p1.GetUserName() < p2.GetUserName() )
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
	
	float GetAvgDamage()
	{
		float totaldamage;
		for( int i = 0; i < m_Players.Count(); i++ )
		{
			SgPlayerClient player = m_Players.GetKey( i );
			totaldamage += ( 1 - player.GetHealth() );
		}
		return totaldamage / m_Players.Count();
	}
	
	float GetAvgELO()
	{
		return 0;
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	int GetHealthColor( SgPlayerClient player )
	{
		//float currhealth = player.GetHealth( "", "" );
		//float maxhealth = player.GetMaxHealth( "", "" );
		//float healthpercent = currhealth / maxhealth;
		//int red = healthpercent * 255;
		//int green = ( 1 - healthpercent ) * 255;
		//return ARGB( 255, red, green, 0 );
	}
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void GetPlayerTuple( out SgPlayerClient player, out Widget widget )
	{
		if(player && !widget)
		{
			widget = m_Players.Get( player );
		}		
		else if (widget && !player)
		{
			player = m_PlayersReverse.Get( widget );
		}
	}	
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void ShowPlayerWidgets( bool show ) {
		Widget pwidget;
		pwidget = m_TeamCollapse.FindAnyWidget("Collapsed");
		pwidget.Show(!show);
		pwidget = m_TeamCollapse.FindAnyWidget("Opened");
		pwidget.Show(show);
		PlayerBase pbase;
		for( int i = 0; i < m_Players.Count();  i++ )
		{
			pwidget = m_Players.GetElement( i );
			pwidget.Show( show );
		}
		ArrangePlayers();
	}
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	override int OnDoubleClick( Widget w, int x, int y, int button )
	{
		if ( m_PlayersReverse.Get( w ) )
		{
			if( SgSClientCaster.GetSelectedPlayer() )
			{
				//Lock camera on player
			}
		}
		return 0;
	}
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( w == m_TeamCollapse )
		{
			SgSClientCaster.ShowTeam( m_Team, !SgSClientCaster.IsTeamMinimized( m_Team ) );
			ShowPlayerWidgets( !SgSClientCaster.IsTeamMinimized( m_Team ) );
		}
		else if ( w == m_TeamLabel )
			SgSClientCaster.TeamSelect( w, m_Team );
		
		else if ( m_PlayersReverse.Get( w ) )
		{
			if( SgSClientCaster.GetSelectedPlayer() )
			{
				ButtonWidget old = ButtonWidget.Cast( m_Players.Get( SgSClientCaster.GetSelectedPlayer() ) );
				old.FindAnyWidget( "Background" ).SetColor( m_TeamColor );
				old.SetState( false );
			}
			
			SgSClientCaster.SelectPlayer( w, m_PlayersReverse.Get( w ) );
			w.FindAnyWidget( "Background" ).SetColor( m_TeamColorSelected );
		}
		return 0;
	}
}