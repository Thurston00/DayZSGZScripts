class SgUiPopupLoading extends SgUiPopup
{
	// Widgets
	private 		Widget 		m_UiContentFrame;
	private 		ImageWidget	m_UiLoadingImage;
	private 		ImageWidget	m_UiCancelImage;
	
	private 		float 		m_RotationValue = 0;
	private const 	int 		m_RotationRefreshRate = 5;		
	
	private 		bool 		m_Lock = false;
	
	private			float		m_AnimationLastTime;
	private			float		m_AnimationTimeElapsed;
	
	// ---------------------------------------
	
	void SgUiPopupLoading(string header)
	{
		m_HeaderText = header;
		BuildLayout();
	}
	
	// ---------------------------------------
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_popup_window/sg_popup_loading.layout";
	}
	override void FindAllWidgets()
	{
		super.FindAllWidgets();
		m_UiLoadingImage 	= FindImage("LoadingImage");
		m_UiCancelImage 	= FindImage("CancelImage");
		m_UiContentFrame 	= FindPanel("ContentFrame");
	}	
	override void LoadAllWidgets()
	{
		super.LoadAllWidgets();
		// Loading image
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(WaitingAnimation, m_RotationRefreshRate ,true, m_RotationValue);
		m_AnimationLastTime = GetGame().GetTime() * 0.001;
		m_UiContentFrame.SetHandler(this);
	}
	
	// ---------------------------------------
	
	void SetLock(bool lock)
	{
		m_Lock = lock;
	}
	
	// ---------------------------------------
	
	private void WaitingAnimation()
	{
		float curr_time = GetGame().GetTime() * 0.001;
		float time_delta = curr_time - m_AnimationLastTime;
		m_AnimationLastTime = curr_time;
		
		m_AnimationTimeElapsed += time_delta;
		
		if ( m_AnimationTimeElapsed > 0.04 )
		{
			m_AnimationTimeElapsed = 0;
						
			m_RotationValue += 22.5;
			// Set rotation
			m_UiLoadingImage.SetRotation( 0, 0, m_RotationValue);
			// Check if rotation is complete
			if (m_RotationValue == 360)
			{
				m_RotationValue = 0;
			}
		}
	}
	
	override bool OnMouseButtonUp(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT)
		{
			if (w == m_UiContentFrame)
			{
				if (!m_Lock)
				{
					Event_OnResponse.Invoke();
				}
				return true;
			}
		}
		return false;
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if ( w == m_UiContentFrame)
		{
			if (!m_Lock)
			{
				m_UiLoadingImage.Show(false);
				m_UiCancelImage.Show(true);
			}
			return true;
		}
		
		return false;
	}
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if ( w == m_UiContentFrame)
		{
			if (!m_Lock)
			{
				m_UiLoadingImage.Show(true);
				m_UiCancelImage.Show(false);
			}
			return true;
		}
		
		return false;
	}

}