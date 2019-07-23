// DESIGN_ID: 0002

/*
	SG class for a single teammate tracker in hud 
*/
class SgUiHudTeammateTracker extends SgUiHudPanel
{
	// Const
	private const int TRACKER_FADE_OUT_TIME = 60000; 
	// Widgets
	private ImageWidget	m_UiTrackerImage;
	private TextWidget  m_UiNameLabel;
	private TextWidget	m_UiDistanceLabel;
	// Data
	private int 	m_Colour;
	private string 	m_Name;
	private float 	m_LastDistance = 0;
	private bool 	m_ShowTracker = true;
	// Events
	private ref ScriptInvoker HudEvent_OnTrackerLocationUpdate;
	private ref ScriptInvoker HudEvent_OnTeammateStatusUpdate;
	
	void SgUiHudTeammateTracker(Widget parent_widget,string name, int colour, ScriptInvoker event_tracker_location_update, ScriptInvoker event_teammate_status_update)
	{
		// Data
		m_Name = name;
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
		return "mod_sg/gui/layouts/sg_hud/sg_teammate_tracker.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiTrackerImage 	= FindImage( "TrackerImage" );		
		m_UiNameLabel 		= FindLabel( "PlayerName" );	
		m_UiDistanceLabel 	= FindLabel( "Distance" );	
	}	
	override protected void LoadAllWidgets()
	{
		LoadAllTrackerIcons();
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
	
	// ----------------------------------------------------------------
	// 
	
	private void SetWidgetColour()
	{
		m_UiNameLabel.SetColor(m_Colour);
		m_UiDistanceLabel.SetColor(m_Colour);
		m_UiTrackerImage.SetColor(m_Colour);
	}
	
	// -----------------------------------------------------------------
	// TRACKER 
	private void LoadAllTrackerIcons()
	{
		m_UiTrackerImage.LoadImageFile(SgEPlayerStates.ALIVE, SgCMenuWidgetPaths.TEAMMATE_TRACKER_ICON);			// Normal icon
		m_UiTrackerImage.LoadImageFile(SgEPlayerStates.UNCONSCIOUS, SgCMenuWidgetPaths.TEAMMATE_UNCONSCIOUS_ICON);	// Unconscious icon
		m_UiTrackerImage.LoadImageFile(SgEPlayerStates.DEAD, SgCMenuWidgetPaths.TEAMMATE_DEAD_ICON);				// Dead icon
	}
	private void UpdateTrackerIcon(SgEPlayerStates teammate_state)
	{	
		if (m_ShowTracker)
		{	
			m_UiTrackerImage.SetImage(teammate_state);
			
			if ( teammate_state == SgEPlayerStates.DEAD) 									// if Dead
			{						
				m_ShowTracker = false;
				
				GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(HideTracker, TRACKER_FADE_OUT_TIME);	// Hide the tracker after 30 second
			}
		}
	}
	
	private void HideTracker()
	{
		m_RootFrame.Show(false);	// Hide tracker icon	
		UnRegisterAllEvents();		// Remove tracker even --> teammate is dead, icon is hidden and there is no point to update its location		
	}
	
	// Update tracker location
	private void UpdateTrackerLocation(float distance, vector teammate_location)
	{		
		vector relativePos = teammate_location;			
				
		relativePos[1]	=	relativePos[1] + 1.83;
		relativePos		=	GetGame().GetScreenPosRelative( relativePos );
		
		// If player camera is NOT lookig on teammate 
		if( relativePos[0] >= 1 || relativePos[0] == 0 || relativePos[1] >= 1 || relativePos[1] == 0 )
		{
			GetRootFrame().Show( false );				// Hide marker
			return;
		}
		else if( relativePos[2] < 0 )
		{
			GetRootFrame().Show( false );				// Hide marker
			return;
		}
		else
		{
			GetRootFrame().Show( true );				// Show marker
		}
		
		GetRootFrame().SetPos( relativePos[0], relativePos[1] );
		
		// Set tracker distance label and tracker size
		SetTrackerDistance(distance);
	}
	
	private void SetTrackerDistance(float distance)
	{
		// Set tracker distance label text
		float distance_diff  = 	m_LastDistance - distance;
		
		if(distance_diff > 0.25 || distance_diff < (-0.25))	
		{
			m_LastDistance = distance;
			m_UiDistanceLabel.SetText(" " + Math.Round(distance).ToString() + "m ");
			m_UiDistanceLabel.Update();
		}				
	}
}