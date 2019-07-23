class SgLootGamePG
{
	ref map<ESgLocationType, ref SgLootGameLocation> m_LootLocations;
	
	void Init(ESgLocationType location)
	{		
		if ( !m_LootLocations )
		{
			m_LootLocations = new map<ESgLocationType, ref SgLootGameLocation>();
		}
		
		if ( !m_LootLocations.Contains( location ) )
		{
			m_LootLocations.Insert( location, new SgLootGameLocation() );
		}
	}
}