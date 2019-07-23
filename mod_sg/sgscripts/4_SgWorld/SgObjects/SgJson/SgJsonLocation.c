class SgJsonLocation
{
	int										m_AreaID;
	int										m_PhaseTime;
	int										m_TransitionTime;
	float									m_BorderRangeMin;
	float									m_BorderRangeMax;
	ESgLocationType							m_LocationType;
	bool									m_IsBorderVisible;
	
	vector									m_Position;
	ref array<vector>						m_BorderPositions;
	ref array<vector>						m_EndPositions;
	
	void InitNewLocation( int area_id, int phase_time, int transition_time, ESgLocationType type, bool is_border_visible )
	{
		m_BorderPositions	= new array<vector>;
		m_EndPositions		= new array<vector>;
		m_AreaID			= area_id;
		m_PhaseTime			= phase_time;
		m_TransitionTime	= transition_time;
		m_LocationType		= type;
		m_IsBorderVisible	= is_border_visible;
	}
	
	void InitBorderPoints( array<vector> border_points )
	{
		foreach( vector pos : border_points )
		{
			AddBorderPoint( pos );
		}
	}
	
	void PrepareForSave()
	{
		m_BorderRangeMax = 0;
		m_BorderRangeMin = 0;
		if ( m_BorderPositions.Count() > 0 )
		{
			RecalculateBorderDistances();
		}
	}
	
	void SetPosition( vector pos )
	{
		m_Position = pos;
	}
	
	vector GetPosition()
	{
		return m_Position;
	}
	
	array<vector> GetBorderPositions()
	{
		return m_BorderPositions;
	}
	
	array<vector> GetEndPositions()
	{
		return m_EndPositions;
	}
	
	int AddBorderPoint( vector position )
	{
		m_BorderPositions.Insert( position );
		return ( m_BorderPositions.Count() - 1 );
	}	
	
	void RemoveBorderPoint( int index )
	{
		if( m_BorderPositions.Count() > 3 )
			m_BorderPositions.Remove( index );
	}
	
	void ClearBorderPoints()
	{
		m_BorderPositions.Clear();
	}
	
	vector InsertBorderPoint( int index )
	{
		vector pos1, pos2;
		if( index > 0 )
		{
			pos1							= m_BorderPositions.Get( index - 1 );
		}
		else
		{
			pos1							= m_BorderPositions.Get( m_BorderPositions.Count() - 1 );
		}
		
		if( index < m_BorderPositions.Count() )
		{
			pos2							= m_BorderPositions.Get( index );
		}
		else
		{
			pos2							= m_BorderPositions.Get( 0 );
		}
		
		float distance						= vector.Distance( pos1, pos2 );
		vector direction					= vector.Direction( pos1, pos2 );
		direction.Normalize();
		vector position							= pos1 + (distance / 2 ) * direction;
		
		m_BorderPositions.InsertAt( position, index );
		
		vector v	= position;
		float dist	= vector.Distance( GetPosition(), v );
		
		if ( dist > m_BorderRangeMax )
		{
			m_BorderRangeMax = dist;
		}
		
		if ( dist < m_BorderRangeMin )
		{
			m_BorderRangeMin = dist;
		}
		
		return position;
	}

	array<vector> GenerateBorderPoints( float radius )
	{
		float antenna_density					= 150.0;
		float perimeter							= Math.PI2 * radius;
		
		int antenna_count						= perimeter / antenna_density;

		vector phase_pos						= GetPosition();
		
		for( int i = 0; i < antenna_count; i++ )
		{
			float theta = ( Math.PI2 / antenna_count );
			float angle = ( theta * i );
			float x_pos = radius * Math.Cos( angle ) + phase_pos[0];
			float y_pos = radius * Math.Sin( angle ) + phase_pos[2];
			vector position = Vector( x_pos, 0, y_pos );
			
			Print("Generate position: "+ position);
			
			SgPluginGameServer.SnapToGround( position );
			//m_BorderPositions.Insert( position );
			AddBorderPoint( position );
		}
		
		return m_BorderPositions;
	}
	
	int AddEnd( vector end_pos )
	{
		m_EndPositions.Insert( end_pos );
		return ( m_EndPositions.Count() - 1 );
	}
	
	void RecalculateBorderDistances()
	{
		m_BorderRangeMax = 0;
		m_BorderRangeMin = 100000000000;
		foreach( vector pos : m_BorderPositions )
		{
			float dist	= vector.Distance( GetPosition(), pos );
			
			int next_i = m_BorderPositions.Find(pos) + 1;
			if ( next_i == m_BorderPositions.Count() )
			{
				next_i = 0;
			}
			vector border_next = m_BorderPositions[ next_i ];
			
			float a = dist;
			float b = vector.Distance( pos, border_next );
			float c = vector.Distance( border_next, GetPosition() );
			float s = ( a + b + c ) / 2;
			float area = Math.Sqrt( s * ( s - a ) * ( s - b ) * ( s - c ) );
			float closestDist = dist;
			
			if ( b > 0 )
			{
				closestDist = (2 * area) / b;
			}
			
			if ( dist > m_BorderRangeMax )
			{
				m_BorderRangeMax = dist;
			}
			
			if ( closestDist < m_BorderRangeMin )
			{
				m_BorderRangeMin = closestDist;
			}
		}
	}
}
