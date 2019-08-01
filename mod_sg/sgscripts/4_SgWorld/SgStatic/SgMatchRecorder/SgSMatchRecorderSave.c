class SgSMatchRecorderSave
{	
	static protected string 										m_DirRoot;
	
	static protected ref SgMatchRecorderFileHandler					m_FileMain;
	static protected ref SgMatchRecorderFileHandler					m_FileActions;
	static protected ref map<int, ref SgMatchRecorderFileHandler>	m_FileEntities;
	static protected string											m_DirPathEntities;
	
	//============================================
	// Init
	//============================================
	static void Init()
	{
		MakeSessionDirectory();
		
		// Save Main Inforamtion of Session
		m_FileMain = new SgMatchRecorderFileHandler(m_DirRoot + "\\Main.sgz", FileMode.APPEND);
		SgMatchRecorderMain matchRecorderMain = new SgMatchRecorderMain( GetCurrentTime(":"), GetCurrentDate("-") );	
		SgSMatchRecorderSerializer<SgMatchRecorderMain>.SaveMatchRecorderEntry(matchRecorderMain, m_FileMain);
		
		// Create File for Ations
		m_FileActions = new SgMatchRecorderFileHandler(m_DirRoot + "\\Actions.sgz", FileMode.APPEND);
		
		// Create Directory for Entities
		m_FileEntities = new map<int, ref SgMatchRecorderFileHandler>;
		m_DirPathEntities = m_DirRoot + "\\Entities";
		MakeDirectory( m_DirPathEntities );		
	}
	
	void ~SgSMatchRecorderSave()
	{
		CloseFile(m_FileMain.m_fileHandle);
		CloseFile(m_FileActions.m_fileHandle);
		
		foreach (SgMatchRecorderFileHandler fileHandlerWrapper : m_FileEntities)
		{
			CloseFile(fileHandlerWrapper.m_fileHandle);
		}
	}
	
	//============================================
	// InitMovingEntity
	//============================================
	static void InitMovingEntity(EntityAI entity)
	{
		if ( !entity )
		{
			return;
		}
		
		int entity_id = entity.GetID();
		
		if ( m_FileEntities.Contains(entity_id) )
		{
			return;
		}
		
		SgMatchRecorderFileHandler entityFH = new SgMatchRecorderFileHandler(m_DirPathEntities + "\\entity_" + entity_id + ".sgz", FileMode.APPEND);
		string e_name = entity.GetName();
		int e_type = SgMatchRecorderEntityType.Unknow;
		int e_teamId = -1;
		
		if ( entity.IsInherited( PlayerBase ) )
		{
			e_type = SgMatchRecorderEntityType.Player;
			
			PlayerBase player = PlayerBase.Cast( entity );
			//e_name = player.GetIdentity().GetName();
			e_name = SgSManagerPlayers.GetSgPlayerByPlayerBase(player).GetUserName();
			
			SgTeam team = SgSManagerPlayers.GetTeamForPlayer(player);
			if (team)
			{
				e_teamId = team.GetTeamID();
			}
		}
		else if ( entity.Type().ToString() == "SG_InfectedBase")
		{
			e_type = SgMatchRecorderEntityType.Zombie;
			e_name = entity.GetType();
		}
		else if ( entity.Type().ToString() == "AnimalBase" )
		{
			e_type = SgMatchRecorderEntityType.Animal;
			e_name = entity.GetType();
		}
		
		SgMatchRecorderSummary matchRecorderSummary = new SgMatchRecorderSummary(e_name, e_type, e_teamId);
		SgSMatchRecorderSerializer<SgMatchRecorderSummary>.SaveMatchRecorderEntry(matchRecorderSummary, entityFH);
		
		m_FileEntities.Insert(entity_id, entityFH);	
	}
	
	//============================================
	// SaveMovingEntity
	//============================================
	static void SaveMovingEntity(float time, EntityAI entity)
	{
		vector pos = entity.GetPosition();
		vector dir = entity.GetDirection();	
			
		Vector2 pos2D = new Vector2(pos[0], pos[2]);
		Vector2 dir2D = new Vector2(dir[0], dir[2]);
		
		SgMatchRecorderEntityMove matchRecorderEntityMove = new SgMatchRecorderEntityMove(time, pos2D, dir2D);
		SgSMatchRecorderSerializer<SgMatchRecorderEntityMove>.SaveMatchRecorderEntry(matchRecorderEntityMove, m_FileEntities.Get(entity.GetID()));
	}
	
	//============================================
	// SavePlayerShoot - Action
	//============================================
	static void SavePlayerShoot(float time, EntityAI entity, vector shot_destination)
	{
		Vector2 shootPosition = new Vector2(shot_destination[0], shot_destination[2]);
		
		SgMatchRecorderPlayerShootActionData playerShootData = new SgMatchRecorderPlayerShootActionData(entity.GetID(), shootPosition);
		SgMatchRecorderAction<SgMatchRecorderPlayerShootActionData> matchRecorderAction = new SgMatchRecorderAction<SgMatchRecorderPlayerShootActionData>(time, SgMatchRecorderActionType.PlayerShoot, playerShootData);
		SgSMatchRecorderSerializer<SgMatchRecorderAction<SgMatchRecorderPlayerShootActionData>>.SaveMatchRecorderEntry(matchRecorderAction, m_FileActions);
	}
	
	//============================================
	// SaveEntityDied - Action
	//============================================
	static void SaveEntityDied(float time, EntityAI entity)
	{		
		SgMatchRecorderPlayerDeathActionData playerDeathData = new SgMatchRecorderPlayerDeathActionData(entity.GetID());
		SgMatchRecorderAction<SgMatchRecorderPlayerDeathActionData> matchRecorderAction = new SgMatchRecorderAction<SgMatchRecorderPlayerDeathActionData>(time, SgMatchRecorderActionType.EntityDied, playerDeathData);
		SgSMatchRecorderSerializer<SgMatchRecorderAction<SgMatchRecorderPlayerDeathActionData>>.SaveMatchRecorderEntry(matchRecorderAction, m_FileActions);
	}
	
	//============================================
	// SaveItemSpawn - Action
	//============================================
	static void SaveItemSpawn(float time, int itemId, vector itemPos, ESgLocationType locationType, SgMatchRecorderActionType actionType)
	{
		Vector2 spawnPosition = new Vector2(itemPos[0], itemPos[2]);
		
		SgMatchRecorderItemSpawnActionData itemSpawnData = new SgMatchRecorderItemSpawnActionData(itemId, spawnPosition, locationType);
		SgMatchRecorderAction<SgMatchRecorderItemSpawnActionData> matchRecorderAction = new SgMatchRecorderAction<SgMatchRecorderItemSpawnActionData>(time, actionType, itemSpawnData);
		SgSMatchRecorderSerializer<SgMatchRecorderAction<SgMatchRecorderItemSpawnActionData>>.SaveMatchRecorderEntry(matchRecorderAction, m_FileActions);
	}
	
	//============================================
	// SaveTransmitterSpawn - Action
	//============================================
	static void SaveTransmitterSpawn(float time, SgLocation location)
	{
		SgMatchRecorderActionType actionType = SgMatchRecorderActionType.SpawnTransmitter;
		switch ( location.GetLocationType() )
		{
			case ESgLocationType.PoICar:
				actionType = SgMatchRecorderActionType.SpawnV3SCrash;
				break;
			case ESgLocationType.PoIHeli:
				actionType = SgMatchRecorderActionType.SpawnHeliCrash;
				break;
			case ESgLocationType.PhaseEnd:
				SgLocationPhaseEnd end_location = SgLocationPhaseEnd.Cast(location);
				SaveItemSpawn(time, end_location.GetEndPositionId(), end_location.GetEndPosition(), location.GetLocationType(), SgMatchRecorderActionType.SpawnEndPoi);
				break;
		}
		
		SaveItemSpawn(time, location.GetAreaID(), location.GetPosition(), location.GetLocationType(), actionType);
		
		array<vector> bored_positions = location.GetBorderPositions();
		for ( int i = 0; i < bored_positions.Count(); ++i )
		{
			vector border_pos = bored_positions[i];
			
			SaveItemSpawn(time, i, border_pos, location.GetLocationType(), SgMatchRecorderActionType.SpawnAntenna);
		}
	}
	
	//============================================
	// SaveTimerSet
	//============================================
	static void SaveTimerSet(float time, int seconds)
	{
		SgMatchRecorderTimerSetActionData timerSetData = new SgMatchRecorderTimerSetActionData(seconds, time);
		SgMatchRecorderAction<SgMatchRecorderTimerSetActionData> matchRecorderAction = new SgMatchRecorderAction<SgMatchRecorderTimerSetActionData>(time, SgMatchRecorderActionType.MainSetTimer, timerSetData);
		SgSMatchRecorderSerializer<SgMatchRecorderAction<SgMatchRecorderTimerSetActionData>>.SaveMatchRecorderEntry(matchRecorderAction, m_FileActions);
	}
	
	//============================================
	// SavePhaseSet
	//============================================
	static void SavePhaseSet(float time, int phase_index)
	{		
		SgMatchRecorderPhaseSetActionData phaseSetData = new SgMatchRecorderPhaseSetActionData(phase_index);
		SgMatchRecorderAction<SgMatchRecorderPhaseSetActionData> matchRecorderAction = new SgMatchRecorderAction<SgMatchRecorderPhaseSetActionData>(time, SgMatchRecorderActionType.MainSetPhase, phaseSetData);
		SgSMatchRecorderSerializer<SgMatchRecorderAction<SgMatchRecorderPhaseSetActionData>>.SaveMatchRecorderEntry(matchRecorderAction, m_FileActions);
	}
	
	//============================================
	// SavePhaseSet
	//============================================
	static void SaveTransitionSet(float time, int transition_index)
	{		
		SgMatchRecorderTransitionSetActionData transitionSetData = new SgMatchRecorderTransitionSetActionData(transition_index);
		SgMatchRecorderAction<SgMatchRecorderTransitionSetActionData> matchRecorderAction = new SgMatchRecorderAction<SgMatchRecorderTransitionSetActionData>(time, SgMatchRecorderActionType.MainSetTransition, transitionSetData);
		SgSMatchRecorderSerializer<SgMatchRecorderAction<SgMatchRecorderTransitionSetActionData>>.SaveMatchRecorderEntry(matchRecorderAction, m_FileActions);
	}
	
	//============================================
	// SaveActivateObject
	//============================================
	static void SaveActivateObject(float time, ESgLocationType location_type)
	{
		SgMatchRecorderActionType actionType = SgMatchRecorderActionType.None;
		switch ( location_type )
		{
			case ESgLocationType.PoICar:
				actionType = SgMatchRecorderActionType.SpawnV3SCrash;
				break;
			case ESgLocationType.PoIHeli:
				actionType = SgMatchRecorderActionType.SpawnHeliCrash;
				break;
			case ESgLocationType.PhaseEnd:
				actionType = SgMatchRecorderActionType.SpawnEndPoi;
				break;
		}
		
		SgMatchRecorderGenericItem activateObjectData = new SgMatchRecorderGenericItem(location_type);
		SgMatchRecorderAction<SgMatchRecorderGenericItem> matchRecorderAction = new SgMatchRecorderAction<SgMatchRecorderGenericItem>(time, actionType, activateObjectData);
		SgSMatchRecorderSerializer<SgMatchRecorderAction<SgMatchRecorderGenericItem>>.SaveMatchRecorderEntry(matchRecorderAction, m_FileActions);
	}
	
	//--------------------------------------------
	// MakeSessionDirectory
	//--------------------------------------------
	static protected void MakeSessionDirectory()
	{
		string dir_root = "$profile:Records";
		
		if ( !FileExist( dir_root ) )
		{
			MakeDirectory( dir_root );
		}
			
		m_DirRoot = dir_root + "\\SgZ_Session_" + GetCurrentDate("-") + "_" + GetCurrentTime("-");
		MakeDirectory( m_DirRoot );
	}
	
	//--------------------------------------------
	// GetCurrentDate
	//--------------------------------------------
	static string GetCurrentDate(string separator)
	{
		int year = 0;
		int month = 0;
		int day = 0;
		
		GetYearMonthDay( year, month, day );
		
		return (year.ToStringLen(4) + separator + month.ToStringLen(2) + separator + day.ToStringLen(2));
	}	
	
	//--------------------------------------------
	// GetCurrentTime
	//--------------------------------------------
	static string GetCurrentTime(string separator)
	{
		int hour = 0;
		int minute = 0;
		int second = 0;
		
		GetHourMinuteSecond(hour, minute, second );
			
		return (hour.ToStringLen(2) + separator + minute.ToStringLen(2) + separator + second.ToStringLen(2));
	}
}