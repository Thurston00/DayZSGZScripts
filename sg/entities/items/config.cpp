////////////////////////////////////////////////////////////////////
//DeRap: sg_entities_items\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 06 17:38:41 2019 : 'file' last modified on Mon Jul 29 11:14:41 2019
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
	class SG_EntitiesItems
	{
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Explosives","DZ_Gear_Traps","DZ_Characters_Headgear"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class TaloonBag_ColorBase;
	class SG_StartBag: TaloonBag_ColorBase
	{
		scope = 2;
		displayName = "Starting Taloon Backpack";
		heatIsolation = 0.1;
		descriptionShort = "Starting backpack for Survivor GameZ";
		itemsCargoSize[] = {4,5};
		itemsRandom[] = {};
		randomQuantity = 0;
		class StartingItems
		{
			class Weapon
			{
				class Meele
				{
					odd = 0.7;
					items[] = {"BrassKnuckles_Dull","Cleaver","CombatKnife","Hammer","HuntingKnife","LugWrench","Screwdriver","Sickle","StunBaton","TelescopicBaton","PipeWrench","MeatTenderizer","BaseballBat","Broom","Paddle","Crowbar","CattleProd","FarmingHoe","FieldShovel","FireExtinguisher","FirefighterAxe","Hatchet","Pipe","Machete","OldHockeyStick","PipeWrench","Pitchfork","Shovel","SledgeHammer","WoodAxe","Mace"};
				};
				class Pistol
				{
					odd = 0.2;
					items[] = {"MKII","P1","CZ75","Glock19","MakarovIJ70","Derringer_Black","1911","FNX45","LongHorn","Flaregun"};
				};
				class Ammo
				{
					odd = 0.1;
					items[] = {"Ammo_22","Ammo_9x19","Ammo_357","Ammo_45ACP","Ammo_308Win","Ammo_357","Ammo_380","Ammo_12gaPellets","Ammo_12gaSlug","Ammo_762x39","Ammo_762x54Tracer","Ammo_ArrowComposite","Ammo_ArrowBolt"};
				};
			};
			class Clothe
			{
				class Torso
				{
					odd = 0.4;
					items[] = {"GorkaEJacket_Summer","GorkaEJacket_Flat","GorkaEJacket_Autumn","HuntingJacket_Brown","HuntingJacket_Spring","HuntingJacket_Summer","HuntingJacket_Winter","M65Jacket_Black","M65Jacket_Khaki","M65Jacket_Olive","M65Jacket_Tan","PoliceJacketOrel","TacticalShirt_Grey","TacticalShirt_Black","TacticalShirt_Olive","TacticalShirt_Tan","TTsKOJacket_Camo","USMCJacket_Desert","USMCJacket_Woodland","TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_OrangeWhiteStripes","TShirt_Red","TShirt_RedBlackStripes","TShirt_White","TShirt_Grey","Shirt_BlueCheck","Shirt_BlueCheckBright","Shirt_GreenCheck","Shirt_RedCheck","Shirt_WhiteCheck","Shirt_WhiteCheckNewAnimSystem","Shirt_PlaneBlack","MedicalScrubsShirt_Blue","MedicalScrubsShirt_Green","MedicalScrubsShirt_White","TrackSuitJacket_Black","TrackSuitJacket_Blue","TrackSuitJacket_Green","TrackSuitJacket_Red","TrackSuitJacket_LightBlue","Sweater_Gray","Sweater_Blue","Sweater_Green","Sweater_Red","MiniDress_Pink","MiniDress_PinkChecker","MiniDress_RedChecker","MiniDress_WhiteChecker","MiniDress_GreenChecker","MiniDress_BrownChecker","MiniDress_BlueChecker","MiniDress_BlueWithDots","LabCoat","NurseDress_White","NurseDress_Blue","WoolCoat_RedCheck","WoolCoat_BlackCheck","WoolCoat_BlueCheck","WoolCoat_GreyCheck","WoolCoat_BrownCheck","Hoodie_Blue","Hoodie_Black","Hoodie_Brown","Hoodie_Green","Hoodie_Grey","Hoodie_Red","WoolCoat_Black","WoolCoat_Red","WoolCoat_Blue","WoolCoat_Green","WoolCoat_Beige","RidersJacket_Black","TrackSuitJacket_Black","TrackSuitJacket_Blue","TrackSuitJacket_Green","TrackSuitJacket_Red","TrackSuitJacket_LightBlue","Raincoat_Orange","Raincoat_Green","Raincoat_Yellow","Raincoat_Pink","Raincoat_Red","Raincoat_Blue","Raincoat_Black","PoliceJacket","ParamedicJacket_Blue","ParamedicJacket_Crimson","ParamedicJacket_Green","QuiltedJacket_Black","QuiltedJacket_Green","QuiltedJacket_Blue","QuiltedJacket_Red","QuiltedJacket_Grey","QuiltedJacket_Orange","QuiltedJacket_Yellow","QuiltedJacket_Violet","BomberJacket_Black","BomberJacket_Brown","BomberJacket_Blue","BomberJacket_Grey","BomberJacket_Maroon","BomberJacket_Olive","BomberJacket_SkyBlue","HikingJacket_Black","HikingJacket_Blue","HikingJacket_Red","HikingJacket_Green","FirefighterJacket_Beige","FirefighterJacket_Black"};
				};
				class Leg
				{
					odd = 0.4;
					items[] = {"BDUPants","TTSKOPants","PolicePants"};
				};
				class Head
				{
					odd = 0.2;
					items[] = {"BallisticHelmet_Green","Ssh68Helmet","TankerHelmet"};
				};
			};
			class Food
			{
				class All
				{
					odd = 1.0;
					items[] = {"SpaghettiCan","TunaCan","TacticalBaconCan"};
				};
			};
			class Drink
			{
				class All
				{
					odd = 1.0;
					items[] = {"SodaCan_Cola","SodaCan_Spite","SodaCan_Pipsi","SodaCan_Kvass"};
				};
			};
			class Tool
			{
				class All
				{
					odd = 1.0;
					items[] = {"Compass","Binoculars","DuctTape"};
				};
			};
			class Attachment
			{
				class All
				{
					odd = 1.0;
					items[] = {"Red9Bttstck","Mosin_Bayonet","ACOGOptic"};
				};
			};
			class Medical
			{
				class Bandage
				{
					odd = 0.5;
					items[] = {"Bandage","BandageDressing"};
				};
				class Rag
				{
					odd = 0.5;
					items[] = {"Rag"};
				};
				class Epinephrine
				{
					odd = 0.5;
					items[] = {"Epinephrine"};
				};
			};
		};
	};
	class SG_StartBag_Blue: SG_StartBag
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\backpacks\data\Taloon_Blue_co.paa","DZ\characters\backpacks\data\Taloon_Blue_co.paa","DZ\characters\backpacks\data\Taloon_Blue_co.paa"};
	};
	class SG_StartBag_Green: SG_StartBag
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\backpacks\data\Taloon_Green_co.paa","DZ\characters\backpacks\data\Taloon_Green_co.paa","DZ\characters\backpacks\data\Taloon_Green_co.paa"};
	};
	class SG_StartBag_Orange: SG_StartBag
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\backpacks\data\Taloon_Orange_co.paa","DZ\characters\backpacks\data\Taloon_Orange_co.paa","DZ\characters\backpacks\data\Taloon_Orange_co.paa"};
	};
	class SG_StartBag_Violet: SG_StartBag
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\backpacks\data\Taloon_Violet_co.paa","DZ\characters\backpacks\data\Taloon_Violet_co.paa","DZ\characters\backpacks\data\Taloon_Violet_co.paa"};
	};
	class Edible_Base;
	class FoodAnimationSources{};
	class FoodStageTransitions;
	class FruitStageTransitions{};
	class MeatStageTransitions{};
	class BoxCerealCrunchin: Edible_Base
	{
		varQuantityInit = 1500;
		varQuantityMin = 0;
		varQuantityMax = 1500;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 930;
			water = 0;
			nutritionalIndex = 105;
		};
	};
	class PowderedMilk: Edible_Base
	{
		varQuantityInit = 1500;
		varQuantityMin = 0;
		varQuantityMax = 1500;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 992;
			water = 0;
			nutritionalIndex = 84;
		};
	};
	class Rice: Edible_Base
	{
		varQuantityInit = 1500;
		varQuantityMin = 0;
		varQuantityMax = 1500;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 3740;
			water = 0;
			nutritionalIndex = 500;
		};
	};
	class Marmalade: Edible_Base
	{
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 836;
			water = 0;
			nutritionalIndex = 95;
		};
	};
	class BakedBeansCan_Opened: Edible_Base
	{
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 78;
			water = 0;
			nutritionalIndex = 1;
		};
	};
	class PeachesCan_Opened: Edible_Base
	{
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 74;
			water = 0;
			nutritionalIndex = 1;
		};
	};
	class TacticalBaconCan_Opened: Edible_Base
	{
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 548;
			water = 0;
			nutritionalIndex = 1;
		};
	};
	class SpaghettiCan_Opened: Edible_Base
	{
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 107;
			water = 0;
			nutritionalIndex = 1;
		};
	};
	class SardinesCan_Opened: Edible_Base
	{
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 208;
			water = 0;
			nutritionalIndex = 1;
		};
	};
	class TunaCan_Opened: Edible_Base
	{
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 186;
			water = 0;
			nutritionalIndex = 1;
		};
	};
	class Apple: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class Banana: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class Orange: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class Tomato: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class GreenBellPepper: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class Zucchini: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class SlicedPumpkin: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class Potato: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class Kiwi: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class SambucusBerry: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class CaninaBerry: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class Cannabis: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class Plum: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class Pear: Edible_Base
	{
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,70,0,32};
					cooking_properties[] = {0,0};
					modifiers[] = {};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
	};
	class HumanSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,537,0,129};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,537,0,129};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class GoatSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class MouflonSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class BoarSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class PigSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class DeerSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class WolfSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class BearSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class CowSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class SheepSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class FoxSteakMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class ChickenBreastMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class RabbitLegMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class CarpFilletMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class MackerelFilletMeat: Edible_Base
	{
		varQuantityInit = 1800;
		varQuantityMin = 0;
		varQuantityMax = 1800;
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {0.5,544,0,236};
					cooking_properties[] = {0,0};
					modifiers[] = {"FoodPoisoning_MediumImpact","Salmonellosis","BrainDisease"};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,30};
					modifiers[] = {"BrainDisease"};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,544,0,236};
					cooking_properties[] = {70,40};
					modifiers[] = {"BrainDisease"};
				};
			};
		};
		class FoodStageTransitions: MeatStageTransitions{};
	};
	class SodaCan_ColorBase: Edible_Base
	{
		varQuantityInit = 400;
		varQuantityMin = 0;
		varQuantityMax = 400;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 43.5;
			water = 0;
			nutritionalIndex = 1;
		};
	};
	class VitaminBottle: Edible_Base
	{
		SingleUseActions[] = {515,520};
		ContinuousActions[] = {120,125};
		varQuantityInit = 10;
		varQuantityMin = 0;
		varQuantityMax = 10;
		quantityBar = 1;
		class Medical
		{
			percentageHeal = 2;
		};
	};
	class TetracyclineAntibiotics: Edible_Base
	{
		SingleUseActions[] = {516,521};
		ContinuousActions[] = {121,126};
		varQuantityInit = 10;
		varQuantityMin = 0;
		varQuantityMax = 10;
		quantityBar = 1;
		class Medical
		{
			percentageHeal = 5;
		};
	};
	class PainkillerTablets: Edible_Base
	{
		SingleUseActions[] = {515,520};
		ContinuousActions[] = {120,125};
		varQuantityInit = 10;
		varQuantityMin = 0;
		varQuantityMax = 10;
		quantityBar = 1;
	};
	class Epinephrine: Inventory_Base
	{
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
	};
	class Morphine: Inventory_Base
	{
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
	};
	class Clothing;
	class PoliceVest: Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
			class GlobalArmor
			{
				immunityBleeding = 1;
				immunityHeadshotInstantKill = 1;
				class Projectile
				{
					class Health
					{
						damage = 0.7;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class PressVest_ColorBase: Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
			class GlobalArmor
			{
				immunityBleeding = 1;
				immunityHeadshotInstantKill = 1;
				class Projectile
				{
					class Health
					{
						damage = 0.6;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.4;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.4;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class PlateCarrierVest: Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
			class GlobalArmor
			{
				immunityBleeding = 1;
				immunityHeadshotInstantKill = 1;
				class Projectile
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.3;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.3;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class WeldingMask: Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
				};
			};
			class GlobalArmor
			{
				immunityBleeding = 1;
				immunityHeadshotInstantKill = 1;
				class Projectile
				{
					class Health
					{
						damage = 0.7;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class FirefightersHelmet_ColorBase: Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
				};
			};
			class GlobalArmor
			{
				immunityBleeding = 1;
				immunityHeadshotInstantKill = 1;
				class Projectile
				{
					class Health
					{
						damage = 0.7;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class TankerHelmet: Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
				};
			};
			class GlobalArmor
			{
				immunityBleeding = 1;
				immunityHeadshotInstantKill = 1;
				class Projectile
				{
					class Health
					{
						damage = 0.7;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class MotoHelmet_ColorBase: Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
				};
			};
			class GlobalArmor
			{
				immunityBleeding = 1;
				immunityHeadshotInstantKill = 1;
				class Projectile
				{
					class Health
					{
						damage = 0.7;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class GreatHelm: Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
			class GlobalArmor
			{
				immunityBleeding = 1;
				immunityHeadshotInstantKill = 1;
				class Projectile
				{
					class Health
					{
						damage = 0.6;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.4;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.4;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class GorkaHelmet: Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
			class GlobalArmor
			{
				immunityBleeding = 1;
				immunityHeadshotInstantKill = 1;
				class Projectile
				{
					class Health
					{
						damage = 0.6;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.4;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.4;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class BallisticHelmet_ColorBase: Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
			class GlobalArmor
			{
				immunityBleeding = 1;
				immunityHeadshotInstantKill = 1;
				class Projectile
				{
					class Health
					{
						damage = 0.5;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.3;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.3;
						startOnHealth = 1;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class MeleeItemBase: Inventory_Base
	{
		handheld = "true";
		armAction = "TwoHanded";
		inventorySlot = "Melee";
		itemSize[] = {1,2};
		lootCategory = "Tools";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeFist";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeFist_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeFist_Heavy";
				range = 2.8;
			};
		};
	};
};
class CfgAmmo
{
	class BulletCore;
	class Bullet_Base: BulletCore
	{
		scope = 0;
		hit = 8;
		indirectHit = 0;
		indirectHitRange = 0;
		model = "";
		soundFly[] = {"",9.999997e-009,1};
		soundDefault1[] = {"dz\sounds\weapons\hits\bullet\soft_ground_1",0.5,1,40};
		soundDefault2[] = {"dz\sounds\weapons\hits\bullet\soft_ground_2",0.5,1,40};
		soundDefault3[] = {"dz\sounds\weapons\hits\bullet\soft_ground_3",0.5,1,40};
		soundDefault4[] = {"dz\sounds\weapons\hits\bullet\soft_ground_4",0.5,1,40};
		soundDefault5[] = {"dz\sounds\weapons\hits\bullet\soft_ground_5",0.5,1,40};
		soundDefault6[] = {"dz\sounds\weapons\hits\bullet\soft_ground_6",0.5,1,40};
		soundDefault7[] = {"dz\sounds\weapons\hits\bullet\soft_ground_7",0.5,1,40};
		soundDefault8[] = {"dz\sounds\weapons\hits\bullet\soft_ground_8",0.5,1,40};
		soundGroundSoft1[] = {"dz\sounds\weapons\hits\bullet\soft_ground_1",0.5,1,40};
		soundGroundSoft2[] = {"dz\sounds\weapons\hits\bullet\soft_ground_2",0.5,1,40};
		soundGroundSoft3[] = {"dz\sounds\weapons\hits\bullet\soft_ground_3",0.5,1,40};
		soundGroundSoft4[] = {"dz\sounds\weapons\hits\bullet\soft_ground_4",0.5,1,40};
		soundGroundSoft5[] = {"dz\sounds\weapons\hits\bullet\soft_ground_5",0.5,1,40};
		soundGroundSoft6[] = {"dz\sounds\weapons\hits\bullet\soft_ground_6",0.5,1,40};
		soundGroundSoft7[] = {"dz\sounds\weapons\hits\bullet\soft_ground_7",0.5,1,40};
		soundGroundSoft8[] = {"dz\sounds\weapons\hits\bullet\soft_ground_8",0.5,1,40};
		soundGroundHard1[] = {"dz\sounds\weapons\hits\bullet\hard_ground_1",0.5,1,40};
		soundGroundHard2[] = {"dz\sounds\weapons\hits\bullet\hard_ground_2",0.5,1,40};
		soundGroundHard3[] = {"dz\sounds\weapons\hits\bullet\hard_ground_3",0.5,1,40};
		soundGroundHard4[] = {"dz\sounds\weapons\hits\bullet\hard_ground_4",0.5,1,40};
		soundGroundHard5[] = {"dz\sounds\weapons\hits\bullet\hard_ground_5",0.5,1,40};
		soundGroundHard6[] = {"dz\sounds\weapons\hits\bullet\hard_ground_6",0.5,1,40};
		soundGroundHard7[] = {"dz\sounds\weapons\hits\bullet\hard_ground_7",0.5,1,40};
		soundGroundHard8[] = {"dz\sounds\weapons\hits\bullet\hard_ground_8",0.5,1,40};
		soundMetal1[] = {"dz\sounds\weapons\hits\bullet\metal_1",0.5,1,40};
		soundMetal2[] = {"dz\sounds\weapons\hits\bullet\metal_2",0.5,1,40};
		soundMetal3[] = {"dz\sounds\weapons\hits\bullet\metal_3",0.5,1,40};
		soundMetal4[] = {"dz\sounds\weapons\hits\bullet\metal_4",0.5,1,40};
		soundMetal5[] = {"dz\sounds\weapons\hits\bullet\metal_5",0.5,1,40};
		soundMetal6[] = {"dz\sounds\weapons\hits\bullet\metal_6",0.5,1,40};
		soundMetal7[] = {"dz\sounds\weapons\hits\bullet\metal_7",0.5,1,40};
		soundMetal8[] = {"dz\sounds\weapons\hits\bullet\metal_8",0.5,1,40};
		soundGlass1[] = {"dz\sounds\weapons\hits\bullet\glass_1",0.5,1,40};
		soundGlass2[] = {"dz\sounds\weapons\hits\bullet\glass_2",0.5,1,40};
		soundGlass3[] = {"dz\sounds\weapons\hits\bullet\glass_3",0.5,1,40};
		soundGlass4[] = {"dz\sounds\weapons\hits\bullet\glass_4",0.5,1,40};
		soundGlass5[] = {"dz\sounds\weapons\hits\bullet\glass_5",0.5,1,40};
		soundGlass6[] = {"dz\sounds\weapons\hits\bullet\glass_6",0.5,1,40};
		soundGlass7[] = {"dz\sounds\weapons\hits\bullet\glass_7",0.5,1,40};
		soundGlass8[] = {"dz\sounds\weapons\hits\bullet\glass_8",0.5,1,40};
		soundGlassArmored1[] = {"dz\sounds\weapons\hits\bullet\glass_arm_1",0.5,1,40};
		soundGlassArmored2[] = {"dz\sounds\weapons\hits\bullet\glass_arm_2",0.5,1,40};
		soundGlassArmored3[] = {"dz\sounds\weapons\hits\bullet\glass_arm_3",0.5,1,40};
		soundGlassArmored4[] = {"dz\sounds\weapons\hits\bullet\glass_arm_4",0.5,1,40};
		soundGlassArmored5[] = {"dz\sounds\weapons\hits\bullet\glass_arm_5",0.5,1,40};
		soundGlassArmored6[] = {"dz\sounds\weapons\hits\bullet\glass_arm_6",0.5,1,40};
		soundGlassArmored7[] = {"dz\sounds\weapons\hits\bullet\glass_arm_7",0.5,1,40};
		soundGlassArmored8[] = {"dz\sounds\weapons\hits\bullet\glass_arm_8",0.5,1,40};
		soundVehiclePlate1[] = {"dz\sounds\weapons\hits\bullet\metal_plate_1",0.5,1,40};
		soundVehiclePlate2[] = {"dz\sounds\weapons\hits\bullet\metal_plate_2",0.5,1,40};
		soundVehiclePlate3[] = {"dz\sounds\weapons\hits\bullet\metal_plate_3",0.5,1,40};
		soundVehiclePlate4[] = {"dz\sounds\weapons\hits\bullet\metal_plate_4",0.5,1,40};
		soundVehiclePlate5[] = {"dz\sounds\weapons\hits\bullet\metal_plate_5",0.5,1,40};
		soundVehiclePlate6[] = {"dz\sounds\weapons\hits\bullet\metal_plate_6",0.5,1,40};
		soundVehiclePlate7[] = {"dz\sounds\weapons\hits\bullet\metal_plate_7",0.5,1,40};
		soundVehiclePlate8[] = {"dz\sounds\weapons\hits\bullet\metal_plate_8",0.5,1,40};
		soundWood1[] = {"dz\sounds\weapons\hits\bullet\wood_1",0.5,1,40};
		soundWood2[] = {"dz\sounds\weapons\hits\bullet\wood_2",0.5,1,40};
		soundWood3[] = {"dz\sounds\weapons\hits\bullet\wood_3",0.5,1,40};
		soundWood4[] = {"dz\sounds\weapons\hits\bullet\wood_4",0.5,1,40};
		soundWood5[] = {"dz\sounds\weapons\hits\bullet\wood_5",0.5,1,40};
		soundWood6[] = {"dz\sounds\weapons\hits\bullet\wood_6",0.5,1,40};
		soundWood7[] = {"dz\sounds\weapons\hits\bullet\wood_7",0.5,1,40};
		soundWood8[] = {"dz\sounds\weapons\hits\bullet\wood_8",0.5,1,40};
		soundHitBody1[] = {"dz\sounds\weapons\hits\bullet\body_1",1,1,20};
		soundHitBody2[] = {"dz\sounds\weapons\hits\bullet\body_2",1,1,20};
		soundHitBody3[] = {"dz\sounds\weapons\hits\bullet\body_3",1,1,20};
		soundHitBody4[] = {"dz\sounds\weapons\hits\bullet\body_4",1,1,20};
		soundHitBody5[] = {"dz\sounds\weapons\hits\bullet\body_5",1,1,20};
		soundHitBody6[] = {"dz\sounds\weapons\hits\bullet\body_6",1,1,20};
		soundHitBody7[] = {"dz\sounds\weapons\hits\bullet\body_7",1,1,20};
		soundHitBody8[] = {"dz\sounds\weapons\hits\bullet\body_8",1,1,20};
		soundHitBuilding1[] = {"dz\sounds\weapons\hits\bullet\building_1",0.5,1,40};
		soundHitBuilding2[] = {"dz\sounds\weapons\hits\bullet\building_2",0.5,1,40};
		soundHitBuilding3[] = {"dz\sounds\weapons\hits\bullet\building_3",0.5,1,40};
		soundHitBuilding4[] = {"dz\sounds\weapons\hits\bullet\building_4",0.5,1,40};
		soundHitBuilding5[] = {"dz\sounds\weapons\hits\bullet\building_5",0.5,1,40};
		soundHitBuilding6[] = {"dz\sounds\weapons\hits\bullet\building_6",0.5,1,40};
		soundHitBuilding7[] = {"dz\sounds\weapons\hits\bullet\building_7",0.5,1,40};
		soundHitBuilding8[] = {"dz\sounds\weapons\hits\bullet\building_8",0.5,1,40};
		soundHitFoliage1[] = {"dz\sounds\weapons\hits\bullet\foliage_1",1,1,20};
		soundHitFoliage2[] = {"dz\sounds\weapons\hits\bullet\foliage_2",1,1,20};
		soundHitFoliage3[] = {"dz\sounds\weapons\hits\bullet\foliage_3",1,1,20};
		soundHitFoliage4[] = {"dz\sounds\weapons\hits\bullet\foliage_4",1,1,20};
		soundHitFoliage5[] = {"dz\sounds\weapons\hits\bullet\foliage_5",1,1,20};
		soundHitFoliage6[] = {"dz\sounds\weapons\hits\bullet\foliage_6",1,1,20};
		soundHitFoliage7[] = {"dz\sounds\weapons\hits\bullet\foliage_7",1,1,20};
		soundHitFoliage8[] = {"dz\sounds\weapons\hits\bullet\foliage_8",1,1,20};
		soundPlastic1[] = {"dz\sounds\weapons\hits\bullet\plastic_1",0.5,1,40};
		soundPlastic2[] = {"dz\sounds\weapons\hits\bullet\plastic_2",0.5,1,40};
		soundPlastic3[] = {"dz\sounds\weapons\hits\bullet\plastic_3",0.5,1,40};
		soundPlastic4[] = {"dz\sounds\weapons\hits\bullet\plastic_4",0.5,1,40};
		soundPlastic5[] = {"dz\sounds\weapons\hits\bullet\plastic_5",0.5,1,40};
		soundPlastic6[] = {"dz\sounds\weapons\hits\bullet\plastic_6",0.5,1,40};
		soundPlastic7[] = {"dz\sounds\weapons\hits\bullet\plastic_7",0.5,1,40};
		soundPlastic8[] = {"dz\sounds\weapons\hits\bullet\plastic_8",0.5,1,40};
		soundConcrete1[] = {"dz\sounds\weapons\hits\bullet\concrete_1",0.5,1,40};
		soundConcrete2[] = {"dz\sounds\weapons\hits\bullet\concrete_2",0.5,1,40};
		soundConcrete3[] = {"dz\sounds\weapons\hits\bullet\concrete_3",0.5,1,40};
		soundConcrete4[] = {"dz\sounds\weapons\hits\bullet\concrete_4",0.5,1,40};
		soundConcrete5[] = {"dz\sounds\weapons\hits\bullet\concrete_5",0.5,1,40};
		soundConcrete6[] = {"dz\sounds\weapons\hits\bullet\concrete_6",0.5,1,40};
		soundConcrete7[] = {"dz\sounds\weapons\hits\bullet\concrete_7",0.5,1,40};
		soundConcrete8[] = {"dz\sounds\weapons\hits\bullet\concrete_8",0.5,1,40};
		soundRubber1[] = {"dz\sounds\weapons\hits\bullet\tyre_1",0.5,1,40};
		soundRubber2[] = {"dz\sounds\weapons\hits\bullet\tyre_2",0.5,1,40};
		soundRubber3[] = {"dz\sounds\weapons\hits\bullet\tyre_3",0.5,1,40};
		soundRubber4[] = {"dz\sounds\weapons\hits\bullet\tyre_4",0.5,1,40};
		soundRubber5[] = {"dz\sounds\weapons\hits\bullet\tyre_5",0.5,1,40};
		soundRubber6[] = {"dz\sounds\weapons\hits\bullet\tyre_6",0.5,1,40};
		soundRubber7[] = {"dz\sounds\weapons\hits\bullet\tyre_7",0.5,1,40};
		soundRubber8[] = {"dz\sounds\weapons\hits\bullet\tyre_8",0.5,1,40};
		soundWater1[] = {"dz\sounds\weapons\hits\bullet\water_1",0.5,1,40};
		soundWater2[] = {"dz\sounds\weapons\hits\bullet\water_2",0.5,1,40};
		soundWater3[] = {"dz\sounds\weapons\hits\bullet\water_3",0.5,1,40};
		soundWater4[] = {"dz\sounds\weapons\hits\bullet\water_4",0.5,1,40};
		soundWater5[] = {"dz\sounds\weapons\hits\bullet\water_5",0.5,1,40};
		soundWater6[] = {"dz\sounds\weapons\hits\bullet\water_6",0.5,1,40};
		soundWater7[] = {"dz\sounds\weapons\hits\bullet\water_7",0.5,1,40};
		soundWater8[] = {"dz\sounds\weapons\hits\bullet\water_8",0.5,1,40};
		hitGroundSoft[] = {"soundGroundSoft1",0.125,"soundGroundSoft2",0.125,"soundGroundSoft3",0.125,"soundGroundSoft4",0.125,"soundGroundSoft5",0.125,"soundGroundSoft6",0.125,"soundGroundSoft7",0.125,"soundGroundSoft8",0.125};
		hitGroundHard[] = {"soundGroundHard1",0.125,"soundGroundHard2",0.125,"soundGroundHard3",0.125,"soundGroundHard4",0.125,"soundGroundHard5",0.125,"soundGroundHard6",0.125,"soundGroundHard7",0.125,"soundGroundHard8",0.125};
		hitMan[] = {"soundHitBody1",0.125,"soundHitBody2",0.125,"soundHitBody3",0.125,"soundHitBody4",0.125,"soundHitBody5",0.125,"soundHitBody6",0.125,"soundHitBody7",0.125,"soundHitBody8",0.125};
		hitArmor[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitBuilding[] = {"soundHitBuilding1",0.125,"soundHitBuilding2",0.125,"soundHitBuilding3",0.125,"soundHitBuilding4",0.125,"soundHitBuilding5",0.125,"soundHitBuilding6",0.125,"soundHitBuilding7",0.125,"soundHitBuilding8",0.125};
		hitFoliage[] = {"soundHitFoliage1",0.125,"soundHitFoliage2",0.125,"soundHitFoliage3",0.125,"soundHitFoliage4",0.125,"soundHitFoliage5",0.125,"soundHitFoliage6",0.125,"soundHitFoliage7",0.125,"soundHitFoliage8",0.125};
		hitWood[] = {"soundWood1",0.125,"soundWood2",0.125,"soundWood3",0.125,"soundWood4",0.125,"soundWood5",0.125,"soundWood6",0.125,"soundWood7",0.125,"soundWood8",0.125};
		hitGlass[] = {"soundGlass1",0.125,"soundGlass2",0.125,"soundGlass3",0.125,"soundGlass4",0.125,"soundGlass5",0.125,"soundGlass6",0.125,"soundGlass7",0.125,"soundGlass8",0.125};
		hitGlassArmored[] = {"soundGlassArmored1",0.125,"soundGlassArmored2",0.125,"soundGlassArmored3",0.125,"soundGlassArmored4",0.125,"soundGlassArmored5",0.125,"soundGlassArmored6",0.125,"soundGlassArmored7",0.125,"soundGlassArmored8",0.125};
		hitConcrete[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitRubber[] = {"soundRubber1",0.25,"soundRubber2",0.25,"soundRubber3",0.25,"soundRubber4",0.25};
		hitPlastic[] = {"soundPlastic1",0.125,"soundPlastic2",0.125,"soundPlastic3",0.125,"soundPlastic4",0.125,"soundPlastic5",0.125,"soundPlastic6",0.125,"soundPlastic7",0.125,"soundPlastic8",0.125};
		hitDefault[] = {"soundDefault1",0.125,"soundDefault2",0.125,"soundDefault3",0.125,"soundDefault4",0.125,"soundDefault5",0.125,"soundDefault6",0.125,"soundDefault7",0.125,"soundDefault8",0.125};
		hitMetal[] = {"soundMetal1",0.125,"soundMetal2",0.125,"soundMetal3",0.125,"soundMetal4",0.125,"soundMetal5",0.125,"soundMetal6",0.125,"soundMetal7",0.125,"soundMetal8",0.125};
		hitMetalplate[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitWater[] = {"soundWater1",0.125,"soundWater2",0.125,"soundWater3",0.125,"soundWater4",0.125,"soundWater5",0.125,"soundWater6",0.125,"soundWater7",0.125,"soundWater8",0.125};
		soundSetBulletFly[] = {"bulletFlyBy_SoundSet"};
		soundSetSuperSonic[] = {"SuperSonicCrack_SoundSet","SuperSonicCrackTail_SoundSet"};
		class SoundSetsGroundHits
		{
			default[] = {"Shell_39mm_default_SoundSet"};
			asphalt_ext[] = {"Shell_39mm_default_SoundSet"};
			asphalt_destroyed_ext[] = {"Shell_39mm_default_SoundSet"};
			asphalt_int[] = {"Shell_39mm_default_int_SoundSet"};
			asphalt_destroyed_int[] = {"Shell_39mm_default_int_SoundSet"};
			asphalt_felt[] = {"Shell_39mm_default_SoundSet"};
			asphalt_felt_int[] = {"Shell_39mm_default_int_SoundSet"};
			cp_broadleaf_dense1[] = {"Shell_39mm_leaves_SoundSet"};
			cp_broadleaf_dense2[] = {"Shell_39mm_leaves_SoundSet"};
			cp_broadleaf_sparse1[] = {"Shell_39mm_leaves_SoundSet"};
			cp_broadleaf_sparse2[] = {"Shell_39mm_leaves_SoundSet"};
			cp_conifer_common1[] = {"Shell_39mm_leaves_SoundSet"};
			cp_conifer_common2[] = {"Shell_39mm_leaves_SoundSet"};
			cp_conifer_moss1[] = {"Shell_39mm_leaves_SoundSet"};
			cp_conifer_moss2[] = {"Shell_39mm_leaves_SoundSet"};
			cp_concrete1[] = {"Shell_39mm_default_SoundSet"};
			cp_concrete2[] = {"Shell_39mm_default_SoundSet"};
			concrete_ext[] = {"Shell_39mm_default_SoundSet"};
			concrete_stairs_ext[] = {"Shell_39mm_default_SoundSet"};
			concrete_int[] = {"Shell_39mm_default_int_SoundSet"};
			concrete_stairs[] = {"Shell_39mm_default_SoundSet"};
			ceramic_tiles_ext[] = {"Shell_39mm_default_SoundSet"};
			ceramic_tiles_int[] = {"Shell_39mm_default_int_SoundSet"};
			ceramic_tiles_roof_ext[] = {"Shell_39mm_default_SoundSet"};
			ceramic_tiles_roof_int[] = {"Shell_39mm_default_int_SoundSet"};
			cp_dirt[] = {"Shell_39mm_dirt_SoundSet"};
			dirt_ext[] = {"Shell_39mm_dirt_SoundSet"};
			dirt_int[] = {"Shell_39mm_dirt_int_SoundSet"};
			cp_grass[] = {"Shell_39mm_grass_SoundSet"};
			grass_dry_ext[] = {"Shell_39mm_grass_SoundSet"};
			grass_dry_int[] = {"Shell_39mm_grass_int_SoundSet"};
			cp_grass_tall[] = {"Shell_39mm_grass_SoundSet"};
			cp_gravel[] = {"Shell_39mm_gravel_SoundSet"};
			gravel_small_ext[] = {"Shell_39mm_gravel_SoundSet"};
			gravel_small_int[] = {"Shell_39mm_gravel_int_SoundSet"};
			gravel_large_ext[] = {"Shell_39mm_gravel_SoundSet"};
			gravel_large_int[] = {"Shell_39mm_gravel_int_SoundSet"};
			lino_ext[] = {"Shell_39mm_default_SoundSet"};
			lino_int[] = {"Shell_39mm_default_int_SoundSet"};
			metal_thick_ext[] = {"Shell_39mm_metal_SoundSet"};
			metal_stairs_ext[] = {"Shell_39mm_metal_SoundSet"};
			metal_thick_int[] = {"Shell_39mm_metal_int_SoundSet"};
			metal_thin_ext[] = {"Shell_39mm_metal_SoundSet"};
			metal_thin_int[] = {"Shell_39mm_metal_int_SoundSet"};
			metal_thin_mesh_ext[] = {"Shell_39mm_metal_SoundSet"};
			metal_thin_mesh_int[] = {"Shell_39mm_metal_int_SoundSet"};
			cp_rock[] = {"Shell_39mm_default_SoundSet"};
			rubble_large_ext[] = {"Shell_39mm_gravel_SoundSet"};
			rubble_large_int[] = {"Shell_39mm_gravel_int_SoundSet"};
			rubble_small_ext[] = {"Shell_39mm_gravel_SoundSet"};
			rubble_small_int[] = {"Shell_39mm_gravel_int_SoundSet"};
			sand_ext[] = {"Shell_39mm_sand_SoundSet"};
			sand_int[] = {"Shell_39mm_sand_int_SoundSet"};
			stone_ext[] = {"Shell_39mm_sand_SoundSet"};
			stone_int[] = {"Shell_39mm_sand_int_SoundSet"};
			textile_carpet_ext[] = {"Shell_39mm_carpet_SoundSet"};
			textile_carpet_int[] = {"Shell_39mm_carpet_int_SoundSet"};
			trash_ext[] = {"Shell_39mm_default_SoundSet"};
			trash_int[] = {"Shell_39mm_default_int_SoundSet"};
			wood_parquet_ext[] = {"Shell_39mm_wood_SoundSet"};
			wood_parquet_int[] = {"Shell_39mm_wood_int_SoundSet"};
			wood_planks_ext[] = {"Shell_39mm_wood_SoundSet"};
			wood_planks_stairs_ext[] = {"Shell_39mm_wood_SoundSet"};
			wood_planks_int[] = {"Shell_39mm_wood_int_SoundSet"};
			wood_planks_stairs_int[] = {"Shell_39mm_wood_int_SoundSet"};
			fresh_water_ext[] = {"Shell_39mm_water_SoundSet"};
			fresh_water_int[] = {"Shell_39mm_water_int_SoundSet"};
			water[] = {"Shell_39mm_water_SoundSet"};
		};
		supersonicCrackNear[] = {};
		supersonicCrackFar[] = {};
		cartridge = "FxCartridge_556";
		timeToLive = 6;
		deflecting = 10;
		tracerStartTime = -1;
		muzzleEffect = "BIS_Effects_Rifle";
		maxLeadSpeed = 23;
		typicalSpeed = 900;
		initSpeed = 900;
		weight = 0.015;
		impactBehaviour = 0;
		class DamageApplied
		{
			type = "Projectile";
			dispersion = 0.0;
			bleedThreshold = 1.0;
			class Health
			{
				damage = 99;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 0;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
	};
	class MeleeDamage: Bullet_Base
	{
		class NoiseHit
		{
			strength = 0;
			type = "sound";
		};
	};
	class SG_MeleeInfected: MeleeDamage
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.15;
			class Health
			{
				damage = 10;
			};
			class Blood
			{
				damage = 50;
			};
			class Shock
			{
				damage = 6;
			};
			additionAnimalMeleeMultiplier = 2;
		};
		soundDefault1[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_1",0.56234133,1,60};
		soundDefault2[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_2",0.56234133,1,60};
		soundDefault3[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_3",0.56234133,1,60};
		soundDefault4[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_4",0.56234133,1,60};
		soundDefault5[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_5",0.56234133,1,60};
		soundDefault6[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_6",0.56234133,1,60};
		soundGroundSoft1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_01",0.5,1,60};
		soundGroundSoft2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_02",0.5,1,60};
		soundGroundSoft3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_03",0.5,1,60};
		soundGroundSoft4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_04",0.5,1,60};
		soundGroundSoft5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_05",0.5,1,60};
		soundGroundSoft6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_06",0.5,1,60};
		soundGroundSoft7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_07",0.5,1,60};
		soundGroundSoft8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_08",0.5,1,60};
		soundGroundHard1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_01",0.5,1,80};
		soundGroundHard2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_02",0.5,1,80};
		soundGroundHard3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_03",0.5,1,80};
		soundGroundHard4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_04",0.5,1,80};
		soundGroundHard5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_05",0.5,1,80};
		soundGroundHard6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_06",0.5,1,80};
		soundGroundHard7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_07",0.5,1,80};
		soundGroundHard8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_08",0.5,1,80};
		soundMetal1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",0.5,1,80};
		soundMetal2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",0.5,1,80};
		soundMetal3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",0.5,1,80};
		soundMetal4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",0.5,1,80};
		soundMetal5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",0.5,1,80};
		soundMetal6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",0.5,1,80};
		soundMetal7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",0.5,1,80};
		soundMetal8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",0.5,1,80};
		soundHitGlass1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_01",0.5,1,100};
		soundHitGlass2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_02",0.5,1,100};
		soundHitGlass3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_03",0.5,1,100};
		soundHitGlass4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_04",0.5,1,100};
		soundHitGlass5[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_05",0.5,1,100};
		soundHitGlass6[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_06",0.5,1,100};
		soundGlassArmored1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_01",0.5,1,60};
		soundGlassArmored2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_02",0.5,1,60};
		soundGlassArmored3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_03",0.5,1,60};
		soundGlassArmored4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_04",0.5,1,60};
		soundGlassArmored5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_05",0.5,1,60};
		soundGlassArmored6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_06",0.5,1,60};
		soundVehiclePlate1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",0.5,1,80};
		soundVehiclePlate2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",0.5,1,80};
		soundVehiclePlate3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",0.5,1,80};
		soundVehiclePlate4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",0.5,1,80};
		soundVehiclePlate5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",0.5,1,80};
		soundVehiclePlate6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",0.5,1,80};
		soundVehiclePlate7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",0.5,1,80};
		soundVehiclePlate8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",0.5,1,80};
		soundWood1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_01",0.5,1,80};
		soundWood2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_02",0.5,1,80};
		soundWood3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_03",0.5,1,80};
		soundWood4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_04",0.5,1,80};
		soundWood5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_05",0.5,1,80};
		soundWood6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_06",0.5,1,80};
		soundWood7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_07",0.5,1,80};
		soundWood8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_08",0.5,1,80};
		soundHitBody1[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_1",0.56234133,1,60};
		soundHitBody2[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_2",0.56234133,1,60};
		soundHitBody3[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_3",0.56234133,1,60};
		soundHitBody4[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_4",0.56234133,1,60};
		soundHitBody5[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_5",0.56234133,1,60};
		soundHitBody6[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_6",0.56234133,1,60};
		soundHitBuilding1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",0.5,1,60};
		soundHitBuilding2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",0.5,1,60};
		soundHitBuilding3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",0.5,1,60};
		soundHitBuilding4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",0.5,1,60};
		soundHitBuilding5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",0.5,1,60};
		soundHitBuilding6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",0.5,1,60};
		soundHitBuilding7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",0.5,1,60};
		soundHitBuilding8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",0.5,1,60};
		soundHitFoliage1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_01",0.5,1,20};
		soundHitFoliage2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_02",0.5,1,20};
		soundHitFoliage3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_03",0.5,1,20};
		soundHitFoliage4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_04",0.5,1,20};
		soundPlastic1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_01",0.5,1,70};
		soundPlastic2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_02",0.5,1,70};
		soundPlastic3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_03",0.5,1,70};
		soundPlastic4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_04",0.5,1,70};
		soundConcrete1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",0.5,1,70};
		soundConcrete2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",0.5,1,70};
		soundConcrete3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",0.5,1,70};
		soundConcrete4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",0.5,1,70};
		soundConcrete5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",0.5,1,70};
		soundConcrete6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",0.5,1,70};
		soundConcrete7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",0.5,1,70};
		soundConcrete8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",0.5,1,70};
		soundRubber1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_01",0.5,1,50};
		soundRubber2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_02",0.5,1,50};
		soundRubber3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_03",0.5,1,50};
		soundRubber4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_04",0.5,1,50};
		soundWater1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_01",0.5,1,40};
		soundWater2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_02",0.5,1,40};
		soundWater3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_03",0.5,1,40};
		hitGroundSoft[] = {"soundGroundSoft1",0.2,"soundGroundSoft2",0.2,"soundGroundSoft3",0.1,"soundGroundSoft4",0.1,"soundGroundSoft5",0.1,"soundGroundSoft6",0.1,"soundGroundSoft7",0.1,"soundGroundSoft8",0.1};
		hitGroundHard[] = {"soundGroundHard1",0.2,"soundGroundHard2",0.2,"soundGroundHard3",0.1,"soundGroundHard4",0.1,"soundGroundHard5",0.1,"soundGroundHard6",0.1,"soundGroundHard7",0.1,"soundGroundHard8",0.1};
		hitMan[] = {"soundHitBody1",0.166,"soundHitBody2",0.166,"soundHitBody3",0.166,"soundHitBody4",0.166,"soundHitBody5",0.166,"soundHitBody6",0.17};
		hitArmor[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitBuilding[] = {"soundHitBuilding1",0.2,"soundHitBuilding2",0.2,"soundHitBuilding3",0.1,"soundHitBuilding4",0.1,"soundHitBuilding5",0.1,"soundHitBuilding6",0.1,"soundHitBuilding7",0.1,"soundHitBuilding8",0.1};
		hitFoliage[] = {"soundHitFoliage1",0.25,"soundHitFoliage2",0.25,"soundHitFoliage3",0.25,"soundHitFoliage4",0.25};
		hitWood[] = {"soundWood1",0.125,"soundWood2",0.125,"soundWood3",0.125,"soundWood4",0.125,"soundWood5",0.125,"soundWood6",0.125,"soundWood7",0.125,"soundWood8",0.125};
		hitGlass[] = {"soundHitGlass1",0.166,"soundHitGlass2",0.166,"soundHitGlass3",0.167,"soundHitGlass4",0.167,"soundHitGlass5",0.167,"soundHitGlass6",0.167};
		hitGlassArmored[] = {"soundGlassArmored1",0.166,"soundGlassArmored2",0.166,"soundGlassArmored3",0.167,"soundGlassArmored4",0.167,"soundGlassArmored5",0.167,"soundGlassArmored6",0.167};
		hitConcrete[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitRubber[] = {"soundRubber1",0.25,"soundRubber2",0.25,"soundRubber3",0.25,"soundRubber4",0.25};
		hitPlastic[] = {"soundPlastic1",0.25,"soundPlastic2",0.25,"soundPlastic3",0.25,"soundPlastic4",0.25};
		hitDefault[] = {"soundDefault1",0.166,"soundDefault2",0.166,"soundDefault3",0.166,"soundDefault4",0.166,"soundDefault5",0.166,"soundDefault6",0.17};
		hitMetal[] = {"soundMetal1",0.125,"soundMetal2",0.125,"soundMetal3",0.125,"soundMetal4",0.125,"soundMetal5",0.125,"soundMetal6",0.125,"soundMetal7",0.125,"soundMetal8",0.125};
		hitMetalplate[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitWater[] = {"soundWater1",0.333,"soundWater2",0.333,"soundWater3",0.333};
	};
	class SG_FriendlyInfectedSequel1: MeleeDamage
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.0;
			class Health
			{
				damage = 1;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
			additionAnimalMeleeMultiplier = 2;
		};
		soundDefault1[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_1",0.56234133,1,60};
		soundDefault2[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_2",0.56234133,1,60};
		soundDefault3[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_3",0.56234133,1,60};
		soundDefault4[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_4",0.56234133,1,60};
		soundDefault5[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_5",0.56234133,1,60};
		soundDefault6[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_6",0.56234133,1,60};
		soundGroundSoft1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_01",0.5,1,60};
		soundGroundSoft2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_02",0.5,1,60};
		soundGroundSoft3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_03",0.5,1,60};
		soundGroundSoft4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_04",0.5,1,60};
		soundGroundSoft5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_05",0.5,1,60};
		soundGroundSoft6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_06",0.5,1,60};
		soundGroundSoft7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_07",0.5,1,60};
		soundGroundSoft8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_08",0.5,1,60};
		soundGroundHard1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_01",0.5,1,80};
		soundGroundHard2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_02",0.5,1,80};
		soundGroundHard3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_03",0.5,1,80};
		soundGroundHard4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_04",0.5,1,80};
		soundGroundHard5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_05",0.5,1,80};
		soundGroundHard6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_06",0.5,1,80};
		soundGroundHard7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_07",0.5,1,80};
		soundGroundHard8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_08",0.5,1,80};
		soundMetal1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",0.5,1,80};
		soundMetal2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",0.5,1,80};
		soundMetal3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",0.5,1,80};
		soundMetal4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",0.5,1,80};
		soundMetal5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",0.5,1,80};
		soundMetal6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",0.5,1,80};
		soundMetal7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",0.5,1,80};
		soundMetal8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",0.5,1,80};
		soundHitGlass1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_01",0.5,1,100};
		soundHitGlass2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_02",0.5,1,100};
		soundHitGlass3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_03",0.5,1,100};
		soundHitGlass4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_04",0.5,1,100};
		soundHitGlass5[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_05",0.5,1,100};
		soundHitGlass6[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_06",0.5,1,100};
		soundGlassArmored1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_01",0.5,1,60};
		soundGlassArmored2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_02",0.5,1,60};
		soundGlassArmored3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_03",0.5,1,60};
		soundGlassArmored4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_04",0.5,1,60};
		soundGlassArmored5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_05",0.5,1,60};
		soundGlassArmored6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_06",0.5,1,60};
		soundVehiclePlate1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",0.5,1,80};
		soundVehiclePlate2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",0.5,1,80};
		soundVehiclePlate3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",0.5,1,80};
		soundVehiclePlate4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",0.5,1,80};
		soundVehiclePlate5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",0.5,1,80};
		soundVehiclePlate6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",0.5,1,80};
		soundVehiclePlate7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",0.5,1,80};
		soundVehiclePlate8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",0.5,1,80};
		soundWood1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_01",0.5,1,80};
		soundWood2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_02",0.5,1,80};
		soundWood3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_03",0.5,1,80};
		soundWood4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_04",0.5,1,80};
		soundWood5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_05",0.5,1,80};
		soundWood6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_06",0.5,1,80};
		soundWood7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_07",0.5,1,80};
		soundWood8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_08",0.5,1,80};
		soundHitBody1[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_1",0.56234133,1,60};
		soundHitBody2[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_2",0.56234133,1,60};
		soundHitBody3[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_3",0.56234133,1,60};
		soundHitBody4[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_4",0.56234133,1,60};
		soundHitBody5[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_5",0.56234133,1,60};
		soundHitBody6[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_6",0.56234133,1,60};
		soundHitBuilding1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",0.5,1,60};
		soundHitBuilding2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",0.5,1,60};
		soundHitBuilding3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",0.5,1,60};
		soundHitBuilding4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",0.5,1,60};
		soundHitBuilding5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",0.5,1,60};
		soundHitBuilding6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",0.5,1,60};
		soundHitBuilding7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",0.5,1,60};
		soundHitBuilding8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",0.5,1,60};
		soundHitFoliage1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_01",0.5,1,20};
		soundHitFoliage2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_02",0.5,1,20};
		soundHitFoliage3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_03",0.5,1,20};
		soundHitFoliage4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_04",0.5,1,20};
		soundPlastic1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_01",0.5,1,70};
		soundPlastic2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_02",0.5,1,70};
		soundPlastic3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_03",0.5,1,70};
		soundPlastic4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_04",0.5,1,70};
		soundConcrete1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",0.5,1,70};
		soundConcrete2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",0.5,1,70};
		soundConcrete3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",0.5,1,70};
		soundConcrete4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",0.5,1,70};
		soundConcrete5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",0.5,1,70};
		soundConcrete6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",0.5,1,70};
		soundConcrete7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",0.5,1,70};
		soundConcrete8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",0.5,1,70};
		soundRubber1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_01",0.5,1,50};
		soundRubber2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_02",0.5,1,50};
		soundRubber3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_03",0.5,1,50};
		soundRubber4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_04",0.5,1,50};
		soundWater1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_01",0.5,1,40};
		soundWater2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_02",0.5,1,40};
		soundWater3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_03",0.5,1,40};
		hitGroundSoft[] = {"soundGroundSoft1",0.2,"soundGroundSoft2",0.2,"soundGroundSoft3",0.1,"soundGroundSoft4",0.1,"soundGroundSoft5",0.1,"soundGroundSoft6",0.1,"soundGroundSoft7",0.1,"soundGroundSoft8",0.1};
		hitGroundHard[] = {"soundGroundHard1",0.2,"soundGroundHard2",0.2,"soundGroundHard3",0.1,"soundGroundHard4",0.1,"soundGroundHard5",0.1,"soundGroundHard6",0.1,"soundGroundHard7",0.1,"soundGroundHard8",0.1};
		hitMan[] = {"soundHitBody1",0.166,"soundHitBody2",0.166,"soundHitBody3",0.166,"soundHitBody4",0.166,"soundHitBody5",0.166,"soundHitBody6",0.17};
		hitArmor[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitBuilding[] = {"soundHitBuilding1",0.2,"soundHitBuilding2",0.2,"soundHitBuilding3",0.1,"soundHitBuilding4",0.1,"soundHitBuilding5",0.1,"soundHitBuilding6",0.1,"soundHitBuilding7",0.1,"soundHitBuilding8",0.1};
		hitFoliage[] = {"soundHitFoliage1",0.25,"soundHitFoliage2",0.25,"soundHitFoliage3",0.25,"soundHitFoliage4",0.25};
		hitWood[] = {"soundWood1",0.125,"soundWood2",0.125,"soundWood3",0.125,"soundWood4",0.125,"soundWood5",0.125,"soundWood6",0.125,"soundWood7",0.125,"soundWood8",0.125};
		hitGlass[] = {"soundHitGlass1",0.166,"soundHitGlass2",0.166,"soundHitGlass3",0.167,"soundHitGlass4",0.167,"soundHitGlass5",0.167,"soundHitGlass6",0.167};
		hitGlassArmored[] = {"soundGlassArmored1",0.166,"soundGlassArmored2",0.166,"soundGlassArmored3",0.167,"soundGlassArmored4",0.167,"soundGlassArmored5",0.167,"soundGlassArmored6",0.167};
		hitConcrete[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitRubber[] = {"soundRubber1",0.25,"soundRubber2",0.25,"soundRubber3",0.25,"soundRubber4",0.25};
		hitPlastic[] = {"soundPlastic1",0.25,"soundPlastic2",0.25,"soundPlastic3",0.25,"soundPlastic4",0.25};
		hitDefault[] = {"soundDefault1",0.166,"soundDefault2",0.166,"soundDefault3",0.166,"soundDefault4",0.166,"soundDefault5",0.166,"soundDefault6",0.17};
		hitMetal[] = {"soundMetal1",0.125,"soundMetal2",0.125,"soundMetal3",0.125,"soundMetal4",0.125,"soundMetal5",0.125,"soundMetal6",0.125,"soundMetal7",0.125,"soundMetal8",0.125};
		hitMetalplate[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitWater[] = {"soundWater1",0.333,"soundWater2",0.333,"soundWater3",0.333};
		hitAnimation = 2;
	};
	class SG_FriendlyInfectedSequel2: MeleeDamage
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.0;
			class Health
			{
				damage = 1;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
			additionAnimalMeleeMultiplier = 2;
		};
		soundDefault1[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_1",0.56234133,1,60};
		soundDefault2[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_2",0.56234133,1,60};
		soundDefault3[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_3",0.56234133,1,60};
		soundDefault4[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_4",0.56234133,1,60};
		soundDefault5[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_5",0.56234133,1,60};
		soundDefault6[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_6",0.56234133,1,60};
		soundGroundSoft1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_01",0.5,1,60};
		soundGroundSoft2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_02",0.5,1,60};
		soundGroundSoft3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_03",0.5,1,60};
		soundGroundSoft4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_04",0.5,1,60};
		soundGroundSoft5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_05",0.5,1,60};
		soundGroundSoft6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_06",0.5,1,60};
		soundGroundSoft7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_07",0.5,1,60};
		soundGroundSoft8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_08",0.5,1,60};
		soundGroundHard1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_01",0.5,1,80};
		soundGroundHard2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_02",0.5,1,80};
		soundGroundHard3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_03",0.5,1,80};
		soundGroundHard4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_04",0.5,1,80};
		soundGroundHard5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_05",0.5,1,80};
		soundGroundHard6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_06",0.5,1,80};
		soundGroundHard7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_07",0.5,1,80};
		soundGroundHard8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_08",0.5,1,80};
		soundMetal1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",0.5,1,80};
		soundMetal2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",0.5,1,80};
		soundMetal3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",0.5,1,80};
		soundMetal4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",0.5,1,80};
		soundMetal5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",0.5,1,80};
		soundMetal6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",0.5,1,80};
		soundMetal7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",0.5,1,80};
		soundMetal8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",0.5,1,80};
		soundHitGlass1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_01",0.5,1,100};
		soundHitGlass2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_02",0.5,1,100};
		soundHitGlass3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_03",0.5,1,100};
		soundHitGlass4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_04",0.5,1,100};
		soundHitGlass5[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_05",0.5,1,100};
		soundHitGlass6[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_06",0.5,1,100};
		soundGlassArmored1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_01",0.5,1,60};
		soundGlassArmored2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_02",0.5,1,60};
		soundGlassArmored3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_03",0.5,1,60};
		soundGlassArmored4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_04",0.5,1,60};
		soundGlassArmored5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_05",0.5,1,60};
		soundGlassArmored6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_06",0.5,1,60};
		soundVehiclePlate1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",0.5,1,80};
		soundVehiclePlate2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",0.5,1,80};
		soundVehiclePlate3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",0.5,1,80};
		soundVehiclePlate4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",0.5,1,80};
		soundVehiclePlate5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",0.5,1,80};
		soundVehiclePlate6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",0.5,1,80};
		soundVehiclePlate7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",0.5,1,80};
		soundVehiclePlate8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",0.5,1,80};
		soundWood1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_01",0.5,1,80};
		soundWood2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_02",0.5,1,80};
		soundWood3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_03",0.5,1,80};
		soundWood4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_04",0.5,1,80};
		soundWood5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_05",0.5,1,80};
		soundWood6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_06",0.5,1,80};
		soundWood7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_07",0.5,1,80};
		soundWood8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_08",0.5,1,80};
		soundHitBody1[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_1",0.56234133,1,60};
		soundHitBody2[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_2",0.56234133,1,60};
		soundHitBody3[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_3",0.56234133,1,60};
		soundHitBody4[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_4",0.56234133,1,60};
		soundHitBody5[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_5",0.56234133,1,60};
		soundHitBody6[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_6",0.56234133,1,60};
		soundHitBuilding1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",0.5,1,60};
		soundHitBuilding2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",0.5,1,60};
		soundHitBuilding3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",0.5,1,60};
		soundHitBuilding4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",0.5,1,60};
		soundHitBuilding5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",0.5,1,60};
		soundHitBuilding6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",0.5,1,60};
		soundHitBuilding7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",0.5,1,60};
		soundHitBuilding8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",0.5,1,60};
		soundHitFoliage1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_01",0.5,1,20};
		soundHitFoliage2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_02",0.5,1,20};
		soundHitFoliage3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_03",0.5,1,20};
		soundHitFoliage4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_04",0.5,1,20};
		soundPlastic1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_01",0.5,1,70};
		soundPlastic2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_02",0.5,1,70};
		soundPlastic3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_03",0.5,1,70};
		soundPlastic4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_04",0.5,1,70};
		soundConcrete1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",0.5,1,70};
		soundConcrete2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",0.5,1,70};
		soundConcrete3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",0.5,1,70};
		soundConcrete4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",0.5,1,70};
		soundConcrete5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",0.5,1,70};
		soundConcrete6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",0.5,1,70};
		soundConcrete7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",0.5,1,70};
		soundConcrete8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",0.5,1,70};
		soundRubber1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_01",0.5,1,50};
		soundRubber2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_02",0.5,1,50};
		soundRubber3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_03",0.5,1,50};
		soundRubber4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_04",0.5,1,50};
		soundWater1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_01",0.5,1,40};
		soundWater2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_02",0.5,1,40};
		soundWater3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_03",0.5,1,40};
		hitGroundSoft[] = {"soundGroundSoft1",0.2,"soundGroundSoft2",0.2,"soundGroundSoft3",0.1,"soundGroundSoft4",0.1,"soundGroundSoft5",0.1,"soundGroundSoft6",0.1,"soundGroundSoft7",0.1,"soundGroundSoft8",0.1};
		hitGroundHard[] = {"soundGroundHard1",0.2,"soundGroundHard2",0.2,"soundGroundHard3",0.1,"soundGroundHard4",0.1,"soundGroundHard5",0.1,"soundGroundHard6",0.1,"soundGroundHard7",0.1,"soundGroundHard8",0.1};
		hitMan[] = {"soundHitBody1",0.166,"soundHitBody2",0.166,"soundHitBody3",0.166,"soundHitBody4",0.166,"soundHitBody5",0.166,"soundHitBody6",0.17};
		hitArmor[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitBuilding[] = {"soundHitBuilding1",0.2,"soundHitBuilding2",0.2,"soundHitBuilding3",0.1,"soundHitBuilding4",0.1,"soundHitBuilding5",0.1,"soundHitBuilding6",0.1,"soundHitBuilding7",0.1,"soundHitBuilding8",0.1};
		hitFoliage[] = {"soundHitFoliage1",0.25,"soundHitFoliage2",0.25,"soundHitFoliage3",0.25,"soundHitFoliage4",0.25};
		hitWood[] = {"soundWood1",0.125,"soundWood2",0.125,"soundWood3",0.125,"soundWood4",0.125,"soundWood5",0.125,"soundWood6",0.125,"soundWood7",0.125,"soundWood8",0.125};
		hitGlass[] = {"soundHitGlass1",0.166,"soundHitGlass2",0.166,"soundHitGlass3",0.167,"soundHitGlass4",0.167,"soundHitGlass5",0.167,"soundHitGlass6",0.167};
		hitGlassArmored[] = {"soundGlassArmored1",0.166,"soundGlassArmored2",0.166,"soundGlassArmored3",0.167,"soundGlassArmored4",0.167,"soundGlassArmored5",0.167,"soundGlassArmored6",0.167};
		hitConcrete[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitRubber[] = {"soundRubber1",0.25,"soundRubber2",0.25,"soundRubber3",0.25,"soundRubber4",0.25};
		hitPlastic[] = {"soundPlastic1",0.25,"soundPlastic2",0.25,"soundPlastic3",0.25,"soundPlastic4",0.25};
		hitDefault[] = {"soundDefault1",0.166,"soundDefault2",0.166,"soundDefault3",0.166,"soundDefault4",0.166,"soundDefault5",0.166,"soundDefault6",0.17};
		hitMetal[] = {"soundMetal1",0.125,"soundMetal2",0.125,"soundMetal3",0.125,"soundMetal4",0.125,"soundMetal5",0.125,"soundMetal6",0.125,"soundMetal7",0.125,"soundMetal8",0.125};
		hitMetalplate[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitWater[] = {"soundWater1",0.333,"soundWater2",0.333,"soundWater3",0.333};
		hitAnimation = 3;
	};
	class MeleeKnife: MeleeDamage
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 0.25;
		};
	};
	class MeleeKnife_Heavy: MeleeKnife
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 1;
		};
	};
	class MeleeMachete: MeleeDamage
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 0.25;
		};
	};
	class MeleeMachete_Heavy: MeleeMachete
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 1;
		};
	};
	class MeleeHatchet: MeleeDamage
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 0.25;
		};
	};
	class MeleeHatchet_Heavy: MeleeHatchet
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 1;
		};
	};
	class MeleeFireAxe: MeleeDamage
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 2;
		};
	};
	class MeleeFireAxe_Heavy: MeleeDamage
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 4;
		};
	};
	class MeleeBat: MeleeDamage
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 2;
		};
	};
	class MeleeBat_Heavy: MeleeBat
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 4;
		};
	};
	class MeleeWrench: MeleeDamage
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 2;
		};
	};
	class MeleeWrench_Heavy: MeleeWrench
	{
		class DamageApplied
		{
			additionAnimalMeleeMultiplier = 4;
		};
	};
	class FirearmHit_Pistol: MeleeDamage
	{
		class DamageApplied
		{
			class Health
			{
				damage = 5;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
			additionAnimalMeleeMultiplier = 1;
		};
	};
	class FirearmHit_Rifle: MeleeDamage
	{
		class DamageApplied
		{
			class Health
			{
				damage = 5;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
			additionAnimalMeleeMultiplier = 1;
		};
	};
	class FirearmHit_Rifle_Buttstock: FirearmHit_Rifle
	{
		class DamageApplied
		{
			class Health
			{
				damage = 5;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
			additionAnimalMeleeMultiplier = 1;
		};
	};
	class FirearmHit_Rifle_Bayonet: FirearmHit_Rifle
	{
		class DamageApplied
		{
			class Health
			{
				damage = 5;
			};
			class Blood
			{
				damage = 0;
			};
			class Shock
			{
				damage = 0;
			};
			additionAnimalMeleeMultiplier = 1;
		};
	};
	class Shotgun_Base;
	class Bullet_12GaugePellets: Shotgun_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_12GaugeSlug: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_556x45: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_545x39: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_762x54: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_308Win: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_762x39: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_45ACP: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_357: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_9x19: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_380: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_22: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
	class Bullet_9x39: Bullet_Base
	{
		class NoiseHit
		{
			strength = 4;
			type = "sound";
		};
	};
};
