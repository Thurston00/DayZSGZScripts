class SgUiTabberUI extends TabberUI
{
	// Dayz Trash --> the align does not work for SG settings. It needs to disabled 
	override void AlignTabbers(){}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{		
		int index = m_TabControls.GetKeyByValue( w );
		Widget tab_control = m_TabControls.Get( index );
		if ( tab_control )
		{			
			Widget tab_title = TextWidget.Cast(tab_control.FindAnyWidget( tab_control.GetName() + "_Title" ));
			Widget tab_underline = tab_title.FindAnyWidget( tab_control.GetName() + "_Underline" );
			
			if ( m_SelectedIndex == index )		// Selected hover
			{ 		
				tab_control.SetColor( SgCMenuColours.COLOUR_YELLOW );
			}
			else								// Unselected hover
			{			
				tab_control.SetColor( SgCMenuColours.COLOUR_LIGHT_GREY_TRANSPARENT_1 );
			}
			
			tab_title.SetColor( SgCMenuColours.COLOUR_WHITE );  
			tab_underline.SetColor( SgCMenuColours.COLOUR_WHITE );
			tab_underline.Show(true);			
			
			return true;
		}
		
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		int index = m_TabControls.GetKeyByValue( w );
		Widget tab_control = m_TabControls.Get( index );
		
		if ( tab_control )
		{			
			Widget tab_title = TextWidget.Cast(tab_control.FindAnyWidget( tab_control.GetName() + "_Title" ));
			Widget tab_underline = tab_title.FindAnyWidget( tab_control.GetName() + "_Underline" );
						
			if ( m_SelectedIndex == index )
			{
				tab_title.SetColor( SgCMenuColours.COLOUR_BLACK ); 					
				tab_control.SetColor( SgCMenuColours.COLOUR_YELLOW_TRANSPARENT_2 );
			}
			else 
			{
				tab_title.SetColor( SgCMenuColours.COLOUR_WHITE );
				tab_control.SetColor( ARGB(0, 0, 0 ,0) );
			}
			
			tab_underline.Show(false);
			
		}
		return false;
	}
	
	override void SelectTabControl( int index )
	{
		Widget tab_control = m_TabControls.Get( index );
		if( tab_control )
		{
			Widget tab_title = TextWidget.Cast(tab_control.FindAnyWidget( tab_control.GetName() + "_Title" ));
			Widget tab_underline = tab_title.FindAnyWidget( tab_control.GetName() + "_Underline" );
			
			tab_control.SetColor( SgCMenuColours.COLOUR_YELLOW );
			tab_title.SetColor( SgCMenuColours.COLOUR_WHITE );  
			tab_underline.SetColor( SgCMenuColours.COLOUR_WHITE );
			tab_underline.Show(true);			
		}
	}
}