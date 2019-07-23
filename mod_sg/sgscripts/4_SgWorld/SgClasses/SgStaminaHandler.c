// SG 60:40 overhaul
/*
modded class StaminaHandler
{		
	void StaminaHandler(PlayerBase player)
	{
		m_Stamina 			= SG_STAMINA_MAX; 
		m_StaminaCap 		= SG_STAMINA_MAX;
	}
	
	override void Update(float deltaT, int pCurrentCommandID)
	{
#ifdef DEVELOPER
		m_Debug = DiagMenu.GetBool(DiagMenuIDs.DM_CHEATS_STAMINA_DISABLE);
		if( m_Debug ) return;
#endif
		if( m_Player )
		{
			// Calculates actual max stamina based on player's load
			if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
				m_Stamina = m_Player.GetStatStamina().Get();

			m_PlayerLoad = m_Player.GetPlayerLoad();

			//! StaminaCap calculation starts when PlayerLoad exceeds STAMINA_WEIGHT_LIMIT_THRESHOLD
			if (m_PlayerLoad >= GameConstants.STAMINA_WEIGHT_LIMIT_THRESHOLD)
			{
				m_StaminaCap =  Math.Max((SG_STAMINA_MAX - (((m_PlayerLoad - GameConstants.STAMINA_WEIGHT_LIMIT_THRESHOLD)/GameConstants.STAMINA_KG_TO_GRAMS) * GameConstants.STAMINA_KG_TO_STAMINAPERCENT_PENALTY)),GameConstants.STAMINA_MIN_CAP);
			}
			else
			{
				m_StaminaCap = SG_STAMINA_MAX;
			}
			
			// Calculates stamina gain/loss based on movement and load
			m_Player.GetMovementState(m_State);

			switch (pCurrentCommandID)
			{
			case DayZPlayerConstants.COMMANDID_MOVE:
				StaminaProcessor_Move(m_State);
			break;
			case DayZPlayerConstants.COMMANDID_LADDER:
				StaminaProcessor_Ladder(m_State);
			break;
			case DayZPlayerConstants.COMMANDID_SWIM:
				StaminaProcessor_Swimming(m_State);
			break;
			case DayZPlayerConstants.COMMANDID_FALL:	//! processed on event
			case DayZPlayerConstants.COMMANDID_MELEE2:  //! processed on event
				break;
			default:
				if( !m_IsInCooldown )
				{
					m_StaminaDelta = GameConstants.STAMINA_GAIN_IDLE_PER_SEC;
				}
			break;
			}
			
			//Sets current stamina & stores + syncs data with client
			if (m_Stamina < 0)
			{
				m_Stamina = 0;
			}
			else
			{
				m_Stamina = Math.Max(0,Math.Min((m_Stamina + m_StaminaDelta*deltaT),m_StaminaCap));
				m_Stamina = m_Stamina - m_StaminaDepletion;
			}
			
			if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
			{
				m_Player.GetStatStamina().Set(m_Stamina);
				m_Time += deltaT;
				if ( m_StaminaParams && m_Time >= GameConstants.STAMINA_SYNC_RATE )
				{
					m_Time = 0;
					m_StaminaParams.param1 = m_Stamina;
					m_StaminaParams.param2 = m_StaminaCap;
					m_StaminaParams.param3 = m_IsInCooldown;
					GetGame().RPCSingleParam(m_Player, ERPCs.RPC_STAMINA, m_StaminaParams, true, m_Player.GetIdentity());
				}
			}
			else
			{
				m_Player.SetStamina(m_Stamina, m_StaminaCap);
			}

			//! sets exhaustion look of player based on stamina level
			HumanCommandAdditives ad = m_Player.GetCommandModifier_Additives();
			float exhaustion_value = 1-((m_Stamina/(m_StaminaCap*0.01))*0.01);
			exhaustion_value = Math.Min(1,exhaustion_value);
			if ( ad )
			{
				// do not apply exhaustion on local client if player is in ADS/Optics (camera shakes)
				if ( m_Player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT && (m_Player.IsInOptics() || m_Player.IsInIronsights()) )
				{
					ad.SetExhaustion(0, true);
				}
				else
				{
					ad.SetExhaustion(exhaustion_value, true);
				}
			}

			CheckStaminaState();

			m_StaminaDelta = 0;
			m_StaminaDepletion = 0; // resets depletion modifier
		}
	}
	
	protected override void StaminaProcessor_Move(HumanMovementState pHumanMovementState)
	{
		switch ( pHumanMovementState.m_iMovement )
		{
		case DayZPlayerConstants.MOVEMENTIDX_SPRINT: //sprint
			if ( pHumanMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_ERECT )
			{
				m_StaminaDelta = -GameConstants.STAMINA_DRAIN_STANDING_SPRINT_PER_SEC;
				SetCooldown(GameConstants.STAMINA_REGEN_COOLDOWN_DEPLETION);
				break;
			}
			if ( pHumanMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_CROUCH)
			{
				m_StaminaDelta = -GameConstants.STAMINA_DRAIN_CROUCHED_SPRINT_PER_SEC;
				SetCooldown(GameConstants.STAMINA_REGEN_COOLDOWN_DEPLETION);
				break;
			}
			m_StaminaDelta = GameConstants.STAMINA_GAIN_JOG_PER_SEC;
		break;
			
		case DayZPlayerConstants.MOVEMENTIDX_RUN: //jog
			if (!m_IsInCooldown)
			{
				m_StaminaDelta = SG_STAMINA_REGENERATION_MULTIPLICATOR * (GameConstants.STAMINA_GAIN_JOG_PER_SEC + CalcStaminaGainBonus());
			}
		break;
			
		case DayZPlayerConstants.MOVEMENTIDX_WALK: //walk
			if (!m_IsInCooldown)
			{
				m_StaminaDelta = SG_STAMINA_REGENERATION_MULTIPLICATOR * (GameConstants.STAMINA_GAIN_WALK_PER_SEC + CalcStaminaGainBonus());
			}
		break;
			
		case DayZPlayerConstants.MOVEMENTIDX_IDLE: //idle
			if (!m_IsInCooldown)
			{
				m_StaminaDelta = SG_STAMINA_REGENERATION_MULTIPLICATOR * (GameConstants.STAMINA_GAIN_IDLE_PER_SEC + CalcStaminaGainBonus());
			}
		break;
			
		default:
			m_StaminaDelta = SG_STAMINA_REGENERATION_MULTIPLICATOR * GameConstants.STAMINA_GAIN_IDLE_PER_SEC;
		break;
		}
	}
	
	protected override void StaminaProcessor_Ladder(HumanMovementState pHumanMovementState)
	{
		switch ( pHumanMovementState.m_iMovement )
		{
		case 2: //climb up (fast)
			m_StaminaDelta = -GameConstants.STAMINA_DRAIN_LADDER_FAST_PER_SEC;
			SetCooldown(GameConstants.STAMINA_REGEN_COOLDOWN_DEPLETION);
			break;
		break;
			
		case 1: //climb up (slow)
			if (!m_IsInCooldown)
			{
				m_StaminaDelta = SG_STAMINA_REGENERATION_MULTIPLICATOR * (GameConstants.STAMINA_GAIN_LADDER_PER_SEC + CalcStaminaGainBonus());
			}
		break;
			
		default:
			m_StaminaDelta = SG_STAMINA_REGENERATION_MULTIPLICATOR * GameConstants.STAMINA_GAIN_IDLE_PER_SEC;
		break;
		}
	}

	protected override void StaminaProcessor_Swimming(HumanMovementState pHumanMovementState)
	{
		switch ( pHumanMovementState.m_iMovement )
		{
		case 3: //swim fast
			m_StaminaDelta = -GameConstants.STAMINA_DRAIN_SWIM_FAST_PER_SEC;
			SetCooldown(GameConstants.STAMINA_REGEN_COOLDOWN_DEPLETION);
			break;
		break;
			
		case 2: //swim slow
			if (!m_IsInCooldown)
			{
				m_StaminaDelta = SG_STAMINA_REGENERATION_MULTIPLICATOR * (GameConstants.STAMINA_GAIN_SWIM_PER_SEC + CalcStaminaGainBonus());
			}
		break;
			
		default:
			m_StaminaDelta = SG_STAMINA_REGENERATION_MULTIPLICATOR * GameConstants.STAMINA_GAIN_IDLE_PER_SEC;
		break;
		}
	}

	override bool HasEnoughStaminaFor(EStaminaConsumers consumer)
	{
		if ( consumer == EStaminaConsumers.SPRINT && m_Player.GetPlayerLoad() > SG_WEIGHT_CAPACITY )
		{
			return false;
		}
		else
		{
			return super.HasEnoughStaminaFor(consumer);
		}
	}

	//
	override float GetStaminaNormalized()
	{	
		return m_Stamina / SG_STAMINA_MAX;
	}
	
	override void DepleteStamina(EStaminaModifiers modifier)
	{
		float val = 0.0;
		StaminaModifier sm = m_StaminaModifiers.GetModifierData(modifier);

		//! select by modifier type and drain stamina
		switch (sm.GetType())
		{
			case m_StaminaModifiers.FIXED:
				m_StaminaDepletion = m_StaminaDepletion + sm.GetMaxValue();
			break;
			
			case m_StaminaModifiers.RANDOMIZED:
				val = Math.RandomFloat(sm.GetMinValue(), sm.GetMaxValue());
				m_StaminaDepletion = m_StaminaDepletion + val;
			break;
		}

		//! run cooldown right after depletion
		SetCooldown(GameConstants.STAMINA_REGEN_COOLDOWN_DEPLETION);
		m_StaminaDepletion = Math.Clamp(m_StaminaDepletion, 0, SG_STAMINA_MAX);
	}
};
*/