class SgCreatePlaygroundPopup extends SgSWEH
{
	protected Widget					m_RootWidget;
	protected ButtonWidget				m_CreateButton;
	
	protected TextListboxWidget			m_MissionList;
	protected EditBoxWidget				m_Name;
	protected EditBoxWidget				m_PlayerCount;
	protected MultilineEditBoxWidget	m_Description;
	protected EditBoxWidget				m_Details;
	
	protected SgPluginPgEditor			m_Manager;
	protected SgPlaygroundEditorMenu	m_Editor;
	
	void SgCreatePlaygroundPopup( Widget root, SgPlaygroundEditorMenu root_menu )
	{
		m_Editor		= root_menu;
		m_Manager		= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) ).GetInstance();
		
		m_RootWidget	= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/popup_widgets/pg_create_popup.layout", root );
		m_CreateButton	= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "CreateButton" ) );
		
		m_MissionList	= TextListboxWidget.Cast( m_RootWidget.FindAnyWidget( "MissionList" ) );
		m_Name			= EditBoxWidget.Cast( m_RootWidget.FindAnyWidget( "NameEditBox" ) );
		m_PlayerCount	= EditBoxWidget.Cast( m_RootWidget.FindAnyWidget( "PlayerEditBox" ) );
		m_Description	= MultilineEditBoxWidget.Cast( m_RootWidget.FindAnyWidget( "DescriptionEditBox" ) );
		m_Details		= EditBoxWidget.Cast( m_RootWidget.FindAnyWidget( "DetailsEditBox" ) );
		
		m_RootWidget.SetHandler( this );
		
		LoadMissions();
	}
	
	void ~SgCreatePlaygroundPopup()
	{
		delete m_RootWidget;
	}
	
	void LoadMissions()
	{
		array<string> missions = SgPluginPgEditor.GetInstance().GetMissions();
		for( int i = 0; i < missions.Count(); i++ )
		{
			int pos = m_MissionList.AddItem( missions.Get( i ), null, 0);
		}
		
		m_MissionList.SelectRow( 0 );
	}
	
	string GetSelectedMission()
	{
		int		pos = m_MissionList.GetSelectedRow();
		string	mission;
		if( pos > -1 )
		{
			m_MissionList.GetItemText( pos, 0, mission );
		}
		return mission;
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if( w == m_CreateButton && button == MouseState.LEFT )
		{
			string	description;
			
			string	name		= m_Name.GetText();
			string	mission		= GetSelectedMission();
			int 	players		= m_PlayerCount.GetText().ToInt();
			string	details		= m_Details.GetText();
			m_Description.GetText( description );
			
			if( name != "" && mission != "" && players > 0 && details != "" && description != "" )
			{
				m_Manager.CreatePlayground( name, mission, description, players, details );
				m_Editor.ClosePopup();
				m_Editor.OpenLoadPopup();
			}
			
			return true;
		}
		return false;
	}
}