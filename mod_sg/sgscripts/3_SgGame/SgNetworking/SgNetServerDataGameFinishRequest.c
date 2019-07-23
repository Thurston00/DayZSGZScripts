// DESIGN_ID: 0001

typedef map<int,ref SgNetDataTeamResult> SgNetDataTeamResultMap;

/*
	SG network server request data class. It is used to finish the game match. 
*/
class SgNetServerDataGameFinishRequest
{
	private ref SgNetDataTeamResultMap m_TeamResultList = new SgNetDataTeamResultMap;
	
	// --------------------------------
	// SETTERS
	void SetTeamResultList(SgNetDataTeamResultMap team_result_list)
	{
		m_TeamResultList = team_result_list;
	}
	
	// --------------------------------
	// GETTERS
	SgNetDataTeamResultMap GetTeamResultList()
	{
		return m_TeamResultList;
	}
}