// DESIGN_ID: 0002

/*
	SG class for a single teammate tracker in a compass 
*/
class SgUiCompassTeammateTracker extends SgUiHudPanel
{
	private const float COMPASS_DISTANCE_TRESHOLD = 50;
	
	// Widgets
	private ImageWidget	m_UiTrackerImage;
	// Data
	private int m_Colour;
	// Events
	private ref ScriptInvoker HudEvent_OnTrackerLocationUpdate;
	private ref ScriptInvoker HudEvent_OnTeammateStatusUpdate;

	void SgUiCompassTeammateTracker(Widget parent_widget, int colour, ScriptInvoker event_tracker_location_update, ScriptInvoker event_teammate_status_update)
	{
		m_Colour = colour;
		// Event
		HudEvent_OnTrackerLocationUpdate = event_tracker_location_update;
		HudEvent_OnTeammateStatusUpdate = event_teammate_status_update;
		// Build
		BuildLayout(parent_widget);
	}
	
	// ----------------------------------------------------------------
	// Overrides --> SgUiHudPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_compass/sg_compass_tracker.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiTrackerImage = ImageWidget.Cast(GetRootFrame());
	}
	override protected void LoadAllWidgets()
	{
		SetWidgetColour();
	}	
	override protected void RegisterAllEvents()
	{
		HudEvent_OnTrackerLocationUpdate.Insert(UpdateTrackerLocation);
		HudEvent_OnTeammateStatusUpdate.Insert(UpdateTrackerIcon);
	}
	override protected void UnRegisterAllEvents()
	{
		HudEvent_OnTrackerLocationUpdate.Remove(UpdateTrackerLocation);
		HudEvent_OnTeammateStatusUpdate.Remove(UpdateTrackerIcon);
	}
	
	// -----------------------------------------------------------------
	// Tracker Location

	// Update compass image
	private void UpdateTrackerLocation(float distance, vector offset, float roatation)
	{	
		// Set rotation
		if ( distance > COMPASS_DISTANCE_TRESHOLD )
		{
			offset.Normalize();	
			offset = offset * COMPASS_DISTANCE_TRESHOLD;
			m_UiTrackerImage.SetRotation( 0, 0, roatation );
		}
		else
		{
			m_UiTrackerImage.SetRotation( 0, 0, roatation );
		}	
		
		// Set position
		float widget_x_pos	= offset[0] / 150;
		float widget_y_pos	= offset[2] / 150;
		m_UiTrackerImage.SetPos(widget_x_pos, -widget_y_pos);
	}
	
	// ------------------------------------------------------------------
	// Tracker Icon
	private void LoadAllTrackerIcons()
	{
		m_UiTrackerImage.LoadImageFile(SgEPlayerStates.ALIVE, SgCMenuWidgetPaths.COMPASS_TEAMMATE_ICON);			// Normal icon
		m_UiTrackerImage.LoadImageFile(SgEPlayerStates.UNCONSCIOUS, SgCMenuWidgetPaths.TEAMMATE_UNCONSCIOUS_ICON);	// Unconscious icon
		m_UiTrackerImage.LoadImageFile(SgEPlayerStates.DEAD, SgCMenuWidgetPaths.TEAMMATE_DEAD_ICON);				// Dead icon
	}
	private void UpdateTrackerIcon(SgEPlayerStates teammate_state)
	{	
		m_UiTrackerImage.SetImage(teammate_state);
			
		if ( teammate_state == SgEPlayerStates.DEAD) 									// if Dead
		{			
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(HideTrakcer, 30000);	// Hide the tracker after 30 seconds
		}
		else 
		{
			m_UiTrackerImage.Show(true);
		}
	}
	private void HideTrakcer()
	{ 
		m_UiTrackerImage.Show(false);													// Hide tracker icon
		HudEvent_OnTrackerLocationUpdate.Remove(UpdateTrackerLocation);					// Remove tracker even --> teammate is dead and there is no point to update his location
	}
	private void SetWidgetColour()
	{
		m_UiTrackerImage.SetColor(m_Colour); 
	}
}

















