/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
class SgMap extends SgUISM
{
	protected			ImageWidget						m_Map;
	
	protected static	int								m_PlaygroundID = -1;
	protected static	bool							m_CasterMap;
	protected			int								m_MapSourceXSize;
	protected			int								m_MapSourceYSize;
	
	protected			bool							m_Dragging;
	protected			int								m_DragXOffset;
	protected			int								m_DragYOffset;
	protected			float 							m_ZoomSpeed = 0.1;
	
	protected static ref array<string>					m_TeammateIDs;
	protected ref 		array<ref SgMapTracker>			m_Trackers;
	
	protected ref		array<Widget>					m_StaticIcons;
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void SgMap( Widget parent = null )
	{
		layoutRoot			= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_map/sg_map.layout", parent );
		m_Trackers			= new array<ref SgMapTracker>;
		m_StaticIcons		= new array<Widget>;
		m_Map				= ImageWidget.Cast( layoutRoot.FindAnyWidget( "MapWidget" ) );
		m_TeammateIDs		= SgSClientGame.GetTeammates();
		
		m_Map.LoadImageFile(0, "{833F88B878B0D0BB}mod_sg/gui/textures/map_severograd.edds", true);
		
		SgSSyncEvents.SyncEvent_OnGamePhaseChanged.Insert( SyncEvent_OnGamePhaseChanged );
		LoadMap( m_PlaygroundID, m_CasterMap );
		InitMapSize();
	}
	
	static void InitMapResources()
	{		
		Widget rootW = GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_map/sg_map.layout", null );
		ImageWidget mapW = ImageWidget.Cast( rootW.FindAnyWidget( "MapWidget" ) );
		mapW.LoadImageFile(0, "{833F88B878B0D0BB}mod_sg/gui/textures/map_severograd.edds", true);
		
		delete rootW;
	}
	
	override Widget Init()
	{
		return layoutRoot;
	}
	
	void ~SgMap()
	{
		SgSSyncEvents.SyncEvent_OnGamePhaseChanged.Remove( SyncEvent_OnGamePhaseChanged );
	}
	
