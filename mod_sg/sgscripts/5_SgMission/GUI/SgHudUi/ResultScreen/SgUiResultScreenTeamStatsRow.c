class SgUiResultScreenTeamStatsRow extends SgUiMenuPanel
{
	private int m_Rank;
	private int m_ZombieKills = 0;
	private int m_PlayerKills = 0;

	// ---------------------------------------------
	
	void SgUiResultScreenTeamStatsRow(Widget parent_widget, ref SgNetDataTeamResult data )
	{
		m_Rank = data.GetRank();
		for(int i = 0; i < data.GetPlayerResultList().Count(); i++)
		{
			m_ZombieKills += data.GetPlayerResultList()[i].GetZombieKills();				// Add Zombie killed
			m_PlayerKills += data.GetPlayerResultList()[i].GetPlayerKillsList().Count();	// Add Players killed 
		}
		BuildLayout(parent_widget);
	}
	
	// ---------------------------------------------
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_result_screen/sg_result_team_stat_row.layout";
	}
	override void LoadAllWidgets()
	{
		FindLabel("RankLabel").SetText(string.Format("%1/%2", m_Rank, "8"));				// SG_TODO: Pato --> this
		FindLabel("PlayerKillsLabel").SetText(m_PlayerKills.ToString());
		FindLabel("ZombieKillsLabel").SetText(m_ZombieKills.ToString());
	}
}