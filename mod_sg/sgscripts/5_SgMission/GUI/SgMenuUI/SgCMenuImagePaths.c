class SgCMenuWidgetPaths
{
	// Imagesets
	private static const string IMAGESET_UI 		= "sgz_ui";
	private static const string IMAGESET_ICONS		= "sg_ui_icons";
	private static const string IMAGESET_GUI		= "sg_gui";
	private static const string IMAGESET_HUD		= "sgz_hud";
	private static const string IMAGESET_MENU		= "sgz_ui_menu";
	private static const string IMAGESET_DAYZ_GUI	= "dayz_gui";
	// ???
	static const string WHITE_PIXEL		 			= string.Format("set:%1 image:%2", IMAGESET_UI, 	"white_pixel");
	// Checkboxes
	static const string CHECKBOX_UNCHECKED_IMAGE 	= string.Format("set:%1 image:%2", IMAGESET_UI, 	"checkbox_unchecked");
	static const string CHECKBOX_CHECKED_IMAGE 		= string.Format("set:%1 image:%2", IMAGESET_UI, 	"checkbox_checked");
	// Radiobutton
	static const string RADIOBUTTON_UNCHECKED_IMAGE = string.Format("set:%1 image:%2", IMAGESET_UI, 	"radio_unchecked");
	static const string RADIOBUTTON_CHECKED_IMAGE 	= string.Format("set:%1 image:%2", IMAGESET_UI, 	"radio_checked");
	// Refresh
	static const string REFRESH_ICON				= string.Format("set:%1 image:%2", IMAGESET_ICONS, 		"Refresh");
	// Arrows	
	static const string ARROW_UP					= string.Format("set:%1 image:%2", IMAGESET_ICONS, 		"UpArrow");
	static const string ARROW_DOWN					= string.Format("set:%1 image:%2", IMAGESET_ICONS, 		"DownArrow");
	static const string ARROW_RIGHT					= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"arrow_right");
	static const string ARROW_LEFT					= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"arrow_left");
	// Tick Icon
	static const string TICK_ICON					= string.Format("set:%1 image:%2", IMAGESET_UI, 		"tick" );
	static const string HOST_ICON					= string.Format("set:%1 image:%2", IMAGESET_UI,			"host" );
	static const string CIRCLE_ICON					= string.Format("set:%1 image:%2", IMAGESET_UI, 		"ready_state" );
	// HUD -> Zone Icons
	static const string PHASE_ZONE_ICON				= string.Format("set:%1 image:%2", IMAGESET_HUD, 		"zone_phase" );
	static const string PHASE_TRANSITION_ICON		= string.Format("set:%1 image:%2", IMAGESET_HUD,		"zone_transition" );
	static const string PHASE_END_ICON				= string.Format("set:%1 image:%2", IMAGESET_HUD, 		"zone_final" );
	// HUD -> Bleeding Icons
	static const string BLOOD_SINGLE_ICON			= string.Format("set:%1 image:%2", IMAGESET_HUD,		"blood_single" );
	static const string BLOOD_DOUBLE_ICON			= string.Format("set:%1 image:%2", IMAGESET_HUD,		"blood_double" );
	static const string BLOOD_TRIPLE_ICON			= string.Format("set:%1 image:%2", IMAGESET_HUD, 		"blood_triple" );
	// HUD -> Teammate status Icons
	static const string TEAMMATE_DEAD_ICON			= string.Format("set:%1 image:%2", IMAGESET_HUD, 		"teammate_dead" );
	static const string TEAMMATE_DISCONNECTED_ICON	= string.Format("set:%1 image:%2", IMAGESET_HUD,		"teammate_disconnected" );
	static const string TEAMMATE_UNCONSCIOUS_ICON	= string.Format("set:%1 image:%2", IMAGESET_HUD, 		"teammate_unconscious" );
	// HUD -> Teammate hud tracker
	static const string TEAMMATE_TRACKER_ICON		= string.Format("set:%1 image:%2", IMAGESET_HUD, 		"tracker" );
	// HUD -> Teammate compass tracker
	static const string COMPASS_TEAMMATE_ICON		= string.Format("set:%1 image:%2", IMAGESET_HUD, 		"compass_teammate" );
	// HUD -> Stance Icons
	static const string STANCE_PRONE_ICON			= string.Format("set:%1 image:%2", IMAGESET_HUD, 		"stance_prone" );
	static const string STANCE_CROUCH_ICON			= string.Format("set:%1 image:%2", IMAGESET_HUD, 		"stance_crouch" );
	static const string STANCE_STANCE_ICON			= string.Format("set:%1 image:%2", IMAGESET_HUD, 		"stance_stand" );
	// HUD -> Sound Icons
	static const string SOUND_LVL_0					= string.Format("set:%1 image:%2", IMAGESET_DAYZ_GUI, 	"Presence0" );
	static const string SOUND_LVL_1					= string.Format("set:%1 image:%2", IMAGESET_DAYZ_GUI, 	"Presence1" );
	static const string SOUND_LVL_2					= string.Format("set:%1 image:%2", IMAGESET_DAYZ_GUI, 	"Presence2" );
	static const string SOUND_LVL_3					= string.Format("set:%1 image:%2", IMAGESET_DAYZ_GUI, 	"Presence3" );
	static const string SOUND_LVL_4					= string.Format("set:%1 image:%2", IMAGESET_DAYZ_GUI, 	"Presence4" );
	// SWITCH -> switch icon
	static const string SWITCH_LEFT					= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"slider_left" );;
	static const string SWITCH_RIGHT				= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"slider_right" );;
	// MENU -> Header
	static const string EXIT_CROSS_ICON				= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"button_exit" );
	static const string SETTINGS_ICON				= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"button_settings" );
	static const string CANCEL_ICON					= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"button_cancel" );

	// PREFAB -> Buttons
	static const string BUTTON_ACTION_HIGH_HOVER	= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"button_action_high_hover" );
	// PREFAB -> Switch - Region 
	static const string SWITCH_REGION_EU			= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"slider_region_eu" );
	static const string SWITCH_REGION_US			= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"slider_region_us" );
	// MENU -> Hind navigation 
	static const string HINT_NAVIGATION_NORMAL		= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"button_navigation_normal" );
	static const string HINT_NAVIGATION_SELECTED	= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"button_navigation_selected" );
	// Logos
	static const string LOGO_SIMPLE					= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"logo" );
	static const string LOGO_FULL					= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"logo_full" );
	// Icons	
	static const string ICON_ALERT					= string.Format("set:%1 image:%2", IMAGESET_MENU, 		"icon_alert" );
	
}

