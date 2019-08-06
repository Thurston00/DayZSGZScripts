////////////////////////////////////////////////////////////////////
//DeRap: sg_entities_characters\bodies\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 06 17:38:41 2019 : 'file' last modified on Mon Jul 29 11:13:29 2019
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

class CfgPatches
{
	class SG_EntitiesActors
	{
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class SurvivorM_Mirek;
	class SG_SurvivorM_Mirek: SurvivorM_Mirek
	{
		model = "\sg\entities\characters\bodies\bodyparts_above0.p3d";
	};
	class DZ_LightAI;
	class ZombieBase: DZ_LightAI
	{
		scope = 0;
		armor = 2.35;
		armorStructural = 2.0;
		faction = "dz_Civ_US";
		rarityUrban = -1;
		extCameraPosition[] = {0.15,0,-2};
		accuracy = 0;
		threat[] = {1,0.05,0.05};
		displayName = "INFECTED";
		simulation = "zombie";
		vehicleClass = "Zombie";
		model = "\DZ\characters\zombies\hermit_newbindpose.p3d";
		zombieLoot = "civilian";
		storageCategory = 3;
		newAnimSystemSoundStepOverride = "walk";
		moves = "CfgMovesMaleSdr2";
		sensitivity = 4;
		sensitivityEar = 0.15;
		wakeDistance = 500;
		minIdleStayTime = 5;
		maxIdleStayTime = 15;
		minRoamRange = 50;
		maxRoamRange = 80;
		meleeAmmo = "MeleeZombie";
		attackSounds = "zombie_attack";
		spottedSounds = "zombie_spotted";
		chaseSounds = "zombie_chase";
		idleSounds = "zombie_idle";
		hiddenSelections[] = {"camo"};
		languages[] = {};
		woman = 0;
		htMin = 60;
		htMax = 1800;
		afMax = 30;
		mfMax = 0;
		mFact = 1;
		tBody = 37;
		glassesEnabled = 0;
		selectionPersonality = "personality";
		gestures = "CfgGesturesMale";
		faceType = "MaleWhiteHeadNew";
		identityTypes[] = {"zombie1","zombie2"};
		boneHead = "head";
		boneHeadCutScene = "headcutscene";
		boneLEye = "eyeleft";
		boneREye = "eyeright";
		boneLEyelidUp = "face_eyelidupperleft";
		boneREyelidUp = "face_eyelidupperright";
		boneLEyelidDown = "face_eyelidlowerleft";
		boneREyelidDown = "face_eyelidlowerright";
		boneLPupil = "l_pupila";
		boneRPupil = "r_pupila";
		bonePrimaryWeapon = "weapon";
		launcherBone = "launcher";
		handGunBone = "RightHand";
		weaponBone = "weapon";
		selectionHeadWound = "injury_head";
		selectionBodyWound = "injury_body";
		selectionLArmWound = "injury_hands";
		selectionRArmWound = "injury_hands";
		selectionLLegWound = "injury_legs";
		selectionRLegWound = "injury_legs";
		memoryPointLStep = "footstepL";
		memoryPointRStep = "footstepR";
		memoryPointAim = "aimPoint";
		memoryPointCameraTarget = "camera";
		memoryPointCommonDamage = "l_femur_hit";
		memoryPointLeaningAxis = "leaning_axis";
		memoryPointAimingAxis = "aiming_axis";
		memoryPointHeadAxis = "head_axis";
		selectionLBrow = "lBrow";
		selectionMBrow = "mBrow";
		selectionRBrow = "rBrow";
		selectionLMouth = "lMouth";
		selectionMMouth = "mMouth";
		selectionRMouth = "rMouth";
		selectionEyelid = "Eyelids";
		selectionLip = "LLip";
		leftArmToElbow[] = {"LeftArm",0.5,"LeftArmExtra",0.5,"LeftArmRoll",0};
		leftArmFromElbow[] = {"LeftElbowExtra",0.5,"LeftForeArm",0.5,"LeftForeArmExtra",0.5,"LeftForeArmRoll",0.5,"leftWristExtra",0.5};
		leftWrist = "LeftHand";
		leftShoulder = "LeftShoulder";
		leftHand[] = {"leftHandThumb3","leftHandThumb2","leftHandThumb1","leftHandIndex3","leftHandIndex2","leftHandIndex1","leftHandMiddle3","leftHandMiddle2","leftHandMiddle1","leftHandRing3","leftHandRing2","leftHandRing1","leftHandRing","leftHandPinky3","leftHandPinky2","leftHandPinky1"};
		leftArmPoints[] = {"LeftShoulder","lelbow","lelbow_axis","lwrist"};
		rightArmToElbow[] = {"rightArm",0.5,"RightArmExtra",0.5,"rightArmRoll",0};
		rightArmFromElbow[] = {"RightElbowExtra",0.5,"rightForeArm",0.5,"RightForeArmExtra",0.5,"rightForeArmRoll",0.5,"rightWristExtra",0.5};
		rightWrist = "rightHand";
		rightShoulder = "rightShoulder";
		rightHand[] = {"rightHandThumb3","rightHandThumb2","rightHandThumb1","rightHandIndex3","rightHandIndex2","rightHandIndex1","rightHandMiddle3","rightHandMiddle2","rightHandMiddle1","rightHandRing3","rightHandRing2","rightHandRing1","rightHandRing","rightHandPinky3","rightHandPinky2","rightHandPinky1"};
		rightArmPoints[] = {"rightShoulder","relbow","relbow_axis","rwrist"};
		leftLegToKnee[] = {"LeftUpLeg",0.5,"LeftUpLegRoll",0};
		leftLegFromKnee[] = {"LeftLeg",0,"LeftLegRoll",0.5};
		leftHeel = "leftFoot";
		leftHip = "pelvis";
		leftFoot[] = {"LeftToeBase"};
		leftLegPoints[] = {"lfemur","lknee","lknee_axis","lankle"};
		rightLegToKnee[] = {"rightUpLeg",0.5,"rightUpLegRoll",0};
		rightLegFromKnee[] = {"rightLeg",0,"rightLegRoll",0.5};
		rightHeel = "rightFoot";
		rightHip = "pelvis";
		rightFoot[] = {"RightToeBase"};
		rightLegPoints[] = {"rfemur","rknee","rknee_axis","rankle"};
		triggerAnim = "dz\Anims\data\anim\sdr\trigger.rtm";
		minGunElev = -80;
		maxGunElev = 60;
		minGunTurn = -1;
		maxGunTurn = 1;
		minHeadTurnAI = -60;
		maxHeadTurnAI = 60;
		vegetation0[] = {"dz\sounds\arma2\Characters\Noises\Bush\bush1",1,1,20};
		vegetation1[] = {"dz\sounds\arma2\Characters\Noises\Bush\bush2",1,1,20};
		vegetation2[] = {"dz\sounds\arma2\Characters\Noises\Bush\bush3",1,1,20};
		vegetationSounds[] = {"vegetation0",0.33,"vegetation1",0.33,"vegetation2",0.33};
		class TalkTopics{};
		class Cargo
		{
			itemsCargoSize[] = {3,4};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class Eventhandlers
		{
			killed = "_this call event_zombieKilled;";
		};
		class ViewPilot
		{
			initFov = 0.8;
			minFov = 0.375;
			maxFov = 1;
			initAngleX = 8;
			minAngleX = -85;
			maxAngleX = 75;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\zombies\data\coveralls.rvmat","dz\characters\zombies\data\coveralls_injury.rvmat","dz\characters\zombies\data\coveralls_injury.rvmat"};
		};
		class HitDamage
		{
			class Group0
			{
				hitSounds[] = {};
				damageSounds[] = {};
			};
			class Group1
			{
				hitSounds[] = {};
				damageSounds[] = {};
			};
			class Group2
			{
				hitSounds[] = {};
				damageSounds[] = {};
			};
			class Group3
			{
				hitSounds[] = {};
				damageSounds[] = {};
			};
		};
		class HitPoints
		{
			class HitHead
			{
				armor = 0.3;
				material = -1;
				name = "head_hit";
				passThrough = 1;
				memoryPoint = "pilot";
			};
			class HitBody: HitHead
			{
				armor = 1.6;
				name = "body";
				memoryPoint = "aimPoint";
			};
			class HitSpine: HitHead
			{
				armor = 1.6;
				name = "Spine2";
				memoryPoint = "aimPoint";
			};
			class HitHands: HitHead
			{
				armor = 0.5;
				material = -1;
				name = "hands";
				passThrough = 1;
			};
			class HitLArm: HitHands
			{
				name = "LeftArm";
				memoryPoint = "lelbow";
			};
			class HitRArm: HitHands
			{
				name = "RightArm";
				memoryPoint = "relbow";
			};
			class HitLForeArm: HitHands
			{
				name = "LeftForeArm";
				memoryPoint = "lwrist";
			};
			class HitRForeArm: HitHands
			{
				name = "RightForeArm";
				memoryPoint = "rwrist";
			};
			class HitLHand: HitHands
			{
				name = "LeftHand";
				memoryPoint = "LeftHandMiddle1";
			};
			class HitRHand: HitHands
			{
				name = "RightHand";
				memoryPoint = "RightHandMiddle1";
			};
			class HitLegs: HitHands
			{
				name = "legs";
				memoryPoint = "pelvis";
			};
			class HitLLeg: HitHands
			{
				name = "LeftLeg";
				memoryPoint = "lknee";
			};
			class HitLLegUp: HitHands
			{
				name = "LeftUpLeg";
				memoryPoint = "lfemur";
			};
			class HitRLeg: HitHands
			{
				name = "RightLeg";
				memoryPoint = "rknee";
			};
			class HitRLegUp: HitHands
			{
				name = "RightUpLeg";
				memoryPoint = "rfemur";
			};
		};
		class AttackActions
		{
			class AttackLong
			{
				attackName = "attackLong";
				stanceName = "erect";
				moveAnimNames[] = {"run","sprint"};
				distance = 4.9;
				time = 2.5;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 2.2;
				ammoType = "MeleeZombie";
			};
			class AttackRun
			{
				attackName = "attackRun";
				stanceName = "erect";
				moveAnimNames[] = {"run","sprint"};
				distance = 2.3;
				time = 1.0;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.0;
				ammoType = "MeleeZombie";
			};
			class AttackShort
			{
				attackName = "attackShort";
				stanceName = "erect";
				moveAnimNames[] = {"idle"};
				distance = 1.0;
				time = 1.0;
				yawAngle = 0;
				pitchAngle = 0;
				attackWidth = 1.0;
				ammoType = "MeleeZombie";
			};
			class AttackShortLow
			{
				attackName = "attackShort";
				stanceName = "erect";
				moveAnimNames[] = {"idle"};
				distance = 1.0;
				time = 1.0;
				yawAngle = 0;
				pitchAngle = -45;
				attackWidth = 1.0;
				ammoType = "MeleeZombie";
			};
			class CrawlAttackMove
			{
				attackName = "crawlAttackMove";
				stanceName = "crawl";
				moveAnimNames[] = {"walk"};
				distance = 1.3;
				time = 1.5;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 1.0;
				ammoType = "MeleeZombie";
			};
			class CrawlAttackStill
			{
				attackName = "crawlAttackStill";
				stanceName = "crawl";
				moveAnimNames[] = {"idle"};
				distance = 1.2;
				time = 1.1;
				yawAngle = 0;
				pitchAngle = 45;
				attackWidth = 1.0;
				ammoType = "MeleeZombie";
			};
		};
		class AIAgentTemplate
		{
			name = "zombie";
			HeadLookBoneName = "lookat";
			teamName = "Zombies";
			class BehaviourHLZombie
			{
				damageToCrawl = 0.04;
				crawlProbability = 0.05;
				class SlotCalm
				{
					class BehaviourZombieCalm
					{
						StandingDurationMin = 4;
						StandingDurationMax = 8;
						WalkingDurationMin = 4;
						WalkingDurationMax = 12;
						MinLookTime = 1;
						MaxLookTime = 2;
						IsAttractMode = 0;
						class WalkingMovement
						{
							maxSpeed = 0.5;
							minSpeed = 0.0;
							acceleration = 5.0;
							maxAngleSpeed = 240.0;
							slowRadius = 0.0;
							stopRadius = 0.5;
						};
						class CrawlingMovement
						{
							maxSpeed = 0.476;
							minSpeed = 0.2;
							acceleration = 5.0;
							maxAngleSpeed = 240.0;
							slowRadius = 0.0;
							stopRadius = 0.5;
						};
					};
				};
				class SlotAttracted
				{
					class BehaviourZombieCalm
					{
						StandingDurationMin = 0;
						StandingDurationMax = 0;
						WalkingDurationMin = 0;
						WalkingDurationMax = 0;
						MinLookTime = 2.5;
						MaxLookTime = 5;
						IsAttractMode = 1;
						class WalkingMovement
						{
							maxSpeed = 0.0;
							minSpeed = 0.0;
							acceleration = 5.0;
							maxAngleSpeed = 240.0;
							slowRadius = 0.0;
							stopRadius = 0.5;
						};
						class CrawlingMovement
						{
							maxSpeed = 0.0;
							minSpeed = 0.0;
							acceleration = 5.0;
							maxAngleSpeed = 240.0;
							slowRadius = 0.0;
							stopRadius = 0.5;
						};
					};
				};
				class SlotAlerted
				{
					class BehaviourZombieAlerted
					{
						class SearchingAroundMovement
						{
							maxSpeed = 3.0;
							minSpeed = 0.0;
							acceleration = 3.0;
							maxAngleSpeed = 240.0;
							slowRadius = 0.0;
							stopRadius = 0.5;
							pathFilter = "ZombieAlerted";
						};
						class SearchingPerceptMovement
						{
							maxSpeed = 3.0;
							minSpeed = 0.0;
							acceleration = 3.0;
							maxAngleSpeed = 240.0;
							slowRadius = 0.0;
							stopRadius = 0.5;
							pathFilter = "ZombieAlerted";
						};
						class ChaseToAttackMovement
						{
							maxSpeed = 6.86;
							minSpeed = 2.0;
							acceleration = 3.0;
							maxAngleSpeed = 360.0;
							slowRadius = 1.5;
							stopRadius = 1.0;
							pathFilter = "ZombieAlerted";
						};
						class ChaseJumpOverObstacle
						{
							maxSpeed = 6.86;
							minSpeed = 2.0;
							acceleration = 3.0;
							maxAngleSpeed = 360.0;
							slowRadius = 1.5;
							stopRadius = 1.0;
							pathFilter = "ZombieAlerted";
						};
						class SearchingAroundCrawlMovement
						{
							maxSpeed = 0.476;
							minSpeed = 0.2;
							acceleration = 3.0;
							maxAngleSpeed = 240.0;
							slowRadius = 0.0;
							stopRadius = 0.5;
						};
						class SearchingPerceptCrawlMovement
						{
							maxSpeed = 0.476;
							minSpeed = 0.2;
							acceleration = 3.0;
							maxAngleSpeed = 240.0;
							slowRadius = 0.0;
							stopRadius = 0.5;
						};
						class ChaseToAttackCrawlMovement
						{
							maxSpeed = 1.568;
							minSpeed = 1.0;
							acceleration = 3.0;
							maxAngleSpeed = 360.0;
							slowRadius = 1.0;
							stopRadius = 0.5;
						};
						attackDistance = 8.0;
						staminaChangeDuringChasing = 3.0;
						targetVisionSelectionTime = 10.0;
						targetNoiseSelectionTime = 20.0;
						visionTimeToChase = 5.0;
					};
				};
				class AlertSystem
				{
					visionToAlertMultiplier = 20.0;
					noiseToAlertMultiplier = 0.75;
					damageToAlertMultiplier = 10000.0;
					class Calm
					{
						DropSpeed = 10;
						DropDelay = 1;
						MaxAlertValue = 20;
					};
					class Attracted
					{
						DropSpeed = 4;
						DropDelay = 5;
						MaxAlertValue = 80;
					};
					class Alerted
					{
						DropSpeed = 6;
						DropDelay = 10;
						MaxAlertValue = 100;
					};
				};
			};
			class TargetSystemDZBase
			{
				visionRangeMin = 12;
				visionRangeMax = 84;
				visionFov = 1.0;
				visionPeripheralRangeMin = 3;
				visionPeripheralRangeMax = 36;
				visionPeripheralFov = 3.3;
				visionManSizeStand = 1.0;
				visionManSizeCrouch = 0.6;
				visionManSizeProne = 0.25;
				visionAngularSpeedMin = 0.1;
				visionAngularSpeedMax = 0.25;
				visionAngularSpeedMaxMult = 8;
				visionNightMinMult = 0.9;
				visionNightMaxMult = 0.2;
				visionRainMinMult = 1.0;
				visionRainMaxMult = 0.8;
				visionFogMinMult = 0.9;
				visionFogMaxMult = 0.5;
			};
			class NoiseSystemParams
			{
				rangeMin = 10.0;
				rangeMax = 25.0;
				rangeShotMin = 50.0;
				rangeShotMax = 200.0;
				class NoiseStrengthTeamMultipliers
				{
					BigGame = 1.0;
					Zombies = 0.0;
					Player = 1.0;
				};
			};
		};
		class NoiseTemplates
		{
			class StepNoise
			{
				strength = 10.0;
				type = "sound";
			};
		};
		class AnimSystem
		{
			meshObject = "dz\characters\zombies\z_hermit.xob";
			animGraph = "dz\anims\cfg\zombie\zombie.ag";
			class StepNoises
			{
				class run
				{
					strength = 100.0;
					type = "sound";
				};
			};
			class AnimEventSounds
			{
				class zombie_attack
				{
					sounds[] = {"DZ\sounds\effects\zombie\attack_0","DZ\sounds\effects\zombie\attack_1","DZ\sounds\effects\zombie\attack_2","DZ\sounds\effects\zombie\attack_3","DZ\sounds\effects\zombie\attack_4","DZ\sounds\effects\zombie\attack_5","DZ\sounds\effects\zombie\attack_6","DZ\sounds\effects\zombie\attack_7","DZ\sounds\effects\zombie\attack_8","DZ\sounds\effects\zombie\attack_9","DZ\sounds\effects\zombie\attack_10","DZ\sounds\effects\zombie\attack_11","DZ\sounds\effects\zombie\attack_13"};
					volume = 1;
					distance = 50;
				};
				class zombie_spotted
				{
					sounds[] = {"DZ\sounds\effects\zombie\spotted_0","DZ\sounds\effects\zombie\spotted_1","DZ\sounds\effects\zombie\spotted_2","DZ\sounds\effects\zombie\spotted_3","DZ\sounds\effects\zombie\spotted_4","DZ\sounds\effects\zombie\spotted_5","DZ\sounds\effects\zombie\spotted_6","DZ\sounds\effects\zombie\spotted_7","DZ\sounds\effects\zombie\spotted_8","DZ\sounds\effects\zombie\spotted_9","DZ\sounds\effects\zombie\spotted_10","DZ\sounds\effects\zombie\spotted_11","DZ\sounds\effects\zombie\spotted_12","DZ\sounds\effects\zombie\spotted_13"};
					volume = 1;
					distance = 50;
				};
				class zombie_idle
				{
					sounds[] = {"DZ\sounds\effects\zombie\idle_0","DZ\sounds\effects\zombie\idle_1","DZ\sounds\effects\zombie\idle_2","DZ\sounds\effects\zombie\idle_3","DZ\sounds\effects\zombie\idle_4","DZ\sounds\effects\zombie\idle_5","DZ\sounds\effects\zombie\idle_6","DZ\sounds\effects\zombie\idle_7","DZ\sounds\effects\zombie\idle_8","DZ\sounds\effects\zombie\idle_9","DZ\sounds\effects\zombie\idle_10","DZ\sounds\effects\zombie\idle_11","DZ\sounds\effects\zombie\idle_12","DZ\sounds\effects\zombie\idle_13","DZ\sounds\effects\zombie\idle_14","DZ\sounds\effects\zombie\idle_15","DZ\sounds\effects\zombie\idle_16","DZ\sounds\effects\zombie\idle_17","DZ\sounds\effects\zombie\idle_18","DZ\sounds\effects\zombie\idle_19","DZ\sounds\effects\zombie\idle_20","DZ\sounds\effects\zombie\idle_21","DZ\sounds\effects\zombie\idle_22","DZ\sounds\effects\zombie\idle_23","DZ\sounds\effects\zombie\idle_24","DZ\sounds\effects\zombie\idle_25","DZ\sounds\effects\zombie\idle_26","DZ\sounds\effects\zombie\idle_27","DZ\sounds\effects\zombie\idle_28"};
					volume = 1;
					distance = 50;
				};
				class zombie_chase
				{
					sounds[] = {"DZ\sounds\effects\zombie\chase_0","DZ\sounds\effects\zombie\chase_1","DZ\sounds\effects\zombie\chase_2","DZ\sounds\effects\zombie\chase_3","DZ\sounds\effects\zombie\chase_4","DZ\sounds\effects\zombie\chase_5","DZ\sounds\effects\zombie\chase_6","DZ\sounds\effects\zombie\chase_7","DZ\sounds\effects\zombie\chase_8","DZ\sounds\effects\zombie\chase_9","DZ\sounds\effects\zombie\chase_10","DZ\sounds\effects\zombie\chase_11","DZ\sounds\effects\zombie\chase_12","DZ\sounds\effects\zombie\chase_13","DZ\sounds\effects\zombie\chase_14"};
					volume = 1;
					distance = 50;
				};
				class z_whoosh
				{
					sounds[] = {"DZ\sounds\effects\Characters\movement\whoosh\whoosh_0","DZ\sounds\effects\Characters\movement\whoosh\whoosh_1","DZ\sounds\effects\Characters\movement\whoosh\whoosh_2","DZ\sounds\effects\Characters\movement\whoosh\whoosh_3","DZ\sounds\effects\Characters\movement\whoosh\whoosh_4","DZ\sounds\effects\Characters\movement\whoosh\whoosh_5","DZ\sounds\effects\Characters\movement\whoosh\whoosh_6","DZ\sounds\effects\Characters\movement\whoosh\whoosh_7"};
					volume = 1;
					distance = 50;
				};
				class z_whoosh_short
				{
					sounds[] = {"DZ\sounds\effects\Characters\movement\whoosh\whoosh_short_0","DZ\sounds\effects\Characters\movement\whoosh\whoosh_short_1","DZ\sounds\effects\Characters\movement\whoosh\whoosh_short_2","DZ\sounds\effects\Characters\movement\whoosh\whoosh_short_3","DZ\sounds\effects\Characters\movement\whoosh\whoosh_short_4","DZ\sounds\effects\Characters\movement\whoosh\whoosh_short_5","DZ\sounds\effects\Characters\movement\whoosh\whoosh_short_6","DZ\sounds\effects\Characters\movement\whoosh\whoosh_short_7"};
					volume = 1;
					distance = 50;
				};
				class z_jump
				{
					sounds[] = {"DZ\sounds\effects\Characters\movement\foley\civil-equipment-run-01","DZ\sounds\effects\Characters\movement\foley\civil-equipment-run-02","DZ\sounds\effects\Characters\movement\foley\civil-equipment-run-03","DZ\sounds\effects\Characters\movement\foley\civil-equipment-run-04","DZ\sounds\effects\Characters\movement\foley\civil-equipment-run-05","DZ\sounds\effects\Characters\movement\foley\civil-equipment-run-06","DZ\sounds\effects\Characters\movement\foley\civil-equipment-run-07"};
					volume = 1;
					distance = 50;
				};
				class z_landing
				{
					sounds[] = {"DZ\sounds\effects\Characters\movement\foley\civil-equipment-sprint-01","DZ\sounds\effects\Characters\movement\foley\civil-equipment-sprint-02","DZ\sounds\effects\Characters\movement\foley\civil-equipment-sprint-03","DZ\sounds\effects\Characters\movement\foley\civil-equipment-sprint-04","DZ\sounds\effects\Characters\movement\foley\civil-equipment-sprint-05","DZ\sounds\effects\Characters\movement\foley\civil-equipment-sprint-06","DZ\sounds\effects\Characters\movement\foley\civil-equipment-sprint-07"};
					volume = 1;
					distance = 50;
				};
			};
		};
	};
	class ZombieFemaleBase: ZombieBase
	{
		scope = 0;
		meleeAmmo = "MeleeZombieFemale";
		sensitivity = 2.5;
		sensitivityEar = 0.2;
		minIdleStayTime = 1;
		maxIdleStayTime = 2;
		minRoamRange = 60;
		maxRoamRange = 90;
		class Wounds: Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\zombies\data\shortskirt.rvmat","dz\characters\zombies\data\shortskirt_injury.rvmat","dz\characters\zombies\data\shortskirt_injury.rvmat"};
		};
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.2;
				passThrough = 1;
			};
			class HitBody: HitHead
			{
				armor = 1.2;
			};
			class HitSpine: HitHead
			{
				armor = 1.2;
			};
			class HitHands: HitHead
			{
				armor = 0.4;
				passThrough = 1;
			};
		};
	};
	class ZombieMaleBase: ZombieBase
	{
		scope = 0;
		meleeAmmo = "MeleeZombieMale";
		sensitivity = 2;
		sensitivityEar = 0.13;
		minIdleStayTime = 1;
		maxIdleStayTime = 2;
		minRoamRange = 50;
		maxRoamRange = 80;
		class Wounds: Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\zombies\data\jacket.rvmat","dz\characters\zombies\data\jacket_injury.rvmat","dz\characters\zombies\data\jacket_injury.rvmat"};
		};
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.3;
				passThrough = 1;
			};
			class HitBody: HitHead
			{
				armor = 0.9;
				passThrough = 1;
			};
			class HitSpine: HitHead
			{
				armor = 0.9;
				passThrough = 1;
			};
			class HitHands: HitHead
			{
				armor = 0.75;
				passThrough = 1;
			};
		};
	};
	class Hermit_Playable: ZombieMaleBase
	{
		simulation = "soldier";
		extCameraPosition[] = {0,-1,-3};
		class AnimSystem: AnimSystem
		{
			animGraph = "dz\anims\cfg\player\player.ag";
		};
	};
	class ZmbM_HermitSkinny_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\hermit_above0.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\hermit.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_SteakKnife","Tool_StoneKnife","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_HermitSkinny_Beige: ZmbM_HermitSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hermit_beige_ca.paa"};
	};
	class ZmbM_HermitSkinny_Black: ZmbM_HermitSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hermit_black_ca.paa"};
	};
	class ZmbM_HermitSkinny_Green: ZmbM_HermitSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hermit_green_ca.paa"};
	};
	class ZmbM_HermitSkinny_Red: ZmbM_HermitSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hermit_red_ca.paa"};
	};
	class ZmbM_FarmerFat_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\farmer_above0.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\farmer.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Tool_SteakKnife","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Cultivation_PepperSeedsPack","Cultivation_PumpkinSeedsPack","Cultivation_TomatoSeedsPack","Cultivation_ZucchiniSeedsPack","Tool_HayHook","Tool_Sickle","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_FarmerFat_Beige: ZmbM_FarmerFat_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\farmer_beige_co.paa"};
	};
	class ZmbM_FarmerFat_Blue: ZmbM_FarmerFat_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\farmer_blue_co.paa"};
	};
	class ZmbM_FarmerFat_Brown: ZmbM_FarmerFat_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\farmer_brown_co.paa"};
	};
	class ZmbM_FarmerFat_Green: ZmbM_FarmerFat_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\farmer_green_co.paa"};
	};
	class ZmbF_CitizenANormal_Base: ZombieFemaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\citizenA_normal_f.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\citizenA_normal_f.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbF_CitizenANormal_Brown: ZmbF_CitizenANormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\citizenA_normal_f_brown_co.paa"};
	};
	class ZmbF_CitizenANormal_Blue: ZmbF_CitizenANormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\citizenA_normal_f_blue_co.paa"};
	};
	class ZmbM_CitizenBFat_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\citizenB_fat_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\citizenB_fat_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_CitizenBFat_Red: ZmbM_CitizenBFat_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\citizenB_fat_m_red_CO.paa"};
	};
	class ZmbM_CitizenBFat_Green: ZmbM_CitizenBFat_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\citizenB_fat_m_green_CO.paa"};
	};
	class ZmbF_CitizenBSkinny_Base: ZombieFemaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\citizenB_skinny_f.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\citizenB_skinny_f.rvmat"};
	};
	class ZmbF_CitizenBSkinny: ZmbF_CitizenBSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\citizenB_skinny_f_CO.paa"};
	};
	class ZmbM_PrisonerSkinny_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\prisoner_skinny_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\prisoner_skinny_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Tool_SteakKnife","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_Lockpick","Tool_HandcuffKeys","Tool_Handcuffs","TelescopicBaton","Tool_Transmitter","Consumable_Chemlight_Blue","Consumable_Chemlight_Green","Consumable_Chemlight_Red","Consumable_Chemlight_White","Consumable_Chemlight_Yellow","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Ammo_45FMJ","Ammo_9mm","Ammo_380","Ammo_762x39","Ammo_22","Ammo_12ga_Pellets","Ammo_357","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_PrisonerSkinny: ZmbM_PrisonerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\prisoner_skinny_m_co.paa"};
	};
	class ZmbM_FirefighterNormal_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\firefighter_normal_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\firefighter_normal_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Tool_SteakKnife","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_Heatpack","Tool_FireExtinguisher","Tool_Lockpick","Medical_Epinephrine","Medical_PainkillerTablets","Tool_Transmitter","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_FirefighterNormal: ZmbM_FirefighterNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\firefighter_normal_m_co.paa"};
	};
	class ZmbM_FishermanOld_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\fisherman_old_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\fisherman_old_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Tool_SteakKnife","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","Tool_Flashlight","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_Heatpack","Consumable_Bait","Tool_FishingRod","Tool_SteakKnife","Food_Worm","Food_Worm","Food_Worm","Consumable_Netting","Consumable_Netting","Meat_MackerelFillet","Trap_SmallFish","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_FishermanOld_Blue: ZmbM_FishermanOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\fisherman_old_blue_m_ca.paa"};
	};
	class ZmbM_FishermanOld_Green: ZmbM_FishermanOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\fisherman_old_green_m_ca.paa"};
	};
	class ZmbM_FishermanOld_Grey: ZmbM_FishermanOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\fisherman_old_grey_m_ca.paa"};
	};
	class ZmbM_FishermanOld_Red: ZmbM_FishermanOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\fisherman_old_red_m_ca.paa"};
	};
	class ZmbF_JournalistNormal_Base: ZombieFemaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\journalist_normal_f.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\journalist_normal_f.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Consumable_Paper","Pen_Black","Pen_Blue","Pen_Green","Pen_Red","Consumable_Battery9V","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbF_JournalistNormal_Blue: ZmbF_JournalistNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\journalist_normal_f_blue_ca.paa"};
	};
	class ZmbF_JournalistNormal_Green: ZmbF_JournalistNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\journalist_normal_f_green_ca.paa"};
	};
	class ZmbF_JournalistNormal_Red: ZmbF_JournalistNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\journalist_normal_f_red_ca.paa"};
	};
	class ZmbF_JournalistNormal_White: ZmbF_JournalistNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\journalist_normal_f_white_ca.paa"};
	};
	class ZmbM_ParamedicNormal_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\paramedic_normal_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\paramedic_normal_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Medical_VitaminBottle","Medical_Epinephrine","Medical_Defibrillator","Medical_Syringe","Medical_InjectionVial","Medical_BandageDressing","Medical_PainkillerTablets","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_ParamedicNormal_Blue: ZmbM_ParamedicNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\paramedic_normal_m_blue_ca.paa"};
	};
	class ZmbM_ParamedicNormal_Green: ZmbM_ParamedicNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\paramedic_normal_m_green_ca.paa"};
	};
	class ZmbM_ParamedicNormal_Red: ZmbM_ParamedicNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\paramedic_normal_m_red_ca.paa"};
	};
	class ZmbM_ParamedicNormal_Black: ZmbM_ParamedicNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\paramedic_normal_m_black_ca.paa"};
	};
	class ZmbF_ParamedicNormal_Base: ZombieFemaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\paramedic_normal_f.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\paramedic_normal_f.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Medical_VitaminBottle","Medical_Epinephrine","Medical_Defibrillator","Medical_Syringe","Medical_InjectionVial","Medical_BandageDressing","Medical_PainkillerTablets","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbF_ParamedicNormal_Blue: ZmbF_ParamedicNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\paramedic_normal_f_blue_co.paa"};
	};
	class ZmbF_ParamedicNormal_Green: ZmbF_ParamedicNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\paramedic_normal_f_green_co.paa"};
	};
	class ZmbF_ParamedicNormal_Red: ZmbF_ParamedicNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\paramedic_normal_f_red_co.paa"};
	};
	class ZmbM_HikerSkinny_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\hiker_skinny_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\hiker_skinny_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Compass","Map_Chernarus","Tool_CanOpener","Tool_Heatpack","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_HikerSkinny_Green: ZmbM_HikerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hiker_skinny_m_green_co.paa"};
	};
	class ZmbM_HikerSkinny_Yellow: ZmbM_HikerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hiker_skinny_m_yellow_co.paa"};
	};
	class ZmbF_HikerSkinny_Base: ZombieFemaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\hiker_skinny_f.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\hiker_skinny_f.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Compass","Map_Chernarus","Tool_CanOpener","Tool_Heatpack","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbF_HikerSkinny_Blue: ZmbF_HikerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hiker_skinny_f_blue_ca.paa"};
	};
	class ZmbF_HikerSkinny_Grey: ZmbF_HikerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hiker_skinny_f_gray_ca.paa"};
	};
	class ZmbF_HikerSkinny_Green: ZmbF_HikerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hiker_skinny_f_green_ca.paa"};
	};
	class ZmbF_HikerSkinny_Red: ZmbF_HikerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hiker_skinny_f_red_ca.paa"};
	};
	class ZmbM_HunterOld_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\Hunter_old_M.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\Hunter_old_M.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","Tool_Flashlight","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"HuntingKnife","Tool_CanOpener","Tool_Heatpack","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_HunterOld_Autumn: ZmbM_HunterOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hunter_old_m_autumn_ca.paa"};
	};
	class ZmbM_HunterOld_Spring: ZmbM_HunterOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hunter_old_m_spring_ca.paa"};
	};
	class ZmbM_HunterOld_Summer: ZmbM_HunterOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hunter_old_m_summer_ca.paa"};
	};
	class ZmbM_HunterOld_Winter: ZmbM_HunterOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\hunter_old_m_winter_ca.paa"};
	};
	class ZmbF_SurvivorNormal_Base: ZombieFemaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\Survivor_normal_f.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\survivor_normal_f.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbF_SurvivorNormal_Blue: ZmbF_SurvivorNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\survivor_normal_f_blue_ca.paa"};
	};
	class ZmbF_SurvivorNormal_Orange: ZmbF_SurvivorNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\survivor_normal_f_orange_ca.paa"};
	};
	class ZmbF_SurvivorNormal_Red: ZmbF_SurvivorNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\survivor_normal_f_red_ca.paa"};
	};
	class ZmbF_SurvivorNormal_White: ZmbF_SurvivorNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\survivor_normal_f_white_ca.paa"};
	};
	class ZmbM_SurvivorDean_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\Survivormod_normal_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\survivormod_normal_m.rvmat"};
		itemsRandom[] = {{"Fruit_Kiwi"}};
	};
	class ZmbM_SurvivorDean_Black: ZmbM_SurvivorDean_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\survivormod_normal_m_black_ca.paa"};
	};
	class ZmbM_SurvivorDean_Blue: ZmbM_SurvivorDean_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\survivormod_normal_m_blue_ca.paa"};
	};
	class ZmbM_SurvivorDean_Grey: ZmbM_SurvivorDean_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\survivormod_normal_m_gray_ca.paa"};
	};
	class ZmbM_PolicemanFat_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\Policeman_fat_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\policeman_fat_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Tool_SteakKnife","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_Lockpick","Tool_HandcuffKeys","Tool_Handcuffs","TelescopicBaton","Tool_Transmitter","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Ammo_45FMJ","Ammo_9mm","Ammo_380","Ammo_762x39","Ammo_22","Ammo_12ga_Pellets","Ammo_357","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_PolicemanFat: ZmbM_PolicemanFat_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\policeman_fat_m_ca.paa"};
	};
	class ZmbF_PoliceWomanNormal_Base: ZombieFemaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\policewoman_normal_f.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\policewoman_normal_f.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Tool_SteakKnife","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_Lockpick","Tool_HandcuffKeys","Tool_Handcuffs","TelescopicBaton","Tool_Transmitter","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Ammo_45FMJ","Ammo_9mm","Ammo_380","Ammo_762x39","Ammo_22","Ammo_12ga_Pellets","Ammo_357","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbF_PoliceWomanNormal: ZmbF_PoliceWomanNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\policewoman_normal_f_co.paa"};
	};
	class ZmbM_SoldierNormal_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\soldier_normal_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\soldier_normal_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Tool_SteakKnife","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","Consumable_Battery9V","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_Transmitter","Tool_Flashlight","Medical_PainkillerTablets","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Ammo_556","Ammo_762","Ammo_545","Ammo_762x39","M_FNX45_15Rnd","CLIP_762x39_10Rnd","M_CMAG_10Rnd","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_SoldierNormal: ZmbM_SoldierNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\soldier_normal_m_co.paa"};
	};
	class ZmbM_CommercialPilotOld_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\commercialPilot_old_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\commercialpilot_old_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_CommercialPilotOld_Olive: ZmbM_CommercialPilotOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\commercialpilot_old_m_olive_co.paa"};
	};
	class ZmbM_CommercialPilotOld_Brown: ZmbM_CommercialPilotOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\commercialpilot_old_m_brown_co.paa"};
	};
	class ZmbM_CommercialPilotOld_Grey: ZmbM_CommercialPilotOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\commercialpilot_old_m_grey_co.paa"};
	};
	class ZmbM_PatrolNormal_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\Patrol_normal_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\patrol_normal_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Tool_SteakKnife","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_Lockpick","Tool_HandcuffKeys","Tool_Handcuffs","TelescopicBaton","Tool_Transmitter","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Ammo_45FMJ","Ammo_9mm","Ammo_380","Ammo_762x39","Ammo_22","Ammo_12ga_Pellets","Ammo_357","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_PatrolNormal_PautRev: ZmbM_PatrolNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\patrol_normal_m_pautrev_co.paa"};
	};
	class ZmbM_PatrolNormal_Autumn: ZmbM_PatrolNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\patrol_normal_m_Autumn_co.paa"};
	};
	class ZmbM_PatrolNormal_Flat: ZmbM_PatrolNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\patrol_normal_m_flat_co.paa"};
	};
	class ZmbM_PatrolNormal_Summer: ZmbM_PatrolNormal_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\patrol_normal_m_Summer_co.paa"};
	};
	class ZmbM_JoggerSkinny_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\jogger_skinny_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\jogger_skinny_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_JoggerSkinny_Blue: ZmbM_JoggerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\jogger_skinny_m_blue_CO.paa"};
	};
	class ZmbM_JoggerSkinny_Green: ZmbM_JoggerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\jogger_skinny_m_green_CO.paa"};
	};
	class ZmbM_JoggerSkinny_Red: ZmbM_JoggerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\jogger_skinny_m_red_CO.paa"};
	};
	class ZmbF_JoggerSkinny_Base: ZombieFemaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\jogger_skinny_f.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\jogger_skinny_f.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbF_JoggerSkinny_Blue: ZmbF_JoggerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\jogger_skinny_f_Blue_CO.paa"};
	};
	class ZmbF_JoggerSkinny_Brown: ZmbF_JoggerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\jogger_skinny_f_Brown_CO.paa"};
	};
	class ZmbF_JoggerSkinny_Green: ZmbF_JoggerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\jogger_skinny_f_Green_CO.paa"};
	};
	class ZmbF_JoggerSkinny_Red: ZmbF_JoggerSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\jogger_skinny_f_Red_CO.paa"};
	};
	class ZmbM_MotobikerFat_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\motobiker_fat_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\motobiker_fat_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"GlowPlug","SparkPlug","TireRepairKit","EngineOil","BrassKnucklesDull","BrassKnucklesShiny","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_MotobikerFat_Beige: ZmbM_MotobikerFat_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\motobiker_fat_m_beige_co.paa"};
	};
	class ZmbM_MotobikerFat_Black: ZmbM_MotobikerFat_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\motobiker_fat_m_black_co.paa"};
	};
	class ZmbM_VillagerOld_Base: ZombieMaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\villager_old_m.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\villager_old_m.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbM_VillagerOld_Blue: ZmbM_VillagerOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\villager_old_m_blue_CO.paa"};
	};
	class ZmbM_VillagerOld_Green: ZmbM_VillagerOld_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\villager_old_m_green_CO.paa"};
	};
	class ZmbF_SkaterYoung_Base: ZombieFemaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\skater_young_f.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\skater_young_f.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Tool_CanOpener","Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbF_SkaterYoung_Brown: ZmbF_SkaterYoung_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\skater_young_f_brown_co.paa"};
	};
	class ZmbF_SkaterYoung_Violet: ZmbF_SkaterYoung_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\skater_young_f_violet_co.paa"};
	};
	class ZmbF_DoctorSkinny_Base: ZombieFemaleBase
	{
		scope = 0;
		model = "\DZ\characters\zombies\doctor_skinny_f.p3d";
		hiddenSelectionsMaterials[] = {"dz\characters\zombies\data\doctor_skinny_f.rvmat"};
		itemsRandom[] = {{"Drink_SodaCanCola","Drink_SodaCanPipsi","Drink_SodaCanSpite","Food_CanBakedBeans","Food_CanPeaches","Food_CanSardines","Food_CanSpaghetti","Food_CanTuna","Food_PowderedMilk","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Consumable_Rags","Consumable_Matchbox","Consumable_Hook","Compass","Consumable_DuctTape","Crafting_Rope","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},{"Medical_VitaminBottle","Medical_Epinephrine","Medical_Defibrillator","Medical_Syringe","Medical_InjectionVial","Medical_BandageDressing","Medical_PainkillerTablets","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""}};
	};
	class ZmbF_DoctorSkinny: ZmbF_DoctorSkinny_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\zombies\data\doctor_skinny_f_CO.paa"};
	};
};
class PreloadVehicles
{
	class Hermit_Playable
	{
		loadStyle = 1;
	};
};
