class SgStartContextMenu extends SgObjectContextMenu
{
	protected Widget m_SetSpawnRadiusButton;
	
	void SgStartContextMenu( Widget root, SgPlaygroundEditorMenu editor )
	{
		m_ContextRoot			= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/context_widgets/pg_spawn_context.layout", root );
		m_SetSpawnRadiusButton	= ButtonWidget.Cast( m_ContextRoot.FindAnyWidget( "SetSpawnRadius" ) );
		
		m_Editor				= editor;
		m_Manager				= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		
		m_ContextRoot.SetHandler( this );
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( w == m_SetSpawnRadiusButton && button == MouseState.LEFT )
		{
			
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