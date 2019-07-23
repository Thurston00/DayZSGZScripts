class SgEndContextMenu extends SgObjectContextMenu
{
	protected Widget m_SetEndRadiusButton;
	protected Widget m_RemoveEndButton;
	
	void SgEndContextMenu( Widget root, SgPlaygroundEditorMenu editor )
	{
		m_ContextRoot			= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/context_widgets/pg_end_context.layout", root );
		m_SetEndRadiusButton	= ButtonWidget.Cast( m_ContextRoot.FindAnyWidget( "SetEndRadius" ) );
		m_RemoveEndButton		= ButtonWidget.Cast( m_ContextRoot.FindAnyWidget( "RemoveEnd" ) );
		m_Editor				= editor;
		m_Manager				= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		
		m_ContextRoot.SetHandler( this );
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( w == m_SetEndRadiusButton && button == MouseState.LEFT )
		{
			HideContext();
			return true;
		}
		else if( w == m_RemoveEndButton && button == MouseState.LEFT )
		{
			HideContext();
			return true;
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