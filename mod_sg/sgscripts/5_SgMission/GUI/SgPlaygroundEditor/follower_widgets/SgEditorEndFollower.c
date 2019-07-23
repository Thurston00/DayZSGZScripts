class SgEditorEndFollower extends SgEditorObjectFollower
{
	protected int			m_PoIIndex;
	protected int			m_PhaseID;
	protected TextWidget	m_IDText;
	
	void SgEditorEndFollower( Widget root, SgJsonLocation location, int index, SgPlaygroundEditorMenu editor )
	{
		m_Location			= location;
		m_PoIIndex			= index;
		
		GetPosition();
		
		m_FollowerRoot		= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/follower_widgets/ph_end_follower.layout", root );
		m_FollowerButton	= m_FollowerRoot.FindAnyWidget( "IconPanel" );
		m_IDText			= TextWidget.Cast( m_FollowerRoot.FindAnyWidget( "Text" ) );
		
		m_MaxFade			= 1;
		m_MinFade			= 0.4;
		
		m_Editor			= editor;
		m_Manager			= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		
		m_IDText.SetText( m_PoIIndex.ToString() );
		
		m_FollowerRoot.SetHandler( this );
	}
	
	int GetPhaseID()
	{
		return m_Location.m_AreaID;
	}
	
	override void SetPosition( vector position )
	{
		m_Location.GetEndPositions().Set( m_PoIIndex, position );
		super.SetPosition( position );
	}
	
	override vector GetPosition()
	{
		m_Position = m_Location.GetEndPositions().Get( m_PoIIndex );
		if( m_FollowedObject && m_FollowedObject.GetPosition() != m_Position )
		{
			SetPosition( m_FollowedObject.GetPosition() );
		}
		return m_Position;
	}
}