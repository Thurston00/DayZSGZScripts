/*
	Ui class for a lobby team table
*/
class SgUiLobbyTable extends SgUiMenuPanel
{
	// Widgets
	private 	TextWidget 						m_UiPlayerCountLabel;
	private 	Widget							m_UiContentGrid;
	private ref array<ref SgUiLobbyTeamSlot> 	m_TeamSlots 			= new ref array<ref SgUiLobbyTeamSlot>;
	// Data
	private ref SgLobbyData						m_LobbyData;
	
	// --------------------------------
	
	void SgUiLobbyTable(Widget parent_widget, SgLobbyData lobby_data)
	{	
		m_LobbyData = lobby_data;
		super.BuildLayout(parent_widget);
	}
	
	// --------------------------------
	// OVERRIDES 
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_lobby/sg_lobby_table.layout";
	}
	
	override protected void FindAllWidgets()
	{
		m_UiPlayerCountLabel 	= FindLabel("PlayerCountLabel");
		m_UiContentGrid 		= FindPanel("ContentGrid");
	}
	
	override protected void LoadAllWidgets()										
	{
		SetContentGrid();
		SetPlayerCountLabel();
	}
	
	// ---------------------------------
	
	private void SetContentGrid()
	{
		for(int i = 0; i < m_LobbyData.GetTeamCount(); i++)
		{
			m_TeamSlots.Insert( new SgUiLobbyTeamSlot(m_UiContentGrid, i, m_LobbyData.GetTeamMode()) );
		}
	}
	
	private void SetPlayerCountLabel()
	{
		m_UiPlayerCountLabel.SetText(m_LobbyData.GetCurrentPlayersCount().ToString() + " / " + m_LobbyData.GetMaxPlayers().ToString());
	}
	
	// -------------------------------------
	
	void ClearAllSlots()
	{
		foreach ( SgUiLobbyTeamSlot slot : m_TeamSlots)
		{
			slot.ClearAllSlots();
		}
	}
	
	void ClearSlotById(int team_id, int slot_id)
	{
		foreach (SgUiLobbyTeamSlot team_slot : m_TeamSlots)
		{
			if (team_slot.GetTeamSlotID() == team_id)
			{
				team_slot.ClearSlotByID(slot_id);
			}
		}
	}
	
	void AddPlayerToTeamSlot(SgNetDataLobbyPlayer player, bool is_host)
	{
		SgUiLobbyTeamSlot team_slot = m_TeamSlots.Get(player.GetTeamId());
		team_slot.AddPlayerToPlayerSlot(player, is_host);
	}
}







