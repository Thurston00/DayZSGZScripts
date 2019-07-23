/*
	Ui class for lobby info panel
*/
class SgUiLobbyInfo extends SgUiMenuPanel
{
	// Widgets
	private 	ImageWidget m_UiMapImage;
	private 	TextWidget  m_UiMapNameLabel;	
	private 	TextWidget	m_UiTeamSizeLabel;
	private		TextWidget	m_UiRoomPassLabel;
	private		TextWidget	m_UiLobbyNameLabel;
	// Data
	private ref SgLobbyData m_LobbyData;
	
	// --------------------------------
	
	// Constructor
	void SgUiLobbyInfo(Widget parent_widget, SgLobbyData lobby_data)
	{			
		m_LobbyData = lobby_data;
		super.BuildLayout(parent_widget);
	}
	
	// --------------------------------
	// OVERRIDES 
		
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_lobby/sg_lobby_info.layout";
	}
	
	override protected void FindAllWidgets()
	{
		m_UiMapImage 			= FindImage("MapImage");
		m_UiMapNameLabel 		= FindLabel("MapNameLabel");
		m_UiTeamSizeLabel 		= FindLabel("TeamSizeValueLabel");
		m_UiRoomPassLabel 		= FindLabel("RoomPassValueLabel");
		m_UiLobbyNameLabel 		= FindLabel("LobbyNameLabel");
	}
	
	override protected void LoadAllWidgets()										
	{
		SetLobbyName();
		SetTeamSizeLabel();
		SetHostPassLabel();
		SetMapWidgets();
	}
	
	// ----------------------------------
	// Widget SETTERS
	private void SetLobbyName()
	{
		m_UiLobbyNameLabel.SetText(m_LobbyData.GetRoomName());
	}
	
	private void SetTeamSizeLabel()
	{
		m_UiTeamSizeLabel.SetText(m_LobbyData.GetTeamMode().GetName());			
	}
	private void SetHostPassLabel()
	{
		string result;
		
		if (m_LobbyData.HasPassword())
		{
			result = "*Yes";
		}
		else 
		{
			result = "*No";
		}
		
		m_UiRoomPassLabel.SetText(result);
	}
	private void SetMapWidgets()
	{
		m_UiMapNameLabel.SetText(m_LobbyData.GetPlayground().GetName());
		m_UiMapImage.LoadImageFile(0, m_LobbyData.GetPlayground().GetImage());
	}
}


