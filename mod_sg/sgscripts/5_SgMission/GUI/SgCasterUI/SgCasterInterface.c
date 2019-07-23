/*! \class SgCasterInterface
 *	\brief Main UIScriptedMenu for the caster interface.
 */
class SgHudCaster extends Hud
{
	protected 		Widget								m_CasterView;
	protected 		Widget								m_CasterLeftPanel;
	protected 		Widget								m_CasterRightPanelContent;
	protected 		Widget								m_CasterCenterPanelContent;
	protected 		Widget								m_SettingsPane;
	protected 		Widget								m_MinimapWidget;
	protected		TextWidget							m_WgtSelectedPlayerName;
	protected		SgCasterCamera						m_Camera;
	protected 	ref	SgMap								m_Minimap;
	protected	ref	SgCasterPlayerInfosPanel			m_CasterPlayerInfosPanel;
	
	protected		bool								m_IsVisible;
	
	protected ref	Timer								m_UpdateTimer;
	private			int									m_PlayersAlive;
	
/*! \brief Initialization of the Caster interface.
 *
 *  Creates an \ref array of SgUITeamArray classes and initializes them.
 *  Gets default persistent data in the SgPluginCasterManager class.
 */
	void SgHudCaster()
	{
		m_CasterView				= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_caster/ui.layout", NULL );
		m_CasterLeftPanel			= m_CasterView.FindAnyWidget("SidePanelLeft");
		m_CasterPlayerInfosPanel	= new SgCasterPlayerInfosPanel( m_CasterLeftPanel, this );
		m_WgtSelectedPlayerName		= TextWidget.Cast( m_CasterView.FindAnyWidget("SelectedPlayerName") );
		
		m_MinimapWidget				= m_CasterView.FindAnyWidget("MinimapFrame");
		m_Minimap					= new SgMap( m_MinimapWidget );
		m_Minimap.LoadMap( GetSgGame().GetPlaygroundID(), true );

		float temp;
		
		//g_Game.SetKeyboardHandle(this);
		
		// Init Caster Data
		array<ref SgCasterGuiTeam> teams = SgSClientCaster.GetInitData().GetTeams();
		foreach( SgCasterGuiTeam team : teams )
		{
			AddTeam( team );
		}
		
		SgSClientCaster.Event_OnCasterTargetPlayerChanged.Insert( Event_OnCasterTargetPlayerChanged );
		
		//return m_CasterView;
	}
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void ~SgHudCaster()
	{
		GetGame().GetInput().ResetGameFocus();
		
		if( DeveloperFreeCamera.IsFreeCameraEnabled() )
		{
			DeveloperFreeCamera.FreeCameraToggle( PlayerBase.Cast( GetGame().GetPlayer() ) );
		}
	}
	
	//===========================================
	// Event_OnCasterTargetPlayerChanged
	//===========================================
	void Event_OnCasterTargetPlayerChanged( PlayerBase selected_player )
	{
		if ( selected_player )
		{
			m_WgtSelectedPlayerName.Show( true );
			m_WgtSelectedPlayerName.SetText( selected_player.GetName() );
		}
		else
		{
			m_WgtSelectedPlayerName.Show( false );
		}		
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	override void Update( float timeslice )
	{
		if( m_IsVisible )
		{
			m_CasterPlayerInfosPanel.UpdateAllTeams();
		}
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	SgCasterInterfaceTeam AddTeam( SgCasterGuiTeam team )
	{
		array<ref SgCasterGuiPlayer> players = team.GetPlayers();
		foreach( SgCasterGuiPlayer player : players )
		{
			m_Minimap.AddTeamPlayer( player.GetPlayerUID(), team.GetTeamID() );
		}
		
		SgCasterInterfaceTeam caster_team = m_CasterPlayerInfosPanel.AddTeam( team );
		
		m_PlayersAlive += caster_team.GetPlayerCount();
		
		return caster_team;
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void ArrangePlayers()
	{/*
		if( GetSgGame().SgIsTeamPlay() )
		{
			bool switched = true;
			SgCasterInterfaceTeam t1, t2;
			int i;
			switch( m_Plugin.m_SortingOption )
			{
				case SortingOption.CAST_ELO:
				{
					while( switched && m_Teams.Count() > 1 )
					{
						switched = false;
						for( i = 0; i < m_Teams.Count() - 1; i++ )
						{
							t1 = m_Teams.GetElement( i );
							t2 = m_Teams.GetElement( i + 1 );
							if( t1.GetAvgELO() < t2.GetAvgELO() )
							{
								t1.m_TeamRoot_Wide.SetSort( t1.m_TeamRoot_Wide.GetSort() + 1 );
							}
						}
					}
					break;
				}
				case SortingOption.CAST_HEALTH:
				{
					while( switched && m_Teams.Count() > 1 )
					{
						switched = false;
						for( i = 0; i < m_Teams.Count() - 1; i++ )
						{
							t1 = m_Teams.GetElement( i );
							t2 = m_Teams.GetElement( i + 1 );
							if( t1.GetAvgDamage() < t2.GetAvgDamage() )
							{
								t1.m_TeamRoot_Wide.SetSort( t1.m_TeamRoot_Wide.GetSort() + 1 );
							}
						}
					}
					break;
				}
				case SortingOption.CAST_NAME:
				{
					while( switched && m_Teams.Count() > 1 )
					{
						switched = false;
						for( i = 0; i < m_Teams.Count() - 1; i++ )
						{
							t1 = m_Teams.GetElement( i );
							t2 = m_Teams.GetElement( i + 1 );
							if( t1.m_Team < t2.m_Team )
							{
								t1.m_TeamRoot_Wide.SetSort( t1.m_TeamRoot_Wide.GetSort() + 1 );
							}
						}
					}
					break;
				}
				default:
					break;
			}
		}
	*/
	}
	
	override void Show( bool show )
	{
		m_IsVisible = show;
		m_CasterView.Show( show );
	
		if ( show )
		{
			m_CasterPlayerInfosPanel.Show();
			OnShow();
		}
		else
		{
			m_CasterPlayerInfosPanel.Hide();
		}
	}

	void Toggle()
	{
		Show( m_IsVisible );
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void OnShow()
	{
		if( SgSManagerPlayers.GetTeams() )
		{
			m_CasterPlayerInfosPanel.UpdateAllTeams();
		}
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void PlayerHealed( int team_id, string player_uid, float heal )
	{
		m_CasterPlayerInfosPanel.PlayerHealed( team_id, player_uid, heal );
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	void PlayerDamaged( int team_id, string player_uid, float damage )
	{
		m_CasterPlayerInfosPanel.PlayerDamaged( team_id, player_uid, damage );
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	void PlayerDied( string player_uid, int team_id )
	{
		m_CasterPlayerInfosPanel.PlayerDied( player_uid, team_id );
		m_PlayersAlive--;
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	bool OnMouseButtonDown( Widget w, int x, int y, int button )
	{
		return false;
	}

	bool OnKeyUp( Widget w, int x, int y, int key )
	{
		if( !w && key == KeyCode.KC_BACK )
		{
			Toggle();
			return true;
		}
		return false;
	}
}
