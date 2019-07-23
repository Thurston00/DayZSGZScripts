/*
	Ui class for a single row in lobby team slot 
*/
class SgUiLobbyPlayerSlot extends SgUiMenuPanel
{
	// Widgets
	private 	TextWidget 				m_UiPlayerNameLabel;
	private 	ImageWidget 			m_UiReadyImage;
	private 	ImageWidget 			m_UiHostImage; 
	private 	ButtonWidget			m_UiJoinButton;
	private 	Widget					m_UiReadyImageFrame;
	private 	Widget					m_UiBorder;
	// Data
	private 	int 					m_PlayerSlotID;
	private 	int 					m_TeamSlotID;
	private 	bool 					m_IsHost;
	private ref SgNetDataLobbyPlayer 	m_Player;
	
	// --------------------------------
	
	// Constructor
	void SgUiLobbyPlayerSlot(Widget parent_widget, int player_slot_id, int team_slot_id)
	{	
		m_PlayerSlotID 	= player_slot_id;
		m_TeamSlotID 	= team_slot_id;		
		super.BuildLayout(parent_widget);
	}
	
	// --------------------------------
	// OVERRIDES 
	
	override string GetLayoutPath()
	{
	 	return "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_lobby/sg_lobby_player_slot.layout";
	}
	
	override protected void FindAllWidgets()
	{
		m_UiPlayerNameLabel = FindLabel("PlayerNameLabel");
		m_UiHostImage 		= FindImage("HostImage");
		m_UiReadyImage 		= FindImage("ReadyImage");
		m_UiJoinButton		= FindButton("JoinButton");
		m_UiBorder			= FindPanel("Border");
	}
	
	override protected void LoadAllWidgets()										
	{
		UpdateLayout();
		
		m_UiBorder.SetColor(SgCMenuColours.COLOUR_YELLOW);
		m_UiJoinButton.SetHandler(this);	
	}
	
	// -------------------------------------
	// GETTERS
	bool IsEmpty()
	{
		if (m_Player)
		{
			return true;
		}
		return false;
	}
	
	int GetTeamSlotID()
	{
		return m_TeamSlotID;
	}
	
	int GetSlotID()
	{
		return m_PlayerSlotID;
	}
	
	// ---------------------------------------------
			
	// Clear this layout back to default
	void ClearSlot()
	{
		m_Player = null;
		m_IsHost = false;
		UpdateLayout();
	}
	
	void AddPlayer(SgNetDataLobbyPlayer player, bool is_host)
	{
		m_Player = player;
		m_IsHost = is_host;
		UpdateLayout();
	}
	
	// -------------------------------------
	// WIDGET SETTERS
	
	void UpdateLayout()
	{
		SetPlayerLabel();
		SetReadyImage();
		SetHostImage();	
		SetSlotColour();
	}
	
	private void SetReadyImage()
	{
		if (m_Player)
		{		
			if (m_IsHost)
			{
				m_UiReadyImage.Show(false);
			}
			else 
			{
				m_UiReadyImage.Show( m_Player.GetReadyCheck() );		
			}
		}
		else 
		{
			m_UiReadyImage.Show(false);
		}
	}
	
	private void SetHostImage()
	{
		if(m_Player)
		{
			m_UiHostImage.Show(m_IsHost);
		}
		else 
		{
			m_UiHostImage.Show(false);
		}
	}
	
	private void SetPlayerLabel()
	{		
		if(m_Player)
		{
			if(m_Player.GetSteamName().Length() > 16)
			{
				m_UiPlayerNameLabel.SetText(m_Player.GetSteamName().Substring(0,16));
			}
			else 
			{
				m_UiPlayerNameLabel.SetText( m_Player.GetSteamName());
			}	
		}
		else 
		{
			m_UiPlayerNameLabel.SetText(SgCMenuWidgetStrings.LOBBY_SLOT_EMPTY);
		}
	}
	
	private void SetSlotColour()
	{
		if(m_Player)
		{
			if(m_Player.GetPlayerUID() == SgLobbyData.GetClientUID())
			{ 
				m_UiBorder.Show(true);
				SetAllColour(SgCMenuColours.COLOUR_YELLOW);
				return;
			}
			
			SetAllColour(SgCMenuColours.COLOUR_WHITE);
			return;
		}
	
		m_UiBorder.Show(false);
		
		SetAllColour(SgCMenuColours.COLOUR_GREY);
	}
	
	private void SetAllColour(int colour)
	{
		m_UiPlayerNameLabel.SetColor(colour);
		m_UiReadyImage.SetColor(colour);
		m_UiHostImage.SetColor(colour);
		//m_UiBorder.SetColor(colour);
	}
	
	// ------------------------------------
	// Mouse EVENTS
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (w == m_UiJoinButton)
		{
			if (button == MouseState.LEFT)
			{
				if (!IsEmpty())
				{
					//SgDebug.Debug("Trying to join to slot :" + m_TeamSlotID.ToString() + " | " + m_PlayerSlotID.ToString(), ClassName(), "OnClick");
					
					// Send server request 
					SgLobbyEvents.Event_AssignePlayer.Invoke(m_TeamSlotID, m_PlayerSlotID);
				}
				else 
				{
					SgDebug.Debug("Selected slot is occupied!" , ClassName(), "OnClick");
				}
				
				return true;
			}
		}
		return false;	
	}

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if ( w == m_UiJoinButton)
		{
			if(m_Player)
			{
				return false;
			}
			m_UiBorder.Show(true);
			return true;
		}
		return false;
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if ( w == m_UiJoinButton)
		{
			if(m_Player)
			{
				return false;
			}
			m_UiBorder.Show(false);
			return true;
		}
		return false;
	}	
}