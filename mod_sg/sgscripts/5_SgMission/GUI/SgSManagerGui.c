class SgSManagerGui
{
	protected static ref SgUiHudBase			m_SgHud;
	protected static ref SgMap					m_MapMenu;
	protected static ref SgHudCaster			m_SgHudCaster;
	protected static ref SgUiResultScreenBase 	m_ResultScreen;
	protected static ref SgUiEndScreen 			m_EndScreen;
	protected static ref SgUiUnconsciousHudBase	m_Unconscious;

	static void Init()
	{
		SgSSyncEvents.SyncEvent_OnWarmUpJoined.Insert( SyncEvent_OnWarmUpJoined );
		SgSSyncEvents.SyncEvent_OnWarmUpFinished.Insert( SyncEvent_OnWarmUpFinished );
		SgSSyncEvents.SyncEvent_OnGameStarted.Insert( SyncEvent_OnGameStarted );
		SgSSyncEvents.SyncEvent_OnPlayerReconnected.Insert( SyncEvent_OnPlayerReconnected );
		SgSSyncEvents.SyncEvent_OnPlayerDied.Insert( SyncEvent_OnPlayerDied );
		SgSSyncEvents.SyncEvent_OnPlayerUnconscious.Insert( SyncEvent_OnPlayerUnconscious );
		SgSSyncEvents.SyncEvent_OnPlayerWokeUp.Insert( SyncEvent_OnPlayerWokeUp );
		SgSSyncEvents.SyncEvent_OnTeamDeadStats.Insert( SyncEvent_OnTeamDeadStats );
	}

	//============================================
	// SyncEvent_OnWarmUpJoined
	//============================================
	static void SyncEvent_OnWarmUpJoined()
	{		
		if (SgSClientGame.GetGameState() == ESgGameState.WarmUp)
		{
			SgUiWarmUpBase.GetWarmUpBase();
		}
	}

	//============================================
	// SyncEvent_OnWarmUpFinished
	//============================================
	static void SyncEvent_OnWarmUpFinished()
	{
		SgUiWarmUpBase.ClearWarmUpBase();
		BackScreenFadeIn( 1 );
	}

	//============================================
	// SyncEvent_OnGameStarted
	//============================================
	static void SyncEvent_OnGameStarted( SgSyncGameStarted game_data )
	{
		GetGame().GetUIManager().Back();

		Print("SyncEvent_OnGameStarted");
		Print("m_PlayersUIDs Debug:");
		game_data.m_PlayersUIDs.Debug();
		Print("m_TeammateUIDs Debug:");
		game_data.m_TeammateUIDs.Debug();
		Print("---------------------------------------");
		
		SgUiWarmUpBase.ClearWarmUpBase(); // Fix for rare case when player connected just right before this event and had WarmUp GUI showed.
		BackScreenFadeOut( 1 );

		if ( SgSClientCaster.IsEnabled() )
		{
			CreateHudCaster();
		}
		else
		{
			SetMap( new SgMap );
			GetGame().GetUIManager().ShowScriptedMenu( SgSManagerGui.GetMap(), null );
			GetGame().GetUIManager().HideScriptedMenu( SgSManagerGui.GetMap() );
			
			CreateHud();
		}
	}

	//============================================
	// SyncEvent_OnPlayerReconnected
	//============================================
	static void SyncEvent_OnPlayerReconnected( SgSyncReconnected game_data_reconnect, vector currentPhasePosition )
	{
		SgSyncGameStarted game_data = new SgSyncGameStarted();
		game_data.m_TeammateUIDs = game_data_reconnect.m_TeammateUIDs;
		game_data.m_PlayersUIDs = game_data_reconnect.m_PlayersUIDs;
		
		if ( game_data_reconnect.m_GameState != ESgGameState.WarmUp)
		{
			SgUiWarmUpBase.ClearWarmUpBase();
		}
		
		SyncEvent_OnGameStarted(game_data);
	}

	//============================================
	// SyncEvent_OnGameFinished
	//============================================
	static void SyncEvent_OnGameFinished( SgSyncGameResultData result_data )
	{

	}

	//============================================
	// SyncEvent_OnPlayerDied
	//============================================
	static void SyncEvent_OnPlayerDied( string player_uid, SgDeathDetails details, int players_alive_count )
	{		
		if (player_uid == SgSClientGame.GetPlayerUID())
		{
			if (m_Unconscious)
			{
				DeleteUnconsciousHud();
			}
			
			CreateEndScreen(false);
			
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(CloseEndScreen, 5000, false);
		}
	}
	
	static void SyncEvent_OnTeamDeadStats( SgNetDataTeamResult data )
	{
		if ( data.GetRank() == 1)
		{
			CreateEndScreen(true);
			
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(CloseEndScreen, 5000, false);
			
			CreateResultScreenWithDelay( data );
		}
		else 
		{
			CreateResultScreen( data );
		}
		
	}
	
	static void SyncEvent_OnPlayerUnconscious()
	{
		CreateUnconsciousHud();
	}	
	
	static void SyncEvent_OnPlayerWokeUp()
	{
		DeleteUnconsciousHud();
	}
	

	//====================================
	// Create, open, show huds
	//====================================
	protected static void CreateHud()
	{		
		// Create hud
		m_SgHud = SgUiHudBase.GetHudBase();
		
		// Set hud
		if (GetGame().GetPlayer())
		{
			PlayerBaseClient.Cast(GetGame().GetPlayer()).SetHud(m_SgHud);
		}
	}
	
	private static void CreateUnconsciousHud()
	{
		// Hide match hud
		m_SgHud.HideAllHUD();
		// Crete unc hud
		m_Unconscious = SgUiUnconsciousHudBase.GetUnconsciousHudBase();
	}
	
	protected static void CreateEndScreen(bool is_winner /* true shows "You have won", false shows "you are dead" */ )
	{
		PPEffects.RemoveUnconsciousnessVignette();
		if (m_Unconscious)
		{
			DeleteUnconsciousHud();
		}
		m_SgHud.HideAllHUD();
		m_EndScreen = new SgUiEndScreen(is_winner);
	}
	
	protected static void CreateResultScreenWithDelay( SgNetDataTeamResult data )
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(CreateResultScreen, 5000, false, data);
	}
	
	protected static void CreateResultScreen( SgNetDataTeamResult data )
	{
		m_ResultScreen = new SgUiResultScreenBase(data);
	}
	
	static void ShowHud()
	{
		// Set hud
		if (GetGame().GetPlayer())
		{
			m_SgHud.ShowAllHUD();
		}
	}
	
	// -------------------------------------------
	// Delete, close, hide huds
	
	protected static void CloseEndScreen()
	{
		delete m_EndScreen;
		m_EndScreen = null;	
	}
	
	private static void DeleteUnconsciousHud()
	{
		// Destroy unc hud
		if (m_Unconscious)
		{
			SgUiUnconsciousHudBase.DestroyUnconsciousHudBase();
		}
		// Show match hud 
		m_SgHud.ShowAllHUD();
	}
	
	static void CloseResult()
	{
		delete m_ResultScreen;
		m_ResultScreen = null;
	}
	
	static void HideHud()
	{
		// Set hud
		if (GetGame().GetPlayer())
		{
			m_SgHud.HideAllHUD();
		}
	}

	//====================================
	// CreateHudCaster
	//====================================
	static void CreateHudCaster()
	{
		m_SgHudCaster = new SgHudCaster();
	}

	//====================================
	// GetSgHud
	//====================================
	static SgUiHudBase GetSgHud()
	{
		if (GetGame().GetPlayer())
			return m_SgHud;
		else 
			return null;
	}

	//-----------------------------------
	// Client: GetMap
	//-----------------------------------
	static SgMap GetMap()
	{
		return m_MapMenu;
	}
	
	//-----------------------------------
	// Client: GetMap
	//-----------------------------------
	static void SetMap( SgMap new_map )
	{
		m_MapMenu = new_map;
	}

	//====================================
	// GetSgHudCaster
	//====================================
	static SgHudCaster GetSgHudCaster()
	{
		return m_SgHudCaster;
	}

	//============================================
	// BackScreenFadeIn
	//============================================
	static void BackScreenFadeIn( float time )
	{
		ref SgFadeScreen screen = new SgFadeScreen( GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_fade_screen.layout", NULL ) );
		screen.FadeIn( time );
	}

	//============================================
	// BackScreenFadeOut
	//============================================
	static void BackScreenFadeOut( float time )
	{
		SgFadeScreen screen = SgFadeScreen.Cast( GetSgGame().SgGetMenu() );

		if( screen )
		{
			screen.FadeOut( time );
		}
	}
}
