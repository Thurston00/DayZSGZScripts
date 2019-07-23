class SgCAContinuousQuantityRepeatAndTime : CAContinuousBase
{		
	protected float 				m_ItemQuantity;
	protected float 				m_SpentQuantity;
	protected float 				m_ItemMaxQuantity;
	protected float					m_TimeElapsed;
	protected float					m_TimeElapsedAfterStart;
	protected float 				m_QuantityUsedPerSecond;
	protected float 				m_DefaultTimeToRepeat;
	protected ref Param1<float>		m_SpentUnits;
	protected float					m_TimeToStartAction;	
	protected bool					m_PlayRevivePart;
	protected const int 			PERCENTAGE_HEAL_COUNSCIOUS = 5;
	protected const int 			PERCENTAGE_HEAL_UNCOUNSCIOUS = 10;
	protected const int 			REVIVE_SALINE_QUANTITY = 25;
	
	void SgCAContinuousQuantityRepeatAndTime( float quantity_used_per_second, float time_to_repeat, float time_to_start_action )
	{
		m_QuantityUsedPerSecond = quantity_used_per_second;
		m_DefaultTimeToRepeat = time_to_repeat;
		m_TimeToStartAction = time_to_start_action;
	}
	
	override void Setup( ActionData action_data )
	{
		m_SpentQuantity = 0;
		m_TimeElapsedAfterStart = 0;
				
		if ( !m_SpentUnits )
		{ 
			m_TimeElapsed = 0;	
			m_ItemQuantity = action_data.m_MainItem.GetQuantity();
			m_ItemMaxQuantity = action_data.m_MainItem.GetQuantityMax();
			m_SpentUnits = new Param1<float>( 0 );
		}
		else
		{	
			if ( GetGame().IsServer() )
			{
				m_ItemQuantity = action_data.m_MainItem.GetQuantity();
			}
			else
			{				
				if ( m_PlayRevivePart )
				{
					m_ItemQuantity = ( action_data.m_MainItem.GetQuantity() - REVIVE_SALINE_QUANTITY );
				}
				else
				{
					m_ItemQuantity = ( action_data.m_MainItem.GetQuantity() - m_QuantityUsedPerSecond );
				}
			}
				
			m_SpentUnits.param1 = 0;
		}		
	}
	
	override int Execute( ActionData action_data  )
	{
		if ( !action_data.m_Player )
		{
			return UA_ERROR;
		}
			
		PlayerBase player_target = GetRealTargetPlayerBase(action_data);
		
		if ( m_TimeElapsed >= m_TimeToStartAction || !player_target.IsUnconscious() )
		{
			if ( m_SpentQuantity < m_ItemQuantity )
			{
				m_SpentQuantity += m_QuantityUsedPerSecond * action_data.m_Player.GetDeltaT();
				m_TimeElapsedAfterStart += action_data.m_Player.GetDeltaT();
				
				if ( m_TimeElapsedAfterStart >= m_DefaultTimeToRepeat || m_PlayRevivePart )
				{		
					CalcAndSetQuantity( action_data );		
					HealPlayer( action_data );								
					Setup(action_data);	//reset data after repeat
					
					m_PlayRevivePart = false;
				}
				return UA_PROCESSING;
			}
			else
			{
				CalcAndSetQuantity( action_data );
				HealPlayer( action_data );
				OnCompletePogress(action_data);
				return UA_FINISHED;
			}
		}
			
		m_PlayRevivePart = true;
		m_TimeElapsed += action_data.m_Player.GetDeltaT();
		return UA_PROCESSING;				
	}
	
	override int Cancel( ActionData action_data )
	{
		if ( !action_data.m_Player )
		{
			return UA_ERROR;
		}
		
		if ( !m_PlayRevivePart )
		{
			CalcAndSetQuantity( action_data );
			HealPlayer( action_data );
		}
		
		return UA_CANCEL;
	}	
	
	override float GetProgress()
	{
		if ( m_PlayRevivePart )
		{
			return m_TimeElapsed / m_TimeToStartAction;
		}
		else
		{
			return 1 - ( m_ItemQuantity - m_SpentQuantity ) / m_ItemMaxQuantity );
		}
	}
	
	//---------------------------------------------------------------------------
	
	void HealPlayer( ActionData action_data )
	{
		if ( GetGame().IsServer() )
		{		
			PlayerBase player_target = GetRealTargetPlayerBase(action_data);	
			int max_health = player_target.GetMaxHealth("GlobalHealth", "Health");
		
			if ( player_target.IsUnconscious() )
			{		
				player_target.SetHealth("GlobalHealth", "Health", ( ( max_health / 100 ) * PERCENTAGE_HEAL_UNCOUNSCIOUS ) );		
				DayZPlayerSyncJunctures.SendPlayerUnconsciousness( player_target, false );	
				action_data.m_MainItem.AddQuantity( - REVIVE_SALINE_QUANTITY );
			}
			else 
			{
				player_target.AddHealth("GlobalHealth", "Health", m_SpentQuantity * ( max_health / m_ItemMaxQuantity ) );
			}	
		}
	}
	
	void CalcAndSetQuantity( ActionData action_data )
	{
		if ( GetGame().IsServer() )
		{
			if ( m_SpentUnits )
			{
				m_SpentUnits.param1 = m_SpentQuantity;
				SetACData(m_SpentUnits);
			}
			
			if ( action_data.m_MainItem )
			{
				action_data.m_MainItem.AddQuantity( - m_SpentQuantity, false, true );
			}
		}
	}
	
	PlayerBase GetRealTargetPlayerBase(ActionData action_data)
	{
		PlayerBase player_target = PlayerBase.Cast( action_data.m_Target.GetObject() );
		
		if ( player_target == null ) // Action target is `Self` and not a `Target`
		{
			player_target = action_data.m_Player;
		}
		
		return player_target;
	}
}