	void LoadMap( int playground, bool castermap )
	{
		if( castermap )
		{
			layoutRoot.SetSort( 0 );
			layoutRoot.SetPos( 0, 0 );
			layoutRoot.SetSize( 1, 1 );
			layoutRoot.Show( true );
		}
		
		m_PlaygroundID		= playground;
		m_CasterMap			= castermap;
		
		if( m_PlaygroundID >= 0 && m_PlaygroundID < 3 )
		{
			m_Map.GetImageSize( 0, m_MapSourceXSize, m_MapSourceYSize );
		}
		else
		{
			m_PlaygroundID = 0;
			m_Map.GetImageSize( 0, m_MapSourceXSize, m_MapSourceYSize );
		}
		
		for( int i = 0; i < m_TeammateIDs.Count(); i++ )
		{
			AddTeammate( m_TeammateIDs.Get( i ), i );
		}
		
		CreateStaticIcons();
		OnPhaseChange( SgSClientGame.GetGameState(), SgSClientGame.GetLocationType() );
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	void AddTeammate( string player_uid, int slot )
	{
		m_Trackers.Insert( new SgMapTracker( player_uid, m_Map, Colors.GetPlayerColorByTeamSlot( slot ) ) );
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	void AddTeamPlayer( string player_uid, int team_id )
	{
		m_Trackers.Insert( new SgMapTracker( player_uid, m_Map, Colors.GetTeamColor( team_id ) ) );
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	void SetPlayerColor( int slot )
	{
		m_Trackers.Insert( new SgMapTracker( SgSClientGame.GetPlayerUID(), m_Map, Colors.GetPlayerColorByTeamSlot( slot ) ) );
	}

	override void OnShow()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if( player && player.m_Hud )
			player.m_Hud.Show( false );
		
		PPEffects.SetBlur(1);
		
		LockControls();
		OnPhaseChange( SgSClientGame.GetGameState(), SgSClientGame.GetLocationType() );
	}
	
	override void OnHide()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if( player && player.m_Hud )
			player.m_Hud.Show( true );
		
		PPEffects.SetBlur(0);
		
		UnlockControls();
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	void SyncEvent_OnGamePhaseChanged( ESgGameState game_state, ESgLocationType location_type, int duration_time, vector currentPhasePosition )
	{
		OnPhaseChange( game_state, location_type );
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */	
	void OnPhaseChange( ESgGameState game_state, ESgLocationType location )
	{
		switch( location )
		{
			case ESgLocationType.PhaseStart:
			{
				if( game_state == ESgGameState.Phase )
				{
					m_Map.FindAnyWidget( "ZoneOverlay1Overlay" ).Show( true );
					m_Map.FindAnyWidget( "ZoneOverlay1Off" ).Show( true );
				}
				break;
			}
			case ESgLocationType.PhaseFirst:
			{
				if( game_state == ESgGameState.Phase )
				{
					m_Map.FindAnyWidget( "ZoneOverlay1On" ).Show( true );
					m_Map.FindAnyWidget( "ZoneOverlay1Off" ).Show( false );
				}
				break;
			}
			case ESgLocationType.PhaseSecond:
			{
				m_Map.FindAnyWidget( "ZoneOverlay1Overlay" ).Show( false );
				m_Map.FindAnyWidget( "ZoneOverlay2Overlay" ).Show( true );
				if( game_state == ESgGameState.Phase )
				{
					m_Map.FindAnyWidget( "ZoneOverlay2On" ).Show( true );
				}
				else if( game_state == ESgGameState.Transition )
				{
					m_Map.FindAnyWidget( "ZoneOverlay2On" ).Show( false );
					m_Map.FindAnyWidget( "ZoneOverlay2Off" ).Show( true );
				}
				break;
			}
			case ESgLocationType.PhaseEnd:
			{
				m_Map.FindAnyWidget( "ZoneOverlay1Overlay" ).Show( false );
				m_Map.FindAnyWidget( "ZoneOverlay2Overlay" ).Show( false );
				m_Map.FindAnyWidget( "ZoneOverlay3Overlay" ).Show( true );
					
				vector pos = CalculateMapPosition( SgSClientGame.GetCollarDeactivator().GetPosition() );
				m_Map.FindAnyWidget( "ZoneOverlay3Overlay" ).SetPos( pos[0], pos[2] );
				break;
			}
		}
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void CreateStaticIcons()
	{
		array<string> types		= new array<string>;
		array<vector> positions	= new array<vector>;
		
		for( int i = 0; i < types.Count(); i++ )
		{
			Widget w = GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_map/" + types.Get( i ) + ".layout", m_Map );
			vector w_pos = CalculateMapPosition( positions.Get( i ) );
			w.SetPos( w_pos[0], w_pos[2] );
			m_StaticIcons.Insert( w );
		}
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	vector CalculateMapPosition( vector world_pos )
	{
		float map_x_scale, map_y_scale;
		
		/*
			The script was originally written for a texture map size of 7680px times 7680px.
			Later on the texture size was changed to 4096px times 4096px.
			The m_MapSourceXSize and m_MapSourceYSize needs to be adjusted by:
			the ratio between old and new teture sizel size = 1.06666666667
			 
		*/
		map_x_scale = 1.06666666667 / m_MapSourceXSize;
		map_y_scale = 1.06666666667 / m_MapSourceYSize;

		float x = world_pos[0] * map_x_scale;
		float y = world_pos[2] * map_y_scale;
		
		vector map_pos = "0 0 0";
		map_pos[0] = x;
		map_pos[2] = y;
		return map_pos;
	}
	
	override bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		if( w == m_Map )
		{
			m_Dragging = true;
			float x_f, y_f;
			m_Map.GetPos( x_f, y_f );
			m_DragXOffset = x - x_f;
			m_DragYOffset = y - y_f;
			return true;
		}
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( w == m_Map )
		{
			m_Dragging = false;
			m_DragXOffset = 0;
			m_DragYOffset = 0;
			return true;
		}
		return false;
	}
	
	override bool OnMouseButtonUp(Widget w, int x, int y, int button)
	{
		m_Dragging = false;
		m_DragXOffset = 0;
		m_DragYOffset = 0;
		return true;
	}
	
	void UpdateMapZoom( float timeslice )
	{
			//TODO smooth zooming
	}
	
	override void Update( float timeslice )
	{
		UpdateMapZoom( timeslice );
		if( m_Dragging )
		{
			int x, y;
			GetMousePos( x, y );
			int x_offset	= x - m_DragXOffset;
			int y_offset	= y - m_DragYOffset;
			
			float x_f, y_f, x_f_p, y_f_p;
			m_Map.GetScreenSize( x_f, y_f );
			m_Map.GetParent().GetScreenSize( x_f_p, y_f_p );
			x_f = x_f - x_f_p;
			y_f = y_f - y_f_p;
			//Print( "x_f:" + x_f + "," + "y_f:" + y_f );
			x_offset = Math.Clamp( x_offset, -x_f, 0 );
			y_offset = Math.Clamp( y_offset, -y_f, 0 );
			//Print( "x:" + x_offset + "," + "y:" + y_offset );
			m_Map.SetPos( x_offset, y_offset );
		}
		
		foreach( SgMapTracker tracker : m_Trackers )
		{
			tracker.UpdateTracker();
		}
		
		if( GetGame().GetInput().LocalPress( "UAUIBack", false ) )
		{
			GetGame().GetUIManager().HideScriptedMenu( SgSManagerGui.GetMap() );
		}
	}
	
	
	void InitMapSize()
	{
		float parent_width, parent_height;
		m_Map.GetParent().GetScreenSize( parent_width, parent_height );
		
		m_Map.SetSize( parent_width, parent_width );
	}
	
	override bool OnMouseWheel(Widget  w, int x, int y, int wheel)
	{
		if( w == m_Map )
		{
			float map_parent_pos_x, map_parent_pos_y;
			float map_parent_width, map_parent_height;
			m_Map.GetParent().GetScreenPos( map_parent_pos_x, map_parent_pos_y );
			m_Map.GetParent().GetScreenSize( map_parent_width, map_parent_height );
			int mouse_x = x - map_parent_pos_x;
			int mouse_y = y - map_parent_pos_y;
			
			float zoom_change = wheel * m_ZoomSpeed;
			float zoom_factor = 1 + zoom_change;
			
			float last_map_width, last_map_height;
			float map_new_width, map_new_height, map_x_pos, map_y_pos;
			
			m_Map.GetScreenSize( last_map_width, last_map_height );
			m_Map.GetScreenPos( map_x_pos, map_y_pos );
			
			map_new_width = last_map_width * zoom_factor;
			map_new_height = last_map_height * zoom_factor;
			
			map_new_width = Math.Clamp( map_new_width, map_parent_width, map_parent_width * 5 );
			map_new_height = Math.Clamp( map_new_height, map_parent_width, map_parent_width * 5 );
			
			if ( map_new_width > 4096 || map_new_height > 4096 ) // Hot Fix for Unlimited Zoom In
			{
				return false;
			}
			
			float map_mouse_x = -map_x_pos + mouse_x;
			float map_mouse_relative_x = map_mouse_x / last_map_width;
			float relative_offset_x = map_mouse_relative_x * zoom_change;
			float map_x_offset = last_map_width * relative_offset_x;
			float map_new_x = map_x_pos - map_x_offset;
			
			float map_mouse_y = -map_y_pos + mouse_y;
			float map_mouse_relative_y = map_mouse_y / last_map_height;
			float relative_offset_y = map_mouse_relative_y * zoom_change;
			float map_y_offset = last_map_height * relative_offset_y;
			float map_new_y = map_y_pos - map_y_offset;
			
			map_new_x = Math.Clamp( map_new_x, -map_new_width, 0 );
			map_new_y = Math.Clamp( map_new_y, -map_new_height, 0 );
			
			m_Map.SetSize( map_new_width, map_new_height );
			m_Map.SetPos( map_new_x, map_new_y );
			return false;
		}
		return true;
	}
}

class SgMapTracker
{
	protected ImageWidget	m_Map;
	
	protected string			m_TeamMateId;
	protected SgPlayerClient	m_TeamMate;
	protected Widget			m_WgtTracker;
	protected ImageWidget		m_WgtIcon;
	
	protected int				m_MapSourceXSize;
	protected int				m_MapSourceYSize;
	
	void SgMapTracker( string player_uid, ImageWidget root, int color )
	{
		m_TeamMateId	= player_uid;
		m_Map			= root;
		
		m_WgtTracker	= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_map/sg_player_icon.layout", root );
		m_WgtIcon		= ImageWidget.Cast( m_WgtTracker.FindAnyWidget( "Icon" ) );
		m_WgtIcon.SetColor( color );
		m_WgtIcon.SetAlpha( 1 );
		
		root.GetImageSize( 0, m_MapSourceXSize, m_MapSourceYSize );
	}
	
	SgPlayerClient GetTeamMate()
	{
		if( !m_TeamMate )
		{
			m_TeamMate = SgSClientGame.GetPlayerByUID( m_TeamMateId );
		}
		
		return m_TeamMate;
	}
	
	void UpdateTracker()
	{
		if( GetTeamMate() )
		{
			m_WgtTracker.Show( true );
			vector teammate_pos	= GetTeamMate().GetPosition();
			vector teammate_rot	= GetTeamMate().GetDirection();
			teammate_pos		= CalculateMapPosition( teammate_pos );
			m_WgtTracker.SetPos( teammate_pos[0], teammate_pos[2] );
			//m_WgtTracker.SetRotation( 0, 0, teammate_rot[2] );
			
		}
		else
		{
			m_WgtTracker.Show( false );
		}
	}
	
	vector CalculateMapPosition( vector world_pos )
	{
		float map_x_scale, map_y_scale;
		
		/*
			The script was originally written for a texture map size of 7680px times 7680px.
			Later on the texture size was changed to 4096px times 4096px.
			The m_MapSourceXSize and m_MapSourceYSize needs to be adjusted by:
			the ratio between old and new teture sizel size = 1.06666666667
			 
		*/
		
		map_x_scale = 1.06666666667 / m_MapSourceXSize;
		map_y_scale = 1.06666666667 / m_MapSourceYSize;

		float x = world_pos[0] * map_x_scale;
		float y = world_pos[2] * map_y_scale;
		
		vector map_pos = "0 0 0";
		map_pos[0] = x;
		map_pos[2] = y;
		return map_pos;
	}
}
