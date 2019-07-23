// DESIGN_ID: 0002

/*
	Class for all the events used in HUD

	SG_TODO: Pato
	1. 	✔ 	Fix Bleeding icon
	2. 	✔ 	Fix Total ammo label					 
	3. 	✔	Fix Teammate compass rotation icon
	4. 	✔	Fix Teammate health bar 
	5. 	✔	Fix Teammate name label 
	6. 	✔	Fix Vest damage colour
	7. 	✔	Fix Helmet damage colour
	8. 	✔	Refactor Item-In-Hands	(event instead of per frame check)
	9. 	✔	Refactor Fire-Mode  	(event instead of per frame check)
	11. ✔	Add Stamina progress bar
	12. ✔	Add Sound / Presnece icons
*/
class SgHudEvents 
{
	// Player Updates
	ref ScriptInvoker HudEvent_OnHealthUpdate 				= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnOverloadUpdate 			= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnBleedingUpdate 			= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnStanceUpdate				= new ScriptInvoker();
	// Game Info Updates
	ref ScriptInvoker HudEvent_OnZoneTimerUpdate 			= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnZonePhaseUpdate 			= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnPlayerCountUpdate 			= new ScriptInvoker();
	// Gear Info Updates
	ref ScriptInvoker HudEvent_OnVestEquippedUpdate			= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnHelmetEquippedUpdate		= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnStaminaUpdate				= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnPresenceUpdate				= new ScriptInvoker();
	// Weapon Updates
	ref ScriptInvoker HudEvent_OnItemInHandsUpdate			= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnAmmoInvnetoryUpdate		= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnAmmoWeaponUpdate			= new ScriptInvoker();
	ref ScriptInvoker HudEvent_OnFireModeUpdate				= new ScriptInvoker();
	// Item Action
	ref ScriptInvoker HudEvent_OnItemActionInteractUpdate	= new ScriptInvoker();	
	ref ScriptInvoker HudEvent_OnItemActionSingleUpdate		= new ScriptInvoker();	
	ref ScriptInvoker HudEvent_OnItemActionContinuousUpdate	= new ScriptInvoker();	
	// Compass Events
	ref ScriptInvoker HudEvent_OnCompassRotationUpdate 		= new ScriptInvoker();
	
	// Teammate events
	ref array<ref SgHudTeamMateEvents> m_TeamMateEvents		= new array<ref SgHudTeamMateEvents>; 
	
	// Data
	private ref 	SgPlayerClient 		m_PlayerClient;
	private 		PlayerBase 			m_PlayerBase;
	private ref 	SgPlayerBaseEvents 	m_PlayerEvents;	
	
	// Value Checks (they are used for checking if the values have been changed since last update)
	private float 		m_LastHealth			= -1;
	private int 		m_LastBleadingSource	= -1;
	private bool 		m_LastOverload			= false;
	private vector  	m_LastRotation;
	private int 		m_LastPlayerCount		= -1;
	private int 		m_LastPhase	 			= -1;
	private EntityAI 	m_LastVest;
	private bool 		m_LastVestIsRuined;
	private EntityAI 	m_LastHelmet;
	private bool 		m_LastHelmetIsRuined;
	private int 		m_LastStance			= -1;
	private string 		m_LastFireMode			= "*";
	private int 		m_LastAmmoWpn			= -1;
	private int 		m_LastAmmoInv			= -1;
	private ItemBase 	m_LastItem;
	private int 		m_LastPresenceLevel		= -1;
	
	//  check how many times are these methods called pointlessly   SG_TODO: Delete this when hud is complete 
	private int m_RepeatCounterCompass 		= 0;
	private int m_RepeatCounterBleeding 	= 0;
	private int m_RepeatCounterOverload 	= 0;
	private int m_RepeatCounterHealth 		= 0;
	private int m_RepeatCounterPlayerCount 	= 0;
	private int m_RepeatCounterPhase  		= 0;
	private int m_RepeatCounterVest			= 0;
	private int m_RepeatCounterHelmet		= 0;
	private int m_RepeatCounterStance		= 0;
	private int m_RepeatCounterFireMode		= 0;
	private int m_RepeatCounterItem			= 0;
	private int m_RepeatCounterAmmoWpn		= 0;
	private int m_RepeatCounterAmmoInv		= 0;
		
