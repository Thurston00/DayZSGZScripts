class SgPluginPgEditor extends PluginBase
{
	protected static SgPluginPgEditor			m_Instance;
	protected bool								m_IsPgLoaded;
	protected ref SgJsonPlayground				m_CurrentPlayground;
	protected ref array<ref SgJsonPlayground>	m_Playgrounds;
	protected ref array<string>					m_Missions;
	protected SgJsonLocation					m_EditingPGLocation;
	
	static ref ScriptInvoker Event_OnPgEditorSaved = new ScriptInvoker();
	
	void SgPluginPgEditor()
	{
		if ( m_Instance == NULL )
		{
			m_Instance = this;
		}
	}
	
	// System Events
	void ~SgPluginPgEditor()
	{
		if ( m_Instance == NULL )
		{
			m_Instance = this;
		}
	}
	
	static SgPluginPgEditor GetInstance()
	{
		return SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
	}
	
	//==========================================
	// OnInit (System Event)
	//==========================================
	override void OnInit()
	{
		if ( GetSgGame().IsMultiplayer() )
		{
			return;
		}
		
		if( SgPluginConfigPlayground.GetInstance() )
		{
			m_Playgrounds	= GetPlaygrounds();
			m_Missions		= SgPluginConfigPlayground.GetInstance().GetMissionNames();
		}
		
		InitOpenEditor(); // SG_TODO: Ivo
	}
	
	//===================================
	// InitOpenEditor
	//===================================
	void InitOpenEditor( )
	{
		if( GetSgGame().GetPlaygroundID() > -1 )
		{
			LoadPlayground( GetSgGame().GetPlaygroundID() );
			EditorToggle();
		}
		else
		{
			GetSgGame().SetPlaygroundID( PluginConfigDebugProfile.GetInstance().GetDefaultPlayground() );
			
			if ( GetSgGame().GetPlaygroundID() != -1 )
			{
				LoadPlayground( GetSgGame().GetPlaygroundID() );
			}
			EditorToggle();
		}		
	}
	
	bool IsOpened()
	{
		return GetGame().GetUIManager().GetMenu() && GetGame().GetUIManager().GetMenu().GetID() == MENU_SG_PG_EDITOR;
	}
	
	void EditorToggle()
	{
		if ( IsOpened() )
		{
			// Close UI Scene Editor Menu
			GetGame().GetUIManager().Back();
			if( DeveloperFreeCamera.IsFreeCameraEnabled() )
			{
				DeveloperFreeCamera.FreeCameraToggle( PlayerBase.Cast( GetGame().GetPlayer() ) );
			}
			FreeCameraControlEnable();
		}
		else
		{
			if( !DeveloperFreeCamera.IsFreeCameraEnabled() )
			{
				DeveloperFreeCamera.FreeCameraToggle( PlayerBase.Cast( GetGame().GetPlayer() ) );
			}
			
			// Open UI Scene Editor Menu
			GetGame().GetUIManager().EnterScriptedMenu( MENU_SG_PG_EDITOR, NULL );
			
			FreeCameraControlDisable();
		}
	}
	
	//==========================================
	// FreeCameraControlEnable
	//==========================================
	void FreeCameraControlEnable()
	{
		// Enable Camera control
		if (GetGame().GetMission())
		{
			GetGame().GetMission().PlayerControlEnable();
		}
		
		// Disable Cursor
		GetGame().GetUIManager().ShowCursor(false);
	}

	//==========================================
	// FreeCameraControlDisable
	//==========================================
	void FreeCameraControlDisable()
	{
		// Disable Camera control
		if (GetGame().GetMission())
		{
			GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		}
		
		// Enable Cursor
		GetGame().GetUIManager().ShowCursor(true);
	}
	
	void Event_OnRClick()
	{
		if( IsOpened() )
		{
			FreeCameraControlEnable();
		}
		
	}
	
	void Event_OnRClickRelease()
	{
		if( IsOpened() )
		{
			FreeCameraControlDisable();
		}
	}
	
	bool IsPgLoaded()
	{
		return m_IsPgLoaded;
	}
	
	array<ref SgJsonPlayground> GetPlaygrounds()
	{
		if( !m_Playgrounds )
		{
			m_Playgrounds = SgSResourceHandler.LoadAllPlaygroundSetups();
		}
		
		return m_Playgrounds;
	}
	
	array<string> GetMissions()
	{
		if( !m_Missions && SgPluginConfigPlayground.GetInstance() )
		{
			m_Missions = SgPluginConfigPlayground.GetInstance().GetMissionNames();
		}
		return m_Missions;
	}
	
	bool PlaygroundExists( int pg_id )
	{
		return true;
	}
	
	void CreatePlayground( string name, string mission, string description, int players, string details )
	{
		m_CurrentPlayground	= new SgJsonPlayground();
		int id = m_Playgrounds.Count();
		m_CurrentPlayground.InitNewPlayground( id, name, mission, description, details, "set:playground_thumbnails image:" + mission);
		
		SaveCurrentPlayground();
		
		LoadPlayground( m_CurrentPlayground.m_PGID );
	}
	
	SgJsonPlayground LoadPlayground( int pg_id )
	{
		m_CurrentPlayground	= SgSResourceHandler.PlaygroundSetupLoad( pg_id );
		if( m_CurrentPlayground )
		{
			GetSgGame().SetPlaygroundID( pg_id );
			if( m_CurrentPlayground.m_PGMapName != GetSgGame().GetLoadedMission() )
			{
				string mission_name	= "mod_sg\\SgEditor\\SgMissions\\MissionSP." + m_CurrentPlayground.m_PGMapName;
				GetSgGame().SetLoadedMission( m_CurrentPlayground.m_PGMapName );
				GetGame().PlayMission( mission_name );
			}
			
			if( IsOpened() )
			{
				GetGame().GetUIManager().GetMenu().Refresh();
			}
			m_IsPgLoaded	= true;
		}
		else
		{
			m_IsPgLoaded	= false;
		}
		return m_CurrentPlayground;
	}
	
	void DeletePlayground( int pg_id )
	{
		SgSResourceHandler.PlaygroundSetupDelete( pg_id );
		if( m_CurrentPlayground && m_CurrentPlayground.m_PGID == pg_id )
		{
			string mission	= "mod_sg\\SgEditor\\SgMissions\\MissionSP.SampleMap";
			GetSgGame().SetLoadedMission( m_CurrentPlayground.m_PGMapName );
			GetGame().PlayMission( mission );
		}
		else
		{
			for( int i = 0; i < m_Playgrounds.Count(); i++ )
			{
				SgJsonPlayground pg = m_Playgrounds.Get( i );
				if( pg && pg.m_PGID == pg_id )
				{
					m_Playgrounds.Remove( i );
					break;
				}
			}
		}
	}
	
	void SetDefaultPlayground( int pg )
	{
		PluginConfigDebugProfile.GetInstance().SetDefaultPlayground( pg );
	}
	
	void SaveCurrentPlayground()
	{
		if( m_CurrentPlayground )
		{
			Event_OnPgEditorSaved.Invoke();
			SgSResourceHandler.PlaygroundSetupSave( m_CurrentPlayground );
		}
	}
	
	SgJsonPlayground GetCurrentPlayground()
	{
		return m_CurrentPlayground;
	}
	
	int GetCurrentPlaygroundID()
	{
		return GetCurrentPlayground().m_PGID;
	}
	
	string GetCurrentPlaygroundName()
	{
		return "SgPlayground_"+GetCurrentPlaygroundID();
	}
	
	int GetCurrentLocationAreaID()
	{
		if ( m_EditingPGLocation )
		{
			return m_EditingPGLocation.m_AreaID;
		}
		
		return -1;
	}
	
	ESgLocationType GetCurrentLocationType()
	{
		if ( m_EditingPGLocation )
		{
			return m_EditingPGLocation.m_LocationType;
		}
		
		return ESgLocationType.None;
	}
	
	void SelectLocation( SgJsonLocation location )
	{
		m_EditingPGLocation = location;
	}
	
	string GetCurrentLocationName()
	{
		return SgPluginGameServer.GetLocationName( GetCurrentLocationType(), GetCurrentLocationAreaID() );
	}
	
	SgJsonLocation InsertLocation( ESgLocationType type )
	{
		return GetCurrentPlayground().AddNewLocation( type );
	}
	
	void StartPlacingLocation( SgJsonLocation location, vector position )
	{
		location.SetPosition( position );
	}
	
	int StartPlacingBorderPoint( SgJsonLocation location, vector position )
	{
		return location.AddBorderPoint( position );
	}
	
	vector InsertBorderPoint( SgJsonLocation location, int index )
	{
		return location.InsertBorderPoint( index );
	}
	
	void RemoveBorderPoint( SgJsonLocation location, int index )
	{
		location.RemoveBorderPoint( index );
	}
	
	void ClearBorderPoints( SgJsonLocation location )
	{
		location.ClearBorderPoints();
	}
	
	int StartPlacingEnd( SgJsonLocation location, vector pos )
	{
		return location.AddEnd( pos );
	}
	
	array<vector> StartGeneratingBorderPoints( SgJsonLocation location, float radius )
	{
		return location.GenerateBorderPoints( radius );
	}
}
