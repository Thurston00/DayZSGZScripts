class SgUiAISpawnpoint extends UIMenuPanel
{
	protected Widget					m_RootWidget;
	protected Widget					m_TopPanelWidget;
	protected TextWidget				m_SpawnpointTextWidget;
	protected ButtonWidget				m_DeleteButton;
	
	protected int						m_Index;
	protected SgUiAIZoneContent			m_AIZoneDataContent;
	
	void SgUiAISpawnpoint( int index, SgUiAIZoneContent aiZoneDataContent )
	{
		m_AIZoneDataContent = aiZoneDataContent;
		
		SetupGUI();
		SetIndex(index);
	}
	
	void ~SgUiAISpawnpoint()
	{
		delete m_RootWidget;
	}
	
	protected void SetupGUI()
	{
		m_RootWidget			= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/ai_editor_widgets/sg_ai_spawnpoint.layout", NULL );
		m_SpawnpointTextWidget	= TextWidget.Cast( m_RootWidget.FindAnyWidget( "SpawnpointTextWidget" ) );
		m_DeleteButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "DeleteSpawnpointButtonWidget" ) );
		
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_DeleteButton, this, "DeleteSpawnpoint" );
	}
	
	void SetIndex(int index)
	{
		m_Index = index;
		m_SpawnpointTextWidget.SetText("Spawnpoint " + m_Index.ToString());
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}
	
	protected void DeleteSpawnpoint()
	{
		m_AIZoneDataContent.DeleteSpawnpoint(m_Index);
	}
}