	// ------------------------------------------------------------
	
	void SgHudEvents()
	{
		m_PlayerClient 	= SgSClientGame.GetPlayer();
		m_PlayerBase 	= m_PlayerClient.GetPlayerBase();
		m_PlayerEvents 	= m_PlayerBase.GetPlayerEvents();
		
		RegisterAllClientEvents();
		RegisterAllTeammateEvents();									
	}
	void ~SgHudEvents()	
	{	
		UnRegisterAllClientEvents();
		
		// SG_TODO: Delete this when hud is complete
		Print("m_RepeatCounterCompass: " 		+ m_RepeatCounterCompass.ToString());
		Print("m_RepeatCounterHealth: " 		+ m_RepeatCounterHealth.ToString());
		Print("m_RepeatCounterOverload: " 		+ m_RepeatCounterOverload.ToString());
		Print("m_RepeatCounterBleeding: " 		+ m_RepeatCounterBleeding.ToString());
		Print("m_RepeatCounterPlayerCount: " 	+ m_RepeatCounterPlayerCount.ToString());
		Print("m_RepeatCounterPhase: " 			+ m_RepeatCounterPhase.ToString());
		Print("m_RepeatCounterVest: " 			+ m_RepeatCounterVest.ToString());
		Print("m_RepeatCounterHelmet: " 		+ m_RepeatCounterHelmet.ToString());
		Print("m_RepeatCounterStance: " 		+ m_RepeatCounterStance.ToString());
		Print("m_RepeatCounterFireMode: " 		+ m_RepeatCounterFireMode.ToString());
		Print("m_RepeatCounterItem: " 			+ m_RepeatCounterItem.ToString());
		Print("m_RepeatCounterAmmoWpn: " 		+ m_RepeatCounterAmmoWpn.ToString());
		Print("m_RepeatCounterAmmoInv: " 		+ m_RepeatCounterAmmoInv.ToString());		
	}
	
	// -------------------------------------------------------------
	
