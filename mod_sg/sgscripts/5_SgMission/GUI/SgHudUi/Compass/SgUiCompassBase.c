// DESIGN_ID: 0002

/*
*/
class SgUiCompassBase extends SgUiHudPanel
{
	// Widgets
	private ImageWidget	m_CompassImage;
	private TextWidget	m_CompassDirectionLabel;
	private ref array<ref SgUiCompassTeammateTracker> m_CompassTrackers = new array<ref SgUiCompassTeammateTracker>;
	// Events
	private ref ScriptInvoker 	HudEvent_OnCompassRotationUpdate;
	private ref array<ref SgHudTeamMateEvents> m_TeamMateEvents;
	// Data 
	private float m_LastDirection;
	
	// Constructor
	void SgUiCompassBase(Widget parent_widget, array<ref SgHudTeamMateEvents> teammate_events, ScriptInvoker event_rotation_update)
	{
		m_TeamMateEvents = teammate_events;
		HudEvent_OnCompassRotationUpdate = event_rotation_update;
		BuildLayout(parent_widget);
	}
	
	// ----------------------------------------------------------------
	// Overrides --> SgUiHudPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_compass/sg_compass.layout";
	}
	override protected void FindAllWidgets()
	{
		m_CompassImage			= FindImage( "Compass" );			
		m_CompassDirectionLabel	= FindLabel( "Direction" );	
	}	
	override protected void LoadAllWidgets()
	{
		// Create a compass tracker for each teammate
		for (int i = 0; i < m_TeamMateEvents.Count(); i++)
		{
			ref SgHudTeamMateEvents teamate_events = m_TeamMateEvents.Get(i);
			int player_color = Colors.GetPlayerColorByTeamSlot(i);						// Get Team Member Colour

			m_CompassTrackers.Insert(new SgUiCompassTeammateTracker( m_CompassImage, player_color, teamate_events.HudEvent_OnTeammateCompassLocationUpdate, teamate_events.HudEvent_OnTeammateStatusUpdate ));	
		}
	}	
	override protected void RegisterAllEvents()
	{
		HudEvent_OnCompassRotationUpdate.Insert(UpdateCompassDirection);
	}
	override protected void UnRegisterAllEvents()
	{
		HudEvent_OnCompassRotationUpdate.Remove(UpdateCompassDirection);
	}
	
	// -----------------------------------------------------------------
	// Compass Direction

	// Update compass image
	private void UpdateCompassDirection(float direction)
	{		
		if (m_LastDirection != direction)
		{
			m_LastDirection = direction;
		}
		m_CompassImage.SetRotation( 0, 0, m_LastDirection );							// Set Compass rotation
		m_CompassDirectionLabel.SetText( Math.Round(m_LastDirection).ToString() );		// Set Compass Direction Text
	}
}