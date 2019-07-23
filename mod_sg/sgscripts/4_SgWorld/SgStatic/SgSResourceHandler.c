class SgSResourceHandler
{
	protected static const	string FOLDER_ROOT					= "mod_sg/SgPlaygrounds";
	protected static const	string FOLDER_PLAYGROUND			= FOLDER_ROOT + "/SgPlayground_";
	
	//===================================
	// PlaygroundSetupSave
	//===================================	
	static void PlaygroundSetupSave( SgJsonPlayground pg_setup )
	{		
		JsonSerializer js = new JsonSerializer();
		MakeDirectory( "mod_sg/SgPlaygrounds/SgPlayground_" + pg_setup.m_PGID );
		string file_path =	"mod_sg/SgPlaygrounds/SgPlayground_" + pg_setup.m_PGID + "/SgPgSetupData.json";
		string json_content;
		
		pg_setup.PrepareForSave();
		
		if ( js.WriteToString(pg_setup, true, json_content) )
		{
			//Print("JSON PACKS LOADED: "+ content);
			FileHandle f = OpenFile(file_path, FileMode.WRITE);
			
			if (f != 0)
			{
				FPrintln(f, json_content);
				CloseFile(f);
			}
		}
	}
	
	//===================================
	// PlaygroundSetupLoad
	//===================================
	static SgJsonPlayground PlaygroundSetupLoad( int pg_id )
	{
		ref SgJsonPlayground pg_setup = new SgJsonPlayground();
		
		string file_path =	"mod_sg/SgPlaygrounds/SgPlayground_" + pg_id + "/SgPgSetupData.json";
		FileHandle file_handle = OpenFile(file_path, FileMode.READ);
		JsonSerializer js = new JsonSerializer();
		
		string js_error = "";
		string line_content = "";
		string content = "";		
		while ( FGets( file_handle,  line_content ) >= 0 )
		{
			content += line_content;
		}
		CloseFile( file_handle );	
		
		if ( js.ReadFromString(pg_setup, content, js_error) )
		{
			//Print("JSON PACKS LOADED: "+ content);
			return pg_setup;
		}
		else
		{
			Error("JSON ERROR => PLAY GROUND LOAD [" + file_path + "]: " + js_error);
			DumpStack();
		}

		return null;
	}
	
	//===================================
	// LocationAIGroupsSpawnDataSave
	//===================================	
	static void LocationAIGroupsSpawnDataSave( int pgId, string locationName, SgJsonLocationAIGroupsSpawnData spawnData )
	{		
		JsonSerializer js = new JsonSerializer();
		
		string filePath = "mod_sg/SgPlaygrounds/SgPlayground_" + pgId + "/SgLocationAIGroupsSpawnData_" + locationName + ".json";
		string jsonContent;
		
		if ( js.WriteToString( spawnData, true, jsonContent ) )
		{
			FileHandle f = OpenFile( filePath, FileMode.WRITE );
			
			if ( f != 0 )
			{
				FPrintln( f, jsonContent );
				CloseFile(f);
			}
		}
	}
	
	//===================================
	// LocationAIGroupsSpawnDataLoad
	//===================================
	static SgJsonLocationAIGroupsSpawnData LocationAIGroupsSpawnDataLoad( int pgId, string locationName, )
	{
		ref SgJsonLocationAIGroupsSpawnData locationAIGroupsSpawnData = new SgJsonLocationAIGroupsSpawnData();
		
		string filePath = "mod_sg/SgPlaygrounds/SgPlayground_" + pgId + "/SgLocationAIGroupsSpawnData_" + locationName + ".json";
		FileHandle fileHandle = OpenFile( filePath, FileMode.READ );
		JsonSerializer js = new JsonSerializer();
		
		string jsError = "";
		string lineContent = "";
		string content = "";		
		while ( FGets( fileHandle,  lineContent ) >= 0 )
		{
			content += lineContent;
		}
		CloseFile( fileHandle );	
		
		if ( js.ReadFromString( locationAIGroupsSpawnData, content, jsError ) )
		{
			return locationAIGroupsSpawnData;
		}
		else
		{
			Error( "JSON ERROR => LOCATION AI GROUPS DATA LOAD [" + filePath + "]: " + jsError );
			DumpStack();
		}

		return locationAIGroupsSpawnData;
	}
	
	static array<ref SgJsonStartLootItem> GetStartLoot()
	{
		string pg_name = SgSManagerPlayground.GetPgName();
		
		array<ref SgJsonStartLootItem> start_loot = new array<ref SgJsonStartLootItem>;
		
		string file_path =	"mod_sg/SgPlaygrounds/" + pg_name + "/SgLoot_Start.json";
		FileHandle file_handle = OpenFile(file_path, FileMode.READ);
		JsonSerializer js = new JsonSerializer();
		
		string js_error = "";
		string line_content = "";
		string content = "";
		if ( file_handle )
		{
			while ( FGets( file_handle,  line_content ) >= 0 )
			{
				content += line_content;
			}
			CloseFile( file_handle );
			
			if ( js.ReadFromString(start_loot, content, js_error) )
			{
				return start_loot;
			}
			else
			{
				Error("JSON ERROR => GetStartLoot [SgLoot_Start.json]: "+ js_error);
				DumpStack();
			}
		}
		
		Error("SgSResourceHandler LOAD ERROR => Start loot cant load file:"+ file_path );
		
		return start_loot;
	}
	
	//===================================
	// GetAllPlaygroundSetups
	//===================================
	static array<ref SgJsonPlayground> LoadAllPlaygroundSetups()
	{
		ref array<ref SgJsonPlayground> pg_setups = new array<ref SgJsonPlayground>();
		
		string	file_name;
		int 	file_attr;
		int		flags;
		
		string path_find_pattern = "mod_sg/SgPlaygrounds/SgPlayground_*";
		FindFileHandle file_handler = FindFile(path_find_pattern, file_name, file_attr, flags);
		
		bool found = true;
		while ( found )
		{
			int pos = file_name.IndexOf("_") + 1;
			int len = file_name.Length() - pos;
			
			if ( pos > -1 && len > -1 )
			{
				int pg_id = file_name.Substring( pos, len ).ToInt();
				
				ref SgJsonPlayground pg_setup = PlaygroundSetupLoad( pg_id );
				
				if ( pg_setup )
				{
					pg_setups.Insert( pg_setup );
				}
			}
			
			found = FindNextFile(file_handler, file_name, file_attr);
		}
		
		return pg_setups;
	}
	
	static void SaveStaticCamera( int number, vector cam_pos, vector cam_ort )
	{
		JsonSerializer js = new JsonSerializer();
		string json_content;
		SgJsonStaticCamera json_static_camera = new SgJsonStaticCamera();
		
		json_static_camera.SetPosition( cam_pos );
		json_static_camera.SetOrientation( cam_ort );
		
		if ( js.WriteToString( json_static_camera, true, json_content ) )
		{
			GetGame().SetProfileString( "sgJsonStaticCamera" + number, json_content );
		}
	}

	static void LoadStaticCamera( int number, out vector cam_pos, out vector cam_ort  )
	{
		string json_content;
		string js_error = "";
		SgJsonStaticCamera json_static_camera = new SgJsonStaticCamera();
		
		JsonSerializer js = new JsonSerializer();
		GetGame().GetProfileString( "sgJsonStaticCamera" + number, json_content );
		
		if ( js.ReadFromString( json_static_camera, json_content, js_error ) )
		{
			cam_pos = json_static_camera.GetPosition();
			cam_ort = json_static_camera.GetOrientation();
		}
		else
		{
			Error("JSON ERROR => ITEM PACKS LOAD: "+ js_error);
			DumpStack();
		}
	}
	
	static void PlaygroundSetupDelete( int pg_id )
	{
		DeleteFolder( "mod_sg/SgPlaygrounds/SgPlayground_" + pg_id );
	}
	
	static void DeleteFolder( string folder_path )
	{
		string	file_name;
		int 	file_attr;
		int		flags;
		
		FindFileHandle file_handler = FindFile( folder_path + "/*", file_name, file_attr, flags );
		
		bool found = true;
		while ( found )
		{
			if( file_attr == 16 )
			{
				DeleteFile( folder_path + "/" + file_name );
			}
			else if ( file_attr == 1 )
			{
				DeleteFolder( folder_path + "/" + file_name );
				DeleteFile( folder_path + "/" + file_name );
			}
			
			Print( file_name );
			found = FindNextFile(file_handler, file_name, file_attr);
		}
		DeleteFile( folder_path );
	}
	
	//===================================
	// LoadGameServerMatchInfo
	//===================================
	static SgNetServerDataMatchLoadResponse LoadGameServerMatchInfo()
	{
		SgNetServerDataMatchLoadResponse matchInfo = new SgNetServerDataMatchLoadResponse();
		JsonSerializer js = new JsonSerializer();
		
		string js_error = "";
		string file_path = "mod_sg/Server/initData/SgForceCustomPlayers.json";
		
		FileHandle file_handle = OpenFile(file_path, FileMode.READ);
		
		string line_content;
		string content = "";
		while ( FGets( file_handle,  line_content ) >= 0 )
		{
			content += line_content;
		}
		CloseFile(file_handle);
		
		if ( !js.ReadFromString(matchInfo, content, js_error) )
		{
			Error("JSON ERROR => ProcessGameServerMatchInfo: " + js_error);
		}
		
		return matchInfo;
	}
	
	//==================================
	// LoadUpHintInfo
	//==================================
	static SgWarmUpContent LoadHintInfo()
	{
		ref SgWarmUpContent data = new SgWarmUpContent;
		
		string file_path =	"mod_sg/SgPlaygrounds/SgJsonWarmupHints.json";
		FileHandle file_handle = OpenFile(file_path, FileMode.READ);
		JsonSerializer js = new JsonSerializer();
		
		string js_error = "";
		string line_content = "";
		string content = "";		
		while ( FGets( file_handle,  line_content ) >= 0 )
		{
			content += line_content;
		}
		CloseFile( file_handle );
		
		if ( js.ReadFromString(data, content, js_error) )
		{
			//Print("JSON PACKS LOADED: "+ content);
			return data;
		}
		else
		{
			Error("JSON ERROR => HINT DATA NOT LOAD FAILED: [Warmup_Hints.json]: "+ js_error);
			DumpStack();
		}
		
		return null;
	}
}
