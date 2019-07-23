class SgSLootGenerator
{			
	//===================================
	// LoadGameLoot
	//===================================
	protected static SgLootGamePG LoadGameLoot()
	{
		ref FileSerializer	file			= new FileSerializer();
		ref SgLootGamePG	pg_loot			= new SgLootGamePG();
		
		string pg_name = SgPluginPgEditor.GetInstance().GetCurrentPlaygroundName();
		string folder_path = "mod_sg/SgPlaygrounds/"+ pg_name +"/";
		
		if ( !FileExist(folder_path) )
		{
			MakeDirectory(folder_path);
		}
		
		string file_path = folder_path+"/SgLoot.enf";
		
		if ( file.Open( file_path, FileMode.READ ) )
		{
			file.Read( pg_loot );
		}
		
		file.Close();
		
		return pg_loot;
	}
	
	//===================================
	// SaveGameLoot
	//===================================
	static void SaveGameLoot(ESgLocationType location_type)
	{
		SgLootGameLocation location_loot = new SgLootGameLocation();
		
		map<ESgBuildingType, ref array<ref SgLootBuilding>>	loot_buildings = SgPluginEditorLoot.GetInstance().m_EditorLootBuildings;
		
		// Creating spawn points
		for ( int i = 0; i < loot_buildings.Count(); ++i )
		{
			ESgBuildingType building_type = loot_buildings.GetKey(i);
			array<ref SgLootBuilding> building_list = loot_buildings[building_type];
			
			location_loot.Init(building_type);
			
			// Buildings list
			for ( int j = 0; j < building_list.Count(); ++j )
			{
				SgLootBuilding building = building_list[j];
				
				Object				building_object		= building.GetObject();
				SgDataBuilding		data_building		= SgData.GetBuildingData(building_object.GetType());
				
				array<ref SgDataBuildingSP> building_sp_list = data_building.GetSpawnPoints();
				
				// Spawn points in building
				for ( int l = 0; l < building_sp_list.Count(); ++l )
				{
					SgDataBuildingSP building_sp = building_sp_list[l];
					
					ref SgLootGameSP sp	= new SgLootGameSP;
					sp.m_Position		= building_object.CoordToParent( building_sp.GetPosition() );
					sp.m_Radius			= building_sp.GetRadius();
					sp.m_LeftItems		= building_sp.GetItemsMax();
					
					location_loot.m_LootSpawnPoints[building_type].Insert( sp );					
				}
			}
		}
		
		string pg_name			= SgPluginPgEditor.GetInstance().GetCurrentPlaygroundName();
		string location_name	= SgPluginPgEditor.GetInstance().GetCurrentLocationName();
		
		array<ref SgJsonItemPack>	json_item_packs	= LoadJsonItemPacks(pg_name, location_type);
		array<ref SgJsonItem>		json_items		= LoadJsonItems(pg_name, location_type);
		
		/*
		for ( int a = 0; a < json_items.Count(); ++a )
		{
			Print("SgJsonItem: "+ json_items[a].m_ItemName);
		}
		*/
		
		// Creating item packs
		if ( json_item_packs && json_item_packs.Count() > 0 )
		{			
			for ( i = 0; i < json_item_packs.Count(); ++i )
			{
				SgJsonItemPack json_item_pack = json_item_packs[i];
								
				SgLootGameItemPack game_item_pack = new SgLootGameItemPack();
				
				game_item_pack.m_ItemPackName = json_item_pack.m_ItemPackName;
				game_item_pack.m_CountMin = json_item_pack.m_Min;
				game_item_pack.m_CountMax = json_item_pack.m_Max;
				
				// Creating Item List in Item Pack 
				game_item_pack.m_LootGameItems = new array<ref SgLootGameItem>();
				for ( j = 0; j < json_items.Count(); ++j )
				{
					SgJsonItem json_item = json_items[j];
					
					if ( json_item.m_ItemPackType == json_item_pack.m_ItemPackType )
					{
						// m_ItemName Creating Item Name for spawn
						SgLootGameItem loot_item = new SgLootGameItem();
						loot_item.m_ItemName = json_item.m_ItemName;
						
						// Quantity
						loot_item.m_QuantityMin = json_item.m_QuantityMin;
						loot_item.m_QuantityMax = json_item.m_QuantityMax;
						
						// Magazine
						loot_item.m_Component = json_item.m_Component;
						loot_item.m_ComponentAttach = json_item.m_ComponentAttach;
						loot_item.m_ComponentQuantityMin = json_item.m_ComponentQuantityMin;
						loot_item.m_ComponentQuantityMax = json_item.m_ComponentQuantityMax;
						
						//Print("loot_item.m_ItemName => "+ loot_item.m_ItemName +" mask: "+ json_item.m_BuildingTypeMask);
						
						// m_BuildingTypes Creating Item Building type list
						loot_item.m_BuildingTypes = new array<ESgBuildingType>();
						for ( int k = 0; k < ESgBuildingType.COUNT - 1; ++k )
						{
							ESgBuildingType data_building_type = Math.Pow(2, k);
							
							if ( k == -1 )
							{
								data_building_type = ESgBuildingType.None;
							}
							
							bool chack_mask = ((json_item.m_BuildingTypeMask & data_building_type) == data_building_type);
							
//Print( json_item.m_BuildingTypeMask.ToString() +" & "+ data_building_type.ToString() +" = "+ (json_item.m_BuildingTypeMask & data_building_type) +" => "+ chack_mask );
							
							//if ( chack_mask && location_loot.m_LootSpawnPoints[data_building_type] && location_loot.m_LootSpawnPoints[data_building_type].Count() > 0 )
							if ( chack_mask )
							{
								loot_item.m_BuildingTypes.Insert(data_building_type);
							}
						}				
						
						game_item_pack.m_LootGameItems.Insert( loot_item );
					}
				}
				
				if (  game_item_pack.m_LootGameItems.Count() == 0 )
				{
					Error("ERROR => Loot Generator = > ItemPack: " + game_item_pack.m_ItemPackName + " has no items!");
				}
				
				location_loot.m_LootItemPacks.Insert( game_item_pack );
			}			
		}
		
		// Save Loot into bin file
		
		FileSerializer file = new FileSerializer();
		
		string data_path = "mod_sg/SgPlaygrounds/" + pg_name + "/SgLoot_" + location_name + ".sg";
		
		if ( file.Open( data_path, FileMode.WRITE ) )
		{
			file.Write( location_loot );
			file.Close();
			
			Print("Loot is saved: " + data_path);
		}
		else
		{
			Error("Generate Loot Error => cant open file: " + data_path );
		}
		
		Print("Generate loot game is DONE");
	}
	
	//===================================
	// LoadJsonItemPacks
	//===================================
	static array<ref SgJsonItemPack> LoadJsonItemPacks(string pg_name, ESgLocationType location_type)
	{
		JsonSerializer js = new JsonSerializer();
		
		string js_error;
		string file_path =	"mod_sg\\SgEditor\\SgPlaygrounds\\"+ pg_name +"\\Location"+ location_type +"_ItemPacks.json";
		
		FileHandle file_handle = OpenFile(file_path, FileMode.READ);
		
		string line_content;
		string content = "";
		while ( FGets( file_handle,  line_content ) >= 0 )
		{
			content += line_content;
		}
		
		CloseFile(file_handle);
		
		array<ref SgJsonItemPack> json_packs = new array<ref SgJsonItemPack>;
		
		if ( js.ReadFromString(json_packs, content, js_error) )
		{
//Print("JSON PACKS LOADED: "+ content);
			return json_packs;
		}
		else
		{
			Error("JSON ERROR "+ file_path +" => ITEM PACKS LOAD: "+ js_error);
			DumpStack();
		}
		
		return null;
	}
	
	//===================================
	// LoadJsonItems
	//===================================
	static array<ref SgJsonItem> LoadJsonItems(string pg_name, ESgLocationType location_type)
	{
		JsonSerializer js = new JsonSerializer();
		
		string js_error;
		string file_path =	"mod_sg\\SgEditor\\SgPlaygrounds\\"+ pg_name +"\\Location"+location_type+"_Items.json";
		
		FileHandle file_handle = OpenFile(file_path, FileMode.READ);
		
		string line_content;
		string content = "";
		while ( FGets( file_handle,  line_content ) >= 0 )
		{
			content += line_content;
		}
		
		CloseFile(file_handle);
		
		array<ref SgJsonItem> json_items = new array<ref SgJsonItem>;
		
		if ( js.ReadFromString(json_items, content, js_error) )
		{
//Print("JSON ITEMS LOADED: "+ content);
//json_items.Debug();
			return json_items;
		}
		else
		{
			Error("JSON ERROR "+ file_path +" => ITEMS LOAD ERROR: "+ js_error);
			DumpStack();
		}
		
		return null;
	}
}