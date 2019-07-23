/*
	This class is a middle-man between DayZ settings and SgZ Menu. Used mainly to keep the layout consistency
*/
class SgUiSettingsBase extends SgUiMenuPanel
{	
	private ref OptionsMenu m_UiOptionMenu;				// <-- DayZ options
	
	// ------------------------------------
	// Override --> SgUiMenuPanel
	override string GetLayoutPath()			// <-- SgZ Layout
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_settings/sg_settings_base.layout";
	}
	override protected void LoadAllWidgets()
	{
		m_UiOptionMenu = new OptionsMenu();
		m_UiOptionMenu.SgInit(GetRootFrame());
	}
}
