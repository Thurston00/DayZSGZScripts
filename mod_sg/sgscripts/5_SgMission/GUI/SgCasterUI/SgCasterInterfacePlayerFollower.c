/*! \class SgCasterInterfacePlayerFollower
 *	\brief Handler for player tracking Widgets.
 *
 *  Provides updating of position and data in the widgets
 *	that appear above players' heads in the caster interface
 *	view.
 */
class SgCasterInterfacePlayerFollower extends SgSWEH
{
	protected		Widget					m_TrackerRoot;
	protected		Widget					m_Label;
	protected		Widget					m_ExtraInfo;
	protected		TextWidget				m_LabelName;
	protected		Widget					m_TeamColor;
	protected		ImageWidget				m_HealthIcon;
	protected		ImageWidget				m_DeathIcon;
	protected		ItemPreviewWidget		m_WeaponIcon;
	protected		ImageWidget				m_Status0Icon;
	protected		ImageWidget				m_Status1Icon;
	protected		SgPlayerClient			m_Player;
	protected	ref	Timer					m_TimerUpdateData;
	protected	ref	Timer					m_TimerUpdatePos;
	protected		float					m_LabelDefaultX;
	protected		float					m_LabelDefaultY;
	protected		bool					m_IsVisible;
	
/*! \brief Constructor for the player tracker.
 *
 *  Initializes and show the player tracking widget.
 *
 *	/param[in]	player	The reference to the player to be tracked.
 */	
	void SgCasterInterfacePlayerFollower( SgPlayerClient player, int team_color )
	{
		m_Player				=	player;
		m_TrackerRoot			=	GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_caster/mainview/playerbasic.layout", NULL );
		Widget content			=	m_TrackerRoot.FindAnyWidget( "Content" );
		m_Label					=	m_TrackerRoot.FindAnyWidget( "Label" );
		m_LabelName				=	TextWidget.Cast( m_Label.FindAnyWidget( "Header" ).FindAnyWidget( "Name" ) );
		m_TeamColor				=	m_Label.FindAnyWidget( "Teamcolor" );
		m_HealthIcon			=	ImageWidget.Cast( m_Label.FindAnyWidget( "healthIcon" ) );
		m_DeathIcon				=	ImageWidget.Cast( m_Label.FindAnyWidget( "deathIcon" ) );
		m_WeaponIcon			=	ItemPreviewWidget.Cast( m_Label.FindAnyWidget( "WeaponPreview" ) );
		m_Status0Icon			=	ImageWidget.Cast( m_Label.FindAnyWidget( "Status0" ) );
		m_Status1Icon			=	ImageWidget.Cast( m_Label.FindAnyWidget( "Status1" ) );
		m_IsVisible = true;
		
		m_TrackerRoot.SetFlags( WidgetFlags.EXACTSIZE );
		m_TrackerRoot.SetHandler( this );
		m_TrackerRoot.GetScreenSize( m_LabelDefaultX, m_LabelDefaultY );
		
		m_TeamColor.SetColor( team_color );
		m_TeamColor.SetAlpha( 0.7 );
	}
	
/*! \brief Destructor for the player details.
 *
 *  Stops timers, and deletes the widget on call.
 */
	void ~SgCasterInterfacePlayerFollower()
	{
		delete m_TrackerRoot;
	}
	
/*! \brief Function calling the separate Update functons.
 *	
 */
	override void Update()
	{
		if( m_IsVisible && m_Player )
		{
			UpdatePos();
			UpdateData();
		}
	}
	
/*! \brief Function updating the position of the tracker widget.
 *	
 *	Currently tracks using GetScreenPos() on the position of the player.
 */
	void UpdatePos()
	{
		vector pos;
		vector offset	=	"0 3 0";
		vector pointpos;
		vector relativePos;
		int x, y;
		GetScreenSize( x, y );
		pos				=	m_Player.GetPosition();
		pointpos		=	pos + offset;
		relativePos		=	GetGame().GetScreenPos( pointpos );	
		m_TrackerRoot.SetPos( relativePos[0] - 72, relativePos[1] - 48 );
		float xs, ys;
		if( relativePos[0] == x || relativePos[0] == 0 || relativePos[1] == y || relativePos[1] == 0 )
		{
			m_TrackerRoot.Show( false );
			return;
		}
		else if( ( (m_LabelDefaultX - (relativePos[2] / 2)) > 40 || SgSClientCaster.GetSelectedPlayer() == m_Player ) && relativePos[2] > 0 )
		{
			m_TrackerRoot.Show( true );
			m_LabelName.Show( true );
			xs = ( m_LabelDefaultX - ( relativePos[2] / 2 ) );
			ys = ( m_LabelDefaultY  - ( relativePos[2] / 6 ) );
		}
		else
		{
			m_TrackerRoot.Show( false );
		}
		
		m_TrackerRoot.SetSize( xs, ys );
		m_TrackerRoot.SetPos( relativePos[0] - (xs / 2), relativePos[1] - ys );
	}
	
/*! \brief Function updating the data in the tracker widget.
 *
 *  Skips updating data in detailed pop-out view if it is hidden.
 */
	void UpdateData()
	{
		if( !SgSClientCaster.GetSelectedPlayerHeader() && SgSClientCaster.GetSelectedPlayer() == m_Player)
		{
			SelectThisPlayer();
		}
		
		if( !m_Player.IsAlive() )
		{
			m_HealthIcon.Show(false);
			m_DeathIcon.Show(true);
		} else
		{
			m_HealthIcon.SetColor( GetHealthColor( m_Player ) );
		}
		
		m_LabelName.SetText( m_Player.GetUserName() );
		
		if( m_Player.GetVirtualHud() )
		{
			int a, b;
			BadgeFracture fract	=	BadgeFracture.Cast( m_Player.GetVirtualHud().GetElement( eDisplayElements.DELM_BADGE_FRACTURE ) );
			TendencyBlood blood	=	TendencyBlood.Cast( m_Player.GetVirtualHud().GetElement( eDisplayElements.DELM_BADGE_BLEEDING ) );
			if( fract )
			{
				a = fract.m_Colors[ fract.GetValue() ];
				m_Status1Icon.Show( true );
				m_Status1Icon.SetColor( a );
			}
			else
			{
				m_Status1Icon.Show( false );
			}
			if( blood )
			{
				b = blood.m_Colors[ blood.GetValue() ];
				m_Status0Icon.Show( true );
				m_Status0Icon.SetColor( b );
			}
			else
			{
				m_Status0Icon.Show( false );
			}
		} else
		{
			m_Status0Icon.Show( false );
			m_Status1Icon.Show( false );
		}
		
		ItemBase iteminhands = ItemBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );
		
