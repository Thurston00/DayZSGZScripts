class SgIntroScene extends Managed
{
	int m_CachedPlaytime;
	int m_currentCharacterID;
	
	//camera
	Camera m_camera;
	vector m_cameraTrans[4];
	
	//demo unit
	PlayerBase 						m_demoUnit;
	vector 							m_demoPos;
	vector 							m_demoRot;
	
	bool 							m_rotatingCharacter;
	int 							m_rotatingCharacterMouseX;
	int 							m_rotatingCharacterMouseY;
	float 							m_rotatingCharacterRot;
	
	ref TStringArray 				m_characterAnimations;
	
	//calculations
	float diff_x;

	//============================================
	// Init
	//============================================	
	void SgIntroScene()
	{
		m_currentCharacterID = -1;
		m_demoPos = "0 0 0";
		m_demoRot = "0 0 0";
		
		m_CachedPlaytime = 0;
		string cached_playtime_str = "";
		
		m_characterAnimations = new TStringArray;
		m_rotatingCharacter = 0;
		int character_to_select = - 1;
		
		g_Game.GetProfileString("cachedPlaytime", cached_playtime_str);
		if ( cached_playtime_str != "" )
		{
			m_CachedPlaytime = cached_playtime_str.ToInt();
		}
		
		World w = g_Game.GetWorld();
		MenuData data = g_Game.GetMenuData();
		
		if (data.GetLastPlayedCharacter())
		{
			character_to_select = data.GetLastPlayedCharacter();
		}
		
		string worldName;
		g_Game.GetWorldName(worldName);
	
		string root_path = "cfgCharacterScenes " + worldName;
		
		int count = g_Game.ConfigGetChildrenCount(root_path);
		int index = Math.RandomInt(0, count - 1);
		string childName;
		g_Game.ConfigGetChildName(root_path, index, childName);
	
		string scene_path = root_path + " " + childName;
		vector target = SwapYZ(g_Game.ConfigGetVector(scene_path + " target"));
		vector position = SwapYZ(g_Game.ConfigGetVector(scene_path + " position"));
		
		/*position[0] = 1318.25; // SG_TODO: Ivo
		position[1] = 1.91;
		position[2] = 1602.17;*/
		
		TIntArray date = new TIntArray;
		g_Game.ConfigGetIntArray(scene_path + " date", date);
		float fov = g_Game.ConfigGetFloat(scene_path + " fov");
		float aperture = g_Game.ConfigGetFloat(scene_path + " aperture");
		float humidity = g_Game.ConfigGetFloat(scene_path + " humidity");
		float overcast = g_Game.ConfigGetFloat(scene_path + " overcast");
		
		if (fov == 0) fov = 0.5;					//min fov
		if (humidity == 0) humidity = 0.2;			//min humidity
		if (overcast == 0) overcast = 0.2;			//min overcast
		
		World world = g_Game.GetWorld();
	
		if (world && date.Count() >= 5)
		{
			world.SetDate(date.Get(0), date.Get(1), date.Get(2), date.Get(3), date.Get(4));
		}
	
		GetGame().ObjectDelete( m_camera );
		Class.CastTo(m_camera, g_Game.CreateObject("staticcamera", SnapToGround( position ), true)); //Vector(position[0] , position[1] + 1, position[2])
		
		Math3D.MatrixIdentity4(m_cameraTrans);
		
		if (m_camera)
		{
			m_camera.SetPosition(Vector(m_camera.GetPosition()[0],m_camera.GetPosition()[1]+0,m_camera.GetPosition()[2]));
			m_camera.LookAt(target);
			
			/*vector cam_rotation = m_camera.GetOrientation(); // SG_TODO: Ivo
			
			Print("Camera Rotations: "+ cam_rotation);
			
			cam_rotation[0] = 115; // horizontal
			cam_rotation[1] = 0; // tilt
			cam_rotation[2] = 0; // vertical
			fov = 1.04;
			
			m_camera.SetOrientation( cam_rotation );
			*/
			m_camera.SetFOV(fov);
			m_camera.SetFocus(5.0, 1.0); //5.0, 1.0
			
			m_camera.SetActive(true);
			
			Math3D.DirectionAndUpMatrix(target - position, "0 1 0", m_cameraTrans);
			m_cameraTrans[3] = m_camera.GetPosition();
			m_demoPos = Vector(0.685547, -0.988281, 3.68823).Multiply4(m_cameraTrans);

			float pos_x = m_demoPos[0];
			float pos_z = m_demoPos[2];
			float pos_y = GetGame().SurfaceY(pos_x, pos_z);
			vector ground_demo_pos = Vector(pos_x, pos_y, pos_z);
			m_demoPos = ground_demo_pos;

			m_demoRot = "0 0 0";
			vector to_cam_dir = m_camera.GetPosition() - m_demoPos;
			m_demoRot[0] = Math.Atan2(to_cam_dir[0], to_cam_dir[2]) * Math.RAD2DEG;
		}
	}
		
	void ChangeCharacter(int characterID)
	{
		if (m_demoUnit)
		{
			g_Game.ObjectDelete(m_demoUnit);
			m_demoUnit = NULL;
		}
		m_currentCharacterID = characterID;
		
		if(characterID == - 1)
		{
			return;
		}
		//TODO remove return once 'CreateCharacterPerson' stops crashing
		return;
		
		Class.CastTo(m_demoUnit, g_Game.GetMenuData().CreateCharacterPerson(characterID));
	
		//g_Game.PreloadObject(type, 1.0);
		
		if (m_demoUnit)
		{
			m_demoUnit.SetPosition(Vector(m_demoPos[0],m_demoPos[1],m_demoPos[2]) + "0 0 333");
			m_demoUnit.SetOrientation(m_demoRot);
	
			InitCharacterAnimations(m_demoUnit.GetHumanInventory().GetEntityInHands());
		}
		Print(m_demoUnit.GetType());
		//Change statics for character HERE
		//counter = m_demoUnit.get("kill");
	}
	
	//============================================
	// Character
	//============================================
	int NextCharacterID()
	{
		int count = g_Game.GetMenuData().GetCharactersCount();
		if( count == 0 )	return -1;
		
		if ( m_currentCharacterID + 1 < count )
		{
			return m_currentCharacterID++; 
		}
		else
		{
			return -1;
		}
	}
	
	int PrevCharacterID()
	{
		int count = g_Game.GetMenuData().GetCharactersCount();
		if( count == 0 )	return -1;
		if( m_currentCharacterID > -1 )
		{
			return m_currentCharacterID - 1;
		}
		return count - 1;
	}
	
	int CurrentCharacterID()
	{
		return m_currentCharacterID;
	}
	
	void CreateCharacter(string type)
	{
		if (m_demoUnit)
		{
			g_Game.ObjectDelete(m_demoUnit);
			m_demoUnit = NULL;
		}
		
		//HideSelectedCharacter();
		
		g_Game.PreloadObject(type, 1.0);
	
		Class.CastTo(m_demoUnit, g_Game.CreateObject(type, SnapToGround(Vector(m_demoPos[0],m_demoPos[1],m_demoPos[2]) + "0 0 333"), true));
		
		if (m_demoUnit)
		{
			//m_demoUnit.SetPosition(m_demoPos);
			m_demoUnit.PlaceOnSurface();
			m_demoUnit.SetOrientation(m_demoRot);
		}
	}
	
	void GetAllItemsInInventory(out array<InventoryItem> items)
	{
		items.Clear();
		
		if (!m_demoUnit) return;
		
		for (int i = 0; i < InventorySlots.COUNT; i++)
		{
			InventoryItem item;
			Class.CastTo(item, m_demoUnit.GetInventory().FindAttachment(i));
	
			if (!item) continue;
	
			items.Insert(item);
	
			if (item.GetInventory().GetCargo())
			{
				CargoBase cargo = item.GetInventory().GetCargo();
	
				for (int j = 0; j < cargo.GetItemCount(); j++)
				{
					InventoryItemBase inventoryItem;
					Class.CastTo(inventoryItem, cargo.GetItem(j));
					items.Insert(inventoryItem);
				}
			}
	
			for (j = 0; j < item.GetInventory().AttachmentCount(); j++)
			{
				Class.CastTo(inventoryItem, item.GetInventory().GetAttachmentFromIndex(j));
				items.Insert(inventoryItem);
			}
		}
		
		Class.CastTo(item, m_demoUnit.GetHumanInventory().GetEntityInHands());
		if (item) items.Insert(item);
	}
	
	void InitCharacterAnimations(EntityAI item)
	{
		m_characterAnimations.Clear();
	
		InventoryItem chainsaw = NULL;
		InventoryItem pistol = NULL;
		InventoryItem rifle = NULL;
		InventoryItem knife = NULL;
		InventoryItem melee = NULL;
		InventoryItem baseballBat = NULL;
		
		if (!m_demoUnit) return;
		
		if (item)	
		{
			if (item.IsKindOf("Chainsaw"))
			{
				Class.CastTo(chainsaw, item);
			}
			
			if (item.IsKindOf("Rifle"))
			{
				Class.CastTo(rifle, item);
			}
	
			if (item.IsKindOf("Pistol"))
			{
				Class.CastTo(pistol, item);
			}
	
			if (item.IsKindOf("KnifeBase"))
			{
				Class.CastTo(knife, item);
			}
	
			if (item.IsKindOf("BaseballBat"))
			{
				Class.CastTo(baseballBat, item);
			}
			
			if (item.IsKindOf("MeleeItemBase"))
			{
				Class.CastTo(melee, item);
			}
		}
		
		if (rifle)
		{
			g_Game.ConfigGetTextArray("CfgMovesMaleSdr2 States menu_idlerifleLong0 variantsPlayer", m_characterAnimations);
		}
		else if (baseballBat)
		{
			g_Game.ConfigGetTextArray("CfgMovesMaleSdr2 States menu_idleBat0 variantsPlayer", m_characterAnimations);
		}
		else if (melee)
		{
			g_Game.ConfigGetTextArray("CfgMovesMaleSdr2 States menu_idleHatchet0 variantsPlayer", m_characterAnimations);
		}
		else if (knife)
		{
			g_Game.ConfigGetTextArray("CfgMovesMaleSdr2 States menu_idleKnife0 variantsPlayer", m_characterAnimations);
		}
		else if (pistol)
		{
			g_Game.ConfigGetTextArray("CfgMovesMaleSdr2 States menu_idlePistol0 variantsPlayer", m_characterAnimations);
		}
		else if (chainsaw)
		{
			g_Game.ConfigGetTextArray("CfgMovesMaleSdr2 States menu_idleChainsaw0 variantsPlayer", m_characterAnimations);
		}
		else
		{
			g_Game.ConfigGetTextArray("CfgMovesMaleSdr2 States menu_idleUnarmed0 variantsPlayer", m_characterAnimations);
		}
	}
	
	//============================================
	// Character controls
	//============================================
	void CharacterRotationStart()
	{
		m_rotatingCharacter = true;
		g_Game.GetMousePos(m_rotatingCharacterMouseX, m_rotatingCharacterMouseY);
		if (m_demoUnit) 
		{
			m_rotatingCharacterRot = m_demoRot[0];
		}
	}
	
	void CharacterRotationStop()
	{
		if (m_rotatingCharacter)
		{
			m_rotatingCharacter = false;
		}
	}
	
	void CharacterRotate()
	{
		int actual_mouse_x;
		int actual_mouse_y;
		g_Game.GetMousePos(actual_mouse_x, actual_mouse_y);
	
		diff_x = m_rotatingCharacterMouseX - actual_mouse_x;
		
		if (m_demoUnit)
		{
			m_demoRot[0] = m_rotatingCharacterRot + (diff_x * 0.5);
			m_demoUnit.SetOrientation(m_demoRot);
		}
	}

	bool IsRotatingCharacter()
	{
		return m_rotatingCharacter;
	}
		
	void SaveDefaultCharacter()
	{
		if (m_demoUnit)
		{
			//Print(String(m_demoUnit.GetType()));
			g_Game.SetProfileString("defaultCharacter", m_demoUnit.GetType());
	
			InventoryItem item = NULL;
			TStringArray inventory = new TStringArray;
			
			for (int i = 0; i < InventorySlots.COUNT; i++)
			{
				Class.CastTo(item, m_demoUnit.GetInventory().FindAttachment(i));
				if (item)
				{
					inventory.Insert(item.GetType());
				}
			}
	
			g_Game.SetProfileStringList("defaultInventory", inventory);
			g_Game.SaveProfile();
		}
	}
	
	void Update()
	{
		if (m_rotatingCharacter)
		{
			CharacterRotate();
		}
	}
	
	//============================================
	// Support
	//============================================
	vector SwapYZ(vector vec)
	{
		vector tmp;
		tmp[0] = vec[0];
		tmp[1] = vec[2];
		tmp[2] = vec[1];
	
		return tmp;
	}
	
	vector SnapToGround(vector pos)
	{
		float pos_x = pos[0];
		float pos_z = pos[2];
		float pos_y = GetGame().SurfaceY(pos_x, pos_z);
		vector tmp_pos = Vector(pos_x, pos_y, pos_z);
		tmp_pos[1] = tmp_pos[1] + pos[1];
	
		return tmp_pos;
	}
}
