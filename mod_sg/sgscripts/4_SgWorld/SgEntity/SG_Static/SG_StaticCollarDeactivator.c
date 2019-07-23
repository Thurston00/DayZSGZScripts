class SG_StaticCollarDeactivator extends SG_Static
{	
	bool		m_SyncIsInteractible;
	int			m_ClientAlarmEffectID;
	
	//=======================================
	// Constructor
	//=======================================
	void SG_StaticCollarDeactivator()
	{
		RegisterNetSyncVariableBool("m_SyncIsInteractible");
		
		if ( GetSgGame().SgIsClientMP() )
		{
			SgSClientGame.SetCollarDeactivator( this );
		}
	}

	//=======================================
	// ShowAlarm
	//=======================================
	void ShowAlarm( ESgGameState game_state, ESgLocationType location_type )
	{
		if ( location_type != ESgLocationType.PhaseEnd )
		{
			return;
		}
		Print( "ShowAlarm: Position: "+ this.GetPosition() );
		ref Effect effect;
		
		if ( game_state == ESgGameState.Transition )
		{
			effect = new SgEffAlarmGreen();
		}
		else if ( game_state == ESgGameState.Phase )
		{
			effect = new SgEffAlarmRed();
		}
		
		if ( SEffectManager.IsEffectExist( m_ClientAlarmEffectID ) )
		{
			SEffectManager.Stop( m_ClientAlarmEffectID );
		}
		
		m_ClientAlarmEffectID = SEffectManager.PlayOnObject( effect, this );
	}
	
	//=======================================
	// SetIteractible
	//=======================================
	void SetIteractible( bool interactible )
	{
		if ( GetSgGame().SgIsServerMP() )
		{
			m_SyncIsInteractible = interactible;
			
			SetSynchDirty();
		}		
	}
	
	//=======================================
	// IsInteractible
	//=======================================
	bool IsInteractible()
	{
		return m_SyncIsInteractible;
	}
	
	//=======================================
	// CanPlayerInteract
	//=======================================
	bool CanPlayerInteract( PlayerBase player_base )
	{
		if ( GetSgGame().SgIsServerMP() )
		{
			return IsInteractible();
		}
		else if ( GetSgGame().SgIsClientMP() )
		{
			if ( IsInteractible() )
			{
				return !SgSClientGame.IsCollarDamageBlocked();
			}
		}
		
		return false;
	}
	
	//=======================================
	// SetActions
	//=======================================
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(SgActionDeactivateCollar);
	}
}