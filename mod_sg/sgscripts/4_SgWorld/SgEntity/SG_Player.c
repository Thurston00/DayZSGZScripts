modded class PlayerBase
{
	protected ref SgPlayer			m_SgPlayer;
	protected int					m_AreaLeaveTime;
	protected vector				m_LockPosition;
	protected bool					m_IsLockPosition;
	
	protected float					m_StomachVolume;
	protected float 				m_ClientHealth;
	
	protected ref Timer				m_TimerXX;
	protected Roadflare				m_TestFlare;
	protected Shape					m_TestSphere;
	protected bool					m_IsGameStarted;	
	
	protected bool 					m_IsOverloaded;
	protected SgEPlayerStates 		m_PlayerState;
	
	protected ref SgPlayerBaseEvents	m_PlayerEvents = new SgPlayerBaseEvents();	
	
	protected ref TStringArray m_DamageZones = new TStringArray;
		
//----------------------------------------------------------------------------------------	
//----------------------------------------------------------------------------------------
// Server/Client
//----------------------------------------------------------------------------------------	
//----------------------------------------------------------------------------------------
	
	//===================================
	// Server: Constructor
	//===================================
	void PlayerBase()
	{
		if ( GetSgGame().IsServer() )
		{
			GetGame().GetUpdateQueue(CALL_CATEGORY_GAMEPLAY).Insert(this.SgUpdateFrame); // SG_TODO: Why not to use existing EOnFrame? Also using this solution remove on game start or sth like this and not only on Destroy.
		}

		RegisterNetSyncVariableFloat("m_ClientHealth");
		
		m_StomachVolume = 0;
		RegisterNetSyncVariableFloat("m_StomachVolume", 0, SG_STOMACH_CAPACITY, 0);
		
		if( GetGame().IsMultiplayer() && !GetGame().IsServer() )
		{
			SgSSyncEvents.SyncEvent_OnPlayerMoveLockChanged.Insert( LockMovement );
		}
		
		m_ClientHealth = GetMaxHealth("GlobalHealth", "Health");
		
		SgSManagerEventsServer.Event_OnGameStarted.Insert( Event_OnGameStarted );
		
		GetDamageZones( m_DamageZones );
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		RemoveAction(ActionDrinkPondContinuous);
	}
	
	override void EOnFrame(IEntity other, float timeSlice)
	{
		if ( GetSgGame().IsServer() )
		{
			float health = GetHealth("GlobalHealth","Health");
			if ( m_ClientHealth != health )
			{
				m_ClientHealth = health;
				SetSynchDirty();
			}
		}
	}
	
	SgPlayerBaseEvents GetPlayerEvents()
	{
		return m_PlayerEvents;
	}
	
 	// SG_TODO: SG-929
	override void EOnPostFrame(IEntity other, int extra)
	{
		if ( GetSgGame().IsClient() )
		{
			SgSClientGame.PostFrameUpdate();
		}
	}
	
	// -------------------------------------------------------------------------------
	override void EOnInit(IEntity other, int extra)
	{
		super.EOnInit( other, extra );
		
		Print(GetGame().GetTime().ToString() +" - PlayerBase EOnInit");
	}


	//===================================
	// GetTeam // SG_TODO: Delete (problems with caster)
	//===================================
	SgTeam GetTeam()
	{
		return m_SgPlayer.GetTeam();
	}
	
	//===================================
	// GetHealth
	//===================================
	float GetClientHealth()
	{
		return m_ClientHealth;
	}
	
	//===================================
	// TestBone
	//===================================
	void TestBone()
	{
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		set<Object> hit_object = new set<Object>;
		if ( GetSgGame().IsServer() )
		{
			if( !m_TestFlare )
			{
				m_TestFlare = Roadflare.Cast( GetGame().CreateObject( "Roadflare", GetPosition() ) );
			}
			int bone_index = GetBoneIndexByName("Head");
			vector pos, orient;
			if (bone_index != -1)
			{
				float quat[4];
				vector from	= GetBonePositionWS( bone_index );
				GetBoneRotationWS( bone_index, quat );
				vector to   = from + ( Math3D.QuatToAngles( quat ) ).AnglesToVector();
			}
			if( m_TestSphere )
			{
				m_TestSphere.Destroy();
			}
			m_TestSphere = Debug.DrawLine( from, to );
		}
		else
		{
			vector from2	= GetGame().GetCurrentCameraPosition();
			vector to2   	= from2 + GetGame().GetCurrentCameraDirection() * 5;			
			
			DayZPhysics.RaycastRV( from2, to2, contact_pos, contact_dir, contact_component, hit_object, this );
			if( m_TestSphere )
			{
				m_TestSphere.Destroy();
			}
			m_TestSphere = Debug.DrawSphere( contact_pos );
			
		}
	}
	
	//===================================
	// Server: Destructor
	//===================================
	void ~PlayerBase()
	{
		if ( GetSgGame() && GetSgGame().IsServer() )
		{
			GetGame().GetUpdateQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.SgUpdateFrame);
		}
	}
	
	override void InitEditor()
	{
		if ( GetGame().IsDebug() )
		{
			if ( !GetGame().IsMultiplayer()  &&  GetGame().GetPlayer()  &&  GetGame().GetPlayer().GetID() == this.GetID() )
			{
				if( GetSgGame().GetPlaygroundID() > -1 )
				{
					SgPluginPgEditor.GetInstance().LoadPlayground( GetSgGame().GetPlaygroundID() );
					SgPluginPgEditor.GetInstance().EditorToggle();
				}
				else
				{
					GetSgGame().SetPlaygroundID( PluginConfigDebugProfile.GetInstance().GetDefaultPlayground() );
					//SgPluginPgEditor.GetInstance().LoadPlayground( GetSgGame().GetPlaygroundID() );
					SgPluginPgEditor.GetInstance().EditorToggle();
				}
			}
		}
	}
	
	//===================================
	// Client: override OnPlayerLoaded
	//===================================
	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();
	}	

	//===================================
	// Server: SetPlayerStomachVolume
	//===================================
	void SetStomachVolume( float volume )
	{
		m_StomachVolume = volume;
		SetSynchDirty();
	}
	
	//===================================
	// Server/Client: GetPlayerStomachVolume
	//===================================
	float GetStomachVolume()
	{
		return m_StomachVolume;
	}

	//===================================
	// Server: SetPlayerBledOut
	//===================================
	void SetPlayerBledOut()
	{
		ProcessUnconsciousness();
		
		if ( GetCanBeDestroyed() )
		{
			SetHealth("GlobalHealth", "Health", 0);
		}
		
		//Analytics
		if ( GetSgGame().IsServer() )
		{
			GetSgGame().GetAnalyticsServer().SendUnconsciousnessEvent( this, null );
		}
	}
	
	//===================================
	// Server: ProcessUnconsciousness
	//===================================
	void ProcessUnconsciousness()
	{
		if ( SgSManagerPlayers.GetTeamByID(m_SgPlayer.GetTeamID()).CanPlayerGoUnconscious() == false || IsUnconscious() )
		{
			SetCanBeDestroyed(true);
		}
		
		if ( GetCanBeDestroyed() == false )
		{
			m_BleedingManagerServer.EnableAddingNewBleedingSources(false);
			m_BleedingManagerServer.RemoveAllSources();
			DayZPlayerSyncJunctures.SendPlayerUnconsciousness(this, true);
			SetHealthEntirePlayer( GetMaxHealth("GlobalHealth", "Health") );
		}
	}
	
	//===================================
	// EEFired // SG_TODO: It was removed from EntityAI in DayZ
	//===================================
	void EEFired( int muzzleType, int mode, string ammoType )
	{		
		//super.EEFired( muzzleType, mode, ammoType );
		
		if ( GetSgGame().IsServer() )
		{
			SgSMatchRecorder.OnPlayerFired(this);
		}
	}
	
	//===================================
	// override EEHitBy
	//===================================
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos)
	{
		if ( GetHealth("","") == 0 && GetCanBeDestroyed() == false )
		{
			if ( dmgZone == "Brain" || dmgZone == "Head" )
			{
				EntityAI head = GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Headgear"));
				
				if ( !( head != null && head.GetHealthLevel() != 4 && GetGame().ConfigGetFloat( "CfgVehicles " + head.GetType() + " DamageSystem " + "GlobalArmor " + "immunityHeadshotInstantKill" ) ) )
				{
					SetCanBeDestroyed(true);	
				}
				else
				{
					ProcessUnconsciousness();
					
					//Analytics
					if ( GetSgGame().IsServer() )
					{
						GetSgGame().GetAnalyticsServer().SendUnconsciousnessEvent( this, source );
					}
				}
			}
			else
			{
				ProcessUnconsciousness();
				
				//Analytics
				if ( GetSgGame().IsServer() )
				{
					GetSgGame().GetAnalyticsServer().SendUnconsciousnessEvent( this, source );
				}
			}
		}
		
		super.EEHitBy( damageResult, damageType, source, component, dmgZone, ammo, modelPos);
				
		if ( GetSgGame().IsServer() )
		{							
			//Compoment51 in the firegeometry of bodyparts_above0 is reserver for the collar
			if ( GetActionComponentName( component, "fire") == "component51" )
			{
				if ( !source.IsInherited( SG_CollarItem ) && source.IsWeapon() )
				{
					if ( GetSgPlayer() && GetSgPlayer().GetSG_Collar() )
					{
						GetSgPlayer().GetSG_Collar().CollarExplode();
					}
				}
			}
			
			//Analytics
			GetSgGame().GetAnalyticsServer().AddHitEvent( this, source );
		}
	}
	
	//====================================
	// Server: EEKilled
	//====================================
	override void EEKilled(Object killer)
	{
		super.EEKilled( killer );
		
		if ( !GetGame().IsMultiplayer() ) { return; }
		
		SgDeathDetails details = new SgDeathDetails();
		
		if ( killer != null )
		{
			if ( killer.IsInherited( EntityAI ) )
			{
				EntityAI parent = EntityAI.Cast( killer ).GetHierarchyRootPlayer();
				PlayerBase item_owner = PlayerBase.Cast( parent );
				
				if ( item_owner && item_owner.IsInherited( PlayerBase ) && !killer.IsInherited( SG_CollarItem ) )
				{
					PlayerBase player = PlayerBase.Cast( item_owner );
					
					details.m_Reason = ESgDeathReason.Player;				
					details.m_KillerUID = player.GetIdentity().GetId();
				}
				else if ( killer.IsInherited( SG_CollarItem ) )
				{
					details.m_Reason = ESgDeathReason.Collar;
					details.m_KillerUID = SG_UID_PLACEHOLDER;
				}
			}
		}
		
		SgSManagerPlayers.GetTeamByID(m_SgPlayer.GetTeamID()).OnTeamPlayerDied(this);
		SgSManagerEventsServer.Event_OnSgPlayerDied(this.GetSgPlayer(), details);
		
		//Analytics
		GetGame().GetAnalyticsServer().SendDeathEvent( this, killer, details.m_Reason );
	}
	
	//====================================
	// Server: LockMovement
	//====================================
	void LockMovement( bool lock )
	{
		if ( GetSgGame().SgIsServerMP() )
		{
			m_LockPosition		= GetPosition();
			m_IsLockPosition	= lock;
		}
		else
		{
			if( lock )
			{
				GetGame().GetInput().ChangeGameFocus( 1, INPUT_DEVICE_KEYBOARD );
			}
			else
			{
				GetGame().GetInput().ResetGameFocus();
				GetGame().GetInput().ChangeGameFocus( -1, INPUT_DEVICE_KEYBOARD );
			}
		}
	}
	
	//====================================
	// GetAreaLeaveTime
	//====================================
	int GetAreaLeaveTime()
	{
		if ( GetSgGame().IsServer() )
		{
			return m_AreaLeaveTime;
		}
		return -1;
	}
	
	//====================================
	// Server: IsInArea
	//====================================
	bool IsInArea()
	{
		if ( GetSgGame().IsServer() )
		{
			return ( GetAreaLeaveTime() == -1 );
		}
		return true;
	}
	
	//====================================
	// Server: SetLeaveAreaTime
	//====================================
	void SetLeaveAreaTime(int leave_time)
	{
		if ( GetSgGame().IsServer() )
		{
			m_AreaLeaveTime = -1;
		}
	}
	
	//====================================
	// Server: SetGodMod
	//====================================
	void SetGodMod(bool is_god_mod)
	{
		if ( GetSgGame().IsServer() )
		{
			SetAllowDamage( !is_god_mod );
		}
	}
	
	//===================================
	// Override Consume
	//===================================
	override bool Consume(ItemBase source, float amount, EConsumeType consume_type )
	{
		if ( super.Consume( source, amount, consume_type ) == false )
		{
			return false;
		}
		
		if( consume_type == EConsumeType.ITEM_SINGLE_TIME || consume_type == EConsumeType.ITEM_CONTINUOUS )
		{
			if(source)
			{
				ProcessMedicals( source.GetMedicalProfile(), amount );
			}		
		}
		
		//Analytics
		if ( source.IsFood() )
		{
			GetSgGame().GetAnalyticsServer().AddFoodConsumeEvent( this, source );
		}
		
		return true;
	}
	
	void ProcessMedicals( MedicalProfile profile, float consumedquantity )
	{
		float percentage_heal = consumedquantity * profile.GetPercentageHeal();
		
		AddHealthEntirePlayer( percentage_heal );
	}
	
	void AddHealthEntirePlayer( float percentage_heal )
	{
		int max_health = GetMaxHealth("GlobalHealth", "Health");
		float heal_amount = ( max_health / 100 ) * percentage_heal;
		
		AddHealth( "GlobalHealth", "Health", heal_amount );
		
		for ( int i = 0; i < m_DamageZones.Count(); i++ )
		{
			AddHealth( m_DamageZones.Get(i), "Health", heal_amount );
		}
	}
	
	void SetHealthEntirePlayer( float set_health )
	{
		AddHealth( "GlobalHealth", "Health", set_health );
		
		for ( int i = 0; i < m_DamageZones.Count(); i++ )
		{
			AddHealth( m_DamageZones.Get(i), "Health", set_health );
		}
	}
	
	//===================================
	// Override SetActionsRemoteTarget
	//===================================
	override void SetActionsRemoteTarget()
	{
		super.SetActionsRemoteTarget();
		RemoveAction(ActionCPR);
	}

	//==================================
	// Event_OnGameStarted
	//==================================
	void Event_OnGameStarted()
	{
		m_IsGameStarted = true;
	}
	
	//==================================
	// OnScheduledTick
	//==================================
	override void OnScheduledTick( float deltaTime )
	{
		if( m_IsGameStarted )
		{
			super.OnScheduledTick( deltaTime );
		}
	}

	//----------------------------------
	// CheckPositions
	//----------------------------------
	protected void SgUpdateFrame(float delta)
	{
		if ( m_IsLockPosition )
		{
			SetPosition(m_LockPosition);
		}
	}
	
	// ----------------------------------
	// CLIENT GETTERS 
	
	SgPlayer GetSgPlayer()
	{
		return m_SgPlayer;
	}
	bool IsPlayerOverloaded()
	{
		return m_IsOverloaded;
	}
	override SgEPlayerStates GetPlayerState()
	{
		return m_PlayerState;
	}
	
	// ----------------------------------
	// CLIENT SETTERS
	
	void SetSgPlayer( SgPlayer sg_player )
	{
		m_SgPlayer = sg_player;		
	}
	void SetPlayerOverload(bool is_overloaded)
	{
		// Set value
		m_IsOverloaded = is_overloaded;
		
		// Notify all listeners - Overload
		m_PlayerEvents.GetEvent_OnOverloadUpdate().Invoke(m_IsOverloaded);
	}
	void SetPlayerState(SgEPlayerStates player_state)
	{
		// Set Value
		m_PlayerState = player_state;
		
		// Notify all listeners - Player State
		m_PlayerEvents.GetEvent_OnStateUpdate().Invoke(m_PlayerState);
	}
	
	// -------------------------------------------------------------------
	// Overrided methods to support events 
	
	override void OnVariablesSynchronized() 
	{
		// Base Method
		super.OnVariablesSynchronized();
			
		// Notify - Health
		m_PlayerEvents.GetEvent_OnHealthUpdate().Invoke(GetClientHealth());
	}	
	override void SetPlayerLoad(float load)
	{
		// Base method
		super.SetPlayerLoad(load);
		
		// Set - Overload
		SetPlayerOverload(IsOverloaded());
	}
	override void OnPlayerRecievedHit()
	{
		// Base method
		super.OnPlayerRecievedHit();
	
		// Notify - Player Hit
		m_PlayerEvents.GetEvent_OnPlayerHit().Invoke();
	
		// Set - Player State
		if (!IsAlive())
		{
			SetPlayerState(SgEPlayerStates.DEAD);
		}
	}
	override void OnUnconsciousStart()
	{
		// Base method
		super.OnUnconsciousStart();
		
		SgSSyncEvents.SyncEvent_OnPlayerUnconscious.Invoke();
	
		// Set - Player State
		SetPlayerState(SgEPlayerStates.UNCONSCIOUS);
		
	}
	override void OnUnconsciousStop(int pCurrentCommandID)
	{
		// Base method
		super.OnUnconsciousStop(pCurrentCommandID);
		
		SgSSyncEvents.SyncEvent_OnPlayerWokeUp.Invoke();
		
		// Set - Player State
		if (IsAlive())
		{
			SetPlayerState(SgEPlayerStates.ALIVE);
		}
		else 
		{
			SetPlayerState(SgEPlayerStates.DEAD);
		}
	}	
	override void OnBleedingSourceAdded()
	{
		// Base method
		super.OnBleedingSourceAdded();
		
		// Notify - Bleeding
		m_PlayerEvents.GetEvent_OnBleedingUpdate().Invoke(m_BleedingSourceCount);
	}
	override void OnBleedingSourceRemoved()
	{
		// Base method
		super.OnBleedingSourceRemoved();
		
		// Notify - Bleeding
		m_PlayerEvents.GetEvent_OnBleedingUpdate().Invoke(m_BleedingSourceCount);
	}
	
	//==================================
	// Inventory
	//==================================	
	override void OnItemInventoryEnter( EntityAI item )
	{
		super.OnItemInventoryEnter( item );
		
		if ( GetSgGame().IsServer() )	
		{
			GetSgGame().GetAnalyticsServer().AddPickUpEvent( this, item );
		}
	}		
}