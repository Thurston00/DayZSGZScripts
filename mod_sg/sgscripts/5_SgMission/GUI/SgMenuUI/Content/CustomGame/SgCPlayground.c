class SgCPlayground
{
	// Static
	private static ref array<ref SgCPlayground> PLAYGROUNDS;
	
	// Data
	private int 		m_ID;					// Playground id
	private string 		m_Name;					// Playground name
	private string 		m_ImagePath;			// Playground image path 
	private string 		m_MapPath;				// Playground map path

	// -----------------------------------------
	
	// Constructor
	void SgCPlayground( int id, string name, string image_path, string map_path)
	{
		m_ID 			= id;					
		m_Name			= name;				
		m_ImagePath		= image_path;
		m_MapPath		= map_path;	
	}
	
	// ----------------------------------------
	// GETTERS
	
	int GetID()
	{
		return m_ID;
	}
	string GetName()
	{
		return m_Name;
	}
	string GetImage()
	{
		return m_ImagePath;
	}
	string GetMap()
	{
		return m_MapPath;
	}
	
	// --------------------------------------
	// STATIC
	static SgCPlayground FindPlaygroundById(SgEPlaygrounds pground_enum)
	{
		if(!PLAYGROUNDS)
		{
			LoadPlayground();
		}
		
		foreach (SgCPlayground playground : PLAYGROUNDS)
		{
			if(pground_enum == playground.GetID())
			{
				return playground;
			}
		}
		
		// Error
		SgDebug.Error("Playground not found!", "SgPlayeground" , "FindPlaygroundById");
		return null;
	}
	
	static SgCPlayground FindPlaygroundByName(string playground_name)
	{
		if(!PLAYGROUNDS)
		{
			LoadPlayground();
		}
		
		foreach (SgCPlayground playground : PLAYGROUNDS)
		{
			if(playground_name == playground.GetName())
			{
				return playground;
			}
		}
		
		// Error
		SgDebug.Error("Playground not found!", "SgPlayeground" , "FindPlaygroundById");
		return null;
	}
	
	private static void LoadPlayground()
	{		
		PLAYGROUNDS = new ref array<ref SgCPlayground>;
		PLAYGROUNDS.Insert( new SgCPlayground( SgEPlaygrounds.SEVEROGRAD, "#sg_playgrounds_severograd", "mod_sg/gui/textures/sgz_playgrounds/sgz_severograd.edds", "") );	 
	}
}

// Playground enums 
enum SgEPlaygrounds
{
	SEVEROGRAD,
}