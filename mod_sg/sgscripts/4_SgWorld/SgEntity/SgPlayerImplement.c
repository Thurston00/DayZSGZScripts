modded class DayZPlayerImplement
{	
	protected bool 			m_ContinuousLoadMagazineFinished;
	protected Weapon_Base 	m_ReEquipWeapon;
	protected Magazine 		m_ReAttachMagazine;
	
	override void ShowDeadScreen( bool show, float duration )
	{
		
	}
	
	override void SimulateDeath(bool state)
	{
		if (g_Game.GetMissionState() != DayZGame.MISSION_STATE_GAME)
		{
			return;
		}
		//Print("Calling simulate death in state: " + state)
		//controlls
		LockControls(state);
		
		//video
		//ShowDeadScreen(state);
		
		GetGame().GetSoundScene().SetSoundVolume(g_Game.m_volume_sound,1);
		GetGame().GetSoundScene().SetSpeechExVolume(g_Game.m_volume_speechEX,1);
		GetGame().GetSoundScene().SetMusicVolume(g_Game.m_volume_music,1);
		GetGame().GetSoundScene().SetVOIPVolume(g_Game.m_volume_VOIP,1);
		GetGame().GetSoundScene().SetRadioVolume(g_Game.m_volume_radio,1);
	}
		
	//-------------------------------------------------------------
	//!
	//! Event Processing
	//! 

	override void OnStepEvent(string pEventType, string pUserString, int pUserInt)
	{
		/*
		Print(pEventType);
		Print(pUserString);
		Print(pUserInt);
		Print("-----------------------------");
		*/
		DayZPlayerType type = GetDayZPlayerType();
		ref HumanMovementState	state = new HumanMovementState();
		GetMovementState(state);

		/*
		if(pUserString == "walk")
			state.m_iMovement = DayZPlayerConstants.MOVEMENTIDX_WALK;
		else if(pUserString == "run")
			state.m_iMovement = DayZPlayerConstants.MOVEMENTIDX_RUN;
		else if(pUserString == "sprint")
			state.m_iMovement = DayZPlayerConstants.MOVEMENTIDX_SPRINT;
		
		if (state.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_CROUCH || state.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDCROUCH || state.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_PRONE || state.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDPRONE)
			state.m_iMovement--;
		*/
		
		if(GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			DayZPlayerTypeStepSoundLookupTable table = type.GetStepSoundLookupTable();
			SoundObjectBuilder soundBuilder = NULL;
			if(pUserInt < 100)
			{
				string surface;
				if(pUserInt % 2 == 1)
				{
					surface = GetSurfaceType(SurfaceAnimationBone.LeftBackLimb);
					if (surface.Length() == 0)//if no surface found, try other leg
						surface = GetSurfaceType(SurfaceAnimationBone.RightBackLimb);
				}
				else
				{
					surface = GetSurfaceType(SurfaceAnimationBone.RightBackLimb);
					if (surface.Length() == 0)//if no surface found, try other leg
						surface = GetSurfaceType(SurfaceAnimationBone.LeftBackLimb);
				}
				
				if (surface.Length() != 0)
					m_LastSurfaceUnderHash = surface.Hash();
					
				soundBuilder = table.GetSoundBuilder(pUserInt, state.m_iMovement, m_LastSurfaceUnderHash, GetBootsType());
			}
			else
			{
				string surface2 = GetSurfaceType();
				if (surface2.Length() != 0)
					m_LastSurfaceUnderHash = surface2.Hash();
				
				soundBuilder = table.GetSoundBuilder(pUserInt, state.m_iMovement, m_LastSurfaceUnderHash, GetBootsType());
			}

			if (soundBuilder != NULL && GetGame().GetPlayer())
			{
				vector orientation = Vector(0, 0, 0);
				vector edgeLength = Vector(1.5, 3.0, 1.5);
				array<Object> excludedObjects = new array<Object>;
				array<Object> collidedObjects = new array<Object>;
				
				if (GetGame().IsBoxColliding(GetPosition(), orientation, edgeLength, excludedObjects, collidedObjects))
				{
					for (int i = 0; i < collidedObjects.Count(); ++i)
					{
						string objectClass = collidedObjects.Get(i).GetType();
						
						if (objectClass.Contains("BushSoft") || objectClass.Contains("BushHard"))
						{
							for (int j = 0; j < type.GetVegetationSounds().Count(); ++j)
							{
								VegetationSound vegetationSound = type.GetVegetationSounds().Get(j);
								
								if (vegetationSound.GetAnimEventIds().Find(pUserInt) >= 0)
								{
									SoundObjectBuilder vegSoundObjectBuilder = vegetationSound.GetSoundObjectBuilder();
									SoundObject vegSoundObject = vegetationSound.GetSoundObjectBuilder().BuildSoundObject();
									
									if (vegSoundObject != NULL)
									{
										AttenuateSoundIfNecessary(vegSoundObject);
										PlaySound(vegSoundObject, vegSoundObjectBuilder);
									}
									
									break;
								}
							}
							
							break;
						}
					}
				}
				
				SoundObject soundObject = soundBuilder.BuildSoundObject();
				if (soundObject != NULL)
				{
					AttenuateSoundIfNecessary(soundObject);
					PlaySound(soundObject, soundBuilder);
				}
			}
		}
		
		if(GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			float noiseMultiplier = 0;
			float speedNoiseMultiplier = 0;
			float bootsNoiseMultiplier = 0;
			float surfaceNoiseMultiplier = GetSurfaceNoise(); //! gets noise multiplayer base on surface player walks on
			
			ref HumanMovementState	hms = new HumanMovementState();

			//! noise multiplier based on player speed
			GetMovementState(hms);

			switch(AITargetCallbacksPlayer.StanceToMovementIdxTranslation(hms))
			{
				case DayZPlayerConstants.MOVEMENTIDX_SPRINT:
					speedNoiseMultiplier = 3.0;
					break;
				case DayZPlayerConstants.MOVEMENTIDX_RUN:
					speedNoiseMultiplier = 1.0;
					break;
				case DayZPlayerConstants.MOVEMENTIDX_WALK:
					speedNoiseMultiplier = 1.0;
					break;
			}

			//! noise multiplier based on type of boots
			switch(GetBootsType())
			{
				case AnimBootsType.Boots:
					bootsNoiseMultiplier = 1.0;
					break;
				case AnimBootsType.Sneakers:
					bootsNoiseMultiplier = 1.0;
					break;
				case AnimBootsType.None:
					bootsNoiseMultiplier = 1.0;
					break;
			}

			NoiseParams noiseParams;
			if (state.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_ERECT || state.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDERECT)
				noiseParams = type.GetNoiseParamsStand();
			else if (state.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_CROUCH || state.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDCROUCH)
				noiseParams = type.GetNoiseParamsCrouch();
			else if (state.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_PRONE || state.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDPRONE)
				noiseParams = type.GetNoiseParamsProne();
			else
			{
				Print("OnStepEvent: wrong stance, id: " + state.m_iStanceIdx + "using backup with stand stance (id: 0)");
				noiseParams = type.GetNoiseParamsStand();
			}
			
			//! calcs noise multiplier from players speed, stance and surface under the player when not in idle
			if (hms.m_iMovement > DayZPlayerConstants.MOVEMENTIDX_IDLE)
			{
				noiseMultiplier = (speedNoiseMultiplier + bootsNoiseMultiplier + surfaceNoiseMultiplier) / 3;
			}
			ProcessFeetDamageServer(pUserInt);
			AddNoise(noiseParams, noiseMultiplier);
		}
	}
	
	Magazine GetReAttachMagazine()
	{
		return m_ReAttachMagazine;
	}
	
	void SetReAttachMagazine( Magazine magazine )
	{
		m_ReAttachMagazine = magazine;
	}
	
	Weapon_Base GetReEquipWeapon()
	{
		return m_ReEquipWeapon;
	}
	
	void SetReEquipWeapon( Weapon_Base weapon )
	{
		m_ReEquipWeapon = weapon;
	}
	
	bool GetContinuouLoadMagazineFinished()
	{
		return m_ContinuousLoadMagazineFinished;
	}
	
	void SetContinuousLoadMagazineFinished( bool finished )
	{
		m_ContinuousLoadMagazineFinished = finished;
	}
}