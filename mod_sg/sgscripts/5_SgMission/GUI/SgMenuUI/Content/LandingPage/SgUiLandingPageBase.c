/*
	
*/
class SgUiLandingPageBase extends SgUiMenuPanel
{
	private const string ROOT_PATH = "mod_sg/gui/layouts/sg_menu/sg_content/sg_landing_page/sg_landing_page_base.layout";
	// Custom Widget
	private ref SgUiTutorial	m_UiTutorial;
	
	// --------------------------------
	// OVERRIDES --> SgUiMenuPanel	
	override string GetLayoutPath()
	{
		return ROOT_PATH;
	}
	override protected void LoadAllWidgets()
	{
		m_UiTutorial = new SgUiTutorial(FindPanel("TutorialFrame"));
	}
	
	// --------------------------------
}