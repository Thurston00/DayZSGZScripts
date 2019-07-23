// Class for Unconscious layout
class  SgUiUnconsciousHudBase extends SgUiHudPanel
{
	// Static var
	private static ref SgUiUnconsciousHudBase	m_instance;
	 // Widgets
	private Widget 					m_UiBPMPanel;
	private TextWidget 				m_UiBPMValueLabel;
	private ref SgUiProgressBarLeft	m_UiBPMValueProgress;
	// Events
	private ref ScriptInvoker 		Event_OnBPMUpdate;

	// --------------------------------------

	static SgUiUnconsciousHudBase GetUnconsciousHudBase()
	{
		if (!m_instance)
		{
			m_instance = new SgUiUnconsciousHudBase()
		}
		return m_instance;
	}
	
	static void DestroyUnconsciousHudBase()
	{
		delete m_instance;
		m_instance = null;
	}
	
	// --------------------------------------
	
	// Constructor
	private void SgUiUnconsciousHudBase()
	{
		BuildLayout();
	}
	// Destructor
	void ~SgUiUnconsciousHudBase()
	{
		PPEffects.SetBlur(0);
	}

	// ---------------------------------------
	// Overrides --> SgUiHudPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_unconscious.layout";
	}
	override protected void FindAllWidgets()
	{
		// Find the Widgets
		m_UiBPMPanel		= FindPanel("UnconsciousPanel");
		m_UiBPMValueLabel 	= FindLabel("BPMContent");
	}
	override protected void LoadAllWidgets()
	{
		// Create Progress Bar
		m_UiBPMValueProgress = new SgUiProgressBarLeft(FindPanel("BPMProgressFrame"), SgUiHudBase.GetHudBase().GetSgHudEvents().HudEvent_OnHealthUpdate);
		// Modify progress bar colour
		m_UiBPMValueProgress.SetProgressBarColour(SgCMenuColours.COLOUR_DARK_RED);	
	}
	override protected void RegisterAllEvents()
	{		
		SgUiHudBase.GetHudBase().GetSgHudEvents().HudEvent_OnHealthUpdate.Insert(SetBPM);
	}
	override protected void UnRegisterAllEvents()
	{			
		SgUiHudBase.GetHudBase().GetSgHudEvents().HudEvent_OnHealthUpdate.Remove(SetBPM);
	}
	
	// ------------------------------------------------------------
		
	private void SetBPM(float BPM)
	{
		PPEffects.SetBlur(1);
		
		int bpm = Math.Round(BPM);
		m_UiBPMValueLabel.SetText(bpm.ToString());
		
		m_UiBPMPanel.SetColor(ARGB(255-bpm,0,0,0));
	}

	// -----------------------------------------
}
