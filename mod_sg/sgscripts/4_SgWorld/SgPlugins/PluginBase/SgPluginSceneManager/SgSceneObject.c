/*
modded class SceneObject
{
	//========================================
	// SceneObject
	//========================================
	override SceneObject Init( string obj_name, vector pos )
	{
		bool is_ai = GetGame().IsKindOf( obj_name, "DZ_LightAI");
		
		EntityAI e = CreateObject(obj_name, pos);
		
		if ( e != NULL )
		{
			if ( e.IsInherited( ItemBase ) ) 
			{		
				ItemBase item = ItemBase.Cast( e );
				item.SetQuantity(item.GetQuantityMax());
			}
			
			LinkEntityAI(e);
		}
		
		m_LinkedSceneObjects		= new array<SceneObject>;
		m_LinkedSceneObjectsShapes	= new map<SceneObject, Shape>;
		m_LinkedSceneObjectsIndices	= new array<int>;
	
		return this;
	}
	
	//========================================
	// CreateObject
	//========================================
	protected EntityAI CreateObject( string obj_name, vector pos )
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
		{
			
		}
		return EntityAI.Cast( GetGame().CreateObject( obj_name, pos ) );
		//return PluginDeveloper.GetInstance().SpawnEntityOnGroundPos( SgPluginSceneManager.PLAYER, obj_name, 1, 1, pos );
		
	}
	
	//========================================
	// UnlinkAll
	//========================================
	override void UnlinkAll()
	{
		int link_count = GetLinkedSceneObjectsCount();
			
		if ( link_count > 0 )
		{
			for ( int i = 0; i < link_count; ++i )
			{
				SgPluginSceneManager.GetInstance().UnlinkSceneObjects(this, GetLinkedSceneObject(0));
			}			
		}
	}
}*/
