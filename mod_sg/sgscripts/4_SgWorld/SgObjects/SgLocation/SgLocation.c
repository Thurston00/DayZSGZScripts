class SgLocation
{		
	protected int									m_AreaID;
	protected ESgLocationType						m_LocationType;
	protected float									m_BorderRangeMin;
	protected float									m_BorderRangeMax;
	protected bool									m_IsInsidePlayersCheck;
	protected int									m_TimeTransition;
	protected int									m_TimePhase;
	protected vector								m_Position;
	protected bool									m_IsPhaseActive;
	protected bool									m_LockBorder;
	
	protected ref array<vector>						m_BorderPositions;
	protected ref map<string, bool>					m_SgPlayersInside;
	protected ref array<ref SgJsonAIHerdSpawnData> 	m_AIHerdSpawnData;
	
	//===============================
	// SgLocation
	//===============================
	void SgLocation()
	{
		m_BorderPositions	= new array<vector>;
		m_SgPlayersInside	= new map<string, bool>;
		
		SgSManagerEventsServer.Event_OnGameInitialized.Insert( Event_OnGameInitialized );
	}
	
	//===============================
	// Event_OnGameInitialized
	//===============================
	void Event_OnGameInitialized( int pg_id )
	{
		Print("SgLocation Event_OnGameInitialized");
		
		SgSManagerLootSpawner.StartDistribution( SgSManagerPlayground.GetPgName(), GetLocationType(), GetAreaID() );
		SgSManagerAi.DistributeAI(m_AIHerdSpawnData);
	}
	
	//===============================
	// SetAreaID
	//===============================
	void SetAreaID( int area_id )
	{
		m_AreaID = area_id;
	}
	
	//===============================
	// GetAreaID
	//===============================
	int GetAreaID()
	{
		return m_AreaID;
	}
	
	//===============================
	// SetLocationType
	//===============================
	void SetLocationType( ESgLocationType location_type )
	{
		m_LocationType = location_type;
	}
	
	//===============================
	// GetLocationType
	//===============================
	ESgLocationType GetLocationType()
	{
		return m_LocationType;
	}
	
	//===============================
	// SetPosition
	//===============================
	void SetPosition( vector pos )
	{
		m_Position = pos;
	}
	
	//===============================
	// GetPosition
	//===============================
	vector GetPosition()
	{
		return m_Position;
	}
	
	//===============================
	// SetBorderRangeMin
	//===============================
	void SetBorderRangeMin( float range_min )
	{
		m_BorderRangeMin = range_min;
	}
	
	//===============================
	// GetBorderRangeMin
	//===============================
	float GetBorderRangeMin()
	{
		return m_BorderRangeMin;
	}
	
	//===============================
	// SetBorderRangeMax
	//===============================
	void SetBorderRangeMax( float range_max )
	{
		m_BorderRangeMax = range_max;
	}
	
	//===============================
	// GetBorderRangeMax
	//===============================
	float GetBorderRangeMax()
	{
		return m_BorderRangeMax;
	}
	
	//===============================
	// IsPhaseLocation
	//===============================
	bool IsPhaseLocation()
	{
		return false;
	}
	
	//===============================
	// SetPhaseBorderLocked
	//===============================
	void SetPhaseBorderLocked( bool lock )
	{
		m_LockBorder = lock;
	}
	
	//===============================
	// IsPhaseBorderLocked
	//===============================
	bool IsPhaseBorderLocked()
	{
		return m_LockBorder;
	}
	
	//===============================
	// Activate
	//===============================
	void Activate()
	{
		m_IsPhaseActive = true;
		
		SgSManagerEventsServer.Event_OnLocationActivated( this );
	}
	
	//===============================
	// Deactivate
	//===============================
	void Deactivate()
	{
		m_IsPhaseActive = false;
		
		SgSManagerEventsServer.Event_OnLocationDeactivated( this );
	}
	
	//===============================
	// IsActive
	//===============================
	bool IsActive()
	{
		return m_IsPhaseActive;
	}
	
	//===============================
	// SetTimePhase
	//===============================
	void SetTimePhase( int time )
	{
		m_TimePhase = time;
	}
	
	//===============================
	// GetTimePhase
	//===============================
	int GetTimePhase()
	{
		return m_TimePhase;
	}
	
	//===============================
	// SetTimeTransition
	//===============================
	void SetTimeTransition( int time )
	{
		m_TimeTransition = time;
	}
	
	//===============================
	// GetTimeTransition
	//===============================
	int GetTimeTransition()
	{
		return m_TimeTransition;
	}
	
	//===============================
	// SetBorderPoints
	//===============================
	void SetBorderPoints( ref array<vector> points )
	{
		for ( int i = 0; i < points.Count() ; ++i )
		{
			m_BorderPositions.Insert( points[i] );
		}
	}
	
	//===============================
	// GetBorderPositions
	//===============================
	ref array<vector> GetBorderPositions()
	{
		return m_BorderPositions;
	}
	
	//===============================
	// SetAiSpawnData
	//===============================
	void SetAiSpawnData( ref array<ref SgJsonAIHerdSpawnData> aIHerdSpawnData )
	{
		m_AIHerdSpawnData = aIHerdSpawnData;
	}
	
	/*
	http://stackoverflow.com/questions/217578/how-can-i-determine-whether-a-2d-point-is-within-a-polygon
	
	nvert: 			Number of vertices in the polygon. Whether to repeat the first vertex at the end has been discussed in the article referred above.
	vertx, verty:	Arrays containing the x- and y-coordinates of the polygon's vertices.
	testx, testy:	X- and y-coordinate of the test point.
	*/
	//====================================
	// CheckPlayersBorderCross
	//====================================
	protected void CheckPlayersBorderCross()
	{
		ref array<ref SgPlayer> players = SgSManagerPlayers.GetSgPlayers();
		
		int i, j, k;
		float vy_i,vy_j, vx_i, vx_j, testx, testy;

		int nvert = m_BorderPositions.Count();
		
		for ( k = 0; k < players.Count(); ++k )
		{
			SgPlayer sg_player = players[k];
			bool is_inside = false;
			bool check_border = true;
			
			if ( sg_player.IsAlive() )
			{
				vector player_pos = sg_player.GetPosition();
			
				if ( GetLocationType() == ESgLocationType.PhaseEnd )
				{
					is_inside = false;
					check_border = false;
				}
				
				if ( check_border && vector.Distance(GetPosition(), player_pos) < GetBorderRangeMin() )
				{
					is_inside = true;
					check_border = false;
				}
				
				if ( check_border )
				{
					j = nvert - 1;		
					for ( i = 0; i < nvert; ++i )
					{			
						vector v1 = m_BorderPositions[i];
						vector v2 = m_BorderPositions[j];
						
						vx_i = v1[0];
						vx_j = v2[0];
						vy_i = v1[2];
						vy_j = v2[2];					
				
						testx = player_pos[0];
						testy = player_pos[2];
						
						// Intersaction test
						float testx_ref = ((vx_j - vx_i) * (testy - vy_i) / (vy_j - vy_i) + vx_i);
						bool test1 = vy_i > testy;
						bool test2 = vy_j > testy;
						bool test3 = testx < testx_ref;
						bool test1_2 = test1 != test2;
						
						if ( test1_2 && test3 )
						{
							is_inside = !is_inside;
						}
						
						j = i;
					}
				}
				
				if ( !m_SgPlayersInside.Contains(sg_player.GetPlayerUID()) || m_SgPlayersInside[sg_player.GetPlayerUID()] != is_inside )
				{
					m_SgPlayersInside[sg_player.GetPlayerUID()] = is_inside;
					
					if ( is_inside )
					{
						SgSManagerEventsServer.Event_OnSgPlayerLocationEnter( sg_player );
					}
					else
					{
						SgSManagerEventsServer.Event_OnSgPlayerLocationLeave( sg_player );
					}
				}
			}
		}
	}
}
