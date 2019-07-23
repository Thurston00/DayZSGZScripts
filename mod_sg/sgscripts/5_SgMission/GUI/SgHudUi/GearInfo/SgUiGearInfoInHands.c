// DESIGN_ID: 0002

/*
	Sg class for equipped-gear-in-hands hud
	SG_TODO: Reanmae this file to SgUiGearInfoInHands.c
*/
class SgUiGearInfoInHands extends SgUiHudPanel
{
	// Widget
	private 	ImageWidget 	m_UiGunImage;
	private 	TextWidget 		m_UiFireModeLabel;
	private 	TextWidget 		m_UiTotalAmmoLabel;
	private 	TextWidget 		m_UiClipAmmoLabel;
	private 	TextWidget 		m_UiItemNameLabel;
	private 	Widget 			m_UiGunGrid;
	// Events
	private ref ScriptInvoker 	Event_OnItemUpdate;
	private ref ScriptInvoker 	Event_OnFireModeUpdate;
	private ref ScriptInvoker 	Event_OnWeaponAmmoUpdate;
	private ref ScriptInvoker 	Event_OnInventoryAmmoUpdate;
	// Constructor
	void SgUiGearInfoInHands(Widget parent_widget, ScriptInvoker event_item_update, ScriptInvoker event_fireMode_update, ScriptInvoker event_wpnAmmo_update, ScriptInvoker event_invAmmo_update)
	{	
		// Events
		Event_OnItemUpdate = event_item_update;
		Event_OnFireModeUpdate = event_fireMode_update;
		Event_OnWeaponAmmoUpdate = event_wpnAmmo_update;
		Event_OnInventoryAmmoUpdate = event_invAmmo_update;
		// Build
		BuildLayout(parent_widget);
	}
	
	// ----------------------------------------------------------------
	// Overrides --> SgUiHudPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_gear_info/sg_gear_info_inhand.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiGunImage 		= FindImage( "GunIconImage" );		
		m_UiFireModeLabel 	= FindLabel( "FireModeLabel" );		
		m_UiTotalAmmoLabel 	= FindLabel( "AmmoLabel" );		
		m_UiClipAmmoLabel 	= FindLabel( "MagazineLabel" );		
		m_UiItemNameLabel 	= FindLabel( "ItemNameLabel" );	
		m_UiGunGrid			= FindPanel( "GunGrid" );	
	}
	override protected void RegisterAllEvents()
	{
		Event_OnItemUpdate.Insert(UpdateItem);
		Event_OnFireModeUpdate.Insert(UpdateFireMode);
		Event_OnWeaponAmmoUpdate.Insert(UpdateWeaponAmmo);
		Event_OnInventoryAmmoUpdate.Insert(UpdateInventoryAmmo);
	}
	override protected void UnRegisterAllEvents()
	{
		Event_OnItemUpdate.Remove(UpdateItem);
		Event_OnFireModeUpdate.Remove(UpdateFireMode);
		Event_OnWeaponAmmoUpdate.Remove(UpdateWeaponAmmo);
		Event_OnInventoryAmmoUpdate.Remove(UpdateInventoryAmmo);
	}
	
	// ------------------------------------------------------------------
	// Weapons
	private void UpdateItem(ItemBase item)
	{
		if (item)
		{
			if (item.IsWeapon())
			{
				// Hide item name label
				m_UiItemNameLabel.Show(false);	
				// Set icon
				SetGunIcon(SgCGunIcon.FindGunByDisplayName(item.GetDisplayName()).GetIcon());
			}
			else 
			{
				// Hide gun icon grind
				m_UiGunGrid.Show(false);
				// Show item name label
				m_UiItemNameLabel.Show(true);
				// Set item name label text 
				m_UiItemNameLabel.SetText(item.GetDisplayName());
			}
		}
		else 
		{
			// Hide gun icon grind
			m_UiGunGrid.Show(false);
			// Hide item name label
			m_UiItemNameLabel.Show(false);
		}
	}
	private void UpdateFireMode(string mode)
	{
		string text;
		switch (mode)
        {
            case "Single" :
			{
                text = "#STR_Single";
            	break;
			}
            case "SemiAuto" :
            {  
				text = "#STR_SemiAuto";
            	break;
			}
            case "FullAuto" :
			{
                text = "#STR_FullAuto";
            	break;
			}
            //currently only doubleshot shotguns
            case "Burst" :
			{
                text = "#STR_Double";//"#STR_Burst";
				break;
			}
        }
		m_UiFireModeLabel.SetText(text);
	}
	// Udpate all the ammunition in weapon (including chamber and magazine)
	private void UpdateWeaponAmmo(int wpn_ammo)
	{
		m_UiClipAmmoLabel.SetText(wpn_ammo.ToString());
	}
	// Update all the usable ammunition for current weapon in the inventory (excluding ammo in the clip)
	private void UpdateInventoryAmmo(int inventory_ammo)
	{
		m_UiTotalAmmoLabel.SetText(inventory_ammo.ToString());
	}	
	// Set correct gun icon 
	private void SetGunIcon(string icon_path)
	{
		m_UiGunGrid.Show(true);
		m_UiGunImage.LoadImageFile(0, icon_path);	
	}
}

