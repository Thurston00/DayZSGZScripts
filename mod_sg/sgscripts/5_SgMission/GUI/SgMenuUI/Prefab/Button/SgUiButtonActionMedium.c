/*
	Action Button style class. Colour, behaviours and sizes are according to UI Style Guide Action Button - (Medium importance)
	Used for the common action buttons such as Apply, Join, Add...
*/
class SgUiButtonActionMedium extends SgUiButton
{
	protected ref array<Widget> m_UiBorder;
	
	protected int m_BorderColourNormal, m_BorderColourDisabled;
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_button/sg_button_action_medium.layout";
	}
	override void FindAllWidgets()
	{
		super.FindAllWidgets();
		
		// Borders
		m_UiBorder = new ref array<Widget>;
		m_UiBorder.Insert(FindPanel("Border"));
		m_UiBorder.Insert(FindPanel("BorderTop"));
		m_UiBorder.Insert(FindPanel("BorderRight"));
		m_UiBorder.Insert(FindPanel("BorderBottom"));
		m_UiBorder.Insert(FindPanel("BorderLeft"));
	}
	override void LoadAllWidgets()
	{
		// Add diferent types of backgrounds 
		m_UiBackground.LoadImageFile(SgEButtonState.NORMAL, SgCMenuWidgetPaths.WHITE_PIXEL);
		super.LoadAllWidgets();
	}

	// ---------------------------------------
	
	override protected void SetColourNormal()
	{
		super.SetColourNormal();

		m_UiBackground.SetColor(m_BackgroundColourNormal);
		SetBorderColour(m_BorderColourNormal);
		SetBorderVisibility(true);
		m_UiUnderline.Show(false);
	}	
	override protected void SetColourHover()
	{
		super.SetColourHover();
		
		m_UiBackground.SetColor(m_BackgroundColourHover);
		SetBorderVisibility(false);
		m_UiUnderline.Show(true);
	}	
	override protected void SetColourClicked()
	{}		
	override protected void SetColourDisabled()
	{
		super.SetColourDisabled();
		
		m_UiBackground.SetColor(m_BackgroundColourDisabled);
		SetBorderColour(m_BorderColourDisabled);
		SetBorderVisibility(true);
		m_UiUnderline.Show(false);
	}
	
	// ---------------------------------------------
		
	protected void SetBorderColour(int colour)
	{
		foreach (Widget widget : m_UiBorder)
		{
			widget.SetColor(colour);
		}
	}
	
	protected void SetBorderVisibility(bool visibility)
	{
		m_UiBorder[SgEWidgetBorder.BORDER].Show(visibility);
	}
	// ---------------------------------------------
	
	override protected void SetDefaultColours()
	{
		super.SetDefaultColours();
		SetBorderColours();
	}
	
	override protected void SetBackgroundColours()
	{
		m_BackgroundColourNormal	= SgCMenuColours.COLOUR_YELLOW_TRANSPARENT_3;
		m_BackgroundColourHover		= SgCMenuColours.COLOUR_YELLOW;
		m_BackgroundColourDisabled	= SgCMenuColours.COLOUR_LIGHT_GREY_TRANSPARENT_1;
	}
	override protected void SetFontColours()
	{
		m_FontColourNormal			= SgCMenuColours.COLOUR_YELLOW;
		m_FontColourHover			= SgCMenuColours.COLOUR_BLACK;
		m_FontColourDisabled		= SgCMenuColours.COLOUR_LIGHT_GREY_TRANSPARENT_2;
	}
	protected void SetBorderColours()
	{
		m_BorderColourNormal 		= SgCMenuColours.COLOUR_YELLOW;
		m_BorderColourDisabled		= SgCMenuColours.COLOUR_LIGHT_GREY;
	}
}

enum SgEWidgetBorder
{
	BORDER
	TOP,
	RIGHT,
	BOTTOM,
	LEFT,
}