[WorkbenchPluginAttribute( "Mod Text Search", "Text Search in Current Mod Only", "ctrl+9", "set:sgz_hud image:teammate_dead", {"ScriptEditor"} ) ]
class ModTextSearchPlugin: WorkbenchPlugin
{
	ref array<string> m_ModFiles = new array<string>;
    ScriptEditor m_module;
	string m_Result;
	
	[Attribute( "", "editbox", "Text to Search in Mod Files" )]
    string TextToSearch;
	
	[ButtonAttribute( "Find", true )]
    bool Find()
    {
		if ( TextToSearch.Length() < 3 )
		{
			Workbench.Dialog( "Error", "You need to search for text with minumum lenght of 3 characters." );
			return true;
		}
		
		m_module = Workbench.GetModule("ScriptEditor");		
		
        Workbench.SearchResources( ".c", FindFiles );
		SearchForTextInFiles();
		
		Workbench.Dialog( "Search Results", m_Result );
		
        return true;
    }
	
	[ButtonAttribute("Cancel")]
    bool Cancel()
    {
        return true;
    }
	
	override void Run()
    {
		Workbench.ScriptDialog( "Mod Text Search", "Name:", this );
	}
	
	override void Configure() 
	{
		Workbench.Dialog( "About `Mod Text Search`", "Author: Roman Roba\nVersion: 0.01" );
	}
	 
	// Logic
	
	void FindFiles( string file )
    {
		file.ToLower();
		if ( !file.Contains("mod_sg/") ) return;
		
		m_ModFiles.Insert(file);
    }
	
	void SearchForTextInFiles()
	{
		FileHandle file_handle;
		
		string text_to_search = TextToSearch;
		text_to_search.ToLower();
		
		foreach ( string file : m_ModFiles )
		{
			file_handle = OpenFile( file, FileMode.READ );
			
			int line = 0;
			string line_content = "";
			while ( FGets( file_handle, line_content ) >= 0 )
			{
				line++;
				line_content.ToLower();
				
				if ( line_content.Contains( text_to_search ) )
				{
					line_content.Replace( "	", "" );
					m_Result += file + "(" + line.ToString() + "):\n > " + line_content + "\n"; 
				}
			}
			
			CloseFile( file_handle );
		}
	}
}