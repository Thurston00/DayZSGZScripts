class SgUiMenuPanel extends ScriptedWidgetEventHandler
{ 
	protected ImageWidget 	m_UiBackground;
	protected Widget 		m_RootFrame;		// Root frame
	
	void BuildLayout(Widget parent_widget = null)
	{	
		SetRoot(GetLayoutPath(), parent_widget);
		
		if(m_RootFrame)
		{
			FindBackground();
			FindAllWidgets();
			RegisterAllEvents();
			LoadAllWidgets();
		}
		else
		{
			SgDebug.Error(SgDebug.E_NOT_FOUND_ROOT, this.ClassName(), "BuildLayout");
		}
	}
	
	void ~SgUiMenuPanel()
	{
		UnRegisterAllEvents();
		OnDestroy();
		
		if ( m_UiBackground )
		{
			delete m_UiBackground;
		}
		
		if ( m_RootFrame )
		{
			delete m_RootFrame;
		}
	}

	private void FindBackground()
	{
		m_UiBackground = ImageWidget.Cast(m_RootFrame.FindAnyWidget("Background"));
	}
	
	// GETTERS ------------------------
	protected Widget GetRootFrame() 
	{
		return m_RootFrame;
	}
	protected ImageWidget GetBackgroundWidget()
	{
		return m_UiBackground;
	}
	
	// SETTERS -------------------------	
	protected void SetRoot(string root_path, Widget parent_widget = null)
	{
		this.m_RootFrame = GetGame().GetWorkspace().CreateWidgets( root_path, parent_widget );
	}
	protected void SetBackground(string image_path)
	{
		this.m_UiBackground.LoadImageFile(0,image_path);
	}
	
	// ↘ ↘ ↘  METHODS FOR OVERRIDE  ↙ ↙ ↙ 	
	string GetLayoutPath()
	{
		SgDebug.Error(SgDebug.E_NOT_OVERRIDEN, ClassName(), "GetLayoutPath");
		return "";
	}
	// Find all the widgets used in this class
	protected void FindAllWidgets();
	// Setup all the widgets used in this class
	protected void LoadAllWidgets();
	// Register all the events used in this class
	protected void RegisterAllEvents();
	protected void UnRegisterAllEvents();
	protected void OnDestroy();
		
	// -----------------------------------------------
	// FIND METHODS 
	
	// Find any panel, frame, grid
	protected Widget FindPanel(string widget_name)
	{
		return m_RootFrame.FindAnyWidget(widget_name);
	}	
	// Find a edit text widget in this layout	
	protected EditBoxWidget FindEditText(string widget_name)
	{
		return EditBoxWidget.Cast(m_RootFrame.FindAnyWidget(widget_name));
	}	
	// Find a text widget in this layout
	protected TextWidget FindLabel(string widget_name)
	{
		return TextWidget.Cast(m_RootFrame.FindAnyWidget(widget_name));
	}
	// Find a multiline text widget in this layout
	protected MultilineTextWidget FindMultilineLabel(string widget_name)
	{
		return MultilineTextWidget.Cast(m_RootFrame.FindAnyWidget(widget_name));
	}		
	// Find a button widget in this layout
	protected ButtonWidget FindButton(string widget_name)
	{
		return ButtonWidget.Cast(m_RootFrame.FindAnyWidget(widget_name));
	}	
	// Find a image widget in this layout
	protected ImageWidget FindImage(string widget_name)
	{
		return ImageWidget.Cast(m_RootFrame.FindAnyWidget(widget_name));
	}		
	// Find a image widget in this layout
	protected CheckBoxWidget FindCheckBox(string widget_name)
	{
		return CheckBoxWidget.Cast(m_RootFrame.FindAnyWidget(widget_name));
	}	
	
	// ------------------------------------------------
}