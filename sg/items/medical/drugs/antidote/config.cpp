////////////////////////////////////////////////////////////////////
//DeRap: sg_items_medical\drugs\antidote\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 06 17:38:42 2019 : 'file' last modified on Mon Jul 29 11:32:20 2019
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
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class SG_Antidote: Inventory_Base
	{
		scope = 2;
		displayName = "Antidote";
		descriptionShort = "Antidote";
		model = "\sg\items\medical\drugs\antidote\antidote.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class AnimEvents
		{
			class SoundWeapon
			{
				class Morphine_spear
				{
					soundSet = "Morphine_spear_SoundSet";
					id = 201;
				};
				class Morphine_out
				{
					soundSet = "Morphine_out_SoundSet";
					id = 202;
				};
			};
		};
		class Medical
		{
			percentageHeal = 25;
		};
	};
};