		if( iteminhands	)
		{
			m_WeaponIcon.Show( true );
			m_WeaponIcon.SetItem( iteminhands );
			int w, h;
			float x, y;
			GetGame().GetInventoryItemSize( iteminhands, w, h );
			if( w < h )
				m_WeaponIcon.SetRotation( 0, 0, 90, true );
			else
				m_WeaponIcon.SetRotation( 0, 0, 0, true );
		}
		else
			m_WeaponIcon.Show( false );
	}
	
/*! \brief Shows the tracker widget.
 */
	override void Show()
	{
		m_TrackerRoot.Show( true );
	}	
	
/*! \brief Hides the tracker widget.
 */
	override void Hide()
	{
		m_TrackerRoot.Show( false );
	}
	
/*! \brief Function to calculate the color for health on a scale of 1 to 100,
 *         from red to green respectively.
 *
 *  Linearly interpolates between full green at 100%, yellow at 50% to red at 0%.
 *	
 *	/param[in]	player	The player to calculate health for.
 *	
 *	/return	The int value for the ARGB value of the colour.
 */
	int GetHealthColor( SgPlayerClient player )
	{
		//float currhealth = player.GetHealth( "", "" );
		//float maxhealth = player.GetMaxHealth( "", "" );
		//float healthpercent = currhealth / maxhealth;
		//int red = healthpercent * 255;
		//int green = ( 1 - healthpercent ) * 255;
		//return ARGB( 255, red, green, 0 );
	}
	
/*! \brief Function retrieving the colour of the team.
 *
 *	/param[in]	team	The team to determine colour for.
 *	
 *	/return	The int defining the colour set in the team's variable.
 
	int GetTeamColor( SgTeam team )
	{
		if( team ) return team.GetColour();
		else return 0;
	}
*/
	
/*! \brief Makes the player selected in the SgPluginCasterManager class.
 *
 *  Required for persistency between opening and closing the interface.
 */
	void DeselectThisPlayer()
	{
		if( SgSClientCaster.GetSelectedPlayerHeader() )
		{
			SgSClientCaster.GetSelectedPlayerHeader().Hide();
		}
		
		m_TeamColor.SetColor( m_Player.GetTeamColor() );

		SgSClientCaster.SelectPlayer( null, null );
		SgSClientCaster.SetSelectedPlayerHeader( null );
	}
		
/*! \brief Makes the player selected in the SgPluginCasterManager class.
 *
 *  Required for persistency between opening and closing the interface.
 */
	void SelectThisPlayer()
	{
		Show();
		
		m_TeamColor.SetColor( m_Player.GetTeamColor() | 0xFD000000 );
		
		SgSClientCaster.SelectPlayer( m_TrackerRoot, m_Player );
		SgSClientCaster.SetSelectedPlayerHeader( this );
	}
	
/*! \brief Determines if this player's widget should be selected
 *	and runs SelectThisPlayer()
 */
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if ( w == m_Label )
		{
			if( SgSClientCaster.GetSelectedPlayerHeader() )
			{
				SgCasterInterfacePlayerFollower.Cast( SgSClientCaster.GetSelectedPlayerHeader() ).DeselectThisPlayer();
			}
			else
			{
				SelectThisPlayer();
			}
			return 0;
		}
		return 0;
	}
	
/*! \brief Determines if this player should be snapped to with camera
 *	and runs LockThisPlayer()
 */
	override int OnDoubleClick( Widget w, int x, int y, int button )
	{
		if ( w == m_Label )
		{
			SgSClientCaster.SetSelectedPlayerWidget( ButtonWidget.Cast( m_TrackerRoot ) );
			SgSClientCaster.CasterPlayerCamEnable( m_Player );
		}
		return 0;
	}
}