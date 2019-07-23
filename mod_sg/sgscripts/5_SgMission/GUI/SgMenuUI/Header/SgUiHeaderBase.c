class SgUiHeaderBase extends SgUiMenuPanel
{
	// Widgets
	private 	Widget 					m_UiNavigationFrame;
	private 	Widget					m_UiMiscFrame;
	// Custom Widget
	private ref SgUiHeaderNavigation	m_ButtonSetMain;
	private ref SgUiHeaderMisc 			m_ButtonSetMisc;
	
	// -------------------------------------------
	
	// Constructor
	void SgUiHeaderBase(Widget parent_widget)
	{		
		super.BuildLayout(parent_widget);
	}
	
	// -------------------------------------------
	// OVERRIDES --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_header/sg_header.layout";
	}	
	override protected void LoadAllWidgets()
	{
		m_ButtonSetMain = new SgUiHeaderNavigation(FindPanel("NavigationFrame"));
		m_ButtonSetMisc = new SgUiHeaderMisc(FindPanel("MiscFrame"));
	}
}