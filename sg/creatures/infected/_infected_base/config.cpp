////////////////////////////////////////////////////////////////////
//DeRap: sg_creatures\infected\_infected_base\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 01 16:12:29 2019 : 'file' last modified on Thu Aug 01 11:12:29 2019
////////////////////////////////////////////////////////////////////

#define _ARMA_

//(12 Enums)
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	stabilizedinaxisx = 1,
	stabilizedinaxisy = 2,
	destructno = 0,
	stabilizedinaxesboth = 3,
	stabilizedinaxesnone = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgAIBehaviours
{
	class Creature_InfectedBase
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "Predator";
		defaultGroupTemplateName = "InfectedPatrolGroupBeh";
		class PathAgent
		{
			radius = 0.3;
			height = 1.8;
			lengthRadius = 0.1;
		};
		class BehaviourHLInfectedPack
		{
			instantAlertRangeMin = 0.0;
			instantAlertRangeMax = 0.0;
			instantAlertStrength = 0.0;
			proximityAttackRange = 2.5;
			proximityAttackPredictTime = 0.5;
			attackCooldown = 2.5;
			attractionChangeTargetCooldown = 5.0;
			changeAttractionTargetRatio = 1.5;
			attractionNoiseStrengthTreshold = 3.0;
			attractionStrengthCeiling = 100.0;
			attractionStrengthDropSpeed = 5.0;
			attractionNoiseWindowStrengthTreshold = 20.0;
			attractionNoiseWindowSize = 5.0;
			attractionVisionPostponeTime = 3.5;
			class SlotCalm
			{
				class BehaviourCalm
				{
					class SoundsDuring
					{
						class Sound1{};
						probability = 0.9;
						RepeatTimeMin = 3.0;
						RepeatTimeMax = 6.0;
						RepeatEnabled = 1;
					};
					travelingMode = 1;
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 0;
					restWeight = 0;
					travelWeight = 40;
					grazeOnSpotDurationMin = 5;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 500;
					grazeWalkingDurationMax = 500;
					restingDurationMin = 5;
					restingDurationMax = 10;
					travelingDurationMin = 15;
					travelingDurationMax = 30;
					grazeWalkingSpeed = 0.2;
					travelingWalkingSpeed = 1.36;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 0.2;
						maxAngleSpeed = 40.0;
						slowRadius = 3.0;
						stopRadius = 1.0;
						pathFilter = "NoJumping";
					};
					class TravelingMovement
					{
						maxSpeed = 0.8;
						minSpeed = 0.2;
						acceleration = 0.3;
						maxAngleSpeed = 40.0;
						slowRadius = 3.0;
						stopRadius = 1.0;
						pathFilter = "NoJumping";
						slowToTurn = 1;
						smoothAcceleration = 1;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.8;
						minSpeed = 0.2;
						acceleration = 0.3;
						maxAngleSpeed = 40.0;
						slowRadius = 3.0;
						stopRadius = 1.0;
						pathFilter = "NoJumping";
						slowToTurn = 1;
						smoothAcceleration = 1;
					};
				};
			};
			class SlotPreAttracted
			{
				class BehaviourInfectedPackInterested
				{
					class SoundsEntering
					{
						class Sound1{};
					};
					class SoundsDuring
					{
						class Sound1{};
						probability = 0.9;
						RepeatTimeMin = 2.0;
						RepeatTimeMax = 4.0;
						RepeatEnabled = 1;
					};
					introStateDurationMin = "8.0f";
					introStateDurationMax = "13.0f";
					lookAtStateDurationMin = "8.0f";
					lookAtStateDurationMax = "13.0f";
					lookAtStateNoiseWindowStrengthTreshold = "11.0f";
					lookAtStateNoiseWindowSize = "5.0f";
				};
			};
			class SlotAttracted
			{
				class BehaviourInfectedPackSearching
				{
					class SoundsEntering
					{
						class Sound1{};
					};
					class SoundsDuring
					{
						class Sound1{};
						probability = 0.9;
						RepeatTimeMin = 2.0;
						RepeatTimeMax = 4.0;
						RepeatEnabled = 1;
					};
					attractionFollowupDistance = 10.0;
					noiseStrengthTreshold = 2.5;
					searchStateDurationMax = 20.0;
					cooldownStateDurationMin = 5.0;
					cooldownStateDurationMax = 15.0;
					class Movement
					{
						maxSpeed = 1.2;
						minSpeed = 0.2;
						acceleration = 0.5;
						maxAngleSpeed = 90.0;
						slowRadius = 4.0;
						stopRadius = 1.0;
						slowToTurn = 1;
						smoothAcceleration = 1;
						pathFilter = "NoJumping";
					};
				};
			};
			class SlotEnraged
			{
				class BehaviourInfectedPackEnraged
				{
					class SoundsEntering
					{
						class Sound1{};
					};
					class SoundsDuring
					{
						class Sound1{};
						probability = 0.9;
						RepeatTimeMin = 3.0;
						RepeatTimeMax = 6.0;
						RepeatEnabled = 1;
					};
					class Movement
					{
						maxSpeed = 4.4;
						minSpeed = 0.6;
						acceleration = 8.0;
						maxAngleSpeed = 180.0;
						slowRadius = 1.5;
						stopRadius = 0.8;
						slowToTurn = 1;
						smoothAcceleration = 1;
						pathFilter = "InfectedEnraged";
					};
					class MovementApproaching
					{
						maxSpeed = 4.4;
						maxSpeedRange = 2.5;
						optimalSpeed = 0.6;
						minSpeed = 0.4;
						acceleration = 1.5;
						maxAngleSpeed = 40.0;
						slowRadius = 1.0;
						stopRadius = 0.2;
						slowToTurn = 1;
						smoothAcceleration = 1;
						pathFilter = "InfectedEnraged";
					};
					class MovementReach
					{
						maxSpeed = 4.4;
						minSpeed = 0.2;
						acceleration = 2.0;
						maxAngleSpeed = 160.0;
						slowRadius = 1.6;
						stopRadius = 0.65;
						slowToTurn = 1;
						smoothAcceleration = 1;
						pathFilter = "InfectedEnraged";
					};
				};
			};
			class SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching
				{
					class SoundsDuring
					{
						class Sound1{};
						probability = 0.9;
						RepeatTimeMin = 3.0;
						RepeatTimeMax = 6.0;
						RepeatEnabled = 1;
					};
					class SoundsExiting
					{
						class Sound1{};
					};
					attractionFollowupDistance = 6.0;
					noiseStrengthTreshold = 4.0;
					searchStateDurationMax = 8.0;
					cooldownStateDurationMin = 4.0;
					cooldownStateDurationMax = 8.0;
					class Movement
					{
						maxSpeed = 1.2;
						minSpeed = 0.2;
						acceleration = 2.5;
						maxAngleSpeed = 180.0;
						slowRadius = 1.0;
						stopRadius = 0.2;
						slowToTurn = 1;
						smoothAcceleration = 1;
						pathFilter = "InfectedEnraged";
					};
					class MovementAlerted
					{
						maxSpeed = 4.4;
						minSpeed = 3.2;
						acceleration = 4.0;
						maxAngleSpeed = 180.0;
						slowRadius = 1.0;
						stopRadius = 0.2;
						slowToTurn = 1;
						smoothAcceleration = 1;
						pathFilter = "InfectedEnraged";
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 15;
				noiseToAlertMultiplier = 1.0;
				damageToAlertMultiplier = 100.0;
				noiseShotToAlertMultiplier = 0.5;
				class Calm
				{
					dropSpeed = 4;
					dropDelay = 2;
					maxAlertValue = 40;
				};
				class Alerted
				{
					dropSpeed = 15;
					dropDelay = 0;
					maxAlertValue = 100;
				};
				class AlertedExtra
				{
					dropSpeed = 25;
					dropDelay = 0.0;
					maxAlertValue = 200;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 0.0;
			rangeMax = 30.0;
			rangeShotMin = 0.0;
			rangeShotMax = 50.0;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 0.8;
				Zombies = 0.4;
				Player = 1.0;
			};
		};
		class TargetSystemDZBase
		{
			class VisionTeamMultipliers
			{
				BigGame = 0.8;
				Zombies = 1.0;
				Player = 1.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.5;
			visionManSizeProne = 0.3;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.5;
			visionRangeMin = 0.0;
			visionRangeMax = 40.0;
			visionFov = 0.9;
			visionPeripheralRangeMin = 1.0;
			visionPeripheralRangeMax = 3.0;
			visionPeripheralFov = 3.15;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.75;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 0.9;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 0.7;
			visionProximityRange = 0.0;
			visionProximityStrengthMult = 0;
			visionCloseRange = 0.0;
			visionCloseHeight = 0.0;
			visionCloseStrengthMult = 0.0;
		};
	};
	class Creature_InfectedGuard: Creature_InfectedBase
	{
		defaultGroupTemplateName = "InfectedGuardGroupBeh";
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					travelWeight = 10;
				};
			};
		};
	};
	class Creature_InfectedGuardDoctor: Creature_InfectedGuard
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_DoctorFat_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_DoctorFat_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_DoctorFat_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_DoctorFat_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_DoctorFat_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_DoctorFat_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
	class Creature_InfectedGuardWorker: Creature_InfectedGuard
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_HeavyIndustryWorker_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_HeavyIndustryWorker_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_HeavyIndustryWorker_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_HeavyIndustryWorker_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_HeavyIndustryWorker_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnraged: SlotEnraged
			{
				class BehaviourInfectedPackEnraged: BehaviourInfectedPackEnraged
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_Normal2_CallToArmsShort_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_HeavyIndustryWorker_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
	class Creature_InfectedGuardPoliceman_fat: Creature_InfectedGuard
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_PolicemanFat_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_PolicemanFat_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_PolicemanFat_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_PolicemanFat_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_PolicemanFat_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnraged: SlotEnraged
			{
				class BehaviourInfectedPackEnraged: BehaviourInfectedPackEnraged
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_Fat_CallToArmsShort_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_PolicemanFat_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
	class Creature_InfectedGuardPolicewoman_normal: Creature_InfectedGuard
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_PoliceWomanNormal_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_PoliceWomanNormal_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_PoliceWomanNormal_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_PoliceWomanNormal_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_PoliceWomanNormal_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnraged: SlotEnraged
			{
				class BehaviourInfectedPackEnraged: BehaviourInfectedPackEnraged
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_Normal_CallToArmsShort_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_PoliceWomanNormal_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
	class Creature_InfectedPatrol: Creature_InfectedBase{};
	class Creature_InfectedPatrolCitizenA_normal_f: Creature_InfectedPatrol
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_CitizenANormal_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_CitizenANormal_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_CitizenANormal_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_CitizenANormal_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_CitizenANormal_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_CitizenANormal_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
	class Creature_InfectedPatrolCitizenA_skinny_m: Creature_InfectedPatrol
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenASkinny_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenASkinny_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenASkinny_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenASkinny_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenASkinny_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnraged: SlotEnraged
			{
				class BehaviourInfectedPackEnraged: BehaviourInfectedPackEnraged
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_Skinny_CallToArmsShort_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenASkinny_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
	class Creature_InfectedPatrolCitizenB_fat: Creature_InfectedPatrol
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenBFat_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenBFat_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenBFat_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenBFat_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenBFat_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnraged: SlotEnraged
			{
				class BehaviourInfectedPackEnraged: BehaviourInfectedPackEnraged
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_Fat_CallToArmsShort_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_CitizenBFat_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
	class Creature_InfectedStatic: Creature_InfectedBase
	{
		defaultGroupTemplateName = "InfectedStaticGroupBeh";
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					travelWeight = 0;
				};
			};
		};
	};
	class Creature_InfectedStaticSkater_young_m: Creature_InfectedStatic
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SkaterYoung_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SkaterYoung_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SkaterYoung_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SkaterYoung_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SkaterYoung_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SkaterYoung_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
	class Creature_InfectedStaticVillager_old_f: Creature_InfectedStatic
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_VillagerOld_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_VillagerOld_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_VillagerOld_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_VillagerOld_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_VillagerOld_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnraged: SlotEnraged
			{
				class BehaviourInfectedPackEnraged: BehaviourInfectedPackEnraged
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_Skinny_CallToArmsShort_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbF_VillagerOld_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
	class Creature_InfectedStaticVillager_old_m: Creature_InfectedStatic
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_VillagerOld_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_VillagerOld_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_VillagerOld_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_VillagerOld_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_VillagerOld_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnraged: SlotEnraged
			{
				class BehaviourInfectedPackEnraged: BehaviourInfectedPackEnraged
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_Old_CallToArmsShort_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_VillagerOld_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
	class Creature_InfectedScreamer: Creature_InfectedBase
	{
		defaultGroupTemplateName = "InfectedScreamerGroupBeh";
	};
	class Creature_InfectedScreamerSoldier_normal_m: Creature_InfectedScreamer
	{
		class BehaviourHLInfectedPack: BehaviourHLInfectedPack
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourCalm: BehaviourCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SoldierNormal_Base_SG_CalmMove_Soundset"};
						};
					};
				};
			};
			class SlotPreAttracted: SlotPreAttracted
			{
				class BehaviourInfectedPackInterested: BehaviourInfectedPackInterested
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SoldierNormal_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SoldierNormal_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
			class SlotAttracted: SlotAttracted
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SoldierNormal_Base_SG_DisturbedIdle_Soundset"};
						};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SoldierNormal_Base_SG_ChaseMove_Soundset"};
						};
					};
				};
			};
			class SlotEnragedTargetLost: SlotEnragedTargetLost
			{
				class BehaviourInfectedPackSearching: BehaviourInfectedPackSearching
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = 1;
							sounds[] = {"ZmbM_SoldierNormal_Base_SG_AlertedMove_Soundset"};
						};
					};
				};
			};
		};
	};
};
class CfgDamages
{
	class SG_InfectedBiteDamage
	{
		bone = "chest";
		ammo = "SG_MeleeInfected";
		radius = 0.7;
		duration = 0.5;
	};
	class SG_InfectedBiteDamageLHand
	{
		bone = "lefthand";
		ammo = "SG_MeleeInfected";
		radius = 0.4;
		duration = 0.5;
	};
	class SG_InfectedBiteDamageRHand
	{
		bone = "righthand";
		ammo = "SG_MeleeInfected";
		radius = 0.4;
		duration = 0.5;
	};
	class SG_InfectedFriendlySequel1_chest
	{
		bone = "spine3";
		ammo = "SG_FriendlyInfectedSequel1";
		radius = 0.4;
		duration = 0.3;
		invertTeams = "true";
	};
	class SG_InfectedFriendlySequel1_Rforearm
	{
		bone = "rightforearmroll";
		ammo = "SG_FriendlyInfectedSequel2";
		radius = 0.2;
		duration = 0.3;
		invertTeams = "true";
	};
	class SG_InfectedFriendlySequel1_Lforearm
	{
		bone = "leftforearmroll";
		ammo = "SG_FriendlyInfectedSequel2";
		radius = 0.2;
		duration = 0.3;
		invertTeams = "true";
	};
	class SG_InfectedFriendlySequel2_chest
	{
		bone = "spine3";
		ammo = "SG_FriendlyInfectedSequel2";
		radius = 0.4;
		duration = 0.3;
		invertTeams = "true";
	};
	class SG_InfectedFriendlySequel2_Rforearm
	{
		bone = "rightforearmroll";
		ammo = "SG_FriendlyInfectedSequel2";
		radius = 0.2;
		duration = 0.3;
		invertTeams = "true";
	};
	class SG_InfectedFriendlySequel2_Lforearm
	{
		bone = "leftforearmroll";
		ammo = "SG_FriendlyInfectedSequel2";
		radius = 0.2;
		duration = 0.3;
		invertTeams = "true";
	};
};
class CfgNoises
{
	class SG_InfectedStepNoise
	{
		type = "sound";
		continuousRange = 100;
		strength = 10;
	};
};
class CfgPatches
{
	class SG_Creatures
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_AI","DZ_Animals"};
	};
};
class CfgVehicles
{
	class AnimalBase;
	class SG_InfectedBase: AnimalBase
	{
		simulation = "dayzanimal";
		scope = 0;
		displayName = "$STR_cfgvehicles_infected0";
		injuryLevels[] = {1.0,0.5,0.2,0.0};
		DamageSphereAmmos[] = {"SG_MeleeInfected","SG_FriendlyInfectedSequel1","SG_FriendlyInfectedSequel2"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLabels[] = {1.0,0.7,0.5,0.3,0.0};
				};
				class Blood
				{
					hitpoints = 5000;
				};
				class Shock
				{
					hitpoints = 5000;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 4;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"Head"};
				};
				class Neck
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0.5;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"Neck"};
					transferToZonesNames[] = {"Head"};
					transferToZonesCoefs[] = {0.5};
					fatalInjuryCoef = 0.01;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0.5;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"Spine1","Spine3"};
					fatalInjuryCoef = 0.01;
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 100;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.25;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 0.4;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"LeftArm","LeftForeArm"};
					transferToZonesNames[] = {"Torso"};
					transferToZonesCoefs[] = {0.5};
					fatalInjuryCoef = 0.01;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 100;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.25;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 0.4;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"RightArm","RightForeArm"};
					transferToZonesNames[] = {"Torso"};
					transferToZonesCoefs[] = {0.5};
					fatalInjuryCoef = 0.01;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 100;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.25;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 0.4;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"LeftLeg","LeftUpLeg"};
					transferToZonesNames[] = {"Torso"};
					transferToZonesCoefs[] = {0.5};
					fatalInjuryCoef = 0.01;
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 100;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.25;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 0.4;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"RightLeg","RightUpLeg"};
					transferToZonesNames[] = {"Torso"};
					transferToZonesCoefs[] = {0.5};
					fatalInjuryCoef = 0.01;
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 100;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"LeftFoot"};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 100;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"RightFoot"};
				};
			};
		};
		class AnimEvents
		{
			class Damages
			{
				class SG_InfectedBiteDamage
				{
					damage = "SG_InfectedBiteDamage";
					id = 1;
				};
				class SG_InfectedBiteDamageLHand
				{
					damage = "SG_InfectedBiteDamageLHand";
					id = 2;
				};
				class SG_InfectedBiteDamageRHand
				{
					damage = "SG_InfectedBiteDamageRHand";
					id = 3;
				};
				class SG_InfectedFriendlySequel1_chestA
				{
					damage = "SG_InfectedFriendlySequel1_chest";
					id = 10;
				};
				class SG_InfectedFriendlySequel1_chestB
				{
					damage = "SG_InfectedFriendlySequel1_chest";
					id = 11;
				};
				class SG_InfectedFriendlySequel1_RforearmA
				{
					damage = "SG_InfectedFriendlySequel1_Rforearm";
					id = 12;
				};
				class SG_InfectedFriendlySequel1_RforearmB
				{
					damage = "SG_InfectedFriendlySequel1_Rforearm";
					id = 13;
				};
				class SG_InfectedFriendlySequel1_LforearmA
				{
					damage = "SG_InfectedFriendlySequel1_Lforearm";
					id = 14;
				};
				class SG_InfectedFriendlySequel1_LforearmB
				{
					damage = "SG_InfectedFriendlySequel1_Lforearm";
					id = 15;
				};
				class SG_InfectedFriendlySequel2_chest
				{
					damage = "SG_InfectedFriendlySequel2_chest";
					id = 20;
				};
				class SG_InfectedFriendlySequel2_Rforearm
				{
					damage = "SG_InfectedFriendlySequel2_Rforearm";
					id = 21;
				};
				class SG_InfectedFriendlySequel2_Lforearm
				{
					damage = "SG_InfectedFriendlySequel2_Lforearm";
					id = 22;
				};
			};
		};
		class CommandMoveSettings
		{
			useSpeedMapping = 0;
			movementSpeedMapping[] = {0.0,0.25,0.5,1.2,4.5,12.2};
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.2;
			lookAtFilterSpeed = 1.57;
		};
	};
};
