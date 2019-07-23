modded class BleedingSource
{
	protected const float BLEED_TIME_DURATION = 360;
				
	//!gets called every frame
	override void OnUpdateServer(float deltatime, bool no_blood_loss)
	{
		float maxHealth = m_Player.GetMaxHealth("GlobalHealth", "Health");
		float healthCoeficient = ( maxHealth / BLEED_TIME_DURATION ) * -1;
			
		if ( m_Player.GetHealth("GlobalHealth", "Health") + deltatime * healthCoeficient <= 0 )
		{ 
			m_Player.m_BleedingManagerServer.RemoveAllSources();
			m_Player.SetPlayerBledOut();
			//m_Player.AddHealth( "GlobalHealth", "Health", deltatime * healthCoeficient );
		}
		else
		{
			m_Player.AddHealth( "GlobalHealth", "Health", deltatime * healthCoeficient );
		}
	}
};