class SgUiButton extends SgUiMenuPanel
{
	// Widgets
	protected 	TextWidget		m_UiContent;
	protected 	Widget 			m_UiUnderline;
	
	// Data					
	protected 	string 			m_Content;						// Button text   
	protected 	SgEButtonState 	m_ButtonState  	= SgEButtonState.NORMAL;		
	
	// Event
	private ref ScriptInvoker	CallbackEvent_OnClick_Left;		// Left mouse click
	private ref ScriptInvoker	CallbackEvent_OnClick_Right;	// Right mouse click
	
	// Colours:
	// - Backgrounds
	protected int m_BackgroundColourNormal, m_BackgroundColourHover, m_BackgroundColourPressed, m_BackgroundColourDisabled;
	// - Fonts
	protected int m_FontColourNormal, m_FontColourHover, m_FontColourPressed, m_FontColourDisabled;
	protected int m_FontSize;
	
	// ---------------------------------------
	
	// Constructor
	void SgUiButton(Widget parent_widget, string content, ScriptInvoker on_click_left_event, ScriptInvoker on_click_right_event = null)
	{
		// Response event
		CallbackEvent_OnClick_Left 	= on_click_left_event;
		CallbackEvent_OnClick_Right	= on_click_right_event;
		// Data 
		m_Content = content;
		// Init
		BuildLayout(parent_widget);
	}
	
	// --------------------------------------
	// OVERRRIDES SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_button/sg_button.layout";
	}
	override void FindAllWidgets()
	{
		m_UiContent	= FindLabel("ContentLabel");
		m_UiUnderline = FindPanel("Underline");
	}
	override void LoadAllWidgets()
	{	
		// Setup
		SetDefaultColours();	
		SetFontSize();
		
		SetContent(m_Content);
		SetButtonStateNormal();
		
		// Handler
		m_UiBackground.SetHandler(this);
	}
	
	// -----------------------------------------
	// DATA GETTERS
	SgEButtonState GetButtonState()
	{
		return m_ButtonState;	
	}
	
	// ------------------------------------------
	// DATA SETTERS
	void SetContent(string text)
	{
		m_Content = text;
		
		if (m_UiContent)
		{
			m_UiContent.SetTextExactSize(m_FontSize);
			m_UiContent.SetText(m_Content);
		}
	}
	void Visible(bool visibility)
	{
		m_RootFrame.Show(visibility);	
	}
	void Enable(bool eneableness)
	{
		m_UiBackground.Enable(eneableness);	
		
		if (eneableness)
		{
			SetButtonStateNormal();
		}
		else 
		{
			SetButtonStateDisabled();
		}
	}
	
	// --------------------------------------------- 
		
	protected void SetBackgroundColour(int colour)
	{
		m_UiBackground.SetColor(colour);
	}
	
	protected void SetFontColour(int colour)
	{
		m_UiContent.SetColor(colour);
		m_UiUnderline.SetColor(colour);
	}
	
	// ---------------------------------------
	
	private void SetButtonStateNormal()
	{
		m_ButtonState = SgEButtonState.NORMAL;
		
		SetColourNormal();
	}	
	protected void SetColourNormal()
	{
		SetBackgroundColour(m_BackgroundColourNormal);
		SetFontColour(m_FontColourNormal);
	}	

	private void SetButtonStateHover()
	{
		m_ButtonState = SgEButtonState.HOVER;
		SetColourHover();
	}	
	protected void SetColourHover()
	{
		SetBackgroundColour(m_BackgroundColourHover);
		SetFontColour(m_FontColourHover);	
	}	
	
	private void SetButtonStateClicked()
	{
		m_ButtonState = SgEButtonState.CLICKED;
		SetColourClicked();
	}
	protected void SetColourClicked()
	{
		SetBackgroundColour(m_BackgroundColourPressed);
		SetFontColour(m_FontColourPressed);	
	}		
	
	private void SetButtonStateDisabled()
	{
		m_ButtonState = SgEButtonState.DISABLE;
		SetColourDisabled();	
	}		
	protected void SetColourDisabled()
	{
		SetBackgroundColour(m_BackgroundColourDisabled);
		SetFontColour(m_FontColourDisabled);	
	}	
	
	// ---------------------------------------
	
	// Set default colour template
	protected void SetDefaultColours()
	{
		SetBackgroundColours();
		SetFontColours();
	}
	
	protected void SetBackgroundColours()
	{
		m_BackgroundColourNormal	= SgCMenuColours.COLOUR_YELLOW_TRANSPARENT_1;
		m_BackgroundColourHover		= SgCMenuColours.COLOUR_YELLOW;
		m_BackgroundColourPressed	= SgCMenuColours.COLOUR_BLACK;
		m_BackgroundColourDisabled	= SgCMenuColours.COLOUR_LIGHT_GREY_TRANSPARENT_1;
	}
	
	protected void SetFontColours()
	{
		m_FontColourNormal			= SgCMenuColours.COLOUR_WHITE;
		m_FontColourHover			= SgCMenuColours.COLOUR_WHITE;
		m_FontColourPressed			= SgCMenuColours.COLOUR_WHITE;
		m_FontColourDisabled		= SgCMenuColours.COLOUR_GREY;
	}
	
	protected void SetFontSize()
	{
		m_FontSize 					= 24;
	}
	// ---------------------------------------
	// OVERRIDES ScriptedWidgetEventHandler
	
	override bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		if (w == m_UiBackground)
		{
			if (m_ButtonState != SgEButtonState.DISABLE)
			{
				switch (button)
				{
					case MouseState.LEFT:
					{
						SetButtonStateClicked();
						if (CallbackEvent_OnClick_Left)
						{
							CallbackEvent_OnClick_Left.Invoke();
						}
						
						
						return true;
					}
					case MouseState.RIGHT:
					{
						if (CallbackEvent_OnClick_Right)
						{
							CallbackEvent_OnClick_Right.Invoke();
						}
						
						return true;
					}
				}
			}
		}
		return false;
	}
	
	override bool OnMouseButtonUp(Widget w, int x, int y, int button)
	{
		if (w == m_UiBackground)
		{
			if (m_ButtonState != SgEButtonState.DISABLE)
			{
				SetButtonStateHover();
			}
			return true;
		}
		return false;
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w == m_UiBackground)
		{
			if (m_ButtonState != SgEButtonState.DISABLE)
			{
				SetButtonStateHover();	
			}
			return true;
		}	
		return false;
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w == m_UiBackground)
		{
			if (m_ButtonState != SgEButtonState.DISABLE)
			{
				SetButtonStateNormal();
			}
			return true;
		}
		return false;
	}
}

enum SgEButtonState
{
	NORMAL,
	CLICKED,
	HOVER,
	DISABLE
}