class SgUiAIHerdData extends UIMenuPanel
{
	protected Widget							m_RootWidget;
	protected Widget							m_TopPanelWidget;
	protected TextWidget						m_HerdTextWidget;
	protected Widget							m_ContentWidget;
	
	protected int								m_Index;
	protected ref SgUiAIHerdDataContent			m_UiAIHerdSpawnDataContent;
	protected ButtonWidget						m_SpawnButton;
	protected ButtonWidget						m_DeleteButton;
	
	protected ref SgJsonAIHerdSpawnData 		m_HerdSpawnData;
	protected SgUiAIGroups 						m_AIGroups;
	
	void SgUiAIHerdData( SgJsonAIHerdSpawnData herdSpawnData, int index, SgUiAIGroups aiGroups )
	{
		m_HerdSpawnData = herdSpawnData;
		m_AIGroups 		= aiGroups;
		
		SetupGUI();
		SetIndex(index);
	}
	
	void ~SgUiAIHerdData()
	{
		delete m_RootWidget;
	}
	
	protected void SetupGUI()
	{
		m_RootWidget			= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/ai_editor_widgets/sg_ai_herd_data.layout", NULL );
		m_TopPanelWidget		= m_RootWidget.FindAnyWidget( "TopPanelWidget" );
		m_HerdTextWidget		= TextWidget.Cast( m_RootWidget.FindAnyWidget( "HerdTextWidget" ) );
		m_SpawnButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "SpawnAIGroupButtonWidget" ) );
		m_DeleteButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "DeleteAIGroupButtonWidget" ) );
		m_ContentWidget			= m_RootWidget.FindAnyWidget( "Content" );
		
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_TopPanelWidget, this, "Expand" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_SpawnButton, this, "SpawnAIGroup" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_DeleteButton, this, "DeleteAIGroup" );
	}
	
	void SetIndex(int index)
	{
		m_Index = index;
		m_HerdTextWidget.SetText( "AI Group " + m_Index.ToString() );
		
		if (m_UiAIHerdSpawnDataContent)
		{
			m_UiAIHerdSpawnDataContent.SetIndex(index);
		}
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}
	
	protected void Expand()
	{
		if (m_UiAIHerdSpawnDataContent == null)
		{
			m_UiAIHerdSpawnDataContent = new SgUiAIHerdDataContent( m_HerdSpawnData, m_Index );
			m_ContentWidget.AddChild( m_UiAIHerdSpawnDataContent.GetRootWidget() );
		}
		else
		{
			m_ContentWidget.RemoveChild( m_UiAIHerdSpawnDataContent.GetRootWidget() );
			m_UiAIHerdSpawnDataContent = null;
		}
	}
	
	protected void SpawnAIGroup()
	{
		SgSManagerAi.DistributeAI(m_HerdSpawnData);
	}
	
	protected void DeleteAIGroup()
	{
		m_AIGroups.DeleteHerd(m_Index);
	}
}