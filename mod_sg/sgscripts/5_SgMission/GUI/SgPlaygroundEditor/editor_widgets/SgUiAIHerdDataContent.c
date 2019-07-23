class SgUiAIHerdDataContent extends UIMenuPanel
{
	protected Widget							m_RootWidget;
	protected EditBoxWidget						m_MinEditBoxWidget;
	protected EditBoxWidget						m_MaxEditBoxWidget;
	protected ButtonWidget						m_ApplyMinMaxButton;
	protected ButtonWidget						m_AddEntityNameButton;
	protected Widget							m_EntityNamesPanelWidget;
	protected TextWidget						m_EntityNamesTextWidget;
	protected Widget							m_EntityNamesContentWidget;
	protected ButtonWidget						m_AddAIZoneButton;
	protected Widget							m_AIZonesPanelWidget;
	protected TextWidget						m_AIZonesTextWidget;
	protected Widget							m_AIZonesContentWidget;
	
	protected bool								m_IsEntityNamesExpanded;
	protected bool								m_IsAIZonesExpanded;
	
	protected int								m_HerdIndex;
	protected SgJsonAIHerdSpawnData 			m_HerdSpawnData;
	protected ref array<ref SgUiAIEntityName>	m_UiAIEntityNames; // All EntityNames for this Herd as GUI
	protected ref array<ref SgUiAIZone>			m_UiAIZones; // All Zones for this Herd as GUI
	
	
	void SgUiAIHerdDataContent( SgJsonAIHerdSpawnData herdSpawnData, int herdIndex )
	{
		m_UiAIEntityNames 	= new ref array<ref SgUiAIEntityName>;
		m_UiAIZones 		= new ref array<ref SgUiAIZone>;
		m_HerdSpawnData 	= herdSpawnData;
		
		SetIndex(herdIndex);
		SetupGUI();
	}
	
	void ~SgUiAIHerdDataContent()
	{		
		delete m_RootWidget;
	}
	
	protected void SetupGUI()
	{
		m_RootWidget				= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/ai_editor_widgets/sg_ai_herd_data_content.layout", NULL );
		m_MinEditBoxWidget			= EditBoxWidget.Cast( m_RootWidget.FindAnyWidget( "MinEditBox" ) );
		m_MaxEditBoxWidget			= EditBoxWidget.Cast( m_RootWidget.FindAnyWidget( "MaxEditBox" ) );
		m_ApplyMinMaxButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "ApplyMinMaxButtonWidget" ) );
		m_AddEntityNameButton		= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "AddEntityNamelButtonWidget" ) );
		m_EntityNamesPanelWidget	= m_RootWidget.FindAnyWidget( "EntityNamesPanelWidgetHolder" );
		m_EntityNamesTextWidget		= TextWidget.Cast( m_RootWidget.FindAnyWidget( "EntityNamesTextWidget" ) );
		m_EntityNamesContentWidget	= m_RootWidget.FindAnyWidget( "EntityNamesContent" );
		m_AddAIZoneButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "AddAIZoneButtonWidget" ) );
		m_AIZonesPanelWidget		= m_RootWidget.FindAnyWidget( "AIZonesPanelWidgetHolder" );
		m_AIZonesTextWidget			= TextWidget.Cast( m_RootWidget.FindAnyWidget( "AIZonesTextWidget" ) );
		m_AIZonesContentWidget		= m_RootWidget.FindAnyWidget( "AIZonesContent" );
		
		m_MinEditBoxWidget.SetText(m_HerdSpawnData.GetMinCount().ToString());
		m_MaxEditBoxWidget.SetText(m_HerdSpawnData.GetMaxCount().ToString());
			
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_ApplyMinMaxButton, this, "ApplyMinMax" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_EntityNamesPanelWidget, this, "ExpandEntityNames" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_AddEntityNameButton, this, "AddEntityName" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_AIZonesPanelWidget, this, "ExpandAIZones" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_AddAIZoneButton, this, "AddAIZone" );
		
		ShowAddAIZone();
		UpdateEntityNamesCount();
		UpdateAIZonesCount();
	}
	
	void SetIndex(int index)
	{
		m_HerdIndex = index;
		UpdateAIZones();
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}	
	
	protected void ShowAddAIZone()
	{
		if ( m_HerdSpawnData.GetAIGroup() != ESgAIGroup.Patrol )
		{
			if ( m_HerdSpawnData.GetAIZones().Count() == 1 )
			{
				m_AddAIZoneButton.Show(false);
			}
			else
			{
				m_AddAIZoneButton.Show(true);
			}
		}
	}
	protected void UpdateEntityNamesCount()
	{
		m_EntityNamesTextWidget.SetText("Entity Names (" + m_HerdSpawnData.GetEntityNames().Count().ToString() + ")" );
	}
	
	protected void UpdateAIZonesCount()
	{
		m_AIZonesTextWidget.SetText("AI Zones (" + m_HerdSpawnData.GetAIZones().Count().ToString() + ")" );
	}
	
	// Min - Max
	
	protected void ApplyMinMax()
	{
		string minText = m_MinEditBoxWidget.GetText().Trim();
		string maxText = m_MaxEditBoxWidget.GetText().Trim();
		
		m_HerdSpawnData.SetMinCount(minText.ToInt());
		m_HerdSpawnData.SetMaxCount(maxText.ToInt());
	}
	
	// Entity Names
	
	void AddAIEntityName(string entityName)
	{
		m_HerdSpawnData.AddEntityName(entityName);	
		
		ExpandEntityNames(true);
		UpdateEntityNamesCount();
	}
	
	void DeleteAIEntityName(string entityName)
	{
		int index = m_HerdSpawnData.GetEntityNames().Find(entityName);
		
		m_EntityNamesContentWidget.RemoveChild( m_UiAIEntityNames[index].GetRootWidget() );
		m_UiAIEntityNames.RemoveOrdered(index);
		m_HerdSpawnData.RemoveEntityName(entityName);
		
		if ( m_UiAIEntityNames.Count() == 0 )
		{
			m_IsEntityNamesExpanded = false;
		}
		
		UpdateEntityNamesCount();
	}
	
	protected void ExpandEntityNames()
	{
		ExpandEntityNames(false);
	}
	
	protected void ExpandEntityNames(bool forceExpand)
	{
		if (m_IsEntityNamesExpanded == false)
		{
			m_IsEntityNamesExpanded = true;
			
			ref array<string> entityNames = m_HerdSpawnData.GetEntityNames();
			foreach ( string entityName : entityNames )
			{
				SgUiAIEntityName entityNameUI = new SgUiAIEntityName(entityName, this);
				m_UiAIEntityNames.Insert(entityNameUI);
				
				m_EntityNamesContentWidget.AddChild(entityNameUI.GetRootWidget());
			}
		}
		else
		{
			if (forceExpand)
			{
				entityNameUI = new SgUiAIEntityName(m_HerdSpawnData.GetEntityNames()[m_HerdSpawnData.GetEntityNames().Count() - 1], this);
				m_UiAIEntityNames.Insert(entityNameUI);
				
				m_EntityNamesContentWidget.AddChild(entityNameUI.GetRootWidget());
			}
			else
			{
				m_IsEntityNamesExpanded = false;
				
				for ( int i = 0; i < m_UiAIEntityNames.Count(); i++ )
				{
					m_EntityNamesContentWidget.RemoveChild(m_UiAIEntityNames[i].GetRootWidget());
				}
				
				m_UiAIEntityNames = new ref array<ref SgUiAIEntityName>;
			}
		}
	}
	
	protected void AddEntityName()
	{		
		if( GetGame().GetUIManager().GetMenu() && GetGame().GetUIManager().GetMenu().GetID() == MENU_SG_PG_EDITOR )
		{			
			SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
			editor.ShowPopup( new SgUiAIAddModelPopup( editor, this, m_HerdSpawnData.GetAIGroup() ) );
		}
	}
	
	// AI Zones
	
	protected void AddAIZone()
	{
		SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
		
		ref SgJsonAIZone aiZoneData = new SgJsonAIZone( editor.GetViewPosition() );
		m_HerdSpawnData.SetAIZone(aiZoneData);
		
		editor.AddAIZone( aiZoneData, m_HerdIndex, m_HerdSpawnData.GetAIZones().Count() - 1, m_HerdSpawnData.GetAIGroup() );
		
		
		ExpandAIZones(true);
		UpdateAIZonesCount();
		ShowAddAIZone();
	}
	
	void DeleteAIZone(int index)
	{		
		SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
		editor.RemoveAIZone( m_HerdSpawnData.GetAIZones()[index] );
		
		m_AIZonesContentWidget.RemoveChild( m_UiAIZones[index].GetRootWidget() );
		m_UiAIZones.RemoveOrdered(index);
		m_HerdSpawnData.RemoveAIZone(index);
		
		if ( m_UiAIZones.Count() == 0 )
		{
			m_IsAIZonesExpanded = false;
		}
		else
		{
			UpdateAIZones();
		}
		
		UpdateAIZonesCount();
		ShowAddAIZone();
	}
	
	protected void UpdateAIZones()
	{
		SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
		
		for ( int i = 0; i < m_UiAIZones.Count(); i++ )
		{
			m_UiAIZones[i].SetIndex(i);
		
			editor.UpdateAIZoneData( m_HerdSpawnData.GetAIZones()[i], m_HerdIndex, i );
		}
	}
	
	protected void ExpandAIZones()
	{
		ExpandAIZones(false);
	}
	
	protected void ExpandAIZones(bool forceExpand)
	{
		if (m_IsAIZonesExpanded == false)
		{
			m_IsAIZonesExpanded = true;
			
			ref array<ref SgJsonAIZone> aiZones = m_HerdSpawnData.GetAIZones();
			for ( int i = 0; i < m_HerdSpawnData.GetAIZones().Count(); i++ )
			{
				SgUiAIZone zoneUI = new SgUiAIZone(aiZones[i], i, this);
				m_UiAIZones.Insert(zoneUI);
				
				m_AIZonesContentWidget.AddChild( zoneUI.GetRootWidget() );
			}
		}
		else
		{
			if (forceExpand)
			{
				int totalAIZones = m_HerdSpawnData.GetAIZones().Count();
				zoneUI = new SgUiAIZone( m_HerdSpawnData.GetAIZones()[totalAIZones - 1], totalAIZones - 1, this );
				m_UiAIZones.Insert(zoneUI);
				
				m_AIZonesContentWidget.AddChild( zoneUI.GetRootWidget() );
			}
			else
			{
				m_IsAIZonesExpanded = false;
				
				for ( i = 0; i < m_UiAIZones.Count(); i++ )
				{
					m_AIZonesContentWidget.RemoveChild(m_UiAIZones[i].GetRootWidget());
				}
				
				m_UiAIZones = new ref array<ref SgUiAIZone>;
			}
		}
	}
}