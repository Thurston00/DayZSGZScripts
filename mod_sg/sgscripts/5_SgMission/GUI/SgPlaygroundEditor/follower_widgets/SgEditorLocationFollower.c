class SgEditorLocationFollower extends SgEditorObjectFollower
{
	protected int				m_Color;
	protected TextWidget		m_IDText;
	protected ImageWidget		m_TransIcon;
	
	protected ref array<ref SgEditorBorderFollower>		m_BorderWidgets;
	protected ref array<ref SgEditorEndFollower>		m_EndWidgets;
	protected ref array<ref SgEditorAIZoneFollower>		m_AIZoneWidgets;
	protected ref array<ref SgEditorSpawnpointFollower>	m_AISpawnpointWidgets;
	
	void SgEditorLocationFollower( Widget root, SgJsonLocation location, int color, SgPlaygroundEditorMenu editor )
	{
		m_Location			= location;
		m_Position			= location.GetPosition();
		
		switch( m_Location.m_LocationType )
		{
			case ESgLocationType.PhaseStart:
			{
				m_FollowerRoot	= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/follower_widgets/ph_spawn_follower.layout", root );
				CreateFollowedObject( "SG_StaticStartPointAll" );
				break;
			}
			case ESgLocationType.PhaseFirst:
			{
				m_FollowerRoot	= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/follower_widgets/ph_transmitter_follower.layout", root );
				CreateFollowedObject( "SG_StaticTransmitter" );
				break;
			}
			case ESgLocationType.PhaseSecond:
			{
				m_FollowerRoot	= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/follower_widgets/ph_transmitter_follower.layout", root );
				CreateFollowedObject( "SG_StaticTransmitter" );
				break;
			}
			case ESgLocationType.PhaseEnd:
			{
				m_FollowerRoot	= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/follower_widgets/ph_transmitter_follower.layout", root );
				CreateFollowedObject( "SG_StaticTransmitter" );
				break;
			}
			case ESgLocationType.PoIHeli:
			{
				m_FollowerRoot	= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/follower_widgets/ph_poi_follower.layout", root );
				break;
			}	
			case ESgLocationType.PoICar:
			{
				m_FollowerRoot	= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/follower_widgets/ph_poi_follower.layout", root );
				break;
			}	
		}
		
		m_IDText				= TextWidget.Cast( m_FollowerRoot.FindAnyWidget( "Text" ) );
		m_TransIcon				= ImageWidget.Cast( m_FollowerRoot.FindAnyWidget( "Icon" ) );
		m_FollowerButton		= m_FollowerRoot.FindAnyWidget( "IconPanel" );
		
		m_Color					= color;
		m_Editor				= editor;
		m_Manager				= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		
		m_BorderWidgets			= new array<ref SgEditorBorderFollower>;
		m_EndWidgets			= new array<ref SgEditorEndFollower>;
		m_AIZoneWidgets			= new array<ref SgEditorAIZoneFollower>;
		m_AISpawnpointWidgets 	= new array<ref SgEditorSpawnpointFollower>;
		
		m_MaxFade				= 0.8;
		m_MinFade				= 0.4;
		
		m_TransIcon.SetColor( m_Color );
		m_TransIcon.SetAlpha( 1 );
		m_IDText.SetText( ( m_Location.m_AreaID ).ToString() );
		
		m_FollowerRoot.SetHandler( this );
	}
	
	void ~SgEditorLocationFollower()
	{
		/*
		foreach( SgEditorObjectFollower ant : m_BorderWidgets )
		{
			delete ant;
		}
		foreach( SgEditorObjectFollower end : m_EndWidgets )
		{
			delete end;
		}
		*/
	}
	
	override void Update()
	{
		UpdatePos();
		vector last_pos;
		vector next_pos;
		
		m_Location.RecalculateBorderDistances();
		
		if( m_Location.m_LocationType == ESgLocationType.PhaseStart )
		{
			Debug.DrawCylinder( m_Position, m_Location.m_BorderRangeMax, 20, Colors.BLUE, ShapeFlags.ONCE + ShapeFlags.TRANSP );
			foreach( SgEditorBorderFollower border : m_BorderWidgets )
			{
				if( border )
					border.Update();
			}
		}
		else
		{
			for( int i = 1; i <= m_BorderWidgets.Count(); i++ )
			{
				SgEditorBorderFollower this_ant_update;
				SgEditorBorderFollower prev_ant_update;
				
				prev_ant_update	= m_BorderWidgets.Get( i - 1 );
				prev_ant_update.Update();
				
				if( i < m_BorderWidgets.Count() )
				{
					this_ant_update	= m_BorderWidgets.Get( i );
					this_ant_update.SetTowerID( i );
				}
				else
				{
					this_ant_update	= m_BorderWidgets.Get( 0 );
					this_ant_update.SetTowerID( 0 );
				}
				
				last_pos = prev_ant_update.GetPosition();
				next_pos = this_ant_update.GetPosition();
				Debug.DrawLine( last_pos, next_pos, m_Color, ShapeFlags.ONCE + ShapeFlags.NOCULL + ShapeFlags.NOZBUFFER );
			}
			
			foreach( SgEditorEndFollower poi_update : m_EndWidgets )
			{
				poi_update.Update();
			}
			
			for( i = 0; i < m_AIZoneWidgets.Count(); i++ )
			{
				m_AIZoneWidgets[i].Update();
				
				if ( m_AIZoneWidgets[i].GetAIGroup() == ESgAIGroup.Patrol && i + 1 < m_AIZoneWidgets.Count() && m_AIZoneWidgets[i].GetHerdIndex() == m_AIZoneWidgets[i + 1].GetHerdIndex() && m_AIZoneWidgets[i].GetAIZoneIndex() == m_AIZoneWidgets[i + 1].GetAIZoneIndex() - 1 )
				{
					Debug.DrawLine( m_AIZoneWidgets[i].GetPosition(), m_AIZoneWidgets[i + 1].GetPosition(), m_Color, ShapeFlags.ONCE + ShapeFlags.NOCULL + ShapeFlags.NOZBUFFER );
				}
			}
			
			foreach( SgEditorSpawnpointFollower spawnpointWidget : m_AISpawnpointWidgets )
			{
				spawnpointWidget.Update();
			}
		}
	}
	
	override void SetPosition( vector position )
	{
		super.SetPosition( position );
		m_Location.SetPosition( m_Position );
	}
	
	void FadePhase( bool fade )
	{
		Fade( fade );
		foreach( SgEditorObjectFollower ant_update : m_BorderWidgets )
		{
			ant_update.Fade( fade );
		}
		foreach( SgEditorObjectFollower poi_update : m_EndWidgets )
		{
			poi_update.Fade( fade );
		}
	}
	
	void AddBorderWidget( SgEditorBorderFollower widget )
	{
		m_BorderWidgets.Insert( widget );
	}
	
	void InsertBorderWidget( SgEditorBorderFollower widget, int index )
	{
		m_BorderWidgets.InsertAt( widget, index );
	}
	
	void RemoveBorderWidget( int index )
	{
		m_BorderWidgets.Remove( index );
	}
	
	void ClearBorderWidgets()
	{
		foreach( SgEditorObjectFollower ant : m_BorderWidgets )
		{
			delete ant;
		}
		m_BorderWidgets.Clear();
	}
	
	void AddEndWidget( SgEditorEndFollower widget )
	{
		m_EndWidgets.Insert( widget );
	}
	
	void AddAIZoneWidget( SgEditorAIZoneFollower widget )
	{		
		bool isInserted = false;
		
		int herdIndex = widget.GetHerdIndex();
		int aiZoneIndex = widget.GetAIZoneIndex();
		
		for ( int i = 0; i < m_AIZoneWidgets.Count(); i++ )
		{
			if ( m_AIZoneWidgets[i].GetAIGroup()== widget.GetAIGroup() && m_AIZoneWidgets[i].GetHerdIndex() == herdIndex && m_AIZoneWidgets[i].GetAIZoneIndex() == aiZoneIndex - 1 )
			{
				m_AIZoneWidgets.InsertAt( widget, i + 1 );
				isInserted = true;
			}
		}
		
		if (!isInserted)
		{
			m_AIZoneWidgets.Insert( widget );
		}
	}
	
	SgEditorAIZoneFollower GetAIZoneWidget( SgJsonAIZone aiZoneData )
	{
		for ( int i = 0; i < m_AIZoneWidgets.Count(); i++ )
		{
			if ( m_AIZoneWidgets[i].GetAIZoneData() == aiZoneData )
			{
				return m_AIZoneWidgets[i];
			}
		}
		
		return null;
	}
	
	void RemoveAIZoneWidget( SgEditorAIZoneFollower widget )
	{
		m_AIZoneWidgets.RemoveOrdered( m_AIZoneWidgets.Find(widget) );
	}
	
	void AddAISpawnpointWidget( SgEditorSpawnpointFollower widget ) 
	{
		m_AISpawnpointWidgets.Insert(widget);
	}
	
	void RemoveSpawnpointWidget( SgEditorSpawnpointFollower widget )
	{
		m_AISpawnpointWidgets.Remove( m_AISpawnpointWidgets.Find(widget) );
	}
	
	SgEditorSpawnpointFollower GetSpawnpointWidget( SgJsonAISpawnPoint spawnpointData )
	{
		for ( int i = 0; i < m_AISpawnpointWidgets.Count(); i++ )
		{
			if ( m_AISpawnpointWidgets[i].GetSpawnpointData() == spawnpointData )
			{
				return m_AISpawnpointWidgets[i];
			}
		}
		
		return null;
	}
	
	int GetAreaID()
	{
		return m_Location.m_AreaID;
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		return false;
	}
}
