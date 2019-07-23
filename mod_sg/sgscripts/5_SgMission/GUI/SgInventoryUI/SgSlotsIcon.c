modded class SlotsIcon 
{
	void SlotsIcon( LayoutHolder parent, Widget root, int index )
	{
		ScriptInvoker invoker = Inventory.GetEventOnItemInHandsChanged();
		invoker.Insert(HighlightIfCombinable);
	}
	
	void ~SlotsIcon()
	{
		ScriptInvoker invoker = Inventory.GetEventOnItemInHandsChanged();
		invoker.Remove(HighlightIfCombinable);
	}

	
  	// Check if the item in hands can be combined with this item
	void HighlightIfCombinable()
	{
		// get player inventory
		ItemBase hold_item = ItemBase.Cast(PlayerBase.Cast( GetGame().GetPlayer()).GetHumanInventory().GetEntityInHands());

		// get the item connected to the icon
		ItemBase current_item = ItemBase.Cast(m_Obj);
		
		if (!current_item)
		{
			return;
		}
		
		
		if (!hold_item)
		{
			HighlightItem(false);
		}
		else if (hold_item.GetInventory().CanAddAttachment(current_item))		// item can be attached
		{
			HighlightItem(true);
		}
		else if (hold_item.CanBeCombined(current_item))							// item stack can be combined
		{
			HighlightItem(true);
		}
		
		else if (ItemManager.GetRecipeCount( false, current_item, hold_item ) > 0)			// item can be combined
		{
			HighlightItem(true);
		}
	
		else if (DayZGame.CheckAmmoCompability(hold_item, current_item))
		{
			HighlightItem(true);
		}
		else if (Magazine.Cast(hold_item) && Magazine.Cast(hold_item).IsCompatiableAmmo(current_item))
		{
			HighlightItem(true);
		}
		else
		{
			HighlightItem(false);
		}
	}

	// HighlightItem this item if true
  	protected void HighlightItem(bool highlighted)
  	{
		if (m_SelectedWidget)
		{
		
			if (highlighted) 
			{
				m_SelectedWidget.SetColor(ARGB(255,255,165,0));								// set its colour to orange
			}					
			else 
			{
				m_SelectedWidget.SetColor(ARGB(255,255,255,255));							// set its colour back to white
			}							
	
			m_SelectedWidget.Show(highlighted);												// Highlight or De-Highlight the icon
		}
  	}
}