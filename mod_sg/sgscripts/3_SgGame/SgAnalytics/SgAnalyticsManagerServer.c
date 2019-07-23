modded class AnalyticsManagerServer
{
	void SendMatchStartEvent( string matchId, int playerCount )
	{
		Analytics.SendMatchStartEvent( matchId, playerCount );
	}
	
	void SendMatchEndEvent()
	{
		Analytics.SendMatchEndEvent();
	}
	
	void SendPhaseStartEvent( int number )
	{
		Analytics.SendPhaseStartEvent( number );
	}
	
	void SendPhaseEndEvent()
	{
		Analytics.SendPhaseEndEvent();
	}
	
	void SendTransitionStartEvent( int number )
	{
		Analytics.SendTransitionStartEvent( number );
	}
	
	void SendTransitionEndEvent()
	{
		Analytics.SendTransitionEndEvent();
	}
	
	//player is unconscious
	void SendUnconsciousnessEvent( Man player, EntityAI source )
	{
		if ( player == null || player.GetIdentity() == null || source == null || source.GetHierarchyRootPlayer() == null || source.GetHierarchyRootPlayer().GetIdentity() == null ) { return; }
		
		string characterId;
		ESgDeathReason cause;
		vector position;
		string attackerId;
		string weapon;
		vector attackerPosition;
		
		characterId = player.GetIdentity().GetId();
		position = player.GetPosition();
		
		Man attacker;
		if ( source )
		{
			if ( source.IsWeapon() || source.IsMeleeWeapon() )
			{
				weapon = source.GetType();
			}
			
			attacker = source.GetHierarchyRootPlayer();
			if ( attacker && attacker.IsPlayer() )
			{
				attackerId = attacker.GetIdentity().GetId();
				attackerPosition = attacker.GetPosition();
			}
		}
		
		if ( attacker )
		{
			cause = ESgDeathReason.Player;
		}
		else
		{
			cause = ESgDeathReason.Other;
		}
		
		//send
		Analytics.SendUnconsciousnessEvent( characterId, cause, position, attackerId, weapon, attackerPosition );
	}
	
	//[NMI]
	void SendResurrectEvent( string characterId, vector position, string teammateId )
	{
		Analytics.SendResurrectEvent( characterId, position, teammateId );
	}
	
	//player died
	void SendDeathEvent( Man player, Object killer, ESgDeathReason cause )
	{
		EntityAI killer_entity = EntityAI.Cast( killer );
		if ( player.GetIdentity() == null || killer_entity.GetHierarchyRootPlayer() == null || killer_entity.GetHierarchyRootPlayer().GetIdentity() == null ) { return; }
		
		string characterId;
		vector position;
		string attackerId;
		string weapon;
		vector attackerPosition;		
		
		characterId = player.GetIdentity().GetId();
		position = player.GetPosition();
		
		if ( killer_entity )
		{
			//weapon
			if ( killer_entity.IsWeapon() || killer_entity.IsMeleeWeapon() )
			{
				weapon = killer_entity.GetType();
			}
			
			Man attacker = killer_entity.GetHierarchyRootPlayer();
			if ( attacker.IsPlayer() )
			{
				attackerId = attacker.GetIdentity().GetId();
				attackerPosition = attacker.GetPosition();
			}
		}
		
		//send
		Analytics.SendDeathEvent( characterId, cause, position, attackerId, weapon, attackerPosition );
	}
	
	//shot fired
	void AddShotEvent( Man player, EntityAI weapon_entity )
	{
		if ( player.GetIdentity() == null ) { return; }
		
		string characterId;
		string weapon;
		vector position;
		
		if ( player )
		{
			characterId = player.GetIdentity().GetId();
			position = player.GetPosition();
		}
		weapon = weapon_entity.GetType();
		
		//send
		Analytics.AddShotEvent( characterId, weapon, position );
	}
	
	//player hit
	void AddHitEvent( Man player, EntityAI source )
	{
		string characterId;
		string weapon;
		vector position;
		
		position = player.GetPosition();
		
		if ( source )
		{
			if ( source.IsWeapon() || source.IsMeleeWeapon() )
			{
				weapon = source.GetType();
				
				if ( source.IsMeleeWeapon() )
				{
					AddMeleeHitEvent( characterId, weapon, position );
				}
			}
		}
		
		//send
		Analytics.AddHitEvent( characterId, weapon, position );
	}
	
	//player hit with melee
	void AddMeleeHitEvent( string characterId, string weapon, vector position )
	{
		Analytics.AddMeleeHitEvent( characterId, weapon, position );
	}
	
	//player picked up an item
	void AddPickUpEvent( Man player, EntityAI taken_item )
	{
		if ( player.GetIdentity() == null ) { return; }
		
		string characterId;
		string item;
		vector position;
		
		characterId = player.GetIdentity().GetId();
		item = taken_item.GetType();
		position = player.GetPosition();				

		//send
		Analytics.AddPickUpEvent( characterId, item, position );
	}
	
	//player consumed food item
	void AddFoodConsumeEvent( Man player, EntityAI food_item )
	{
		if ( player.GetIdentity() == null ) { return; }
		
		string characterId;
		string consumable;
		vector position;
		
		characterId = player.GetIdentity().GetId();
		consumable = food_item.GetType();
		position = player.GetPosition();

		//send
		Analytics.AddFoodConsumeEvent( characterId, consumable, position );
	}
}