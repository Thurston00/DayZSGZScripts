class SgUiResultScreenPlayerStatsHeader extends SgUiMenuPanel
{
	void SgUiResultScreenPlayerStatsHeader(Widget parent)
	{
		BuildLayout(parent);
	}
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_result_screen/sg_result_player_stat_header.layout";
	}
}