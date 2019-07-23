// DESIGN_ID: 0002

/*
	SG_TODO: Desc
*/
class SgUiPlayerInfoBase extends SgUiHudPanel
{
	// Widgets
	private 	Widget 			m_UiSplitter;
	private 	Widget 			m_UiOverloadFrame;
	private 	Widget 			m_UiBleedingFrame;
	private 	ImageWidget 	m_UiBackground;
	private 	ImageWidget 	m_UiOverloadIcon;
	private 	ImageWidget 	m_UiBleedingIcon;
	private ref SgUiProgressBar m_UiHealthBar;	
	// Events
	private ref ScriptInvoker 	Event_OnOverloadChanged;
	private ref ScriptInvoker 	Event_OnBleedingChanged;
	private ref ScriptInvoker 	Event_OnHealthChanged;
	// Data
	private 	bool 			m_IsBleedingThreadRunning;
	private 	bool 			m_BleedingColourSwitch;
	
	/// Constructor
	void SgUiPlayerInfoBase(Widget parent_widget, ScriptInvoker event_overload_changed, ScriptInvoker event_bleeding_changed, ScriptInvoker event_health_changed)
	{
		// Events
		Event_OnOverloadChanged = event_overload_changed;
		Event_OnBleedingChanged = event_bleeding_changed;
		Event_OnHealthChanged	= event_health_changed;
		// Build 
		BuildLayout(parent_widget);
	}
	
	// ---------------------------------------------
	// OVERRIDES --> SgUiHudPanel
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_player_info/sg_player_info_base.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiSplitter 		= FindPanel("SplitterImage");
		m_UiOverloadFrame	= FindPanel("OverloadFrame");
		m_UiBleedingFrame	= FindPanel("BleedingFrame");
		m_UiOverloadIcon 	= FindImage("OverloadIcon");
		m_UiBleedingIcon 	= FindImage("BleedingIcon");
		m_UiBackground		= FindImage("Background");
	}	
	override protected void LoadAllWidgets()
	{
		// Load healthbar
		m_UiHealthBar = new ref SgUiProgressBar(FindPanel("HealthBarFrame"));
		// Load image set
		LoadBleedingIcons();
		SetSplitter();
	}
	override protected void RegisterAllEvents()
	{
		Event_OnOverloadChanged.Insert(SetOverloadedIcon);
		Event_OnBleedingChanged.Insert(SetBleedingSourceIcon);
		Event_OnHealthChanged.Insert(SetHealthBar);
	}
	override protected void UnRegisterAllEvents()
	{
		Event_OnOverloadChanged.Remove(SetOverloadedIcon);
		Event_OnBleedingChanged.Remove(SetBleedingSourceIcon);
		Event_OnHealthChanged.Remove(SetHealthBar);
	}
	
	// -----------------------------------------------
	// Splitter
	private void SetSplitter()
	{
		m_UiSplitter.Show((m_UiOverloadFrame.IsVisible() || m_UiBleedingFrame.IsVisible()));
	}
	
	// -----------------------------------------------	
	// Overload 
	private void SetOverloadedIcon(bool is_overloaded = false)			// Show/Hide overload icon
	{
		m_UiOverloadFrame.Show(is_overloaded);
		SetSplitter();
	}
	
	// -----------------------------------------------
	// Bleeding
	private void LoadBleedingIcons()									/// Load all bleeding icons
	{
		m_UiBleedingIcon.LoadImageFile(0, SgCMenuWidgetPaths.BLOOD_SINGLE_ICON);
		m_UiBleedingIcon.LoadImageFile(1, SgCMenuWidgetPaths.BLOOD_DOUBLE_ICON);
		m_UiBleedingIcon.LoadImageFile(2, SgCMenuWidgetPaths.BLOOD_TRIPLE_ICON);
	}
	private void SetBleedingSourceIcon(int bleeding_sources = 0)		/// Set correct bleeding 
	{
		if (bleeding_sources == 0)					// Hide bleeding in player doesn't bleed
		{		
			if (m_IsBleedingThreadRunning)
			{
				m_IsBleedingThreadRunning = false;
				GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(BleedingThread);
			}
			
			m_UiBackground.SetColor(SgCMenuColours.COLOUR_BLACK);
			m_UiBleedingFrame.Show(false);
					
		}
		else 										// Show corret bleeding icon
		{	
			
			m_UiBleedingFrame.Show(true);
			m_UiBleedingIcon.SetImage( Math.Clamp((bleeding_sources - 1), 0, 2));
			
			if (!m_IsBleedingThreadRunning)
			{
				m_IsBleedingThreadRunning = true;
				
				//GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(BleedingThread);
				GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(BleedingThread, 1000, true);
			}
		}
		SetSplitter();
	}
	
	private void BleedingThread()
	{
		if (m_BleedingColourSwitch)
		{
			m_UiBackground.SetColor(SgCMenuColours.COLOUR_BLACK);
		}
		else 
		{
			m_UiBackground.SetColor(SgCMenuColours.COLOUR_DARK_RED);
		}
		
		m_BleedingColourSwitch = !m_BleedingColourSwitch;
	}
	
	// -------------------------------------------------
	// Health
	private void SetHealthBar(float health = 100)							/// Set Health bar value
	{
		m_UiHealthBar.SetProgress(health);
	}
}






