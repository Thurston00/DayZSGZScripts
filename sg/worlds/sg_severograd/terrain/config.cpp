////////////////////////////////////////////////////////////////////
//DeRap: sg_worlds_severograd\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 01 16:12:34 2019 : 'file' last modified on Tue Jul 23 11:27:05 2019
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
	class DZ_Worlds_SG_Severograd_World
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Surfaces"};
	};
};
class cfgCharacterScenes
{
	class SG_Severograd
	{
		class Severograd_01
		{
			target[] = {-1600,-1600,125};
			position[] = {1713.2,2608.8,2.0};
			fov = 0.6;
			date[] = {2018,8,2,14,45};
			aperture = 16;
		};
	};
};
class CfgWorlds
{
	class DefaultWorld
	{
		class Weather;
		class Grid;
	};
	class CAWorld: DefaultWorld
	{
		class Grid: Grid{};
	};
	class DefaultLighting;
	class SG_Severograd: CAWorld
	{
		access = 3;
		worldId = 1;
		cutscenes[] = {"SG_SeverogradIntro1"};
		description = "SG_Severograd";
		worldName = "\sg\worlds\sg_severograd\terrain\SG_Severograd.wrp";
		class Navmesh
		{
			navmeshName = "\sg\Worlds\SG_Severograd\navmesh\navmesh.nm";
			filterIsolatedIslandsOnLoad = 1;
			visualiseOffset = 0.0;
			class GenParams
			{
				tileWidth = 50.0;
				cellSize1 = 0.25;
				cellSize2 = 0.1;
				cellSize3 = 0.1;
				filterIsolatedIslands = 1;
				seedPosition[] = {7500,0,7500};
				class Agent
				{
					diameter = 0.6;
					standHeight = 1.5;
					crouchHeight = 1.0;
					proneHeight = 0.5;
					maxStepHeight = 0.45;
					maxSlope = 60.0;
				};
				class Links
				{
					class Infected_210
					{
						typeId = 210;
						jumpLength = 2.0;
						jumpHeight = 2.1;
						minCenterHeight = 1.8;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump3";
						flags[] = {"jumpOver"};
						color = 1711701501;
					};
					class Infected_180
					{
						typeId = 180;
						jumpLength = 2.0;
						jumpHeight = 1.8;
						minCenterHeight = 1.5;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump3";
						flags[] = {"jumpOver"};
						color = 1719270914;
					};
					class Infected_150
					{
						typeId = 150;
						jumpLength = 2.0;
						jumpHeight = 1.5;
						minCenterHeight = 1.2;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump3";
						flags[] = {"jumpOver"};
						color = 1728052480;
					};
					class Infected_120
					{
						typeId = 120;
						jumpLength = 2.0;
						jumpHeight = 1.2;
						minCenterHeight = 0.9;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump3";
						flags[] = {"jumpOver"};
						color = 1727987712;
					};
					class Infected_90
					{
						typeId = 90;
						jumpLength = 2.0;
						jumpHeight = 0.9;
						minCenterHeight = 0.6;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump3";
						flags[] = {"jumpOver"};
						color = 1728017152;
					};
					class Infected_70
					{
						typeId = 70;
						jumpLength = 2.0;
						jumpHeight = 0.7;
						minCenterHeight = 0.4;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump3";
						flags[] = {"jumpOver"};
						color = 1720058367;
					};
				};
			};
		};
		longitude = 30;
		latitude = -45;
		soundMapAttenCoef = 0.01;
		class SoundMapValues
		{
			treehard = 0.03;
			treesoft = 0.03;
			bushhard = 0.0;
			bushsoft = 0.0;
			forest = 1.0;
			house = 0.3;
			church = 0.5;
		};
		class OutsideTerrain
		{
			satellite = "sg\worlds\sg_severograd\data\outside_sat_co.paa";
			enableTerrainSynth = 1;
			class Layers
			{
				class Layer0
				{
					nopx = "DZ\surfaces\data\terrain\cp_grass_nopx.paa";
					texture = "DZ\surfaces\data\terrain\cp_grass_ca.paa";
				};
			};
		};
		plateFormat = "ML$ - #####";
		plateLetters = "ABCDEGHIKLMNOPRSTVXZ";
		class Grid: Grid
		{
			offsetX = 0;
			offsetY = 0;
			class Zoom1
			{
				zoomMax = 0.15;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = 100;
			};
			class Zoom2
			{
				zoomMax = 0.85;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = 1000;
			};
			class Zoom3
			{
				zoomMax = 1e+030;
				format = "XY";
				formatX = "0";
				formatY = "0";
				stepX = 10000;
				stepY = 10000;
			};
		};
		startTime = "9:20";
		startDate = "11/10/2017";
		startWeather = 0.25;
		startFog = 0.0;
		forecastWeather = 0.25;
		forecastFog = 0.0;
		class Weather: Weather{};
		centerPosition[] = {7100,7750,300};
		seagullPos[] = {1272.842,150.0,14034.962};
		ilsPosition[] = {0.0,0.0};
		ilsDirection[] = {0.0,0.0,0.0};
		ilsTaxiIn[] = {0.0,0.0};
		ilsTaxiOff[] = {0.0,0.0};
		class Sounds
		{
			sounds[] = {};
		};
		clutterGrid = 1.0;
		clutterDist = 125;
		noDetailDist = 40;
		fullDetailDist = 15;
		midDetailTexture = "sg\worlds\sg_severograd\data\middle_sat_mco.paa";
		terrainNormalTexture = "sg\worlds\sg_severograd\data\global_nohq.paa";
		class UsedTerrainMaterials
		{
			material0 = "DZ\surfaces\data\terrain\cp_broadleaf_dense1.rvmat";
			material1 = "DZ\surfaces\data\terrain\cp_broadleaf_dense2.rvmat";
			material2 = "DZ\surfaces\data\terrain\cp_broadleaf_sparse1.rvmat";
			material3 = "DZ\surfaces\data\terrain\cp_broadleaf_sparse2.rvmat";
			material4 = "DZ\surfaces\data\terrain\cp_concrete1.rvmat";
			material5 = "DZ\surfaces\data\terrain\cp_concrete2.rvmat";
			material6 = "DZ\surfaces\data\terrain\cp_conifer_common1.rvmat";
			material7 = "DZ\surfaces\data\terrain\cp_conifer_common2.rvmat";
			material8 = "DZ\surfaces\data\terrain\cp_conifer_moss1.rvmat";
			material9 = "DZ\surfaces\data\terrain\cp_conifer_moss2.rvmat";
			material10 = "DZ\surfaces\data\terrain\cp_dirt.rvmat";
			material11 = "DZ\surfaces\data\terrain\cp_grass.rvmat";
			material12 = "DZ\surfaces\data\terrain\cp_grass_tall.rvmat";
			material13 = "DZ\surfaces\data\terrain\cp_gravel.rvmat";
			material14 = "DZ\surfaces\data\terrain\cp_rock.rvmat";
		};
		class Subdivision
		{
			class Fractal
			{
				rougness = 5;
				maxRoad = 0.02;
				maxTrack = 0.5;
				maxSlopeFactor = 0.05;
			};
			class WhiteNoise
			{
				rougness = 2;
				maxRoad = 0.01;
				maxTrack = 0.05;
				maxSlopeFactor = 0.0025;
			};
			minY = -0.0;
			minSlope = 0.02;
		};
		class Ambient
		{
			class BigInsects
			{
				radius = 20;
				cost = "(5 - (2 * houses)) * (1 - night) * (1 - rain) * (1 - sea) * (1 - windy)";
				class Species{};
			};
			class BigInsectsAquatic
			{
				radius = 20;
				cost = "(3 * sea) * (1 - night) * (1 - rain) * (1 - windy)";
				class Species{};
			};
			class SmallInsects
			{
				radius = 3;
				cost = "(12 - 8 * hills) * (1 - night) * (1 - rain) * (1 - sea) * (1 - windy)";
				class Species{};
			};
			class NightInsects
			{
				radius = 3;
				cost = "(9 - 8 * hills) * night * (1 - rain) * (1 - sea) * (1 - windy)";
				class Species{};
			};
			class WindClutter
			{
				radius = 10;
				cost = "((20 - 5 * rain) * (3 * (windy factor [0.2, 0.5]))) * (1 - sea)";
				class Species
				{
					class FxWindGrass1
					{
						probability = "0.4 - 0.2 * hills - 0.2 * trees";
						cost = 1;
					};
					class FxWindGrass2
					{
						probability = "0.4 - 0.2 * hills - 0.2 * trees";
						cost = 1;
					};
					class FxWindRock1
					{
						probability = "0.4 * hills";
						cost = 1;
					};
					class FxCrWindLeaf1
					{
						probability = "0.2 * trees";
						cost = 1;
					};
					class FxCrWindLeaf2
					{
						probability = "0.1 * trees + 0.2";
						cost = 1;
					};
					class FxCrWindLeaf3
					{
						probability = "0.1 * trees";
						cost = 1;
					};
				};
			};
			class NoWindClutter
			{
				radius = 15;
				cost = 8;
				class Species
				{
					class FxWindPollen1
					{
						probability = 1;
						cost = 1;
					};
					class FxCrWindLeaf1
					{
						probability = "0.2 * trees";
						cost = 1;
					};
					class FxCrWindLeaf2
					{
						probability = "0.1 * trees + 0.2";
						cost = 1;
					};
					class FxCrWindLeaf3
					{
						probability = "0.1 * trees";
						cost = 1;
					};
				};
			};
		};
	};
	initWorld = "SG_Severograd";
};
class CfgWorldList
{
	class SG_Severograd{};
};
class CfgMissions
{
	class Cutscenes
	{
		class SG_SeverogradIntro1{};
	};
};
