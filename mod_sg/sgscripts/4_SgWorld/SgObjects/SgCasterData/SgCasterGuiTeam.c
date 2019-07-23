/*! \class SgCasterGuiTeam
 *	\brief Container class for a lobby team.
 */
class SgCasterGuiTeam
{
	//! Teams's name.
	private 	int								m_TeamID;
	//! Teams's name.
	private 	string							m_Name;
	//! Team's lobby color.
	private 	int								m_TeamColor;
	//! Array of players in the team.
	private ref array<ref SgCasterGuiPlayer>	m_Players;
	//! Number of slots in the team.
	private		int								m_TeamSize;
/*! \brief Initialization of the container.
 *	\param team_name Name of the team.
 *	\param players Array of player ID's that are in the team.
 */
	void SgCasterGuiTeam( int team_id, string team_name )
	{
		m_TeamID = team_id;
		m_Name = team_name;
		m_TeamColor = 0;
		m_Players = new array<ref SgCasterGuiPlayer>;
	}

/*! \brief Gets the name of the team.
 *	\return The team's name.
 */
	int GetTeamID()
	{
		return m_TeamID;
	}

/*! \brief Set the name of the team.
 *	\param name The team's name.
 */
	void SetName(string name)
	{
		m_Name = name;
	}	
	
/*! \brief Gets the name of the team.
 *	\return The team's name.
 */
	string GetName()
	{
		return m_Name;
	}

/*! \brief Sets the color of the team as an int.
 *	\param Team's color.
 */
	void SetTeamColor( int color )
	{
		m_TeamColor = color;
	}
	
/*! \brief Gets the color of the team as an int.
 *	\return Team's color.
 */
	int GetTeamColor()
	{
		return m_TeamColor;
	}
	
/*! \brief Gets the Lobby Widget of the team.
 *	\return The team's widget.
 */
	int GetTeamSize()
	{
		return m_TeamSize;
	}
	
/*! \brief Gets the players of the team.
 *	\return The team's players.
 */
	array<ref SgCasterGuiPlayer> GetPlayers()
	{
		return m_Players;
	}
	
/*! \brief Adds a player to the team.
 *	\param The new player.
 */
	void AddPlayer( SgCasterGuiPlayer player )
	{
		if( player )
		{
			m_Players.Insert( player );
		}
	}
}