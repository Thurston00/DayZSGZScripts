class SgCasterInterfacePlayer extends SgSWEH
{
	private Widget									m_UserWidget;
	private TextWidget								m_Name;
	private ImageWidget								m_Background;
	private	bool									m_IsVisible;
	private	bool									m_IsVisibleFollower;
	protected ref SgCasterInterfacePlayerFollower	m_Follower;
	
	void SgCasterInterfacePlayer( Widget root, SgCasterGuiPlayer player, SgPlayerClient object, int teamcolor )
	{
		m_UserWidget	= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_caster/leftpanel/playerinfo_wide.layout", root );
		m_Name			= TextWidget.Cast( m_UserWidget.FindAnyWidget( "Name" ) );
		m_Background	= ImageWidget.Cast( m_UserWidget.FindAnyWidget( "Background" ) );
		
		m_Follower		= new SgCasterInterfacePlayerFollower( object, player.GetTeamColor() );
		
		m_Background.SetColor( teamcolor );
		m_Background.SetAlpha( 0.3 );
		
		SetName( player.GetUserName() );
		m_IsVisible = true;
		m_IsVisibleFollower = true;
		m_UserWidget.SetHandler( this );
	}
	
	void ~SgCasterInterfacePlayer()
	{
		delete m_Follower;
		delete m_UserWidget;
	}
	
	void SetName( string name )
	{
		m_Name.SetText( name );
	}
	
	override void Update()
	{
		m_Follower.Update();
	}
	
	override void Show()
	{
		m_IsVisible = true;
		m_UserWidget.Show( true );
		m_UserWidget.Update();
	}
	
	override void Hide()
	{
		m_IsVisible = false;
		m_UserWidget.Show( false );
		m_UserWidget.Update();
	}
	
	override void Toggle()
	{
		if( m_IsVisible )
		{
			m_IsVisible = false;
			m_UserWidget.Show( false );
		}
		else
		{
			m_IsVisible = true;
			m_UserWidget.Show( true );
		}
		m_UserWidget.Update();
	}
	
	void ShowFollower()
	{
		m_IsVisibleFollower = true;
		m_Follower.Show();
	}
	
	void HideFollower()
	{
		m_IsVisibleFollower = false;
		m_Follower.Hide();
	}
	
	void ToggleVisibleFollower()
	{
		if( m_IsVisibleFollower )
		{
			m_IsVisibleFollower = false;
			m_Follower.Hide();
		}
		else
		{
			m_IsVisibleFollower = true;
			m_Follower.Show();
		}
	}
	
	void PlayerHealed( float heal )
	{
		
	}
	
	void PlayerDamaged( float damage )
	{
		
	}
	
	void PlayerDied()
	{
		
	}
}