class SgUiSwitchRegion extends SgUiMenuPanel
{
	// Widgets
	protected 	TextWidget		m_UiLeftLabel, m_UiRightLabel;
	protected 	ImageWidget		m_UiImage;
	// Data					
	protected 	SgESwitchState 	m_SwitchState = SgESwitchRegion.EU;
	protected 	string 			m_OptionLeftText = "*EU";
	protected 	string 			m_OptionRightText = "*US";
	// Event
	private ref ScriptInvoker	SwitchEvent_OnSwitched;		
	// Colours:
	// - Fonts
	int m_FontColourNormal, m_FontColourHover, m_FontColourSelected, m_FontColourDisabled;
	
	// ---------------------------------------
	
	// Constructor
	void SgUiSwitchRegion(Widget parent_widget, ScriptInvoker on_switched_event)
	{
		// Response event
		SwitchEvent_OnSwitched 	= on_switched_event;
		// Init
		BuildLayout(parent_widget);
	}
	
	// --------------------------------------
	// OVERRRIDES SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_switch/sg_switch_region.layout";
	}
	override void FindAllWidgets()
	{
		m_UiRightLabel	= FindLabel("RightLabel");
		m_UiImage		= FindImage("SwitchImage");
	}
	override void LoadAllWidgets()
	{	
		// Switch icons
		m_UiImage.LoadImageFile(SgESwitchRegion.EU, SgCMenuWidgetPaths.SWITCH_REGION_EU);
		m_UiImage.LoadImageFile(SgESwitchRegion.US, SgCMenuWidgetPaths.SWITCH_REGION_US);
		// Switch Labels
		SetDefaultSelection();
		// Colours
		SetFontColours();
		// Handler
		m_RootFrame.SetHandler(this);
	}
	
	private void SetDefaultSelection()
	{
		SwitchRightLabelText();
	}
	
	
	private void SwitchRightLabelText()
	{
		switch (m_SwitchState)
		{
			case SgESwitchRegion.EU:
			{
				
				m_UiRightLabel.SetText(m_OptionLeftText);
				break;
			}
			case SgESwitchRegion.US:
			{
				
				m_UiRightLabel.SetText(m_OptionRightText);
				break;
			}
		}
	}
	
	private void SetSwitchOption(SgESwitchState switch_option)
	{
		if (switch_option != m_SwitchState)
		{
			m_SwitchState = switch_option;
			
			if (SwitchEvent_OnSwitched)
			{
				SwitchEvent_OnSwitched.Invoke(m_SwitchState);
			}
			
			SwitchRightLabelText();
			UpdateSwitchImage();
		}
	} 
	
	// ------------------------------------------
	
	SgESwitchState GetSwitchState()
	{
		return m_SwitchState;
	}
	
 	// ------------------------------------------

	void Visible(bool visibility)
	{
		m_RootFrame.Show(visibility);	
	}
	
	void Enable(bool eneableness)
	{		
		m_RootFrame.Enable(eneableness);
		
		SetRightOptionFontColour(m_FontColourDisabled);
		SetImageColour(m_FontColourDisabled);

	}

	// --------------------------------------------- 
		
	protected void SetImageColour(int colour)
	{
		m_UiImage.SetColor(colour);
	}
	protected void SetRightOptionFontColour(int colour)
	{
		m_UiRightLabel.SetColor(colour);
	}

	// ---------------------------------------
	
	protected void SetFontColours()
	{
		m_FontColourNormal				= SgCMenuColours.COLOUR_WHITE;
		m_FontColourHover				= SgCMenuColours.COLOUR_YELLOW;
		m_FontColourSelected			= SgCMenuColours.COLOUR_YELLOW_TRANSPARENT_1;
		m_FontColourDisabled			= SgCMenuColours.COLOUR_LIGHT_GREY;
	}	
	
	private void Switch()
	{
		if (m_SwitchState == SgESwitchRegion.US)
		{
			SetSwitchOption(SgESwitchRegion.EU);
		}
		else
		{
			SetSwitchOption(SgESwitchRegion.US);
		}
	}
	
	private void UpdateSwitchImage()
	{
		m_UiImage.SetImage(m_SwitchState);
	}
		
	
	// ---------------------------------------
	// OVERRIDES ScriptedWidgetEventHandler

	override bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		switch (w)
		{
			case m_UiImage:
			{
				Switch();
				return true;
			} 
		}
		return false;
	}
	
	override bool OnMouseButtonUp(Widget w, int x, int y, int button)
	{
		if (w == m_UiImage || w == m_UiRightLabel)
		{
			SetImageColour(m_FontColourHover);
			
			return true;
		} 
		return false;
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w == m_UiImage || w == m_UiRightLabel)
		{
			SetImageColour(m_FontColourHover);
			
			return true;
		} 
		return false;
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w == m_UiImage || w == m_UiRightLabel)
		{
			SetImageColour(m_FontColourNormal);
			
			return true;
		} 
		return false;
	}
}

enum SgESwitchRegion
{
	EU, 
	US
}