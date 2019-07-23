modded class ActionBiteVitaminBottle
{
	override void OnEndServer( ActionData action_data )
	{	
		super.OnEndServer( action_data );
		
		float quantity = Math.Min( 1, action_data.m_MainItem.GetQuantity() );
		action_data.m_MainItem.AddQuantity( -quantity, true, false );
		action_data.m_Player.ProcessMedicals( action_data.m_MainItem.GetMedicalProfile(), quantity);
	}
};