////////////////////////////////////////////////////////////////////
//DeRap: sg_entities_items\weapons\ammunition\config.bin
//Produced from mikero's Dos Tools Dll version 7.16
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Tue Jul 23 06:59:53 2019 : 'file' last modified on Thu Jul 11 15:25:34 2019
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
	class SG_EntitiesItemsWeaponsAmmunition
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Magazines","DZ_Weapons_Ammunition"};
	};
};
class CfgMagazines
{
	class Magazine_Base;
	class Ammunition_Base: Magazine_Base
	{
		lootCategory = "Ammo";
		ContinuousActions[] = {207};
		rotationFlags = 2;
		itemSize[] = {1,1};
		ammo = "";
		spawnDamageRange[] = {0.0,0.6};
		destroyOnEmpty = 1;
		varQuantityDestroyOnMin = 1;
		canBeSplit = 1;
		simpleHeap = 1;
		soundUse = "craft_rounds";
		emptySound = "craft_rounds";
	};
	class Ammo_45ACP: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_45ACP0";
		descriptionShort = "$STR_CfgMagazines_Ammo_45ACP1";
		model = "\sg\entities\items\weapons\ammunition\SG_45acp_LooseRounds.p3d";
		weight = 12;
		count = 25;
		ammo = "Bullet_45ACP";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\45cal_loose.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\45cal_loose.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\45cal_loose_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\45cal_loose_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\45cal_loose_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_9x19: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_9x190";
		descriptionShort = "$STR_CfgMagazines_Ammo_9x191";
		model = "\sg\entities\items\weapons\ammunition\SG_9mm_LooseRounds.p3d";
		weight = 6;
		count = 25;
		ammo = "Bullet_9x19";
		muzzleFlashParticle = "weapon_shot_mp5k_01";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\9mm.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\9mm.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\9mm_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\9mm_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\9mm_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_380: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_3800";
		descriptionShort = "$STR_CfgMagazines_Ammo_3801";
		model = "\sg\entities\items\weapons\ammunition\SG_380auto_LooseRounds.p3d";
		weight = 6;
		count = 35;
		ammo = "Bullet_380";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\9mm.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\9mm.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\9mm_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\9mm_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\9mm_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_556x45: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_556x450";
		descriptionShort = "$STR_CfgMagazines_Ammo_556x451";
		model = "\sg\entities\items\weapons\ammunition\SG_556_LooseRounds.p3d";
		weight = 4;
		count = 20;
		ammo = "Bullet_556x45";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\556_LooseRounds5.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\556_LooseRounds5.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\556_LooseRounds5_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\556_LooseRounds5_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\556_LooseRounds5_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_762x54: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_762x540";
		descriptionShort = "$STR_CfgMagazines_Ammo_762x541";
		model = "\sg\entities\items\weapons\ammunition\SG_762_LooseRounds.p3d";
		weight = 9;
		count = 20;
		ammo = "Bullet_762x54";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\mosinclip.rvmat"}},{0.7,{"DZ\weapons\attachments\data\mosinclip.rvmat"}},{0.5,{"DZ\weapons\attachments\data\mosinclip_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\mosinclip_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\mosinclip_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_762x39: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_762x390";
		descriptionShort = "$STR_CfgMagazines_Ammo_762x391";
		model = "\sg\entities\items\weapons\ammunition\SG_762x39_LooseRounds.p3d";
		weight = 8;
		count = 20;
		ammo = "Bullet_762x39";
		muzzleFlashParticle = "weapon_shot_izh18_01";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762x39.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762x39.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762x39_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762x39_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762x39_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_12gaPellets: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_12gaPellets0";
		descriptionShort = "$STR_CfgMagazines_Ammo_12gaPellets1";
		model = "\sg\entities\items\weapons\ammunition\SG_12ga_00buck.p3d";
		weight = 28;
		count = 10;
		ammo = "Bullet_12GaugePellets";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\rem870_ammo.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\rem870_ammo.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\rem870_ammo_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\rem870_ammo_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\rem870_ammo_destruct.rvmat"}}};
				};
			};
		};
	};
};
