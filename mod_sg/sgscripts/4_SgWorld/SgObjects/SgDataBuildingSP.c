enum SgObjectSpawnsPointDir
{
	HORIZONTAL_UP,
	HORIZONTAL_DOWN,
	HORIZONTAL_LEFT,
	HORIZONTAL_RIGHT,
	VERTICAL_UP,
	VERTICAL_DOWN
}

class SgDataBuildingSP
{
	string m_Name;
	vector m_Position;
	float m_Radius;
	int m_ItemsMax;
	
	void SgDataBuildingSP()
	{
		m_Name = "Point";
		m_Position = Vector( 0, 0, 0 );
		m_ItemsMax = 2;
		m_Radius = 0.6;
	}
	
	string GetName()
	{
		return m_Name;
	}
	
	void SetName( string name )
	{
		m_Name = name;
	}
	
	vector GetPosition()
	{
		return m_Position;
	}
	
	void SetPosition( vector position )
	{
		m_Position = position;
	}
	
	float GetRadius()
	{
		return m_Radius;
	}
	
	void SetRadius(float radius)
	{
		m_Radius = radius;
	}
	
	void SetItemsMax(int count)
	{
		m_ItemsMax = count;
	}
	
	int GetItemsMax()
	{
		return m_ItemsMax;
	}
	
	vector GetRandomPosition()
	{
		vector pos = vector.Zero;
		vector random_dir = vector.Zero;
		
		random_dir[0] = Math.RandomIntInclusive(-1,1);
		random_dir[2] = Math.RandomIntInclusive(-1,1);
		random_dir = random_dir.Normalized();
		
		float offset = Math.RandomFloat(0, m_Radius);	
		
		return (random_dir * offset);
	}
}