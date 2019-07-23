////////////////////////////////////////////////////////////////////
//DeRap: sg_assets_playground\dragon_tooth\config.bin
//Produced from mikero's Dos Tools Dll version 7.16
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Tue Jul 23 06:59:52 2019 : 'file' last modified on Wed Jul 10 13:42:08 2019
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
	class SG_Static;
	class SG_StaticDragonTooth: SG_Static
	{
		scope = 2;
		model = "\sg\assets\playground\dragon_tooth\dragon_tooth.p3d";
	};
	class SG_StaticDragonTooth_Red: SG_Static
	{
		scope = 2;
		model = "\sg\assets\playground\dragon_tooth\dragon_tooth_red.p3d";
		hiddenSelections[] = {"antenna","tooth"};
		hiddenSelectionsTextures[] = {"\sg\assets\playground\dragon_tooth\data\sg_dragon_tooth_antenna.paa","\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_1a.paa"};
		phase1Textures[] = {"\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_1a.paa","\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_1b.paa","\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_1c.paa","\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_1d.paa","\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_1e.paa"};
		phase2Textures[] = {"\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_2a.paa","\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_2b.paa","\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_2c.paa","\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_2d.paa","\sg\assets\playground\dragon_tooth\data\sg_sloupky_co_red_2e.paa"};
	};
	class SG_StaticDragonTooth_Yellow: SG_Static
	{
		scope = 2;
		model = "\sg\assets\playground\dragon_tooth\dragon_tooth_yellow.p3d";
		hiddenSelections[] = {"all"};
		hiddenSelectionsTextures[] = {""};
	};
	class SG_StaticDragonTooth_Green: SG_Static
	{
		scope = 2;
		model = "\sg\assets\playground\dragon_tooth\dragon_tooth_green.p3d";
	};
};
