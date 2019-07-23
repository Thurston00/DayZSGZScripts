class SgUiAIZone extends UIMenuPanel
{
	protected Widget					m_RootWidget;
	protected Widget					m_TopPanelWidget;
	protected TextWidget				m_AIZoneTextWidget;
	protected ButtonWidget				m_DeleteButton;
	protected Widget					m_ContentWidget;
	
	protected int						m_Index;
	protected SgJsonAIZone				m_AIZone;
	protected ref SgUiAIZoneContent		m_UiAIZoneContent;
	protected SgUiAIHerdDataContent		m_HerdDataContent;
	
	void SgUiAIZone( SgJsonAIZone aiZone, int index, SgUiAIHerdDataContent herdDataContent )
	{
		m_AIZone 			= aiZone;
		m_HerdDataContent 	= herdDataContent;
		
		SetupGUI();
		SetIndex(index);
	}
	
	void ~SgUiAIZone()
	{
		if (m_UiAIZoneContent)
		{
			m_UiAIZoneContent.HideAllSpawnPoints();
		}
		
		delete m_RootWidget;
	}
	
	protected void SetupGUI()
	{
		m_RootWidget			= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/ai_editor_widgets/sg_ai_zone.layout", NULL );
		m_TopPanelWidget		= m_RootWidget.FindAnyWidget( "TopPanelWidget" );
		m_AIZoneTextWidget		= TextWidget.Cast( m_RootWidget.FindAnyWidget( "AIZoneTextWidget" ) );
		m_DeleteButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "DeleteAIZoneButtonWidget" ) );
		m_ContentWidget			= m_RootWidget.FindAnyWidget( "AIZoneContent" );
		
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_TopPanelWidget, this, "Expand" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_DeleteButton, this, "DeleteAIZone" );
	}
	
	void SetIndex(int index)
	{
		m_Index = index;
		m_AIZoneTextWidget.SetText("AI Zone " + m_Index.ToString());
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}
	
	protected void Expand()
	{
		if (m_UiAIZoneContent == null)
		{
			m_UiAIZoneContent = new SgUiAIZoneContent(m_AIZone);
			m_ContentWidget.AddChild( m_UiAIZoneContent.GetRootWidget() );
		}
		else
		{
			m_UiAIZoneContent.HideAllSpawnPoints();
			m_ContentWidget.RemoveChild( m_UiAIZoneContent.GetRootWidget() );
			delete m_UiAIZoneContent;
		}
	}
	
	protected void DeleteAIZone()
	{
		m_HerdDataContent.DeleteAIZone(m_Index);
	}
}