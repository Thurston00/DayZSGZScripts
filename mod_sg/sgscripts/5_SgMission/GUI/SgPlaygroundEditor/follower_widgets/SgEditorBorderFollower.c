class SgEditorBorderFollower extends SgEditorObjectFollower
{
	protected int				m_TowerID;
	
	protected TextWidget		m_IDText;
	protected ImageWidget		m_AntIcon;
	
	void SgEditorBorderFollower( Widget root, SgJsonLocation location, int index, int color, SgPlaygroundEditorMenu editor )
	{
		m_Location				= location;
		m_TowerID				= index;
		
		GetPosition();
		
		m_FollowerRoot			= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/follower_widgets/ph_antenna_follower.layout", root );
		
		m_FollowerButton		= m_FollowerRoot.FindAnyWidget( "IconPanel" );
		m_IDText				= TextWidget.Cast( m_FollowerRoot.FindAnyWidget( "Text" ) );
		m_AntIcon				= ImageWidget.Cast( m_FollowerRoot.FindAnyWidget( "Icon" ) );
		
		m_MaxFade				= 0.85;
		m_MinFade				= 0.24;
		
		m_Editor				= editor;
		m_Manager				= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		
		m_AntIcon.SetColor( color );
		m_AntIcon.SetAlpha( 1 );
		
		if( m_Location.m_IsBorderVisible )
		{
			CreateFollowedObject( "SG_StaticAntenna" );
		}
		
		m_FollowerRoot.SetHandler( this );
	}
	
	override void Update()
	{
		super.Update();
		m_IDText.SetText( m_TowerID.ToString() );
	}
	
	override void SetPosition( vector position )
	{
		m_Location.GetBorderPositions().Set( m_TowerID, position );
		super.SetPosition( position );
	}
	
	override vector GetPosition()
	{
		m_Position = m_Location.GetBorderPositions().Get( m_TowerID );
		if( m_FollowedObject && m_FollowedObject.GetPosition() != m_Position )
		{
			SetPosition( m_FollowedObject.GetPosition() );
		}
		return m_Position;
	}
	
	void SetTowerID( int id )
	{
		m_TowerID = id;
	}
	
	int GetPhaseID()
	{
		return m_Location.m_AreaID;
	}
	
	int GetBorderPointID()
	{
		return m_TowerID;
	}
}