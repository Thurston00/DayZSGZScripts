// Player Shoot Action
class SgMatchRecorderPlayerShootActionData
{
	protected int	 					playerID; 		// SG_TODO: m_PlayerID
	protected Vector2 					shootPosition; 	// SG_TODO: m_ShootPosition
	
	void SgMatchRecorderPlayerShootActionData(int playerID, Vector2 shootPosition)
	{
		this.playerID 		= playerID;
		this.shootPosition 	= shootPosition;
	}
}