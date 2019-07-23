class SgLocationPoI : SgLocation
{	
	protected bool m_DidSendToClients = false;
	protected int m_PreviousLocationDuration;
    protected ref array<ref SgLootGameItem> loot = new array<ref SgLootGameItem>();
	
	bool GetDidSentToClients()
	{
		return m_DidSendToClients;
	}
	
	override void Event_OnGameInitialized( int pg_id )
	{
		FileSerializer file 				= new FileSerializer();
		SgLootGameLocation location_loot 	= new SgLootGameLocation();
		
		string location_name 	= SgPluginGameServer.GetLocationName( GetLocationType(), GetAreaID() );
		string data_path 		= "mod_sg/SgPlaygrounds/" + SgSManagerPlayground.GetPgName() + "/SgLoot_" + location_name + ".sg";
	
		if ( file.Open( data_path, FileMode.READ ) )
		{
			if ( file.Read( location_loot ) )
			{
				DistributeLoot( location_loot );
			}
			
			file.Close();				
		}		
	}
	
	protected void GenerateLoot()
	{
		Error("This method has to be overriden! (class SgLocationPoI, method GenerateLoot)");
	}
	
	protected void AddLootItem( string item_name )
	{
		SgLootGameItem item = new SgLootGameItem();
		item.m_ItemName = item_name;
		item.m_BuildingTypes = new array<ESgBuildingType>();
		item.m_BuildingTypes.Insert(ESgBuildingType.Military);
		
		loot.Insert(item);
	}
	
	protected void DistributeLoot( SgLootGameLocation location_loot)
	{
		GenerateLoot();
		
		for ( int i = 0; i < loot.Count(); ++i )
		{
			SgLootGameItem spawn_item = loot[i];
			SgLootGameSP sp = location_loot.m_LootSpawnPoints[ESgBuildingType.Military].GetRandomElement();
			location_loot.m_LootSpawnPoints[ESgBuildingType.Military].RemoveItem(sp);
			
			vector random_dir = Math3D.GetRandomDir();
			random_dir[1] = 0;
			vector pos = sp.m_Position + (Math.RandomFloat(0, sp.m_Radius) * random_dir);
			
			spawn_item.SpawnItem( pos, false );
		}	
	}
}

