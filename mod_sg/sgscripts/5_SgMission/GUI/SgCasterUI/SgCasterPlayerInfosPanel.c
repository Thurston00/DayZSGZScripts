/*! \class SgCasterInterface
 *	\brief Main UIScriptedMenu for the caster interface.
 */
class SgCasterPlayerInfosPanel extends SgSWEH
{
	
	protected		Widget								m_CasterLeftPanelRoot;
	protected		Widget								m_CasterLeftPanelContent;
	
	//Checkboxes
	protected		CheckBoxWidget						m_GroupTeamsToggle;
	protected		CheckBoxWidget						m_ShowDeadToggle;
	protected		CheckBoxWidget						m_ShowWeaponsToggle;
	protected		CheckBoxWidget						m_ShowHealthToggle;
	
	//Sorting Menu
	protected		ButtonWidget						m_OpenSortMenuButton;
	protected		Widget								m_SortMenuPanel;
	protected		TextWidget							m_SortByTeams;
	protected		TextWidget							m_SortByHealth;
	protected		TextWidget							m_SortByELO;
	
	protected ref	array<ref SgCasterInterfaceTeam>	m_Teams;
	
	protected ref	SgHudCaster							m_MainInterface;
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void SgCasterPlayerInfosPanel( Widget root, SgHudCaster owner )
	{
		m_MainInterface				=	owner;
		m_Teams						=	new array<ref SgCasterInterfaceTeam>;
		
		m_CasterLeftPanelRoot		=	GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_caster/leftpanel/players_info_panel.layout", root );
		m_CasterLeftPanelContent	=	m_CasterLeftPanelRoot.FindAnyWidget( "Content" );
		
		//Checkboxes
		m_GroupTeamsToggle			=	CheckBoxWidget.Cast( m_CasterLeftPanelRoot.FindAnyWidget( "GroupTeams" ) );
		m_ShowDeadToggle			=	CheckBoxWidget.Cast( m_CasterLeftPanelRoot.FindAnyWidget( "ShowDead" ) );
		m_ShowWeaponsToggle			=	CheckBoxWidget.Cast( m_CasterLeftPanelRoot.FindAnyWidget( "ShowWeapons" ) );
		m_ShowHealthToggle			=	CheckBoxWidget.Cast( m_CasterLeftPanelRoot.FindAnyWidget( "ShowHealth" ) );
		
		//Sorting Menu
		m_OpenSortMenuButton		=	ButtonWidget.Cast( m_CasterLeftPanelRoot.FindAnyWidget( "OpenSortMenu" ) );
		m_SortMenuPanel				=	m_OpenSortMenuButton.FindAnyWidget( "SortOptionsPanel" );
		m_SortByTeams				=	TextWidget.Cast( m_OpenSortMenuButton.FindAnyWidget( "TeamSort" ) );
		m_SortByHealth				=	TextWidget.Cast( m_OpenSortMenuButton.FindAnyWidget( "HealthSort" ) );
		m_SortByELO					=	TextWidget.Cast( m_OpenSortMenuButton.FindAnyWidget( "ELOSort" ) );
		
		m_CasterLeftPanelRoot.SetHandler( this );
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void ~SgCasterPlayerInfosPanel()
	{
		for( int i = 0; i < m_Teams.Count(); i++ )
		{
			delete m_Teams.Get( i );
		}
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	override void Show()
	{
		for( int i = 0; i < m_Teams.Count(); i++ )
		{
			SgCasterInterfaceTeam team = m_Teams.Get( i );
			team.Show();
		}
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	override void Hide()
	{
		for( int i = 0; i < m_Teams.Count(); i++ )
		{
			SgCasterInterfaceTeam team = m_Teams.Get( i );
			team.Hide();
		}
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void UpdateAllTeams()
	{
		array<ref SgPlayerClient> players = SgSClientGame.GetPlayers();
		
		if( m_Teams )
		{
			for( int i = 0; i < m_Teams.Count(); i++ )
			{
				SgCasterInterfaceTeam team = m_Teams.Get( i );
				team.Update();
			}
		}
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	SgCasterInterfaceTeam AddTeam( SgCasterGuiTeam team )
	{
		ref SgCasterInterfaceTeam caster_team = new SgCasterInterfaceTeam( m_CasterLeftPanelContent, team );
		
		m_Teams.Insert( caster_team );
		return caster_team;
	}
	
	void SetOptionColor()
	{
		int colorUnsel	=	ARGB( 200, 255, 255, 255 );
		int colorSel	=	ARGB( 255, 255, 255, 255 );
		switch( SgSClientCaster.GetCasterSortingOption() )
		{
			case ESgCasterSortingOption.ELO:
			{
				m_SortByTeams.SetColor( colorUnsel );
				m_SortByHealth.SetColor( colorUnsel );
				m_SortByELO.SetColor( colorSel );
				break;
			}
			case ESgCasterSortingOption.HEALTH:
			{
				m_SortByTeams.SetColor( colorUnsel );
				m_SortByHealth.SetColor( colorSel );
				m_SortByELO.SetColor( colorUnsel );
				break;
			}
			case ESgCasterSortingOption.NAME:
			{
				m_SortByTeams.SetColor( colorSel );
				m_SortByHealth.SetColor( colorUnsel );
				m_SortByELO.SetColor( colorUnsel );
				break;
			}
			default:
				break;
		}
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void PlayerHealed( int team_id, string player_uid, float heal )
	{
		SgCasterInterfaceTeam team = m_Teams.Get( team_id );
		if( team )
			team.PlayerHealed( player_uid, heal );
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	void PlayerDamaged( int team_id, string player_uid, float damage )
	{
		SgCasterInterfaceTeam team = m_Teams.Get( team_id );
		if( team )
			team.PlayerDamaged( player_uid, damage );
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	void PlayerDied( string player_uid, int team_id )
	{
		SgCasterInterfaceTeam team = m_Teams.Get( team_id );
		if( team )
			team.PlayerDied( player_uid );
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	override bool OnMouseButtonDown( Widget w, int x, int y, int button )
	{
		if ( w == m_OpenSortMenuButton )
		{
			if( m_SortMenuPanel.IsVisible() )
			{
				m_SortMenuPanel.Show( false );
			}
			else
			{
				m_SortMenuPanel.Show( true );
			}
			return 0;
		}
		else if ( m_SortMenuPanel.IsVisible() &&  w == m_SortByTeams )
		{
			SgSClientCaster.SetCasterSortingOption( ESgCasterSortingOption.NAME );
			SetOptionColor();
			return 0;
		}
		else if ( m_SortMenuPanel.IsVisible() &&  w == m_SortByHealth )
		{
			SgSClientCaster.SetCasterSortingOption( ESgCasterSortingOption.HEALTH );
			SetOptionColor();
			return 0;
		}
		else if ( m_SortMenuPanel.IsVisible() &&  w == m_SortByELO )
		{
			SgSClientCaster.SetCasterSortingOption( ESgCasterSortingOption.ELO );
			SetOptionColor();
			return 0;
		}
		return 0;
	}
}