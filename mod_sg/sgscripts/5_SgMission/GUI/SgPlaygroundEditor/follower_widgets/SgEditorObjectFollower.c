class SgEditorObjectFollower extends SgSWEH
{
	protected Widget					m_FollowerRoot;
	protected Widget					m_FollowerButton;
	
	protected vector					m_Position;
	protected EntityAI					m_FollowedObject;
	
	protected SgJsonLocation			m_Location;
	
	protected float						m_MaxFade;
	protected float						m_MinFade;
	
	protected SgPluginPgEditor			m_Manager;
	protected SgPlaygroundEditorMenu	m_Editor;
	
	void ~SgEditorObjectFollower()
	{
		DestroyFollowedObject();
		delete m_FollowerRoot;
	}
	
	void CreateFollowedObject( string type )
	{
		m_FollowedObject = EntityAI.Cast( GetGame().CreateObject( type, m_Position ) );
		SetPosition( m_Position );
	}
	
	void DestroyFollowedObject()
	{
		if( m_FollowedObject )
		{
			GetGame().ObjectDelete( m_FollowedObject );
		}
	}
	
	override void Update()
	{
		UpdatePos();
	}
	
	EntityAI GetObj()
	{
		return m_FollowedObject;
	}
	
	void SetPosition( vector position )
	{
		m_Position = position;
		if( m_FollowedObject )
		{
			m_FollowedObject.SetPosition( position );
			m_FollowedObject.PlaceOnSurface();
		}
		UpdatePos();
	}
	
	void SetRotation( vector dir )
	{
		if( m_FollowedObject )
		{
			m_FollowedObject.SetDirection( dir );
		}
	}
	
	vector GetPosition()
	{
		return m_Position;
	}
	
	vector GetRotation()
	{
		if( m_FollowedObject )
		{
			return m_FollowedObject.GetDirection();
		}
		return "0 0 0";
	}
	
/*! \brief Function updating the position of the tracker widget.
 *	
 *	Currently tracks using GetScreenPos() on the position of the player.
 */
	void UpdatePos()
	{
		vector relativePos;
			
		relativePos		=	GetGame().GetScreenPosRelative( GetPosition() );
		
		if( relativePos[0] >= 1 || relativePos[0] == 0 || relativePos[1] >= 1 || relativePos[1] == 0 )
		{
			m_FollowerRoot.Show( false );
			return;
		}
		else if( relativePos[2] < 0 )
		{
			m_FollowerRoot.Show( false );
			return;
		}
		else
		{
			m_FollowerRoot.Show( true );
		}
		
		float x, y;
		m_FollowerRoot.GetSize( x, y );
		
		m_FollowerRoot.SetPos( relativePos[0], relativePos[1] );
	}
	
	void Fade( bool fade )
	{
		if( fade )
		{
			m_FollowerRoot.SetAlpha( m_MinFade );
		}
		else
		{
			m_FollowerRoot.SetAlpha( m_MaxFade );
		}
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		return false;
	}
	
	override bool OnDoubleClick( Widget w, int x, int y, int button )
	{
		return false;
	}
	
	override bool OnMouseButtonDown( Widget w, int x, int y, int button )
	{
		if( w == m_FollowerButton && button == MouseState.LEFT )
		{
			if( m_Editor )
			{
				m_Editor.SelectObject( this );
			}
			return true;
		}
		return false;
	}
	
	override bool OnMouseButtonUp( Widget w, int x, int y, int button )
	{
		if( w == m_FollowerButton && button == MouseState.LEFT )
		{
			if( m_Editor )
			{
				m_Editor.SelectObject( null );
			}
			return true;
		}
		else
		if( w == m_FollowerButton && MouseState.RIGHT )
		{
			m_Editor.ShowContextMenu( this, x, y );
		}
		return false;
	}
}