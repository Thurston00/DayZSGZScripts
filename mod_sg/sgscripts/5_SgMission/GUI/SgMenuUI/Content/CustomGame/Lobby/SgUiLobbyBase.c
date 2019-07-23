/*
	Ui base class for custom game lobby

	SG_TODO: Update documentation!
*/
class SgUiLobbyBase extends SgUiMenuPanel
{
	// Widgets
	private 	Widget 					m_UiLobbyInfoFrame;
	private 	Widget 					m_UiUnassignedFrame;
	private 	Widget 					m_UiLobbyTableFrame;
	// Custom Widgets
	private ref SgUiLobbyInfo  			m_UiLobbyInfo;
	private ref SgUiUnassignedPlayers 	m_UiUnassignedPlayers;
	private ref SgUiLobbyTable			m_UiLobbyTable;
	private ref SgUiButtonActionMedium	m_PrimaryButton;
	private ref SgUiButtonActionMedium	m_LeaveLobbyButton;
	private ref SgUiButtonActionMedium	m_UiDestoryButton;
	// Data
	private ref SgLobbyData 			m_LobbyData;
	private ref SgLobbyEvents			m_LobbyEvents;
	
	// -------------------------------
	// OVERRIDES --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_lobby/sg_custom_game_lobby_base.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiLobbyInfoFrame 		= FindPanel("LobbyInfoFrame");
		m_UiUnassignedFrame 	= FindPanel("UnassignedFrame");
		m_UiLobbyTableFrame 	= FindPanel("LobbyTableFrame");
	}
	override protected void RegisterAllEvents()
	{
		SgLobbyData.Event_OnLobbyDataUpdated.Insert(UpdateAllWidgets);
		SgLobbyData.Event_OnPlayerLocationUpdated.Insert(UpdatePlayerLocation);
		
		m_LobbyEvents.Event_OnPrimaryButtonEnabled.Insert(UpdatePrimaryButton);
	}
	override protected void UnRegisterAllEvents()
	{
		SgLobbyData.Event_OnLobbyDataUpdated.Remove(UpdateAllWidgets);
		SgLobbyData.Event_OnPlayerLocationUpdated.Remove(UpdatePlayerLocation);
		
		m_LobbyEvents.Event_OnPrimaryButtonEnabled.Remove(UpdatePrimaryButton);
	}
	override protected void OnDestroy()
	{
		m_LobbyEvents.LeaveLobbyRequest(SgEPopupButtonType.PRIMARY);
	}
	
	// -----------------------------------
	// Widget SETTERS
		
	private void SetLobbyInfoFrame()
	{	
		m_UiLobbyInfo = new SgUiLobbyInfo(m_UiLobbyInfoFrame, m_LobbyData);
	}	
	private void SetUnassignedPlayersFrame()
	{
		m_UiUnassignedPlayers = new SgUiUnassignedPlayers(m_UiUnassignedFrame); 
	}
	private void SetLobbyTableFrame()
	{
		m_UiLobbyTable = new SgUiLobbyTable(m_UiLobbyTableFrame, m_LobbyData);
	}
	private void SetButtons()
	{
		Widget button_grid = FindPanel("ButtonsGrid");
		
		// Leave Lobby Button
		m_LeaveLobbyButton = new SgUiButtonActionMedium(button_grid, SgCMenuButtonStrings.LOBBY_LEAVE_C, SgLobbyEvents.Event_OnLeaveLobbyButtonClicked); 
		
		
		// Start Game / Ready Player Button
		if (m_LobbyData.AmIHost())
		{
			m_UiDestoryButton = new SgUiButtonActionMedium(FindPanel("DestroyButtonFrame"), SgCMenuButtonStrings.LOBBY_DESTROY_C, SgLobbyEvents.Event_OnDestroyLobbyByttonClicked); 		
			m_PrimaryButton = new SgUiButtonActionMedium(button_grid, SgCMenuButtonStrings.LOBBY_START_C, SgLobbyEvents.Event_OnStartGameButtonClicked); 

		}
		else 
		{
			m_PrimaryButton = new SgUiButtonActionMedium(button_grid, SgCMenuButtonStrings.LOBBY_READY_C, SgLobbyEvents.Event_OnReadyGameButtonClicked); 
		}
		
		m_PrimaryButton.Enable(false);
	}
	
	// -------------------------------------------
	// UPDATES
	
	private void InitAllWidgets()
	{
		SetLobbyInfoFrame();
		SetUnassignedPlayersFrame();
		SetLobbyTableFrame();
		SetButtons();
		
		UpdatePlayerLocation();
	}
	
	private void UpdateAllWidgets()
	{		
		SetUnassignedPlayersFrame();
		SetLobbyTableFrame();
		UpdatePlayerLocation();
	}
	
	void UpdatePlayerLocation()
	{
		m_UiUnassignedPlayers.ClearScroller();
		m_UiLobbyTable.ClearAllSlots();
		
		ref array<ref SgNetDataLobbyPlayer> players = m_LobbyData.GetLobbyPlayers();
		if( players )
		{		
			for ( int i = 0; i < players.Count(); i++)
			{
				if (players.Get(i).GetSlotId() == -1)
				{
					m_UiUnassignedPlayers.AddUnassignedPlayerRow(players.Get(i), m_LobbyData.IsHost(players.Get(i)));
				}
				else 
				{
					m_UiLobbyTable.AddPlayerToTeamSlot(players.Get(i), m_LobbyData.IsHost(players.Get(i)));
				}
			}
		}
	}
	
	private void UpdatePrimaryButton(bool is_enabled)
	{
		m_PrimaryButton.Enable(is_enabled);
	}
	
	// -------------------------------------------
	// LOBBY DATA METHODS	
	
	void SetLobbyData(SgLobbyData data)
	{
		m_LobbyData = data;
		
		Print("TEAM MODE ID: " + data.GetTeamMode().GetID());
		
		if (!m_LobbyEvents)
		{
			m_LobbyEvents = new SgLobbyEvents(this);
		}
		InitAllWidgets();
	}
	
	SgLobbyData GetLobbyData()
	{
		return m_LobbyData;
	}
}