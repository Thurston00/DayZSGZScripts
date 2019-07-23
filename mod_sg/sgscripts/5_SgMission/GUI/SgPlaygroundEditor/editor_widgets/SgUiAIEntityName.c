class SgUiAIEntityName extends UIMenuPanel
{
	protected Widget					m_RootWidget;
	
	protected TextWidget				m_EntityNameTextWidget;
	protected ButtonWidget				m_DeleteButton;
	
	protected string					m_EntityName;
	protected SgUiAIHerdDataContent		m_HerdDataContent;
	
	void SgUiAIEntityName( string entityName, SgUiAIHerdDataContent herdDataContent )
	{		
		m_EntityName = entityName;
		m_HerdDataContent = herdDataContent;
		
		SetupGUI(entityName);
	}
	
	void ~SgUiAIEntityName()
	{
		delete m_RootWidget;
	}
	
	protected void SetupGUI(string entityName)
	{
		m_RootWidget			= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/ai_editor_widgets/sg_ai_entity_name.layout", NULL );
		m_EntityNameTextWidget	= TextWidget.Cast( m_RootWidget.FindAnyWidget( "EntityNameTextWidget" ) );
		m_DeleteButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "DeleteEntityNameButtonWidget" ) );
		
		entityName.Replace( "SG_GuardInfected", "" );
		entityName.Replace( "SG_PatrolInfected", "" );
		entityName.Replace( "SG_ScreamerInfected", "" );
		entityName.Replace( "SG_StaticInfected", "" );
		
		m_EntityNameTextWidget.SetText(entityName);
		
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_DeleteButton, this, "DeleteEntityName" );
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}
	
	protected void DeleteEntityName()
	{
		m_HerdDataContent.DeleteAIEntityName(m_EntityName);
	}
}