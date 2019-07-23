modded class OptionSelector 
{
	override void ColorOption()
	{
		switch( m_SelectedOptionIndex )
		{
			case 0:
			{
				m_SelectedOption.SetColor( ARGB( 255, 255, 255, 255 ) );
				break;
			}
			case 1:
			{
				m_SelectedOption.SetColor( ARGB( 255, 255, 0, 0 ) );
				break;
			}
			case 2:
			{
				m_SelectedOption.SetColor( SgCMenuColours.COLOUR_YELLOW );
				break;
			}
		}
	}
}