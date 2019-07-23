class SgBorderContextMenu extends SgObjectContextMenu
{
	protected Widget m_AddBorderPointBeforeButton;
	protected Widget m_AddBorderPointAfterButton;
	protected Widget m_RemoveBorderPointButton;
	
	void SgBorderContextMenu( Widget root, SgPlaygroundEditorMenu editor )
	{
		m_ContextRoot					= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/context_widgets/pg_antenna_context.layout", root );
		m_AddBorderPointBeforeButton	= ButtonWidget.Cast( m_ContextRoot.FindAnyWidget( "AddBefore" ) );
		m_AddBorderPointAfterButton		= ButtonWidget.Cast( m_ContextRoot.FindAnyWidget( "AddAfter" ) );
		m_RemoveBorderPointButton		= ButtonWidget.Cast( m_ContextRoot.FindAnyWidget( "Remove" ) );
		m_Editor						= editor;
		m_Manager						= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		m_ContextRoot.SetHandler( this );
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		SgEditorBorderFollower border_point			= SgEditorBorderFollower.Cast( m_ContextObject );
		
		if( border_point && m_Location )
		{
			if( w == m_AddBorderPointBeforeButton && button == MouseState.LEFT )
			{
				m_Editor.InsertBorderPoint( m_Location, border_point.GetBorderPointID() );
				HideContext();
			}
			else if( w == m_AddBorderPointAfterButton && button == MouseState.LEFT )
			{
				m_Editor.InsertBorderPoint( m_Location, border_point.GetBorderPointID() + 1 );
				HideContext();
			}
			else if( w == m_RemoveBorderPointButton && button == MouseState.LEFT )
			{
				m_Editor.RemoveBorderPoint( m_Location, border_point.GetBorderPointID() );
				HideContext();
			}
		}
		return false;
	}
	
	override bool OnDoubleClick( Widget w, int x, int y, int button )
	{
		return false;
	}
	
	override bool OnMouseButtonDown( Widget w, int x, int y, int button )
	{
		return false;
	}
	
	override bool OnMouseButtonUp( Widget w, int x, int y, int button )
	{
		return false;
	}
}