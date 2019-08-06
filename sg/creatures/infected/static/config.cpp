////////////////////////////////////////////////////////////////////
//DeRap: sg_creatures\infected\static\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 06 17:38:41 2019 : 'file' last modified on Thu Aug 01 11:12:33 2019
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
	class SG_CreaturesStaticBase
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"SG_Creatures"};
	};
};
class CfgVehicles
{
	class SG_InfectedBase;
	class SG_StaticInfectedBase: SG_InfectedBase
	{
		aiGroupType = "Static";
		aiGroupBehaviour = "InfectedStaticGroupBeh";
	};
	class SG_StaticInfectedSkaterMale: SG_StaticInfectedBase
	{
		scope = 0;
		model = "sg\creatures\infected\static\skater_young_m\skater_young_m.p3d";
		aiAgentTemplate = "Creature_InfectedStaticSkater_young_m";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsMaterials[] = {"sg\creatures\infected\static\skater_young_m\data\skater_young_m.rvmat"};
		class enfanimsys
		{
			meshObject = "sg\creatures\infected\_infected_base\_data\infectedSG_skeleton.xob";
			graphname = "sg\creatures\_animations\AnimationGraph\infected_SG.agr";
			defaultinstance = "sg\creatures\_animations\AnimationGraph\infected_SG_mario.asi";
			startnode = "MasterSM";
			skeletonName = "infectedSG_skeleton.xob";
			alternativeinstancies[] = {"sg\creatures\_animations\AnimationGraph\infected_SG_john.asi"};
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
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 8;
				};
				class Sprint1
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 9;
				};
				class Sprint2
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 10;
				};
				class Sprint3
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 11;
				};
				class Sprint4
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 12;
				};
				class Scuff1
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 17;
				};
				class Scuff2
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 18;
				};
				class Sccuff3
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 19;
				};
				class Scuff4
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 20;
				};
				class landFeetErc
				{
					soundLookupTable = "landFeetErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 21;
				};
				class landFootErc
				{
					soundLookupTable = "landFootErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 22;
				};
				class Bodyfall
				{
					soundLookupTable = "bodyfall_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 23;
				};
				class Bodyfall_Hand
				{
					soundLookupTable = "bodyfall_hand_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 24;
				};
				class Bodyfall_Slide
				{
					soundLookupTable = "bodyfall_slide_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 25;
				};
				class Prone_Walk_L
				{
					soundLookupTable = "walkProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 27;
				};
				class Prone_Walk_R
				{
					soundLookupTable = "walkProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 28;
				};
				class Prone_Run_L
				{
					soundLookupTable = "runProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 29;
				};
				class Prone_Run_R
				{
					soundLookupTable = "runProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 30;
				};
			};
			class Sounds
			{
				class Attack_Light1
				{
					soundSet = "Zmb_Attack_Light1_SoundSet";
					id = 1;
				};
				class Attack_Light2
				{
					soundSet = "Zmb_Attack_Light2_SoundSet";
					id = 2;
				};
				class Attack_Heavy1
				{
					soundSet = "Zmb_Attack_Heavy1_SoundSet";
					id = 3;
				};
				class Attack_Heavy2
				{
					soundSet = "Zmb_Attack_Heavy2_SoundSet";
					id = 4;
				};
				class TwoHands
				{
					soundSet = "Zmb_Attack_TwoHands_SoundSet";
					id = 5;
				};
			};
			class SoundVoice
			{
				class LightHit
				{
					soundSet = "ZmbM_Normal2_LightHit_Soundset";
					id = 1;
				};
				class HeavyHit
				{
					soundSet = "ZmbM_Normal2_HeavyHit_Soundset";
					id = 2;
				};
				class Attack
				{
					soundSet = "ZmbM_Normal2_Attack_Soundset";
					id = 5;
				};
				class Jump
				{
					soundSet = "ZmbM_Normal2_Jump_Soundset";
					id = 10;
				};
				class Land
				{
					soundSet = "ZmbM_Normal2_Land_Soundset";
					id = 11;
				};
				class CallToArmsShort
				{
					soundSet = "ZmbM_Normal2_CallToArmsShort_Soundset";
					id = 20;
				};
			};
		};
	};
	class SG_StaticInfectedSkaterMaleBlue: SG_StaticInfectedSkaterMale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\skater_young_m\data\skater_young_m_blue_CO.paa"};
	};
	class SG_StaticInfectedSkaterMaleBrown: SG_StaticInfectedSkaterMale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\skater_young_m\data\skater_young_m_brown_CO.paa"};
	};
	class SG_StaticInfectedSkaterMaleGreen: SG_StaticInfectedSkaterMale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\skater_young_m\data\skater_young_m_green_CO.paa"};
	};
	class SG_StaticInfectedSkaterMaleGrey: SG_StaticInfectedSkaterMale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\skater_young_m\data\skater_young_m_grey_CO.paa"};
	};
	class SG_StaticInfectedVillagerMale: SG_StaticInfectedBase
	{
		scope = 0;
		model = "sg\creatures\infected\static\villager_old_m\villager_old_m.p3d";
		aiAgentTemplate = "Creature_InfectedStaticVillager_old_m";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsMaterials[] = {"sg\creatures\infected\static\villager_old_m\data\citizenB_fat_m.rvmat"};
		class enfanimsys
		{
			meshObject = "sg\creatures\infected\_infected_base\_data\infectedSG_skeleton.xob";
			graphname = "sg\creatures\_animations\AnimationGraph\infected_SG.agr";
			defaultinstance = "sg\creatures\_animations\AnimationGraph\infected_SG_mario.asi";
			startnode = "MasterSM";
			skeletonName = "infectedSG_skeleton.xob";
			alternativeinstancies[] = {"sg\creatures\_animations\AnimationGraph\infected_SG_john.asi"};
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
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 8;
				};
				class Sprint1
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 9;
				};
				class Sprint2
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 10;
				};
				class Sprint3
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 11;
				};
				class Sprint4
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 12;
				};
				class Scuff1
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 17;
				};
				class Scuff2
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 18;
				};
				class Sccuff3
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 19;
				};
				class Scuff4
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 20;
				};
				class landFeetErc
				{
					soundLookupTable = "landFeetErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 21;
				};
				class landFootErc
				{
					soundLookupTable = "landFootErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 22;
				};
				class Bodyfall
				{
					soundLookupTable = "bodyfall_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 23;
				};
				class Bodyfall_Hand
				{
					soundLookupTable = "bodyfall_hand_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 24;
				};
				class Bodyfall_Slide
				{
					soundLookupTable = "bodyfall_slide_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 25;
				};
				class Prone_Walk_L
				{
					soundLookupTable = "walkProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 27;
				};
				class Prone_Walk_R
				{
					soundLookupTable = "walkProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 28;
				};
				class Prone_Run_L
				{
					soundLookupTable = "runProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 29;
				};
				class Prone_Run_R
				{
					soundLookupTable = "runProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 30;
				};
			};
			class Sounds
			{
				class Attack_Light1
				{
					soundSet = "Zmb_Attack_Light1_SoundSet";
					id = 1;
				};
				class Attack_Light2
				{
					soundSet = "Zmb_Attack_Light2_SoundSet";
					id = 2;
				};
				class Attack_Heavy1
				{
					soundSet = "Zmb_Attack_Heavy1_SoundSet";
					id = 3;
				};
				class Attack_Heavy2
				{
					soundSet = "Zmb_Attack_Heavy2_SoundSet";
					id = 4;
				};
				class TwoHands
				{
					soundSet = "Zmb_Attack_TwoHands_SoundSet";
					id = 5;
				};
			};
			class SoundVoice
			{
				class LightHit
				{
					soundSet = "ZmbM_Old_LightHit_Soundset";
					id = 1;
				};
				class HeavyHit
				{
					soundSet = "ZmbM_Old_HeavyHit_Soundset";
					id = 2;
				};
				class Attack
				{
					soundSet = "ZmbM_Old_Attack_Soundset";
					id = 5;
				};
				class Jump
				{
					soundSet = "ZmbM_Old_Jump_Soundset";
					id = 10;
				};
				class Land
				{
					soundSet = "ZmbM_Old_Land_Soundset";
					id = 11;
				};
				class CallToArmsShort
				{
					soundSet = "ZmbM_Old_CallToArmsShort_Soundset";
					id = 20;
				};
			};
		};
	};
	class SG_StaticInfectedVillagerMaleBlue: SG_StaticInfectedVillagerMale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\villager_old_m\data\villager_old_m_blue_CO.paa"};
	};
	class SG_StaticInfectedVillagerMaleGreen: SG_StaticInfectedVillagerMale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\villager_old_m\data\villager_old_m_green_CO.paa"};
	};
	class SG_StaticInfectedVillagerMaleGrey: SG_StaticInfectedVillagerMale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\villager_old_m\data\villager_old_m_CO.paa"};
	};
	class SG_StaticInfectedVillagerFemale: SG_StaticInfectedBase
	{
		scope = 0;
		model = "sg\creatures\infected\static\villager_old_f\villager_old_f.p3d";
		aiAgentTemplate = "Creature_InfectedStaticVillager_old_f";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsMaterials[] = {"sg\creatures\infected\static\villager_old_f\data\villager_old_f.rvmat"};
		class enfanimsys
		{
			meshObject = "sg\creatures\infected\_infected_base\_data\infectedSG_skeleton.xob";
			graphname = "sg\creatures\_animations\AnimationGraph\infected_SG.agr";
			defaultinstance = "sg\creatures\_animations\AnimationGraph\infected_SG_mario.asi";
			startnode = "MasterSM";
			skeletonName = "infectedSG_skeleton.xob";
			alternativeinstancies[] = {"sg\creatures\_animations\AnimationGraph\infected_SG_john.asi"};
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
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "walkErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "runErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 8;
				};
				class Sprint1
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 9;
				};
				class Sprint2
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 10;
				};
				class Sprint3
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 11;
				};
				class Sprint4
				{
					soundLookupTable = "sprintErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 12;
				};
				class Scuff1
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 17;
				};
				class Scuff2
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 18;
				};
				class Sccuff3
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 19;
				};
				class Scuff4
				{
					soundLookupTable = "scuffErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 20;
				};
				class landFeetErc
				{
					soundLookupTable = "landFeetErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 21;
				};
				class landFootErc
				{
					soundLookupTable = "landFootErc_Boots_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 22;
				};
				class Bodyfall
				{
					soundLookupTable = "bodyfall_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 23;
				};
				class Bodyfall_Hand
				{
					soundLookupTable = "bodyfall_hand_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 24;
				};
				class Bodyfall_Slide
				{
					soundLookupTable = "bodyfall_slide_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 25;
				};
				class Prone_Walk_L
				{
					soundLookupTable = "walkProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 27;
				};
				class Prone_Walk_R
				{
					soundLookupTable = "walkProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 28;
				};
				class Prone_Run_L
				{
					soundLookupTable = "runProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 29;
				};
				class Prone_Run_R
				{
					soundLookupTable = "runProne_Zmb_LookupTable";
					noise = "ZombieStepNoise";
					id = 30;
				};
			};
			class Sounds
			{
				class Attack_Light1
				{
					soundSet = "Zmb_Attack_Light1_SoundSet";
					id = 1;
				};
				class Attack_Light2
				{
					soundSet = "Zmb_Attack_Light2_SoundSet";
					id = 2;
				};
				class Attack_Heavy1
				{
					soundSet = "Zmb_Attack_Heavy1_SoundSet";
					id = 3;
				};
				class Attack_Heavy2
				{
					soundSet = "Zmb_Attack_Heavy2_SoundSet";
					id = 4;
				};
				class TwoHands
				{
					soundSet = "Zmb_Attack_TwoHands_SoundSet";
					id = 5;
				};
			};
			class SoundVoice
			{
				class LightHit
				{
					soundSet = "ZmbF_Skinny_LightHit_Soundset";
					id = 1;
				};
				class HeavyHit
				{
					soundSet = "ZmbF_Skinny_HeavyHit_Soundset";
					id = 2;
				};
				class Attack
				{
					soundSet = "ZmbF_Skinny_Attack_Soundset";
					id = 5;
				};
				class Jump
				{
					soundSet = "ZmbF_Skinny_Jump_Soundset";
					id = 10;
				};
				class Land
				{
					soundSet = "ZmbF_Skinny_Land_Soundset";
					id = 11;
				};
				class CallToArmsShort
				{
					soundSet = "ZmbF_Skinny_CallToArmsShort_Soundset";
					id = 20;
				};
			};
		};
	};
	class SG_StaticInfectedVillagerFemaleBlue: SG_StaticInfectedVillagerFemale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\villager_old_f\data\villager_old_f_blue_CO.paa"};
	};
	class SG_StaticInfectedVillagerFemaleGreen: SG_StaticInfectedVillagerFemale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\villager_old_f\data\villager_old_f_green_CO.paa"};
	};
	class SG_StaticInfectedVillagerFemaleRed: SG_StaticInfectedVillagerFemale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\villager_old_f\data\villager_old_f_red_CO.paa"};
	};
	class SG_StaticInfectedVillagerFemaleWhite: SG_StaticInfectedVillagerFemale
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"sg\creatures\infected\static\villager_old_f\data\villager_old_f_white_CO.paa"};
	};
};
