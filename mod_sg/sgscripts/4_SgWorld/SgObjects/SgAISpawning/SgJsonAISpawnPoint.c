class SgJsonAISpawnPoint
{
	protected vector	m_Position;
	
	void SgJsonAISpawnPoint(vector position)
	{
		m_Position = position;
	}
	
	void SetPosition(vector position)
	{
		m_Position = position;
	}
	
	vector GetPosition()
	{
		return m_Position;
	}
}