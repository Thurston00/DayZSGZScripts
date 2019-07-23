class SgLootBuilding
{
	protected 		Object		m_BuildingObject;
	protected ref	array<int>	m_SPFreeSpawnsLeft;
	
	void SgLootBuilding(Object obj)
	{
		m_BuildingObject = obj;
		
		m_SPFreeSpawnsLeft = new array<int>;
		
		SgDataBuilding building = SgData.GetBuildingData(obj.GetType());
		array<ref SgDataBuildingSP> sps = building.GetSpawnPoints();
		
		for ( int i = 0; i < sps.Count(); ++i )
		{
			
			m_SPFreeSpawnsLeft.Insert( sps[i].GetItemsMax() );
		}
	}
	
	int GetFreeSpawnCount()
	{
		int count = 0;
		
		for ( int i = 0; i < m_SPFreeSpawnsLeft.Count(); ++i )
		{
			count += m_SPFreeSpawnsLeft[i];
		}
		
		return count;
	}
	
	Object GetObject()
	{
		return m_BuildingObject;
	}
	
	//=====================================
	// GetFreeSP
	//=====================================
	int GetFreeSPDataIndex()
	{
		array<int> free_sp_indices = new array<int>;
		
		for ( int i = 0; i < m_SPFreeSpawnsLeft.Count(); ++i )
		{
			if ( m_SPFreeSpawnsLeft[i] > 0 )
			{
				free_sp_indices.Insert(i);
			}
		}
		
		if ( free_sp_indices.Count() > 0 )
		{
			int index = free_sp_indices[Math .RandomInt(0, free_sp_indices.Count())];
			
			return index;
		}
		
		return -1;
	}
	
	void ConsumeSpawnPosition(int ps_index)
	{
		m_SPFreeSpawnsLeft[ps_index] = m_SPFreeSpawnsLeft[ps_index] - 1;
	}
}