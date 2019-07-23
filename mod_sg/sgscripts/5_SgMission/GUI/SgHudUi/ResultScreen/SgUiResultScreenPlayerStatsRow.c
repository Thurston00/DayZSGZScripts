class SgUiResultScreenPlayerStatsRow extends SgUiMenuPanel
{
	private TextWidget 	m_UiNameLabel;
	private TextWidget 	m_UiPlayerKillsLabel;
	private TextWidget 	m_UiZombieKillsLabel;
	private TextWidget 	m_UiSurvTimeLabel;
	
	private bool m_IsClientPlayer;
	private string m_Name;
	private int m_ZombieKills;
	private int m_PlayerKills;
	private int m_SurvivalTime;
	
	// ----------------------------------------
	
	void SgUiResultScreenPlayerStatsRow(Widget parent_widget, string name, int zombie_kill, int player_kill, int survival_time, bool is_player)
	{
		m_Name = name;
		m_ZombieKills = zombie_kill;
		m_PlayerKills = player_kill;
		m_SurvivalTime = survival_time;
		m_IsClientPlayer = is_player;
		
		BuildLayout(parent_widget);
	}
	
	// -----------------------------------------

	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_result_screen/sg_result_player_stat_row.layout";
	}
	override void FindAllWidgets()
	{
		m_UiNameLabel 			= FindLabel("PlayerNameLabel");
		m_UiPlayerKillsLabel 	= FindLabel("PlayerKillsLabel");
		m_UiZombieKillsLabel	= FindLabel("ZombieKillsLabel");
		m_UiSurvTimeLabel 		= FindLabel("SurvivalTimeLabel");
	}
	override void LoadAllWidgets()
	{	
		if (m_IsClientPlayer)
		{
				m_UiNameLabel.SetColor(SgCMenuColours.COLOUR_YELLOW);
				m_UiPlayerKillsLabel.SetColor(SgCMenuColours.COLOUR_YELLOW);
				m_UiZombieKillsLabel.SetColor(SgCMenuColours.COLOUR_YELLOW);
				m_UiSurvTimeLabel.SetColor(SgCMenuColours.COLOUR_YELLOW);
		}
		
		m_UiNameLabel.SetText(m_Name);
		m_UiPlayerKillsLabel.SetText(m_PlayerKills.ToString());
		m_UiZombieKillsLabel.SetText(m_ZombieKills.ToString());
		m_UiSurvTimeLabel.SetText(m_SurvivalTime.ToString());
	}
	
	// --------------------------------------
}