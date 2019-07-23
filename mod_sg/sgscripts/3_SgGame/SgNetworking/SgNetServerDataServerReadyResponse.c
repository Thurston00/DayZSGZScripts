// DESIGN_ID: 0001

/*
	SG network server response data class. It is used when server is ready for a match. 
*/
class SgNetServerDataServerReadyResponse
{
	private string m_ServerIP;
	private int m_ServerPort;
	
	// --------------------------------
	// GETTERS
	string GetServerIp()
	{
		return m_ServerIP;
	}
	int GetServerPort()
	{
		return m_ServerPort;
	}
}