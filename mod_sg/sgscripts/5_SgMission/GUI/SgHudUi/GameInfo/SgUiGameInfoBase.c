// DESIGN_ID: 0002

/*
	SG_TODO: DEsc
*/
class SgUiGameInfoBase extends SgUiHudPanel
{
	// Widgets
	private 	TextWidget 		m_UiZoneTimeLabel;
	private 	TextWidget 		m_UiPlayerCountLabel;
	private 	TextWidget		m_UiCurrentZoneLabel;
	private 	ImageWidget 	m_UiZoneIcon;
	// Data
	private 	float 			m_RoundTime;
	// Events 
	private ref ScriptInvoker 	HudEvent_OnPhaseTimerUpdate;
	private ref ScriptInvoker 	HudEvent_OnPhaseTypeUpdate;
	private ref ScriptInvoker 	HudEvent_OnPlayerCounterUpdate;
	
	void SgUiGameInfoBase(Widget parent_widget, ScriptInvoker event_phase_timer_update, ScriptInvoker event_phase_type_update, ScriptInvoker event_player_counter_changed)
	{
		HudEvent_OnPhaseTimerUpdate	 	= event_phase_timer_update;
		HudEvent_OnPhaseTypeUpdate 		= event_phase_type_update;
		HudEvent_OnPlayerCounterUpdate 	= event_player_counter_changed;
		BuildLayout(parent_widget);
		
		OnPlayerCountChanged( SgSClientGame.GetPlayersAliveCount() );
	}
	
	// ----------------------------------------------------------------
	// Overrides --> SgUiHudPanel
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_game_info/sg_game_info_base.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiZoneTimeLabel			= FindLabel("ZoneTimeLabel");
		m_UiPlayerCountLabel		= FindLabel("PlayerCountLabel");
		m_UiCurrentZoneLabel		= FindLabel("CurentZoneValueLabel");
		m_UiZoneIcon	 			= FindImage("ZoneIcon");
	}		
	override protected void LoadAllWidgets()
	{
		LoadZoneIconSet();
	}	
	override protected void RegisterAllEvents()
	{
		HudEvent_OnPhaseTimerUpdate.Insert(OnZoneTimeChanged);
		HudEvent_OnPhaseTypeUpdate.Insert(OnZoneIconChanged);
		HudEvent_OnPlayerCounterUpdate.Insert(OnPlayerCountChanged);
	}
	override protected void UnRegisterAllEvents()
	{
		HudEvent_OnPhaseTimerUpdate.Remove(OnZoneTimeChanged);
		HudEvent_OnPhaseTypeUpdate.Remove(OnZoneIconChanged);
		HudEvent_OnPlayerCounterUpdate.Remove(OnPlayerCountChanged);
	}
	
	// ------------------------------------------------------------------
	// Zone Icons
	/// Load zone icons 
	private void LoadZoneIconSet()
	{
		m_UiZoneIcon.LoadImageFile(0, SgCMenuWidgetPaths.PHASE_ZONE_ICON);
		m_UiZoneIcon.LoadImageFile(1, SgCMenuWidgetPaths.PHASE_TRANSITION_ICON);
		m_UiZoneIcon.LoadImageFile(2, SgCMenuWidgetPaths.PHASE_END_ICON);
	}		
	/// On Zone Update
	private void OnZoneIconChanged( ESgGameState phase_type, ESgLocationType location_type )
	{			
		switch(phase_type)
		{
			case ESgGameState.Phase:
			{
				if (location_type == ESgLocationType.PhaseEnd)
				{
					m_UiZoneIcon.SetImage(2);
					m_UiCurrentZoneLabel.SetText("");
				}
				else 
				{
					m_UiZoneIcon.SetImage(0);
					m_UiCurrentZoneLabel.SetText( GetLocationTypeText(location_type) );	
				}
				break;
			}
			case ESgGameState.Transition:
			{
				m_UiZoneIcon.SetImage(1);
				m_UiCurrentZoneLabel.SetText( GetLocationTypeText(location_type) );	
				break;
			}
			default:
			{
				m_UiZoneIcon.SetImage(0);
				m_UiCurrentZoneLabel.SetText("X");
				break;
			}
		}
	}
	
	private string GetLocationTypeText( ESgLocationType location_type )
	{
		switch ( location_type )
		{
			case ESgLocationType.PhaseFirst: 	{ return "1"; }
			case ESgLocationType.PhaseSecond: 	{ return "2"; }
			case ESgLocationType.PhaseStart: 	{ return "0"; }
		}
		
		return "X";
	}
	
	// ------------------------------------------------------------------
	// Zone Timer
	/// On Zone Time Update
	private void OnZoneTimeChanged(string time)
	{
		m_UiZoneTimeLabel.SetText( time );
	}
	
	// --------------------------------------------------------------------		
	// Player count
	private void OnPlayerCountChanged(int player_count)
	{
		m_UiPlayerCountLabel.SetText(player_count.ToString());
	}	
}


