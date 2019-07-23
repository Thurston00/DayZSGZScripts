class SgUiAIGroups extends UIMenuPanel
{
	protected Widget							m_RootWidget;
	protected Widget							m_TopPanelWidget;
	protected TextWidget						m_AIGroupTextWidget;
	protected ButtonWidget						m_AddHerdButton;
	protected Widget							m_ContentWidget;
	
	protected ESgAIGroup						m_AIGroup;
	protected bool								m_IsExpanded;
	
	protected array<ref SgJsonAIHerdSpawnData>	m_AIHerdSpawnData; // All Herd Data for all AI Groups!
	protected ref array<ref SgUiAIHerdData>		m_UiAIHerdData;	// SgJsonAIHerdSpawnData as GUI
	
	void SgUiAIGroups( ESgAIGroup aiGroup, array<ref SgJsonAIHerdSpawnData> herdData )
	{
		m_AIGroup = aiGroup;
		
		m_AIHerdSpawnData = herdData;
		m_UiAIHerdData = new ref array<ref SgUiAIHerdData>;
		
		SetupGUI();
		SetupAIZonesFollowers();
	}
	
	void ~SgUiAIGroups()
	{		
		delete m_RootWidget;
	}
	
	protected void SetupGUI()
	{
		m_RootWidget				= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/ai_editor_widgets/sg_ai_groups.layout", NULL );
		m_TopPanelWidget			= m_RootWidget.FindAnyWidget( "TopPanelWidget" );
		m_AIGroupTextWidget			= TextWidget.Cast( m_RootWidget.FindAnyWidget( "AIGroupTextWidget" ) );
		m_AddHerdButton				= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "AddHerdButtonWidget" ) );
		m_ContentWidget				= m_RootWidget.FindAnyWidget( "Content" );
		
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_TopPanelWidget, this, "Expand" );
		m_AIGroupTextWidget.SetText(GetNameForAIGroup(m_AIGroup));
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_AddHerdButton, this, "AddHerd" );
	}
	
	protected void SetupAIZonesFollowers()
	{
		SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
		
		int index = 0;
		foreach ( SgJsonAIHerdSpawnData herdSpawnData : m_AIHerdSpawnData )
		{
			if ( herdSpawnData.GetAIGroup() != m_AIGroup ) continue;
			
			array<ref SgJsonAIZone> aiZones = herdSpawnData.GetAIZones();
			for ( int j = 0; j < aiZones.Count(); j++ )
			{
				editor.AddAIZone( aiZones[j], index, j, herdSpawnData.GetAIGroup() );
			}
			
			index++;
		}
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}
	
	// Herds
	
	protected void AddHerd()
	{		
		SgJsonAIHerdSpawnData herdData = new SgJsonAIHerdSpawnData(m_AIGroup);
		m_AIHerdSpawnData.Insert(herdData);
		
		Expand(true);
	}
	
	void DeleteHerd(int index)
	{
		SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
		
		int count = 0;
		foreach ( SgJsonAIHerdSpawnData herdSpawnData : m_AIHerdSpawnData )
		{
			if ( herdSpawnData.GetAIGroup() != m_AIGroup ) continue;
			
			if ( count == index )
			{
				array<ref SgJsonAIZone> aiZones = herdSpawnData.GetAIZones();
				foreach ( SgJsonAIZone aiZone : aiZones )
				{
					editor.RemoveAIZone( aiZone );
				}
				
				m_AIHerdSpawnData.RemoveItem(herdSpawnData);
				
				break;
			}
			
			count++;
		}
		
		m_UiAIHerdData.RemoveOrdered(index);
		
		if ( m_UiAIHerdData.Count() == 0 )
		{
			m_IsExpanded = false;
		}
		else
		{
			for ( int i = 0; i < m_UiAIHerdData.Count(); i++ )
			{
				m_UiAIHerdData[i].SetIndex(i);
			}
		}
	}
	
	protected void Expand()
	{
		Expand(false);
	}
	
	protected void Expand(bool forceExpand)
	{
		if (m_IsExpanded == false)
		{
			int index = 0;
			foreach ( SgJsonAIHerdSpawnData herdData : m_AIHerdSpawnData )
			{
				if ( herdData.GetAIGroup() != m_AIGroup ) continue;
				
				SgUiAIHerdData herdUI = new SgUiAIHerdData(herdData, index++, this);
				m_UiAIHerdData.Insert(herdUI);
				
				m_ContentWidget.AddChild(herdUI.GetRootWidget());
			}
			
			if ( m_UiAIHerdData.Count() != 0 )
			{
				m_IsExpanded = true;
			}
		}
		else
		{
			if (forceExpand)
			{
				herdUI = new SgUiAIHerdData( m_AIHerdSpawnData[m_AIHerdSpawnData.Count() - 1], m_UiAIHerdData.Count(), this );
				m_UiAIHerdData.Insert(herdUI);
				
				m_ContentWidget.AddChild(herdUI.GetRootWidget());
			}
			else
			{
				m_IsExpanded = false;
				
				for ( int i = 0; i < m_UiAIHerdData.Count(); i++ )
				{
					m_ContentWidget.RemoveChild(m_UiAIHerdData[i].GetRootWidget());
				}
				
				m_UiAIHerdData = new ref array<ref SgUiAIHerdData>;
			}
		}
	}
}