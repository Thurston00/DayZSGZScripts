modded class Mp133Shotgun_Base 
{
	override void SetActions()
	{
		super.SetActions();
		RemoveAction(FirearmActionLoadBulletQuick); // Easy reload
		AddAction(FirearmActionLoadMultiBulletQuick); // Easy reload
	}
};
