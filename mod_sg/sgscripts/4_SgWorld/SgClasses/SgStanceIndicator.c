modded class StanceIndicator
{	
	override void DisplayStance(SgEPlayerStance stance)
	{	
		if ( m_Player )
		{
			m_Player.GetPlayerEvents().GetEvent_OnStanceUpdate().Invoke(stance);
		}
	}
};

enum SgEPlayerStance
{
	STANCE_ERECT = 1,
	STANCE_CROUCH = 2,
	STANCE_PRONE = 3
}