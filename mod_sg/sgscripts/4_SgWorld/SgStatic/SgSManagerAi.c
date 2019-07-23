// For more reference on old Zombie Manager see deleted SgSManagerZombies via this line commit.
class SgSManagerAi
{
	protected static ref map<ESgAIGroup, string> m_aiGroupBehaviourNames 	= new ref map<ESgAIGroup, string>;
	protected static ref array<ref EntityAI> m_AIEntities 					= new ref array<ref EntityAI>;
	
	static void DistributeAI( array<ref SgJsonAIHerdSpawnData> aiHerdsSpawnData )
	{
		foreach ( SgJsonAIHerdSpawnData aiHerdSpawnData : aiHerdsSpawnData)
		{
			DistributeAI(aiHerdSpawnData);
		}
	}
	
	static void DistributeAI( SgJsonAIHerdSpawnData aiHerdSpawnData )
	{
		bool forwardDirection 		= true;
		bool loop 					= false;
		int defaulAIZoneIndex 		= 0;
		
		if ( aiHerdSpawnData.GetEntityNames().Count() == 0 )
		{
			Error("[SgSManagerAi] Can't spawn AI Group without any defined Entity Names");
			return;
		}
		
		SetupAIZoneIndex( defaulAIZoneIndex, aiHerdSpawnData );
		if ( defaulAIZoneIndex == -1 ) return;
		
		ESgAIGroup aiGroupType 												= aiHerdSpawnData.GetAIGroup();
		string aiGroupBehaviourName 										= GetAiGroupBehaviourName(aiGroupType);
		AIGroup aiGroup 													= CreateGroup(aiGroupBehaviourName);
		array<ref BehaviourGroupInfectedPackWaypointParams> waypointsParams = CreateWaypoints(aiHerdSpawnData);
		
		SetupInfectedPackAIGroup( aiGroup, waypointsParams, defaulAIZoneIndex, forwardDirection, loop );
		CreateAIObjects( aiHerdSpawnData, aiGroup, defaulAIZoneIndex );
	}
	
	// Main AI Creation Logic
	
	protected static void SetupAIZoneIndex( out int aiZoneIndex, SgJsonAIHerdSpawnData aiHerdSpawnData )
	{
		array<ref SgJsonAIZone> aiZones 			= aiHerdSpawnData.GetAIZones();
		array<ref SgJsonAIZone> aiZonesSpawnable 	= SgArray<SgJsonAIZone>.Copy( aiHerdSpawnData.GetAIZones() );
		
		foreach ( SgJsonAIZone aiZone : aiZones )
		{
			if ( !aiZone.GetCanSpawn() )
			{
				aiZonesSpawnable.RemoveItem(aiZone);
			}
		}
		
		aiZone = aiZonesSpawnable.GetRandomElement();
		if ( aiZone )
		{
			aiZoneIndex = aiZones.Find(aiZone);
		}
		else
		{
			aiZoneIndex = -1;
		}
	}
	
	protected static ref array<ref BehaviourGroupInfectedPackWaypointParams> CreateWaypoints( SgJsonAIHerdSpawnData aiHerdSpawnData )
	{
		ref array<ref BehaviourGroupInfectedPackWaypointParams> waypointParams = new array<ref BehaviourGroupInfectedPackWaypointParams>();
		
		array<ref SgJsonAIZone> aiZones =  aiHerdSpawnData.GetAIZones();
		foreach ( SgJsonAIZone aiZone : aiZones)
		{
			waypointParams.Insert( BehaviourGroupInfectedPackWaypointParams( aiZone.GetPosition(), aiZone.GetRange() ) );
		}
		
		return waypointParams;
	}
	
	protected static AIGroup CreateGroup(string aiGroupBehaviourName)
	{
		AIWorld aiWorld = GetGame().GetWorld().GetAIWorld();
		return aiWorld.CreateGroup(aiGroupBehaviourName);
 	}
	
	protected static void SetupInfectedPackAIGroup( AIGroup aiGroup, array<ref BehaviourGroupInfectedPackWaypointParams> waypointParams, int defaulAIZoneIndex, bool forwardDirection, bool loop )
	{
		BehaviourGroupInfectedPack bgip;
		Class.CastTo( bgip, aiGroup.GetBehaviour() );
		if (bgip)
		{
			bgip.SetWaypoints( waypointParams, defaulAIZoneIndex, forwardDirection, loop );
		}
	}
	
	protected static void InitAI( Object obj, AIGroup aiGroup )
	{
		DayZCreatureAI creatureAi;
		Class.CastTo(creatureAi, obj);
		if (creatureAi)
		{
			creatureAi.InitAIAgent(aiGroup);
		}
	}
	
