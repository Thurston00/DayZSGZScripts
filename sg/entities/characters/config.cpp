////////////////////////////////////////////////////////////////////
//DeRap: sg_entities_characters\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 01 16:12:29 2019 : 'file' last modified on Mon Jul 29 11:13:29 2019
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
	class SG_Characters
	{
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Characters"};
	};
};
class CfgVehicles
{
	class AllVehicles;
	class Man: AllVehicles
	{
		class ViewPilot;
		class HeadLimits;
	};
	class SurvivorBase: Man
	{
		attachments[] = {"Head","Shoulder","Melee","Headgear","Mask","Eyewear","Hands","LeftHand","Gloves","Armband","Vest","Body","Back","Hips","Legs","Feet","Collar"};
		class NoiseStepStand
		{
			strength = 16.0;
			type = "sound";
		};
		class NoiseStepCrouch
		{
			strength = 6.0;
			type = "sound";
		};
		class NoiseStepProne
		{
			strength = 3.0;
			type = "sound";
		};
		class NoiseLandLight
		{
			strength = 6;
			type = "sound";
		};
		class NoiseLandHeavy
		{
			strength = 25;
			type = "sound";
		};
	};
	class SurvivorMale_Base: SurvivorBase
	{
		model = "\sg\entities\characters\bodies\bodyparts_above0.p3d";
	};
	class SurvivorFemale_Base: SurvivorBase
	{
		model = "\sg\entities\characters\bodies\bodyparts_above0.p3d";
	};
};
class CfgNonAIVehicles
{
	class ProxyCollar_SG
	{
		scope = 2;
		simulation = "ProxyInventory";
		inventorySlot = "Collar";
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 1;
		model = "\sg\entities\Characters\Proxies\Collar_SG.p3d";
	};
};
