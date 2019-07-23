class SgLootGameLocation
{
	ref map<ESgBuildingType, ref array<ref SgLootGameSP>>	m_LootSpawnPoints;
	ref array<ref SgLootGameItemPack>						m_LootItemPacks;
	
	void Init(ESgBuildingType building_type)
	{
		if ( !m_LootSpawnPoints )
		{
			m_LootSpawnPoints = new map<ESgBuildingType, ref array<ref SgLootGameSP>>();
		}
		
		if ( !m_LootSpawnPoints.Contains( building_type ) )
		{
			m_LootSpawnPoints.Insert( building_type, new array<ref SgLootGameSP> );
		}
		
		m_LootItemPacks = new ref array<ref SgLootGameItemPack>();
	}
}