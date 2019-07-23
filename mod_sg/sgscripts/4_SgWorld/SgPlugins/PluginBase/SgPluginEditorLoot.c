class SgPluginEditorLoot extends PluginBase
{	
		bool												m_IsOpen;
	ref Timer												m_TickTimer;
		SgJsonLocation										m_EditLocation;
	ref map<string, ref array<Object>>						m_BuildingsInArea;
	ref map<Object, ref SgEditorBuilding>					m_EditorBuildings;
	ref map<ESgBuildingType, ref array<ref SgLootBuilding>>	m_EditorLootBuildings;
	ref map<ESgBuildingType, int>							m_EditorLootBuildingsSP;
		bool 												m_SelectObject;	
		Object 												m_SelectedObject;
		Object												m_ObjLastPointed;
		bool												m_SelectedSPMove;
	ref SgDataBuilding										m_SelectedBuilding;
		bool												m_GUIRefresh;
		ESgLocationType										m_LocationEditing;
		bool												m_OpenLootEditor;
	float m_BuildingEditorAddHeight = 1;
	
	int m_LocationItemMax;
	
	//===========================================
	// GetInstance
	//===========================================
	static SgPluginEditorLoot GetInstance()
	{
		return SgPluginEditorLoot.Cast( GetPlugin( SgPluginEditorLoot ) );
	}
	
	//===========================================
	// SgPluginEditorLoot
	//===========================================
	override void OnInit()
	{
		m_BuildingEditorTypeEnum = new array<string>;
		m_BuildingEditorTypeEnum.Insert("None");
		m_BuildingEditorTypeEnum.Insert("Civil_1");
		m_BuildingEditorTypeEnum.Insert("Civil_2");
		m_BuildingEditorTypeEnum.Insert("Civil_3");
		m_BuildingEditorTypeEnum.Insert("Garage");
		m_BuildingEditorTypeEnum.Insert("GarageBig");
		m_BuildingEditorTypeEnum.Insert("Hospital");
		m_BuildingEditorTypeEnum.Insert("Holy");
		m_BuildingEditorTypeEnum.Insert("PoliceStation");
		m_BuildingEditorTypeEnum.Insert("FireStation");
		m_BuildingEditorTypeEnum.Insert("Military");
		m_BuildingEditorTypeEnum.Insert("Hunting");
		m_BuildingEditorTypeEnum.Insert("ConstructionSite");
		m_BuildingEditorTypeEnum.Insert("Structure");
		m_BuildingEditorTypeEnum.Insert("Car");
		m_BuildingEditorTypeEnum.Insert("School");
		m_BuildingEditorTypeEnum.Insert("EditorHighlight");
		
		m_EditorLootBuildingsSP = new map<ESgBuildingType, int>();
		
		m_BuildingEditorSPSelectionPreview = -1;
	}
	
	//===========================================
	// EditorOpenTimed
	//===========================================
	void EditorOpenTimed( SgJsonLocation location )
	{
		m_EditLocation = location;
		m_TickTimer = new Timer( CALL_CATEGORY_GUI );
		m_TickTimer.Run(0.2, this, "EditorOpen", NULL, false);
	}
	
	//===========================================
	// EditorOpen
	//===========================================
	void EditorOpen()
	{
		m_IsOpen = true;
		m_SelectObject = true;
		
		m_EditorBuildings = new map<Object, ref SgEditorBuilding>;
		if( !m_TickTimer )
		{
			m_TickTimer = new Timer();
		}
		else
		{
			m_TickTimer.Stop();
		}
		
		m_TickTimer.Run(0.1, this, "OnGUIMain", NULL, true);
		
		m_BuildingsInArea = GetBuildingsInLocation( m_EditLocation );
		
		UpdateBuildingsByType();
		
		for ( int i = 0; i < m_BuildingsInArea.Count(); ++i )
		{
			string building_type = m_BuildingsInArea.GetKey(i);
			ref array<Object> obj_array = m_BuildingsInArea.GetElement(i);
			
			for ( int j = 0; j < obj_array.Count(); ++j )
			{
				ref SgEditorBuilding editor_building = new SgEditorBuilding(obj_array[j]);
				editor_building.BBoxNormal();
				
				m_EditorBuildings.Insert(obj_array[j], editor_building);
			}
		}
		
		CountLootItemMax();
	}
	
	//===========================================
	// EditorClose
	//===========================================
	void EditorClose()
	{
		m_IsOpen = false;
		
		if ( m_TickTimer )
		{
			m_TickTimer.Stop();
		}
		
		OnGUIMain();
		
		m_EditorBuildings.Clear();
		m_BuildingsInArea.Clear();
		
		delete m_EditorBuildings;
		delete m_BuildingsInArea;
		
		if( GetGame().GetUIManager().GetMenu() && GetGame().GetUIManager().GetMenu().GetID() == MENU_SG_PG_EDITOR )
		{
			SgUISM menu = SgUISM.Cast( GetGame().GetUIManager().GetMenu() );
			menu.Show();
		}
	}
	
	//===========================================
	// IsEditorOpen
	//===========================================
	bool IsEditorOpen()
	{
		return m_IsOpen;
	}
	
	//===========================================
	// UpdateBuildingsByType
	//===========================================
	void UpdateBuildingsByType()
	{
		if ( m_EditorLootBuildings )
		{
			for ( int i = 0; i < m_EditorLootBuildings.Count(); ++i )
			{
				delete m_EditorLootBuildings[i];
			}
			delete m_EditorLootBuildings;
		}
		
		m_EditorLootBuildings = GetLootBuildingsInLocation( m_EditLocation );
	}
	
	//===========================================
	// Event_OnClick
	//===========================================
	void Event_OnClick()
	{
		if ( IsEditorOpen() )
		{
			if ( m_SelectObject )
			{
				Object obj = GetObjectFromCursor();
				
				if ( obj )
				{
					SelectBuilding( obj );
				}
			}
			else if ( m_SelectedSPMove  )
			{
				m_SelectedSPMove = false;
			}
			else if ( m_BuildingEditorSPSelectionPreview > -1 )
			{
				m_EditorBuildings[m_SelectedObject].DeselectSP( m_BuildingEditorSPSelectionLast );
				m_EditorBuildings[m_SelectedObject].SelectSP( m_BuildingEditorSPSelectionPreview );				
				
				m_BuildingEditorSPSelectionLast = m_BuildingEditorSPSelectionPreview;
				m_BuildingEditorSPSelection = m_BuildingEditorSPSelectionPreview;
				
				m_BuildingEditorSPSelectionPreview = -1;
				
				m_GUIRefresh = true;
			}
			else if ( m_SelectedObject )
			{
				SgEditorBuildingSP sp = GetSpawnPointFromCursor();
				if( sp )
				{
					Print( "Selecting SP" );
					m_EditorBuildings[m_SelectedObject].DeselectSP( m_BuildingEditorSPSelectionLast );
					
					m_BuildingEditorSPSelectionLast = m_EditorBuildings[m_SelectedObject].SelectSP( sp );
					m_BuildingEditorSPSelection = m_BuildingEditorSPSelectionLast;
					
					m_GUIRefresh = true;
				}
			}
		}		
	}
	
	//===========================================
	// SelectBuilding
	//===========================================
	void SelectBuilding(Object obj)
	{
		m_SelectedObject = obj;
		m_SelectedBuilding = SgData.GetBuildingData( obj.GetType() );
		m_SelectObject = false;
		m_BuildingEditorTypeSelection = SgSManagerLootSpawner.ConvertBuildingTypeToIndex(m_SelectedBuilding.GetBuildingType());

		BuildingBBoxAllHide();
		
		if ( obj && m_EditorBuildings.Contains(obj) )
		{
			m_EditorBuildings[obj].BBoxSelected();
			m_EditorBuildings[obj].SpawnPointsShow(m_SelectedBuilding);
		}
	}
	
	//===========================================
	// GetSelectedBuilding
	//===========================================
	SgDataBuilding GetSelectedBuilding()
	{
		return m_SelectedBuilding;
	}
	
	//===========================================
	// SelectBuilding
	//===========================================
	void DeselectBuilding()
	{
		m_EditorBuildings[m_SelectedObject].SpawnPointsHide();
		m_SelectedObject = NULL;
		m_SelectedBuilding = NULL;
		m_SelectObject = true;

		BuildingBBoxAllNormal();
	}	
	
	//===========================================
	// BuildingBBoxAllShow
	//===========================================
	void BuildingBBoxAllNormal()
	{
		for ( int i = 0; i < m_EditorBuildings.Count(); ++i )
		{
			m_EditorBuildings.GetElement(i).BBoxNormal();
		}
	}
	
	//===========================================
	// BuildingBBoxAllHide
	//===========================================
	void BuildingBBoxAllHide()
	{
		for ( int i = 0; i < m_EditorBuildings.Count(); ++i )
		{
			m_EditorBuildings.GetElement(i).BBoxDelete();
		}
	}
	
	//===========================================
	// BuildingBBoxAllHide
	//===========================================
	vector GetCursorPos()
	{
		// Direction Vector from current active Camera
		vector dir = GetGame().GetPointerDirection();
		
		// Raycast from
		vector from = FreeDebugCamera.GetInstance().GetPosition();
		// Raycast to
		vector to = from + ( dir * 10000 );   
		// Raycast out parameter
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		
		//Raycast(vector begPos, vector endPos, out vector contactPos, out vector contactDir, out int contactComponent, out set<Object> results = NULL, Object with = NULL, Object ignore = NULL,  bool sorted = false,  bool ground_only = false,  int iType = ObjIntersectView, float radius = 0.0);
		
		if ( DayZPhysics.RaycastRV(from, to, contact_pos, contact_dir, contact_component, NULL, NULL, NULL, false, false, ObjIntersectView) )   
		{
			return contact_pos;
		}
		
		return vector.Zero;
	}
	
	//===========================================
	// GetObjectFromCursor
	//===========================================
	Object GetObjectFromCursor()
	{
	// Direction Vector from current active Camera
		vector dir = GetGame().GetPointerDirection();
		
		// Raycast from
		vector from = FreeDebugCamera.GetInstance().GetPosition();
		// Raycast to
		vector to = from + ( dir * 1000 );
		// Raycast out parameter
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		ref set<Object> objects = new set<Object>;
		CollisionFlags flags = CollisionFlags.ALLOBJECTS;
		
								//(vector begPos, 	vector endPos,	out vector contactPos,	out vector contactDir, 	out int contactComponent, 	set<Object> results = NULL,	Object with = NULL,	Object ignore = NULL,	bool sorted = false,	bool ground_only = false,	int iType = ObjIntersectView,	float radius = 0.0,	CollisionFlags flags = CollisionFlags.NEARESTCONTACT);
		if ( DayZPhysics.RaycastRV(from,			to, 			contact_pos, 			contact_dir, 			contact_component, 			objects,					null,				null,					false,					false,						ObjIntersectView,				0,					flags) )
		{
			for ( int i = 0; i < objects.Count(); ++i )
			{
				if ( m_BuildingsInArea.Contains( objects.Get(i).GetType() ) )
				{
					return objects.Get(i);
				}
			}
		}
		
		return NULL;
	}
	
	//===========================================
	// GetSpawnPointFromCuros
	//===========================================
	SgEditorBuildingSP GetSpawnPointFromCursor()
	{
		vector pos = GetCursorPos();
		
		if ( m_EditorBuildings[m_SelectedObject] )
		{
			array<ref SgEditorBuildingSP> sps = m_EditorBuildings[m_SelectedObject].GetSpawnPoints();
			
			for ( int i = 0; i < sps.Count(); i++ )
			{
				SgEditorBuildingSP sp = sps[i];
				vector pos_obj = sp.GetPosition();
				//pos_obj	= GetGame().GetScreenPosRelative( pos_obj );
				//pos		= GetGame().GetScreenPosRelative( pos );
				if( WithinRange( pos, pos_obj, sp.GetRadius() ) )
				{
					Print( "SP " + i + " withing range" );
					return sp;
				}
			}
		}
		
		return null;
	}
	
	bool WithinRange( vector pos, vector obj, float range )
	{
		vector offset = obj - pos;
		
		if( offset.Length() < range )//( pos[0] >= ( obj[0] - 0.1 ) ) && ( pos[0] <= ( obj[0] + 0.1 ) ) )
		{
			Print( offset.Length() );
			return true;
		}
		return false;
	}
	
	//===========================================
	// OnUpdate
	//===========================================
	void OnUpdate()
	{
		if ( IsEditorOpen() )
		{
			if ( m_SelectedBuilding && m_SelectedBuilding.GetSpawnPoints().Count() > 0 )
			{
				if ( m_SelectedSPMove )
				{
					vector pos = GetCursorPos();
					
					m_SelectedBuilding.GetSpawnPoint(m_BuildingEditorSPSelection).SetPosition( m_SelectedObject.CoordToLocal( pos ) );
					m_EditorBuildings[m_SelectedObject].SetSPPosition(m_BuildingEditorSPSelection, pos );
				}
				else
				{
					array<ref SgEditorBuildingSP> sps = m_EditorBuildings[m_SelectedObject].GetSpawnPoints();
					
					vector cursor_pos = GetGame().GetPointerDirection();
					
					float best_dist = 0.07;
					int best_index = -1;
					
					for ( int i = 0; i < sps.Count(); ++i )
					{
						SgEditorBuildingSP sp = sps[i];
						
						vector sp_scree_pos = GetGame().GetScreenPosRelative( sp.GetPosition() );
						sp_scree_pos[0] = sp_scree_pos[0] - 0.5;
						sp_scree_pos[1] = sp_scree_pos[1] - 0.5;
						sp_scree_pos[2] = 0;
						
						float dist = vector.Distance(cursor_pos, sp_scree_pos);
						
						if ( dist < best_dist )
						{
							best_dist = dist;
							best_index = i;
						}
					}
					
					if ( best_index > -1 && best_index != m_BuildingEditorSPSelection)
					{
						m_BuildingEditorSPSelectionPreview = best_index;
						
						m_EditorBuildings[m_SelectedObject].PreviewSelectSP( m_BuildingEditorSPSelectionPreview );
					}
					else
					{
						if ( m_BuildingEditorSPSelectionPreview > -1 )
						{
							if ( m_BuildingEditorSPSelectionPreview == m_BuildingEditorSPSelection )
							{
								m_EditorBuildings[m_SelectedObject].SelectSP( m_BuildingEditorSPSelectionPreview );
							}
							else
							{
								m_EditorBuildings[m_SelectedObject].DeselectSP( m_BuildingEditorSPSelectionPreview );
							}
							
							m_BuildingEditorSPSelectionPreview = -1;							
						}
					}
				}
			}
		}
	}
	
	//===========================================
	// OnGUIMain
	//===========================================
	void OnGUIMain()
	{
		int windowPosX = 0;
		int windowPosY = 300;
		DbgUI.BeginCleanupScope();
		DbgUI.Begin("Loot Editor", windowPosX, windowPosY);
		if ( m_GUIRefresh )
		{
			m_GUIRefresh = false;
		}
		else if (m_IsOpen)
		{
			if ( m_OpenLootEditor )
			{
				OnGUILootEditor();
			}
			else if ( m_SelectedObject )
			{
				OnGUIBuildingEditor(m_SelectedObject, m_SelectedBuilding);
				
				if ( m_SelectedBuilding )
				{
					SgDataBuildingSP sp = m_SelectedBuilding.GetSpawnPoint(m_BuildingEditorSPSelection);
					
					if ( sp && !m_GUIRefresh)
					{
						OnGUISpawnPoint(sp);
					}
				}
			}
			else
			{
				if ( m_SelectObject )
				{
					if ( m_EditorLootBuildings )
					{						
						DbgUI.Text("Buildings Civil_1: "+			m_EditorLootBuildings[ESgBuildingType.Civil_1].Count());
						DbgUI.Text("ItemMax: "+						m_EditorLootBuildingsSP[ESgBuildingType.Civil_1]);
						
						DbgUI.Text("Buildings Civil_2: "+			m_EditorLootBuildings[ESgBuildingType.Civil_2].Count());
						DbgUI.Text("ItemMax: "+						m_EditorLootBuildingsSP[ESgBuildingType.Civil_2]);
						
						DbgUI.Text("Buildings Civil_3: "+			m_EditorLootBuildings[ESgBuildingType.Civil_3].Count());
						DbgUI.Text("ItemMax: "+						m_EditorLootBuildingsSP[ESgBuildingType.Civil_3]);
						
						DbgUI.Text("Buildings Garage: "+			m_EditorLootBuildings[ESgBuildingType.Garage].Count());
						DbgUI.Text("ItemMax: "+						m_EditorLootBuildingsSP[ESgBuildingType.Garage]);
						
						DbgUI.Text("Buildings GarageBig: "+			m_EditorLootBuildings[ESgBuildingType.GarageBig].Count());
						DbgUI.Text("ItemMax: "+						m_EditorLootBuildingsSP[ESgBuildingType.GarageBig]);
						
						DbgUI.Text("Buildings Hospital: "+			m_EditorLootBuildings[ESgBuildingType.Hospital].Count());
						DbgUI.Text("ItemMax: "+						m_EditorLootBuildingsSP[ESgBuildingType.Hospital]);
						
						DbgUI.Text("Buildings Holy: "+				m_EditorLootBuildings[ESgBuildingType.Holy].Count());
						DbgUI.Text("ItemMax: "+						m_EditorLootBuildingsSP[ESgBuildingType.Holy]);
						
						DbgUI.Text("Buildings PoliceStation: " + 	m_EditorLootBuildings[ESgBuildingType.PoliceStation].Count());
						DbgUI.Text("ItemMax: " +					m_EditorLootBuildingsSP[ESgBuildingType.PoliceStation]);
						
						DbgUI.Text("Buildings FireStation: " + 		m_EditorLootBuildings[ESgBuildingType.FireStation].Count());
						DbgUI.Text("ItemMax: " +					m_EditorLootBuildingsSP[ESgBuildingType.FireStation]);
						
						DbgUI.Text("Buildings Military: " + 		m_EditorLootBuildings[ESgBuildingType.Military].Count());
						DbgUI.Text("ItemMax: " +					m_EditorLootBuildingsSP[ESgBuildingType.Military]);
						
						DbgUI.Text("Buildings Hunting: " + 			m_EditorLootBuildings[ESgBuildingType.Hunting].Count());
						DbgUI.Text("ItemMax: " +					m_EditorLootBuildingsSP[ESgBuildingType.Hunting]);
						
						DbgUI.Text("Buildings ConstructionSite: " + m_EditorLootBuildings[ESgBuildingType.ConstructionSite].Count());
						DbgUI.Text("ItemMax: " +					m_EditorLootBuildingsSP[ESgBuildingType.ConstructionSite]);
						
						DbgUI.Text("Buildings Structure: " + 		m_EditorLootBuildings[ESgBuildingType.Structure].Count());
						DbgUI.Text("ItemMax: " +					m_EditorLootBuildingsSP[ESgBuildingType.Structure]);
						
						DbgUI.Text("Buildings Car: " + 				m_EditorLootBuildings[ESgBuildingType.Car].Count());
						DbgUI.Text("ItemMax: " +					m_EditorLootBuildingsSP[ESgBuildingType.Car]);
						
						DbgUI.Text("Buildings School: " + 			m_EditorLootBuildings[ESgBuildingType.School].Count());
						DbgUI.Text("ItemMax: " +					m_EditorLootBuildingsSP[ESgBuildingType.School]);
						
						DbgUI.Text("Buildings EditorHighlight: " + 	m_EditorLootBuildings[ESgBuildingType.EditorHighlight].Count());
						DbgUI.Text("ItemMax: " +					m_EditorLootBuildingsSP[ESgBuildingType.EditorHighlight]);
						
						DbgUI.Text("Buildings None: "+				m_EditorLootBuildings[ESgBuildingType.None].Count());
					}
					
					
					Object select_obj = GetObjectFromCursor();
					
					if ( select_obj && (m_ObjLastPointed == NULL || select_obj != m_ObjLastPointed ))
					{
						if ( m_ObjLastPointed )
						{
							m_EditorBuildings[m_ObjLastPointed].BBoxNormal();
						}
						
						if ( m_EditorBuildings[select_obj] )
						{
							m_ObjLastPointed = select_obj;
							m_EditorBuildings[select_obj].BBoxPreviewSelect();
						}
					}
					else if ( select_obj == NULL && m_ObjLastPointed )
					{
						m_EditorBuildings[m_ObjLastPointed].BBoxNormal();
						m_ObjLastPointed = NULL;
					}					
					
					if ( m_ObjLastPointed )
					{
						SgDataBuilding building_pointed = SgData.GetBuildingData(m_ObjLastPointed.GetType());
						ESgBuildingType building_type = building_pointed.GetBuildingType();
						int building_type_index = SgSManagerLootSpawner.ConvertBuildingTypeToIndex(building_type);
						
						DbgUI.Text("----- Pointed Building ------");
						DbgUI.Text("Building Name: "+ m_ObjLastPointed.GetType());
						DbgUI.Text("Building Type: "+ m_BuildingEditorTypeEnum[building_type_index]);
						DbgUI.Text("Count in phase: "+ m_BuildingsInArea[m_ObjLastPointed.GetType()].Count());
						DbgUI.Text("Spawn Points Count: "+  SgData.GetBuildingData(m_ObjLastPointed.GetType()).GetSpawnPoints().Count() );
						DbgUI.Text("Items Count Max: "+  SgData.GetBuildingData(m_ObjLastPointed.GetType()).GetItemsMax() );
					}
					else
					{
						DbgUI.Text("Select object for loot edit.");
					}
					
					
					if ( DbgUI.Button("Edit Loot", 50) )
					{
						OpenLootEdit();
					}
					
					if ( DbgUI.Button("Close Editor", 50) )
					{
						EditorClose();
					}
				}
				else
				{
					if ( DbgUI.Button("Select Object", 50) )
					{
						m_SelectObject = true;
					}
				}
			}
		}
		DbgUI.End();
		DbgUI.EndCleanupScope();
		
		OnUpdate();
	}
	
		int		m_BuildingEditorSPSelection;
		int		m_BuildingEditorSPSelectionLast;
		int		m_BuildingEditorSPSelectionPreview;
		int		m_BuildingEditorTypeSelection;
		int		m_BuildingEditorSPRadius;
		bool	m_BuildingEditorSPXray;
	ref array<string> m_BuildingEditorTypeEnum;
	
	void OpenLootEdit()
	{		
		m_OpenLootEditor = true;
		
		CountLootItemMax();
	}
	
	void CountLootItemMax()
	{
		m_LocationItemMax = 0;
		
		for ( int i = 0; i < m_EditorLootBuildings.Count(); ++i )
		{
			ESgBuildingType building_type = m_EditorLootBuildings.GetKey(i);

			array<ref SgLootBuilding> buildings = m_EditorLootBuildings.Get( building_type );
			m_EditorLootBuildingsSP[building_type] = 0;
			
			for ( int k = 0; k < buildings.Count(); ++k)
			{
				array<ref SgDataBuildingSP> building_sp_list = SgData.GetBuildingData(buildings[k].GetObject().GetType()).GetSpawnPoints();
				
				for ( int j = 0; j < building_sp_list.Count(); ++j )
				{
					m_LocationItemMax += building_sp_list[j].GetItemsMax();
					m_EditorLootBuildingsSP[building_type] = m_EditorLootBuildingsSP[building_type] + building_sp_list[j].GetItemsMax();
				}			
			}
		}
	}
	
	//===========================================
	// OnGUIBuildingEditor
	//===========================================
	void OnGUIBuildingEditor(Object obj, SgDataBuilding building)
	{
		string building_type = building.GetObjectType();
		DbgUI.Text("Building Name: "+ building_type );
		DbgUI.Text("Building Count: "+ m_BuildingsInArea.Get( building_type ).Count() );
		DbgUI.Text("Spawn Points: "+ m_SelectedBuilding.GetSpawnPoints().Count() );
		DbgUI.Text("Items Max: "+ m_SelectedBuilding.GetItemsMax() );
		
		DbgUI.Check("Sp render X-Ray", m_BuildingEditorSPXray);
		DbgUI.SameLine();
		if ( DbgUI.Button("Apply X-Ray", 50) )
		{
			m_EditorBuildings[m_SelectedObject].SpawnPointsShow(m_SelectedBuilding);
		}
		
		DbgUI.Combo("Building Type", m_BuildingEditorTypeSelection, m_BuildingEditorTypeEnum);
		
		
		building.SetBuildingType(SgSManagerLootSpawner.ConvertBuildingTypeIndex(m_BuildingEditorTypeSelection));
		
		array<ref SgDataBuildingSP> spawn_points = m_SelectedBuilding.GetSpawnPoints();		
		
		if ( spawn_points.Count() > 0 )
		{
			ref TStringArray sp_list = new array<string>;

			for ( int i = 0; i < spawn_points.Count(); ++i )
			{
				SgDataBuildingSP spawn_point = spawn_points[i];
				sp_list.Insert("Spawn Point "+ i);
			}
			
			DbgUI.List("Spawn Points", m_BuildingEditorSPSelection, sp_list);
			
			if ( m_BuildingEditorSPSelectionLast != m_BuildingEditorSPSelection )
			{
				m_EditorBuildings[m_SelectedObject].DeselectSP( m_BuildingEditorSPSelectionLast );
				m_EditorBuildings[m_SelectedObject].SelectSP( m_BuildingEditorSPSelection );
				
				m_BuildingEditorSPSelectionLast = m_BuildingEditorSPSelection;
				
				m_GUIRefresh = true;
			}
		}
		else
		{
			DbgUI.Text("No spawn points");
		}
		
		if ( DbgUI.Button("Add", 50) )
		{
			m_SelectedBuilding.AddSpawnPoint();
			m_BuildingEditorSPSelection = m_SelectedBuilding.GetSpawnPoints().Count() - 1;
			m_EditorBuildings[m_SelectedObject].SpawnPointsShow(m_SelectedBuilding);
			m_SelectedSPMove = true;
			m_GUIRefresh = true;
		}
		
		DbgUI.SameLine();
		
		if ( DbgUI.Button("Delete", 50) )
		{
			building.RemoveSpawnPoint( building.GetSpawnPoint( m_BuildingEditorSPSelection ) );
			m_GUIRefresh = true;
			m_EditorBuildings[m_SelectedObject].SpawnPointsShow(m_SelectedBuilding);
		}
		
		if ( DbgUI.Button("Save", 50) )
		{
			SgData.SaveBuildingData( m_SelectedBuilding );
		}
		
		if ( DbgUI.Button("Deselect Object", 50) )
		{
			DeselectBuilding();
			UpdateBuildingsByType();
		}
	}
	
	void OnGUISpawnPoint(SgDataBuildingSP sp)
	{
		DbgUI.Begin("Spawn Point ", 0, 0);			
		{				
			if ( DbgUI.Button("Move", 50) )
			{
				m_SelectedSPMove = true;
			}			
			
			DbgUI.Spacer(2);
			
			// SP Items Max
			float height = 10;
			DbgUI.SliderFloat("Offset height", height, 1, 100);
			m_BuildingEditorAddHeight = height / 100;
			DbgUI.SameLine();
			DbgUI.Text( "("+ m_BuildingEditorAddHeight +")" );
			
			if ( DbgUI.Button("Up", 50) )
			{
				vector pos_u = sp.GetPosition();
				pos_u[1] = pos_u[1] + m_BuildingEditorAddHeight;
				sp.SetPosition(pos_u);
				m_EditorBuildings[m_SelectedObject].SetSPPosition(m_BuildingEditorSPSelection, m_SelectedObject.CoordToParent(pos_u) );
			}
			
			DbgUI.SameLine();
			
			if ( DbgUI.Button("Down", 50) )
			{
				vector pos_d = sp.GetPosition();
				pos_d[1] = pos_d[1] - m_BuildingEditorAddHeight;
				sp.SetPosition(pos_d);
				m_EditorBuildings[m_SelectedObject].SetSPPosition(m_BuildingEditorSPSelection, m_SelectedObject.CoordToParent(pos_d) );
			}
			
			// SP Position
			DbgUI.Text("Position: "+ sp.GetPosition() );		
		
			// SP Radius
			float radius = sp.GetRadius() * 100;
			DbgUI.SliderFloat("Radius", radius, 20, 200);
			float rad = radius / 100;
			DbgUI.SameLine();
			DbgUI.Text( "("+rad.ToString()+")" );
			
			if ( sp.GetRadius() != rad )
			{
				sp.SetRadius( rad );
				m_EditorBuildings[m_SelectedObject].SetSPRadius(m_BuildingEditorSPSelection, rad );
				
				int item_max = Math.Round( rad * 3 ); 
				
				sp.SetItemsMax( item_max );
			}
			
			DbgUI.Spacer(2);
			
			// SP Items Max
			DbgUI.Text( "ItemMax: "+ sp.GetItemsMax().ToString() );
		}
		DbgUI.End();
	}
	
	void OnGUILootEditor()
	{		
		/*
		SgDataLocationItemPacks pg_loot = GetDataLootItemPacks();
		
		array<ref SgDataItemPack> location_item_packs = pg_loot.m_LocationDataItemPacks;
		*/
		DbgUI.Begin("Loot Editor", 0, 0);			
		{
		
			DbgUI.Text( "Items per pack: item max: "+ m_LocationItemMax );
			DbgUI.SameLine();
			
			DbgUI.Text( " " );
			
			/*
			for ( int i = 0; i < location_item_packs.Count(); ++i )
			{
				SgDataItemPack item_pack = location_item_packs[i];

				DbgUI.Text("["+ item_pack.m_ItemPackName +"] => Ratio: "+ item_pack.m_CountRatio + " Random: "+ item_pack.m_RandomRange +" Min:"+ item_pack.m_CountMin +" Opt:"+ item_pack.m_CountOpt +" Max:"+ item_pack.m_CountMax );
			}
			*/
			
			if ( DbgUI.Button("Generate Loot", 100) )
			{
				SgSLootGenerator.SaveGameLoot( SgPluginPgEditor.GetInstance().GetCurrentLocationType() );
			}
			
			if ( DbgUI.Button("Distribute Loot", 100) )
			{				
				SgSManagerLootSpawner.StartDistribution( SgPluginPgEditor.GetInstance().GetCurrentPlaygroundName(), SgPluginPgEditor.GetInstance().GetCurrentLocationType(), SgPluginPgEditor.GetInstance().GetCurrentLocationAreaID() );
			}
			
			if ( DbgUI.Button("Distribute Stress Loot", 100) )
			{
				SgSManagerLootSpawner.StartDistribution( SgPluginPgEditor.GetInstance().GetCurrentPlaygroundName(), SgPluginPgEditor.GetInstance().GetCurrentLocationType(), SgPluginPgEditor.GetInstance().GetCurrentLocationAreaID(), true );
			}
			
			if ( DbgUI.Button("Close", 100) )
			{
				m_OpenLootEditor = false;
			}
		}
		DbgUI.End();
	}
	
	//=======================================
	// GetBuildingsInArea
	//=======================================
	map<ESgBuildingType, ref array<ref SgLootBuilding>> GetLootBuildingsInLocation( SgJsonLocation location )
	{
		ref map<ESgBuildingType, ref array<ref SgLootBuilding>> buildings_sorted = new map<ESgBuildingType, ref array<ref SgLootBuilding>>;
		ref map<string, ref array<Object>> buildings = GetBuildingsInLocation( location );
		
		buildings_sorted.Insert(ESgBuildingType.None,				new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.Civil_1,			new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.Civil_2,			new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.Civil_3,			new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.Garage,				new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.GarageBig,			new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.Hospital,			new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.Holy,				new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.PoliceStation,		new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.FireStation,		new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.Military,			new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.Hunting,			new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.ConstructionSite,	new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.Structure,			new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.Car,				new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.School,				new array<ref SgLootBuilding>);
		buildings_sorted.Insert(ESgBuildingType.EditorHighlight,	new array<ref SgLootBuilding>);
		
		for ( int i = 0; i < buildings.Count(); ++i )
		{
			string building_name = buildings.GetKey(i);
			SgDataBuilding building_data = SgData().GetBuildingData( building_name );
			
			if ( building_data )
			{
				ESgBuildingType building_type = building_data.GetBuildingType();
				
				array<Object> buildings_in_area = buildings.GetElement(i);
				
				for ( int j = 0; j < buildings_in_area.Count(); ++j )
				{
					ref SgLootBuilding loot_building = new SgLootBuilding(buildings_in_area.Get( j ) );
					
					if ( buildings_sorted.Get( building_type ) )
					{
						buildings_sorted[building_type].Insert(loot_building);
					}
					else
					{
						building_data.SetBuildingType(ESgBuildingType.None);
						buildings_sorted[ESgBuildingType.None].Insert(loot_building);
					}
				}
			}
		}
		
		for ( int k = 0; k < buildings.Count(); ++k )
		{
			delete buildings.GetElement(0);
		}
		
		delete buildings;
		
		return buildings_sorted;
	}
	
	//=======================================
	// GetBuildingsInArea
	//=======================================
	map<string, ref array<Object>> GetBuildingsInLocation( SgJsonLocation location )
	{
		array<Object> objects = new array<Object>;
		array<CargoBase> cargos = new array<CargoBase>;
		ref map<string, ref array<Object>> buildings = new map<string, ref array<Object>>;
				
		GetGame().GetObjectsAtPosition( location.GetPosition(), location.m_BorderRangeMax, objects, cargos );
		
		for ( int i = 0; i < objects.Count(); ++i )
		{	
			Object obj = objects[i];
			
			if( GetGame().ObjectIsKindOf( obj, "HouseNoDestruct" ) || GetGame().ObjectIsKindOf( obj, "House" ) )
			{
				if ( IsObjectInLocation( EntityAI.Cast( obj ), m_EditLocation ) )
				{					
					string obj_type = obj.GetType();
					if ( !buildings.Contains(obj_type) )
					{
						ref array<Object> objs_array = new array<Object>;
						buildings.Insert(obj_type, objs_array);
					}
					buildings[obj_type].Insert(obj);
				}
				else
				{
//Print("House: "+ obj.GetType() +" in OUT of area");
				}
			}
		}
		return buildings;		
	}
	
	//====================================
	// IsObjectInLocation
	//====================================
	bool IsObjectInLocation(EntityAI obj, SgJsonLocation location)
	{
		int i, j, k;
		float vy_i,vy_j, vx_i, vx_j, testx, testy;
		bool is_inside = false;
		
		vector obj_pos = obj.GetPosition();
		
		if ( obj_pos.Distance(location.GetPosition(), obj_pos) < location.m_BorderRangeMin )
		{
			return true;
		}
		
		array<vector> borders = location.GetBorderPositions();
		int nvert = borders.Count();
		
		j = nvert - 1;		
		for ( i = 0; i < nvert; ++i )
		{			
			vector v1 = borders[i];
			vector v2 = borders[j];
			
			vx_i = v1[0];
			vx_j = v2[0];
			vy_i = v1[2];
			vy_j = v2[2];
	
			testx = obj_pos[0];
			testy = obj_pos[2];
			
			// Intersaction test
			float a = (vx_j - vx_i);
			float b = (testy - vy_i);
			float c = (vy_j - vy_i);
			float testx_ref = vx_i;
			if ( a != 0 && b != 0 && c != 0 )
			{
				testx_ref = (a * b / c + vx_i);
			}
			
			bool test1 = vy_i > testy;
			bool test2 = vy_j > testy;
			bool test3 = testx < testx_ref;
			bool test1_2 = test1 != test2;
			
			if ( test1_2 && test3 )
			{
				is_inside = !is_inside;
			}
			
			j = i;
		}
			
		return is_inside;
		
	}
}
