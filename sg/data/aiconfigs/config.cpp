////////////////////////////////////////////////////////////////////
//DeRap: sg_data\aiconfigs\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 06 17:38:41 2019 : 'file' last modified on Mon Jul 29 10:57:32 2019
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class SG_data_aiconfigs{};
};
class AIParamsDebug
{
	showViewCones = "true";
	showLifeCycle = "true";
};
class AIParams
{
	maxNoiseRange = 400.0;
	rainToNoiseMultiplier = 10.0;
	seaToNoiseMultiplier = 15.0;
	noiseDampeningMultiplier = 0.7;
	noiseCollisionDampeningMultiplier = 0.2;
	noiseShotCollisionDampeningMultiplier = 0.5;
	groupLODDistance = 1000.0;
	class AgentTeams
	{
		TeamList[] = {"Player","BigGame","Zombies","Predator","AmbientLife"};
		class Player
		{
			friends[] = {"Player"};
		};
		class Predator
		{
			friends[] = {"Predator","AmbientLife"};
		};
		class BigGame
		{
			friends[] = {"BigGame","AmbientLife"};
		};
		class Zombies
		{
			friends[] = {"Zombies","AmbientLife"};
		};
		class AmbientLife
		{
			friends[] = {"AmbientLife"};
		};
	};
};
class GroupBehaviourTemplates
{
	class DZAmbientLifeGroupBeh
	{
		type = "AmbientLifeGroup";
		groupRadius = 10.0;
		groupMinCount = 2;
		groupMaxCount = 10;
		spawnMinDistanceBetweenAgents = 3.0;
	};
	class InfectedPatrolGroupBeh
	{
		type = "InfectedPack";
		alertDistributionSpeed = 20.0;
		catchUpTestDelay = 4.0;
		catchUpStartRadius = 30.0;
		catchUpTargetRadius = 7.0;
		groupRadius = 10.0;
		spawnMinDistanceBetweenAgents = 3.0;
		agentPathLength = 20.0;
		singleAgentSafeKeeperDelayMin = 1e+006;
		singleAgentSafeKeeperDelayMax = 1e+006;
		safeKeeperIntervalMin = 1e+006;
		safeKeeperIntervalMax = 1e+006;
		lifeCycleGroupSpeed = 1.0;
		changeTargetCooldown = 5.0;
		changeTargetAlertRatio = 1.2;
		changeTargetEffectRadius = 5.0;
		enragedRingDistanceMax = 10.0;
		enragedRingDistanceMin = 3.0;
		enragedReachDistanceMin = 0.8;
		enragedReachDistanceMax = 3.0;
		enragedOnReachCount = 3;
		maxEnrageTime = 10.0;
		predictFollowingMaxDistance = 10.0;
		predictFollowingTime = 2.5;
		predictReachFollowingMaxDistance = 2.0;
		predictReachFollowingTime = 1.0;
		subgroupSpacingMax = 500.0;
		class LifeCycleDayTime
		{
			class Activity1
			{
				endTimeMin = 10.0;
				endTimeMax = 10.0;
				zoneType = "HuntingGround";
				stayInZone = "false";
			};
			class Activity2
			{
				endTimeMin = 16.0;
				endTimeMax = 16.0;
				zoneType = "HuntingGround";
				stayInZone = "false";
			};
		};
	};
	class InfectedGuardGroupBeh: InfectedPatrolGroupBeh
	{
		type = "InfectedPack";
	};
	class InfectedStaticGroupBeh: InfectedPatrolGroupBeh
	{
		type = "InfectedPack";
		catchUpStartRadius = 1000.0;
		catchUpTargetRadius = 999.0;
	};
	class InfectedScreamerGroupBeh: InfectedPatrolGroupBeh
	{
		type = "InfectedPack";
	};
	class SGZWolfZombiePhase2GroupBeh
	{
		type = "Predators";
		alertDistributionSpeed = 0.0;
		catchUpTestDelay = 4.0;
		catchUpStartRadius = 20.0;
		catchUpTargetRadius = 5.0;
		groupRadius = 10.0;
		spawnMinDistanceBetweenAgents = 1.0;
		agentPathLength = 100.0;
		atNeedMinDuration = 60.0;
		atNeedMaxDuration = 120.0;
		singleAgentSafeKeeperDelayMin = 100.0;
		singleAgentSafeKeeperDelayMax = 100.0;
		preyAttractionRange = 0.1;
		innerOuterCircleRatio = 0.9;
		endAttractionRange = 10;
		attractionCooldown = 10;
		endAttractionTime = 30;
		targetEscapingSpeed = 1.3;
		killAddFear = 0.0;
		eatingTime = 600.0;
		huntingCooldown = 30.0;
		maxHuntingTime = 30;
		safeKeeperIntervalMin = 20;
		safeKeeperIntervalMax = 40;
		siegeAttackCountdownMin = 10000;
		siegeAttackCountdownMax = 10000;
		huntAttackCountdownMin = 1;
		huntAttackCountdownMax = 10;
		changeTargetCooldown = 5.0;
		changeTargetAlertRatio = 1.3;
		changeTargetEffectRadius = 6.0;
		subgroupSpacingMax = 500.0;
		class LifeCycleDayTime
		{
			class Activity1
			{
				endTimeMin = 10.0;
				endTimeMax = 10.0;
				zoneType = "HuntingGround";
				stayInZone = "false";
			};
			class Activity2
			{
				endTimeMin = 16.0;
				endTimeMax = 16.0;
				zoneType = "HuntingGround";
				stayInZone = "false";
			};
		};
	};
	class DZWolfGroupBeh
	{
		type = "Predators";
		alertDistributionSpeed = 20.0;
		catchUpTestDelay = 4.0;
		catchUpStartRadius = 80.0;
		catchUpTargetRadius = 7.0;
		groupRadius = 10.0;
		spawnMinDistanceBetweenAgents = 1.0;
		agentPathLength = 100.0;
		atNeedMinDuration = 60.0;
		atNeedMaxDuration = 120.0;
		singleAgentSafeKeeperDelayMin = 100.0;
		singleAgentSafeKeeperDelayMax = 100.0;
		preyAttractionRange = 350.0;
		innerOuterCircleRatio = 0.6;
		endAttractionRange = 10;
		attractionCooldown = 60;
		endAttractionTime = 300;
		targetEscapingSpeed = 1.5;
		killAddFear = 34;
		eatingTime = 600.0;
		huntingCooldown = 120.0;
		maxHuntingTime = 60;
		safeKeeperIntervalMin = 20;
		safeKeeperIntervalMax = 40;
		siegeAttackCountdownMin = 1;
		siegeAttackCountdownMax = 12;
		huntAttackCountdownMin = 1;
		huntAttackCountdownMax = 10;
		changeTargetCooldown = 5.0;
		changeTargetAlertRatio = 1.3;
		changeTargetEffectRadius = 6.0;
		subgroupSpacingMax = 500.0;
		class LifeCycleDayTime
		{
			class Activity1
			{
				endTimeMin = 8.5;
				endTimeMax = 8.5;
				zoneType = "Rest";
			};
			class Activity2
			{
				endTimeMin = 16.0;
				endTimeMax = 16.0;
				zoneType = "HuntingGround";
				stayInZone = "false";
			};
			class Activity3
			{
				endTimeMin = 18.5;
				endTimeMax = 19.5;
				zoneType = "Rest";
			};
			class Activity4
			{
				endTimeMin = 22.5;
				endTimeMax = 23.5;
				zoneType = "HuntingGround";
				stayInZone = "false";
			};
		};
	};
	class DZDeerGroupBeh
	{
		type = "WildHerbivores";
		alertDistributionSpeed = 20.0;
		catchUpTestDelay = 4.0;
		catchUpStartRadius = 30.0;
		catchUpTargetRadius = 7.0;
		groupRadius = 10.0;
		spawnMinDistanceBetweenAgents = 3.0;
		agentPathLength = 60.0;
		atNeedMinDuration = 60.0;
		atNeedMaxDuration = 60.0;
		singleAgentSafeKeeperDelayMin = 10.0;
		singleAgentSafeKeeperDelayMax = 100.0;
		safeKeeperIntervalMin = 10;
		safeKeeperIntervalMax = 30;
		class LifeCycleDayTime
		{
			class Activity1
			{
				endTimeMin = 8.0;
				endTimeMax = 9.0;
				zoneType = "Graze";
			};
			class Activity2
			{
				endTimeMin = 10.0;
				endTimeMax = 11.0;
				zoneType = "Rest";
			};
			class Activity3
			{
				endTimeMin = 13.0;
				endTimeMax = 14.0;
				zoneType = "Graze";
			};
			class Activity4
			{
				endTimeMin = 17.0;
				endTimeMax = 18.0;
				zoneType = "Graze";
			};
			class Activity5
			{
				endTimeMin = 20.0;
				endTimeMax = 21.0;
				zoneType = "Water";
			};
		};
	};
	class DZdomesticGroupBeh
	{
		type = "DomesticHerbivores";
		alertDistributionSpeed = 0.0;
		groupMaxAlertedSpreadRadius = 30.0;
		catchUpStartRadius = 50.0;
		catchUpTargetRadius = 15.0;
		groupRadius = 10.0;
		spawnMinDistanceBetweenAgents = 3.0;
		agentPathLength = 60.0;
		atNeedMinDuration = 60.0;
		atNeedMaxDuration = 60.0;
		singleAgentSafeKeeperDelayMin = 20.0;
		singleAgentSafeKeeperDelayMax = 20.0;
		pauseLifeCycleAfterEscapeDuration = 60;
		safeKeeperIntervalMin = 10.0;
		safeKeeperIntervalMax = 30.0;
		class LifeCycleDayTime
		{
			class Activity1
			{
				endTimeMin = 8.0;
				endTimeMax = 9.0;
				zoneType = "Rest";
			};
			class Activity2
			{
				endTimeMin = 11.0;
				endTimeMax = 12.0;
				zoneType = "Water";
			};
			class Activity3
			{
				endTimeMin = 13.0;
				endTimeMax = 14.0;
				zoneType = "Graze";
			};
			class Activity4
			{
				endTimeMin = 18.0;
				endTimeMax = 19.0;
				zoneType = "Graze";
			};
			class Activity5
			{
				endTimeMin = 20.0;
				endTimeMax = 21.0;
				zoneType = "Graze";
			};
		};
	};
	class DZSheepGroupBeh
	{
		type = "DomesticHerbivores";
		alertDistributionSpeed = 0.0;
		groupMaxAlertedSpreadRadius = 10.0;
		catchUpTestDelay = 1.0;
		catchUpStartRadius = 15.0;
		catchUpTargetRadius = 5.0;
		groupRadius = 10.0;
		spawnMinDistanceBetweenAgents = 3.0;
		agentPathLength = 30.0;
		atNeedMinDuration = 60.0;
		atNeedMaxDuration = 60.0;
		singleAgentSafeKeeperDelayMin = 20.0;
		singleAgentSafeKeeperDelayMax = 20.0;
		pauseLifeCycleAfterEscapeDuration = 60;
		safeKeeperIntervalMin = 10.0;
		safeKeeperIntervalMax = 20.0;
		class LifeCycleDayTime
		{
			class Activity1
			{
				endTimeMin = 8.0;
				endTimeMax = 9.0;
				zoneType = "Rest";
			};
			class Activity2
			{
				endTimeMin = 10.0;
				endTimeMax = 11.0;
				zoneType = "Graze";
			};
			class Activity3
			{
				endTimeMin = 13.0;
				endTimeMax = 14.0;
				zoneType = "Graze";
			};
			class Activity4
			{
				endTimeMin = 18.0;
				endTimeMax = 19.0;
				zoneType = "Rest";
			};
			class Activity5
			{
				endTimeMin = 20.0;
				endTimeMax = 21.0;
				zoneType = "Graze";
			};
		};
	};
};
class PathGraphFilters
{
	class ZombieCalm
	{
		class Flags
		{
			include[] = {"walk","door","inside"};
			exclude[] = {"disabled","swim","swimsea","jump","climb","crawl","crouch"};
		};
		class Costs
		{
			building = 5.0;
		};
	};
	class ZombieAlerted
	{
		class Flags
		{
			include[] = {"walk","door","inside","jump","climb"};
			exclude[] = {"disabled","crawl","crouch"};
		};
		class Costs
		{
			jump0 = 3.0;
			jump1 = 0.0;
			jump2 = 0.0;
			jump3 = 0.0;
			jump4 = 0.0;
			water = 5.0;
		};
	};
	class ZombieCrawl
	{
		class Flags
		{
			include[] = {"walk","door","inside"};
			exclude[] = {"disabled","swim","swimsea","jump","climb","crouch"};
		};
	};
	class ChickenOnRun
	{
		class Flags
		{
			include[] = {"walk","door","inside","jump"};
			exclude[] = {"disabled","swim","swimsea","climb"};
		};
		class Costs
		{
			jump0 = 0.0;
			jump1 = 0.0;
			jump2 = 0.0;
			jump3 = 0.0;
			jump4 = 0.1;
			water = 5.0;
		};
	};
	class DeerOnRun
	{
		class Flags
		{
			include[] = {"walk","door","inside","jumpover"};
			exclude[] = {"disabled","swim","swimsea","climb","crawl","crouch"};
		};
		class Costs
		{
			jump0 = 0.0;
			jump1 = 0.0;
			jump2 = 1.0;
			jump3 = 1.0;
			jump4 = 0.0;
			water = 1.0;
			building = 5.0;
		};
	};
	class RoeDeerOnRun
	{
		class Flags
		{
			include[] = {"walk","door","inside","jumpover"};
			exclude[] = {"disabled","swim","swimsea","climb","crawl","crouch"};
		};
		class Costs
		{
			jump0 = 0.0;
			jump1 = 0.0;
			jump2 = 1.0;
			jump3 = 0.0;
			jump4 = 0.0;
			water = 1.0;
			building = 5.0;
		};
	};
	class CowOnRun
	{
		class Flags
		{
			include[] = {"walk","door","inside","jumpover"};
			exclude[] = {"disabled","swim","swimsea","climb","crawl","crouch"};
		};
		class Costs
		{
			jump0 = 0.0;
			jump1 = 0.0;
			jump2 = 0.5;
			jump3 = 0.0;
			jump4 = 0.0;
			water = 1.0;
			building = 5.0;
		};
	};
	class WolfOnHunt
	{
		class Flags
		{
			include[] = {"walk","door","inside","jumpover"};
			exclude[] = {"disabled","swim","swimsea","climb","crawl","crouch"};
		};
		class Costs
		{
			jump0 = 0.0;
			jump1 = 0.0;
			jump2 = 1.0;
			jump3 = 1.0;
			jump4 = 0.0;
			water = 1.0;
		};
	};
	class WolfOnOuterCircle
	{
		class Flags
		{
			include[] = {"walk","jumpover"};
			exclude[] = {"disabled","swim","swimsea","climb","crawl","crouch"};
		};
		class Costs
		{
			jump0 = 0.0;
			jump1 = 0.0;
			jump2 = 1.0;
			jump3 = 1.0;
			jump4 = 0.0;
			water = 1.0;
		};
	};
	class NoJumping
	{
		class Flags
		{
			include[] = {"walk"};
			exclude[] = {"disabled","swim","swimsea","climb","crawl","crouch","jumpover"};
		};
		class Costs
		{
			jump0 = 0.0;
			jump1 = 0.0;
			jump2 = 1.0;
			jump3 = 0.0;
			jump4 = 0.0;
			water = 1.0;
		};
	};
	class InfectedEnraged
	{
		class Flags
		{
			include[] = {"walk","door","inside","jumpover"};
			exclude[] = {"disabled","swim","swimsea","climb","crawl","crouch"};
		};
		class Costs
		{
			jump0 = 0.0;
			jump1 = 0.0;
			jump2 = 0.0;
			jump3 = 0.8;
			jump4 = 0.0;
			water = 1.0;
		};
	};
};
