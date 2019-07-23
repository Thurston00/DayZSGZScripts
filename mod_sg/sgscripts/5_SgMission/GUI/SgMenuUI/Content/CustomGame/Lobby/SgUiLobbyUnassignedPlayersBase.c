/*
	Ui class for unassigned player panel in custom lobby
*/
class SgUiUnassignedPlayers extends SgUiMenuPanel
{
	// Widgets
	private 	Widget 			m_UiScroller;
	private 	ButtonWidget 	m_UnassinButton;
	// Custom Widgets
	private ref array<ref SgUiUnassignedPlayerRow> m_UiScrollerRows = new array<ref SgUiUnassignedPlayerRow>;
	
	// ----------------------------------
	
	// Constructor
	void SgUiUnassignedPlayers(Widget parent_widget)
	{
		super.BuildLayout(parent_widget);
	}
	
	// --------------------------------
	// OVERRIDES 
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_lobby/sg_lobby_unassigned_players.layout";
	}
	
	override protected void FindAllWidgets()
	{
		m_UiScroller 	= FindPanel("Scroller");
		m_UnassinButton = FindButton("ScrollerButton");
	}
	
	override protected void LoadAllWidgets()										
	{
		m_UnassinButton.SetHandler(this);
	}
	
	// ----------------------------------
	
	void ClearScroller()
	{
		m_UiScrollerRows.Clear();
	}
	
	void AddUnassignedPlayerRow(SgNetDataLobbyPlayer player, bool isHost)
	{
		string client_id = SgLobbyData.GetClientUID();
		
		if (player.GetSlotId() == -1)
		{
			bool is_clinet = false;
			
			if (player.GetPlayerUID() == client_id)
			{
				is_clinet = true;
			}
			
			m_UiScrollerRows.Insert( new SgUiUnassignedPlayerRow(m_UiScroller, player.GetSteamName(), isHost, is_clinet) );
		}
	}
	
	// ----------------------------------
	// EVENTS
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (w == m_UnassinButton) 
		{
			if (button == MouseState.LEFT)
			{
				SgDebug.Debug("Unassigne button Clicked.", ClassName(), "OnClick");
				SgLobbyEvents.Event_UnassignePlayer.Invoke();
				return true;
			}
		}
		return false;
	}	
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w == m_UnassinButton)
		{
			m_UiBackground.SetColor(SgCMenuColours.COLOUR_HOVER);
			return true;
		}
		
		return super.OnMouseEnter(w,x,y);
	}	
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w == m_UnassinButton)
		{
			m_UiBackground.SetColor(SgCMenuColours.COLOUR_PANEL_BACKGROUND);
			return true;
		}
		
		return super.OnMouseEnter(w,x,y);
	}
}