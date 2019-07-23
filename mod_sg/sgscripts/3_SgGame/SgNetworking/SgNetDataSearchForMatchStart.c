// DESIGN_ID: 0001 

/*
	- "Pseudo Abstract" class for starting a game search 
	- NOTE: Apparently there is not a server response yet
*/
class SgNetDataSearchForGameStart {}

/*
	- SG network request data class for server to start looking for a match game
*/
class SgNetDataSearchForMatchStartRequest extends SgNetDataSearchForGameStart
{
	private SgEGameMode 	m_GameMode;
	private SgETeamSize 	m_TeamSize;
	private bool 			m_FillTeam;
	private array<string> 	m_TeammatesUIDs;
	private SgERegion 		m_Region;
	
	// --------------------------------
	
	void SgNetDataSearchForMatchStartRequest(SgEGameMode game_mode, SgETeamSize team_size, bool fill_team, array<string> teammates_uuids, SgERegion region)
	{
		m_GameMode		= game_mode;
		m_TeamSize 		= team_size;
		m_FillTeam 		= fill_team;
		m_TeammatesUIDs = teammates_uuids;
		m_Region = region;
	}
	
	// ----------------------------
	// SETTERS 
	
	void SetGameType(SgEGameMode game_mode)
	{
		m_GameMode = game_mode;
	}
	void SetTeamMode(SgETeamSize team_size)
	{
		m_TeamSize = team_size;
	}
	void SetFillTeam(bool fill_team)
	{
		m_FillTeam = fill_team;
	}
	void SetTeammatesUUIDs(array<string> teammates_uuids)
	{
		m_TeammatesUIDs = teammates_uuids;
	}	
	
	void SetRegion(SgERegion region)
	{
		m_Region = region;
	}
}

