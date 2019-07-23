// Item Spawn Action
class SgMatchRecorderItemSpawnActionData
{
	protected int 									itemID; 		// SG_TODO: m_ItemID
	protected Vector2 								spawnPosition; 	// SG_TODO: m_SpawnPosition
	protected ESgLocationType						locationType; 	// SG_TODO: m_LocationType -- Old phaseIndex
	
	void SgMatchRecorderItemSpawnActionData(int itemID, Vector2 spawnPosition, ESgLocationType locationType)
	{
		this.itemID 	  	= itemID;
		this.spawnPosition 	= spawnPosition;
		this.locationType	= locationType;
	}
}