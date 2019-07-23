class SgUiWarmUpPageControl extends SgUiMenuPanel
{
	// Widget
	private 	GridSpacerWidget 		m_UiPageGrid;
	private ref array<ImageWidget> 		m_PageImageButton = new array<ImageWidget>;
	private ref array<Widget> 			m_PageFrame = new array<Widget>;
	// Data
	private 	int 	m_PageCount;		
	private 	int 	m_SelectedIndex;
	// Event
	private ref ScriptInvoker Event_OnPageSelected;
	
	// Constructor
	void SgUiWarmUpPageControl(Widget parent, int page_count, ScriptInvoker event_warm_up_page_changed)
	{
		m_PageCount = page_count;
		Event_OnPageSelected = event_warm_up_page_changed;
		BuildLayout(parent);
	}
	
	// ---------------------------------------------
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_warm_up/sg_page_control.layout";
	}
	override protected void FindAllWidgets()
	{
		m_UiPageGrid = GridSpacerWidget.Cast(FindPanel("Grid"));
		
		for (int i = 0; i < m_PageCount; i++)
		{
			m_PageFrame.Insert(FindPanel("PageFrame_" + i));
			m_PageImageButton.Insert(FindImage("PageImage_" + i));
		}
		m_UiPageGrid.SetHandler(this);
	}
	override protected void LoadAllWidgets()
	{
		for (int i = 0; i < m_PageCount; i++)
		{
			ImageWidget image = m_PageImageButton.Get(i);
			image.LoadImageFile(0, SgCMenuWidgetPaths.HINT_NAVIGATION_NORMAL);
			image.LoadImageFile(1, SgCMenuWidgetPaths.HINT_NAVIGATION_SELECTED);
			
			m_PageFrame.Get(i).Show(true);
		}		
		OnPageSelected(0);
	}
	override protected void RegisterAllEvents()
	{
		Event_OnPageSelected.Insert(OnPageSelected);
	}
	
	// -------------------------------------------------
	
	private void OnPageSelected(int index)
	{
		m_SelectedIndex = index;
		ClearAll();
		m_PageImageButton.Get(index).SetImage(1);
	}
	
	private void ClearAll()
	{
		foreach(ImageWidget image : m_PageImageButton)
		{
			image.SetImage(0);
		}
	}
	
	// -------------------------------------------------
	
	override bool OnMouseButtonUp(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT)
		{
			for (int i = 0; i < m_PageImageButton.Count(); i++)
			{
				if (m_PageImageButton.Get(i) == w)
				{
					Event_OnPageSelected.Invoke(i);
					return true;
				}
			}
		}
		return false;
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{ 
		if (w)
		{
			w.SetColor(SgCMenuColours.COLOUR_YELLOW);
			return true;
		}
		
		return false;
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w)
		{
			w.SetColor(SgCMenuColours.COLOUR_WHITE_TRANSPARENT_1);
			return true;
		}
		return false;
	}
}