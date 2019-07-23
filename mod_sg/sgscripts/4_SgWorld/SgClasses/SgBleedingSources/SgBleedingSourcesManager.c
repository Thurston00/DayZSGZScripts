modded class BleedingSourcesManagerServer
{
	bool m_CanAddNewBleedingSource = true;
	
	override void OnTick(float delta_time)
	{
		m_Tick += delta_time;
		if ( m_Tick > TICK_INTERVAL_SEC && m_BleedingSources != null )
		{
			int count = m_BleedingSources.Count();
			for (int i = 0; i < count; i++)
			{
				m_BleedingSources.GetElement(i).OnUpdateServer(delta_time, m_DisableBloodLoss);
				
				if (m_BleedingSources != null)
				{
					count = m_BleedingSources.Count();
				}
				else 
				{
					return;
				}
			}
		}
	}
	
	void EnableAddingNewBleedingSources(bool enable)
	{
		m_CanAddNewBleedingSource = enable;
	}
	
	override void ProcessHit(float damage, EntityAI source, int component, string zone, string ammo, vector modelPos)
	{
		ItemBase item_hit;
		float immunityBleeding;
		
		if ( !m_CanAddNewBleedingSource )
		{
			return;
		}
		
		if ( zone == "Torso" )
		{
			item_hit = ItemBase.Cast( m_Player.FindAttachmentBySlotName( "vest" ) );
		
			if ( item_hit )
			{	
				immunityBleeding = GetGame().ConfigGetFloat( "CfgVehicles " + item_hit.GetType() + " DamageSystem " + "GlobalArmor " + "immunityBleeding" );
								
				if ( immunityBleeding )
				{
					return;
				}
			}
		}
		
		if ( zone == "Head" )
		{
			item_hit = ItemBase.Cast( m_Player.FindAttachmentBySlotName( "headgear" ) );
			
			if ( item_hit )
			{
				immunityBleeding = GetGame().ConfigGetFloat( "CfgVehicles " + item_hit.GetType() + " DamageSystem " + "GlobalArmor " + "immunityBleeding" );
				
				if ( immunityBleeding )
				{
					return;
				}
			}
		}
		
		float bleed_chance = GetGame().ConfigGetFloat( "CfgAmmo " + ammo + " DamageApplied " + "bleedThreshold" );
		if ( Math.RandomFloat01() < bleed_chance )
		{
			AttemptAddBleedingSource(component);
		}
	}
}