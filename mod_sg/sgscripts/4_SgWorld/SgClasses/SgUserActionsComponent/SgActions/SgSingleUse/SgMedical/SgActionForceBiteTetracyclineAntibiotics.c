modded class ActionForceBiteTetracyclineAntibiotics
{
	override void OnEndServer( ActionData action_data )
	{	
		super.OnEndServer( action_data );
		
		float quantity = Math.Min( 1, action_data.m_MainItem.GetQuantity() );
		PlayerBase target_player = PlayerBase.Cast(action_data.m_Target.GetObject());
		
		action_data.m_MainItem.AddQuantity( -quantity, true, false );
		target_player.ProcessMedicals( action_data.m_MainItem.GetMedicalProfile(), quantity);
	}
};