class SgUiPopupResponseNote extends SgUiPopupResponse
{
	// Data
	private string 	m_NoteText;
	private string 	m_NoteIcon;
	
	// ----------------------------------------------------
	
	void SetPopUpNote(string note, string icon)
	{
		m_NoteText = note;
		m_NoteIcon = icon;
		
		UpdateNote();
	}
	
	void UpdateNote()
	{
		FindImage("NoteIcon").LoadImageFile(0, m_NoteIcon);
		FindLabel("NoteLabel").SetText(m_NoteText);
	}
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_popup_window/sg_popup_response_note.layout";
	}
		
	// ------------------------------------------------------
}