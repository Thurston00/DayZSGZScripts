class SgSManagerLootSpawner extends PluginBase
{		
	
	//===========================================
	// StartDistribution
	//===========================================
	static void StartDistribution( string pg_name, ESgLocationType location_type, int area_id , bool stress_test = false )
	{		
		FileSerializer file = new FileSerializer();
		
		SgLootGameLocation location_loot = new SgLootGameLocation();
		
		string location_name = SgPluginGameServer.GetLocationName( location_type, area_id );
		
		string data_path = "mod_sg/SgPlaygrounds/" + pg_name + "/SgLoot_" + location_name + ".sg";
	
		if ( file.Open( data_path, FileMode.READ ) )
		{
			if ( file.Read( location_loot ) )
			{
				DistributeLocation( location_loot, stress_test );
			}
			
			file.Close();				
		}		
	}
	
	//-------------------------------------------
	// DistributeLocation
	//-------------------------------------------
	static protected void DistributeLocation( SgLootGameLocation location_loot, bool stress_test = false )
	{
		int spawned_items_count = 0;
		ref SgLootGameItemPack item_pack;
		
		for ( int j=0; j < location_loot.m_LootItemPacks.Count(); ++j )
		{
			item_pack = location_loot.m_LootItemPacks[j];			
				
			if ( item_pack.m_LootGameItems.Count() > 0 )
			{		
				if ( stress_test )
				{
					item_pack.m_Count = item_pack.m_CountMax;
				}
				else
				{			
					item_pack.m_Count = Math.RandomIntInclusive(item_pack.m_CountMin, item_pack.m_CountMax);
				}
			}
		}
		
		
		
		int i = 0;
		while ( location_loot.m_LootItemPacks.Count() > 0 )
		{
			item_pack = location_loot.m_LootItemPacks[i];
			
			if ( item_pack.m_LootGameItems.Count() > 0 )
			{				
				SgLootGameItem item = item_pack.GetRandomItem();
				
				if ( item.m_BuildingTypes.Count() > 0 )
				{
					ESgBuildingType	spawn_building_type	= item.m_BuildingTypes.GetRandomElement();
					array<ref SgLootGameSP>	sps	= location_loot.m_LootSpawnPoints[spawn_building_type];
						
					if ( sps.Count() > 0 )
					{
						SgLootGameSP sp = sps.GetRandomElement();
					
						bool spawned = item_pack.SpawnItemPack(sp, item);
		
						if ( spawned )
						{
							item_pack.m_Count -= 1;
							sp.m_LeftItems -= 1;
							
							spawned_items_count++;

Print("SgPluginLootSpawner INFO: Spawned item: "+ spawned_items_count +" ItemPack: "+ item_pack.m_ItemPackName +" ItemName: '"+ item.m_ItemName +"' BuildingType: "+ spawn_building_type +" item pack count left: "+ item_pack.m_Count);
														
							if ( item_pack.m_Count <= 0 )
							{
								location_loot.m_LootItemPacks.Remove(i);
							}
							
							if ( sp.m_LeftItems <= 0 )
							{
								sps.RemoveItem( sp );
							}
						}
						else
						{
							item_pack.m_LootGameItems.RemoveItem( item );
Error("SgPluginLootSpawner ERROR: Item: '"+ item.m_ItemName +"' is not exists in the game!" );
						}
					}
					else
					{
Print("SgPluginLootSpawner INFO: No more spawn points of building type:  ItemName: '"+ item.m_ItemName +"' BuildingType: "+ spawn_building_type +" deleting from lists!");
						// while 2 condition count if is array 0 while 2 will stop
						item.m_BuildingTypes.RemoveItem( spawn_building_type );
					}
				}
				else
				{
					item_pack.m_LootGameItems.RemoveItem( item );
Error("SgPluginLootSpawner ERROR: No more free spawn points for Item: "+ item.m_ItemName +" in ItemPack: "+ item_pack.m_ItemPackName +" Count: "+ item_pack.m_Count +"! Removing from ItemPack. Left Items in ItemPack: "+ item_pack.m_LootGameItems.Count() );
				}			
			}
			else
			{
				location_loot.m_LootItemPacks.Remove(i);
				i--;
				
Error("SgPluginLootSpawner ERROR: ItemPack: "+ item_pack.m_ItemPackName +" has no items !!! Fix it in xls");
			}
			
			i++;
			if ( i >= location_loot.m_LootItemPacks.Count() )
			{
				i = 0;
			}
		}
		
Print("SgPluginLootSpawner DONE -> Item Count: "+ spawned_items_count);
	}
	
	//===========================================
	// ConvertBuildingTypeIndex
	//===========================================
	static ESgBuildingType ConvertBuildingTypeIndex(int index)
	{
		switch ( index )
		{
			case 0:
			{
				return ESgBuildingType.None;
			}
			case 1:
			{
				return ESgBuildingType.Civil_1;
			}
			case 2:
			{
				return ESgBuildingType.Civil_2;
			}
			case 3:
			{
				return ESgBuildingType.Civil_3;
			}
			case 4:
			{
				return ESgBuildingType.Garage;
			}
			case 5:
			{
				return ESgBuildingType.GarageBig;
			}
			case 6:
			{
				return ESgBuildingType.Hospital;
			}
			case 7:
			{
				return ESgBuildingType.Holy;
			}
			case 8:
			{
				return ESgBuildingType.PoliceStation;
			}
			case 9:
			{
				return ESgBuildingType.FireStation;
			}
			case 10:
			{
				return ESgBuildingType.Military;
			}
			case 11:
			{
				return ESgBuildingType.Hunting;
			}
			case 12:
			{
				return ESgBuildingType.ConstructionSite;
			}
			case 13:
			{
				return ESgBuildingType.Structure;
			}
			case 14:
			{
				return ESgBuildingType.Car;
			}
			case 15:
			{
				return ESgBuildingType.School;
			}
			case 16:
			{
				return ESgBuildingType.EditorHighlight;
			}
		}
		
		return 0;
	}
	
	//===========================================
	// ConvertBuildingTypeToIndex
	//===========================================
	static int ConvertBuildingTypeToIndex(ESgBuildingType building_type)
	{
		switch ( building_type )
		{
			case ESgBuildingType.None:
			{
				return 0;
			}
			case ESgBuildingType.Civil_1:
			{
				return 1;
			}
			case ESgBuildingType.Civil_2:
			{
				return 2;
			}
			case ESgBuildingType.Civil_3:
			{
				return 3;
			}
			case ESgBuildingType.Garage:
			{
				return 4;
			}
			case ESgBuildingType.GarageBig:
			{
				return 5;
			}
			case ESgBuildingType.Hospital:
			{
				return 6;
			}
			case ESgBuildingType.Holy:
			{
				return 7;
			}
			case ESgBuildingType.PoliceStation:
			{
				return 8;
			}
			case ESgBuildingType.FireStation:
			{
				return 9;
			}
			case ESgBuildingType.Military:
			{
				return 10;
			}
			case ESgBuildingType.Hunting:
			{
				return 11;
			}
			case ESgBuildingType.ConstructionSite:
			{
				return 12;
			}
			case ESgBuildingType.Structure:
			{
				return 13;
			}
			case ESgBuildingType.Car:
			{
				return 14;
			}
			case ESgBuildingType.School:
			{
				return 15;
			}
			case ESgBuildingType.EditorHighlight:
			{
				return 16;
			}
		}
		
		return -1;
	}
	
	//===========================================
	// ConvertBuildingTypeToString
	//===========================================
	static string ConvertBuildingTypeToString(ESgBuildingType building_type)
	{
		switch ( building_type )
		{
			case ESgBuildingType.None:
			{
				return "None";
			}
			case ESgBuildingType.Civil_1:
			{
				return "Civil_1";
			}
			case ESgBuildingType.Civil_2:
			{
				return "Civil_2";
			}
			case ESgBuildingType.Civil_3:
			{
				return "Civil_3";
			}
			case ESgBuildingType.Garage:
			{
				return "Garage";
			}
			case ESgBuildingType.GarageBig:
			{
				return "GarageBig";
			}
			case ESgBuildingType.Hospital:
			{
				return "Hospital";
			}
			case ESgBuildingType.Holy:
			{
				return "Holy";
			}
			case ESgBuildingType.PoliceStation:
			{
				return "PoliceStation";
			}
			case ESgBuildingType.FireStation:
			{
				return "FireStation";
			}
			case ESgBuildingType.Military:
			{
				return "Military";
			}
			case ESgBuildingType.Hunting:
			{
				return "Hunting";
			}
			case ESgBuildingType.ConstructionSite:
			{
				return "ConstructionSite";
			}
			case ESgBuildingType.Structure:
			{
				return "Structure";
			}
			case ESgBuildingType.Car:
			{
				return "Car";
			}
			case ESgBuildingType.School:
			{
				return "School";
			}
			case ESgBuildingType.EditorHighlight:
			{
				return "EditorHighlight";
			}
		}
		return "Unknown";
	}
}