////////////////////////////////////////////////////////////////////
//DeRap: sg_entities_static\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 06 17:38:41 2019 : 'file' last modified on Mon Jul 29 11:20:16 2019
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
	class Land_Smokestack_Metal;
	class SG_StaticTransmitter: SG_Static
	{
		scope = 2;
		model = "sg\entities\static\sg_static_transmiter.p3d";
		hiddenSelections[] = {"glow"};
		hiddenSelectionsMaterials[] = {"sg\entities\static\data\light_off.rvmat"};
	};
	class SG_StaticAntenna: SG_Static
	{
		scope = 2;
		model = "sg\entities\static\sg_static_antenna.p3d";
		hiddenSelections[] = {"pillar_beam_1"};
		hiddenSelectionsMaterials[] = {"sg\entities\static\data\sg_light_beam_white_on.rvmat"};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,0.8,0.6,0.9};
				ambient[] = {0.1,0.08,0.06,1.0};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 1;
				radius = 20;
				brightness = 1;
				dayLight = 1;
			};
		};
	};
	class SG_StaticAntennaBig: SG_Static
	{
		scope = 2;
		model = "sg\entities\static\sg_static_antenna_big.p3d";
		hiddenSelections[] = {"pillar_beam_1"};
		hiddenSelectionsMaterials[] = {"sg\entities\static\data\sg_light_beam_white_on.rvmat"};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,0.8,0.6,0.9};
				ambient[] = {0.1,0.08,0.06,1.0};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 1;
				radius = 20;
				brightness = 1;
				dayLight = 1;
			};
		};
	};
	class SG_StaticAntennaSmall: SG_Static
	{
		scope = 2;
		model = "sg\entities\static\sg_static_dragon_tooth.p3d";
		hiddenSelections[] = {"pillar_beam_1"};
		hiddenSelectionsMaterials[] = {"sg\entities\static\data\sg_light_beam_white_on.rvmat"};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,0.8,0.6,0.9};
				ambient[] = {0.1,0.08,0.06,1.0};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 1;
				radius = 20;
				brightness = 1;
				dayLight = 1;
			};
		};
	};
	class SG_StaticStartPointAll: SG_Static
	{
		scope = 2;
		model = "sg\entities\static\sg_static_start_amplion.p3d";
		featureSize = 5000;
		ladders[] = {};
	};
	class SG_StaticSpawner: SG_Static
	{
		scope = 2;
		model = "\sg\entities\static\sg_static_pile_pallets.p3d";
	};
	class SG_StaticSpawnerCZ: SG_StaticSpawner
	{
		scope = 2;
		sgSpawnItems[] = {"CZ61","Mag_CZ61_20Rnd","Ammo_380"};
		sgSpawnOnlyInLobby = 1;
	};
	class SG_StaticSpawnerM4A1: SG_StaticSpawner
	{
		scope = 2;
		sgSpawnItems[] = {"M4A1","Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd"};
		sgSpawnOnlyInLobby = 1;
	};
	class SG_StaticSpawnerMosin: SG_StaticSpawner
	{
		scope = 2;
		sgSpawnItems[] = {"Mosin9130","Ammo_762x54","Mag_CLIP762x54_5Rnd"};
		sgSpawnOnlyInLobby = 1;
	};
	class SG_StaticSpawnerShotgun: SG_StaticSpawner
	{
		scope = 2;
		sgSpawnItems[] = {"Izh43Shotgun","Ammo_12gaPellets","Mag_12gaSnaploader_2Rnd"};
		sgSpawnOnlyInLobby = 1;
	};
	class SG_StaticSpawnerZombie: SG_StaticSpawner
	{
		scope = 2;
		model = "\sg\entities\static\sg_static_pallet.p3d";
		sgSpawnItems[] = {"ZmbM_CitizenBFat_Red"};
		sgSpawnUseAI = 0;
	};
	class SG_StaticHelicopter: SG_Static
	{
		scope = 2;
		model = "DZ\vehicles\air\UH1Y\UH1Y.p3d";
		featureSize = 5000;
		ladders[] = {};
	};
};
