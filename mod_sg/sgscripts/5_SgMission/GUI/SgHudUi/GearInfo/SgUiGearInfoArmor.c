// DESIGN_ID: 0002

/*
	Sg class for hud Vest icon

	SG_TODO: Rename the file to SgUiGearInfoVest.c 
*/
class SgUiGearInfoVest extends SgUiHudPanel
{
	// Widget
	private ImageWidget m_UiVestImage;
	private TextWidget m_UiVestValueLabel;
	// Event
	private ref ScriptInvoker Event_OnVestUpdate;
	private ref ScriptInvoker Event_OnArmorUpdate;
	// Constructor
	void SgUiGearInfoVest(Widget parent_widget, ref ScriptInvoker event_Vest_update,  ref ScriptInvoker event_armor_update)
	{	
		Event_OnVestUpdate = event_Vest_update;
		Event_OnArmorUpdate = event_armor_update;
		BuildLayout(parent_widget);
		UpdateVest(0,0);
	}
	
	// ----------------------------------------------------------------
	// Overrides --> SgUiHudPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_gear_info/sg_gear_info_armor.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiVestImage			= FindImage( "ArmorImage" );			
		m_UiVestValueLabel		= FindLabel( "ArmorLabel" );	
	}	
	override protected void RegisterAllEvents()
	{
		Event_OnVestUpdate.Insert(UpdateVest);
	}
	override protected void UnRegisterAllEvents()
	{
		Event_OnVestUpdate.Remove(UpdateVest);
	}
	
	// ------------------------------------------------------------------
	
	private void UpdateVest(int Vest_level, bool is_ruined)
	{
		if (Vest_level != 0)	
		{
			m_UiVestImage.Show(true);
			m_UiVestValueLabel.SetText(Vest_level.ToString());
			
			if (is_ruined)
			{
				m_UiVestImage.SetColor(SgCMenuColours.COLOUR_DARK_RED);
			}
			else 
			{
				m_UiVestImage.SetColor(SgCMenuColours.COLOUR_WHITE);
			}
		}
		else 
		{
			m_UiVestImage.Show(false);	
		}

		Event_OnArmorUpdate.Invoke();
	}
	
	override void Show(bool show)
	{
		m_UiVestImage.Show(show);
	}
	
	bool IsShown()
	{
		return m_UiVestImage.IsVisible();
	}
}