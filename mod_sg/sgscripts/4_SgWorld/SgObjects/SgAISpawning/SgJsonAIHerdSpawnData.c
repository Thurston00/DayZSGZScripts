class SgJsonAIHerdSpawnData
{
	protected ESgAIGroup		 			m_AIGroup;
	protected int 							m_MinCount;
	protected int							m_MaxCount;
	protected ref array<string> 			m_EntityNames;
	protected ref array<ref SgJsonAIZone> 	m_AIZones;
	
	void SgJsonAIHerdSpawnData(ESgAIGroup sgAIGroup)
	{
		m_AIGroup		= sgAIGroup;
		m_EntityNames	= new ref array<string>;
		m_AIZones   	= new ref array<ref SgJsonAIZone>;
	}
	
	ESgAIGroup GetAIGroup()
	{
		return m_AIGroup;
	}
	
	int GetMinCount()
	{
		return m_MinCount;
	}
	
	void SetMinCount(int minCount)
	{
		m_MinCount = minCount;
	}
	
	int GetMaxCount()
	{
		return m_MaxCount;
	}
	
	void SetMaxCount(int maxCount)
	{
		m_MaxCount = maxCount;
	}
	
	ref array<string> GetEntityNames()
	{
		return m_EntityNames;
	}
	
	void AddEntityName(string entityName)
	{
		m_EntityNames.Insert(entityName);
	}
	
	void RemoveEntityName(string entityName)
	{
		m_EntityNames.RemoveItem(entityName);
	}
	
	ref array<ref SgJsonAIZone> GetAIZones()
	{
		return m_AIZones;
	}
	
	void SetAIZone(ref SgJsonAIZone aiZone)
	{
		m_AIZones.Insert(aiZone);
	}
	
	void RemoveAIZone(int index)
	{
		m_AIZones.RemoveOrdered(index);
	}
}