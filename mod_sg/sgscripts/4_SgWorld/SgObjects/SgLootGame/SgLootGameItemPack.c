class SgLootGameItemPack
{
	string m_ItemPackName;
	int m_CountMin;
	int m_CountMax;
	int m_Count;
	
	ref array<ref SgLootGameItem> m_LootGameItems;
	
	bool SpawnItemPack(SgLootGameSP sp, SgLootGameItem spawn_item)
	{		
		vector random_dir = Math3D.GetRandomDir();
		random_dir[1] = 0;
		vector pos = sp.m_Position + (Math.RandomFloat(0, sp.m_Radius) * random_dir);
		
		return spawn_item.SpawnItem(pos, false);
	}
	
	SgLootGameItem GetRandomItem()
	{
		return m_LootGameItems.GetRandomElement();
	}
}