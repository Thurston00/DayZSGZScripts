class SgEditorAIZoneFollower extends SgEditorObjectFollower
{
	protected TextWidget	m_IDText;
	protected Widget		m_IconBcg;
	protected ImageWidget	m_Icon;
	
	protected int			m_HerdIndex;
	protected int			m_AIZoneIndex;
	protected int 			m_Color;
	protected SgJsonAIZone  m_AIZoneData;
	protected ESgAIGroup 	m_AIGroup;
	
	void SgEditorAIZoneFollower( Widget root, SgJsonLocation location, int herdIndex, int aiZoneIndex, int color, SgPlaygroundEditorMenu editor, SgJsonAIZone aiZoneData, ESgAIGroup aiGroup )
	{
		m_Location			= location;
		m_AIGroup			= aiGroup;
		
		m_FollowerRoot		= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/follower_widgets/sg_ai_zone_follower.layout", root );
		m_FollowerButton	= m_FollowerRoot.FindAnyWidget( "IconPanel" );
		m_IDText			= TextWidget.Cast( m_FollowerRoot.FindAnyWidget( "Text" ) );
		m_IconBcg			= m_FollowerRoot.FindAnyWidget( "IconBcg" );
		m_Icon				= ImageWidget.Cast( m_FollowerRoot.FindAnyWidget( "Icon" ) );
		
		m_MaxFade			= 1;
		m_MinFade			= 0.4;
		
		m_Editor			= editor;
		m_AIZoneData		= aiZoneData;
		m_Manager			= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		
		SetColor(color);
		SetIcon(aiGroup);
		SetIndexes( herdIndex, aiZoneIndex );
		SetPosition( aiZoneData.GetPosition() );
		
		m_FollowerRoot.SetHandler( this );
	}
	
	int GetPhaseID()
	{
		return m_Location.m_AreaID;
	}
	
	int GetHerdIndex()
	{
		return m_HerdIndex;
	}
	
	int GetAIZoneIndex()
	{
		return m_AIZoneIndex;
	}
	
	ESgAIGroup GetAIGroup()
	{
		return m_AIGroup;
	}
	
	void SetIndexes( int herdIndex, int aiZoneIndex )
	{
		m_HerdIndex 	= herdIndex;
		m_AIZoneIndex = aiZoneIndex;
		
		m_IDText.SetText( m_HerdIndex.ToString() + "/" + m_AIZoneIndex.ToString() );
	}
	
	void SetColor(int color)
	{
		m_Color = color;
		
		m_IconBcg.SetColor( m_Color );
	}
	
	protected void SetIcon(ESgAIGroup aiGroup)
	{
		string imgPath;
		
		switch (aiGroup)
		{
			case ESgAIGroup.Patrol: 	
				imgPath = SgCEditorImagePaths.AI_GROUP_PATROL_ICON;
				break;
			case ESgAIGroup.Guard:		
				imgPath = SgCEditorImagePaths.AI_GROUP_GUARD_ICON;
				break;
			case ESgAIGroup.Static:		
				imgPath = SgCEditorImagePaths.AI_GROUP_STATIC_ICON;
				break;
			case ESgAIGroup.Screamer:	
				imgPath = SgCEditorImagePaths.AI_GROUP_SCREAMER_ICON;
				break;
		}
		
		m_Icon.LoadImageFile( 0, imgPath);
	}
	
	SgJsonAIZone GetAIZoneData()
	{
		return m_AIZoneData;
	}
	
	override void Update()
	{
		Debug.DrawCylinder( m_AIZoneData.GetPosition(), m_AIZoneData.GetRange(), 30, m_Color, ShapeFlags.ONCE + ShapeFlags.WIREFRAME );
		
		super.Update();
	}
	
	override void SetPosition( vector position )
	{
		m_AIZoneData.SetPosition(position);
	}
	
	override vector GetPosition()
	{		
		return m_AIZoneData.GetPosition();
	}
}
