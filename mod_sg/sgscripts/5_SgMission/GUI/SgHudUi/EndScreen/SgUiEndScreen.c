class SgUiEndScreen extends SgUiHudPanel
{
	private bool m_IsWinner;
	
	void SgUiEndScreen(bool winner)
	{
		m_IsWinner = winner;
		BuildLayout();
	}

	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_end_game_message.layout";
	}
	override protected void LoadAllWidgets()
	{		
		if (m_IsWinner)
		{
			FindLabel("EndMessageLine1").SetText(SgCMenuWidgetStrings.END_SCREEN_WINNER_LINE_1);
			FindLabel("EndMessageLine2").SetText(SgCMenuWidgetStrings.END_SCREEN_WINNER_LINE_2);
		}
		else 
		{
			FindLabel("EndMessageLine1").SetText(SgCMenuWidgetStrings.END_SCREEN_DEAD_LINE_1);
			FindLabel("EndMessageLine2").SetText(SgCMenuWidgetStrings.END_SCREEN_DEAD_LINE_2);
		}
	}
}