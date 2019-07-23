modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
	
		//SG actions
		actions.Insert( SgActionDeactivateCollar );
		actions.Insert( SgActionInjectAntidoteSelf );
		
		//DayZ Actions (Unused by DayZ)
		actions.Insert( ActionFeedVitaminBottle );
		actions.Insert( ActionEatVitaminBottle );
		
		actions.Insert(FirearmActionLoadBulletQuick);
		actions.Insert(FirearmActionLoadMultiBulletQuick);
		actions.Insert(FirearmActionMechanicManipulate);
	}
};