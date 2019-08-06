////////////////////////////////////////////////////////////////////
//DeRap: sg_worlds_chernarusplusminus\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 06 17:38:44 2019 : 'file' last modified on Tue May 08 15:10:37 2018
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
	class DZ_Worlds_Chernarusplusminus_World
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Surfaces"};
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
	class ChernarusPlusMinus: CAWorld
	{
		access = 3;
		worldId = 1;
		cutscenes[] = {"ChernarusPlusIntro1"};
		description = "ChernarusPlusMinus";
		worldName = "\sg\worlds\chernarusplusminus\terrain\berezino.wrp";
		class Navmesh
		{
			navmeshName = "\dz\Worlds\chernarusplus\navmesh\navmesh.nm";
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
					maxStepHeight = 0.4;
					maxSlope = 45.0;
				};
				class Links
				{
					class ZedJump387_050
					{
						jumpLength = 1.5;
						jumpHeight = 0.5;
						minCenterHeight = 0.3;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump0";
						flags[] = {"jumpOver"};
						color = 1727987712;
					};
					class ZedJump387_110
					{
						jumpLength = 3.9;
						jumpHeight = 1.1;
						minCenterHeight = 0.5;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump0";
						flags[] = {"jumpOver"};
						color = 1711308800;
					};
					class ZedJump420_160
					{
						jumpLength = 4.0;
						jumpHeight = 1.6;
						minCenterHeight = 1.1;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump0";
						flags[] = {"jumpOver"};
						color = 1711276287;
					};
					class ZedJump265_210
					{
						jumpLength = 2.45;
						jumpHeight = 2.5;
						minCenterHeight = 1.8;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump0";
						flags[] = {"climb"};
						color = 1720975571;
					};
					class Fence50_110deer
					{
						typeId = 100;
						jumpLength = 8.0;
						jumpHeight = 1.1;
						minCenterHeight = 0.5;
						jumpDropdownMin = 1.0;
						jumpDropdownMax = -1.0;
						areaType = "jump2";
						flags[] = {"jumpOver"};
						color = 1722460927;
					};
					class Fence110_160deer
					{
						typeId = 101;
						jumpLength = 8.0;
						jumpHeight = 1.6;
						minCenterHeight = 1.1;
						jumpDropdownMin = 1.0;
						jumpDropdownMax = -1.0;
						areaType = "jump3";
						flags[] = {"jumpOver"};
						color = 1713700856;
					};
					class Fence50_110hen
					{
						typeId = 110;
						jumpLength = 4.0;
						jumpHeight = 1.1;
						minCenterHeight = 0.5;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump4";
						flags[] = {"jumpOver"};
						color = 1728053162;
					};
					class Fence110_160hen
					{
						typeId = 111;
						jumpLength = 4.0;
						jumpHeight = 1.6;
						minCenterHeight = 1.1;
						jumpDropdownMin = 0.5;
						jumpDropdownMax = -0.5;
						areaType = "jump4";
						flags[] = {"jumpOver"};
						color = 1728053162;
					};
				};
			};
		};
		longitude = 30;
		latitude = -45;
		class OutsideTerrain
		{
			satellite = "sg\worlds\chernarusplusminus\data\outside_sat_co.paa";
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
		class Weather: Weather
		{
			class LightingNew
			{
				class C_Night
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -18;
					sunOrMoon = 0.0;
					diffuse[] = {0.1,0.18,0.3};
					diffuseCloud[] = {0.1,0.18,0.3};
					ambient[] = {0.004,0.0079,0.012};
					ambientCloud[] = {0.004,0.0079,0.012};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.036,0.056,0.087};
					skyAroundSun[] = {0.036,0.056,0.087};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Astro1
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -17;
					sunOrMoon = 0.5;
					diffuse[] = {0.0,0.0,0.0};
					diffuseCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.016,0.0316,0.048};
					ambientCloud[] = {0.016,0.0316,0.048};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.036,0.056,0.087};
					skyAroundSun[] = {0.036,0.056,0.087};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Astro2
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -16;
					sunOrMoon = 1.0;
					diffuse[] = {0.0,0.0,0.0};
					diffuseCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.032,0.0632,0.096};
					ambientCloud[] = {0.032,0.0632,0.096};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.036,0.056,0.087};
					skyAroundSun[] = {0.1011,0.1063,0.0926};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Astro3
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -14;
					sunOrMoon = 1.0;
					diffuse[] = {0.0,0.0,0.0};
					diffuseCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.032,0.0632,0.096};
					ambientCloud[] = {0.032,0.0632,0.096};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.1,0.14,0.22};
					skyAroundSun[] = {0.3035,0.319,0.278};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Nautical1
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -12;
					sunOrMoon = 1.0;
					diffuse[] = {0.1011,0.1063,0.0926};
					diffuseCloud[] = {0.1011,0.1063,0.0926};
					ambient[] = {0.032,0.0632,0.096};
					ambientCloud[] = {0.032,0.0632,0.096};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.15,0.21,0.34};
					skyAroundSun[] = {0.6039,0.5411,0.4509};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Nautical2
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -10;
					sunOrMoon = 1.0;
					diffuse[] = {0.1011,0.1063,0.0926};
					diffuseCloud[] = {0.1011,0.1063,0.0926};
					ambient[] = {0.032,0.0632,0.096};
					ambientCloud[] = {0.032,0.0632,0.096};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.15,0.21,0.34};
					skyAroundSun[] = {0.8039,0.5411,0.4509};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Nautical3
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -8;
					sunOrMoon = 1.0;
					diffuse[] = {0.2311,0.2112,0.184};
					diffuseCloud[] = {0.2311,0.2112,0.184};
					ambient[] = {0.064,0.1264,0.192};
					ambientCloud[] = {0.064,0.1264,0.192};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.15,0.21,0.34},0.1};
					skyAroundSun[] = {{1.039,0.5411,0.2509},0.8};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Civil1
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -6;
					sunOrMoon = 1.0;
					diffuse[] = {0.346,0.1803,0.0836};
					diffuseCloud[] = {0.346,0.1803,0.0836};
					ambient[] = {0.128,0.2528,0.384};
					ambientCloud[] = {0.128,0.2528,0.384};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.3,0.225,0.327},1.0};
					skyAroundSun[] = {{1.039,0.5411,0.2509},1.8};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Civil2
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -4;
					sunOrMoon = 1.0;
					diffuse[] = {{0.446,0.1803,0.0836},0.5};
					diffuseCloud[] = {{0.446,0.1803,0.0836},0.5};
					ambient[] = {{0.128,0.2528,0.384},1.5};
					ambientCloud[] = {{0.128,0.2528,0.384},1.5};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.6,0.549,0.745},2.0};
					skyAroundSun[] = {{1.439,0.5411,0.2509},3.1};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Civil3
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -2;
					sunOrMoon = 1.0;
					diffuse[] = {{3.5,1.64,1},2.5};
					diffuseCloud[] = {{3.5,1.64,1},2.5};
					ambient[] = {{0.2,0.23,0.4},3.5};
					ambientCloud[] = {{0.2,0.23,0.4},3.5};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{1.2,0.64,1},4.0};
					skyAroundSun[] = {{1.439,0.5411,0.2509},5.1};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Day0
				{
					height = 0;
					overcast = 0.5;
					sunAngle = 0;
					sunOrMoon = 1.0;
					diffuse[] = {{1.3,0.404,0.294},4.5};
					diffuseCloud[] = {{1.3,0.404,0.294},4.5};
					ambient[] = {{0.2,0.23,0.4},5.5};
					ambientCloud[] = {{0.2,0.23,0.4},5.5};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{1.2,0.64,1},6.7};
					skyAroundSun[] = {{3.5,1.64,1},7.7};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Day4
				{
					height = 0;
					overcast = 0.5;
					sunAngle = 4;
					sunOrMoon = 1;
					diffuse[] = {{1.2,0.404,0.294},9.4};
					diffuseCloud[] = {{1.2,0.404,0.294},9.4};
					ambient[] = {{0.2,0.23,0.4},9.1};
					ambientCloud[] = {{0.2,0.23,0.4},9.1};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{1.2,0.917,1.213},11.0};
					skyAroundSun[] = {{2.2,1.24,1},11.8};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Day8
				{
					height = 0;
					overcast = 0.5;
					sunAngle = 8;
					sunOrMoon = 1;
					diffuse[] = {{1.0,0.604,0.294},10.4};
					diffuseCloud[] = {{1.0,0.604,0.294},10.4};
					ambient[] = {{0.383,0.58,0.858},8.9};
					ambientCloud[] = {{0.383,0.58,0.858},8.9};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{1.1,0.917,1.213},11};
					skyAroundSun[] = {{1.2,0.674,0.294},11.8};
					desiredLuminanceCoef = 0.6;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Day12
				{
					height = 0;
					overcast = 0.5;
					sunAngle = 12;
					sunOrMoon = 1;
					diffuse[] = {{1.0,0.64,0.31},11.4};
					diffuseCloud[] = {{1.0,0.64,0.31},11.4};
					ambient[] = {{0.383,0.58,0.858},9.9};
					ambientCloud[] = {{0.383,0.58,0.858},9.9};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.5,0.64,1},12};
					skyAroundSun[] = {{1.0,0.874,0.494},12.8};
					desiredLuminanceCoef = 0.6;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Day16
				{
					height = 0;
					overcast = 0.5;
					sunAngle = 16;
					sunOrMoon = 1;
					diffuse[] = {{1,0.87,0.85},11.8};
					diffuseCloud[] = {{1,0.87,0.85},11.8};
					ambient[] = {{0.12,0.18,0.28},10.5};
					ambientCloud[] = {{0.12,0.18,0.28},10.5};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.5,0.64,1},12};
					skyAroundSun[] = {{1.0,1.0,1.0},12.8};
					desiredLuminanceCoef = 0.6;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Day35
				{
					height = 0;
					overcast = 0.5;
					sunAngle = 35;
					sunOrMoon = 1;
					diffuse[] = {{1,0.87,0.85},12.4};
					diffuseCloud[] = {{1,0.87,0.85},12.4};
					ambient[] = {{0.2,0.27,0.32},11.2};
					ambientCloud[] = {{0.2,0.27,0.32},11.2};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.5,0.64,1},12};
					skyAroundSun[] = {{1.0,1.0,1.0},12.8};
					desiredLuminanceCoef = 0.6;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class C_Day60
				{
					height = 0;
					overcast = 0.5;
					sunAngle = 60;
					sunOrMoon = 1;
					diffuse[] = {{1,0.87,0.85},13.0};
					diffuseCloud[] = {{1,0.87,0.85},13.0};
					ambient[] = {{0.2,0.27,0.32},12.1};
					ambientCloud[] = {{0.2,0.27,0.32},12.1};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.5,0.64,1},13.0};
					skyAroundSun[] = {{1.0,1.0,1.0},14.0};
					desiredLuminanceCoef = 0.6;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Night
				{
					height = 0;
					overcast = 0.9;
					sunAngle = -18;
					sunOrMoon = 0.0;
					diffuse[] = {0.0,0.0,0.0};
					diffuseCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.004,0.0079,0.012};
					ambientCloud[] = {0.004,0.0079,0.012};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.012,0.012,0.012};
					skyAroundSun[] = {0.012,0.012,0.012};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Astro1
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -17;
					sunOrMoon = 0.5;
					diffuse[] = {0.004,0.0079,0.012};
					diffuseCloud[] = {0.004,0.0079,0.012};
					ambient[] = {0.004,0.0079,0.012};
					ambientCloud[] = {0.004,0.0079,0.012};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.036,0.056,0.087};
					skyAroundSun[] = {0.036,0.056,0.087};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Nautical1
				{
					height = 0;
					overcast = 0.5;
					sunAngle = -12;
					sunOrMoon = 1.0;
					diffuse[] = {0.004,0.0079,0.012};
					diffuseCloud[] = {0.004,0.0079,0.012};
					ambient[] = {0.004,0.0079,0.012};
					ambientCloud[] = {0.004,0.0079,0.012};
					groundReflection[] = {0.0,0.0,0.0};
					groundReflectionCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.036,0.056,0.087};
					skyAroundSun[] = {0.1011,0.1063,0.0926};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Civil1
				{
					height = 0;
					overcast = 0.9;
					sunAngle = -6;
					sunOrMoon = 1;
					diffuse[] = {0.018,0.018,0.018};
					diffuseCloud[] = {0.018,0.018,0.018};
					ambient[] = {0.1,0.18,0.29};
					ambientCloud[] = {0.1,0.18,0.29};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {0.1,0.14,0.22};
					skyAroundSun[] = {0.1,0.14,0.22};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Civil2
				{
					height = 0;
					overcast = 0.9;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {0.018,0.018,0.018};
					diffuseCloud[] = {0.018,0.018,0.018};
					ambient[] = {{0.145,0.227,0.349},1.6};
					ambientCloud[] = {{0.145,0.227,0.349},1.6};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.1,0.14,0.22},2.715};
					skyAroundSun[] = {{0.1,0.14,0.22},3.799};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Day0
				{
					height = 0;
					overcast = 0.9;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.27},0.4};
					diffuseCloud[] = {{0.27,0.27,0.27},0.4};
					ambient[] = {{0.145,0.227,0.349},2.4};
					ambientCloud[] = {{0.145,0.227,0.349},2.4};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.1,0.14,0.22},4.715};
					skyAroundSun[] = {{0.1,0.14,0.22},5.799};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Day4
				{
					height = 0;
					overcast = 0.9;
					sunAngle = 4;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.29},4.4};
					diffuseCloud[] = {{0.27,0.27,0.29},4.4};
					ambient[] = {{0.145,0.227,0.349},5.4};
					ambientCloud[] = {{0.145,0.227,0.349},5.4};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.1,0.18,0.29},6.715};
					skyAroundSun[] = {{0.1,0.18,0.29},7.799};
					desiredLuminanceCoef = 1;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Day8
				{
					height = 0;
					overcast = 0.9;
					sunAngle = 8;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.3},7.4};
					diffuseCloud[] = {{0.27,0.27,0.3},7.4};
					ambient[] = {{0.145,0.227,0.349},8.1};
					ambientCloud[] = {{0.145,0.227,0.349},8.1};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.2,0.36,0.58},8.0};
					skyAroundSun[] = {{0.2,0.36,0.58},8.8};
					desiredLuminanceCoef = 0.6;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Day12
				{
					height = 0;
					overcast = 0.9;
					sunAngle = 12;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.3},8.2};
					diffuseCloud[] = {{0.27,0.27,0.3},8.2};
					ambient[] = {{0.145,0.227,0.349},10.1};
					ambientCloud[] = {{0.145,0.227,0.349},10.1};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{0.4,0.72,1.0},9.0};
					skyAroundSun[] = {{0.4,0.72,1.0},9.8};
					desiredLuminanceCoef = 0.6;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Day35
				{
					height = 0;
					overcast = 0.9;
					sunAngle = 35;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.3},9.4};
					diffuseCloud[] = {{0.27,0.27,0.3},9.4};
					ambient[] = {{0.15,0.2,0.25},11.1};
					ambientCloud[] = {{0.15,0.2,0.25},11.1};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{1,1,1},11};
					skyAroundSun[] = {{1,1,1},11.8};
					desiredLuminanceCoef = 0.6;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
				class O_Day60
				{
					height = 0;
					overcast = 0.9;
					sunAngle = 60;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.3},10.4};
					diffuseCloud[] = {{0.27,0.27,0.3},10.4};
					ambient[] = {{0.2,0.24,0.29},12.4};
					ambientCloud[] = {{0.2,0.24,0.29},12.4};
					groundReflection[] = {0,0,0};
					groundReflectionCloud[] = {0,0,0};
					bidirect[] = {0,0,0};
					bidirectCloud[] = {0,0,0};
					sky[] = {{1,1,1},12};
					skyAroundSun[] = {{1,1,1},12.8};
					desiredLuminanceCoef = 0.6;
					desiredLuminanceCoefCloud = 1;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0,0,0};
					swBrightness = 1;
				};
			};
		};
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
		midDetailTexture = "sg\worlds\chernarusplusminus\data\middle_sat_mco.paa";
		terrainNormalTexture = "sg\worlds\chernarusplusminus\data\global_nohq.paa";
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
	initWorld = "ChernarusPlusMinus";
};
class CfgWorldList
{
	class ChernarusPlusMinus{};
};
class CfgMissions
{
	class Cutscenes
	{
		class ChernarusPlusMinusIntro1
		{
			directory = "sg\worlds\ChernarusPlusMinus\data\scenes\intro.ChernarusPlus";
		};
	};
};
