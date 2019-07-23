class SgFadeScreen extends SgSWEH
{
	protected	Widget		m_Root;
	protected	ref Timer	m_FadeTimer;
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void SgFadeScreen( Widget root )
	{
		m_Root = root;
		m_FadeTimer = new Timer(CALL_CATEGORY_GUI);
		if( GetGame().GetUIManager() )
		{
			// Disable Cursor
			GetGame().GetUIManager().ShowCursor(false);
		}
	}
	
	void FadeIn( float fade_in_time )
	{
		m_Root.SetAlpha( 0 );
		if( m_FadeTimer.IsRunning() )
		{
			m_FadeTimer.Stop();
		}
		GetSgGame().SgSetMenu( this );
		m_FadeTimer.Run( ( fade_in_time / 50.0 ), this, "RaiseFade", null, true );
	}
	
	void FadeOut( float fade_out_time )
	{
		if( m_FadeTimer.IsRunning() )
		{
			m_FadeTimer.Stop();
		}
		
		m_FadeTimer.Run( ( fade_out_time / 50.0 ), this, "LowerFade", null, true );
	}
	
	void RaiseFade()
	{
		float alpha = m_Root.GetAlpha() + ( 1.0 / 50.0 );
		if( alpha < 1 )
		{
			m_Root.SetAlpha( alpha  );
		}
		else
		{
			m_Root.SetAlpha( 1 );
			m_FadeTimer.Stop();
		}
	}
	
	void LowerFade()
	{
		float alpha = m_Root.GetAlpha() - ( 1.0 / 50.0 );
		if( alpha > 0 )
		{
			m_Root.SetAlpha( alpha );
		}
		else
		{
			m_Root.SetAlpha( 0 );
			m_FadeTimer.Stop();
		}
	}
}