	/// Register events used in HUD
	private void RegisterAllClientEvents()
	{
		// Player info updates
		m_PlayerEvents.GetEvent_OnPlayerHit().Insert(OnPlayerHit);										// Player Hit		//SG_60:40 
		//m_PlayerEvents.GetEvent_OnOverloadUpdate().Insert(OnOverloadUpdate);							// Overload			//SG_60:40
		m_PlayerEvents.GetEvent_OnBleedingUpdate().Insert(OnBleedingUpdate);							// Bleeding			//SG_60:40
		m_PlayerEvents.GetEvent_OnHealthUpdate().Insert(OnHealthUpdate);								// Health			//SG_60:40 
		m_PlayerEvents.GetEvent_OnStaminaUpdated().Insert(OnStaminaUpdate);
		// Game info updates
		SgSClientGame.Event_OnGamePlayersAliveCount.Insert(OnPlayerCountUpdate);						// Player Count
		SgSSyncEvents.SyncEvent_OnGamePhaseChanged.Insert(OnGamePhaseUpdate);							// Phase 
		SgSClientTimer.ClientEvent_OneSecondTimerUpdate.Insert(OnRoundTimerSync);								// Round Timer
		// Gear info panel updates
		m_PlayerEvents.GetEvent_OnStanceUpdate().Insert(OnStanceUpdate);								// Player Stance
		m_PlayerBase.GetOnItemAddedToHands().Insert(OnItemInHandsAdded);								// Item in hands Added
		m_PlayerBase.GetOnItemRemovedFromHands().Insert(OnItemInHandsRemoved);							// Item in hands Removed
		m_PlayerEvents.GetEvent_OnFireModeSwiched().Insert(OnFireModeUpdate);							// Weapon fire mode
		m_PlayerClient.GetOnHelmetChangedEvent().Insert(OnHelmetUpdate);								// Helmet			//SG_60:40 
		m_PlayerClient.GetOnVestChangedEvent().Insert(OnVestUpdate);									// Vest				//SG_60:40 
	}
	/// Remove events used in HUD
	private void UnRegisterAllClientEvents()
	{
		// Player info updates
		m_PlayerEvents.GetEvent_OnPlayerHit().Remove(OnPlayerHit);										// Player Hit		//SG_60:40
		//m_PlayerEvents.GetEvent_OnOverloadUpdate().Remove(OnOverloadUpdate);							// Overload			//SG_60:40 
		m_PlayerEvents.GetEvent_OnBleedingUpdate().Remove(OnBleedingUpdate);							// Bleeding			//SG_60:40 
		m_PlayerEvents.GetEvent_OnHealthUpdate().Remove(OnHealthUpdate);								// Health			//SG_60:40 
		// Game info updates
		SgSClientGame.Event_OnGamePlayersAliveCount.Remove(OnPlayerCountUpdate);						// Player Count
		SgSSyncEvents.SyncEvent_OnGamePhaseChanged.Remove(OnGamePhaseUpdate);							// Phase 
		SgSClientTimer.ClientEvent_OneSecondTimerUpdate.Remove(OnRoundTimerSync);								// Round Timer
		// Gear info panel updates
		m_PlayerEvents.GetEvent_OnStanceUpdate().Remove(OnStanceUpdate);								// Player Stance
		m_PlayerBase.GetOnItemAddedToHands().Remove(OnItemInHandsAdded);								// Item in hands Added
		m_PlayerBase.GetOnItemRemovedFromHands().Remove(OnItemInHandsRemoved);							// Item in hands Removed
		m_PlayerEvents.GetEvent_OnFireModeSwiched().Remove(OnFireModeUpdate);							// Weapon fire ModelEntity
		m_PlayerClient.GetOnHelmetChangedEvent().Remove(OnHelmetUpdate);								// Helmet			//SG_60:40 
		m_PlayerClient.GetOnVestChangedEvent().Remove(OnVestUpdate);									// Vest				//SG_60:40 
	}
	/// Find and insert teammates events
	private void RegisterAllTeammateEvents()
	{		
		// Find team members 
		array<string> team_members = SgSClientGame.GetTeammates();										// List of team members ids	
		string player_uid = SgSClientGame.GetPlayerUID();												// Client id
		
		// For each team member 
		for (int slot = 0; slot < team_members.Count(); slot++)
		{
			string team_member_uid = team_members[slot];												// Team member ID 
			// if team member id is different than client id
			if ( team_member_uid != player_uid )
			{
				// Get teammate client
				SgPlayerClient teammate = SgSClientGame.GetPlayerByUID(team_member_uid);	
				if (teammate)
				{													
					// Init their hud events 
					m_TeamMateEvents.Insert(new SgHudTeamMateEvents(teammate));	
				}
			}
		}
	}
	
	// --------------------------------------------------------------
	// UPDATES
	
	// Per-Frame Update --------------------------------------------
	void Update(float time_slice)
	{
		// Compass
		OnUpdateCompass(GetGame().GetCurrentCameraDirection());							//SG_60:40 - Hide The Aswesome Stuff Tha tDesigners Don't Want To Have In The Game For Now
		// Sound
		OnPresenceUpdate();
		// Markers
		foreach (SgHudTeamMateEvents teammate : m_TeamMateEvents)
		{		
			teammate.UpdateTeammate(SgSClientGame.GetPlayer().GetPosition());
		}
		
		// Temp solution --> should be called as an event insted
		Weapon_Base weapon_in_hands = Weapon_Base.Cast( m_PlayerBase.GetHumanInventory().GetEntityInHands());
		
		if (weapon_in_hands)
		{
			// Temp solution --> should be called as an event insted
			OnAmmoWeaponUpdate(weapon_in_hands.GetClipAmmo());
			// Temp solution --> should be called as an event insted
			OnAmmoInventoryUpdate(weapon_in_hands.GetAllInventoryAmmo());
		}
	}
	
	// -------------------------------------------------------------
	// TEMPORAL GETTERS --> hopefully most of these getters will be on the correct items in a future 
	
