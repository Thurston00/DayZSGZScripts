modded class ZombieBase
{	
	override void EOnInit(IEntity other, int extra)
	{
	}
	
	override void EEKilled( Object killer )
	{
		super.EEKilled(killer);
		
		string killerUID = SG_UID_PLACEHOLDER;
		
		if ( killer != null )
		{
			if ( killer.IsInherited( EntityAI ) )
			{
				EntityAI parent = EntityAI.Cast( killer ).GetHierarchyRootPlayer();
				PlayerBase item_owner = PlayerBase.Cast( parent );
				
				if ( item_owner && item_owner.IsInherited( PlayerBase ) )
				{
					killerUID = PlayerBase.Cast( item_owner ).GetIdentity().GetId();
				}
			}
		}
		
		SgSManagerEventsServer.Event_OnZombieDied( this, killerUID );
	}
}
