class SgSyncData
{	
	ref array<int>				m_Int;
	ref array<float>			m_Float;
	ref array<string>			m_String;
	ref array<vector>			m_Vector;
	ref SgCasterGuiData			m_CasterData;
	ref SgSyncReconnected		m_DataReconnected;
	ref SgSyncGameStarted		m_DataGameStarted;
	ref SgSyncGameUpdate		m_DataGameUpdate;
	ref SgSyncGameResultData	m_DataGameResult;
	ref SgNetDataTeamResult 	m_DataTeamResult;
	
	void SgSyncData()
	{
		m_Int		= new array<int>;
		m_Float		= new array<float>;
		m_String	= new array<string>;
		m_Vector	= new array<vector>;
	}
}