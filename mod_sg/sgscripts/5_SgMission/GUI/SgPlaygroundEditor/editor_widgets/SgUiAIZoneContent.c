class SgUiAIZoneContent extends UIMenuPanel
{
	protected Widget							m_RootWidget;
	protected EditBoxWidget						m_RangeEditBoxWidget;
	protected ButtonWidget						m_ApplyRangeButton;
	protected Widget							m_IsSpawnablePanelWidget;
	protected Widget							m_CheckBoxFrameWidget;
	protected ref SgUiCheckBoxRowSmall 			m_IsSpawnableCheckBox;
	protected Widget							m_SpawnpointsPanelWidgetHolder;
	protected Widget							m_SpawnpointsPanelWidget;
	protected ButtonWidget						m_AddSpawnpointButton;
	protected TextWidget						m_SpawnpointsTextWidget;
	protected Widget							m_ContentWidget;
	
	protected bool								m_IsSpawnpointsExpanded;
	
	protected SgJsonAIZone						m_AIZone;
	protected ref array<ref SgUiAISpawnpoint>	m_UiAISpawnpoints; // All Spawnpoints for this Herd as GUI
	
	protected ref ScriptInvoker 				Event_OnIsSpawnableCheckboxChanged;
	
	void SgUiAIZoneContent(SgJsonAIZone aiZone)
	{
		m_AIZone = aiZone;
		m_UiAISpawnpoints = new ref array<ref SgUiAISpawnpoint>;
		
		SetupGUI();
	}
	
	void ~SgUiAIZoneContent()
	{			
		delete m_RootWidget;
	}
	
	protected void SetupGUI()
	{
		m_RootWidget					= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/ai_editor_widgets/sg_ai_zone_content.layout", NULL );
		m_RangeEditBoxWidget			= EditBoxWidget.Cast( m_RootWidget.FindAnyWidget( "RangeEditBox" ) );
		m_ApplyRangeButton				= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "ApplyRangeButtonWidget" ) );
		m_IsSpawnablePanelWidget		= m_RootWidget.FindAnyWidget( "IsSpawnablePanelWidget" );
		m_CheckBoxFrameWidget			= m_RootWidget.FindAnyWidget( "CheckBoxFrameWidget" );
		m_SpawnpointsPanelWidgetHolder  = m_RootWidget.FindAnyWidget( "SpawnpointsPanelWidgetHolder" );
		m_SpawnpointsPanelWidget  		= m_RootWidget.FindAnyWidget( "SpawnpointPanelWidget" );
		m_AddSpawnpointButton			= ButtonWidget.Cast( m_RootWidget.FindAnyWidget( "AddSpawnpointButtonWidget" ) );
		m_SpawnpointsTextWidget			= TextWidget.Cast( m_RootWidget.FindAnyWidget( "SpawnpointsTextWidget" ) );
		m_ContentWidget					= m_RootWidget.FindAnyWidget( "SpawnpointContent" );
		
		m_RangeEditBoxWidget.SetText( m_AIZone.GetRange().ToString() );

		SetupCheckBox();
		
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_ApplyRangeButton, this, "ApplyRange" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_SpawnpointsPanelWidget, this, "Expand" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( m_AddSpawnpointButton, this, "AddSpawnpoint" );
		
		UpdateSpawnpointsCount();
	}
	
	protected void SetupCheckBox()
	{
		Event_OnIsSpawnableCheckboxChanged = new ref ScriptInvoker;
		Event_OnIsSpawnableCheckboxChanged.Insert(Event_OnIsSpawnableCheckboxChanged);
		
		m_IsSpawnableCheckBox = new ref SgUiCheckBoxRowSmall( m_CheckBoxFrameWidget, "", "", this.Event_OnIsSpawnableCheckboxChanged );
		
		if ( m_AIZone.GetCanSpawn() )
		{
			m_IsSpawnableCheckBox.Check();
		}
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}	
	
	protected void UpdateSpawnpointsCount()
	{
		m_SpawnpointsTextWidget.SetText("Spawnpoints (" + m_AIZone.GetSpawnpoints().Count().ToString() + ")" );
	}
	
	// Range
	
	protected void ApplyRange()
	{
		string rangeText = m_RangeEditBoxWidget.GetText().Trim();
		m_AIZone.SetRange( rangeText.ToFloat() );
	}
	
	// Is Spawnable
	
	protected void Event_OnIsSpawnableCheckboxChanged( SgUiCheckBoxRow checkBox )
	{
		m_AIZone.SetCanSpawn( checkBox.GetChecked() );
	}
	
	// Spawnpoints
	
	protected void AddSpawnpoint()
	{
		SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
		
		ref SgJsonAISpawnPoint spawnpointData 	= new SgJsonAISpawnPoint( editor.GetViewPosition() );
		m_AIZone.AddSpawnpoint(spawnpointData);
		
		if (m_IsSpawnpointsExpanded)
		{
			editor.AddAISpawnpoint( spawnpointData, m_AIZone, m_AIZone.GetSpawnpoints().Count() - 1 );
		}
		
		Expand(true);
		UpdateSpawnpointsCount();
	}
	
	void DeleteSpawnpoint(int index)
	{
		SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
		editor.RemoveSpawnpoint( m_AIZone.GetSpawnpoints()[index] );
		
		m_ContentWidget.RemoveChild( m_UiAISpawnpoints[index].GetRootWidget() );
		m_UiAISpawnpoints.RemoveOrdered(index);
		m_AIZone.RemoveSpawnpoint(index);
		
		if ( m_UiAISpawnpoints.Count() == 0 )
		{
			m_IsSpawnpointsExpanded = false;
		}
		else
		{
			for ( int i = 0; i < m_UiAISpawnpoints.Count(); i++ )
			{
				m_UiAISpawnpoints[i].SetIndex(i);
			
				editor.UpdateSpawnpointData( m_AIZone.GetSpawnpoints()[i], i );
			}
		}
		
		UpdateSpawnpointsCount();
	}
	
	void HideAllSpawnPoints()
	{
		SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
		
		if ( m_IsSpawnpointsExpanded && editor )
		{
			
			for ( int i = 0; i < m_UiAISpawnpoints.Count(); i++ )
			{
				editor.RemoveSpawnpoint( m_AIZone.GetSpawnpoints()[i] );
			}
		}
	}
	
	protected void Expand()
	{
		Expand(false);
	}
	
	protected void Expand(bool forceExpand)
	{
		if (m_IsSpawnpointsExpanded == false)
		{
			m_IsSpawnpointsExpanded = true;
			
			SgPlaygroundEditorMenu editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
			
			ref array<ref SgJsonAISpawnPoint> spawnpoints = m_AIZone.GetSpawnpoints();
			for ( int i = 0; i < spawnpoints.Count(); i++ )
			{
				editor.AddAISpawnpoint( spawnpoints[i], m_AIZone, i );
				
				SgUiAISpawnpoint spawnpointUI = new SgUiAISpawnpoint( i, this );
				m_UiAISpawnpoints.Insert(spawnpointUI);
				
				m_ContentWidget.AddChild( spawnpointUI.GetRootWidget() );
			}
		}
		else
		{
			if (forceExpand)
			{
				int totalSpawnpoints = m_AIZone.GetSpawnpoints().Count();
				spawnpointUI = new SgUiAISpawnpoint( totalSpawnpoints - 1, this );
				m_UiAISpawnpoints.Insert(spawnpointUI);
				
				m_ContentWidget.AddChild( spawnpointUI.GetRootWidget() );
			}
			else
			{
				m_IsSpawnpointsExpanded = false;
				
				editor = SgPlaygroundEditorMenu.Cast( GetGame().GetUIManager().GetMenu() );
				
				for ( i = 0; i < m_UiAISpawnpoints.Count(); i++ )
				{
					editor.RemoveSpawnpoint( m_AIZone.GetSpawnpoints()[i] );
					m_ContentWidget.RemoveChild( m_UiAISpawnpoints[i].GetRootWidget() );
				}
				
				m_UiAISpawnpoints = new ref array<ref SgUiAISpawnpoint>;
			}
		}
	}
}