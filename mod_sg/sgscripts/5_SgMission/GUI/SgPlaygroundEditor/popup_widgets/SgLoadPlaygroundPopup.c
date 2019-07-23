class SgLoadPlaygroundPopup extends SgSWEH
{
	protected Widget					m_RootWidget;
	protected TextListboxWidget			m_PgList;
	protected ButtonWidget				m_LoadButton;
	protected ButtonWidget				m_CreateButton;
	protected ButtonWidget				m_DeleteButton;
	protected ButtonWidget				m_DefaultButton;
	
	protected Widget					m_PopupWidget;
	protected ButtonWidget				m_ConfirmButton;
	protected ButtonWidget				m_CancelButton;
	
	protected SgPluginPgEditor			m_Manager;
	protected SgPlaygroundEditorMenu	m_Editor;
	
	void SgLoadPlaygroundPopup( Widget root, SgPlaygroundEditorMenu root_menu )
	{
		m_Editor		= root_menu;
		m_Manager		= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) ).GetInstance();
		m_RootWidget	= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/popup_widgets/pg_select_popup.layout", root );
		m_PgList		= TextListboxWidget.Cast( m_RootWidget.FindAnyWidget( "PgList" ) );
		m_LoadButton	= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "LoadButton" ) );
		m_CreateButton	= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "CreateButton" ) );
		m_DeleteButton	= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "DeleteButton" ) );
		m_DefaultButton	= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "DefaultButton" ) );
		
		m_PopupWidget	= m_RootWidget.FindAnyWidget( "Popup" );
		m_ConfirmButton	= ButtonWidget.Cast( m_PopupWidget.FindAnyWidget( "ConfirmButton" ) );
		m_CancelButton	= ButtonWidget.Cast( m_PopupWidget.FindAnyWidget( "CancelButton" ) );
		m_RootWidget.SetHandler( this );

		LoadPlaygrounds();
	}
	
	void ~SgLoadPlaygroundPopup()
	{
		delete m_RootWidget;
	}
	
	void LoadPlaygrounds()
	{
		array<ref SgJsonPlayground> playgrounds = SgPluginPgEditor.GetInstance().GetPlaygrounds();
		for( int i = 0; i < playgrounds.Count(); i++ )
		{
			SgJsonPlayground pg = playgrounds.Get(i);
			int pos = m_PgList.AddItem( pg.m_PGID.ToString(), null, 0);
			m_PgList.SetItem( pos, pg.m_PGName, null, 1);
			m_PgList.SetItem( pos, pg.m_PGMapName, null, 2);
			m_PgList.SelectRow( i );
		}
	}
	
	int GetSelectedPlaygroundID()
	{
		int		pos = m_PgList.GetSelectedRow();
		string	pg_id;
		m_PgList.GetItemText( pos, 0, pg_id );
		return pg_id.ToInt();
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if( w == m_LoadButton && button == MouseState.LEFT )
		{
			SgJsonPlayground pg = m_Manager.LoadPlayground( GetSelectedPlaygroundID() );
			m_Editor.TogglePopup( false );
			m_Editor.ToggleTitlebar( true );
			m_Editor.ClosePopup();
			return true;
		}
		else if( w == m_CreateButton && button == MouseState.LEFT )
		{
			m_Editor.OpenCreatePopup();
			return true;
		}
		else if( w == m_DeleteButton && button == MouseState.LEFT )
		{
			m_PopupWidget.Show(true);
			return true;
		}
		else if( w == m_ConfirmButton && button == MouseState.LEFT )
		{
			int selected_row = m_PgList.GetSelectedRow();
			m_PopupWidget.Show(false);
			m_Manager.DeletePlayground( GetSelectedPlaygroundID() );
			m_PgList.RemoveRow( selected_row );
			return true;
		}
		else if( w == m_CancelButton && button == MouseState.LEFT )
		{
			m_PopupWidget.Show(false);
			return true;
		}
		else if( w == m_DefaultButton && button == MouseState.LEFT )
		{
			m_Manager.SetDefaultPlayground( GetSelectedPlaygroundID() );
			return true;
		}
		return false;
	}
}