class SG_StaticSpawner extends SG_Static
{	
	protected 		vector				m_WorldSpawnPoint;
	protected	ref	array<string>		m_SpawnItems;
	protected	ref	array<ItemBase>		m_SpawnedItems;
	protected		bool				m_UseAI;
	
	void SG_StaticSpawner()
	{
		if ( GetSgGame().IsServer() )
		{
			SetEventMask(EntityEvent.INIT);			
		}
	}
	
	//=======================================
	// EOnInit
	//=======================================
	override void EOnInit(IEntity other, int extra)
	{
		m_SpawnItems = new array<string>;
		ConfigGetTextArray("sgSpawnItems", m_SpawnItems);
		
		bool spawn_in_teams = ConfigGetBool("sgSpawnInTeam");
		m_UseAI = ConfigGetBool("sgSpawnUseAI");
		
		if ( GetSgGame().IsMultiplayer() && spawn_in_teams )
		{
			return;
		}
		
		for ( int i = 0; i < m_SpawnItems.Count(); ++i )
		{
			SpawnItem(i);
		}
	}
	
	//=======================================
	// SpawnItem
	//=======================================
	void SpawnItem(int item_index)
	{
		LOD lod = GetLODByName("memory");
		Selection selection = lod.GetSelectionByName("SpawnPoints");
		vector spawn_pos = GetPosition() + selection.GetVertexPosition(lod, item_index);
		string object_name = m_SpawnItems[ item_index ];
		Print( object_name );
		if ( GetGame().IsKindOf( object_name, "DZ_LightAI") )
		{
			Object obj = GetGame().CreateObject(object_name, spawn_pos, false, m_UseAI);
			if( obj.IsInherited( ManBase ) )
			{
				ManBase man = ManBase.Cast( obj );
				man.SetSpawner(this, item_index);
			}
		}
		else
		{
			ItemBase item = ItemBase.Cast( GetGame().CreateObject(object_name, spawn_pos) );
			if( item )
			{
				item.SetSpawner(this, item_index);
			}
		}
	}
}