// DESIGN_ID: 0001

typedef array<ref SgNetDataLobbyTeam> SgNetDataLobbyTeamArray;
typedef array<ref SgNetDataLobbyPlayer> SgNetDataLobbyPlayerArray;

/*
	Detailed SG network data class for lobby details (basically more detailed SgNetDataLobbyInfo) 
*/
class SgNetDataLobbyDetails extends SgNetDataLobbyInfo
{
	private string m_HostPlayerName;									// Host name
	private ref SgNetDataLobbyTeamArray m_LobbyTeams;				// List of lobby teams
	private ref SgNetDataLobbyPlayerArray m_LobbyPlayers;			// List of lobby players
	
	// ----------------------------------------
	// GETTERS
	string GetHostPlayerName()
	{
		return m_HostPlayerName;
	}
	array<ref SgNetDataLobbyTeam> GetLobbyTeams()
	{
		return m_LobbyTeams;
	}
	array<ref SgNetDataLobbyPlayer> GetLobbyPlayers()
	{
		return m_LobbyPlayers;
	}
}