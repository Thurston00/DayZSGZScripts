modded class OptionSelectorSlider 
{
	override void ColorHighlight( Widget w )
	{
		if ( w )
		{
			if ( m_Slider )
			{
				SetFocus( m_Slider );
				m_Slider.SetColor( SgCMenuColours.COLOUR_YELLOW );
			}	
			else 
			{
				super.ColorHighlight( w );
			}
		}
	}
}