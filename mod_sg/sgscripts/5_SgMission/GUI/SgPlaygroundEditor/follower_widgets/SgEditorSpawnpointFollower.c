class SgEditorSpawnpointFollower extends SgEditorObjectFollower
{
	protected TextWidget			m_IDText;
	protected Widget				m_Icon;
	
	protected int					m_HerdIndex;
	protected int					m_SpawnpointIndex;
	protected int 					m_Color;
	protected SgJsonAIZone  		m_AIZoneData;
	protected SgJsonAISpawnPoint 	m_SpawnpointData;
	
	void SgEditorSpawnpointFollower( Widget root, SgJsonLocation location, int spawnpointIndex, int color, SgPlaygroundEditorMenu editor, SgJsonAIZone aiZoneData, SgJsonAISpawnPoint spawnpoint )
	{
		m_Location			= location;
		m_Color 			= color;
		
		m_FollowerRoot		= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/follower_widgets/sg_spawnpoint_follower.layout", root );
		m_FollowerButton	= m_FollowerRoot.FindAnyWidget( "IconPanel" );
		m_IDText			= TextWidget.Cast( m_FollowerRoot.FindAnyWidget( "Text" ) );
		m_Icon				= m_FollowerRoot.FindAnyWidget( "Icon" );
		
		m_MaxFade			= 1;
		m_MinFade			= 0.4;
		
		m_Editor			= editor;
		m_AIZoneData		= aiZoneData;
		m_SpawnpointData	= spawnpoint;
		m_Manager			= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		
		SetIndex( spawnpointIndex );
		SetPosition( spawnpoint.GetPosition() );
		
		m_FollowerRoot.SetHandler( this );
	}
	
	int GetPhaseID()
	{
		return m_Location.m_AreaID;
	}
	
	void SetIndex( int spawnpointIndex )
	{
		m_SpawnpointIndex 	= spawnpointIndex;
		
		m_IDText.SetText( m_SpawnpointIndex.ToString() );
	}
	
	SgJsonAISpawnPoint GetSpawnpointData()
	{
		return m_SpawnpointData;
	}
	
	override void Update()
	{
		Debug.DrawCylinder( m_SpawnpointData.GetPosition(), 0, 7, m_Color, ShapeFlags.ONCE + ShapeFlags.WIREFRAME );
		Debug.DrawSphere( m_SpawnpointData.GetPosition(), 0.25, m_Color, ShapeFlags.ONCE);
		Debug.DrawLine( m_SpawnpointData.GetPosition(), m_AIZoneData.GetPosition(), m_Color, ShapeFlags.ONCE + ShapeFlags.NOCULL + ShapeFlags.NOZBUFFER );
		
		super.Update();
	}
	
	override void SetPosition( vector position )
	{
		AIWorld aiWorld = GetGame().GetWorld().GetAIWorld();
		vector navmesh_position;
		aiWorld.SampleNavmeshPosition( position, 999, navmesh_position);
		
		m_SpawnpointData.SetPosition(navmesh_position);
	}
	
	override vector GetPosition()
	{		
		return  m_SpawnpointData.GetPosition();
	}
}
