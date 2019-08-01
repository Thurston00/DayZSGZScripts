modded class WeaponManager 
{
	override void OnWeaponActionEnd()
	{
		super.OnWeaponActionEnd();
		
		m_player.GetPlayerEvents().GetEvent_OnFireModeSwiched().Invoke(m_player.GetCurrentWeaponMode());
	}
}