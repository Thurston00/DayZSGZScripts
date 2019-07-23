modded class InspectMenuNew extends UIScriptedMenu
{

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("mod_sg/gui/layouts/sg_inventory/sg_inventory_new_inspect.layout");
		
		return layoutRoot;
	}
	
	override void SetItem(EntityAI item)
	{
		super.SetItem(item);
		
		InspectMenuNew.UpdateAmmoType(layoutRoot, item);
	}
	
	static void UpdateAmmoType(Widget root_widget, EntityAI item)
	{
		if ( item.IsInherited( ZombieBase ) || item.IsInherited( Car ) ) return;
		
		Widget ammo_grid_widget = root_widget.FindAnyWidget("AmmoGrid");
		ammo_grid_widget.Show(true);
			
		string ammo_label_text = "";	
		string ammo_name = "";
		
		if(item.IsInherited( Weapon ) )
		{
			Weapon weapon;
			TStringArray compatible_ammo_list = new TStringArray();
			Class.CastTo(weapon, item);
			
			string type = weapon.GetType();
			string path = "cfgWeapons" + " " + type + " " + "chamberableFrom";
			
			GetGame().ConfigGetTextArray(path, compatible_ammo_list);
			
			foreach(string ammo_raw : compatible_ammo_list)
			{
				string ammo_path = "CfgMagazines" + " " + ammo_raw + " " + "displayName";
				ammo_name = GetGame().ConfigGetTextOut(ammo_path);
				ammo_label_text += ammo_name + " ";
			}
			
			WidgetTrySetText( ammo_grid_widget, "AmmoValueLabel", ammo_label_text);
		}
		else if(item.IsInherited( Magazine ) )
		{
			Magazine magazine;
			
			Class.CastTo(magazine, item);
			
			foreach(string ammo : magazine.m_CompatiableAmmo)
			{				
				ammo_label_text += ammo_name + " ";
			}
			
			WidgetTrySetText( ammo_grid_widget, "AmmoValueLabel", ammo_label_text);
		}
		else 
		{
			ammo_grid_widget.Show(false);
		}
	}
}