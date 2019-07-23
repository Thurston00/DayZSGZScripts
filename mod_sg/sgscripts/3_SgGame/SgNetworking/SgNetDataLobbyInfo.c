// DESIGN_ID: 0001

/*
	SG network base data class for lobby info  
*/
class SgNetDataLobbyInfo
{
	protected string m_LobbyId;
	protected string m_LobbyName;
	protected bool m_Password;						// If the lobby has a password
	protected SgEGameMode m_GameMode;				// Mode of game
	protected int m_PlayerMax;						// Maximum count of players
	protected SgETeamSize m_TeamSize;				// Team size type (solo, duo ... )
	protected int m_PlayerSlotMax;					// Maximal player slot for the lobby
	protected int m_PlayerSlotUsed;					// Current available empty player slots
	protected int m_PlaygroundId;					// Playground
	
	// ----------------------------------------
	// GETTERS
	string GetLobbyId()
	{
		return m_LobbyId;
	}
	string GetLobbyName()
	{
		return m_LobbyName;
	}	
	bool GetPassword()
	{
		return m_Password;
	}
	SgEGameMode GetGameMode()
	{
		return m_GameMode;
	}
	int GetPlayerMax()
	{
		return m_PlayerMax;
	}
	SgETeamSize GetTeamSize()
	{
		return m_TeamSize;
	}
	int GetPlayerSlotMax()
	{
		return m_PlayerSlotMax;
	}
	int GetPlayerSlotUsed()
	{
		return m_PlayerSlotUsed;
	}
	int GetPlaygroundId()
	{
		return m_PlaygroundId;
	}
}