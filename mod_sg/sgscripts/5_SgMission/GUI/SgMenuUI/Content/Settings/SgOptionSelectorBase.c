modded class OptionSelectorBase 
{
	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;
				
		ButtonSetColor(w, SgCMenuColours.COLOUR_YELLOW);
	}
}