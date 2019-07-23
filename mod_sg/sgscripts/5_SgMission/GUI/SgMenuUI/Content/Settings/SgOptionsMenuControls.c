modded class OptionsMenuControls
{ 	
	KeybindingsGroup m_UiKeybindingGroupTab;
	
	void SetKeybindingTab(KeybindingsGroup tab)
	{
		m_UiKeybindingGroupTab = tab;
	}
	
	override string GetLayoutName()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_settings/sg_controls_tab.layout";
	}
		
	override void EnterKeybindingMenu()
	{
		//m_UiKeybindingGroupTab.Focus();
	}
}