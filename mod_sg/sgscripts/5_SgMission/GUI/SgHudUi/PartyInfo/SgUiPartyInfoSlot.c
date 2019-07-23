// DESIGN_ID: 0002

/*
	SG_TODO: Desc
*/
class SgUiPartyInfoSlot extends SgUiHudPanel
{
	// Widgets
	private 	TextWidget		m_UiNameLabel;
	private 	ImageWidget 	m_UiMicrophoneIcon;
	private 	ImageWidget 	m_UiStatusIcon;
	private ref SgUiProgressBar m_UiHealhBar;
	// Data
	private string 				m_PlayerName;
	private int					m_PlayerColour;
	// Events
	private ref ScriptInvoker Event_OnTeammateStateChanged;		
	private ref ScriptInvoker Event_OnTeammateHealthChanged;	
	private ref ScriptInvoker Event_OnTeammateMicrophoneChanged;	
	
	void SgUiPartyInfoSlot(Widget parent_widget, string name, int colour, ScriptInvoker event_status_update, ScriptInvoker event_health_update, ScriptInvoker event_microphone_update)
	{
		// Data
		m_PlayerName 	= name;
		m_PlayerColour 	= colour;
		// Events
		Event_OnTeammateStateChanged 		= event_status_update;
		Event_OnTeammateHealthChanged	 	= event_health_update;
		Event_OnTeammateMicrophoneChanged	= event_microphone_update;
		// Build
		BuildLayout(parent_widget);
	}
	
	// ----------------------------------------------
	// Override --> SgUiHudPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_party_info/sg_party_info_slot.layout";
	}
	override protected void LoadAllWidgets()
	{
		m_UiHealhBar = new SgUiProgressBar(FindPanel("HealthBarFrame"));
		LoadAllStatusIcons();
		SetNameLabel();
	}
	override protected void FindAllWidgets()
	{
		m_UiNameLabel 		= FindLabel("NameLabel");
		m_UiMicrophoneIcon 	= FindImage("MicrophoneIcon");
		m_UiStatusIcon 		= FindImage("StatusIcon");
	}
	override protected void RegisterAllEvents()
	{
		Event_OnTeammateStateChanged.Insert(SetStatusIcon);	
		Event_OnTeammateHealthChanged.Insert(SetHealthBar);	
		Event_OnTeammateMicrophoneChanged.Insert(SetMicrophoneIcon);	
	}
	override protected void UnRegisterAllEvents()
	{
		Event_OnTeammateStateChanged.Remove(SetStatusIcon);	
		Event_OnTeammateHealthChanged.Remove(SetHealthBar);	
		Event_OnTeammateMicrophoneChanged.Remove(SetMicrophoneIcon);	
	}
	
	// -------------------------------------------------
	// Status	
	private void LoadAllStatusIcons()											/// Load all player status icons
	{
		m_UiStatusIcon.LoadImageFile(0, SgCMenuWidgetPaths.TEAMMATE_UNCONSCIOUS_ICON);			// Uncoscious icon
		m_UiStatusIcon.LoadImageFile(1, SgCMenuWidgetPaths.TEAMMATE_DEAD_ICON);					// Dead icon
		m_UiStatusIcon.LoadImageFile(2, SgCMenuWidgetPaths.TEAMMATE_DISCONNECTED_ICON);			// Disconnected icon
	}
	private void SetStatusIcon(SgEPlayerStates teammate_state)
	{
		// Reset colours
		SetDefaultColours();							
		
		// Set icon acording to player state
		if ( teammate_state == SgEPlayerStates.ALIVE)	// if player healthy hide status
		{
			m_UiStatusIcon.Show(false);						// hide status icon
		}
		else 											// else
		{
			m_UiStatusIcon.Show(true);						// show status icon
			m_UiStatusIcon.SetImage(teammate_state - 1);	// set appropriate icon
			
			if (teammate_state == SgEPlayerStates.UNCONSCIOUS)
			{
				SetUnconsciousColours();			
			}
			else
			{
				SetDeadColours();
			}
		}
	}
	
	// -------------------------------------------------
	// Microphone
	private void SetMicrophoneIcon(bool show_microphone = false)
	{
		m_UiMicrophoneIcon.Show(show_microphone);
	}
	
	// --------------------------------------------------
	// Healthbar
	private void SetHealthBar(float health)	// Health range float 0 - 100 ?? 
	{
		m_UiHealhBar.SetProgress(health);
	}
	
	// ----------------------------------------------------
	// Name	
	private void SetNameLabel()
	{
		m_UiNameLabel.SetText(m_PlayerName);
	}
	
	// ----------------------------------------------------
	// Colours 
	private void SetDefaultColours()											/// Default colours without any modifiers 
	{
		m_UiHealhBar.SetProgressBarColour(SgCMenuColours.COLOUR_WHITE);
		m_UiNameLabel.SetColor(m_PlayerColour);
		m_UiStatusIcon.SetColor(SgCMenuColours.COLOUR_WHITE);
	}	
	private void SetDeadColours()												/// Set colours when player dead or disconnected
	{
		m_UiNameLabel.SetColor(SgCMenuColours.COLOUR_LIGHT_GREY);
		m_UiStatusIcon.SetColor(SgCMenuColours.COLOUR_LIGHT_GREY);
	}
	private void SetUnconsciousColours()										// Set colours when player unconscious
	{
		m_UiHealhBar.SetProgressBarColour(SgCMenuColours.COLOUR_DARK_RED);
		m_UiNameLabel.SetColor(SgCMenuColours.COLOUR_LIGHT_GREY);
		m_UiStatusIcon.SetColor(SgCMenuColours.COLOUR_DARK_RED);
	}
}








