modded class InjuryAnimationHandler
{
	override void Update(float deltaT)
	{
		if( m_AnimationChange )
		{
			m_Player.GetCommandModifier_Additives().SetInjured(0, false);
			m_AnimationChange = false;
		}

		super.Update( deltaT );
	}
}