// DESIGN_ID: 0002

/*
	SG_TODO: Desc
*/
class SgUiProgressBar extends SgUiMenuPanel
{
	// Widget
	private ImageWidget m_UiProgressBar;
	// Data
	private float 		m_MaxWidth;
	private float 		m_MaxHeight;
	private float 		m_Progress = 100;		// value in % (min 0 max 100);
	
	// Event
	protected ref ScriptInvoker Event_OnProgressBarUpdate;

	void SgUiProgressBar(Widget parent_widget, ScriptInvoker event_progress_bar_update = null)
	{	
		Event_OnProgressBarUpdate = event_progress_bar_update;
		
		BuildLayout(parent_widget);
	}
	
	// ------------------------------
	// OVERRIDES -- > SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_progress_bar/sg_progress_bar_base.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiProgressBar 	= FindImage("ProgressBar");
	}
	override protected void LoadAllWidgets()										
	{
		LoadDefaultColours();
		
		m_UiProgressBar.GetSize(m_MaxWidth,m_MaxHeight);
		SetProgressBarSize();
	}
	override protected void RegisterAllEvents()
	{
		if (Event_OnProgressBarUpdate)
		{
			Event_OnProgressBarUpdate.Insert(SetProgress);
		}
	}
	override protected void UnRegisterAllEvents()
	{
		if (Event_OnProgressBarUpdate)
		{
			Event_OnProgressBarUpdate.Remove(SetProgress);
		}
	}
	
	// ---------------------------------------------
	// Colour
	
	protected void LoadDefaultColours()
	{
		SetBackgroundColour(SgCMenuColours.COLOUR_HEALTHBAR_BACKGROUND);
		SetProgressBarColour(SgCMenuColours.COLOUR_WHITE);
	}
	
	void SetBackgroundColour(int colour)
	{
		m_UiBackground.SetColor(colour);
	}

	void SetProgressBarColour(int colour)
	{
		m_UiProgressBar.SetColor(colour);
	}
	
	// -----------------------------------------------
	// Update progress
	
	// Limited from 0 - 100
	void SetProgress(float progress)
	{
		m_Progress = Math.Clamp(progress, 0, 100);
		SetProgressBarSize();
	}
	
	private void SetProgressBarSize()
	{
		float size; 
		size = m_Progress * ( m_MaxWidth / 100); 
		
		m_UiProgressBar.SetSize( size , m_MaxHeight, true);
	}
}