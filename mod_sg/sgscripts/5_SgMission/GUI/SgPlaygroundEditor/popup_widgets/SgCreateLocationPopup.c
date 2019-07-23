class SgCreateLocationPopup extends SgSWEH
{
	protected Widget					m_RootWidget;
	
	protected TextListboxWidget			m_LocationListWidget;
	protected ButtonWidget				m_ConfirmButton;
	protected ButtonWidget				m_CancelButton;
	
	protected SgPluginPgEditor			m_Manager;
	protected SgPlaygroundEditorMenu	m_Editor;
	
	void SgCreateLocationPopup( Widget root, SgPlaygroundEditorMenu root_menu )
	{
		m_Editor				= root_menu;
		m_Manager				= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) ).GetInstance();
		m_RootWidget			= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/popup_widgets/sg_list_selection_popup.layout", root );
		
		m_LocationListWidget	= TextListboxWidget.Cast( m_RootWidget.FindAnyWidget( "LocationList" ) );
		m_ConfirmButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "ConfirmButton" ) );
		m_CancelButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "CancelButton" ) );
		
				
		m_LocationListWidget.AddItem( "Start",				new Param1<ESgLocationType>(ESgLocationType.PhaseStart), 0 );
		m_LocationListWidget.AddItem( "First Phase", 		new Param1<ESgLocationType>(ESgLocationType.PhaseFirst), 0 );
		m_LocationListWidget.AddItem( "Second Phase",		new Param1<ESgLocationType>(ESgLocationType.PhaseSecond), 0 );
		m_LocationListWidget.AddItem( "End Phase",			new Param1<ESgLocationType>(ESgLocationType.PhaseEnd), 0 );
		m_LocationListWidget.AddItem( "PoI Heli Crash",		new Param1<ESgLocationType>(ESgLocationType.PoIHeli), 0 );
		m_LocationListWidget.AddItem( "PoI Car Crash",		new Param1<ESgLocationType>(ESgLocationType.PoICar), 0 );
		
		m_LocationListWidget.SelectRow( 0 );
		
		m_RootWidget.SetHandler( this );
	}
	
	void ~SgCreateLocationPopup()
	{
		delete m_RootWidget;
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if( w == m_ConfirmButton && button == MouseState.LEFT )
		{
			Param1<ESgLocationType> par = new Param1<ESgLocationType>(ESgLocationType.None);
			m_LocationListWidget.GetItemData(m_LocationListWidget.GetSelectedRow(), 0, par);
			ESgLocationType type = par.param1;
			
			SgJsonLocation location = m_Manager.InsertLocation( type );
			m_Editor.StartPlacingLocation( location );
			m_Editor.ClosePopup();
			return true;
		}
		else if( w == m_CancelButton && button == MouseState.LEFT )
		{
			m_Editor.ClosePopup();
			return true;
		}
		return false;
	}
}
