class SgUiSwitch extends SgUiMenuPanel
{
	// Widgets
	protected 	TextWidget		m_UiLeftLabel, m_UiRightLabel;
	protected 	ImageWidget		m_UiImage;
	// Data					
	protected 	SgESwitchState 	m_SwitchState = SgESwitchState.LEFT;
	protected 	string 			m_OptionLeftText, m_OptionRightText;
	// Event
	private ref ScriptInvoker	SwitchEvent_OnSwitched;		
	// Colours:
	// - Fonts
	int m_FontColourNormal, m_FontColourHover, m_FontColourSelected, m_FontColourDisabled;
	
	// ---------------------------------------
	
	// Constructor
	void SgUiSwitch(Widget parent_widget, string text_option_left, string text_option_right, ScriptInvoker on_switched_event)
	{
		// Response event
		SwitchEvent_OnSwitched 	= on_switched_event;
		// Data 
		m_OptionLeftText = text_option_left;
		m_OptionRightText = text_option_right;
		// Init
		BuildLayout(parent_widget);
	}
	
	// --------------------------------------
	// OVERRRIDES SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_switch/sg_switch.layout";
	}
	override void FindAllWidgets()
	{
		m_UiLeftLabel	= FindLabel("LeftLabel");
		m_UiRightLabel	= FindLabel("RightLabel");
		m_UiImage		= FindImage("SwitchImage");
	}
	override void LoadAllWidgets()
	{	
		// Switch icons
		m_UiImage.LoadImageFile(SgESwitchState.LEFT, SgCMenuWidgetPaths.SWITCH_LEFT);
		m_UiImage.LoadImageFile(SgESwitchState.RIGHT, SgCMenuWidgetPaths.SWITCH_RIGHT);
		// Switch Labels
		m_UiLeftLabel.SetText(m_OptionLeftText);
		m_UiRightLabel.SetText(m_OptionRightText);
		// Colours
		SetFontColours();
		// Handler
		m_RootFrame.SetHandler(this);
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
		
		SetLeftOptionFontColour(m_FontColourDisabled);
		SetRightOptionFontColour(m_FontColourDisabled);
		SetImageColour(m_FontColourDisabled);

	}

	// --------------------------------------------- 
		
	protected void SetImageColour(int colour)
	{
		m_UiImage.SetColor(colour);
	}
	protected void SetLeftOptionFontColour(int colour)
	{
		m_UiLeftLabel.SetColor(colour);
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
		if (m_SwitchState == SgESwitchState.RIGHT)
		{
			SetSwitchOption(SgESwitchState.LEFT);
		}
		else
		{
			SetSwitchOption(SgESwitchState.RIGHT);
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
			case m_UiLeftLabel:
			{
				SetSwitchOption(SgESwitchState.LEFT);
				return true;
			}
			case m_UiRightLabel:
			{
				SetSwitchOption(SgESwitchState.RIGHT);
				return true;
			}
		}
		return false;
	}
	
	override bool OnMouseButtonUp(Widget w, int x, int y, int button)
	{
		if (w == m_UiImage || w == m_UiLeftLabel || w == m_UiRightLabel)
		{
			SetImageColour(m_FontColourHover);
			//SetRightOptionFontColour(m_FontColourHover);
			//SetLeftOptionFontColour(m_FontColourHover);
			
			return true;
		} 
		return false;
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w == m_UiImage || w == m_UiLeftLabel || w == m_UiRightLabel)
		{
			SetImageColour(m_FontColourHover);
			//SetRightOptionFontColour(m_FontColourHover);
			//SetLeftOptionFontColour(m_FontColourHover);
			
			return true;
		} 
		return false;
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w == m_UiImage || w == m_UiLeftLabel || w == m_UiRightLabel)
		{
			SetImageColour(m_FontColourNormal);
			//SetRightOptionFontColour(m_FontColourNormal);
			//SetLeftOptionFontColour(m_FontColourNormal);
			
			return true;
		} 
		return false;
	}
}

enum SgESwitchState
{
	LEFT,
	RIGHT
}