class SgJsonPlayground
{	
	int								m_PGID; 			// Used by editor
	
	string							m_PGName;
	string							m_PGMapName;
	string							m_PGDescription;
	string							m_PGDetails;
	string							m_PGImage;

	ref array<ref SgJsonLocation>	m_Locations;

	SgJsonLocation GetSetupLocation(int phase_index)
	{
		return m_Locations[phase_index];
	}
	
	void PrepareForSave()
	{
		foreach( SgJsonLocation loc : m_Locations )
		{
			loc.PrepareForSave();
		}
	}
	
	void InitNewPlayground( int pg_id, string name, string mission, string description, string details, string image )
	{
		m_Locations			= new array<ref SgJsonLocation>;
		
		m_PGID				= pg_id;
		m_PGName			= name;
		m_PGMapName			= mission;
		m_PGDescription		= description;
		m_PGDetails			= details;
		m_PGImage			= image;
	}
	
	SgJsonLocation AddNewLocation( ESgLocationType type )
	{
		ref SgJsonLocation location	= new SgJsonLocation();
		bool borders_visible		= type == ESgLocationType.PhaseFirst || type == ESgLocationType.PhaseSecond;
		location.InitNewLocation( m_Locations.Count(), 0, 0, type, borders_visible );
		m_Locations.Insert( location );
		return location;
	}
	
	void KeepLocations(ESgLocationType type, int request_count)
	{
		float locations_count = 0;
		foreach ( SgJsonLocation location : m_Locations )
		{
			if ( location.m_LocationType == type) 
			{ 
				locations_count++;
			}
		}
		
		if ( locations_count <= request_count )
		{
			return;
		}
		
		float probability = 1 / locations_count;
		for ( int i = 0; i < m_Locations.Count(); i++ )
		{
			SgJsonLocation location_to_remove = m_Locations[i];
			if ( location_to_remove.m_LocationType == type )
			{
				if ( request_count > 0 )
				{
					if ( Math.RandomFloat01() < probability )
					{
						request_count--;
					}
					else if ( locations_count == request_count )
					{
						return;
					}
					else
					{
						m_Locations.RemoveItem(location_to_remove);
						i--;
					}
				}
				else
				{
					m_Locations.RemoveItem(location_to_remove);
					i--;
				}
				
				locations_count--;
			}
		}
	}
}