	/*								SG_TODO: PATO --> this needs to be as a getter on a item !!!! 
	/ Desc: 	Get armor level of the passed vest
	/ Param1: 	EntityAI 	-> the vest that will be checked 
	/ Return:  	int 		-> vest armor level
	*/
	private int GetVestArmorLevel(EntityAI vest)
	{
		int armor_lvl;	
		array<string> vest_name = new array<string>;
		vest.GetType().Split("_", vest_name);
		// Allocate level
		switch(vest_name[0])
		{
			case "PoliceVest":
			{
				armor_lvl = 1;
				break;
			} 
			case "PressVest":
			{
				armor_lvl = 2;
				break;
			}
			case "PlateCarrierVest":
			{
				armor_lvl = 3;
				break;
			}
			default:
			{
				armor_lvl = 0;
				break;
			}
		}
		return armor_lvl;
	}	
	/*								SG_TODO: PATO --> this needs to be as a getter on a item !!!! 
	/ Desc: 	Get armor level of the passed helmet
	/ Param1: 	EntityAI 	-> the helmet that will be checked 
	/ Return:  	int 		-> helmet armor level
	*/
	private int GetHelmetArmorLevel(EntityAI helmet)
	{		
		int armor_lvl;	
		array<string> helmet_name = new array<string>;
		helmet.GetType().Split("_", helmet_name);
		// Allocate level
		switch(helmet_name[0])
		{
			case "MotoHelmet":
			{
				armor_lvl = 1;
				break;
			} 
			case "GorkaHelmet":
			{
				armor_lvl = 2;
				break;
			}
			case "BallisticHelmet":
			{
				armor_lvl = 3;
				break;
			}
			default:
			{
				armor_lvl = 0;
				break;
			}
		}
		return armor_lvl;
	}
	
	// Event Invokes --------------------------------------------------
	 
