////////////////////////////////////////////////////////////////////
//DeRap: sg_assets_playground\collar_deactivator\config.bin
//Produced from mikero's Dos Tools Dll version 7.16
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Tue Jul 23 06:59:52 2019 : 'file' last modified on Wed Jul 10 13:42:07 2019
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
	class SG_StaticCollarDeactivator: SG_Static
	{
		scope = 2;
		model = "\sg\assets\playground\collar_deactivator\collar_deactivator.p3d";
		featureSize = 5000;
		ladders[] = {};
	};
};
