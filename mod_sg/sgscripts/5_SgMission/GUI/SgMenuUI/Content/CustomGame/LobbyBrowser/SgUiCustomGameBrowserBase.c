/*
	Ui class for Game browser panel 
*/
class SgUiCustomGameBrowserBase extends SgUiMenuPanel
{	
	private ref 	SgNetworkService 		m_NetService;
	private const 	int 					REFRESH_TIMER	= 30000;
	// Widgets
	private 		Widget 					m_UiLobbyGrid;
	private	 		Widget 					m_UiLobbyMessage;
	private ref 	SgUiButtonRefresh		m_UiRefreshButton;	
	private ref 	SgUiButtonActionMedium	m_UiJoinButton;
	private ref 	SgUiCustomGameBrowserRowHeader m_UiHeader;
	// Custom layouts
	private ref 	array<ref SgUiCustomGameBrowserRow> m_UiLobbyList 	= new array<ref SgUiCustomGameBrowserRow>;
	// Data	
	private ref 	array<ref SgNetDataLobbyInfo> m_LobbyListEntries 	= new array<ref SgNetDataLobbyInfo>;
	private ref		SgNetDataLobbyInfo 		m_SelectedLobbyData;
	// Events	
	private ref 	ScriptInvoker Event_OnEnterLobby 				= new ScriptInvoker();
	private ref 	ScriptInvoker Event_OnSelectLobbyById 			= new ScriptInvoker();
	private ref 	ScriptInvoker Event_OnLobbySelect				= new ScriptInvoker();	
	// Button Events
	private	ref 	ScriptInvoker Event_LobbyRefreshButton_OnClick	= new ScriptInvoker();
	private	ref 	ScriptInvoker Event_LobbyJoinButton_OnClick		= new ScriptInvoker();
	
	// -----------------------------------------
	
	// Constructor
	void SgUiCustomGameBrowserBase(Widget parent_widget)
	{		
		m_NetService = SgNetworkService.GetService();
		
		super.BuildLayout(parent_widget);
		
		RequestLoadLobbyList();
	}	
	// Destructor
	void ~SgUiCustomGameBrowserBase()
	{		
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(RequestLoadLobbyList);
	}
	
