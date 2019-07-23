class SgUiAIAddModelPopup extends SgSWEH
{
	protected Widget					m_RootWidget;
	
	protected TextListboxWidget			m_AIListWidget;
	protected ButtonWidget				m_ConfirmButton;
	protected ButtonWidget				m_CancelButton;
	
	protected SgPlaygroundEditorMenu	m_Editor;
	protected SgUiAIHerdDataContent		m_HerdDataContent;
	protected ESgAIGroup				m_AiGroup;
	
	void SgUiAIAddModelPopup( SgPlaygroundEditorMenu editor, SgUiAIHerdDataContent herdDataContent, ESgAIGroup aiGroup )
	{
		m_Editor 			= editor;
		m_HerdDataContent 	= herdDataContent;
		m_AiGroup 			= aiGroup;
		
		SetupGUI();
	}
	
	void ~SgUiAIAddModelPopup()
	{
		delete m_RootWidget;
	}
	
	protected void SetupGUI()
	{
		m_RootWidget			= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/popup_widgets/sg_list_selection_popup.layout", m_Editor.GetRootWidget() );
		
		m_AIListWidget			= TextListboxWidget.Cast( m_RootWidget.FindAnyWidget( "LocationList" ) );
		m_ConfirmButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "ConfirmButton" ) );
		m_CancelButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "CancelButton" ) );
		
		AddAIOptions();
		
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_ConfirmButton, this, "Confirmed" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_CancelButton, this, "Cancelled" );
		
		m_RootWidget.SetHandler(this);
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}
	
	protected void AddAIOptions()
	{
		string aiGroup = GetNameForAIGroup(m_AiGroup);
		string cfgClassname = "CfgVehicles";
		int cfgItemCount = g_Game.ConfigGetChildrenCount(cfgClassname);
		
		for ( int i = 0; i < cfgItemCount; i++ )
		{
			string aiClassName;
			GetGame().ConfigGetChildName(cfgClassname, i, aiClassName);
			string aiFullPath = cfgClassname + " " + aiClassName;
			
			
			string configAiGroupType = GetGame().ConfigGetTextOut(aiFullPath + " " + "aiGroupType");
			
			if( configAiGroupType == aiGroup && GetGame().ConfigGetTextOut(aiFullPath + " " + "scope") == "2" )
			{
				m_AIListWidget.AddItem( aiClassName, new Param1<string>(aiClassName), 0 );
			}
		}
		
		m_AIListWidget.SelectRow( 0 );
	}
	
	protected void Confirmed()
	{
		Param1<string> par = new Param1<string>("");
		m_AIListWidget.GetItemData(m_AIListWidget.GetSelectedRow(), 0, par);
		string entityName = par.param1;
		
		m_HerdDataContent.AddAIEntityName(entityName);
		m_Editor.ClosePopupOnly();
	}
	
	protected void Cancelled()
	{
		m_Editor.ClosePopupOnly();
	}
}