	// Game AI Object Creation
	
	protected static void CreateAIObjects( SgJsonAIHerdSpawnData aiHerdSpawnData, AIGroup aiGroup, int defaulAIZoneIndex )
	{
		int zombieCount = Math.RandomIntInclusive( aiHerdSpawnData.GetMinCount(), aiHerdSpawnData.GetMaxCount() );
		array<string> entityNames = aiHerdSpawnData.GetEntityNames();
		array<ref SgJsonAIZone> aiZones =  aiHerdSpawnData.GetAIZones();
		
		if ( aiZones.Count() == 0 ) return;
		
		SgJsonAIZone aiZone = aiZones[defaulAIZoneIndex];		
		array<ref SgJsonAISpawnPoint> spawnpoints = SgArray<SgJsonAISpawnPoint>.Copy( aiZone.GetSpawnpoints() );
		
		int missingSPCount = zombieCount - spawnpoints.Count();
		for ( int i = 0; i < missingSPCount; i++ )
		{
			FindNewSP( spawnpoints, aiZone );
		}
		
		for ( i = 0; i < zombieCount; i++ )
		{
			if ( spawnpoints.Count() == 0 ) return;
			SgJsonAISpawnPoint spawnpoint = spawnpoints.GetRandomElement();
			
			Object obj = GetGame().CreateObject( entityNames.GetRandomElement(), spawnpoint.GetPosition(), false, false, true );
			obj.SetPosition( spawnpoint.GetPosition() );
			m_AIEntities.Insert(EntityAI.Cast(obj));
			InitAI( obj, aiGroup );
			
			spawnpoints.RemoveItem(spawnpoint);
		}
	}
	
	protected static void FindNewSP( array<ref SgJsonAISpawnPoint> spawnpoints, SgJsonAIZone aiZone, int recursiveCounter = 0 )
	{
		if ( recursiveCounter == 5 ) return;
		
		float a = Math.RandomFloat01() * Math.PI2;
		float r = aiZone.GetRange() * Math.Sqrt( Math.RandomFloat01() );
		float spawnX = r * Math.Cos(a);
		float spawnZ = r * Math.Sin(a);

		vector newSpawnPos = aiZone.GetPosition();
		newSpawnPos[0] = newSpawnPos[0] + spawnX;
		newSpawnPos[2] = newSpawnPos[2] + spawnZ;
		newSpawnPos[1] = GetGame().SurfaceY( newSpawnPos[0], newSpawnPos[2] );
		
		AIWorld aiWorld = GetGame().GetWorld().GetAIWorld();
		aiWorld.SampleNavmeshPosition( newSpawnPos, 999, newSpawnPos);
		
		foreach ( SgJsonAISpawnPoint spawnpoint : spawnpoints )
		{
			if ( vector.Distance( newSpawnPos, spawnpoint.GetPosition() ) < 1 )
			{
				FindNewSP( spawnpoints, aiZone, recursiveCounter++ );
				return;
			}
		}
		
		spawnpoints.Insert( new SgJsonAISpawnPoint(newSpawnPos) );
	}
	
	// Getting Group Behaviour Names from Configs
	
	protected static string GetAiGroupBehaviourName(ESgAIGroup aiGroup) 
	{
		if ( m_aiGroupBehaviourNames.Contains(aiGroup) )
		{
			return m_aiGroupBehaviourNames[aiGroup];
		}
		else
		{
			string behaviourName = FindAiGroupBehaviourFor(aiGroup);
			m_aiGroupBehaviourNames.Insert( aiGroup, behaviourName);
			return behaviourName;
		}
	}
	
	protected static string FindAiGroupBehaviourFor(ESgAIGroup aiGroup)
	{
		string aiGroupName = GetNameForAIGroup(aiGroup);
		string cfgClassname = "CfgVehicles";
		int cfgItemCount = g_Game.ConfigGetChildrenCount(cfgClassname);
		
		for ( int i = 0; i < cfgItemCount; i++ )
		{
			string aiClassName;
			GetGame().ConfigGetChildName(cfgClassname, i, aiClassName);
			
			string aiFullPath = cfgClassname + " " + aiClassName;
			string configAiGroupType = GetGame().ConfigGetTextOut(aiFullPath + " " + "aiGroupType");
			
			if( configAiGroupType == aiGroupName && GetGame().ConfigGetTextOut(aiFullPath + " " + "scope") == "0" )
			{
				return GetGame().ConfigGetTextOut(aiFullPath + " " + "aiGroupBehaviour");
			}
		}
		
		return "";
	}
	
	// Getting AI Entities
	
	static array<ref EntityAI> GetAIEntities()
	{
		return m_AIEntities;
	}
}