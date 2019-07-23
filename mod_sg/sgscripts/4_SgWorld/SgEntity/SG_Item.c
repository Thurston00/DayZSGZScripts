modded class ItemBase
{
	protected SG_StaticSpawner		m_Spawner;
	protected int					m_SpawnerItemIndex;
	
	ref Timer m_TimerIB;
	
	void ItemBase()
	{
		if ( m_TimerIB == NULL && (GetGame().IsMultiplayer() && GetGame().IsClient()) )
		{
			//m_TimerIB = new Timer( CALL_CATEGORY_GAMEPLAY );
			//m_TimerIB.Run(1, this, "DebugF", NULL );
		}
	}

	void DebugF()
	{	
		//Print("Item Init position = "+ GetPosition());
		Shape.CreateSphere(ARGB(20, 255, 255, 255), ShapeFlags.TRANSP|ShapeFlags.NOZWRITE|ShapeFlags.NOZBUFFER|ShapeFlags.NOOUTLINE, GetPosition(), 0.6);
	}
	
	void SetSpawner(SG_StaticSpawner spawner, int item_index)
	{
		m_Spawner = spawner;
		m_SpawnerItemIndex = item_index;
	}
	
	//
	// Medical profile
	//
	
	float GetMedicalPercentageHeal()
	{
		if( !IsLiquidPresent() )
		{
			Edible_Base edible = Edible_Base.Cast( this );
			return edible.GetPercentageHeal();
		}
		else
		{
			return 0; // In future add logic for liquid medicine.
		}
	}
	
	MedicalProfile GetMedicalProfile()
	{
		return new MedicalProfile(GetMedicalPercentageHeal());
	}
}