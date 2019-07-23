// DESIGN_ID: 0001

typedef array<ref SgNetDataLobbyInfo> SgNetDataLobbyInfoArray;

/*
	"Pseudo abstract" (it would be so nice to have an abstract class support in Enfusion) SG network data class for loading a lobby list
*/
class SgNetDataLobbyListLoad{}

/*
	SG network request data class for load lobby 
*/
class SgNetDataLobbyListLoadRequest extends SgNetDataLobbyListLoad {}

/*
	SG network response data class for load lobby 
*/
class SgNetDataLobbyListLoadResponse extends SgNetDataLobbyListLoad
{
	private ref SgNetDataLobbyInfoArray m_LobbyList;					// List of all found lobbies 
		
	// -------------------------------------------
	// GETTERS
	array<ref SgNetDataLobbyInfo> GetLobbyList()
	{
		return m_LobbyList;
	}
}