////////////////////////////////////////////////////////////////////
//DeRap: sg_items_gear_functional\collar\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 01 16:12:30 2019 : 'file' last modified on Mon Jul 29 11:31:30 2019
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
	class SG_EntitiesStatic
	{
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Explosives","DZ_Gear_Traps","DZ_Characters_Headgear"};
	};
};
class CfgAmmo
{
	class DefaultAmmo;
	class SG_CollarExplosion: DefaultAmmo
	{
		indirectHit = 1;
		indirectHitRange = 0.5;
		effect = "SgEffCollarExplosion";
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {"Grenade_explosion_SoundSet","Grenade_Tail_SoundSet"};
		soundHit[] = {"DZ\sounds\weapons\grenades\hand_grenade_1",10.0,1};
		soundFly[] = {"dz\sounds\Weapons\explosions\noise",3.162277e-005,1};
		soundEngine[] = {"",9.999998e-005,4};
		class DamageApplied
		{
			type = "FragGrenade";
			class Health
			{
				damage = 50;
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
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class SG_CollarItem: Clothing
	{
		scope = 2;
		displayName = "Sg collar";
		descriptionShort = "Sg collar";
		model = "\sg\items\gear_functional\collar\collar_item\collar_item_g.p3d";
		featureSize = 5000;
		ladders[] = {};
		ammoType = "SG_CollarExplosion";
		inventorySlot = "Collar";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Collar"};
		weight = 100;
		itemSize[] = {1,1};
		absorbency = 0.1;
		heatIsolation = 0.1;
		class ClothingTypes
		{
			male = "\sg\items\gear_functional\collar\collar_item\collar_item_m.p3d";
			female = "\sg\items\gear_functional\collar\collar_item\collar_item_f.p3d";
		};
	};
};
