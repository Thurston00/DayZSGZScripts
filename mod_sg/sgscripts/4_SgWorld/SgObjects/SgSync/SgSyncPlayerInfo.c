class SgSyncPlayerInfo
{	
	string 		m_PlayerUID;
	string 		m_PlayerName;
	int			m_TeamId;
	int			m_LowBits;
	int			m_HighBits;
	
	void SgSyncPlayerInfo( string player_uid, string player_name, int team_id, int low_bits, int high_bits )
	{
		m_PlayerUID 	= player_uid;
		m_PlayerName 	= player_name;
		m_TeamId 		= team_id;
		m_LowBits 		= low_bits;
		m_HighBits 		= high_bits;
	}
}