// DESIGN_ID: 0002

/*
	Base HUD player class used in a match. Have access to each UI component on a player screen. 
*/
class SgUiHudBase extends SgUiHudPanel
{
	private static ref SgUiHudBase 	HUD_BASE; 
	// Widgets
	private ref SgUiGameInfoBase	m_UiGameInfo;
	private ref SgUiCompassBase		m_UiCompass;			//SG_60:40 - Hide The Aswesome Stuff Tha tDesigners Don't Want To Have In The Game For Now
	private ref SgUiPlayerInfoBase	m_UiPlayerInfo;			//SG_60:40 - Hide The Aswesome Stuff Tha tDesigners Don't Want To Have In The Game For Now
	private ref SgUiPartyInfoBase	m_UiPartyInfo;			//SG_60:40 - Hide The Aswesome Stuff Tha tDesigners Don't Want To Have In The Game For Now
	private ref SgUiGearInfoBase	m_UiGearInfo;
	private ref SgUiContActionPanel m_UiContActionPanel;	//SG_60:40 - Hide The Aswesome Stuff Tha tDesigners Don't Want To Have In The Game For Now
	private ref array<ref SgUiHudTeammateTracker> m_UiHudTracker = new array<ref SgUiHudTeammateTracker>;
	// Events
	private ref SgHudEvents			m_HudEvents = new SgHudEvents();
	
	// ------------------------------------------------
	
	// Constructor
	private void SgUiHudBase()
	{
		BuildLayout();
	}
	// Getter
	static SgUiHudBase GetHudBase()
	{
		if (!HUD_BASE)
		{
			HUD_BASE = new ref SgUiHudBase();			
		}
		return HUD_BASE;
	}
	
	// ----------------------------------------------
	// Override --> SgUiHudPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_hud_base.layout";
	}
	override protected void LoadAllWidgets()
	{
		m_UiGameInfo 		= new SgUiGameInfoBase(FindPanel("GameInfoFrame"), m_HudEvents.HudEvent_OnZoneTimerUpdate, m_HudEvents.HudEvent_OnZonePhaseUpdate, m_HudEvents.HudEvent_OnPlayerCountUpdate);
		m_UiCompass 		= new SgUiCompassBase(FindPanel("CompassFrame"), m_HudEvents.m_TeamMateEvents, m_HudEvents.HudEvent_OnCompassRotationUpdate);
		m_UiPlayerInfo 		= new SgUiPlayerInfoBase(FindPanel("PlayerInfoFrame"), m_HudEvents.HudEvent_OnOverloadUpdate, m_HudEvents.HudEvent_OnBleedingUpdate, m_HudEvents.HudEvent_OnHealthUpdate);
		m_UiPartyInfo 		= new SgUiPartyInfoBase(FindPanel("PartyInfoFrame"), m_HudEvents.m_TeamMateEvents);	
		m_UiGearInfo 		= new SgUiGearInfoBase(FindPanel("GearInfoFrame"), m_HudEvents);
		m_UiContActionPanel = new SgUiContActionPanel(GetRootFrame());

		LoadHudTrackers();
	}
	
	// ---------------------------------------------
	
	private void LoadHudTrackers()
	{
		// Foreach teammate 
		for (int i = 0; i < m_HudEvents.m_TeamMateEvents.Count(); i++)
		{		
			ref SgHudTeamMateEvents teamate_events = m_HudEvents.m_TeamMateEvents.Get(i);
			string name 		= teamate_events.GetPlayerClient().GetUserName();
			int player_color 	= Colors.GetPlayerColorByTeamSlot(i);
			
			m_UiHudTracker.Insert(new SgUiHudTeammateTracker(GetRootFrame(), name, player_color, teamate_events.HudEvent_OnTeammateHUDMarkerLocationUpdate, teamate_events.HudEvent_OnTeammateStatusUpdate));
		}
	}
	
	// Update all components
	override void Update(float timeslice)
	{
		m_HudEvents.Update(timeslice);
	}
	
	// -------------------------------------
	// SHOW / HIDE methods
	
	///  Show all hud components
	void ShowAllHUD()
	{
		m_RootFrame.Show(true);
	}
	/// Show hidden compass component -- used when inventory is open
	void ShowCompass()
	{
		m_UiCompass.Show();
	}
	/// Hide all hud components
	void HideAllHUD()
	{
		m_RootFrame.Show(false);
	}
	/// Hide compass -- used when inventory is open
	void HideCompass()
	{
		m_UiCompass.Hide();
	}
	
	SgHudEvents GetSgHudEvents()
	{
		return m_HudEvents;
	}
}