	/// Called every time a client player is hit
	private void OnPlayerHit()
	{
		OnHelmetUpdate(m_PlayerClient.GetEquippedHelmet());					// Check Helmet
		OnVestUpdate(m_PlayerClient.GetEquippedHelmet());					// Check Armor
	}
	private void OnUpdateCompass(vector rotation)
	{	
		if (m_LastRotation != rotation)
		{
			m_LastRotation = rotation;
			float direction	= 360.0 - rotation.VectorToAngles()[0];			
			HudEvent_OnCompassRotationUpdate.Invoke(direction);
		}
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterCompass++;
		}
	}
	private void OnHealthUpdate(float health)
	{
		if (m_LastHealth != health)
		{
			m_LastHealth = health;
			HudEvent_OnHealthUpdate.Invoke( health );
		}	
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterHealth++;
		}
	}
	private void OnOverloadUpdate(bool is_overloaded )
	{
		if (m_LastOverload != is_overloaded)
		{		
			m_LastOverload = is_overloaded;
			HudEvent_OnOverloadUpdate.Invoke(is_overloaded);
		}		
		else // SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterOverload++;
		}
	}
	private void OnBleedingUpdate(int bleeding_sources)
	{
		if (m_LastBleadingSource != bleeding_sources)
		{
			m_LastBleadingSource = bleeding_sources;
			HudEvent_OnBleedingUpdate.Invoke(bleeding_sources);
		}
		else // SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterBleeding++;
		}
	}
	private void OnPlayerCountUpdate(int player_count)
	{
		if (m_LastPlayerCount != player_count)
		{
			m_LastPlayerCount = player_count;		
			HudEvent_OnPlayerCountUpdate.Invoke(player_count);
		}
		else // SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterPlayerCount++;
		}
	}	
	private void OnGamePhaseUpdate(ESgGameState phase_type, ESgLocationType location_type)
	{
		if (m_LastPhase != phase_type)
		{
			m_LastPhase = phase_type;		
			HudEvent_OnZonePhaseUpdate.Invoke(phase_type, location_type);
		}
		else // SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterPhase++;
		}
	}
	private void OnRoundTimerSync(int time)
	{
		int mins = Math.Floor(time / 60);
		int secs = time - (60 * mins);

		string time_string = string.Format("%1:%2", mins.ToStringLen(2), secs.ToStringLen(2));
		HudEvent_OnZoneTimerUpdate.Invoke(time_string);
	}
	private void OnStanceUpdate(SgEPlayerStance stance)
	{
		if (m_LastStance != stance)
		{
			m_LastStance = stance;
			
			HudEvent_OnStanceUpdate.Invoke(stance);
		}
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterStance++;
		}		
		
	}
	private void OnVestUpdate(EntityAI vest)
	{
		bool vest_is_ruined; 
		if (vest)
		{
			vest_is_ruined = vest.IsRuined();
		}
		
		if (m_LastVest != vest || m_LastVestIsRuined == vest_is_ruined )
		{
			m_LastVest = vest;
			m_LastVestIsRuined = vest_is_ruined;
			
			int vest_level; 
			if (vest)
			{
				vest_level = GetVestArmorLevel(vest);
			}
			HudEvent_OnVestEquippedUpdate.Invoke(vest_level, vest_is_ruined);
		}	
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterVest++;
		}
	}
	private void OnHelmetUpdate(EntityAI helmet)
	{
		bool helmet_is_ruined;
		if (helmet)
		{
			helmet_is_ruined = helmet.IsRuined();
		}
			
		if (m_LastHelmet != helmet || m_LastHelmetIsRuined == helmet_is_ruined)
		{
			m_LastHelmet = helmet;
			m_LastHelmetIsRuined = helmet_is_ruined;
			
			int helmet_level;
			if (helmet)
			{
				helmet_level = GetHelmetArmorLevel(helmet);			
			}
			HudEvent_OnHelmetEquippedUpdate.Invoke(helmet_level, helmet_is_ruined);
		}
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterHelmet++;
		}	
	}
	private void OnItemInHandsAdded(ItemBase item)
	{
		if (m_LastItem != item)
		{
			m_LastItem = item;
			HudEvent_OnItemInHandsUpdate.Invoke(item);
			OnFireModeUpdate(m_PlayerBase.GetCurrentWeaponMode());
		}
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterItem++;
		}	
	}
	private void OnItemInHandsRemoved()
	{
		if (m_LastItem != null)
		{
			m_LastItem = null;
			HudEvent_OnItemInHandsUpdate.Invoke(null);
		}
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterItem++;
		}	
	}
	private void OnFireModeUpdate(string mode)
	{		
		if (m_LastFireMode != mode)
		{
			m_LastFireMode = mode;	     
			HudEvent_OnFireModeUpdate.Invoke(mode);
		}
		else // SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterFireMode++;
		}  
	}
	private void OnAmmoWeaponUpdate(int ammo)
	{
		if (m_LastAmmoWpn != ammo)
		{
			m_LastAmmoWpn = ammo;
			HudEvent_OnAmmoWeaponUpdate.Invoke(ammo);
		}
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterAmmoWpn++;
		}	
	}	
	private void OnAmmoInventoryUpdate(int ammo)
	{
		if (m_LastAmmoInv != ammo)
		{
			m_LastAmmoInv = ammo;
			HudEvent_OnAmmoInvnetoryUpdate.Invoke(ammo);
		}
		else 	// SG_TODO: Delete this when finished with hud
		{
			m_RepeatCounterAmmoInv++;
		}	
	}
	private void OnStaminaUpdate(int value, int range)
	{
		float max = GameConstants.STAMINA_MAX;
		float percentage = range / max;
		float current_stamina = ( value / range ) * 100;
		
		HudEvent_OnStaminaUpdate.Invoke(current_stamina, percentage);
	}
	private void OnPresenceUpdate()
	{
		PlayerBase player;

		if ( Class.CastTo(player, GetGame().GetPlayer()) )
		{
			int presence_level = player.GetNoisePresenceInAI();
			
			
			if (presence_level != m_LastPresenceLevel)
			{
				m_LastPresenceLevel = presence_level;
				
				HudEvent_OnPresenceUpdate.Invoke(presence_level);
			}
		}
	}
}