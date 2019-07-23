modded class KeybindingElement
{
	override string GetLayoutName()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_settings/sg_keybinding_option.layout";
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( w == m_PrimaryBindButton || w == m_PrimaryClear )
		{
			m_PrimaryBindButton.SetColor( ARGB( 255, 232, 212, 85 ) );
			m_PrimaryClear.Show( true );
			m_PrimaryClear.Update();
			m_AlternativeClear.Show( false );
			return true;
		}
		else if( w == m_AlternativeBindButton || w == m_AlternativeClear )
		{
			m_AlternativeBindButton.SetColor( ARGB( 255, 233, 212, 85 ) );
			m_PrimaryClear.Show( false );
			m_AlternativeClear.Show( true );
			m_AlternativeClear.Update();
			return true;
		}
		else
		{
			m_PrimaryBindButton.SetColor( ARGBF( 0, 0, 0, 0 ) );
			m_AlternativeBindButton.SetColor( ARGBF( 1, 0, 0, 0 ) );
			m_PrimaryClear.Show( false );
			m_AlternativeClear.Show( false );
		}
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( w == m_PrimaryClear || w == m_PrimaryBindButton )
		{
			if( enterW != m_PrimaryClear && enterW != m_PrimaryBindButton )
			{
				m_PrimaryClear.Show( false );
				m_PrimaryBindButton.SetColor( ARGBF( 1, 0, 0, 0 ) );
			}
		}
		if( w == m_AlternativeClear || w == m_AlternativeBindButton )
		{
			if( enterW != m_AlternativeClear && enterW != m_AlternativeBindButton )
			{
				m_AlternativeClear.Show( false );
				m_AlternativeBindButton.SetColor( ARGBF( 1, 0, 0, 0 ) );
			}
		}
		return false;
	}
}

