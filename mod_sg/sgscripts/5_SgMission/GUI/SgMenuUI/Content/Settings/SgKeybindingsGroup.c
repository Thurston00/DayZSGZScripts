modded class KeybindingsGroup
{	
	private ref OptionsMenu m_OptionsMenu;
	
	override string GetLayoutName()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_settings/sg_keybinding_group.layout";
	}

	void Focus()
	{
		SetFocus( m_Root );
	}
	
	void SetOptionsMenu(OptionsMenu menu)
	{
		m_OptionsMenu = menu;
	}
	
	override void ClearKeybind( int key_index )
	{
		m_OptionsMenu.EnableApplyButton( true );
		m_OptionsMenu.EnableResetButton( true );
	}
	
	override void ClearAlternativeKeybind( int key_index )
	{
		m_OptionsMenu.EnableApplyButton( true );
		m_OptionsMenu.EnableResetButton( true );
	}
	
	override void StartEnteringKeybind( int key_index )
	{
		m_CurrentSettingAlternateKeyIndex	= -1;
		m_CurrentSettingKeyIndex			= key_index;
	}
	override void StartEnteringAlternateKeybind( int key_index )
	{
		m_CurrentSettingKeyIndex			= -1;
		m_CurrentSettingAlternateKeyIndex	= key_index;
	}
	
	override void Apply()
	{
		super.Apply();
		GetUApi().Export();
	}
	
	override void Reset()
	{
		super.Reset();
		
		m_OptionsMenu.EnableApplyButton( false );
		m_OptionsMenu.EnableResetButton( false );
	}
	
	void Update( float timeslice )
	{		
		if( m_CurrentSettingKeyIndex != -1 || m_CurrentSettingAlternateKeyIndex != -1 )
		{
			UAInputAPI ua_api = GetUApi();
			if ( ua_api.DeterminePressedButton() != 0 )
			{
				string name;
				string text;
				ref array<int> new_keybinds = new array<int>;
				
				// remove previous backlit
				GetDayZGame().GetBacklit().KeybindingClear();

				for ( int i = 0; i < ua_api.DeterminedCount(); ++i )
				{
					int kb_id = ua_api.GetDetermined( i );
					new_keybinds.Insert( kb_id );
					
					// light up specific key
					GetDayZGame().GetBacklit().KeybindingShow(kb_id);
				}
				
				if ( m_CurrentSettingKeyIndex != -1 )
				{	
					m_OptionsMenu.EnableApplyButton( true );
					m_OptionsMenu.EnableResetButton( true );
					
					m_KeyWidgets.Get( m_CurrentSettingKeyIndex ).Reload( new_keybinds, false );
					m_CurrentSettingKeyIndex = -1;
				}
				else if ( m_CurrentSettingAlternateKeyIndex != -1 )
				{
					m_OptionsMenu.EnableApplyButton( true );
					m_OptionsMenu.EnableResetButton( true );
					
					m_KeyWidgets.Get( m_CurrentSettingAlternateKeyIndex ).Reload( new_keybinds, true );
					m_CurrentSettingAlternateKeyIndex = -1;
				}
			}
		}
	}
	
}