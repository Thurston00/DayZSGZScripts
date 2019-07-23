// DESIGN_ID: 0001
/*
	SG_TODO: Desc
*/
class SgUiPartyInfoBase extends SgUiHudPanel
{
	// Widgets
	private ref array<ref SgUiPartyInfoSlot> m_UiPartyList = new array<ref SgUiPartyInfoSlot>;
	// Events
	private ref array<ref SgHudTeamMateEvents> m_TeamMateEvents;
	
	void SgUiPartyInfoBase(Widget parent_widget, array<ref SgHudTeamMateEvents> teammate_events)
	{
		m_TeamMateEvents = teammate_events;
		BuildLayout(parent_widget);
	}
	
	// ----------------------------------------------
	// Override --> SgUiHudPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_party_info/sg_party_info_base.layout";
	}
	override protected void LoadAllWidgets()
	{
		LoadPartySlost();
	
	}
	
	// ----------------------------------------------
	
	private void LoadPartySlost()
	{
		// Create a compass tracker for each teammate
		for (int i = 0; i < m_TeamMateEvents.Count(); i++)
		{
			ref SgHudTeamMateEvents teamate_events 		= m_TeamMateEvents.Get(i);
			string player_name 							= teamate_events.GetPlayerClient().GetUserName();
			int player_color 							= Colors.GetPlayerColorByTeamSlot(i);			
			ref ScriptInvoker event_state 				= teamate_events.HudEvent_OnTeammateStatusUpdate;		
			ref ScriptInvoker event_health 				= teamate_events.HudEvent_OnTeammateHealthUpdate;
			ref ScriptInvoker event_mic 				= teamate_events.HudEvent_OnTeammateMicrophoneUpdate;
			
			m_UiPartyList.Insert(new ref SgUiPartyInfoSlot(FindPanel("PartyGrid"), player_name , player_color, event_state, event_health, event_mic));
		}
	}
}