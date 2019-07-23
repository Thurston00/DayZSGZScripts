class SgSManagerPlayground
{	
	protected static int			m_PgID;
	protected static int			m_BiggestTeamSize = -1;
	
	protected static ref array<ref SgLocation> m_Locations;	
	
	//==================================
	// Init
	//==================================
	static void Setup( SgJsonPlayground pg_setup )
	{
		m_PgID			= pg_setup.m_PGID;
		m_Locations		= new array<ref SgLocation>;
		
		pg_setup.KeepLocations(ESgLocationType.PoICar, 1);
		pg_setup.KeepLocations(ESgLocationType.PoIHeli, 1);
		
		for ( int i = 0; i < pg_setup.m_Locations.Count(); ++i )
		{
			SgJsonLocation jsonLocation = pg_setup.m_Locations[i];
			string locationName = SgPluginGameServer.GetLocationName( jsonLocation.m_LocationType, jsonLocation.m_AreaID );
			SgJsonLocationAIGroupsSpawnData locationAIGroupsSpawnData = SgSResourceHandler.LocationAIGroupsSpawnDataLoad( pg_setup.m_PGID, locationName );
			ref SgLocation location = CreateLocationFromSetup( pg_setup.m_Locations[i], locationAIGroupsSpawnData );
			
			m_Locations.Insert( location );
		}
	}
	
	//==================================
	// GetPgID
	//==================================
	static int GetPgID()
	{
		return m_PgID;
	}
	
	//==================================
	// GetPgName
	//==================================
	static string GetPgName()
	{
		return "SgPlayground_"+ GetPgID();
	}
	
	//==================================
	// GetBiggestTeamSize
	//==================================
	static int GetBiggestTeamSize()
	{
		if ( m_BiggestTeamSize == -1 )
		{
			map<int, ref SgTeam> teams = SgSManagerPlayers.GetTeams();
			foreach ( SgTeam team : teams )
			{
				if ( team.GetPlayers().Count() > m_BiggestTeamSize )
				{
					m_BiggestTeamSize = team.GetPlayers().Count();
				}
			}
		}
		
		return m_BiggestTeamSize;
	}
	
	//==================================
	// GetLocations
	//==================================
	static array<ref SgLocation> GetLocations()
	{
		return m_Locations;
	}
	
	//==================================
	// GetActivePhaseLocation
	//==================================
	static SgLocation GetActivePhaseLocation()
	{
		if ( m_Locations )
		{
			for ( int i = 0; i < m_Locations.Count(); ++i )
			{
				if ( m_Locations[i].IsActive() )
				{
					return m_Locations[i];
				}
			}
		}
		
		return null;
	}
	
	//==================================
	// GetLocationByLocationType
	//==================================
	static SgLocation GetLocationByLocationType( ESgLocationType location_type )
	{
		if ( location_type != ESgLocationType.None && m_Locations )
		{
			for ( int i = 0; i < m_Locations.Count(); ++i )
			{
				SgLocation location = m_Locations[i];
				
				if ( location && location.GetLocationType() == location_type )
				{
					return location;
				}
			}
		}
		
		return null;
	}
	
	//----------------------------------
	// CreateLocationFromSetup
	//----------------------------------
	protected static SgLocation CreateLocationFromSetup( SgJsonLocation location_setup, SgJsonLocationAIGroupsSpawnData locationAIGroupsSpawnData )
	{
		switch ( location_setup.m_LocationType )
		{
			case ( ESgLocationType.PhaseStart ):
			{
				ref SgLocationPhaseStart loc_start = new SgLocationPhaseStart();
				loc_start.SetAreaID( location_setup.m_AreaID );
				loc_start.SetLocationType( location_setup.m_LocationType );
				loc_start.SetPosition( location_setup.m_Position );
				loc_start.SetBorderRangeMax( location_setup.m_BorderRangeMax );
				loc_start.SetBorderRangeMin( location_setup.m_BorderRangeMin );
				loc_start.SetBorderPoints( location_setup.GetBorderPositions() );
				loc_start.SetTimePhase( location_setup.m_PhaseTime );
				loc_start.SetAiSpawnData( locationAIGroupsSpawnData.m_AIHerdSpawnData );
				
				return loc_start;
			}
			case ( ESgLocationType.PhaseFirst ):
			{
				ref SgLocationPhaseFirst loc_first = new SgLocationPhaseFirst();
				loc_first.SetAreaID( location_setup.m_AreaID );
				loc_first.SetLocationType( location_setup.m_LocationType );
				loc_first.SetPosition( location_setup.m_Position );
				loc_first.SetBorderRangeMax( location_setup.m_BorderRangeMax );
				loc_first.SetBorderRangeMin( location_setup.m_BorderRangeMin );
				loc_first.SetBorderPoints( location_setup.GetBorderPositions() );
				loc_first.SetTimePhase( location_setup.m_PhaseTime );
				loc_first.SetAiSpawnData( locationAIGroupsSpawnData.m_AIHerdSpawnData );
				
				return loc_first;
			}
			case ( ESgLocationType.PhaseSecond ):
			{
				ref SgLocationPhaseSecond loc_sec = new SgLocationPhaseSecond();
				loc_sec.SetAreaID( location_setup.m_AreaID );
				loc_sec.SetLocationType( location_setup.m_LocationType );
				loc_sec.SetPosition( location_setup.m_Position );
				loc_sec.SetBorderRangeMax( location_setup.m_BorderRangeMax );
				loc_sec.SetBorderRangeMin( location_setup.m_BorderRangeMin );
				loc_sec.SetBorderPoints( location_setup.GetBorderPositions() );
				loc_sec.SetTimePhase( location_setup.m_PhaseTime );
				loc_sec.SetTimeTransition( location_setup.m_TransitionTime );
				loc_sec.SetAiSpawnData( locationAIGroupsSpawnData.m_AIHerdSpawnData );
				
				return loc_sec;
			}
			case ( ESgLocationType.PhaseEnd ):
			{
				ref SgLocationPhaseEnd loc_end = new SgLocationPhaseEnd();
				loc_end.SetAreaID( location_setup.m_AreaID );
				loc_end.SetLocationType( location_setup.m_LocationType );
				loc_end.SetPosition( location_setup.m_Position );
				loc_end.SetBorderRangeMax( 0 );
				loc_end.SetBorderRangeMin( 0 );
				loc_end.SetBorderPoints( location_setup.GetBorderPositions() );
				loc_end.SetEndPositions( location_setup.GetEndPositions() );
				loc_end.SetTimePhase( location_setup.m_PhaseTime );
				loc_end.SetTimeTransition( location_setup.m_TransitionTime );
				loc_end.SetAiSpawnData( locationAIGroupsSpawnData.m_AIHerdSpawnData );
				
				return loc_end;
			}
			case ( ESgLocationType.PoIHeli ):
			{
				ref SgLocationPoIHeli loc_poi_heli = new SgLocationPoIHeli();
				loc_poi_heli.SetAreaID( location_setup.m_AreaID );
				loc_poi_heli.SetLocationType( location_setup.m_LocationType );
				loc_poi_heli.SetPosition( location_setup.m_Position );
				loc_poi_heli.SetBorderRangeMax( location_setup.m_BorderRangeMax );
				loc_poi_heli.SetTimePhase( 0 );
				loc_poi_heli.SetAiSpawnData( locationAIGroupsSpawnData.m_AIHerdSpawnData );
				
				return loc_poi_heli;
			}
			case ( ESgLocationType.PoICar ):
			{
				ref SgLocationPoICar loc_poi_car = new SgLocationPoICar();
				loc_poi_car.SetAreaID( location_setup.m_AreaID );
				loc_poi_car.SetLocationType( location_setup.m_LocationType );
				loc_poi_car.SetPosition( location_setup.m_Position );
				loc_poi_car.SetBorderRangeMax( location_setup.m_BorderRangeMax );
				loc_poi_car.SetTimePhase( 0 );
				loc_poi_car.SetAiSpawnData( locationAIGroupsSpawnData.m_AIHerdSpawnData );
				
				return loc_poi_car;
			}
		}
		
		return null;
	}
}
