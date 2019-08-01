modded class InjuryAnimationHandler
{
	void SetInjuryCommandParams(bool enable, eInjuryHandlerLevels level)
	{
		super.SetInjuryCommandParams(enable, level);
		
		// player in sgz does not get anim injury
		level = 0;
		
		m_InjuryAnimDamageValue = GetInjuryValue(level);
	}
}