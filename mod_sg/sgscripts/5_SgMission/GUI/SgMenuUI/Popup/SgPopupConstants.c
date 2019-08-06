enum SgEPopupButtonType
{
	PRIMARY,
	SECONDARY
}

enum SgEPopupType
{
	INPUT,
	OUTPUT
}

class SgCPopupDescTexts			
{
	static const string EMPTY 						= "";
	static const string LEAVE_LOBBY 				= "#sg_popup_content_leave_lobby";
	static const string LOBBY_DESTROY 				= "#sg_popup_content_destroy_lobby";
	static const string EXIT_GAME					= "#sg_popup_content_exit_game";
	static const string LEAVE_MATCH 				= "#sg_popup_content_leave_match";
	static const string W_WRONG_PASSWORD  			= "#sg_popup_content_wrong_password";
	static const string W_MISS_LOBBY_NAME			= "#sg_popup_content_lobby_name_empty";
	static const string E_LOBBY_DATA_REQUEST_FAILED	= "#sg_popup_content_lobbies_not_loaded";
	static const string E_LOBBY_DATA_NOT_FOUND		= "#sg_popup_content_lobbies_not_found";
	static const string E_SERVICE_CONNECT_FAIL		= "#sg_popup_content_connecting_service_fail";
}

class SgCPopupHeaderTexts	
{
	static const string LEAVE_LOBBY 				= "#sg_popup_header_leave_lobby";
	static const string LOBBY_DESTROY 				= "#sg_popup_header_destroy_lobby";
	static const string EXIT_GAME					= "#sg_popup_header_exit_game";
	static const string LEAVE_MATCH 				= "#sg_popup_header_leave_match";
	static const string ENTER_PASSWORD 				= "#sg_popup_header_enter_password";
	static const string ALERT						= "#sg_popup_header_alert";
	static const string WAIT_FOR_SERVER				= "#sg_popup_header_waiting_for_server";
	static const string WAIT_FOR_RESPONSE			= "#sg_popup_header_waiting_server_response";
	static const string CONNECTING_TO_SERVICES		= "#sg_popup_content_connecting_service";
}

class SgCPopupButtonTexts 		
{
	static const string OK 							= "#sg_menu_buttons_ok_c";
	static const string CANCEL 						= "#sg_menu_buttons_cancel_c";
	static const string DESTROY 					= "#sg_menu_buttons_destroy_c";
	static const string LEAVE 						= "#sg_menu_buttons_leave_c";
	static const string EXIT 						= "#sg_menu_button_exit_c";
	static const string ENTER 						= "#sg_menu_buttons_enter_c";
	static const string RETRY 						= "#sg_menu_buttons_retry_c";
}

class SgCPopupNoteTexts
{
	static const string UP_TO_DATE					= "*Make sure your game is up to date.";
}