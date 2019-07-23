class SgUiCheckBoxRow extends SgUiMenuPanel
{
	// Widgets
	protected TextWidget	m_UiCheckBoxText;
	protected ButtonWidget	m_UiButton;
	protected ImageWidget 	m_CheckboxImage;
	// Data
	protected string 		m_Text;
	protected string 		m_Value;
	protected bool 			m_IsChecked = false;
	// Events
	protected ref ScriptInvoker Event_OnCheckboxChanged;

	// --------------------------------
	
	// Constructor
	void SgUiCheckBoxRow(Widget root, string text, string value, ScriptInvoker invoker)
	{
		this.m_Text = text;
		this.m_Value = value;
		this.Event_OnCheckboxChanged = invoker;
		
		super.BuildLayout(root);
	}
	
	// --------------------------------
	// OVERRIDES --> SgUiMenuPanel methods
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_checkbox/sg_checkbox_default.layout";
	}
	
	override protected void FindAllWidgets()
	{
		this.m_UiCheckBoxText 		= FindLabel("CheckBoxText");		
		this.m_UiButton				= FindButton("Button");
		this.m_CheckboxImage		= FindImage("CheckBoxImage");
	}
	
	override protected void LoadAllWidgets()						
	{
		this.m_UiCheckBoxText.SetText(this.m_Text);
		this.LoadImageFiles();
		this.m_UiButton.SetHandler(this);
	}
	
	// --------------------------------
	// Getters
	bool GetChecked()
	{
		return this.m_IsChecked;
	}
	string GetText()
	{
		return this.m_Text;
	}
	string GetValue()
	{
		return this.m_Value;
	}
	
	// -----------------------------
	// Getters
	void Check()
	{
		this.m_IsChecked = true;		
		this.UpdateWidget();
	}
	void Uncheck()
	{
		this.m_IsChecked = false;
		this.UpdateWidget();
	}
	void ChangeState()
	{
		this.m_IsChecked = !m_IsChecked;
		this.UpdateWidget();
	}
	void UpdateWidget()
	{
		if(this.m_IsChecked)
		{
			this.m_CheckboxImage.SetImage(1);
		}
		else 
		{
			this.m_CheckboxImage.SetImage(0);
		}
	}
	protected void LoadImageFiles()
	{
		this.m_CheckboxImage.LoadImageFile(0, SgCMenuWidgetPaths.CHECKBOX_UNCHECKED_IMAGE);
		this.m_CheckboxImage.LoadImageFile(1, SgCMenuWidgetPaths.CHECKBOX_CHECKED_IMAGE);
	}
	
	// ------------------------------------------------
	// MOUSE EVENTS
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w == this.m_UiButton)
		{
			m_UiCheckBoxText.SetColor(SgCMenuColours.COLOUR_YELLOW);
			m_CheckboxImage.SetColor(SgCMenuColours.COLOUR_YELLOW);
			return true;
		}
		return false;
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w == this.m_UiButton)
		{			
			m_UiCheckBoxText.SetColor(SgCMenuColours.COLOUR_WHITE);
			m_CheckboxImage.SetColor(SgCMenuColours.COLOUR_WHITE);
			return true;
		}
		return false;
	}
		
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if(w == this.m_UiButton)
		{
			this.ChangeState();
			Event_OnCheckboxChanged.Invoke(this);
			return true;
		}	
		return false;
	}
	
	// ----------------------------------------
}