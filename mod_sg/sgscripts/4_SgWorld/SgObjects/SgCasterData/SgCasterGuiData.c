/*! \class SgCasterGuiData
 *	\brief Container class for a lobby.
 */
class SgCasterGuiData
{
	//! Name of the game
	string							m_GameName;
	//! ID of the playground
	int								m_PgID;
	//! Array of teams in the lobby
	ref array<ref SgCasterGuiTeam>	m_Teams;
	//! Amount of users in the lobby
	int								m_PlayerCount;
	
	void Init()
	{
		m_Teams		= new array<ref SgCasterGuiTeam>;
	}
	
/*! \brief Initialization of the container. Converts the server data to client data.
 *	\param name Name of the game.
 *	\param type Type of the game.
 *	\param pg_id ID of the playground.
 *	\param users Array of server users.
 *	\param teams Array of server teams.
 */
	void Init( string name, int pg_id, ref array<ref SgCasterGuiTeam> gui_teams, int playercount )
	{
		m_GameName	= name;
		m_PgID		= pg_id;
		m_Teams		= gui_teams;
		m_PlayerCount = playercount;
	}
	
/*! \brief Get the size of the teams.
 *	\return Number of slots in the team.
 */
	int GetTeamSize()
	{
		if( m_Teams.Count() > 0 )
		{
			return (16 / m_Teams.Count()); // SG_TODO
		}
		return 0;
	}

/*! \brief Get the number of teams.
 *	\return Number of teams.
 */	
	int GetTeamCount()
	{
		return m_Teams.Count();
	}
	
/*! \brief Get the number of total players.
 *	\return Number of players.
 */	
	int GetPlayerCount()
	{
		return m_PlayerCount;
	}
	
/*! \brief Get the reference to all teams.
 *	\return Reference to the team array container.
 */	
	array<ref SgCasterGuiTeam> GetTeams()
	{
		return m_Teams;
	}
}