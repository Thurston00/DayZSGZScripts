// DESIGN_ID: 0001

/*
	SG network data class for lobby team info
*/
class SgNetDataLobbyTeam
{
	private int m_TeamId;
	private int m_PlayerCount;
	
	// ----------------------------------------
	// GETTERS
	int GetLobbyId()
	{
		return m_TeamId;
	}
	int GetPlayerCount()
	{
		return m_PlayerCount;
	}
}