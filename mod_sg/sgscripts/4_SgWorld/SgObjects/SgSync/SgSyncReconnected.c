class SgSyncReconnected
{	
	int								m_PgID;
	int								m_PlayersAliveCount;
	ESgGameState					m_GameState;
	ESgLocationType					m_LocationType;
	float							m_LocationTimeLeft;
	int								m_LocationDuration;
	ref array<vector>				m_PoICarPositions;
	ref array<vector>				m_PoIHeliPositions;
	ref array<ref SgSyncPlayerInfo>	m_PlayersUIDs;
	ref array<string>				m_TeammateUIDs;
}