modded class MissionGameplay
{
	private bool m_SgIsControlsLocked;
	protected ref SgSClientTimer m_ClientTimer;
	
	void SetControlLock(bool is_locked)
	{
		m_SgIsControlsLocked = is_locked;
	}
	
	void MissionGameplay()
	{
		PlayerBase.Event_OnPlayerDeath.Remove( Pause );
	}
	
	//====================================
	// override IsGame
	//====================================
	override bool IsGame()
	{
		return true;
	}
	
	//====================================
	// OnInit
	//====================================
	override void OnInit()
	{
		super.OnInit();
		
		m_ClientTimer = new SgSClientTimer;
		SgSClientGame.Init();
		SgSManagerSounds.Init();
		SgSManagerGui.Init();
		
		PPEffects.SgInit();
		
		//m_hud.Show( false ); // SG_TODO: Ivo
	}
	
	//====================================
	// OnKeyPress
	//====================================
	override void OnKeyPress(int key)
	{
		super.OnKeyPress(key);
		
		if ( key == KeyCode.KC_M )
		{
			if ( !GetGame().GetUIManager().GetMenu() )
			{
				if( !GetGame().GetUIManager().GetMenu() )
				{
					GetGame().GetUIManager().ShowScriptedMenu( SgSManagerGui.GetMap(), null );
					PlayerControlDisable(INPUT_EXCLUDE_ALL);
				}
			}
			else if ( SgSManagerGui.GetMap() == SgMap.Cast(GetGame().GetUIManager().GetMenu()) )
			{
				GetGame().GetUIManager().HideScriptedMenu( SgSManagerGui.GetMap() );
				PlayerControlEnable();
			}
		}
		
		if ( GetGame().IsServer() && key == KeyCode.KC_Q )
		{
			/*
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			PlayerIdentity id = player.GetIdentity();
			
			GetGame().SelectSpectator( id, "SgDeadcam", player.GetPosition() );
			*/
			
			
			
			ref array<string> magazines = new array<string>();
			string item_path = "cfgWeapons CZ75 magazines";

			GetGame().ConfigGetTextArray(item_path, magazines);						

			magazines.Debug();
		}			
	}
		
	override void OnUpdate(float timeslice)
	{
		UIScriptedMenu menu = m_UIManager.GetMenu();
		Input input = GetGame().GetInput();
		bool disabled_controls = m_ControlDisabled;
		
		super.OnUpdate( timeslice );
		
		if (m_SgIsControlsLocked)
		{
			PlayerControlDisable(INPUT_EXCLUDE_ALL);
		}
	}
	
	override void PlayerControlEnable()
	{		
		if ( GetGame().IsMultiplayer() )
		{
			if ( SgSClientGame.GetGameState() == ESgGameState.WarmUp && SgSClientGame.GetLocationType() == ESgLocationType.PhaseFirst )
			{
				if ( IsControlDisabled() )
				{
					PlayerControlDisable( INPUT_EXCLUDE_ALL );
					m_ControlDisabled = false;
				}	
				
				return;
			}
			
			if ( SgSClientGame.GetLocationType() == ESgLocationType.PhaseStart )
			{
				if ( IsControlDisabled() )
				{
					PlayerControlDisable( INPUT_EXCLUDE_MOVEMENT );
					m_ControlDisabled = false;
				}	
				
				return;
			}
		}
		
		super.PlayerControlEnable();
	}
	
	override void PlayerControlDisable(int mode)
	{
		switch (mode)
		{
			case INPUT_EXCLUDE_MOVEMENT:
			{
				GetUApi().ActivateExclude("movement");
				break;
			}
		}

		super.PlayerControlDisable( mode );
	}
	
	override void OnEvent(EventType eventTypeId, Param params)
	{
		super.OnEvent( eventTypeId, params);
		
		switch(eventTypeId)
		{
			case StartupEventTypeID :
			{
				Print("==========> StartupEventTypeID");
				break;
			}
			case MPSessionStartEventTypeID :
			{
				Print("==========> MPSessionStartEventTypeID");
				break;
			}
			case MPSessionEndEventTypeID :
			{
				Print("==========> MPSessionEndEventTypeID");
				break;
			}
			case MPSessionFailEventTypeID :
			{
				Print("==========> MPSessionFailEventTypeID");
				break;
			}
			case MPSessionPlayerReadyEventTypeID :
			{
				Print("==========> MPSessionPlayerReadyEventTypeID");
				
				break;
			}
			case ClientNewEventTypeID :
			{
				Print("==========> ClientNewEventTypeID");
				break;
			}
			case ClientRespawnEventTypeID :
			{
				Print("==========> ClientRespawnEventTypeID");
				break;
			}
			case ClientReadyEventTypeID :
			{
				Print("==========> ClientReadyEventTypeID");
				break;
			}
			case ClientDisconnectedEventTypeID :
			{
				Print("==========> ClientDisconnectedEventTypeID");
				break;
			}
			case LogoutCancelEventTypeID :
			{
				Print("==========> LogoutCancelEventTypeID");
				break;
			}
			case LoginTimeEventTypeID :
			{
				Print("==========> LoginTimeEventTypeID");
				break;
			}
			case MPConnectionLostEventTypeID :
			{
				Print("==========> MPConnectionLostEventTypeID");
				break;
			}		
		}
	}
	
	override void ShowInventory()
	{
		super.ShowInventory();
		
		SgUiHudBase sg_hud = SgSManagerGui.GetSgHud();
		if (sg_hud)
		{
			sg_hud.HideCompass();
		}
	}
	override void HideInventory()
	{
		super.HideInventory();
		
		SgUiHudBase sg_hud = SgSManagerGui.GetSgHud();
		if (sg_hud)
		{
			sg_hud.ShowCompass();
		}
	}
	
	override void Continue()
	{
		if ( !SgUiWarmUpBase.IsNull() )
		{
			GetUIManager().CloseMenu(MENU_INGAME);
			
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater( RestoreWarmUpUICursor, 100, false );
			return;
		}
		
		if ( SgSClientGame.GetLocationType() == ESgLocationType.PhaseStart )
		{
			GetUIManager().CloseMenu(MENU_INGAME);
			return;
		}
		
		super.Continue();
	}
	
	void RestoreWarmUpUICursor()
	{
		if ( !SgUiWarmUpBase.IsNull() )
		{
			GetGame().GetUIManager().ShowUICursor(true);
		}
	}
};