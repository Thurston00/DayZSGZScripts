/*
	Action Button style class. Colour, behaviours and sizes are according to UI Style Guide Action Button - (High importance)
	Used for the most important actions such as Play, Start ...
*/
class SgUiButtonActionHigh extends SgUiButton
{		
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_button/sg_button_action_high.layout";
	}
	override void LoadAllWidgets()
	{
		// Add diferent types of backgrounds 
		m_UiBackground.LoadImageFile(SgEButtonState.NORMAL, SgCMenuWidgetPaths.WHITE_PIXEL);
		m_UiBackground.LoadImageFile(SgEButtonState.HOVER, SgCMenuWidgetPaths.BUTTON_ACTION_HIGH_HOVER);
		
		super.LoadAllWidgets();
	}

	// ---------------------------------------
	
	override protected void SetColourNormal()
	{
		SetBackgroundColour(m_BackgroundColourNormal);
		SetFontColour(m_FontColourNormal);

		m_UiBackground.SetImage(SgEButtonState.NORMAL);
		m_UiUnderline.Show(false);
	}	
	override protected void SetColourHover()
	{
		SetBackgroundColour(m_BackgroundColourHover);
		SetFontColour(m_FontColourHover);	
		
		
		m_UiBackground.SetImage(SgEButtonState.HOVER);
		m_UiUnderline.Show(true);
	}	
	override protected void SetColourClicked(){}		
	override protected void SetColourDisabled()
	{
		SetBackgroundColour(m_BackgroundColourDisabled);
		SetFontColour(m_FontColourDisabled);
		
		m_UiBackground.SetImage(SgEButtonState.NORMAL);
		m_UiUnderline.Show(false);
	}
	
	// ---------------------------------------------
	
	override protected void SetBackgroundColours()
	{
		m_BackgroundColourNormal	= SgCMenuColours.COLOUR_YELLOW_TRANSPARENT_2;
		m_BackgroundColourHover		= SgCMenuColours.COLOUR_YELLOW;
		m_BackgroundColourDisabled	= SgCMenuColours.COLOUR_LIGHT_GREY_TRANSPARENT_1;
	}
	override protected void SetFontColours()
	{
		m_FontColourNormal			= SgCMenuColours.COLOUR_BLACK;
		m_FontColourHover			= SgCMenuColours.COLOUR_BLACK;
		m_FontColourDisabled		= SgCMenuColours.COLOUR_LIGHT_GREY_TRANSPARENT_2;
	}
}