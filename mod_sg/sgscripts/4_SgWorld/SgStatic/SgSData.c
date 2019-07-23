class SgData
{	
	protected static ref map<string, ref SgDataBuilding> m_DataBuildings;
	
	//=============================
	// LoadDataBuildings
	//=============================
	static string GetDataFolderPath()
	{
		return "mod_sg\\SgEditor\\SgLoot";
	}
	
	//=============================
	// LoadDataBuildings
	//=============================
	static void LoadDataBuildings()
	{
		
	}
	
	//=============================
	// BuidingHasData
	//=============================
	static bool HasBuildingData(string building_name)
	{
		return FileExist( GetDataFolderPath()+"\\"+building_name+".loot" );
	}
	
	//=============================
	// GetBuildingData
	//=============================
	static SgDataBuilding GetBuildingData(string building_name)
	{
		if( !m_DataBuildings )
		{
			m_DataBuildings = new map<string, ref SgDataBuilding>;
		}
		
		ref SgDataBuilding data_building = m_DataBuildings.Get( building_name );
		
		if( data_building )
		{
			return data_building;
		}
		else if ( HasBuildingData(building_name) )
		{
			FileSerializer file = new FileSerializer();
			
			string file_path = GetDataFolderPath()+"\\"+building_name+".loot";
			
			if ( file.Open( file_path, FileMode.READ ) )
			{
				file.Read( data_building );
				file.Close();
//Print("GetBuildingData => Load "+ building_name +" type => "+ data_building.GetBuildingType());
			}
		}
		else
		{
//Print("GetBuildingData => New Empty None "+ building_name);		
			data_building = new SgDataBuilding(building_name)
		}
		data_building.SetObjectType(building_name);
		m_DataBuildings.Insert( building_name, data_building );
		return data_building;
	}
	
	//=============================
	// SaveBuildingData
	//=============================
	static void SaveBuildingData(SgDataBuilding data_building)
	{
		FileSerializer file = new FileSerializer();
		
		string data_path =	GetDataFolderPath() +"\\"+ data_building.GetObjectType() +".loot";
		
		if ( file.Open( data_path, FileMode.WRITE ) )
		{
			file.Write( data_building );
			file.Close();
		}
	}
		
	//=============================
	// GetBuildingColor
	//=============================
	static int GetBuildingColor(Object obj)
	{
		if ( HasBuildingData( obj.GetType() ) )
		{
			SgDataBuilding building = GetBuildingData( obj.GetType() );
			ESgBuildingType building_type = building.GetBuildingType();
			
			switch ( building_type )
			{
				case ESgBuildingType.None:
				{
					return ARGB(80, 255, 255, 255);
				}
				case ESgBuildingType.Civil_1:
				{
					return ARGB(80, 90, 70, 120);
				}
				case ESgBuildingType.Civil_2:
				{
					return ARGB(80, 170, 70, 120);
				}
				case ESgBuildingType.Civil_3:
				{
					return ARGB(80, 255, 1, 120);
				}
				case ESgBuildingType.Garage:
				{
					return ARGB(80, 150, 150, 150);
				}
				case ESgBuildingType.GarageBig:
				{
					return ARGB(80, 0, 255, 255);
				}
				case ESgBuildingType.Hospital:
				{
					return ARGB(80, 255, 0, 0);
				}
				case ESgBuildingType.Holy:
				{
					return ARGB(80, 255, 70, 50);
				}
				case ESgBuildingType.PoliceStation:
				{
					return ARGB(80, 0, 176, 240);
				}
				case ESgBuildingType.FireStation:
				{
					return ARGB(80, 220, 100, 10);
				}
				case ESgBuildingType.Military:
				{
					return ARGB(80, 120, 150, 50);
				}
				case ESgBuildingType.Hunting:
				{
					return ARGB(80, 150, 140, 80);
				}
				case ESgBuildingType.ConstructionSite:
				{
					return ARGB(80, 200, 200, 30);
				}
				case ESgBuildingType.Structure:
				{
					return ARGB(80, 255, 255, 255);
				}
				case ESgBuildingType.Car:
				{
					return ARGB(80, 1, 1, 100);
				}
				case ESgBuildingType.School:
				{
					return ARGB(80, 255, 255, 0);
				}
				case ESgBuildingType.EditorHighlight:
				{
					return ARGB(255, 255, 50, 30);
				}
			}
		}
		return 0;
	}
}