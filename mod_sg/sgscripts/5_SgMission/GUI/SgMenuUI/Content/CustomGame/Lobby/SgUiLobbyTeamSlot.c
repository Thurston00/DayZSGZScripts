/*
	Ui class for a single team slot in lobby
*/
class SgUiLobbyTeamSlot extends SgUiMenuPanel
{
	// Consts
	private const string 						ROOT_SOLO 	= "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_lobby/sg_lobby_team_slot_solo.layout";
	private const string 						ROOT_DUO 	= "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_lobby/sg_lobby_team_slot_duo.layout";
	private const string 						ROOT_SQUAD 	= "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_lobby/sg_lobby_team_slot_squad.layout";
	// Widgets
	private 	Widget 							m_UiPlayerGrid;
	private 	TextWidget						m_UiTeamLabel;
	private ref array<ref SgUiLobbyPlayerSlot> 	m_UiPlayerSlots 		= new ref array<ref SgUiLobbyPlayerSlot>;
	// Data
	private 	int 							m_SlotID;
	private ref SgCTeamMode						m_TeamMode;
	
	// --------------------------------
	
	// Constructor
	void SgUiLobbyTeamSlot(Widget parent_widget, int id, SgCTeamMode team_mode)
	{	
		m_SlotID = id;
		m_TeamMode = team_mode;
		super.BuildLayout(parent_widget);
	}
	
	// ---------------------------------
	// OVERRIDES SgUiMenuPanel methods
	
	override string GetLayoutPath()
	{
		// Select correct layout 
		switch (m_TeamMode.GetID())
		{
			case SgETeamSize.SOLO:
			{
				return ROOT_SOLO;
			}
			case SgETeamSize.DUO:
			{
				return ROOT_DUO;
			}
			case SgETeamSize.SQUAD:
			{
				return ROOT_SQUAD;
			} 
		}
		return "";
	}
	
	override protected void FindAllWidgets()
	{
		m_UiPlayerGrid	= FindPanel("ContentGrid");
		m_UiTeamLabel	= FindLabel("TeamLabel");	
	}
	
	override protected void LoadAllWidgets()										
	{
		for(int i = 0; i < m_TeamMode.GetSize() ; i++)
		{
			m_UiPlayerSlots.Insert(new SgUiLobbyPlayerSlot(m_UiPlayerGrid, i, m_SlotID));
		}	
		
		m_UiTeamLabel.SetText((m_SlotID + 1).ToString());
	}
	
	// -----------------------------------
		
	int GetTeamSlotID()
	{
		return m_SlotID;
	}
	
	// --------------------------------------
	
	void ClearAllSlots()
	{
		foreach( SgUiLobbyPlayerSlot slot : m_UiPlayerSlots)
		{
			slot.ClearSlot();
		}
	}
	
	void ClearSlotByID(int slot_id)
	{
		foreach ( SgUiLobbyPlayerSlot slot : m_UiPlayerSlots)
		{
			if (slot.GetSlotID() == slot_id)
			{
				slot.ClearSlot();
			}
		}
	}
	
	void AddPlayerToPlayerSlot(SgNetDataLobbyPlayer player, bool is_host = false)
	{		
		SgUiLobbyPlayerSlot player_slot = m_UiPlayerSlots.Get(player.GetSlotId());
		player_slot.AddPlayer(player, is_host);
	}
}