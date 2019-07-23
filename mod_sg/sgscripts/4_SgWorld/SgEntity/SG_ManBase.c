modded class ManBase
{	
	protected 		SG_StaticSpawner	m_Spawner;
	protected		int					m_SpawnerItemIndex;
	protected ref	Timer				m_DestroyTimer;
	
	void SetSpawner(SG_StaticSpawner spawner, int item_index)
	{
		m_Spawner = spawner;
		m_SpawnerItemIndex = item_index;
	}
	
	void ManBase()
	{
		if ( GetSgGame().IsServer() )
		{
			SetEventMask(EntityEvent.INIT);			
		}
	}
	
	void ~ManBase()
	{
		if ( m_DestroyTimer )
		{
			delete m_DestroyTimer;		
		}
	}
	
	// -------------------------------------------------------------------------------
	override void EOnInit(IEntity other, int extra)
	{
		//PrintString("EOnInit: "+ Type() +" id: "+ GetID());
		m_DestroyTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
	}
	
	//====================================
	// Server: EEKilled
	//====================================
	override void EEKilled(Object killer)
	{	
		super.EEKilled(killer);
		
		if ( SgPluginGameServer.GetInstance().IsGameRunning() )
		{		
			if ( GetSgGame().SgIsServerMP() )
			{
				SgSMatchRecorder.OnEntityDied( this, EntityAI.Cast( killer ) );
			}
		}
		else
		{
			if ( m_Spawner )
			{
				m_Spawner.SpawnItem(m_SpawnerItemIndex);
				m_DestroyTimer.Run(2, this, "Destroy", NULL, false);
			}
		}
	}
	
	void Destroy()
	{
		//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallByName(GetGame(), "ObjectDelete", new Param1<Object>(this)); 
	}
	
}