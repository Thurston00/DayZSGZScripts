class SgDataBuilding
{
	protected string							m_ObjectType;
	protected ref array<ref SgDataBuildingSP> 	m_SpawnPoints;
	protected ESgBuildingType					m_BuildingType;
	
	//=====================================
	// SgDataBuilding
	//=====================================
	void SgDataBuilding( string object_type )
	{
		m_ObjectType = object_type;
		m_SpawnPoints = new array<ref SgDataBuildingSP>;
		m_BuildingType = ESgBuildingType.None;
		
		SgData.SaveBuildingData(this);
	}
	
	//=====================================
	// SetObjectType
	//=====================================
	void SetObjectType( string type )
	{
		m_ObjectType = type;
		
		SgData.SaveBuildingData(this);
	}
	
	//=====================================
	// GetObjectType
	//=====================================
	string GetObjectType()
	{
		return m_ObjectType;
	}
		
	//=====================================
	// SetBuildingType
	//=====================================
	void SetBuildingType(ESgBuildingType b_type)
	{
		m_BuildingType = b_type;
		
		SgData.SaveBuildingData(this);
	}
	
	//=====================================
	// GetBuildingType
	//=====================================
	ESgBuildingType GetBuildingType()
	{
		return m_BuildingType;
	}
	
	//=====================================
	// AddPoint
	//=====================================
	SgDataBuildingSP AddSpawnPoint()
	{
		ref SgDataBuildingSP point = new SgDataBuildingSP();
		m_SpawnPoints.Insert( point );
		
		SgData.SaveBuildingData(this);
		
		return point;
	}
	
	//=====================================
	// GetSpawnPoint
	//=====================================
	SgDataBuildingSP GetSpawnPoint( int index )
	{
		if ( index < m_SpawnPoints.Count() )
		{
			return m_SpawnPoints[index];
		}
		
		return NULL;
	}
	
	//=====================================
	// RemovePoint
	//=====================================
	void RemoveSpawnPoint( SgDataBuildingSP point )
	{
		m_SpawnPoints.RemoveItem( point );
	}
	
	//=====================================
	// GetSpawnPoints
	//=====================================
	array<ref SgDataBuildingSP> GetSpawnPoints()
	{
		return m_SpawnPoints;
	}
	
	//=====================================
	// GetItemsMax
	//=====================================
	int GetItemsMax()
	{
		int count = 0; 
		
		for ( int i = 0; i < m_SpawnPoints.Count(); ++i )
		{
			count = count + m_SpawnPoints[i].GetItemsMax();
		}
		
		return count;
	}
}