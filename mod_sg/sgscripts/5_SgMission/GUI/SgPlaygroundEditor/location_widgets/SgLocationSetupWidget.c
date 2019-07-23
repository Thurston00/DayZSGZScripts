class SgLocationSetupWidget extends SgSWEH
{
	protected Widget								m_Root;
	protected SgJsonLocation						m_Location;
	protected ref SgJsonLocationAIGroupsSpawnData	m_LocationAIGroupsSpawnData;
	protected SgPluginPgEditor						m_Manager;
	protected ref SgUiAISpawnEditor					m_AISpawnEditor;
	protected SgPlaygroundEditorMenu				m_Editor;
	protected bool									m_Editing;
	
	protected ButtonWidget							m_LocationEdit;
	protected ButtonWidget							m_AddBorder;
	protected ButtonWidget							m_ClearBorder;
	protected ButtonWidget							m_GenerateBorders;
	protected ButtonWidget							m_LootEditor;
	protected ButtonWidget							m_OpenAISpawnEditor;
	
	protected TextWidget							m_LocationID;
	protected TextWidget							m_LocationType;
	protected EditBoxWidget							m_PhaseTimeBox;
	protected EditBoxWidget							m_TransitionTimeBox;
	
	void ~SgLocationSetupWidget()
	{
		
	}
	
	override void Show()
	{
		if (m_AISpawnEditor)
		{
			m_Editor.RemoveChildWidget(m_AISpawnEditor.GetRootWidget());
		}
	}
	
	override void Update()
	{
		if( !m_Root )
		{
			return;
		}
	}
	
	void Select( bool select )
	{
		if( select )
		{
			m_Root.FindAnyWidget( "SetupPanel" ).Show( true );
			m_LocationEdit.SetText( "Finish Editing" );
			m_Editing = true;
		}
		else
		{
			m_Root.FindAnyWidget( "SetupPanel" ).Show( false );
			m_LocationEdit.SetText( "Edit" );
			m_Editing = false;
		}
		AutoHeightSpacer spacer;
		m_Root.GetScript( spacer );
		spacer.Update();
		m_Root.GetParent().GetScript( spacer );
		spacer.Update();
		Fade( !select );
	}
	
	void Fade( bool fade )
	{
		if( fade )
		{
			m_Root.SetAlpha( 0.2 );
			m_LocationEdit.SetFlags( WidgetFlags.IGNOREPOINTER );
		}
		else
		{
			m_Root.SetAlpha( 1 );
			m_LocationEdit.ClearFlags( WidgetFlags.IGNOREPOINTER );
		}
	}
	
	override bool OnChange( Widget w, int x, int y, bool finished )
	{		
		if( w == m_PhaseTimeBox )
		{
			string p_text	= m_PhaseTimeBox.GetText();
			int p_value		= p_text.ToInt();
			if( p_value >= 0 )
			{
				m_Location.m_PhaseTime = p_value;
				return true;
			}
		}
		else if( w == m_TransitionTimeBox )
		{
			string t_text	= m_TransitionTimeBox.GetText();
			int t_value		= t_text.ToInt();
			if( t_value >= 0 )
			{
				m_Location.m_TransitionTime = t_value;
				return true;
			}
		}
		return false;
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( w == m_LocationEdit )
		{
			if( m_Editing )
			{
				m_Editor.SelectLocation( null );
			}
			else
			{
				m_Editor.SelectLocation( m_Location );
			}
			return true;
		}
		else if( w == m_AddBorder )
		{
			m_Editor.StartPlacingBorderPoint( m_Location );
		}
		else if( w == m_ClearBorder )
		{
			m_Editor.ClearBorderPoints( m_Location );
		}
		else if( w == m_GenerateBorders )
		{
			m_Editor.CreateRadiusSelector( m_Location.GetPosition() );
		}
		else if( w == m_LootEditor )
		{
			SgPluginEditorLoot.GetInstance().EditorOpenTimed( m_Location );
			m_Editor.Hide();
		}
		else if( w == m_OpenAISpawnEditor )
		{
			m_Editor.Hide();
			
			if (m_AISpawnEditor == null) 
			{ 
				m_AISpawnEditor = new SgUiAISpawnEditor(m_LocationAIGroupsSpawnData);
				m_Editor.AddChildWidget( m_AISpawnEditor.GetRootWidget() );
			}
			else
			{
				Error("AI Editor should not exist in here.");
			}
		}
		return false;
	}
}
