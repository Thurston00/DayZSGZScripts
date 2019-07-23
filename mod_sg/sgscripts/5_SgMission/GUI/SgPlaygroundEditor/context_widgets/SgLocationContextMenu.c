class SgLocationContextMenu extends SgObjectContextMenu
{
	protected Widget m_EditLocationButton;
	protected Widget m_ClearBorderPointsButton;
	
	void SgLocationContextMenu( Widget root, SgPlaygroundEditorMenu editor )
	{
		m_ContextRoot				= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/context_widgets/pg_location_context.layout", root );
		m_EditLocationButton		= ButtonWidget.Cast( m_ContextRoot.FindAnyWidget( "EditLocation" ) );
		m_ClearBorderPointsButton	= ButtonWidget.Cast( m_ContextRoot.FindAnyWidget( "ClearBorderPoints" ) );
		
		m_Editor					= editor;
		m_Manager					= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		
		m_ContextRoot.SetHandler( this );
	}
	
	void ~SgLocationContextMenu()
	{
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( w == m_EditLocationButton && button == MouseState.LEFT && m_Location )
		{
			m_Editor.SelectLocation( m_Location );
			HideContext();
			return true;
		}
		else if( w == m_ClearBorderPointsButton && button == MouseState.LEFT && m_Location )
		{
			m_Editor.ClearBorderPoints( m_Location );
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