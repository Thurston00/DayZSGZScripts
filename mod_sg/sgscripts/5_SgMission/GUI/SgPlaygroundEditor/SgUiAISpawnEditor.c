class SgUiAISpawnEditor extends UIMenuPanel
{
	protected Widget								m_RootWidget;
	protected ScrollWidget							m_ScrollWidget;
	protected Widget								m_ContentWidget;
	protected ButtonWidget							m_CloseButtonWidget;
	
	protected ref array<ref SgUiAIGroups>			m_UiAIGroups;
	protected ref array<ref SgJsonAIHerdSpawnData>	m_AIHerdSpawnData; // All Herd Data for all AI Groups
	
	void SgUiAISpawnEditor(SgJsonLocationAIGroupsSpawnData locationAIGroupsSpawnData)
	{
		m_UiAIGroups = new ref array<ref SgUiAIGroups>;
		m_AIHerdSpawnData = locationAIGroupsSpawnData.m_AIHerdSpawnData;
		
		SetupGUI();
	}
	
	void ~SgUiAISpawnEditor()
	{
		delete m_RootWidget;
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}
	
	protected void SetupGUI()
	{
		m_RootWidget				= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/ai_editor_widgets/sg_ai_editor.layout", NULL );
		m_ScrollWidget				= ScrollWidget.Cast( m_RootWidget.FindAnyWidget( "Scroller" ) );
		m_ContentWidget				= m_ScrollWidget.FindAnyWidget( "Content" );
		m_CloseButtonWidget			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "CloseButtonWidget" ) );
		
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_CloseButtonWidget, this, "CloseAIEditor" );
		
		setupAIGroups();
	}
	
	protected void setupAIGroups()
	{
		array<ESgAIGroup> aiGroups = GetAllAIGroups();
		foreach (ESgAIGroup aiGroup : aiGroups)
		{
			SgUiAIGroups uiAIGroups = new SgUiAIGroups( aiGroup, m_AIHerdSpawnData );
			m_UiAIGroups.Insert(uiAIGroups);
			m_ContentWidget.AddChild(uiAIGroups.GetRootWidget());
		}
	}
	
	protected void CloseAIEditor()
	{
		if( GetGame().GetUIManager().GetMenu() && GetGame().GetUIManager().GetMenu().GetID() == MENU_SG_PG_EDITOR )
		{			
			SgUISM menu = SgUISM.Cast( GetGame().GetUIManager().GetMenu() );
			menu.Show();
			
			HideAllAIZones();
			
			delete this;
		}
	}
	
	protected void HideAllAIZones()
	{
		SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
		
		foreach ( SgJsonAIHerdSpawnData herdSpawnData : m_AIHerdSpawnData )
		{
			array<ref SgJsonAIZone> aiZones = herdSpawnData.GetAIZones();
			foreach ( SgJsonAIZone aiZone : aiZones )
			{
				editor.RemoveAIZone(aiZone);
			}
		}
	}
}