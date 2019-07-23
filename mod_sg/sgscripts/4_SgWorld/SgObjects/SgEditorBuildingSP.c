class SgEditorBuildingSP
{
	vector m_Position;
	float m_Radius;
	int m_ItemsMax;
	Shape m_ShapeCenter;
	Shape m_ShapeRadius;
	
	//=====================================
	// SgEditorBuildingSP
	//=====================================
	void SgEditorBuildingSP(vector v, float r)
	{
		m_Position = v;
		m_Radius = r;
		
		SPShow();
		Deselect();
	}
	
	//=====================================
	// SgEditorBuildingSP
	//=====================================
	void ~SgEditorBuildingSP()
	{
		if ( m_ShapeCenter )
		{
			m_ShapeCenter.Destroy();
			m_ShapeCenter = NULL;
		}
		
		if ( m_ShapeRadius )
		{
			m_ShapeRadius.Destroy();
			m_ShapeRadius = NULL;
		}
	}
		
	//===========================================
	// SPShow
	//===========================================
	void SPShow()
	{
		if ( m_ShapeCenter )
		{
			m_ShapeCenter.Destroy();
			m_ShapeCenter = NULL;
		}
		
		if ( m_ShapeRadius )
		{
			m_ShapeRadius.Destroy();
			m_ShapeRadius = NULL;
		}	
		
		int flags = ShapeFlags.TRANSP|ShapeFlags.NOZWRITE;
		
		if ( SgPluginEditorLoot.GetInstance().m_BuildingEditorSPXray )
		{
			flags = flags|ShapeFlags.NOZBUFFER;
		}
		
		m_ShapeRadius = Shape.CreateCylinder(0xFFFFFFFF, flags, m_Position, m_Radius, 0.1);
		m_ShapeCenter = Shape.CreateSphere(0xFFFFFFFF, flags, m_Position, 0.2);
	}
	
	void Select()
	{
		m_ShapeRadius.SetColor( ARGBF(0.6, 0.0, 0.6, 0.0) );
		m_ShapeCenter.SetColor( ARGBF(0.6, 0.0, 0.6, 0.0) );
	}
	
	void SelectPreview()
	{
		m_ShapeRadius.SetColor(  ARGBF(0.6, 0.0, 0.4, 0.2) );
		m_ShapeCenter.SetColor(  ARGBF(0.6, 0.0, 0.4, 0.2) );
	}
	
	void Deselect()
	{
		m_ShapeRadius.SetColor( ARGBF(0.6, 0.0, 0.0, 0.6) );
		m_ShapeCenter.SetColor( ARGBF(0.6, 0.0, 0.0, 0.6) );
	}
	
	void SetPosition(vector pos)
	{
		m_Position = pos;
		
		SPShow();
		Select();	
	}
	
	vector GetPosition()
	{
		return m_Position;
	}
	
	void SetRadius(float radius)
	{
		m_Radius = radius;
		
		SPShow();
		Select();
	}
	
	float GetRadius()
	{
		return m_Radius;
	}
}