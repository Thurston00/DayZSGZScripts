class SgEditorBuilding
{
		Object							m_Object;
		Shape							m_BBoxShape;
	ref array<ref SgEditorBuildingSP>	m_SPShapes;
	
	//=====================================
	// SgEditorBuilding
	//=====================================
	void SgEditorBuilding(Object obj)
	{
		m_Object = obj;
		m_SPShapes = new array<ref SgEditorBuildingSP>;
	}
	
	void ~SgEditorBuilding()
	{
		BBoxDelete();
		delete m_SPShapes;
	}

	//===========================================
	// BBoxPreviewSelect
	//===========================================
	void BBoxPreviewSelect()
	{
		BBoxCreate(ARGBF(0.6, 0.0, 0.6, 0.0), ShapeFlags.TRANSP|ShapeFlags.NOZWRITE);
	}
	
	//===========================================
	// BBoxSelected
	//===========================================
	void BBoxSelected()
	{
		BBoxCreate(ARGBF(0.0, 0.6,0.0,0), ShapeFlags.TRANSP|ShapeFlags.NOZWRITE|ShapeFlags.WIREFRAME);
	}
	
	//===========================================
	// BBoxNormal
	//===========================================
	void BBoxNormal()
	{		
		int flags = ShapeFlags.TRANSP|ShapeFlags.NOZWRITE|ShapeFlags.WIREFRAME;

		if ( SgData.HasBuildingData(m_Object.GetType()) && SgData.GetBuildingData(m_Object.GetType()).GetBuildingType() != ESgBuildingType.None )
		{
			flags = ShapeFlags.TRANSP|ShapeFlags.NOZWRITE;
		}
		
		int color = SgData.GetBuildingColor( m_Object );
		
		BBoxCreate(color, flags);
	}
	
	//===========================================
	// BBoxDelete
	//===========================================
	void BBoxDelete()
	{
		if ( m_BBoxShape != NULL )
		{
			m_BBoxShape.Destroy();
			m_BBoxShape = NULL;
		}
	}
	
	//===========================================
	// SetSPPosition
	//===========================================
	void SetSPPosition(int sp_index, vector pos)
	{
		m_SPShapes[sp_index].SetPosition(pos);
	}
	
	//===========================================
	// SetSPPosition
	//===========================================
	void SetSPRadius(int sp_index, float rad)
	{
		m_SPShapes[sp_index].SetRadius(rad);
	}
	
	//===========================================
	// GetSpawnPoints
	//===========================================
	array<ref SgEditorBuildingSP> GetSpawnPoints()
	{
		return m_SPShapes;
	}
	
	//===========================================
	// SelectSP
	//===========================================
	int SelectSP(int sp_index)
	{
		m_SPShapes[sp_index].Select();
		return sp_index;
	}
	
	//===========================================
	// SelectSP
	//===========================================
	int SelectSP( SgEditorBuildingSP sp )
	{
		int pos = m_SPShapes.Find( sp );
		m_SPShapes[pos].Select();
		return pos;
	}
	
	//===========================================
	// SelectSP
	//===========================================
	void PreviewSelectSP(int sp_index)
	{
		m_SPShapes[sp_index].SelectPreview();
	}
	
	//===========================================
	// DeselectSP
	//===========================================
	void DeselectSP(int sp_index)
	{
		if ( m_SPShapes.Count() > 0 && sp_index >= 0 && sp_index < m_SPShapes.Count() )
		{
			m_SPShapes[sp_index].Deselect();
		}
	}
	
	//===========================================
	// SpawnPointsShow
	//===========================================
	void SpawnPointsShow(SgDataBuilding building_data)
	{
		SpawnPointsHide();
		
		array<ref SgDataBuildingSP> points = building_data.GetSpawnPoints();
		
		for ( int i = 0; i < points.Count(); ++i )
		{
			ref SgDataBuildingSP point = points[i];
		
Print("SpawnPointsShow => "+ m_Object.GetPosition() + " + "+ point.GetPosition() +" = "+ (m_Object.GetPosition() + point.GetPosition()) );			
									
			m_SPShapes.Insert( new SgEditorBuildingSP(m_Object.CoordToParent( point.GetPosition() ), point.GetRadius()) );
		}		
	}
	
	//===========================================
	// SpawnPointsHide
	//===========================================
	void SpawnPointsHide()
	{
		for ( int s = 0; s < m_SPShapes.Count(); ++s )
		{
			delete m_SPShapes[s];
		}
		
		m_SPShapes.Clear();
	}
	
	//===========================================
	// BuildingBBoxAllHide
	//===========================================
	protected void BBoxCreate(int color, int flags)
	{
		BBoxDelete();
		
		vector min		= "0 0 0";
		vector max		= "0 0 0";					
		
		vector size = Vector(0,0,0);
		vector min_max[2];
			
		m_Object.GetCollisionBox(min_max);
			
		size[0] = min_max[1][0] - min_max[0][0];
		size[2] = min_max[1][2] - min_max[0][2];
		size[1] = min_max[1][1] - min_max[0][1];
		
		float width		= size[0];
		float height	= size[1];
		float length	= size[2];		
		
		float width_h = width*0.5;
		float lenght_h = length*0.5;
		
		min[0] = -width_h;
		min[1] = 0;
		min[2] = -lenght_h;
		
		max[0] = width_h;
		max[1] = height;
		max[2] = lenght_h;
						
		vector mat[4];
		m_Object.GetTransform(mat);
		
		m_BBoxShape = Shape.Create(ShapeType.BBOX, color, flags, min, max);
		m_BBoxShape.SetMatrix(mat);
	}
}