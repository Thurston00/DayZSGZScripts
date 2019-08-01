////////////////////////////////////////////////////////////////////
//DeRap: sg_structures\military\tent_big1\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 01 16:12:32 2019 : 'file' last modified on Mon Jul 29 11:27:12 2019
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