	// -----------------------------------------
	// OVERRIDES --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_game_browser_list.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiLobbyGrid 		= FindPanel("ContentGrid");
		m_UiLobbyMessage	= FindLabel("NoResultsLabel");
	}
	override protected void LoadAllWidgets()
	{
		m_UiHeader			= new SgUiCustomGameBrowserRowHeader();
		m_UiHeader.BuildLayout(FindPanel("HeaderFrame"));
		m_UiRefreshButton 	= new SgUiButtonRefresh(FindPanel("RefreshImageFrame"), SgCMenuWidgetPaths.REFRESH_ICON, Event_LobbyRefreshButton_OnClick);
		m_UiJoinButton 		= new SgUiButtonActionMedium(FindPanel("JoinButtonFrame"), SgCMenuButtonStrings.LOBBY_JOIN_C, Event_LobbyJoinButton_OnClick);
		m_UiJoinButton.Enable(false);
	
		RequestLoadLobbyList();
		
		// Refresh Lobby 
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(RequestLoadLobbyList, REFRESH_TIMER, true);
	}
	override protected void RegisterAllEvents()
	{		
		// Lobby selections events
		Event_OnEnterLobby.Insert(EnterSelectedLobby);
		Event_OnLobbySelect.Insert(SetSelectedLobby);		
		// Page Button Events 
		Event_LobbyRefreshButton_OnClick.Insert(RequestLoadLobbyList);
		Event_LobbyJoinButton_OnClick.Insert(EnterSelectedLobby); 
		// Server Events
		if (m_NetService)
		{			
			m_NetService.GetEvent_OnLobbyListLoaded().Insert(OnLobbyListLoaded);
			m_NetService.GetEvent_OnLobbyCreated().Insert(OnLobbyCreated);
		}
		else 
		{
			SgDebug.Error("Could not get Net Service", ClassName(), "RegisterAllEvents" );
		}
	}
	override protected void UnRegisterAllEvents()
	{			
		// Lobby selections events
		Event_OnEnterLobby.Remove(EnterSelectedLobby);
		Event_OnLobbySelect.Remove(SetSelectedLobby);		
		// Page Button Events 
		Event_LobbyRefreshButton_OnClick.Remove(RequestLoadLobbyList);
		Event_LobbyJoinButton_OnClick.Remove(EnterSelectedLobby); 
		// Server Events
		if (m_NetService)
		{		
			m_NetService.GetEvent_OnLobbyListLoaded().Remove(OnLobbyListLoaded);
			m_NetService.GetEvent_OnLobbyCreated().Remove(OnLobbyCreated);
		}
		else 
		{
			SgDebug.Error("Could not get Net Service", ClassName(), "RegisterAllEvents" );
		}
	}
	
	// -----------------------------------------
	// SETTERS
	
	// Setup lobby grid page
	private void SetLobbyGridPage()
	{	
		SetSelectedLobby(null);																		// Reset selected lobby	
		
		if(m_LobbyListEntries.Count())																// IF lobby data list
		{			
			m_UiLobbyList.Clear();																	// -> Clear lobby widget list

			foreach( ref SgNetDataLobbyInfo lobby : m_LobbyListEntries )							// -> For each lobby entry 					
			{																						
				// create lobby data grid row
				m_UiLobbyList.Insert( new SgUiCustomGameBrowserRow(m_UiLobbyGrid, lobby, Event_OnLobbySelect, Event_OnEnterLobby));
			}
			SetGridVisibility(true);																// -> Show grid
		}
		else 																						// ELSE
		{
			SetGridVisibility(false);																// -> Hide grid
		}
	}	
	// Set visibility of grid (show lobby message if lobby grid is hidden)
	private void SetGridVisibility(bool isContentShown)
	{
		m_UiLobbyGrid.Show(isContentShown);															// Hide/Show lobby grid
		m_UiLobbyMessage.Show(!isContentShown);														// Show/Hide empty lobby message
	}
	// Setter for m_SelectedLobbyData
	private void SetSelectedLobby(ref SgNetDataLobbyInfo lobby_data)
	{
		m_SelectedLobbyData = lobby_data;

		// Update join button
		m_UiJoinButton.Enable(m_SelectedLobbyData != null); 	
	}
	
	// ---------------------------------------------
	// Enter lobby methods
	
	// Enter selected lobby 
	private void EnterSelectedLobby()
	{	
		if (m_SelectedLobbyData)
		{
			if (m_SelectedLobbyData.GetPassword())
			{
				EnterLobbyWithPassword();
			}
			else 
			{
				EnterLobbyWithoutPassword();
			}
		}
		else 
		{
			SgDebug.Error("Lobby not selected!", this.ClassName(), "EnterSelectedLobby");
		}
	}
	// Create Lobby-Enter popup with password intut text box
	private void EnterLobbyWithPassword()
	{
		// Create popup
		ScriptInvoker response = SgMenuManager.OpenUserTextInputPopup(SgCPopupHeaderTexts.ENTER_PASSWORD, SgCPopupButtonTexts.ENTER, SgCPopupButtonTexts.CANCEL);
		// Listen to response
		response.Insert(EvaluateEnterLobbyWithPasswordResponse);
	}
	// Evaluate the Lobby enter popup reponse
	private void EvaluateEnterLobbyWithPasswordResponse(SgEPopupButtonType button, string password)
	{
		if (button == SgEPopupButtonType.PRIMARY)
		{
			RequestJoinLobby(m_SelectedLobbyData.GetLobbyId(), password);
		}	
	}
	// Enter Lobby without password
	private void EnterLobbyWithoutPassword()
	{
		RequestJoinLobby(m_SelectedLobbyData.GetLobbyId());
	}
	
	// -----------------------------------------
	// Server Requests
	
	// Server request - Join a lobby 
	private void RequestJoinLobby(string id, string password = "")
	{	
		// Create request
		SgNetDataLobbyJoinRequest request = new SgNetDataLobbyJoinRequest(id, password);
		// Send request
		SgEResult result = SgSNetworkServiceWrapper.JoinCustomGame(request);
		// Listen for response
		m_NetService.GetEvent_OnLobbyJoined().Insert(OnGameDataRecieved);
	
		// Handle result
		if ( result == SgEResult.ERROR )
		{
			// Error debug
			SgDebug.Error("Request loby list data request failed ", this.ClassName(), "RequestLoadLobbyList");
			// Player Response
			// SG_TODO: Wrong password popup
		}
		else 
		{
			// ... Wait for response
		}
	}
	
	// Server request - Load List of Lobbies 
	private void RequestLoadLobbyList()
	{
		// Debug
		SgDebug.Debug("Requesting lobby list data", this.ClassName(), "RequestLoadLobbyList");
		// Start loading animation
		m_UiRefreshButton.StartButtonAnimation();
		// Create request
		ref SgNetDataLobbyListLoadRequest request = new SgNetDataLobbyListLoadRequest();
		// Send request
		SgEResult result; 
		
		if (m_NetService)
		{
			result = m_NetService.LoadLobbyList(request);
		}
		
		if (result == SgEResult.ERROR)
		{
			// Error Debug
			SgDebug.Error("Request loby list data request failed ", this.ClassName(), "RequestLoadLobbyList");
			// Player Response
			// SG_TODO: Could not load lobbies popup
		}
		else 
		{
			// ... Wait for response
		}
	}
	
	// -----------------------------------------------
	// Server Responses
		
	
	// Server response - Lobby created by client
	private void OnLobbyCreated(SgEResult resultStatus, SgNetDataLobbyCreateResponse resultValue)
	{
		RequestJoinLobby(resultValue.GetLobbyId());
	}
	
	// Server response - Lobby data recieved --> an open new screen with lobby data
	private void OnGameDataRecieved(SgEResult resultStatus, SgNetDataLobbyJoinResponse resultValue)
	{
		// Remove the lobby load listener 
		SgNetworkService.GetService().GetEvent_OnLobbyJoined().Remove(OnGameDataRecieved);
		
		// Get lobby data
		SgNetDataLobbyDetails 				lobby_details 	= resultValue.GetLobbyDetails();		
		string 								id 				= lobby_details.GetLobbyId();
		string 								name			= lobby_details.GetLobbyName();
		bool 								has_pass		= lobby_details.GetPassword();
		SgEPlaygrounds						pg_id 			= lobby_details.GetPlaygroundId();
		SgETeamSize							team_mode_id	= lobby_details.GetTeamSize();
		int 								max_players		= lobby_details.GetPlayerSlotMax();
		string 								host_name		= lobby_details.GetHostPlayerName();
		ref array<ref SgNetDataLobbyPlayer>	lobby_players 	= lobby_details.GetLobbyPlayers();	
		
		// Create lobby data
		ref SgLobbyData data = new SgLobbyData(id, name, has_pass, pg_id, team_mode_id, max_players, host_name, lobby_players);
		// Open Lobby
		SgMenuManager.OpenMenuLobby(data);
	}
	
	// Server response -  Set list of custom lobbies 
	private void OnLobbyListLoaded(SgEResult resultStatus, SgNetDataLobbyListLoadResponse resultValue)
	{
		// Stop loading animation
		m_UiRefreshButton.StopButtonAnimation();
		// Set the data
		m_LobbyListEntries = resultValue.GetLobbyList(); // Save data	
		// Refresh lobby grid
		SetLobbyGridPage();	
	}
}