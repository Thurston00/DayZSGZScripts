class SgLootGameItem
{
	string	m_ItemName;
	int		m_QuantityMin;
	int		m_QuantityMax;
	int		m_ComponentQuantityMin;
	int		m_ComponentQuantityMax;
	bool	m_ComponentAttach;
	string	m_Component;
	
	ref array<ESgBuildingType>		m_BuildingTypes;
	
	bool SpawnItem( vector spawn_pos, bool old_spawn_system = false )
	{

		/*
if ( !GetGame().IsMultiplayer() && m_ItemName == "CZ75" )
{
	Shape.CreateSphere(ARGB(100, 255, 255, 255), ShapeFlags.TRANSP|ShapeFlags.NOZWRITE|ShapeFlags.NOZBUFFER|ShapeFlags.NOOUTLINE, spawn_pos, 0.6);
}
		*/
		
Print("SgLootGameItem.SpawnItem() -> m_ItemName = " + m_ItemName);
		ItemBase item = ItemBase.Cast( GetGame().CreateObject(m_ItemName, spawn_pos, false) );
		if ( item )
		{
			if ( old_spawn_system )
			{
				if ( item.IsWeapon() || item.IsMagazine() )
				{
					item.SetOrientation( Vector( Math.RandomInt( 0, 360 ), -90, 0) );
				}
				else
				{
					item.SetOrientation( Vector( Math.RandomInt( 0, 360 ), 0, 0) );
				}
			}
			else
			{
				vector itemGroundPos = item.GetPosition();
				
				if ( item.IsKindOf("Ammunition_Base"))
				{
					item.SetOrientation( Vector( Math.RandomInt( 0, 360 ), -90, itemGroundPos[2] ) );
				}
				else
				{
					item.SetOrientation( Vector( Math.RandomInt( 0, 360 ), itemGroundPos[1], itemGroundPos[2] ) );
					PlaceItemOnGround(item, spawn_pos);
				}
			}
				
			// Setup Components
			
			if ( m_Component.Length() > 0 )
			{
				int componentQuantity = Math.RandomIntInclusive(m_ComponentQuantityMin, m_ComponentQuantityMax);
				
				if ( componentQuantity > 0 )
				{
					ItemBase component = ItemBase.Cast( GetGame().CreateObject( m_Component, spawn_pos, false ) );
					PlaceItemOnGround(component, spawn_pos);
					
					if ( component.IsKindOf("Ammunition_Base"))
					{
						component.SetOrientation( Vector( Math.RandomInt( 0, 360 ), -90, itemGroundPos[2] ) );
					}
					else
					{
						PlaceItemOnGround(component, spawn_pos);
					}
					
					Magazine mag = Magazine.Cast( component );
					if (mag != null)
					{
						mag.ServerSetAmmoCount( componentQuantity );	
						
						Weapon weapon = Weapon.Cast(item);
						if (weapon != null) 
						{
							if ( m_ComponentAttach && weapon.CanAttachMagazine(weapon.GetCurrentMuzzle(), mag) )
							{
								weapon.AttachMagazine(weapon.GetCurrentMuzzle(), mag); //SG_TODO: Magazine is stuck in weapon
							}
						}
					}
					else if ( m_ComponentAttach && item.GetInventory().CanAddAttachment(component) )
					{
						item.PredictiveTakeEntityAsAttachment(component);
					}
				}
			}
			
			// Set quantity
			if ( m_QuantityMax > 0 )
			{
				item.SetQuantity( Math.RandomIntInclusive(m_QuantityMin, m_QuantityMax) );
			}
			
//Print("SgLootSpawnerObject: Created item: " + m_ItemName + " pos: " + spawn_pos );
			return true;
		}
		
//Print("SgLootSpawnerObject: Cant create item: "+ m_ItemName );
		return false;
	}
	
	// Placing items on ground with correct orientation
	protected void PlaceItemOnGround(ItemBase item, vector spawn_pos)
	{
		vector m4[4];
		Math3D.MatrixIdentity4(m4);
		GameInventory.PrepareDropEntityPos(item, item, m4);
		vector ypr[3];
		ypr[0] = m4[0];
		ypr[1] = m4[1];
		ypr[2] = m4[2];	
		item.SetOrientation(Math3D.MatrixToAngles(ypr));
		item.SetPosition(spawn_pos);
	}
}