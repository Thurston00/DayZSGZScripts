// DESIGN_ID: 0002

/*
	Sg base class for hud gear panel
*/
class SgUiGearInfoBase extends SgUiHudPanel
{
	// Widget
	private 	Widget 				m_UiVestFrame;
	private 	Widget 				m_UiHelmetFrame;
	private 	ProgressBarWidget 	m_UiStamina;
	private 	Widget 				m_UiStaminaBackground;
	private 	Widget 				m_PresenceLevel0, m_PresenceLevel1,m_PresenceLevel2,m_PresenceLevel3,m_PresenceLevel4;
	private 	ImageWidget			m_UiRightSplitter;
	private 	ImageWidget 		m_UiStanceImage;
	private ref SgUiGearInfoHelmet 	m_UiHelmetInfo;
	private ref SgUiGearInfoVest 	m_UiVestInfo;
	private ref SgUiGearInfoInHands m_UiInHandsInfo;
	// Events
	private ref SgHudEvents 		m_HudEvents;
	private ref ScriptInvoker 		Event_OnArmorUpdate = new ScriptInvoker();
	
	// ----------------------------------------------------------------
	
	// Constructor
	void SgUiGearInfoBase(Widget parent_widget, ref SgHudEvents hud_events)
	{	
		m_HudEvents = hud_events;
		BuildLayout(parent_widget);
	}
	
	// ----------------------------------------------------------------
	// Overrides --> SgUiHudPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_gear_info/sg_gear_info_base.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiVestFrame		= FindPanel( "VestFrame" );
		m_UiHelmetFrame		= FindPanel( "HelmetFrame" );	
		m_UiRightSplitter 	= FindImage( "RightSplitter" );		
		m_UiStanceImage 	= FindImage( "StanceImage" );		
		m_UiStamina 		= ProgressBarWidget.Cast(FindPanel("StaminaBar"));
		m_UiStaminaBackground = FindPanel("StaminaBackground");
		m_PresenceLevel0 	= FindImage("Presence0");
		m_PresenceLevel1	= FindImage("Presence1");
		m_PresenceLevel2	= FindImage("Presence2");
		m_PresenceLevel3	= FindImage("Presence3");
		m_PresenceLevel4	= FindImage("Presence4");
		
	}
	override protected void LoadAllWidgets()
	{
		LoadStanceImages();
		m_UiHelmetInfo 	= new SgUiGearInfoHelmet(m_UiHelmetFrame, m_HudEvents.HudEvent_OnHelmetEquippedUpdate, Event_OnArmorUpdate);		//SG_60:40
		m_UiVestInfo 	= new SgUiGearInfoVest(m_UiVestFrame, m_HudEvents.HudEvent_OnVestEquippedUpdate, Event_OnArmorUpdate);				//SG_60:40
		m_UiInHandsInfo = new SgUiGearInfoInHands(FindPanel("HandFrame"), m_HudEvents.HudEvent_OnItemInHandsUpdate, m_HudEvents.HudEvent_OnFireModeUpdate, m_HudEvents.HudEvent_OnAmmoWeaponUpdate, m_HudEvents.HudEvent_OnAmmoInvnetoryUpdate);
		CheckRightSplitter();
	}	
	override protected void RegisterAllEvents()
	{
		m_HudEvents.HudEvent_OnStanceUpdate.Insert(UpdateStance);
		m_HudEvents.HudEvent_OnHelmetEquippedUpdate.Insert(CheckHelmetFrame);
		m_HudEvents.HudEvent_OnVestEquippedUpdate.Insert(CheckVestFrame);
		m_HudEvents.HudEvent_OnPresenceUpdate.Insert(UpdatePresence);
		m_HudEvents.HudEvent_OnStaminaUpdate.Insert(StaminaUpdate);
	}
	override protected void UnRegisterAllEvents()
	{
		m_HudEvents.HudEvent_OnStanceUpdate.Remove(UpdateStance);
		m_HudEvents.HudEvent_OnHelmetEquippedUpdate.Remove(CheckHelmetFrame);
		m_HudEvents.HudEvent_OnVestEquippedUpdate.Remove(CheckVestFrame);
		m_HudEvents.HudEvent_OnPresenceUpdate.Remove(UpdatePresence);
		m_HudEvents.HudEvent_OnStaminaUpdate.Remove(StaminaUpdate);
	}
	
	// ------------------------------------------------------------------
	
	// Load all possible stance icons
	private void LoadStanceImages()	
	{
		m_UiStanceImage.LoadImageFile(SgEPlayerStance.STANCE_ERECT, SgCMenuWidgetPaths.STANCE_STANCE_ICON);		// Stand
		m_UiStanceImage.LoadImageFile(SgEPlayerStance.STANCE_CROUCH, SgCMenuWidgetPaths.STANCE_CROUCH_ICON);	// Crouch
		m_UiStanceImage.LoadImageFile(SgEPlayerStance.STANCE_PRONE, SgCMenuWidgetPaths.STANCE_PRONE_ICON);		// Prone
	}
	
	// Update the stance image widget base on CharacterStance enum parameter
	private void UpdateStance(SgEPlayerStance stance)
	{		
		m_UiStanceImage.SetImage(stance);
	}

	// Update the presence 
	private void UpdatePresence(int presence_level)
	{
		m_PresenceLevel0.Show( false );
		m_PresenceLevel1.Show( false );
		m_PresenceLevel2.Show( false );
		m_PresenceLevel3.Show( false );
		m_PresenceLevel4.Show( false );

		if ( presence_level > 0 )
		{
			m_PresenceLevel0.Show( true );
		}
		if ( presence_level > 1 )
		{
			m_PresenceLevel1.Show( true );
		}
		if ( presence_level > 2 )
		{
			m_PresenceLevel2.Show( true );
		}
		if ( presence_level > 3 )
		{
			m_PresenceLevel3.Show( true );
		}
		if ( presence_level > 4 )
		{
			m_PresenceLevel4.Show( true );
		}
	}
	
	private void StaminaUpdate(float current_stamina, float percentage)
	{
		float sx, sy;
		m_UiStamina.SetCurrent( current_stamina );
		m_UiStamina.GetSize( sx, sy );
		m_UiStamina.SetSize( percentage, sy );
 	//	m_UiStaminaBackground.SetSize( 1-percentage, sy);
	}
	
	// ------------------------------------------
	// Splitters
	
	private void CheckRightSplitter()
	{
		if (m_UiVestInfo && m_UiHelmetInfo)
		{
			m_UiRightSplitter.Show(m_UiHelmetInfo.IsShown() || m_UiVestInfo.IsShown());
		}
	}
	private void CheckHelmetFrame(int helmet_level)
	{
		m_UiHelmetInfo.Show(helmet_level != 0);		
		CheckRightSplitter();
	}
	private void CheckVestFrame(int vest_level)
	{
		m_UiVestInfo.Show(vest_level != 0);		
		CheckRightSplitter();
	}
}