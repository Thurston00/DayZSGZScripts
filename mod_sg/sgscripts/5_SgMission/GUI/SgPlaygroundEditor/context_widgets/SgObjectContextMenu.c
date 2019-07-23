class SgObjectContextMenu extends SgSWEH
{
	protected Widget					m_ContextRoot;
	
	protected SgEditorObjectFollower	m_ContextObject;
	
	protected SgJsonLocation			m_Location;
	protected SgPluginPgEditor			m_Manager;
	protected SgPlaygroundEditorMenu	m_Editor;
	
	void ~SgObjectContextMenu()
	{
		delete m_ContextRoot;
	}
	
	void OpenContext( SgEditorObjectFollower object, SgJsonLocation location )
	{
		m_ContextObject = object;
		m_Location = location;
		m_ContextRoot.Show( true );
		m_ContextRoot.Update();
	}
	
	void HideContext()
	{
		m_ContextObject = null;
		m_ContextRoot.Show( false );
		m_ContextRoot.Update();
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
		return false;
	}
	
	override bool OnMouseButtonUp( Widget w, int x, int y, int button )
	{
		return false;
	}
}