class SgUiTutorial extends SgUiMenuPanel
{
	private const string ROOT_PATH = "mod_sg/gui/layouts/sg_menu/sg_hint/sg_hint_base.layout";
	// Widgets
	private 	ImageWidget				m_UiImage;
	private ref SgUiButtonImage			m_UiNextButton;  
	private ref SgUiButtonImage			m_UiPreviousButton;
	private ref SgUiWarmUpPageControl	m_UiPageControl;
	private 	TextWidget				m_UiTextLabel;
	private 	TextWidget				m_UiTitleLabel;
	// Data
	private ref SgWarmUpContent  		m_ContentList 						= new SgWarmUpContent();
	private 	int 					m_PageIndex							= 0;
	private 	const int 				m_SlideShowDelay					= 25000;
	// Events	
	private ref ScriptInvoker			Event_NextButtonClicked_Left 		= new ScriptInvoker();
	private ref ScriptInvoker			Event_PreviousButtonClicked_Left 	= new ScriptInvoker();
	private ref ScriptInvoker			Event_OnContentChange 				= new ScriptInvoker();
	
	// ----------------------------------------
	
	void SgUiTutorial(Widget parent_widget)
	{		
		BuildLayout(parent_widget);
	}
	
	// ----------------------------------------------

	override string GetLayoutPath()
	{
		return ROOT_PATH;
	}
	override protected void FindAllWidgets()
	{
		m_UiImage	= FindImage("ContentImage");
		m_UiTextLabel = FindLabel("HintText");
		m_UiTitleLabel = FindLabel("TitleLabel");
	}
	override protected void LoadAllWidgets()
	{
		LoadContentList();
		
		m_UiNextButton			= new ref SgUiButtonImage(FindPanel("RightButtonFrame"), SgCMenuWidgetPaths.ARROW_RIGHT, Event_NextButtonClicked_Left);
		m_UiPreviousButton		= new ref SgUiButtonImage(FindPanel("LeftButtonFrame"), SgCMenuWidgetPaths.ARROW_LEFT, Event_PreviousButtonClicked_Left);
		m_UiPageControl			= new ref SgUiWarmUpPageControl(FindPanel("NavigationFrame"), m_ContentList.m_Hints.Count(), Event_OnContentChange );
	}
	override protected void RegisterAllEvents()
	{
		Event_NextButtonClicked_Left.Insert(ShowNextPage);
		Event_PreviousButtonClicked_Left.Insert(ShowPreviousPage);
		Event_OnContentChange.Insert(SetPageIndex);
	}
	override protected void UnRegisterAllEvents()
	{
		Event_NextButtonClicked_Left.Remove(ShowNextPage);
		Event_PreviousButtonClicked_Left.Remove(ShowPreviousPage);
		Event_OnContentChange.Remove(SetPageIndex);
	}
	
	// -----------------------------------------
	private void LoadContentList()
	{
		m_ContentList = SgSResourceHandler.LoadHintInfo();
		
		for (int i = 0; i < m_ContentList.m_Hints.Count(); i++)
		{
			m_UiImage.LoadImageFile(i, m_ContentList.m_Hints.Get(i).m_Image);
		}
		
		SetContent();
	}	
	
	private void SetPageIndex(int index)
	{
		m_PageIndex = index;
		SetContent();
	}
	
	private void SetContent()
	{
		SgWarmUpHint hint = m_ContentList.m_Hints.Get(m_PageIndex);
		if (hint)
		{
			m_UiTitleLabel.SetText(hint.m_Title); 	
			m_UiTextLabel.SetText(hint.m_Text);
			m_UiImage.SetImage(m_PageIndex);
		}
		
		RestartSlideShow();
	}
	
	private void ShowNextPage()
	{
		int index;
		
		if ( m_PageIndex < m_ContentList.m_Hints.Count() - 1 )
		{
			index = m_PageIndex + 1;
		}
		else 
		{
			index = 0;
		}
		
		Event_OnContentChange.Invoke(index);
	}	
	
	private void ShowPreviousPage()
	{
		int index;
		
		if ( m_PageIndex == 0 )
		{
			index = m_ContentList.m_Hints.Count() - 1;
		}
		else 
		{
			index = m_PageIndex - 1;
		}
		Event_OnContentChange.Invoke(index);
	}
	
	// -------------------------------------------
	// Slideshow 
	private void StartSlideshow()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(SlideshowThread, m_SlideShowDelay);
	}
	
	private void SlideshowThread()
	{
		ShowNextPage();
	}
	
	private void StopSlideShow()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(SlideshowThread);
	}
	
	private void RestartSlideShow()
	{
		StopSlideShow();
		StartSlideshow();
	}
}