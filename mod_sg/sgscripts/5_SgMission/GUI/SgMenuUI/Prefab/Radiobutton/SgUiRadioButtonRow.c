class SgUiRadioButtonRow extends SgUiCheckBoxRow
{
	// --------------------------------
	// OVERRIDES --> SgUiMenuPanel methods
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_radiobutton/sg_radiobutton_row_default.layout";
	}
	
	// -------------------------------
	// Overrides --> SgUiCheckBoxRow
	
	override protected void LoadImageFiles()
	{
		this.m_CheckboxImage.LoadImageFile(0, SgCMenuWidgetPaths.RADIOBUTTON_UNCHECKED_IMAGE);
		this.m_CheckboxImage.LoadImageFile(1, SgCMenuWidgetPaths.RADIOBUTTON_CHECKED_IMAGE);
	}
	
	// -----------------------------------
	// Overrides --> 
			
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if(w == this.m_UiButton)
		{
			this.Check();
			Event_OnCheckboxChanged.Invoke(this);
			return true;
		}	
		return false;
	}
	
	// ----------------------------------------
}