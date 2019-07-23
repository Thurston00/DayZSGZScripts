class SgUiButtonSelection extends SgUiButton
{
	int m_BackgroundColourSelected, m_BackgroundColourHoverSelected;
	
	// Data
	protected bool m_IsSelected;								// is this button selected? 
	
	// Override --> SgUiButton
	override protected void SetBackgroundColours()
	{
		m_BackgroundColourNormal		= SgCMenuColours.COLOUR_NULL;
		m_BackgroundColourHover			= SgCMenuColours.COLOUR_LIGHT_GREY_TRANSPARENT_1;
		m_BackgroundColourSelected		= SgCMenuColours.COLOUR_YELLOW_TRANSPARENT_2;
		m_BackgroundColourHoverSelected	= SgCMenuColours.COLOUR_YELLOW;
		m_BackgroundColourDisabled		= SgCMenuColours.COLOUR_NULL;
	}
	override protected void SetFontColours()
	{
		m_FontColourNormal			= SgCMenuColours.COLOUR_WHITE;
		m_FontColourHover			= SgCMenuColours.COLOUR_BLACK;
		m_FontColourDisabled		= SgCMenuColours.COLOUR_GREY;
	}	
	
	// -------------------------------------------
	override protected void SetColourNormal()
	{
		m_UiUnderline.Show(false);

		if (!m_IsSelected)
		{
			SetBackgroundColour(m_BackgroundColourNormal);
			SetFontColour(m_FontColourNormal);
		}
		else 
		{
			SetBackgroundColour(m_BackgroundColourSelected);
			SetFontColour(m_FontColourNormal);
		}
	}	

	override protected void SetColourHover()
	{
		m_UiUnderline.Show(true);
		
		if (!m_IsSelected)
		{
			SetBackgroundColour(m_BackgroundColourHover);
			SetFontColour(m_FontColourNormal);	
		}
		else 
		{
			SetBackgroundColour(m_BackgroundColourHoverSelected);
			SetFontColour(m_FontColourHover);	
		}
	}	
	
	override protected void SetColourClicked(){	}		
		
	override protected void SetColourDisabled()
	{
		m_UiUnderline.Show(false);
		SetBackgroundColour(m_BackgroundColourDisabled);
		SetFontColour(m_FontColourDisabled);	
	}	
	
	// Abstract 
	protected void CallButtonSetEvent(Widget w)
	{
		// Override this
	}
	
	override bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		if (super.OnMouseButtonDown(w,x,y,button))
		{
			{
				CallButtonSetEvent(w);
				return true;
			}
		}
		return false;
	}
	
	protected void OnNavigationUpdated(Widget w)
	{
		if (w == m_UiBackground)
		{
			m_IsSelected = true;
			
			SetColourHover();
		}
		else 
		{
			m_IsSelected = false;
			
			if (m_ButtonState != SgEButtonState.DISABLE)
			{
				SetColourNormal();
			}
		}
	}
	
	// ---------------------------------------
	// Setters
	
	void SetSelected(bool is_selected)
	{
		m_IsSelected = is_selected;
		SetColourNormal();
	}
}