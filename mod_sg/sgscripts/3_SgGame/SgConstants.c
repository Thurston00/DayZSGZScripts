const int RPC_CLIENT_LOADED				= 9900;
const int RPC_RETURN_ACCESS				= 9901;
const int RPC_SG_HUD_COMMAND			= 9902;
const int RPC_SG_GAME_COMMAND			= 9903;
const int RPC_SG_SERVER_COMMAND			= 9904;
const int RPC_SG_GAME_LOG				= 9905;
const int RPC_SG_PLAYER_MOVE_LOCK		= 9906;
const int RPC_SG_PLAYER_MOVE_UNLOCK		= 9907;
const int RPC_SG_PLAYER_VIEW_LOCK		= 9909;
const int RPC_SG_PLAYER_VIEW_UNLOCK		= 9910;
const int CALL_ID_SG_RPC_CALL			= 100;
//const int MENU_SG_CONSOLE	      		= 536870912;
//const int MENU_SG_SERVER_INFO     	= 1073741824;
const int MENU_SG_PG_EDITOR				= 1 << 32;
const int MENU_SG_MAIN_MENU				= 1 << 33;
const int MENU_SG_CHARACTER				= 51;
const int MENU_SG_GAME_MODE				= 52;
const int MENU_SG_RESULT_SCREEN			= 53;

//const for PlayerStats
const int SG_WEIGHT_CAPACITY			= 27000;
const int SG_STOMACH_CAPACITY			= 2000;
const int SG_STOMACH_VOMIT_THRESHOLD 	= 2000;
const int SG_FATALLY_STUFFED_TRESHOLD	= 2000;
const float SG_MIN_OPTIMAL_HEAL_RANGE 	= 50;
const float SG_MAX_OPTIMAL_HEAL_RANGE 	= 75;
const float SG_BLOOD_FATAL_TRESHOLD 	= 50;

//const for Player stamina
const float SG_STAMINA_MAX 							= 200;
const float SG_STAMINA_REGENERATION_MULTIPLICATOR 	= 1.5;

//const for Playground
const int SG_TIME_WARM_UP_DURATION						= 120000;
const int SG_TIME_IN_PHASE_TO_SHOW_POI_EFFECT 			= 120;
const int SG_TIME_IN_TRANSITION_TO_REMOVE_POI_EFFECT 	= 120;

const string SG_UID_PLACEHOLDER						= "SG_UID_PLACEHOLDER";

// Commands using user action sync
const int INPUT_UDT_CONTINUOUS_LOAD_MAGAZINE_CANCEL	= 100;

/**
* \ input exclude types
*/
const int INPUT_EXCLUDE_MOVEMENT = 4;