modded class ActionSkinning
{	
	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer( action_data );
		
		//DropEquipAndDestroyRootLambda used in the base class overriden, in order NOT to copying collar upon skinning
	}
};

modded class DropEquipAndDestroyRootLambda
{
	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{			
		InventoryLocation understash_src = m_NewLocation; // m_NewLocation is a backup of original old_item's src before the operation started
		
		array<EntityAI> children = new array<EntityAI>;
		old_item.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, children);
		int count = children.Count();
		for (int i = 0; i < count; i++)
		{
			EntityAI child = children.Get(i);
			if ( child && !child.IsInherited( SG_CollarItem ) )
			{
				InventoryLocation child_src = new InventoryLocation;
				child.GetInventory().GetCurrentInventoryLocation(child_src);
				
				InventoryLocation child_dst = new InventoryLocation;
				child_dst.Copy(child_src);
				child_dst.CopyLocationFrom(understash_src);
				//@TODO: modify _dst with place on gnd?
				
				m_Player.LocalTakeToDst(child_src, child_dst);
												
				GetGame().RemoteObjectTreeCreate(child); // this forces server to send CreateVehicle Message to client. This is needed for preserving the appearance of network operations on client (so that DeleteObject(old) arrives before CreateVehicle(new)). @NOTE: this does not delete the object on server, only it's network representation.
			}
		}
	}
}