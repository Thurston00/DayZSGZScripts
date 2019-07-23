/*! \class SgPluginCasterManager
 *	\brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */

class SgSClientCaster
{
	protected static bool							m_UIMinimized;
	protected static ref map<string, bool>			m_TeamsMinimized = new map<string, bool>;
	protected static SgCasterCamera					m_CasterCamera;
	protected static ButtonWidget					m_SelectedPlayerWidget;
	protected static	ref SgSWEH					m_SelectedPlayerHeader;
	static				ref SgSWEH					m_ViewClass;
	protected static ESgCasterSortingOption			m_CasterSortingOption = ESgCasterSortingOption.NAME;
	protected static ref SgCasterGuiData			m_CasterInitData;
	protected static int							m_SelectedPlayerIndex = -1;
	protected static SgPlayerClient					m_SelectedPlayer;
	
	static ref ScriptInvoker Event_OnCasterTargetPlayerChanged = new ScriptInvoker();
	
	// Call from SgSSyncEvents after game start 
	static void Init( SgCasterGuiData caster_data )
	{
		m_CasterInitData = caster_data;
	}
	
	static SgCasterGuiData GetInitData()
	{
		return m_CasterInitData;
	}
	
	static bool IsEnabled()
	{
		return ( m_CasterCamera != null );
	}	
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static bool IsMinimized()
	{
		return m_UIMinimized;
	}
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static void ToggleMinimized()
	{
		m_UIMinimized = !m_UIMinimized;
	}
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static bool IsTeamMinimized( string team )
	{
		if ( m_TeamsMinimized.Get( team ) )
		{
			return m_TeamsMinimized.Get( team );
		}
		else 
		{
			m_TeamsMinimized.Insert( team, false );
			return false;
		}
	}
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static void ShowTeam( string team, bool show)
	{
		if( m_TeamsMinimized.Contains( team ) )
			m_TeamsMinimized.Set( team , show );
		else
			m_TeamsMinimized.Insert( team, show );
	}	
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static void SelectPlayer( Widget w, SgPlayerClient player )
	{
		m_SelectedPlayer		= player;
		m_SelectedPlayerWidget	= ButtonWidget.Cast( w );
		
		ref array<SgPlayerClient> alive_players = SgSClientGame.GetAlivePlayers();
		
		for ( int i = 0; i < alive_players.Count(); ++i )
		{
			if ( alive_players[i] == player )
			{
				m_SelectedPlayerIndex = i;
				break;
			}
		}
		
		Event_OnCasterTargetPlayerChanged.Invoke( player );		
	}
	
	static bool IsPlayerSelected()
	{
		return ( m_SelectedPlayer != null );
	}
	
	static SgPlayerClient GetSelectedPlayer()
	{
		 return m_SelectedPlayer;
	}
	
	static void SelectPlayerNext()
	{
		if ( SgSClientGame.GetPlayersAliveCount() > 0 )
		{
			ref array<SgPlayerClient> alive_players = SgSClientGame.GetAlivePlayers();
			
			m_SelectedPlayerIndex++;			
			
			if ( m_SelectedPlayerIndex >= alive_players.Count() )
			{
				m_SelectedPlayerIndex = 0;
			}
			
			SelectPlayer( null, alive_players[m_SelectedPlayerIndex] );
		
			delete alive_players;
		}		
	}
	
	static void SelectPlayerPrev()
	{
		if ( SgSClientGame.GetPlayersAliveCount() > 0 )
		{
			ref array<SgPlayerClient> alive_players = SgSClientGame.GetAlivePlayers();
			
			m_SelectedPlayerIndex--;
			
			if ( m_SelectedPlayerIndex < 0 )
			{
				m_SelectedPlayerIndex = alive_players.Count() - 1;
			}
			
			SelectPlayer( null, alive_players[m_SelectedPlayerIndex] );
		
			delete alive_players;
		}
	}
	
	static void SetSelectedPlayerHeader( SgSWEH player_header )
	{
		m_SelectedPlayerHeader = player_header;
	}
	
	static SgSWEH GetSelectedPlayerHeader()
	{
		return m_SelectedPlayerHeader;
	}
	
	static void SetSelectedPlayerWidget( ButtonWidget player_header )
	{
		m_SelectedPlayerWidget = player_header;
	}
	
	static ButtonWidget GetSelectedPlayerWidget()
	{
		return m_SelectedPlayerWidget;
	}
	
	static void SetCasterSortingOption( ESgCasterSortingOption sorting )
	{
		m_CasterSortingOption = sorting;
	}
	
	static ESgCasterSortingOption GetCasterSortingOption()
	{
		return m_CasterSortingOption;
	}
	
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static void TeamSelect( Widget w, string team )
	{
		Print("Player Selected");
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static void CasterSelect( SgCasterCamera caster )
	{
		m_CasterCamera = caster;
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static void CasterFreeCamEnable()
	{
		if( IsEnabled() )
		{
			// Enable Camera control
			GetGame().GetInput().ResetGameFocus();
			
			// Disable Cursor
			GetGame().GetUIManager().ShowCursor(false);
		}
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static void CasterFreeCamDisable()
	{
		if( IsEnabled() )
		{
			// Disable Camera control
			GetGame().GetInput().ChangeGameFocus(1);
			
			// Enable Cursor
			GetGame().GetUIManager().ShowCursor(true);
		}
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static void CasterPlayerCamEnable( SgPlayerClient player )
	{
		if( m_CasterCamera )
		{
			if( m_SelectedPlayerWidget )
			{
				m_SelectedPlayerWidget.Show( false );
			}
			
			m_CasterCamera.SetTarget( ESgCasterCameraState.Snap, player );
		}
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	static void CasterPlayerCamDisable()
	{
		if( m_CasterCamera )
		{
			if( m_SelectedPlayerWidget )
			{
				m_SelectedPlayerWidget.Show( true );
			}
			
			m_CasterCamera.SetTarget( ESgCasterCameraState.Free, null );		
		}
	}
	
	static void UpdateController()
	{
		Input input = GetGame().GetInput();
	// [1] Free Camera	
		if ( input.LocalPress( "UAItem0" ) )
		{
			Print("Set Camera type FreeFly");
			
			//GetGame().GetInput().ChangeGameFocus(1);
			
			m_CasterCamera.SetCameraState( ESgCasterCameraState.Free );
		}
	// [2] Snap Camera
		else if ( input.LocalPress( "UAItem1" ) )
		{
			Print("Set Camera type Snap");
			
			//GetGame().GetInput().ChangeGameFocus(-1);
			//GetGame().GetInput().ResetGameFocus();
			
			m_CasterCamera.SetCameraState( ESgCasterCameraState.Snap );
		}
	// [3] - Identical Camera
		else if ( input.LocalPress( "UAItem2" ) )
		{
			Print("Set & Cycle Identical Camera type (1stPerson / 3rdPerson)");
			
			if ( m_CasterCamera.GetCameraState() == ESgCasterCameraState.FirstPerson )
			{
				m_CasterCamera.SetCameraState( ESgCasterCameraState.ThirdPerson );
			}
			else
			{
				m_CasterCamera.SetCameraState( ESgCasterCameraState.FirstPerson );
			}
		}
	// [PageUp] - Change camera on next player
		else if ( input.LocalPress( "UAZeroingUp" ) )
		{
			SelectPlayerNext();
		}
	// [PageDown] - Change camera on prev player
		else if ( input.LocalPress( "UAZeroingDown" ) )
		{
			SelectPlayerPrev();
		}
	}
}
