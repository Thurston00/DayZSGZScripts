class SgSMatchRecorder
{	
	static protected const float 				WORLD_SCAN_PERIOD = 1000;
	
	static protected float						m_TimeStart;
	
	static protected ref array<EntityAI>		m_MovingEntities;
	
	//============================================
	// Start
	//============================================
	static void Start()
	{
		SgSMatchRecorderSave.Init();		
		
		m_TimeStart			= GetWorldTime();
		m_MovingEntities	= new array<EntityAI>;
		
		InitSpawnedEntities();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UpdateInPeriod, WORLD_SCAN_PERIOD, true);
		
		array<ref SgLocation> locations = SgSManagerPlayground.GetLocations();
		for ( int i = 0; i < locations.Count(); ++i )
		{	
			OnLocationCreated(locations[i]);
		}
	}
	
	//============================================
	// GetCurrentTimeRounded
	//============================================
	static int GetCurrentTimeRounded()
	{
		return Math.Round((GetWorldTime() - m_TimeStart) / 1000);
	}
	
	//============================================
	// GetCurrentTime
	//============================================
	static int GetCurrentTime()
	{
		return (GetWorldTime() - m_TimeStart) / 1000;
	}
	
	//============================================
	// AnaliticFrameUpdate
	//============================================
	static void UpdateInPeriod()
	{
		WorldScan();
	}
	
	//============================================
	// WorldScan
	//============================================
	static void WorldScan()
	{		
		for ( int i = 0; i < m_MovingEntities.Count(); ++i )
		{
			EntityAI e = m_MovingEntities[i];
			
			if ( e && e.IsAlive() )
			{
				OnEntityMove(e);
			}
		}
	}
	
	//============================================
	// InitSpawnedEntities
	//============================================
	static void InitSpawnedEntities()
	{
		array<ref SgPlayer> sg_players = SgSManagerPlayers.GetSgPlayers();
		foreach ( SgPlayer sg_player : sg_players )
		{
			PlayerBase player_base = sg_player.GetPlayerBase();
			
			if ( player_base )
			{
				m_MovingEntities.Insert(sg_player.GetPlayerBase());
				SgSMatchRecorderSave.InitMovingEntity(sg_player.GetPlayerBase());
			}
		}
		
		/*array<ref EntityAI> ai_entities = SgSManagerAi.GetAIEntities();
		foreach ( EntityAI entity : ai_entities )
		{
			m_MovingEntities.Insert(entity);
			SgSMatchRecorderSave.InitMovingEntity(entity);
		}*/
	}
	
	//============================================
	// OnEntityMove
	//============================================
	static void OnEntityMove(EntityAI entity)
	{
		SgSMatchRecorderSave.SaveMovingEntity(GetCurrentTimeRounded(), entity);
	}
	
	//============================================
	// OnItemSpawn
	//============================================
	static void OnItemSpawn(EntityAI entity)
	{
		SgSMatchRecorderSave.SaveItemSpawn(GetCurrentTime(), entity.GetID(), entity.GetPosition(), ESgLocationType.None, SgMatchRecorderActionType.ItemSpawn);
	}
	
	//============================================
	// OnLocationCreated
	//============================================
	static void OnLocationCreated(SgLocation location)
	{
		SgSMatchRecorderSave.SaveTransmitterSpawn(GetCurrentTime(), location);
	}
	
	//============================================
	// OnTimerSet
	//============================================
	static void OnTimerSet(int seconds)
	{
		SgSMatchRecorderSave.SaveTimerSet(GetCurrentTime(), seconds);
	}
	
	//============================================
	// OnPhaseSet
	//============================================
	static void OnPhaseActiveSet(int phase_index)
	{
		SgSMatchRecorderSave.SavePhaseSet(GetCurrentTime(), phase_index);
	}
	
	//============================================
	// OnTransitionSet
	//============================================
	static void OnTransitionSet(int transition_index)
	{
		SgSMatchRecorderSave.SaveTransitionSet(GetCurrentTime(), transition_index);
	}
	
	//============================================
	// OnActivateObject
	//============================================
	static void OnActivateObject(ESgLocationType location_type)
	{
		SgSMatchRecorderSave.SaveActivateObject(GetCurrentTime(), location_type);
	}
	
	//============================================
	// OnPlayerFired
	//============================================
	static void OnPlayerFired(PlayerBase player)
	{
		vector from = player.GetPosition();
		vector to = from + ( player.GetDirection() * 250 );
		//vector contact_pos;
		//vector contact_dir;
		//int contact_component;
		
		//if ( DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, NULL, player, NULL, false, false ) )
		//{
		//	SgSMatchRecorderSave.SavePlayerShoot(GetCurrentTime(), player, contact_pos);
		//}
		//else
		//{
			SgSMatchRecorderSave.SavePlayerShoot(GetCurrentTime(), player, to);
		//}
	}
	
	//============================================
	// OnEntityDied
	//============================================
	static void OnEntityDied(EntityAI target, EntityAI source)
	{
		SgSMatchRecorderSave.SaveEntityDied(GetCurrentTime(), target);
	}
	
	//============================================
	// not works
	//============================================
	static void OnEntityHitBy(EntityAI target, EntityAI source, float hit_damage)
	{
		
	}
}