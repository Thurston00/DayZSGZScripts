/*! \class SgCasterGuiPlayer
 *	\brief Container class for a lobby user.
 */
class SgCasterGuiPlayer
{
	private string			m_SgPlayerUID;
	//! Player's team's ID.
	private int				m_TeamID = -1;
	//! Player's team's Color.
	private int				m_TeamColor;
	//! Player's ready status.
	private bool 			m_Ready = false;
	//! Player's access status.
	private string 			m_Avatar;

/*! \brief Initialization of the container.
 *	\param player_UID UID of the player.
 *	\param team_id Id of the team.
 *	\param color Team color.
 */
	void SgCasterGuiPlayer( string player_UID, int team_id, int color )
	{
		m_SgPlayerUID	= player_UID;
		m_Avatar		= "set:sg_gui image:avatar";
		m_TeamID		= team_id;
		m_TeamColor		= color;
	}

/*! \brief Gets the UID of the Player.
 *	\return UID of the player.
 */
	string GetPlayerUID()
	{
		return m_SgPlayerUID;
	}

/*! \brief Gets the UID of the Player.
 *	\return UID of the player.
 */
	string GetUserName()
	{
		SgPlayerClient player = SgSClientGame.GetPlayerByUID( m_SgPlayerUID );
		return player.GetUserName();
	}

/*! \brief Gets the player's team's ID.
 *	\return The ID of the player's team, -1 if not in a team.
 */
	int GetTeam()
	{
		return m_TeamID;
	}
	
/*! \brief Gets the player's team's Color.
 *	\return The value of the player's team's color.
 */
	int GetTeamColor()
	{
		return m_TeamColor;
	}
	
/*! \brief Gets the player's avatar.
 *	\return Filename of the player's avatar.
 */
	string GetAvatar()
	{
		return m_Avatar;
	}
}