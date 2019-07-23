// DESIGN_ID: 0001

/*
	SG network data class for base player
*/
class SgNetDataPlayer
{
	protected string m_PlayerUID;
	protected string m_SteamName;			
	protected int m_TeamId;							// -1 = unassigned
	
	// ----------------------------------------
	// GETTERS
	string GetPlayerUID()
	{
		return m_PlayerUID;
	}
	string GetSteamName()
	{
		return m_SteamName;
	}
	int GetTeamId()
	{
		return m_TeamId;
	}
}