modded class ActionEatPainkillerTablets
{
	const int PERCENTAGE_HEAL = 20;
	
	override void OnEndServer( ActionData action_data )
	{	
		super.OnEndServer( action_data );
		
		int max_health = action_data.m_Player.GetMaxHealth("GlobalHealth", "Health");
		
		action_data.m_Player.AddHealth("GlobalHealth", "Health", ( ( max_health / 100 ) * PERCENTAGE_HEAL ) );
	}
};