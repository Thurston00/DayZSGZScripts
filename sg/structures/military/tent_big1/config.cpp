////////////////////////////////////////////////////////////////////
//DeRap: sg_structures\military\tent_big1\config.bin
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
	class SG_HouseNoDestructTentBig1: HouseNoDestruct
	{
		scope = 1;
		model = "\sg\structures\military\tent_big2\tent_big1.p3d";
	};
};