class SgJsonAIZone
{
	protected vector							m_Position;
	protected float 							m_Range;
	protected bool 								m_CanSpawn;
	protected ref array<ref SgJsonAISpawnPoint> m_SpawnPoints;
	
	void SgJsonAIZone(vector position)
	{
		SetPosition(position);
		m_Range = 10;
		m_CanSpawn = true;
		m_SpawnPoints = new ref array<ref SgJsonAISpawnPoint>;
	}
	
	void SetPosition(vector position)
	{
		m_Position = position;
	}
	
	vector GetPosition()
	{
		return m_Position;
	}
	
	void SetRange(float range)
	{
		m_Range = range;
	}
	
	float GetRange()
	{
		return m_Range;
	}
	
	void SetCanSpawn(bool canSpawn)
	{
		m_CanSpawn = canSpawn;
	}
	
	bool GetCanSpawn()
	{
		return m_CanSpawn;
	}
	
	void AddSpawnpoint(SgJsonAISpawnPoint spawnpoint)
	{
		m_SpawnPoints.Insert(spawnpoint);
	}
	
	void RemoveSpawnpoint(int index)
	{
		m_SpawnPoints.RemoveOrdered(index);
	}
	
	ref array<ref SgJsonAISpawnPoint> GetSpawnpoints()
	{
		return m_SpawnPoints;
	}
}