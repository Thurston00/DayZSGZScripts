class SgUiButtonMenuPrimaryImage extends SgUiButtonMenuPrimary
{	
	// Widgets
	protected ImageWidget m_UiImage;
	// Colours	
	protected int m_ImageColourNormal ,m_ImageColourHover, m_ImageColourPressed, m_ImageColourDisabled;
	
	// ---------------------------------------
	// OVERRIDES --> SgUiMenuPanel
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_button/sg_button_image.layout";
	}
	override void FindAllWidgets()
	{
		super.FindAllWidgets();
		
		m_UiImage = FindImage("Image");
	}
	
	// ------------------------------------------
		
	void SetImage(string image_path)
	{
		m_UiImage.LoadImageFile(0,image_path);
	}
	
	void SetImageColour(int colour)
	{
		m_UiImage.SetColor(colour);
	}
	
	private void SetImageColours()
	{
		m_ImageColourNormal		= SgCMenuColours.COLOUR_WHITE;
		m_ImageColourHover		= SgCMenuColours.COLOUR_YELLOW;
		m_ImageColourPressed	= SgCMenuColours.COLOUR_YELLOW_TRANSPARENT_1;
		m_ImageColourDisabled	= SgCMenuColours.COLOUR_YELLOW_TRANSPARENT_3;
	}
	
	// --------------------------------------
	// OVERRIDES --> SgUiButton
	
	override void SetContent(string text)
	{
		SetImage(text);
	}
	
	// Set default colour template
	override protected void SetDefaultColours()
	{
		SetImageColours();
	}
	
	override protected void SetColourNormal()
	{
		if (!m_IsSelected)
		{
			SetImageColour(m_ImageColourNormal);
		}
		else 
		{
			SetImageColour(m_ImageColourPressed);
		}
	}	
	
	override protected void SetColourHover()
	{
		SetImageColour(m_ImageColourHover);
	}	
	
	override protected void SetColourClicked() {	}	
	
	override protected void SetColourDisabled()
	{
		SetImageColour(m_ImageColourDisabled);
	}	
}