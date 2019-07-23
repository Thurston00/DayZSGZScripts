class SG_Collar
{
	protected const float		DAMAGE_PER_TICK 		= 1;	//damage per tick
	protected const float		DEFAULT_FREQUENCY 		= 1;	//defalut frequency at which the collar is ticking
	protected const float		TICK_TO_BORDER_RATE 	= 0.03;	//tick acceleration per time out of phase
	protected const float		TICK_TO_BORDER_RATE_MAX = 0.25;	//max frequency of ticks per time out of phase
	protected const float		TICK_TO_POI_RATE		= 1;	//tick frequency based on distance to POI in endgame, this number represent the damage at 0 distance to POI
	protected const float 		DIST_MAX 				= 150;	//distance at which the frequency gets capped in end game 
	protected const float		TICK_TO_POI_RATE_MAX 	= 0.5;	//max frequency of ticks based on distance in end game 
	
	protected ref SgPlayer			m_SgPlayer;
	protected bool					m_IsActive;
	protected bool					m_IsBlocked;
	protected float					m_CollarDamage;
	protected float					m_UpdateFreq;
	protected ref Timer 			m_UpdateTimer;	
	protected float					m_CollarEnergy;
	protected SgLocationPhaseEnd	m_LocationEnd;
	protected SG_CollarItem			m_CollarItem;
	
	void SG_Collar( SgPlayer sg_player )
	{
		SetSgPlayer( sg_player );
		
		m_UpdateTimer = new Timer();
		
		SgSManagerEventsServer.Event_OnSgPlayerLocationLeave.Insert(Event_OnSgPlayerLocationLeave);
		SgSManagerEventsServer.Event_OnSgPlayerLocationEnter.Insert(Event_OnSgPlayerLocationEnter);
		SgSManagerEventsServer.Event_OnLocationDeactivated.Insert(Event_OnLocationDeactivated);
		
		m_LocationEnd = SgLocationPhaseEnd.Cast( SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PhaseEnd ) );
	}
	
	//====================================
	// AttachOnPlayer
	//====================================
	void AttachOnPlayer()
	{
		m_CollarItem = SG_CollarItem.Cast( GetSgPlayer().GetPlayerBase().CreateInInventory( "SG_CollarItem" ) );
	}
	
	//====================================
	// SetSgPlayer
	//====================================
	void SetSgPlayer( SgPlayer sg_player )
	{
		m_SgPlayer = sg_player;
	}
	
	//====================================
	// GetSgPlayer
	//====================================
	SgPlayer GetSgPlayer()
	{
		return m_SgPlayer;
	}
	
	//====================================
	// Event_OnSgPlayerLocationLeave
	//====================================
	void Event_OnSgPlayerLocationLeave( SgPlayer sg_player )
	{
		if ( sg_player.GetPlayerUID() == GetSgPlayer().GetPlayerUID() )
		{
			Activate();
		}
	}
	
	//====================================
	// Event_OnSgPlayerLocationEnter
	//====================================
	void Event_OnSgPlayerLocationEnter( SgPlayer sg_player )
	{
		if ( sg_player.GetPlayerUID() == GetSgPlayer().GetPlayerUID() )
		{
			Deactivate();
		}
	}
	
	//====================================
	// Event_OnLocationDeactivated
	//====================================
	void Event_OnLocationDeactivated( SgLocation location )
	{
		if ( IsActive() )
		{
			Deactivate();
		}
	}
	
	//====================================
	// SetDamageBlock
	//====================================
	void SetDamageBlock(bool block)
	{
		if ( m_IsBlocked == block )
		{
			return;
		}
		
		m_IsBlocked = block;
		
		SgSManagerEventsServer.Event_OnSgPlayerCollarBlockChanged( GetSgPlayer(), block );
		
		m_UpdateTimer.Run(m_UpdateFreq, this, "UpdateCollar", NULL, false);
	}
	
	//====================================
	// IsDamageBlocked
	//====================================
	bool IsDamageBlocked()
	{
		return m_IsBlocked;
	}
	
	//====================================
	// IsActive
	//====================================
	bool IsActive()
	{
		return m_IsActive;
	}
	
	//====================================
	// UpdateCollar
	//====================================
	void UpdateCollar()
	{			
		if ( !IsActive() || IsDamageBlocked() || !GetSgPlayer() || !GetSgPlayer().GetPlayerBase() )
		{
			return;
		}
				
		if ( m_LocationEnd.IsActive() )
		{		
			vector pos_end = m_LocationEnd.GetEndPosition();
			vector pos_plr = GetSgPlayer().GetPosition();
			
			float distance = vector.Distance(pos_plr, pos_end);
		
			m_UpdateFreq = ( distance / DIST_MAX ) * ( TICK_TO_POI_RATE_MAX - TICK_TO_POI_RATE ) + TICK_TO_POI_RATE;
			
			if ( m_UpdateFreq < TICK_TO_POI_RATE_MAX )
			{
				m_UpdateFreq = TICK_TO_POI_RATE_MAX;
			}
		}
		else
		{			
			if ( m_UpdateFreq > TICK_TO_BORDER_RATE_MAX )
			{
				m_UpdateFreq = m_UpdateFreq - TICK_TO_BORDER_RATE;
			}
			else
			{
				m_UpdateFreq = TICK_TO_BORDER_RATE_MAX;
			}
		}
		
		if ( DAMAGE_PER_TICK < GetSgPlayer().GetPlayerBase().GetHealth() )
		{
			DoDamage(DAMAGE_PER_TICK);
		}	
		else
		{
			CollarExplode();	
			m_UpdateTimer.Stop();	
		}
		
		if ( !m_UpdateTimer.IsRunning() && GetSgPlayer().IsAlive() )
		{
			m_UpdateTimer.Run(m_UpdateFreq, this, "UpdateCollar", NULL, false);
		}
	}
	
	//------------------------------------
	// Activate
	//------------------------------------
	protected void Activate()
	{
		m_IsActive = true;
		m_UpdateFreq = DEFAULT_FREQUENCY;
		
		
		UpdateCollar();
	}
	
	//------------------------------------
	// Deactivate
	//------------------------------------
	protected void Deactivate()
	{
		m_IsActive = false;
	}
	
	//------------------------------------
	// DoDamage
	//------------------------------------
	protected void DoDamage(float damage)
	{		
		GetSgPlayer().GetPlayerBase().DecreaseHealth("", "Health", damage);
		
		//Print( "Collar DoDamage: "+ damage +" Heath: "+ GetSgPlayer().GetPlayerBase().GetHealth("", "Health") );
		
		SgSManagerEventsServer.Event_OnSgPlayerCollarDamage( GetSgPlayer() );
	}
	
	//====================================
	// CollarExplode
	//====================================
	void CollarExplode()
	{
		if ( m_CollarItem )
		{
			PlayerBase player = GetSgPlayer().GetPlayerBase();
			player.SetCanBeDestroyed( true );
				
			m_CollarItem.Explode( DT_EXPLOSION, "SG_CollarExplosion" );
			
			SgSManagerEventsServer.Event_OnSgPlayerCollarExplode( GetSgPlayer() );
			
			GetGame().ObjectDelete( m_CollarItem );
			
			if ( m_SgPlayer.GetPlayerBase().IsAlive() )
			{
				KillPlayer();
			}
			//TODO urob z hlavy po vybuchu kyptik
		}
	}
	
	//------------------------------------
	// KillPlayer
	//------------------------------------
	protected void KillPlayer()
	{
		if ( GetGame().IsServer() )
		{
			m_SgPlayer.GetPlayerBase().ProcessDirectDamage( DT_CUSTOM, m_CollarItem, "Head", "SG_CollarExplosion", "0 0 0" );
			
			EntityAI itemInHands = m_SgPlayer.GetPlayerBase().GetHumanInventory().GetEntityInHands();
			
			if ( itemInHands )
			{
				if ( m_SgPlayer.GetPlayerBase().CanDropEntity(itemInHands) )
				{
					vector transform[4];
					itemInHands.GetTransform( transform );
					m_SgPlayer.GetPlayerBase().ServerDropEntity( itemInHands );
					itemInHands.SetTransform( transform );
				}
			}
		}
	}
}