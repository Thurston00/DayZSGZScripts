/*
	Ui class for a single row in Game Browser
*/
class SgUiCustomGameBrowserRow extends SgUiCustomGameBrowserRowHeader
{
	// Widgets
	private 	ImageWidget 	m_UiPassImage;
	private 	ImageWidget 	m_UiLineRow[2];
	private		ButtonWidget 	m_UiSelectedButton;
	// Data
	private ref SgNetDataLobbyInfo m_Data;
	private 	bool 			m_IsSelected;
	// Events
	private ref ScriptInvoker 	Event_OnLobbySelected;
	private ref ScriptInvoker 	Event_OnLobbyEntered;
	
	// --------------------------------------
	
	// Constructor
	void SgUiCustomGameBrowserRow(Widget parent_widget, ref SgNetDataLobbyInfo data, ScriptInvoker event_lobby_selected, ScriptInvoker event_lobbby_entered)
	{	
		m_Data = data;	
		Event_OnLobbySelected = event_lobby_selected;
		Event_OnLobbyEntered = event_lobbby_entered;
		
		super.BuildLayout(parent_widget);
	}
	
	// ------------------------------------
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_content/sg_custom_game/sg_game_browser_slot.layout";
	}
	
	override protected void FindAllWidgets()
	{
		super.FindAllWidgets();
		m_UiPassImage 		= FindImage("LockImage");
		m_UiSelectedButton	= FindButton("SelectButton");
		m_UiLineRow[0]		= FindImage("BottomImage1");
		m_UiLineRow[1]		= FindImage("BottomImage0");
	}
	
	override protected void LoadAllWidgets()
	{
		// Widget data
		m_UiLobbyNameLabel.SetText(m_Data.GetLobbyName());															// Lobby name
		m_UiPlaygroundLabel.SetText(SgCPlayground.FindPlaygroundById(m_Data.GetPlaygroundId()).GetName()); 			// Playground name
		m_UiPassImage.Show(m_Data.GetPassword());																	// Password
		m_UiGameModeLabel.SetText(SgCTeamMode.FindModeById(m_Data.GetTeamSize()).GetName());						// Game mode
		m_UiSlotLabel.SetText(string.Format( "%1 / %2", m_Data.GetPlayerSlotUsed(), m_Data.GetPlayerSlotMax()));	// Current occupation and max slots
		// Handler
		m_UiSelectedButton.SetHandler(this);
	}	
	override protected void UnRegisterAllEvents()
	{
		Event_OnLobbySelected.Remove(UnselectRow);
	}
	
	// -------------------------------
	// SETTERS
	
	private void SelectRow()
	{	
		// Visualy change the 
		m_IsSelected = true;
		SetColour(SgCMenuColours.COLOUR_GREEN_ACCENT_PRESSED);
		
		// Notify listeners
		Event_OnLobbySelected.Invoke(m_Data);
		// Listen for changes
		Event_OnLobbySelected.Insert(UnselectRow);
	}	
	
	private void UnselectRow()
	{
		m_IsSelected = false;
		SwitchColour();
		
		Event_OnLobbySelected.Remove(UnselectRow);
	}
	
	private void SwitchColour()
	{
		if (m_IsSelected)
		{
			SetColour(SgCMenuColours.COLOUR_GREEN_ACCENT_PRESSED);
		}
		else 
		{
			SetColour(SgCMenuColours.COLOUR_LIGHT_GREY);
			m_UiLobbyNameLabel.SetColor(SgCMenuColours.COLOUR_WHITE);
		}
	}

	private void SetColour(int colour)
	{
		m_UiLobbyNameLabel.SetColor(colour);
		m_UiPassImage.SetColor(colour);
		m_UiGameModeLabel.SetColor(colour);
		m_UiSlotLabel.SetColor(colour);
		m_UiPlaygroundLabel.SetColor(colour);
		m_UiLineRow[0].SetColor(colour);
		m_UiLineRow[1].SetColor(colour);
	}
	
	// ------------------------------------------------
	// MOUSE EVENTS
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if(m_Data != null)
		{
			
			if (w == m_UiSelectedButton)
			{
				SetColour(SgCMenuColours.COLOUR_YELLOW);
				return true;
			}
		}
		return false;
	}
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if(m_Data != null)
		{
			if (w == m_UiSelectedButton)
			{
				SwitchColour();
				return true;
			}
		}
		return false;
	}		
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if(m_Data != null)
		{
			if(w == m_UiSelectedButton)
			{
				if(button == MouseState.LEFT)
				{
					SelectRow();
					
					return true;
				}
			}
		}
		return false;
	}
	override bool OnDoubleClick(Widget w, int x, int y, int button)
	{
		if(m_Data != null)
		{
			if(w == m_UiSelectedButton)
			{
				if(button == MouseState.LEFT)
				{	
					// Notify listeners				
					Event_OnLobbyEntered.Invoke(m_Data);
					return true;
				}
			}
		}
		return false;
	}
}