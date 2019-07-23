/*
	Ui base class for custom game
*/
class SgUiCustomGameBase extends SgUiMenuPanel
{
	// Data
	private ref SgUiCreateCustomGameBase 	m_UiCreateCustomGame;
	private ref SgUiCustomGameBrowserBase 	m_UiCustomGameBrowser;
		
	// --------------------------------

	// OVERRIDES 
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_custom_game_base.layout";
	}

	override protected void LoadAllWidgets()										
	{
		m_UiCreateCustomGame 	= new SgUiCreateCustomGameBase(FindPanel("CreateGameFrame"));
		m_UiCustomGameBrowser 	= new SgUiCustomGameBrowserBase(FindPanel("BrowseGameFrame"));
	}
}