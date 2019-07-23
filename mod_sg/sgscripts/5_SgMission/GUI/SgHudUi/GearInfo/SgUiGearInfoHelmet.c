// DESIGN_ID: 0002

/*
	Sg class for hud helmet panel
*/
class SgUiGearInfoHelmet extends SgUiHudPanel
{
	// Widget
	private ImageWidget m_UiHelmetImage;
	private TextWidget 	m_UiHelmetValueLabel;
	// Event
	private ref ScriptInvoker Event_OnHelmetUpdate;
	private ref ScriptInvoker Event_OnArmorUpdate;
	// Constructor
	void SgUiGearInfoHelmet(Widget parent_widget, ref ScriptInvoker event_helmet_update, ref ScriptInvoker event_armor_update)
	{
		Event_OnHelmetUpdate = event_helmet_update;
		Event_OnArmorUpdate = event_armor_update;
		BuildLayout(parent_widget);
		UpdateHelmet(0,0);
	}
	
	// ----------------------------------------------------------------
	// Overrides --> SgUiHudPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_gear_info/sg_gear_info_helmet.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiHelmetImage			= FindImage( "HelmetImage" );			
		m_UiHelmetValueLabel	= FindLabel( "HelmetLabel" );	
	}	
	override protected void RegisterAllEvents()
	{
		Event_OnHelmetUpdate.Insert(UpdateHelmet);
	}
	override protected void UnRegisterAllEvents()
	{
		Event_OnHelmetUpdate.Remove(UpdateHelmet);
	}
	
	// ------------------------------------------------------------------
	
	private void UpdateHelmet(int Helmet_level, bool is_ruined)
	{
		if (Helmet_level != 0)
		{
			m_UiHelmetImage.Show(true);
			m_UiHelmetValueLabel.SetText(Helmet_level.ToString());
			
			if (is_ruined)
			{
				m_UiHelmetImage.SetColor(SgCMenuColours.COLOUR_DARK_RED);
			}
			else 
			{
				m_UiHelmetImage.SetColor(SgCMenuColours.COLOUR_WHITE);
			}
		}
		else 
		{
			m_UiHelmetImage.Show(false);	
		}
		
		Event_OnArmorUpdate.Invoke();
	}
	
	override void Show(bool show)
	{
		m_UiHelmetImage.Show(show);
	}
	
	bool IsShown()
	{	
		return m_UiHelmetImage.IsVisible();
	}
}