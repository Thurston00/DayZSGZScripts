////////////////////////////////////////////////////////////////////
//DeRap: sg_data\config.bin
//Produced from mikero's Dos Tools Dll version 7.16
//https://armaservices.maverick-applications.com/Products/MikerosDosTools/default
//'now' is Tue Jul 23 06:59:53 2019 : 'file' last modified on Tue Jul 16 10:38:55 2019
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class SG_Data
	{
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgMods
{
	class mod_sg
	{
		dir = "sg";
		picture = "DZ\ui\data\logos\dayz_ca";
		action = "http://www.test-mod.com";
		hideName = 1;
		hidePicture = 1;
		name = "Mod Survivor GameZ";
		skeletonDefinitions = "SG\creatures\skeletons.anim.xml";
		credits = "BIS_fnc_credits_H";
		author = "Bohemia Interactive";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game"};
		class defs
		{
			class imageSets
			{
				files[] = {"mod_sg/gui/imagesets/sgz_new_ui/sgz_ui.imageset","mod_sg/gui/imagesets/sg_caster_item_icons.imageset","mod_sg/gui/imagesets/playground_thumbnails.imageset","mod_sg/gui/imagesets/sg_gui.imageset","mod_sg/gui/imagesets/sg_ui_icons.imageset","mod_sg/gui/imagesets/sgz_new_ui/sgz_hud.imageset","mod_sg/gui/imagesets/sgz_editor/sg_editor.imageset","mod_sg/gui/imagesets/sgz_new_ui/sgz_ui_menu_atlas.imageset"};
			};
			class widgetStyles
			{
				files[] = {"mod_sg/gui/looknfeel/sgzwidgets.styles"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"mod_sg/SgScripts/3_SgGame"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"mod_sg/SgScripts/4_SgWorld"};
			};
			class missionScriptModule
			{
				value = "SgCreateMission";
				files[] = {"mod_sg/SgScripts/5_SgMission"};
			};
		};
	};
};
class CfgSlots
{
	class Slot_Collar
	{
		name = "Collar";
		displayName = "Collar";
		ghostIcon = "headgear";
	};
};
