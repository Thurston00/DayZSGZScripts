////////////////////////////////////////////////////////////////////
//DeRap: sg_items_weapons\melee\baseball_bat\config.bin
//Produced from mikero's Dos Tools Dll version 7.16
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Tue Jul 23 06:59:54 2019 : 'file' last modified on Tue Jun 25 14:38:07 2019
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
	class SG_ItemsWeapons
	{
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class SG_BaseballBat: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BaseballBat0";
		descriptionShort = "$STR_CfgVehicles_BaseballBat1";
		model = "\sg\items\weapons\melee\baseball_bat\data\models\baseball_bat.p3d";
		rotationFlags = 17;
		autoQuickbar = 1;
		inventorySlot = "Melee";
		weight = 566;
		itemSize[] = {2,8};
		itemBehaviour = 2;
		fragility = 0.02;
		lootTag[] = {"Civilian","Work"};
		lootCategory = "Tools";
		openItemSpillRange[] = {40,80};
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeBat";
				range = 1.5;
			};
			class Heavy
			{
				ammo = "MeleeBat_Heavy";
				range = 1.5;
			};
			class Sprint
			{
				ammo = "MeleeBat_Heavy";
				range = 4.1;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blunt\Data\BaseballBat.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View.rvmat"}},{0.7,{"DZ\weapons\melee\blunt\Data\BaseballBat.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View.rvmat"}},{0.5,{"DZ\weapons\melee\blunt\Data\BaseballBat_damage.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blunt\Data\BaseballBat_damage.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blunt\Data\BaseballBat_destruct.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View_destruct.rvmat"}}};
				};
			};
		};
	};
	class SG_BaseballBat_IceSkates: SG_BaseballBat
	{
		model = "\sg\items\weapons\melee\baseball_bat\data\models\baseball_bat_ice_skates.p3d";
	};
};
