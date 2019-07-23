// DESIGN_ID: 0001

typedef array<int> SkinItemArray;
typedef array<int> StartItemArray;

/*
	SG network data class for match player
*/
class SgNetDataMatchPlayer extends SgNetDataPlayer
{
	private SkinItemArray m_SkinItemIDs;
	private StartItemArray m_StartItemIDs;			
	
	// ----------------------------------------
	// GETTERS
	array<int> GetSkinItemIds()
	{
		return m_SkinItemIDs;
	}
	array<int> GetStartItemIds()
	{
		return m_StartItemIDs;
	}
}