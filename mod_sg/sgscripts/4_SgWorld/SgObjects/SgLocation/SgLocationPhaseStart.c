class SgLocationPhaseStart : SgLocation
{	
	private Object m_CenterObject;
	private ref array<ref Object> m_StartLootPlaces = new array<ref Object>(); // SG_TODO : naozaj je nutne pouzit ref na Object ?
	private ref map<ESgLootStartContainer, ref array<ref SgJsonStartLootItem>> m_StartLoot = new ref map<ESgLootStartContainer, ref array<ref SgJsonStartLootItem>>;
	
	//===============================
	// Event_OnGameInitialized
	//===============================
	override void Event_OnGameInitialized( int pg_id )
	{
		super.Event_OnGameInitialized( pg_id );
		
		m_CenterObject = GetGame().CreateObject( "SG_StaticStartPointAll", GetPosition() );
				
		array<Object> objects = new array<Object>();
		
		vector pos = GetPosition();
		pos[0] = pos[0] + 1;
		pos[2] = pos[2] + 1;
		m_StartLootPlaces.Insert( GetGame().CreateObject( "SG_PathPanel", pos ) );
		
		pos = GetPosition();
		pos[0] = pos[0] + 1;
		pos[2] = pos[2] - 1;
		m_StartLootPlaces.Insert( GetGame().CreateObject( "SG_PathPanel", pos ) );
		
		pos = GetPosition();
		pos[0] = pos[0] - 1;
		pos[2] = pos[2] - 1;
		m_StartLootPlaces.Insert( GetGame().CreateObject( "SG_PathPanel", pos ) );
		
		pos = GetPosition();
		pos[0] = pos[0] - 1;
		pos[2] = pos[2] + 1;
		m_StartLootPlaces.Insert( GetGame().CreateObject( "SG_PathPanel", pos ) );
		
		array<ref SgJsonStartLootItem> json_start_loot = SgSResourceHandler.GetStartLoot();
		
		Print("LocationStart StartLoot => json_start_loot.Count() = "+ json_start_loot.Count() );
		
		for ( int j = 0; j < json_start_loot.Count(); ++j )
		{
			ref SgJsonStartLootItem loot_item = json_start_loot[j];
			
			if ( !m_StartLoot.Contains( loot_item.m_StartLootCategory ) )
			{
				Print("LocationStart StartLoot => m_StartLoot Create category = "+ loot_item.m_StartLootCategory );
				m_StartLoot.Insert( loot_item.m_StartLootCategory, new array<ref SgJsonStartLootItem> );
			}

			Print("LocationStart StartLoot => m_StartLoot Insert category = "+ loot_item.m_StartLootCategory );						
			m_StartLoot[loot_item.m_StartLootCategory].Insert( loot_item );
		}
	}
	
	//===============================
	// Activate
	//===============================
	override void Activate()
	{
		super.Activate();
		
		//TeleportPlayersAtStartingPosition();
		SgSManagerPlayers.PlayersLockMovement(true);
		//SgSManagerPlayers.PlayersWearTeamCloth();
		SgSManagerPlayers.PlayersAttachCollar();
		
		CreateStartLoot();
	}
	
	//===============================
	// Deactivate
	//===============================
	override void Deactivate()
	{
		super.Deactivate();
		
		SgSManagerPlayers.PlayersLockMovement(false);
	}
	
	//===============================
	// IsPhaseLocation
	//===============================
	override bool IsPhaseLocation()
	{
		return true;
	}
	
	//----------------------------------
	// TeleportPlayersAtStartingPosition
	//----------------------------------
	void TeleportPlayersAtStartingPosition()
	{
		vector position				= GetPosition();
		array<ref SgTeam> teams  	= SgSManagerPlayers.GetTeamsArr();
		
		int team_count				= teams.Count();
		int biggest_team_size		= SgSManagerPlayground.GetBiggestTeamSize();
		int teams_spacing			= 2; //2 means that spacing between time has size of 2 player team spacing
		
		float radius				= m_BorderRangeMax;
		
		int pos						= 0;
		int positions				= ( team_count * biggest_team_size ) + ( team_count * teams_spacing ); // #ofPlayers + #ofTeamSpacing
		float theta					= ( Math.PI2 / positions );
		float angle_offset			= Math.RandomFloat(0, 360);
		
		for( int i = 0; i < team_count; ++i )
		{
			SgTeam team						= teams.GetRandomElement();
			array<string> player_uids		= team.GetPlayerUIDs();
			
			teams.RemoveItem(team);
			
			for( int j = 0; j < player_uids.Count(); ++j )
			{
				SgPlayer sg_player = SgSManagerPlayers.GetSgPlayerByPlayerUID( player_uids[j] );
				
				float angle = ( theta * pos ) + angle_offset;
				float x_pos = radius * Math.Cos( angle ) + position[0];
				float y_pos = radius * Math.Sin( angle ) + position[2];
				vector spawn_pos = Vector( x_pos, 0, y_pos );
				SgPluginGameServer.SnapToGround( spawn_pos );
				
				sg_player.SetPosition( spawn_pos );
				
				vector dir = (position - spawn_pos).Normalized();
				sg_player.SetDirection( dir );
				pos++;
			}
			
			pos += biggest_team_size - player_uids.Count();
			pos += teams_spacing;
		}
	}
	
	//----------------------------------
	// CreateStartLoot
	//----------------------------------
	private void CreateStartLoot()
	{
		int containers_count = Math.Ceil(SgSManagerPlayers.GetPlayersCount() * 0.25);
		
		if ( m_StartLootPlaces == null )
		{
			Error("CreateStartLoot -> m_StartLootPlaces is null !");
			return;
		}
		
		if ( m_StartLootPlaces.Count() != 4 )
		{
			Error("CreateStartLoot -> m_StartLootPlaces has bad objects! (m_StartLootPlaces count:"+ m_StartLootPlaces.Count() +"  )");
			return;
		}
		
		array<ref Object> start_loot_places = SgArray<Object>.Copy(m_StartLootPlaces);
		
		for ( int j = 0; j < containers_count; ++j )
		{
			Object start_loot_place = start_loot_places.GetRandomElement();
			start_loot_places.RemoveItem(start_loot_place);
			
			vector pos = start_loot_place.GetPosition();
			//pos[1] = GetGame().SurfaceY(pos[0], pos[2]);
			pos[1] = pos[1] + 0.05;
			EntityAI item_container = EntityAI.Cast(GetGame().CreateObject( "SmallProtectorCase", pos, false ));
			item_container.SetOrientation( "0 0 0" );
			
			ESgLootStartContainer loot_container_cat = Math.RandomInt(0, ESgLootStartContainer.Count);
			
			// Create copy of loot list for spawning
			ref array<ref SgJsonStartLootItem> loot_items = m_StartLoot[loot_container_cat];
			ref array<ref SgJsonStartLootItem> loot_items_copy = new array<ref SgJsonStartLootItem>();
			for ( int m = 0; m < loot_items.Count(); ++m )
			{
				ref SgJsonStartLootItem loot_item_copy = new SgJsonStartLootItem;
				loot_item_copy.m_StartLootCategory = loot_items[m].m_StartLootCategory;
				loot_item_copy.m_ItemName = loot_items[m].m_ItemName;
				loot_item_copy.m_SpawnOdd = loot_items[m].m_SpawnOdd;
				loot_items_copy.Insert( loot_item_copy );
			}				
			
			// 3 is count of items in container
			for ( int i = 0; i < 3; ++i )
			{				
				// Calculate chance for spawn
				float chance_random = Math.RandomFloat01();
				float chance = 0;
				
				// Calculate chance
				for ( int l = 0; l < loot_items.Count(); ++l )
				{
					SgJsonStartLootItem start_item = loot_items_copy[l];
					chance += start_item.m_SpawnOdd;
					
					if ( chance_random <= chance )
					{
						// Spawn item into container
						item_container.GetInventory().CreateEntityInCargo( start_item.m_ItemName );
						
						// Remove item from container item list
						loot_items_copy.RemoveItem( start_item );
						
						// Distribute odd from spawned item to other items
						if ( loot_items_copy.Count() > 0 )
						{
							float add_odd = start_item.m_SpawnOdd / loot_items_copy.Count();
							for ( int k = 0; k < loot_items_copy.Count(); k++ )
							{
								loot_items_copy[k].m_SpawnOdd += add_odd;
							}
						}
						
						break;
					}
				}
			}
			
			delete loot_items_copy;
		}
	}
	
	
	//----------------------------------
	// CreateStartAxeLoot
	//----------------------------------
	/*private void CreateStartAxeLoot()
	{
		array<ref Object> start_loot_places = SgArray<Object>.Copy(m_StartLootPlaces);
		
		int spawnCount = start_loot_places.Count();
		for ( int j = 0; j < spawnCount; ++j )
		{
			Object start_loot_place = start_loot_places.GetRandomElement();
			start_loot_places.RemoveItem(start_loot_place);
			
			vector pos = start_loot_place.GetPosition();
			pos[1] = pos[1] + 0.05;
			EntityAI item_container = EntityAI.Cast(GetGame().CreateObject( "WoodAxe", pos, false ));
			item_container.SetOrientation( "0 0 0" );
			
			ESgLootStartContainer loot_container_cat = Math.RandomInt(0, ESgLootStartContainer.Count);
		}
	}
	
	
	//----------------------------------
	// CreateContainersBorder
	//----------------------------------
	private void CreateContainersBorder()
	{
		vector position 	= GetPosition();
		float radius 		= m_BorderRangeMax + 5; // SG_TODO: Make a constant
		int containerCount 	= Math.Floor( (Math.PI2 * radius) / 6 ); // SG_TODO: Make a constant for container width
		float theta	 		= ( Math.PI2 / containerCount );
		
		for ( int i = 0; i < containerCount; i++ )
		{
			float angle = ( theta * i );
			float x_pos = radius * Math.Cos( angle ) + position[0];
			float y_pos = radius * Math.Sin( angle ) + position[2];
			vector spawn_pos = Vector( x_pos, 0, y_pos );
			
			//SgPluginGameServer.SnapToGround( spawn_pos );
			
			EntityAI item_container;
			if ( i == 22 )
			{
				item_container = EntityAI.Cast(GetGame().CreateObject( "Land_Container_1Aoh", spawn_pos, false )); // Land_Container_1Aoh
				m_Gate = item_container;
			}
			else
			{
				item_container = EntityAI.Cast(GetGame().CreateObject( "Land_Container_1Moh", spawn_pos, false )); // Land_Container_1Aoh
			}
			
			item_container.SetOrientation( Vector( ((360.0 / containerCount) * (containerCount - i)) , 0 , 0 ) );
		}
	}*/
}

