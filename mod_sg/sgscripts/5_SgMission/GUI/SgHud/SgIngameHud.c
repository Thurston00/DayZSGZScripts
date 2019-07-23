modded class IngameHud
{
	private ref ScriptInvoker Event_OnStaminaUpdated;
	override void Init( Widget hud_panel_widget )
	{
		m_HudPanelWidget			 	= hud_panel_widget;
		m_QuickbarWidget				= m_HudPanelWidget.FindAnyWidget("QuickbarGrid");
		m_LeftHudPanelWidget			= m_HudPanelWidget.FindAnyWidget("LeftHUDPanel");
		Class.CastTo(m_Stamina, m_HudPanelWidget.FindAnyWidget("StaminaBar"));
		m_Presence						= m_HudPanelWidget.FindAnyWidget("PresencePanel");
		m_Badges						= hud_panel_widget.FindAnyWidget("BadgesPanel");
		m_Notifiers						= m_HudPanelWidget.FindAnyWidget("NotifiersPanel");
		m_BadgeNotifierDivider			= m_HudPanelWidget.FindAnyWidget("BadgeNotifierDivider");	
		m_VehiclePanel					= m_HudPanelWidget.FindAnyWidget("VehiclePanel");
		m_StancePanel					= m_HudPanelWidget.FindAnyWidget("StancePanel");
		m_ActionTarget					= m_HudPanelWidget.FindAnyWidget("ActionTargetsCursorWidget");
		m_WalkieTalkie 					= m_HudPanelWidget.FindAnyWidget("WalkieTalkie");
		
		m_ActionTarget.GetScript(m_ActionTargetsCursor);
		
		myTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		myTimer.Run( 1, this, "InitQuickbar" );
		#ifndef NO_GUI
		m_Timer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_Timer.Run(0.05, this, "RefreshQuickbar", NULL, true );
		#endif
		
		HideUnwantedDayZHud();
		ShowHudPlayer(true);
		
		
		
	}
	
	// --------------------------------------------------------
	// DAYZ TRASH
	override void SetLeftStatsVisibility(bool visible){}
	override void RefreshVehicleHud( float timeslice ){};
	override void ShowVehicleInfo(){};
	override void DisplayTendencyNormal( int key, int tendency, int status ){};
	override void DisplayTendencyTemp( int key, int tendency, int status ){};
	override void DisplayPresence(){};
	override void DisplayStance(int stance){};
	override void DisplayNotifier( int key, int tendency, int status ){};
	override void DisplayBadge( int key, int value ){};
	override void UpdateBloodName(){};
	override void SetStamina( int value , int range )
	{				
		if (Event_OnStaminaUpdated)
		{		
			Event_OnStaminaUpdated.Invoke(value, range);
			return;
		}
		else 
		{
			Event_OnStaminaUpdated = PlayerBase.Cast(GetGame().GetPlayer()).GetPlayerEvents().GetEvent_OnStaminaUpdated();
			SetStamina(value, range);
		}
	}
	override void SetStomachState( int state ){};
	override void SetTemperature( string temp ){};
	
	private void HideUnwantedDayZHud()
	{
		DeleteDayZItemAction();
		m_HudPanelWidget.FindAnyWidget("PlayerPanel").Show( false );
		m_VehiclePanel.Show(false);
		m_Stamina.Show(false);
		m_StancePanel.Show(false);
		m_Presence.Show(false);
		m_BadgeNotifierDivider.Show(false);
		m_Badges.Show(false);
		m_Notifiers.Show( false );
		
		foreach (ImageWidget image : m_StatesWidgets)
		{
			image.Show(false);						
		}
	}
	private void DeleteDayZItemAction()
	{
		Class data; 
		m_LeftHudPanelWidget.FindAnyWidget("ItemActions").GetScript(data);
		delete data;
	}
	
	// ----------------------------------------------------------
	
	override void ShowHudPlayer( bool show)
	{		
		SgUiHudBase hud = SgSManagerGui.GetSgHud();
		
		if (hud)
		{
			ShowQuickBar(show);
			
			if (show)
			{
				hud.ShowAllHUD();
			}
			else 
			{
				hud.HideAllHUD();
			}
		}
		
		super.ShowHudPlayer(show);
		
		
		m_BadgeNotifierDivider.Show(false);
		m_Badges.Show(false);
		m_Notifiers.Show( false );
	}
	
	void ToggleQuickBar( bool show, bool ignore_state = false )
	{
		if (show)
		{
			RefreshQuickbar();
		}
		m_QuickbarWidget.Show(show);
	}
	
	override void ShowHudInventory( bool show )
	{
		m_HudInventory = false;
	}
	
	override void ShowHudUI( bool show )
	{
		m_HudHideUI = !show;
		RefreshHudVisibility();
		
		SgUiHudBase hud = SgSManagerGui.GetSgHud();
		
		if (hud)
		{
			ShowQuickBar(show);
			
			if (show)
			{
				hud.ShowAllHUD();
			}
			else 
			{
				hud.HideAllHUD();
			}
		}
		
		m_BadgeNotifierDivider.Show(false);
		m_Badges.Show(false);
		m_Notifiers.Show( false );
	}
	
	override void ShowHud( bool show )
	{
		m_HudState = show;
		g_Game.SetProfileOption( EDayZProfilesOptions.HUD, show );
		RefreshHudVisibility();
		
		SgUiHudBase hud = SgSManagerGui.GetSgHud();
		
		if (hud)
		{
			ShowQuickBar(show);
			
			if (show)
			{
				hud.ShowAllHUD();
			}
			else 
			{
				hud.HideAllHUD();
			}
		}
		
		m_BadgeNotifierDivider.Show(false);
		m_Badges.Show(false);
		m_Notifiers.Show( false );
	}
	
}
