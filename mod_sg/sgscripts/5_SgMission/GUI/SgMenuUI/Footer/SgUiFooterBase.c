class SgUiFooterBase extends SgUiMenuPanel
{
	// Consts
	private const string	 		ROOT_PATH = "mod_sg/gui/layouts/sg_menu/sg_footer/sg_footer_base.layout";
	// Custom Widgets
	private ref SgUiFooterPlayPanel	m_UiPlayPanel;
		
	
	// ---------------------------
	// Constructor
	void SgUiFooterBase(Widget parent_widget)
	{		
		super.BuildLayout(parent_widget);
	}
	
	// ------------------------------
	// OVERRIDES --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return ROOT_PATH;
	}
	override protected void LoadAllWidgets()
	{
		m_UiPlayPanel = new SgUiFooterPlayPanel(FindPanel("PlayFrame"));
	}
}