class SgStartSetupWidget extends SgLocationSetupWidget
{
	void SgStartSetupWidget( Widget root, SgJsonLocation location, SgPlaygroundEditorMenu editor, SgJsonLocationAIGroupsSpawnData locationAIGroupsSpawnData )
	{
		m_Root						= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_playground_editor/setup_widgets/pg_start_settings_panel.layout", root );
		m_Location					= location;
		m_LocationAIGroupsSpawnData = locationAIGroupsSpawnData;
		m_Editor					= editor;
		m_Manager					= SgPluginPgEditor.Cast( GetPlugin( SgPluginPgEditor ) );
		
		m_LocationEdit				= ButtonWidget.Cast( m_Root.FindAnyWidget( "Edit" ) );
		m_AddBorder					= ButtonWidget.Cast( m_Root.FindAnyWidget( "AddBorder" ) );
		m_ClearBorder				= ButtonWidget.Cast( m_Root.FindAnyWidget( "ClearBorder" ) );
		m_GenerateBorders			= ButtonWidget.Cast( m_Root.FindAnyWidget( "GenerateBorders" ) );
		m_LootEditor				= ButtonWidget.Cast( m_Root.FindAnyWidget( "LootEditor" ) );
		m_OpenAISpawnEditor			= ButtonWidget.Cast( m_Root.FindAnyWidget( "OpenAISpawnEditor" ) );
		
		m_LocationID				= TextWidget.Cast( m_Root.FindAnyWidget( "LocationID" ) );
		m_LocationType				= TextWidget.Cast( m_Root.FindAnyWidget( "LocationType" ) );
	
		m_PhaseTimeBox				= EditBoxWidget.Cast( m_Root.FindAnyWidget( "PhaseTimeEdit" ) );
		
		m_LocationID.SetText( "Location ID: " + m_Location.m_AreaID.ToString() + "" );
		m_LocationType.SetText( "Location Type: First Phase" );
		
		m_PhaseTimeBox.SetText( m_Location.m_PhaseTime.ToString() );
		
		m_Root.SetHandler( this );
	}
}
