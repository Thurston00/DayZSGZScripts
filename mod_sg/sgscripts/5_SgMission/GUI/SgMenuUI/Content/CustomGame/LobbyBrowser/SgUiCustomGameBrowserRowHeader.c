/*
	Ui class for a Game Browser row header

	NOTE: 
	Please note that you have to call BuildLayout() manually as it can't be located in a constructor. It makes problems when this class is inherited. 
*/
class SgUiCustomGameBrowserRowHeader extends SgUiMenuPanel
{
	// Widgets
	protected TextWidget m_UiLobbyNameLabel;
	protected TextWidget m_UiPassLabel;
	protected TextWidget m_UiGameModeLabel;
	protected TextWidget m_UiSlotLabel;
	protected TextWidget m_UiPlaygroundLabel;
	
	// ------------------------------------
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_game_browser_slot_header.layout";
	}
	
	override protected void FindAllWidgets()
	{
		m_UiLobbyNameLabel		= FindLabel("LobbyNameLabel");
		m_UiPassLabel 			= FindLabel("PassLabel");
		m_UiGameModeLabel 		= FindLabel("GameModeLabel");
		m_UiSlotLabel	 		= FindLabel("SlotsLabel");
		m_UiPlaygroundLabel 	= FindLabel("PlaygroundLabel");
	}
	
	override protected void LoadAllWidgets()
	{
		m_UiLobbyNameLabel.SetText(SgCMenuWidgetStrings.LOBBY_TABLE_NAME);
		m_UiPassLabel.SetText(SgCMenuWidgetStrings.LOBBY_TABLE_PRIVACY);
		m_UiGameModeLabel.SetText(SgCMenuWidgetStrings.LOBBY_TABLE_MODE);
		m_UiPlaygroundLabel.SetText(SgCMenuWidgetStrings.LOBBY_TABLE_PLAYGROUND);
		m_UiSlotLabel.SetText(SgCMenuWidgetStrings.LOBBY_TABLE_SLOTS);
	}
}