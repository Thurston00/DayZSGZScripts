modded class BoltActionRifle_InnerMagazine_Base
{
	override void SetActions()
	{
		super.SetActions();
		RemoveAction(FirearmActionLoadBulletQuick); // Easy reload
		AddAction(FirearmActionLoadMultiBulletQuick); // Easy reload
	}
};