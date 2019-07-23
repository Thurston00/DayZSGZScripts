class SgWidgetPlayerInfo
{
	Widget		m_WidgetRoot;
	TextWidget	m_WidgetPlayerName;
	TextWidget	m_WidgetTeamName;
	TextWidget	m_WidgetPlyerStatus;
	TextWidget	m_WidgetPlyerScore;
	TextWidget	m_WidgetPlyerKills;
	TextWidget	m_WidgetZombieKills;
	TextWidget	m_WidgetAnimalKills;
	
	void SgWidgetPlayerInfo(Widget parent, int index)
	{
		m_WidgetRoot = GetGame().GetWorkspace().CreateWidgets("mod_sg/gui/layouts/sg_server_info/sg_server_info_player.layout", parent);
		
		float width;
		float height;
		
		m_WidgetRoot.GetSize(width, height);
		m_WidgetRoot.SetPos(0 , height * index);
		
		m_WidgetPlayerName		= TextWidget.Cast( m_WidgetRoot.FindAnyWidget("txt_name") );
		m_WidgetTeamName		= TextWidget.Cast( m_WidgetRoot.FindAnyWidget("txt_team") );
		m_WidgetPlyerStatus		= TextWidget.Cast( m_WidgetRoot.FindAnyWidget("txt_status") );
		m_WidgetPlyerScore		= TextWidget.Cast( m_WidgetRoot.FindAnyWidget("txt_score") );
		m_WidgetPlyerKills		= TextWidget.Cast( m_WidgetRoot.FindAnyWidget("txt_player_kills") );
		m_WidgetZombieKills		= TextWidget.Cast( m_WidgetRoot.FindAnyWidget("txt_zombie_kills") );
		m_WidgetAnimalKills		= TextWidget.Cast( m_WidgetRoot.FindAnyWidget("txt_animal_kills") );
	}
	
	void ~SgWidgetPlayerInfo()
	{
	}
	
	void SetPlayerName(string text)
	{
		m_WidgetPlayerName.SetText( text );
	}
	
	void SetTeamName(string text)
	{
		m_WidgetTeamName.SetText( text );
	}
	
	void SetPlayerStatus(string text)
	{
		m_WidgetPlyerStatus.SetText( text );
	}
	
	void SetPlayerScore(string text)
	{
		m_WidgetPlyerScore.SetText( text );
	}
	
	void SetPlayerKills(string text)
	{
		m_WidgetPlyerKills.SetText( text );
	}
	
	void SetZombieKills(string text)
	{
		m_WidgetZombieKills.SetText( text );
	}
	
	void SetAnimalKills(string text)
	{
		m_WidgetAnimalKills.SetText( text );
	}
}