class CasterTrackerFollower : ScriptedWidgetEventHandler
{
	protected	Widget	m_Root;
	protected	Object	m_Target;
	protected	vector	m_LocalCoord;
	
	reference	bool	m_OffScreenHide;
	reference	bool	m_ScaleWithDistance;
	
	reference	float	m_PivotX;
	reference	float	m_PivotY;
	
	protected	float	m_ReferenceX;
	protected	float	m_ReferenceY;
	
	void Init( Widget root, Object target, vector offset )
	{
		m_Root			= root;
		m_Target		= target;
		m_LocalCoord	= offset;
		
		m_Root.GetSize( m_ReferenceX, m_ReferenceY );
	}
	
	//-----------------------------------------
	// Update
	//-----------------------------------------
	void Update()
	{
		if( m_Target && m_Root )
		{
			vector pos = m_Target.CoordToParent( m_LocalCoord ) ;
			vector relative_pos = GetGame().GetScreenPosRelative( pos );
			float xs, ys;
			
			m_Root.GetSize( xs, ys );
			
			float z = relative_pos[2];
			
			if( m_ScaleWithDistance && z >= 40 )
			{
				xs = m_ReferenceX * ( 40 / z );
				ys = m_ReferenceY * ( 40 / z );
			}
			
			float x = relative_pos[0] - 0.5 + xs * m_PivotX;
			float y = relative_pos[1] - 0.5 + ys * m_PivotY;
			
			
			if ( m_OffScreenHide )
			{
				if ( z >= 0 )
				{
					if ( x >= 0.5 || x <= -0.5 )
					{
						m_Root.Show( false );
					}
					else if ( y >= 0.5 || y <= -0.5 )
					{
						m_Root.Show( false );
					}
					else
						m_Root.Show( true );
				}
				else
					m_Root.Show( false );
			}
			else // Snap to screen edges
			{
				if ( z <= 0 )
				{
					x = -x;
					
					if ( y >= 0 )
					{
						y = -0.5;
					}
					else
					{
						y = 0.5;
					}
				}
			}
			
			m_Root.SetPos(x, y, true);
			m_Root.SetSize(xs, ys, true);
		}
	}
};