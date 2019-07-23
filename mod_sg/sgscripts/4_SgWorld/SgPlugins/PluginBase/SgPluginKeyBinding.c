modded class PluginKeyBinding
{
#ifdef DEVELOPER
	override void OnInit()
	{
		super.OnInit();
		
		// SG Editors
		string editor;
		if ( !GetGame().CommandlineGetParam("sgEditor", editor))
		{
			return;
		}
		
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Keyboard Binds	|UI_ID							|Key1					|Key2					|Callback Plugin		|Callback Function				|Info Shrtcut				|Info Description
		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//					|constants.h					|constants.h			|constants.h			|only plugin name		|only function					|							|
		//					|MENU_***						|DIK_***				|KeyCode.***			|						|in plugin						|							|
		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//RegisterKeyBind(	 MENU_NONE|MENU_SG_SERVER_INFO	,KeyCode.KC_I			,-1						,"SgPluginGameClient"	,"ToggleGUIServerInfo" 			,"[I]"						,"Open server informations. Players ping...");
		//RegisterKeyBind(	 MENU_NONE						,KeyCode.KC_BACK		,-1						,"SgPluginCasterManager","CasterPlayerCamDisable" 		,"[Esc]"					,"Exit player follow camera"				);
		RegisterKeyBind(	 MENU_NONE						,KeyCode.KC_LCONTROL	,KeyCode.KC_T			,"SgTestingPlugin"		,"TestFunction" 				,"[Esc]"					,"Exit player follow camera"				);
		RegisterKeyBind(	 MENU_NONE						,KeyCode.KC_LCONTROL	,KeyCode.KC_4			,"SgTestingPlugin"		,"SaveStaticCamera0" 			,"[LCtrl]+[4]"				,"Save static camera 0"						);
		RegisterKeyBind(	 MENU_NONE						,KeyCode.KC_LCONTROL	,KeyCode.KC_5			,"SgTestingPlugin"		,"SaveStaticCamera1" 			,"[LCtrl]+[5]"				,"Save static camera 1"						);
		RegisterKeyBind(	 MENU_NONE						,KeyCode.KC_LCONTROL	,KeyCode.KC_6			,"SgTestingPlugin"		,"SaveStaticCamera2" 			,"[LCtrl]+[6]"				,"Save static camera 2"						);
		RegisterKeyBind(	 MENU_NONE						,KeyCode.KC_4  			,-1						,"SgTestingPlugin"		,"LoadStaticCamera0" 			,"[4]"						,"Load static camera 0"						);
		RegisterKeyBind(	 MENU_NONE						,KeyCode.KC_5  			,-1						,"SgTestingPlugin"		,"LoadStaticCamera1" 			,"[5]"						,"Load static camera 1"						);
		RegisterKeyBind(	 MENU_NONE						,KeyCode.KC_6  			,-1						,"SgTestingPlugin"		,"LoadStaticCamera2" 			,"[6]"						,"Load static camera 2"						);
		RegisterKeyBind(	 MENU_NONE|MENU_SG_PG_EDITOR	,KeyCode.KC_LCONTROL	,KeyCode.KC_Z			,"SgPluginPgEditor"		,"EditorToggle"					,"[LWin]+[TAB]"				,"Show/Hide Scripted Scene Editor"			);
		RegisterKeyBind(	 MENU_SG_PG_EDITOR				,KeyCode.KC_LCONTROL	,KeyCode.KC_S			,"SgPluginPgEditor"		,"SaveCurrentPlayground"		,"[LCtrl]+[Z]"				,"Playgrounds Editor => Save Current Scene"	);

		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Mouses Binds		|UI_ID							|Mouse Button			|Mouse Event			|Callback Plugin		|Callback Function			|Info Shrtcut			|Info Description
		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------
		//					|constants.h					|MB_LEFT				|MB_EVENT_CLICK			|only plugin name		|only function				|						|
		//					|MENU_***						|MB_RIGHT				|MB_EVENT_DOUBLECLICK   |						|in plugin					|						|
		//					|								|MB_MIDDLE				|MB_EVENT_DRAG			|						|							|						|
		//					|								|						|MB_EVENT_RELEASE		|						|							|						|
		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		RegisterMouseBind( 	MENU_NONE|MENU_SG_PG_EDITOR		,MouseState.RIGHT		,MB_EVENT_RELEASE		,"SgPluginPgEditor"		,"Event_OnRClickRelease"	,"[RMB] Release"		,"Object Spawns Editor => Disable camera movement"	);
		RegisterMouseBind( 	MENU_NONE|MENU_SG_PG_EDITOR		,MouseState.LEFT		,MB_EVENT_CLICK			,"SgPluginEditorLoot"	,"Event_OnClick"			,"[LMB] Click"			,"Mission Editor => Select object in scene"			);
		RegisterMouseBind( 	MENU_NONE|MENU_SG_PG_EDITOR		,MouseState.RIGHT		,MB_EVENT_PRESS			,"SgPluginEditorLoot"	,"Event_OnRClick"			,"[RMB] Hold"			,"Object Spawns Editor => Enable camera movement"	);
		RegisterMouseBind( 	MENU_NONE|MENU_SG_PG_EDITOR		,MouseState.LEFT		,MB_EVENT_PRESS			,"SgPluginEditorLoot"	,"Event_OnClick"			,"[LMB] Hold"			,"Object Spawns Editor => Click"					);
		RegisterMouseBind( 	MENU_NONE|MENU_SG_PG_EDITOR		,MouseState.LEFT		,MB_EVENT_DRAG			,"SgPluginEditorLoot"	,"Event_OnDrag"				,"[LMB] Hold"			,"Object Spawns Editor => Speed-up gizmo controls"	);
		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
#endif
}
