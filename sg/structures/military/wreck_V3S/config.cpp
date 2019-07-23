////////////////////////////////////////////////////////////////////
//DeRap: sg_structures\military\wreck_V3S\config.bin
//Produced from mikero's Dos Tools Dll version 7.16
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Tue Jul 23 06:59:57 2019 : 'file' last modified on Thu Jun 27 08:13:03 2019
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
	class SG_Structures
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Structures_Industrial"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class Land_SG_Wreck_V3S: HouseNoDestruct
	{
		scope = 2;
		model = "\sg\structures\military\wreck_V3S\SG_Wreck_V3S.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
			};
			class Doors2
			{
				displayName = "door 2";
				component = "Doors2";
				soundPos = "doors2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
			};
			class Doors5
			{
				displayName = "door 5";
				component = "Doors5";
				soundPos = "doors5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
			};
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
			};
		};
	};
};
