/*! \class SgListView
 *	\brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
class SgListView : ScriptedWidgetEventHandler
{
	protected	float	m_RootXSize;
	protected	float	m_RootYSize;
	
	
	protected	float	m_ChildSize;
	protected	int		m_ChildCount;
	protected	Widget	m_Root;
	protected	bool	m_Refreshed = false;
	
	reference	bool	m_ResizeRoot;
	reference	bool	m_Resize;
	reference	bool	m_Horizontal;
	reference	bool	m_IgnoreInvisible;
	reference	bool	m_IgnoreFirst;
	reference	float	m_Gap;
	
	void RefreshChildCount()
	{
		Widget child = m_Root.GetChildren();
		
		if( child && m_IgnoreFirst )
			child = child.GetSibling();
		
		while( child )
		{
			if( !m_IgnoreInvisible || child.IsVisible() )
			{
				m_ChildCount++;
			}
			child = child.GetSibling();
		}
	}
	
	void RefreshSizes()
	{
		m_Root.GetSize( m_RootXSize, m_RootYSize );
		if( m_ChildCount > 0 )
		{
			m_ChildSize			= ( ( 1 - ( ( m_ChildCount - 1 ) * m_Gap ) ) /  m_ChildCount ) ;
		}
	}
	
	void Resize()
	{
		Widget child = m_Root.GetChildren();
		float total_size = 0;
		float xi, yi;
		if( m_Horizontal )
		{
			if( m_ResizeRoot )
			{
				if( child && m_IgnoreFirst )
					child = child.GetSibling();
				
				while( child )
				{
					if( !m_IgnoreInvisible || child.IsVisible() )
					{
						child.GetScreenSize( xi, yi );
						total_size += xi;
					}
					child = child.GetSibling();
				}
				m_Root.SetFlags( WidgetFlags.HEXACTSIZE );
				m_Root.GetScreenSize( xi,yi );
				if( total_size != xi )
				{
					m_Root.SetSize( total_size, m_RootYSize, false  );
					if( m_Root.GetParent() )
					{
						Realign();
						m_Root.GetParent().Update();
					}
				}
			}
			if( m_Resize )
			{
				ResizeHorizontal();
				Realign();
			}
		}
		else
		{
			if( m_ResizeRoot )
			{
				if( child && m_IgnoreFirst )
					child = child.GetSibling();
				
				while( child )
				{
					if( !m_IgnoreInvisible || child.IsVisible() )
					{
						child.GetScreenSize( xi, yi );
						total_size += yi;
					}
					child = child.GetSibling();
				}
				m_Root.SetFlags( WidgetFlags.VEXACTSIZE );
				m_Root.GetScreenSize( xi,yi );
				if( total_size != yi )
				{
					m_Root.SetSize( m_RootXSize, total_size, false );
					if( m_Root.GetParent() )
					{
						Realign();
						m_Root.GetParent().Update();
					}
				}
			}
			if( m_Resize )
			{
				ResizeVertical();
				Realign();
			}
		}
	}
	
	void ResizeHorizontal()
	{
		Widget child = m_Root.GetChildren();
		
		if( child && m_IgnoreFirst )
			child = child.GetSibling();
		
		while( child )
		{
			if( !m_IgnoreInvisible || child.IsVisible() )
			{
				child.SetSize( m_ChildSize, 1, false );
			}
			child = child.GetSibling();
		}
	}
	
	void ResizeVertical()
	{
		Widget child = m_Root.GetChildren();
		
		if( child && m_IgnoreFirst )
			child = child.GetSibling();
		
		while( child )
		{
			if( !m_IgnoreInvisible || child.IsVisible() )
			{
				child.SetSize( 1, m_ChildSize, false );
			}
			child = child.GetSibling();
		}
	}
	
	void RealignHorizontal()
	{
		float last_pos = 0;
		float total_size = 0;
		Widget child = m_Root.GetChildren();
		while( child )
		{
			if( !m_IgnoreInvisible || child.IsVisible() )
			{
				float x, y;
				float xi, yi;
				child.GetSize( x, y );
				child.GetScreenSize( xi, yi );
				child.SetPos( last_pos, 0, false );
				
				total_size += xi;
				last_pos += x + m_Gap;
			}
			child = child.GetSibling();
		}
	}
	
	void RealignVertical()
	{
		float last_pos = 0;
		float total_size = 0;
		Widget child = m_Root.GetChildren();
		while( child )
		{
			if( !m_IgnoreInvisible || child.IsVisible() )
			{
				float x, y;
				float xi, yi;
				child.GetSize( x, y );
				child.GetScreenSize( xi, yi );
				child.SetPos( 0, last_pos, false );
				
				total_size += yi;
				last_pos += y + m_Gap;
			}
			child = child.GetSibling();
		}
	}
	
	void Realign()
	{
		if( m_Horizontal )
			RealignHorizontal();
		else
			RealignVertical();
	}
	
	void Refresh()
	{
		if( !m_Refreshed )
		{
			RefreshSizes();
			Realign();
			Resize();
		}
		
		m_Refreshed = true;
	}
	
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	void OnWidgetScriptInit( Widget w )
	{
		m_Root = w;
		m_Root.SetHandler( this );
		RefreshChildCount();
		Refresh();
	}
		
/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	override bool OnChildAdd( Widget w, Widget  child )
	{
		super.OnChildAdd( w, child );
		if ( w == m_Root ) 
		{
			m_ChildCount++;
			m_Refreshed = false;
			Refresh();
			return true;
		}
		return false;
	}

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */
	override bool OnChildRemove( Widget w, Widget  child )
	{
		super.OnChildRemove( w, child );
		if ( w == m_Root )
		{
			m_ChildCount--;
			m_Refreshed = false;
			Refresh();
			return true;
		}
		return false;
	}

	override bool OnUpdate( Widget w )
	{
		if( w != m_Root )
		{
			Resize();
			return true;
		}
		return false;
	}
}