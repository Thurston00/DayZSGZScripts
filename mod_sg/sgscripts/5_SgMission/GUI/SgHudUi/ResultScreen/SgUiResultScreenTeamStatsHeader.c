class SgUiResultScreenTeamStatsHeader extends SgUiMenuPanel
{
	void SgUiResultScreenTeamStatsHeader(Widget parent)
	{
		BuildLayout(parent);
	}
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_result_screen/sg_result_team_stat_header.layout";
	}
}