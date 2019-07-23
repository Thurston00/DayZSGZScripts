class SgCTeamMode
{
	// Static
	private static ref array<ref SgCTeamMode> TEAM_MODES; 
	// Data
	private int 	m_ID;
	private int		m_Size;
	private string 	m_Name;

	// ---------------------------
	
	// Constructor
	private void SgCTeamMode(int id, int size, string name)
	{
		m_ID 	= id;
		m_Size	= size;
		m_Name	= name;
	}
	
	// --------------------------------------
	// GETTERS
	
	int GetID()
	{
		return m_ID;
	}
	int GetSize()
	{
		return m_Size;
	}
	string GetName()
	{
		return m_Name;
	}
	
	// --------------------------------------
	// STATIC
	
	static SgCTeamMode FindModeById(SgETeamSize team_mode_enum)
	{
		if(!TEAM_MODES)
		{
			LoadTeams();
		}
		
		foreach ( SgCTeamMode mode : TEAM_MODES )
		{
			if(team_mode_enum == mode.GetID())
			{
				return mode;
			}
		}
		
		// Error
		SgDebug.Error("Team mode not found!", "SgCTeamMode" , "FindModeById");
		return null;
	}
	
	static SgCTeamMode FindModeBySize(int  team_size)
	{
		if(!TEAM_MODES)
		{
			LoadTeams();
		}
		
		foreach ( SgCTeamMode mode : TEAM_MODES )
		{
			if(team_size == mode.GetSize())
			{
				return mode;
			}
		}
		
		// Error
		SgDebug.Error("Team mode not found!", "SgCTeamMode" , "FindModeById");
		return null;
	}
	
	private static void LoadTeams()
	{
		TEAM_MODES = new ref array<ref SgCTeamMode>;	 
		TEAM_MODES.Insert( new SgCTeamMode( SgETeamSize.CUSTOM,	0, "#sg_menu_lobby_custom" ) );	 
		TEAM_MODES.Insert( new SgCTeamMode( SgETeamSize.SOLO,	1, "#sg_menu_lobby_solo" ) );	 
		TEAM_MODES.Insert( new SgCTeamMode( SgETeamSize.DUO, 	2, "#sg_menu_duo" ) );	 
		TEAM_MODES.Insert( new SgCTeamMode( SgETeamSize.SQUAD, 	4, "#sg_menu_squad" ) );	 
	}
}