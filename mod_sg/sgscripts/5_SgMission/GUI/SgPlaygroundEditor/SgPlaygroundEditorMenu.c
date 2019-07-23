class SgPlaygroundEditorMenu extends SgUISM
{
	protected Widget									m_RootWidget;
	protected Widget									m_Viewport;
	protected Widget									m_TitlebarWidget;
	protected Widget									m_LeftSidebarWidget;
	protected Widget									m_RightSidebarWidget;
	protected Widget									m_PopupWidget;
	protected Widget									m_TipWidget;
	protected Widget									m_ContextMenuWidget;
	
	protected TextWidget								m_NotifyWidget;
	protected ButtonWidget								m_NewButtonWidget;
	protected ButtonWidget								m_SaveButtonWidget;
	protected ButtonWidget								m_AddLocationButtonWidget;
	protected ButtonWidget								m_ExitButtonWidget;
	protected ButtonWidget								m_PopupExitButtonWidget;
	
	protected MultilineTextWidget						m_TipText;
	
	protected SgPluginPgEditor							m_Manager;
	protected bool										m_IsVisible;
	protected ref SgSWEH								m_PopupMenu;
	protected ref Timer									m_PopupDeleteTimer;
	protected ref Timer									m_PopupCreateTimer;
	protected ref WidgetFadeTimer						m_NotifyFadeTimer;
	
	protected ref SgPlaygroundLocationsWidget			m_SetupLocations;
	protected ref array<ref SgEditorLocationFollower>	m_UpdateWidgets;
	protected ref SgLocationContextMenu					m_LocationContext;
	protected ref SgBorderContextMenu					m_BorderContext;
	protected ref SgEndContextMenu						m_EndContext;
	protected ref SgStartContextMenu					m_StartContext;
	
	protected ESgPgEditorStates							m_EditorState;
	protected SgEditorObjectFollower					m_SelectedObject;
	
	protected int										m_SelectedPhase;
	
	void SgPlaygroundEditorMenu()
	{
		m_Manager					= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		/*
		MissionGameplay mission		= MissionGameplay.Cast( GetGame().GetMission() );
		if( mission )
		{
			mission.GetHud().Show( false );
			mission.GetSgHud().Show( false );
		}
		*/
	}

	override Widget Init()
	{
		m_RootWidget				= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/sg_playground_editor.layout", NULL );
		
		m_Viewport					= m_RootWidget.FindAnyWidget( "Viewport" );
		
		m_TitlebarWidget			= m_RootWidget.FindAnyWidget( "Titlebar" );
		
		m_NotifyWidget				= TextWidget.Cast( m_RootWidget.FindAnyWidget( "NotifyWidget" ) );
		m_NewButtonWidget			= ButtonWidget.Cast( m_TitlebarWidget.FindAnyWidget( "FileButton" ) );
		m_SaveButtonWidget			= ButtonWidget.Cast( m_TitlebarWidget.FindAnyWidget( "SaveButton" ) );
		m_AddLocationButtonWidget	= ButtonWidget.Cast( m_TitlebarWidget.FindAnyWidget( "AddLocationButton" ) );
		m_ExitButtonWidget			= ButtonWidget.Cast( m_TitlebarWidget.FindAnyWidget( "ExitButton" ) );
		m_PopupExitButtonWidget		= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "PopupExitButton" ) );
		
		m_LeftSidebarWidget			= m_RootWidget.FindAnyWidget( "LeftSidebar" );
		
		m_RightSidebarWidget		= m_RootWidget.FindAnyWidget( "RightSidebar" );
		
		m_PopupWidget				= m_RootWidget.FindAnyWidget( "Popup" );
		
		m_TipWidget					= m_Viewport.FindAnyWidget( "TipContainer" );
		m_TipText					= MultilineTextWidget.Cast( m_TipWidget.FindAnyWidget( "TipText" ) );
		
		m_ContextMenuWidget			= m_RootWidget.FindAnyWidget( "ContextMenu" );
		m_LocationContext			= new SgLocationContextMenu( m_ContextMenuWidget, this );
		m_BorderContext				= new SgBorderContextMenu( m_ContextMenuWidget, this );
		m_EndContext				= new SgEndContextMenu( m_ContextMenuWidget, this );
		m_StartContext				= new SgStartContextMenu( m_ContextMenuWidget, this );
		TogglePanels( false );
		
		m_PopupDeleteTimer			= new Timer( CALL_CATEGORY_GUI );
		m_PopupCreateTimer			= new Timer( CALL_CATEGORY_GUI );
		m_NotifyFadeTimer			= new WidgetFadeTimer;
		m_UpdateWidgets				= new array<ref SgEditorLocationFollower>;
		
		ToggleTitlebar( true );
		
		if( !m_Manager.GetInstance().IsPgLoaded() )
		{
			m_PopupWidget.Show( true );
			m_PopupMenu			= new SgLoadPlaygroundPopup( m_PopupWidget, this );
		}
		
		Refresh();
		
		g_Game.SetKeyboardHandle(this);
		MissionGameplay mission = MissionGameplay.Cast( GetGame().GetMission() );
		mission.GetHudDebug().HideCrosshairVisibility();
		
		m_IsVisible = true;
		
		SgPluginPgEditor.Event_OnPgEditorSaved.Insert( Event_OnPgEditorSaved );
		
		return m_RootWidget;
	}
	
	void ~SgPlaygroundEditorMenu()
	{
		if( m_PopupMenu )
		{
			delete m_PopupMenu;
		}
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}
	
	void LoadPlaygroundData()
	{
		SgJsonPlayground pg	= m_Manager.GetCurrentPlayground();
		if( pg )
		{
			TogglePanels( true );
			if( m_SetupLocations )
			{
				delete m_SetupLocations;
			}
			m_UpdateWidgets.Clear();
			m_SetupLocations = new SgPlaygroundLocationsWidget( m_LeftSidebarWidget, pg, this );
			
			SetTitlebar( pg.m_PGID, pg.m_PGMapName, pg.m_PGName );
			array<ref SgJsonLocation>	locations	= pg.m_Locations;
			for( int i = 0; i < locations.Count(); i++ )
			{
				SgJsonLocation location				= locations.Get( i );
				if( location )
				{
					ref SgEditorLocationFollower t_f	= new SgEditorLocationFollower( m_Viewport, location, Colors.GetTeamColor( i ), this );
					array<vector> borders				= location.GetBorderPositions();
					array<vector> ends					= location.GetEndPositions();
					
					if( borders )
					{
						for( int j = 0; j < borders.Count(); j++ )
						{
							ref SgEditorBorderFollower a_f	= new SgEditorBorderFollower( m_Viewport, location, j, Colors.GetTeamColor( i ), this );
							t_f.AddBorderWidget( a_f );
						}
					}
					
					if( ends )
					{
						for( int k = 0; k < ends.Count(); k++ )
						{
							ref SgEditorEndFollower p_f		= new SgEditorEndFollower( m_Viewport, location, k, this );
							t_f.AddEndWidget( p_f );
						}
					}
					
					m_UpdateWidgets.Insert( t_f );
				}
			}
			SelectLocation( null );
		}
		else
		{
			ToggleLeftSidebar( false );
		}
	}
	
	override void Update( float timeslice )
	{
		foreach( SgEditorLocationFollower to_update : m_UpdateWidgets )
		{
			if( to_update )
			{
				to_update.Update();
			}
		}
		
		if( m_SetupLocations )
		{
			m_SetupLocations.Update();
		}
		
		switch( m_EditorState )
		{
			case ESgPgEditorStates.None:
			{
				m_SelectedObject = null;
				break;
			}
			case ESgPgEditorStates.Moving:
			{
				if( m_SelectedObject )
				{
					m_SelectedObject.SetPosition( GetMousePositionInScene(false) );
				}
				break;
			}
			case ESgPgEditorStates.Rotating:
			{
				if( m_SelectedObject )
				{
					float direction			= GetDirectionFromObjectToPointer();
					vector curr_direction	= m_SelectedObject.GetRotation();
					vector angle_direction	= curr_direction.VectorToAngles();
					angle_direction[0]		= direction;
					
					curr_direction			= angle_direction.AnglesToVector();
					
					m_SelectedObject.SetRotation( curr_direction );
				}
				break;
			}
			case ESgPgEditorStates.Radius:
			{
				vector pos = m_Manager.GetCurrentPlayground().m_Locations.Get( m_SelectedPhase ).GetPosition();
				Debug.DrawCylinder( pos, vector.Distance( pos, GetMousePositionInScene() ), 10, Colors.BLUE, ShapeFlags.ONCE + ShapeFlags.TRANSP + ShapeFlags.NOZBUFFER );
				break;
			}
		}
	}
	
	override void Refresh()
	{
		super.Refresh();
		if( m_Manager )
		{
			ClearWidgets();
			LoadPlaygroundData();
		}
	}
	
	void Event_OnPgEditorSaved()
	{
		Notify( "Game Saved", 2 );
		
		m_SetupLocations.SaveLocationsAIGroupsSpawnData();
	}
	
	void Notify( string text, float time )
	{
		m_NotifyWidget.SetText( text );
		m_NotifyFadeTimer.FadeOut( m_NotifyWidget, time );
	}
	
	void ClearWidgets()
	{
		foreach( SgEditorLocationFollower follower : m_UpdateWidgets )
		{
			delete follower;
		}
		delete m_SetupLocations;
	}
	
	void ToggleTitlebar( bool show )
	{
		if( m_TitlebarWidget )
			m_TitlebarWidget.Show( show );
	}
	
	void ToggleLeftSidebar( bool show )
	{
		if( m_LeftSidebarWidget )
			m_LeftSidebarWidget.Show( show );
	}
	
	void ToggleRightSidebar( bool show )
	{
		if( m_RightSidebarWidget )
			m_RightSidebarWidget.Show( show );
	}
	
	void TogglePopup( bool show )
	{
		if( m_PopupWidget )
			m_PopupWidget.Show( show );
	}
	
	void ToggleTip( bool show )
	{
		if( m_TipWidget )
			m_TipWidget.Show( show );
	}
	
	void TogglePanels( bool show )
	{
		ToggleTitlebar( show );
		ToggleLeftSidebar( show );
		//ToggleRightSidebar( show );
		ToggleTip( show );
	}
	
	override void Toggle()
	{
		m_IsVisible = !m_IsVisible;
		TogglePanels( m_IsVisible );
	}
	
	void ShowContextMenu( SgEditorObjectFollower obj, int x, int y )
	{
		float xfs, yfs, xfst, yfst;
		m_ContextMenuWidget.GetScreenSize( xfs, yfs );
		m_RootWidget.GetScreenSize( xfst, yfst );
		
		if( xfs + x > xfst )
		{
			x = xfst - xfs;
		}
		if( yfs + y > yfst )
		{
			y = yfst - yfs;
		}
		
		m_ContextMenuWidget.SetPos( x, y );
		
		if( obj && obj.IsInherited( SgEditorLocationFollower ) )
		{
			SgEditorLocationFollower location = SgEditorLocationFollower.Cast( obj );
			HideContextMenu();
			m_ContextMenuWidget.Show( true );
			m_LocationContext.OpenContext( obj, m_Manager.GetCurrentPlayground().m_Locations.Get( location.GetAreaID() ) );
		}
		else if( obj && obj.IsInherited( SgEditorBorderFollower ) )
		{
			SgEditorBorderFollower border = SgEditorBorderFollower.Cast( obj );
			if( m_SelectedPhase == border.GetPhaseID() )
			{
				HideContextMenu();
				m_ContextMenuWidget.Show( true );
				m_BorderContext.OpenContext( obj, m_Manager.GetCurrentPlayground().m_Locations.Get( border.GetPhaseID() ) );
			}
		}
		else if( obj && obj.IsInherited( SgEditorEndFollower ) )
		{
			SgEditorEndFollower end = SgEditorEndFollower.Cast( obj );
			if( m_SelectedPhase == end.GetPhaseID() )
			{
				HideContextMenu();
				m_ContextMenuWidget.Show( true );
				m_EndContext.OpenContext( obj, m_Manager.GetCurrentPlayground().m_Locations.Get( end.GetPhaseID() ) );
			}
		}
		
		m_ContextMenuWidget.Update();
	}
	
	void HideContextMenu()
	{
		m_LocationContext.HideContext();
		m_BorderContext.HideContext();
		m_StartContext.HideContext();
		m_EndContext.HideContext();
		m_ContextMenuWidget.Show( false );
	}
	
	override void Show()
	{
		TogglePanels( true );
	}
	
	override void Hide()
	{
		TogglePanels( false );
	}
	
	void AddChildWidget(Widget child)
	{
		m_Viewport.AddChild(child);
	}
	
	void RemoveChildWidget(Widget child)
	{
		m_Viewport.RemoveChild(child);
	}
	
	void SetState( ESgPgEditorStates state )
	{
		m_EditorState = state;
	}
	
	ESgPgEditorStates GetState()
	{
		return m_EditorState;
	}
	
	bool SelectObject( SgEditorObjectFollower obj ) // SG_TODO: This need to be refactored
	{
		if( obj && obj.IsInherited( SgEditorLocationFollower ) )
		{
			SgEditorLocationFollower location = SgEditorLocationFollower.Cast( obj );
			if( location.GetAreaID() == m_SelectedPhase )
			{
				m_SelectedObject = obj;
				m_TipText.SetText( "Press LCtrl to rotate objects." );
				SetState( ESgPgEditorStates.Moving );
				return true;
			}
		}
		else if( obj && obj.IsInherited( SgEditorBorderFollower ) )
		{
			SgEditorBorderFollower border = SgEditorBorderFollower.Cast( obj );
			if( border.GetPhaseID() == m_SelectedPhase )
			{
				m_SelectedObject = obj;
				m_TipText.SetText( "Press LCtrl to rotate objects." );
				SetState( ESgPgEditorStates.Moving );
			}
			else
			{
				m_TipText.SetText( "Moving antennas is enabled only in phase editing." );
			}
			return true;
		}
		else if( obj && obj.IsInherited( SgEditorEndFollower ) )
		{
			SgEditorEndFollower end = SgEditorEndFollower.Cast( obj );
			if( m_SelectedPhase == end.GetPhaseID() )
			{
				m_SelectedObject = obj;
				m_TipText.SetText( "Press LCtrl to rotate objects." );
				SetState( ESgPgEditorStates.Moving );
			}
			else
			{
				m_TipText.SetText( "Moving end point is enabled only in phase 3 editing." );
			}
			return true;
		}
		else if( obj && obj.IsInherited( SgEditorAIZoneFollower ) )
		{
			SgEditorAIZoneFollower aiZone = SgEditorAIZoneFollower.Cast( obj );
			if( m_SelectedPhase == aiZone.GetPhaseID() )
			{
				m_SelectedObject = obj;
				m_TipText.SetText( "Press LCtrl to rotate objects." );
				SetState( ESgPgEditorStates.Moving );
			}
			else
			{
				m_TipText.SetText( "Moving end point is enabled only in phase 3 editing." );
			}
			return true;
		}
		else if( obj && obj.IsInherited( SgEditorSpawnpointFollower ) )
		{
			SgEditorSpawnpointFollower spawnpoint = SgEditorSpawnpointFollower.Cast( obj );
			if( m_SelectedPhase == spawnpoint.GetPhaseID() )
			{
				m_SelectedObject = obj;
				m_TipText.SetText( "Press LCtrl to rotate objects." );
				SetState( ESgPgEditorStates.Moving );
			}
			else
			{
				m_TipText.SetText( "Moving end point is enabled only in phase 3 editing." );
			}
			return true;
		}
		else
		{
			m_SelectedObject = null;
			m_TipText.SetText( "Drag objects to reposition them.\nRClick to enable movement." );
			SetState( ESgPgEditorStates.None );
		}
		return false;
	}
	
	void SelectLocation( SgJsonLocation location )
	{
		m_SelectedPhase = -1;
		
		if ( location )
		{
			m_SelectedPhase = location.m_AreaID;
		}		
		
		SgPluginPgEditor.GetInstance().SelectLocation( location );
		m_SetupLocations.SelectPhase( m_SelectedPhase );
		
		foreach( SgSWEH location_show : m_UpdateWidgets )
		{
			SgEditorLocationFollower location_follower = SgEditorLocationFollower.Cast( location_show );
			if( location_follower ) 
			{
				if( m_SelectedPhase >= 0 )
				{
					location_follower.FadePhase( location_follower.GetAreaID() != m_SelectedPhase );
				}
				else
				{
					location_follower.FadePhase( false );
				}
			}
		}
	}
	
	void ClosePopup()
	{
		m_PopupDeleteTimer.Run( 0.05, this, "DeletePopup" );
	}
	
	void ClosePopupOnly()
	{
		m_PopupDeleteTimer.Run( 0.05, this, "DeletePopupOnly" );
	}
	
	void DeletePopup()
	{
		ToggleLeftSidebar( true );
		ToggleTip( true );
		
		if( m_PopupMenu )
			delete m_PopupMenu;
		TogglePopup( false );
	}
	
	void DeletePopupOnly()
	{
		if( m_PopupMenu )
		{
			delete m_PopupMenu;
		}
	}
	
	void OpenLoadPopup()
	{
		ToggleLeftSidebar( false );
		ToggleTip( false );
		
		m_PopupMenu = new SgLoadPlaygroundPopup( m_PopupWidget, this );
		TogglePopup( true );
	}
	
	void OpenCreatePopup()
	{
		ToggleLeftSidebar( false );
		ToggleTip( false );
		
		m_PopupMenu = new SgCreatePlaygroundPopup( m_PopupWidget, this );
		TogglePopup( true );
	}
	
	void OpenLocationCreatePopup()
	{
		m_PopupMenu = new SgCreateLocationPopup( m_RootWidget, this );
	}
	
	void ShowPopup(SgSWEH popup)
	{
		m_PopupMenu = popup;
	}
	
	bool IsPopupOpened()
	{
		return m_PopupMenu != NULL;
	}
	
	void SnapToGround( out vector pos )
	{
		float pos_x = pos[0];
		float pos_z = pos[2];
		float pos_y = GetGame().SurfaceY(pos_x, pos_z);
		pos[1] = pos_y;
	}
	
	vector GetMousePositionInScene( bool ground_only = true )
	{
		vector dir = GetGame().GetPointerDirection();
		vector from = FreeDebugCamera.GetInstance().GetPosition(); 
		vector to = from + ( dir * 100000000 );   
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		EntityAI selected_object;
		if( m_SelectedObject )
		{
			selected_object = m_SelectedObject.GetObj();
		}
		
		DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, null, null, selected_object, ground_only, ground_only, ObjIntersectView );
		return contact_pos;
	}
	
	float GetDirectionFromObjectToPointer()
	{
		if( m_SelectedObject )
		{
			vector from		= m_SelectedObject.GetPosition();
			vector to		= GetMousePositionInScene();
			
			vector result	= from - to;
			
			return result.VectorToAngles()[0];
		}
		
		return 0;
	}
	
	vector GetViewPosition( bool ground_only = true )
	{
		// Raycast from
		vector from = FreeDebugCamera.GetInstance().GetPosition(); 
		// Direction Vector from current active Camera
		vector dir = FreeDebugCamera.GetInstance().GetOrientation().AnglesToVector();

		// Raycast to
		vector to = from + ( dir * 100000000 );   
		// Raycast out parameter
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		set<Object> objects = new set<Object>;
		
		DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, null, null, null, ground_only, ground_only, ObjIntersectView);
		//DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, null, null, null, true, true );
		return contact_pos;
	}
	
	void StartPlacingLocation( SgJsonLocation location )
	{
		vector contact_pos					= GetViewPosition();
		
		m_Manager.StartPlacingLocation( location, contact_pos );
		ref SgEditorLocationFollower t_f	= new SgEditorLocationFollower( m_Viewport, location, Colors.GetTeamColor( location.m_AreaID ), this );
		m_UpdateWidgets.Insert( t_f );
		
		m_SetupLocations.AddLocation( location );
	}
	
	void StartPlacingBorderPoint( SgJsonLocation location )
	{
		vector contact_pos					= GetViewPosition();
		
		int index = m_Manager.StartPlacingBorderPoint( location, contact_pos );
		
		SgEditorLocationFollower t_f		= m_UpdateWidgets.Get( location.m_AreaID );
		ref SgEditorBorderFollower a_f		= new SgEditorBorderFollower( m_Viewport, location, index, Colors.GetTeamColor( location.m_AreaID ), this );
		t_f.AddBorderWidget( a_f );
	}
	
	void InsertBorderPoint( SgJsonLocation location, int index )
	{
		vector pos							= m_Manager.InsertBorderPoint( location, index );
		
		SgEditorLocationFollower t_f		= m_UpdateWidgets.Get( location.m_AreaID );
		ref SgEditorBorderFollower a_f		= new SgEditorBorderFollower( m_Viewport, location, index, Colors.GetTeamColor( location.m_AreaID ), this );
		t_f.InsertBorderWidget( a_f, index );
	}
	
	void RemoveBorderPoint( SgJsonLocation location, int index )
	{
		m_Manager.RemoveBorderPoint( location, index );
		
		SgEditorLocationFollower t_f		= m_UpdateWidgets.Get( location.m_AreaID );
		t_f.RemoveBorderWidget( index );
	}
	
	void ClearBorderPoints( SgJsonLocation location )
	{
		m_Manager.ClearBorderPoints( location );
		
		SgEditorLocationFollower t_f		= m_UpdateWidgets.Get( location.m_AreaID );
		t_f.ClearBorderWidgets();
	}
	
	void StartPlacingEnd( SgJsonLocation location )
	{
		vector contact_pos					= GetViewPosition();
		
		int index							= m_Manager.StartPlacingEnd( location, contact_pos );
		
		SgEditorLocationFollower t_f		= m_UpdateWidgets.Get( location.m_AreaID );
		ref SgEditorEndFollower p_f			= new SgEditorEndFollower( m_Viewport, location, index, this );
		p_f.SetPosition( contact_pos );
		t_f.AddEndWidget( p_f );
	}
	
	void CreateRadiusSelector( vector center )
	{
		SetState( ESgPgEditorStates.Radius );
		Print( "Radius" );
	}
	
	void StartGeneratingAntennas( vector mouse_position )
	{
		SgJsonLocation location				= m_Manager.GetCurrentPlayground().m_Locations.Get( m_SelectedPhase );
		float radius						= vector.Distance( location.GetPosition(), mouse_position );
		if( location )
		{
			array<vector> borders = m_Manager.StartGeneratingBorderPoints( location, radius );
			
			for( int i = 0; i <  borders.Count(); i++ )
			{
				SgEditorLocationFollower t_f	= m_UpdateWidgets.Get( location.m_AreaID );
				ref SgEditorBorderFollower a_f	= new SgEditorBorderFollower( m_Viewport, location, i, Colors.GetTeamColor( location.m_AreaID ), this );
				t_f.AddBorderWidget( a_f );
			}
		}
	}
	
	void SetTitlebar( int id, string mission_name, string name )
	{
		MultilineTextWidget pg_id	= MultilineTextWidget.Cast( m_TitlebarWidget.FindAnyWidget( "PlaygroundID" ) );
		MultilineTextWidget m_name	= MultilineTextWidget.Cast( m_TitlebarWidget.FindAnyWidget( "MissionName" ) );
		MultilineTextWidget pg_name	= MultilineTextWidget.Cast( m_TitlebarWidget.FindAnyWidget( "PlaygroundName" ) );
		MultilineTextWidget players	= MultilineTextWidget.Cast( m_TitlebarWidget.FindAnyWidget( "PlayerCount" ) );
		
		pg_id.SetText( id.ToString() + " " );
		m_name.SetText( mission_name + " " );
		pg_name.SetText( name + " " );
		players.SetText( "-" );
	}
	
	EntityAI GetObjectUnderCursor()
	{
		// Direction Vector from current active Camera
		vector dir = GetGame().GetPointerDirection();
		
		// Raycast from
		vector from = FreeDebugCamera.GetInstance().GetPosition(); 
		// Raycast to
		vector to = from + ( dir * 100000 );
		// Raycast out parameter
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		set<Object> objects = new set<Object>;
		bool selected = false;
		
		if ( DayZPhysics.RaycastRV(from, to, contact_pos, contact_dir, contact_component, objects) )   
		{
			if( objects.Count() > 0 )
				return EntityAI.Cast( objects.Get( 0 ) );
		}
		return null;
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		super.OnClick( w, x, y, button );
		if( w == m_NewButtonWidget && button == MouseState.LEFT )
		{
			if( !m_PopupMenu )
			{
				OpenLoadPopup();
				return true;
			}
		}
		else if( w == m_SaveButtonWidget && button == MouseState.LEFT )
		{
			m_Manager.SaveCurrentPlayground();
		}
		else if( w == m_AddLocationButtonWidget && button == MouseState.LEFT )
		{
			if( !m_PopupMenu )
			{
				OpenLocationCreatePopup();
				return true;
			}
		}
		else if( w == m_ExitButtonWidget && button == MouseState.LEFT )
		{
			m_Manager.EditorToggle();
		}
		else if( w == m_PopupExitButtonWidget && button == MouseState.LEFT )
		{
			ClosePopup();
			TogglePopup( false );
		}
		return false;
	}
	
	// AI 
	
	void AddAIZone( SgJsonAIZone aiZoneData, int herdIndex, int aiZoneIndex, ESgAIGroup aiGroup )
	{		
		SgJsonLocation location							= m_Manager.GetCurrentPlayground().m_Locations.Get( m_SelectedPhase );
		SgEditorLocationFollower locationFollower 		= m_UpdateWidgets.Get( location.m_AreaID );
		ref SgEditorAIZoneFollower aiZoneFollower 		= new SgEditorAIZoneFollower( m_Viewport, location, herdIndex, aiZoneIndex, Colors.GetTeamColor( herdIndex ), this, aiZoneData, aiGroup );
		
		locationFollower.AddAIZoneWidget( aiZoneFollower );
	}
	
	void UpdateAIZoneData( SgJsonAIZone aiZoneData, int herdIndex, int aiZoneIndex )
	{
		SgJsonLocation location							= m_Manager.GetCurrentPlayground().m_Locations.Get( m_SelectedPhase );
		SgEditorLocationFollower locationFollower 		= m_UpdateWidgets.Get( location.m_AreaID );
		SgEditorAIZoneFollower aiZoneFollower			= locationFollower.GetAIZoneWidget(aiZoneData);
		
		aiZoneFollower.SetIndexes( herdIndex, aiZoneIndex );
		aiZoneFollower.SetColor( Colors.GetTeamColor( herdIndex ) );
	}
	
	void RemoveAIZone(SgJsonAIZone aiZoneData)
	{
		SgJsonLocation location							= m_Manager.GetCurrentPlayground().m_Locations.Get( m_SelectedPhase );
		SgEditorLocationFollower locationFollower 		= m_UpdateWidgets.Get( location.m_AreaID );
		SgEditorAIZoneFollower aiZoneFollower			= locationFollower.GetAIZoneWidget(aiZoneData);
		
		locationFollower.RemoveAIZoneWidget(aiZoneFollower);
	}
	
	void AddAISpawnpoint( SgJsonAISpawnPoint spawnpointData, SgJsonAIZone aiZoneData, int spawnpointIndex )
	{		
		SgJsonLocation location								= m_Manager.GetCurrentPlayground().m_Locations.Get( m_SelectedPhase );
		SgEditorLocationFollower locationFollower 			= m_UpdateWidgets.Get( location.m_AreaID );
		ref SgEditorSpawnpointFollower spawnpointFollower 	= new SgEditorSpawnpointFollower( m_Viewport, location, spawnpointIndex, Colors.GetTeamColor( 14 ), this, aiZoneData, spawnpointData );
		
		locationFollower.AddAISpawnpointWidget(spawnpointFollower);
	}
	
	void UpdateSpawnpointData( SgJsonAISpawnPoint spawnpointData, int index )
	{
		SgJsonLocation location							= m_Manager.GetCurrentPlayground().m_Locations.Get( m_SelectedPhase );
		SgEditorLocationFollower locationFollower 		= m_UpdateWidgets.Get( location.m_AreaID );
		SgEditorSpawnpointFollower spawnpointFollower	= locationFollower.GetSpawnpointWidget(spawnpointData);
		
		spawnpointFollower.SetIndex(index);
	}
	
	void RemoveSpawnpoint(SgJsonAISpawnPoint spawnpointData)
	{
		SgJsonLocation location							= m_Manager.GetCurrentPlayground().m_Locations.Get( m_SelectedPhase );
		SgEditorLocationFollower locationFollower 		= m_UpdateWidgets.Get( location.m_AreaID );
		SgEditorSpawnpointFollower spawnpointFollower	= locationFollower.GetSpawnpointWidget(spawnpointData);
		
		locationFollower.RemoveSpawnpointWidget(spawnpointFollower);
	}
	
	// Input
	
	override bool OnMouseButtonDown( Widget w, int x, int y, int button )
	{
		Print("OnMouseButtonDown");
		if( w == m_Viewport )
		{
			
			EntityAI obj	= GetObjectUnderCursor();
			if( button == MouseState.LEFT )
			{
				m_ContextMenuWidget.Show( false );
				switch( m_EditorState )
				{
					case ESgPgEditorStates.Moving:
					{
						SelectObject( null );
						SetState( ESgPgEditorStates.None );
						Print( "None" );
						break;
					}
					case ESgPgEditorStates.Radius:
					{
						StartGeneratingAntennas( GetMousePositionInScene() );
						SetState( ESgPgEditorStates.None );
						Print( "None" );
						break;
					}
					case ESgPgEditorStates.None:
					{
						return true;//SelectObject( obj );
					}
				}
			}
			else if( button == MouseState.RIGHT )
			{
				if( /*obj.IsSgEditableObject()*/ obj && ( obj.IsInherited( SG_StaticTransmitter ) || obj.IsInherited( SG_StaticAntenna ) || obj.IsInherited( SG_StaticStartPointAll ) || obj.IsInherited( Roadflare ) ) )
				{
					//ShowContextMenu( obj, x, y );
				}
				else
				{
					HideContextMenu();
					m_Manager.GetInstance().Event_OnRClick();
				}
			}
		}
		return false;
	}	
	
	override bool OnMouseButtonUp( Widget w, int x, int y, int button )
	{
		switch( m_EditorState )
		{
			case ESgPgEditorStates.None:
			{
				SelectObject( null );
				break;
			}
			case ESgPgEditorStates.Moving:
			{
				SelectObject( null );
				SetState( ESgPgEditorStates.None );
				break;
			}
			case ESgPgEditorStates.Rotating:
			{
				SetState( ESgPgEditorStates.Moving );
				break;
			}
		}
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( w == m_Viewport )
		{
			//m_TipText.SetText( "Drag objects to reposition them.\nRClick to enable movement." );
			//SetState( ESgPgEditorStates.None );
			//Print( "None" );
			return true;
		}
		return false;
	}
	
	override bool OnKeyDown(Widget w, int x, int y, int key)
	{
		if( !w && KeyCode.KC_LCONTROL == key )
		{
			SetState( ESgPgEditorStates.Rotating );
			return true;
		}
		return false;
	}
	
	override bool OnKeyUp(Widget w, int x, int y, int key)
	{
		if( !w && KeyCode.KC_LCONTROL == key )
		{
			SetState( ESgPgEditorStates.None );
			return true;
		}
		else if( !w && key == KeyCode.KC_BACK )
		{
			if( !m_PopupWidget )
			{
				Toggle();
				return true;
			}
		}
		return false;
	}
}
