class SgSyncGameUpdate
{	
	ref array<string>	m_PlayersUIDs;
	ref array<vector>	m_PlayersPosition;
	ref array<vector>	m_PlayersDirection;
	
	void SgSyncGameUpdate()
	{
		m_PlayersUIDs 		= new array<string>;
		m_PlayersPosition	= new array<vector>;
		m_PlayersDirection	= new array<vector>;
	}
	
	void AddPlayer( SgPlayer sg_player )
	{
		m_PlayersUIDs.Insert( sg_player.GetPlayerUID() );
		m_PlayersPosition.Insert( sg_player.GetPosition() );
		m_PlayersDirection.Insert( sg_player.GetDirection() );
	}
}