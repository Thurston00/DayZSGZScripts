// DESIGN_ID: 0001

typedef array<ref SgNetDataMatchPlayer> SgNetDataMatchPlayerArray;

/*
	SG network server response data class. It is used when server loads a match. 
*/
class SgNetServerDataMatchLoadResponse
{
	private string m_MatchId;
	private ref SgNetDataMatchPlayerArray m_PlayerList;
	
	// --------------------------------
	// GETTERS
	string GetMatchId()
	{
		return m_MatchId;
	}
	
	array<ref SgNetDataMatchPlayer> GetPlayerList()
	{
		return m_PlayerList;
	}
}