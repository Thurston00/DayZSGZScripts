class SgUiMaskedTextBox extends SgUiMenuPanel
{
	private const int FONT_CAPTION_SIZE = 16;
	private const int FONT_HEADLINE_SIZE = 26;
	// Widget
	protected 		EditBoxWidget	m_UiUserInputEditBox;
	protected 		TextWidget	 	m_UiMaskedLabel;
	// Data
	private 		string 			m_Hint; 
	private 		bool 			m_IsMasked;
	// Events		
	
	// Constructor
	void SgUiMaskedTextBox(Widget parrent_widget, string hint)
	{
		this.m_Hint = hint;
		super.BuildLayout(parrent_widget);
	}
	
	// ----------------------------------------------------
	// Overrides --> SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_masked_text/sg_masked_textbox.layout";
	}
	override void FindAllWidgets()
	{
		this.m_UiUserInputEditBox	= FindEditText("InputTextBox");
		this.m_UiMaskedLabel			= FindLabel("MaskedLabel");
	}	
	override void LoadAllWidgets()
	{
		this.SetMaskedText();
		m_UiUserInputEditBox.SetHandler(this);
	}	
	
	// ------------------------------------------------------
	// Getters
	
	string GetText()
	{
		return this.m_UiUserInputEditBox.GetText().Trim();
	}
	
	// ------------------------------------------------------
	// Setters
	
	void SwitchMasked()
	{
		this.m_IsMasked = !this.m_IsMasked;
		SetMaskedText();
	}
	
	private void SetMaskedText()
	{
		string text = this.m_UiUserInputEditBox.GetText().Trim();
		string output;
		
		if (text == "")
		{
			if(this.m_Hint != "")
			{
				output = this.m_Hint;
				
				this.m_UiMaskedLabel.SetColor(SgCMenuColours.COLOUR_LIGHT_GREY);
				m_UiMaskedLabel.SetTextExactSize(FONT_CAPTION_SIZE);
			}
		}
		else 
		{
			if (this.m_IsMasked)
			{
				for (int i = 0; i < text.Length(); i++)
				{
					output += "*";
				}	
			}
			else 
			{
				output = text;
			}
			this.m_UiMaskedLabel.SetColor(SgCMenuColours.COLOUR_WHITE);	
			m_UiMaskedLabel.SetTextExactSize(FONT_HEADLINE_SIZE);
		}
		this.m_UiMaskedLabel.SetText(output);
	}

	// ------------------------------------------------------
	
	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		if(w == this.m_UiUserInputEditBox)
		{
			SetMaskedText();			
		}
		return super.OnChange(w, x, y, finished);
	}
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w == m_UiUserInputEditBox)
		{
			m_UiUserInputEditBox.SetColor(SgCMenuColours.COLOUR_YELLOW);
			m_UiMaskedLabel.SetColor(SgCMenuColours.COLOUR_YELLOW);
			return true;
		}
		return false;
	}
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		
		if (w == m_UiUserInputEditBox)
		{
			m_UiUserInputEditBox.SetColor(SgCMenuColours.COLOUR_WHITE);
			m_UiMaskedLabel.SetColor(SgCMenuColours.COLOUR_WHITE);
			return true;
		}
		return false;
	}
}