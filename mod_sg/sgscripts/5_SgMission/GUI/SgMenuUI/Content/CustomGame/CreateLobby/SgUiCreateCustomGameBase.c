/*
	Ui base class for "create custom game" panel
*/
class SgUiCreateCustomGameBase extends SgUiMenuPanel
{
	// Widgets
	private 	Widget 					m_UiTeamSizeFrame;
	private 	Widget 					m_UiPlaygroundFrame;
	private		Widget 					m_UiPasswordFrame; 
	private 	Widget	 				m_UiGameNameFrame;
	// Custom Widgets	
	private ref SgUiButtonActionMedium 	m_UiCreateGameButton;
	private ref SgUiRadioButton 		m_UiTeamSizeRadioButtons;
	private ref SgUiRadioButton 		m_UiPlaygroundRadioButtons;
	private ref SgUiPasswordTextBox		m_UiPassTextBox;
	private ref SgUiMaskedTextBox		m_UiGameNameTextBox;
	// Events
	private ref ScriptInvoker 			Event_CreateButton_OnClick	= new ScriptInvoker();
	
	// --------------------------------
	
	// Constructor
	void SgUiCreateCustomGameBase(Widget parent_widget)
	{
		super.BuildLayout(parent_widget);
	}
	
	// ------------------------------
	// OVERRIDES -- > SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return  "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_create_custom_game.layout";
	}
	override protected void FindAllWidgets()
	{
		// Find widgets
		m_UiTeamSizeFrame 		= FindPanel("TeamSizeContentFrame");
		m_UiPlaygroundFrame 	= FindPanel("PlaygroundContentFrame");		
		m_UiPasswordFrame 		= FindPanel("PasswordFrame");
		m_UiGameNameFrame 		= FindPanel("GameNameGrid");
	}
	override protected void LoadAllWidgets()										
	{
		m_UiCreateGameButton = new SgUiButtonActionMedium( FindPanel("CreateGameButtonFrame"), SgCMenuButtonStrings.CREATE_GAME_C, Event_CreateButton_OnClick);
		SetTeamSizeRadioButtons();
		SetPlaygroundRadioButtons();
		SetPasswordTextBoxFrame();
		SetGameNameTextBoxFrame();
		
		super.GetRootFrame().SetHandler(this);
	}
	override protected void RegisterAllEvents()
	{
		Event_CreateButton_OnClick.Insert(EventRequest_CreateLobbyData);
	}
	override protected void UnRegisterAllEvents()
	{
		Event_CreateButton_OnClick.Remove(EventRequest_CreateLobbyData);
	}

	// -------------------------------------------------
	private void SetPlaygroundRadioButtons()
	{	
		SgCPlayground severograd = SgCPlayground.FindPlaygroundById(SgEPlaygrounds.SEVEROGRAD);
		
		// Create radiobutton data
		ref array<ref Param2< string, string>> playgrounds = new ref array<ref Param2< string, string>>;
		// Insert radiobutton entry 
		playgrounds.Insert( new ref Param2<string, string>(severograd.GetName(), severograd.GetID().ToString()));
		// Create radiobutton set 
		m_UiPlaygroundRadioButtons = new SgUiRadioButton(m_UiPlaygroundFrame, playgrounds);
	}
	private void SetTeamSizeRadioButtons()
	{
		// Create team mode data list
		array<ref SgCTeamMode> team_mode_list = new ref array<ref SgCTeamMode>; 
		// Get team mode data 
		team_mode_list.Insert(SgCTeamMode.FindModeById(SgETeamSize.SOLO));	
		team_mode_list.Insert(SgCTeamMode.FindModeById(SgETeamSize.DUO));
		team_mode_list.Insert(SgCTeamMode.FindModeById(SgETeamSize.SQUAD));
			
		// Create RadioButton Data List
		ref array<ref Param2< string, string>> team_sizes = new ref array<ref Param2< string, string>>;
		
		foreach(SgCTeamMode mode : team_mode_list)
		{
			// Insert radiobutton entry
			team_sizes.Insert( new ref Param2<string, string>(mode.GetName(), mode.GetID().ToString()) );
		}
		// Create radiobutton set
		m_UiTeamSizeRadioButtons = new SgUiRadioButton(m_UiTeamSizeFrame, team_sizes);
	}
	private void SetPasswordTextBoxFrame()
	{
		m_UiPassTextBox = new SgUiPasswordTextBox(m_UiPasswordFrame);
	}
	private void SetGameNameTextBoxFrame()
	{
		m_UiGameNameTextBox = new SgUiMaskedTextBox(m_UiGameNameFrame, SgCMenuWidgetStrings.GAME_NAME_HINT);	
	}
	
	// ----------------------------------------------
	
	private bool CheckRoomNameText(string room_name)
	{
		if(room_name == "")
		{
			SgDebug.Error("Room name cannot be empty!", ClassName(), "CheckRoomNameText");
			SgMenuManager.OpenAlertPopup(SgCPopupDescTexts.W_MISS_LOBBY_NAME);
			return false;
		}
		return true;
	}
	
	// -----------------------------------------------
	// Events	
	
	private void EventRequest_CreateLobbyData()
	{			
		ref SgNetDataLobbyCreateRequest lobby_data;
		
		// Room name
		string 			room_name 	= m_UiGameNameTextBox.GetText();	
		if (!CheckRoomNameText(room_name)) {return;}
		// Team Mode
		SgETeamSize		team_mode	= m_UiTeamSizeRadioButtons.GetSelectedRadioButtonValue().ToInt();
		// Playground
		SgEPlaygrounds 	playground	= m_UiPlaygroundRadioButtons.GetSelectedRadioButtonValue().ToInt();
		// Password
		string 			password	= m_UiPassTextBox.GetText();			
		
		SgDebug.Debug("Creating a lobby!", ClassName(), "EventRequest_CreateLobbyData");
				
		lobby_data = new SgNetDataLobbyCreateRequest(room_name, team_mode, playground, password);
		SgEResult result = SgSNetworkServiceWrapper.CreateCustomMatch(lobby_data);		
	}
}

