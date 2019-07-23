class SgPlaygroundLocationsWidget extends SgSWEH
{
	protected SgJsonPlayground 													m_Playground;
	protected SgPlaygroundEditorMenu											m_Editor;
	protected SgPluginPgEditor													m_Manager;
	
	protected Widget															m_Root;
	protected Widget															m_Content;
	protected ref array<ref SgLocationSetupWidget>								m_LocationWidgets;
	protected ref map<ref SgJsonLocation, ref SgJsonLocationAIGroupsSpawnData>	m_LocationAIGroupsSpawnData;
	
	void SgPlaygroundLocationsWidget( Widget root, SgJsonPlayground pg, SgPlaygroundEditorMenu editor )
	{
		m_Playground				= pg;
		m_Editor					= editor;
		m_Manager					= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		
		m_Root						= root;
		m_Content					= m_Root.FindAnyWidget( "Content" );
		m_LocationWidgets			= new array<ref SgLocationSetupWidget>;
		m_LocationAIGroupsSpawnData = new map<ref SgJsonLocation, ref SgJsonLocationAIGroupsSpawnData>;
		
		if( pg )
		{
			InitNewPlayground( m_Playground );
		}
		
		m_Root.SetHandler( this );
	}
	
	void ~SgPlaygroundLocationsWidget()
	{
		foreach( SgLocationSetupWidget phase : m_LocationWidgets )
		{
			delete phase;
		}
		delete m_Root;
	}
	
	override void Update()
	{
		if( !m_Root.IsVisible() )
			return;
		
		foreach( SgLocationSetupWidget phase : m_LocationWidgets )
		{
			phase.Update();
		}
	}
	
	void InitNewPlayground( SgJsonPlayground pg )
	{
		m_Playground						= pg;
		array<ref SgJsonLocation> locations	= pg.m_Locations;
		
		for( int i = 0; i < locations.Count(); i++ )
		{
			SgJsonLocation location	= locations.Get( i );
			AddLocation( location );
		}
	}
	
	void AddLocation( SgJsonLocation location )
	{
		string locationName = SgPluginGameServer.GetLocationName( location.m_LocationType, location.m_AreaID );
		ref SgJsonLocationAIGroupsSpawnData locationAIGroupsSpawnData = SgSResourceHandler.LocationAIGroupsSpawnDataLoad( m_Playground.m_PGID, locationName );
		ref SgLocationSetupWidget location_widget;
		
		m_LocationAIGroupsSpawnData.Insert( location, locationAIGroupsSpawnData );
		
		switch( location.m_LocationType )
		{
			case ESgLocationType.PhaseStart:
			{
				location_widget	= new SgIntroSetupWidget( m_Content, location, m_Editor, locationAIGroupsSpawnData );
				break;
			}
			case ESgLocationType.PhaseFirst:
			{
				location_widget	= new SgStartSetupWidget( m_Content, location, m_Editor, locationAIGroupsSpawnData );
				break;
			}
			case ESgLocationType.PhaseSecond:
			{
				location_widget	= new SgMidSetupWidget( m_Content, location, m_Editor, locationAIGroupsSpawnData );
				break;
			}
			case ESgLocationType.PhaseEnd:
			{
				location_widget	= new SgEndSetupWidget( m_Content, location, m_Editor, locationAIGroupsSpawnData );
				break;
			}
			case ESgLocationType.PoIHeli:
			{
				location_widget	= new SgPoISetupWidget( m_Content, location, m_Editor, locationAIGroupsSpawnData );
				break;
			}
			case ESgLocationType.PoICar:
			{
				location_widget	= new SgPoISetupWidget( m_Content, location, m_Editor, locationAIGroupsSpawnData );
				break;
			}
		}
		
		m_LocationWidgets.Insert( location_widget );
	}
	
	void SelectPhase( int phase )
	{
		if( phase >= 0 )
		{
			for( int i = 0; i < m_LocationWidgets.Count(); i++ )
			{
				SgLocationSetupWidget fade_phase = m_LocationWidgets.Get( i );
				if( i == phase )
				{
					fade_phase.Select( true );
				}
				else
				{
					fade_phase.Select( false );
				}
			}
		}
		else
		{
			foreach( SgLocationSetupWidget phase_show : m_LocationWidgets )
			{
				phase_show.Select( false );
				phase_show.Fade( false );
			}
		}
	}
	
	void SaveLocationsAIGroupsSpawnData()
	{		
		for ( int i = 0; i < m_LocationAIGroupsSpawnData.Count(); i++ )
		{
			SgJsonLocation location = m_LocationAIGroupsSpawnData.GetKey(i);
			string locationName = SgPluginGameServer.GetLocationName( location.m_LocationType, location.m_AreaID );
			SgSResourceHandler.LocationAIGroupsSpawnDataSave( m_Playground.m_PGID, locationName, m_LocationAIGroupsSpawnData.GetElement(i) );
		}
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		return false;
	}
}