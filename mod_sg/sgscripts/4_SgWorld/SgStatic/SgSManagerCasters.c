class SgSManagerCasters
{
	protected static ref array<ref SgCaster> m_Casters = new array<ref SgCaster>();
	
	//=================================
	// EnableCasters
	//=================================
	static void EnableCasters( SgCasterGuiData data )
	{
		/*SgLobbyTeam caster_team = SgSLobbyServer.GetTeams().Get( SgSLobbyServer.GetTeams().Count() - 1 );
		array<string> casters = caster_team.GetPlayerUIDs();
		
		for( int i = 0; i < casters.Count(); i++ )
		{
			SgPlayer player = SgSManagerPlayers.GetSgPlayerByPlayerUID( casters.Get(i) );
			if( player )
			{
				PlayerIdentity id = player.GetIdentity();
				if( id )
				{
					SgLocation location_start = SgSManagerPlayground.GetLocationByLocationType( ESgLocationType.PhaseStart );
					GetGame().SelectSpectator( id, "SgCasterCamera", location_start.GetPosition() );
					
					CreateCaster( player, data );
					
					player.SetPosition( location_start.GetPosition() );
				}	
			}
		}*/
	}
	
	//----------------------------------
	// CreateCaster
	//----------------------------------
	protected static void CreateCaster( SgPlayer player, SgCasterGuiData data )
	{
		PlayerIdentity identity = player.GetIdentity();
		
		SgCaster caster = new SgCaster( identity );
		
		m_Casters.Insert( caster );
		
		//SG_TODO: Send `SgCasterGuiData data` to Caster
	}
	
	//==================================
	// GetCasters
	//==================================
	static array<ref SgCaster> GetCasters()
	{
		return m_Casters;
	}
}