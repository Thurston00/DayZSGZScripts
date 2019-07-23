/*
	Ui class for unassigned player row in custom lobby
*/
class SgUiUnassignedPlayerRow extends SgUiMenuPanel
{
	// Widgets
	private TextWidget 	m_UiPlayerNameLabel;
	private ImageWidget m_UiHostImage;
	// Data
	private string 	m_PlayerName;
	private bool 	m_IsHost;
	private bool 	m_IsClient;
	
	// --------------------------------
	
	void SgUiUnassignedPlayerRow(Widget parent_widget, string player_name, bool host, bool client)
	{			
		m_PlayerName 	= player_name;
		m_IsHost 		= host;
		m_IsClient		= client;
		super.BuildLayout(parent_widget);
	}
	
	// --------------------------------
	// OVERRIDES 
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_lobby/sg_lobby_unassigned_row.layout";
	}
	
	override protected void FindAllWidgets()
	{
		m_UiPlayerNameLabel = FindLabel("PlayerNameLabel");
		m_UiHostImage	 	= FindImage("PlayerImage");
	}
	
	override protected void LoadAllWidgets()
	{
		SetNameLabel();
		SetHostImage();
		SetWidgetColour();
	}
	
	// ----------------------------------
	// WIDGET SETTERS
	
	private void SetNameLabel()
	{
		m_UiPlayerNameLabel.SetText(m_PlayerName);
	}

	private void SetHostImage()
	{
		m_UiHostImage.Show(m_IsHost);
	}
	
	private void SetWidgetColour()
	{
		if (m_IsClient)
		{
			SetColour(SgCMenuColours.COLOUR_YELLOW);	
		}
		else 
		{
			SetColour(SgCMenuColours.COLOUR_WHITE);
		}
	}
	
	private void SetColour(int colour)
	{
		m_UiPlayerNameLabel.SetColor(colour);
		m_UiHostImage.SetColor(colour);
	}
}