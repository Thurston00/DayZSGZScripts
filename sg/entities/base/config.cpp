////////////////////////////////////////////////////////////////////
//DeRap: sg_entities_base\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 01 16:12:29 2019 : 'file' last modified on Mon Jul 29 11:13:52 2019
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
	class SG_EntitiesBase
	{
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Man;
	class Inventory_Base;
	class Building;
	class SG_Actor: Man
	{
		scope = 0;
	};
	class SG_Item: Inventory_Base{};
	class SG_Static: Building
	{
		scope = 0;
		inventorySlot = "";
		itemSize[] = {0,0};
		ladders[] = {};
		inventoryCondition = 0;
	};
};
