modded class Analytics
{
	// disabled DZ analytics events
	override static void PlayerDeath(StatsEventDeathData data) {}
	override static void PlayerScoredKill(StatsEventScoredKillData data) {}
	override static void PlayerDisconnected(StatsEventDisconnectedData data) {}
	override static void PlayerMeasures(StatsEventMeasuresData data) {}
	override static void PlayerSpawned(StatsEventSpawnedData data) {}

	static void SendMatchStartEvent(string matchId, int playerCount)
	{
		m_MatchId = matchId;
		
		StatsEventData data = new StatsEventData("matchStart");//TODO: do without allocation ?
		data.AddString("id_match", m_MatchId);
		data.AddInt("player_count", playerCount);
		ScriptAnalytics.SendEvent(data);
	}
	
	static void SendMatchEndEvent()
	{
		StatsEventData data = new StatsEventData("matchEnd");//TODO: do without allocation ?
		data.AddString("id_match", m_MatchId);
		ScriptAnalytics.SendEvent(data);
		
		m_MatchId = "undefined";
		m_PhaseNumber = 0;
		m_TransitionNumber = 0;
		m_ShotCount = 0;
		m_ShotHitCount = 0;
		m_MeleeCount = 0;
		m_MeleeHitCount = 0;
		m_PickupCount = 0;
		m_FoodConsumeCount = 0;
	}
	
	static void SendPhaseStartEvent(int number)
	{
		m_PhaseNumber = number;
		
		StatsEventData data = new StatsEventData("phaseStart");//TODO: do without allocation ?
		data.AddString("id_match", m_MatchId);
		data.AddInt("number", m_PhaseNumber);
		ScriptAnalytics.SendEvent(data);
	}
	
	static void SendPhaseEndEvent()
	{
		StatsEventData data = new StatsEventData("phaseEnd");//TODO: do without allocation ?
		data.AddString("id_match", m_MatchId);
		data.AddInt("number", m_PhaseNumber);
		data.AddInt("shot_count", m_ShotCount);
		data.AddInt("shot_hit_count", m_ShotHitCount);
		data.AddInt("melee_count", m_MeleeCount);
		data.AddInt("melee_hit_count", m_MeleeHitCount);
		data.AddInt("pickup_count", m_PickupCount);
		data.AddInt("food_consume_count", m_FoodConsumeCount);
		ScriptAnalytics.SendEvent(data);
		
		m_ShotCount = 0;
		m_ShotHitCount = 0;
		m_MeleeCount = 0;
		m_MeleeHitCount = 0;
		m_PickupCount = 0;
		m_FoodConsumeCount = 0;
	}
	
	static void SendTransitionStartEvent(int number)
	{
		m_TransitionNumber = number;
		
		StatsEventData data = new StatsEventData("transitionStart");//TODO: do without allocation ?
		data.AddString("id_match", m_MatchId);
		data.AddInt("number", m_TransitionNumber);
		ScriptAnalytics.SendEvent(data);
	}
	
	static void SendTransitionEndEvent()
	{
		StatsEventData data = new StatsEventData("transitionEnd");//TODO: do without allocation ?
		data.AddString("id_match", m_MatchId);
		data.AddInt("number", m_PhaseNumber);
		data.AddInt("shot_count", m_ShotCount);
		data.AddInt("shot_hit_count", m_ShotHitCount);
		data.AddInt("melee_count", m_MeleeCount);
		data.AddInt("melee_hit_count", m_MeleeHitCount);
		data.AddInt("pickup_count", m_PickupCount);
		data.AddInt("food_consume_count", m_FoodConsumeCount);
		ScriptAnalytics.SendEvent(data);
		
		m_ShotCount = 0;
		m_ShotHitCount = 0;
		m_MeleeCount = 0;
		m_MeleeHitCount = 0;
		m_PickupCount = 0;
		m_FoodConsumeCount = 0;
	}
	
	static void SendUnconsciousnessEvent(string characterId, ESgDeathReason cause, vector position, string attackerId, string weapon, vector attackerPosition)
	{
		StatsEventData data = new StatsEventData("characterUnconsciousness");//TODO: do without allocation ?
		data.AddString("id_match", m_MatchId);
		
		switch (cause)
		{
			case ESgDeathReason.Player:
				data.AddString("cause", "player");
				break;
			case ESgDeathReason.Fall:
				data.AddString("cause", "fall");
				break;
			case ESgDeathReason.Collar:
				data.AddString("cause", "collar");
				break;
			default:
				data.AddString("cause", "other");
		}
		
		data.AddVector("position", position);
		data.AddString("weapon", weapon);
		data.AddVector("attacker_position", attackerPosition);
		ScriptAnalytics.SendEvent(data);
	}
	
	static void SendResurrectEvent(string characterId, vector position, string teammateId)
	{
		StatsEventData data = new StatsEventData("characterResurrect");//TODO: do without allocation ?
		data.AddString("id_match", m_MatchId);
		data.AddVector("position", position);
		ScriptAnalytics.SendEvent(data);
	}
	
	static void SendDeathEvent(string characterId, ESgDeathReason cause, vector position, string attackerId, string weapon, vector attackerPosition)
	{
		StatsEventData data = new StatsEventData("characterDeath");//TODO: do without allocation ?
		data.AddString("id_match", m_MatchId);
		
		switch (cause)
		{
			case ESgDeathReason.Player:
				data.AddString("cause", "player");
				break;
			case ESgDeathReason.Fall:
				data.AddString("cause", "fall");
				break;
			case ESgDeathReason.Collar:
				data.AddString("cause", "collar");
				break;
			default:
				data.AddString("cause", "other");
		}
		
		data.AddVector("position", position);
		data.AddString("weapon", weapon);
		data.AddVector("attacker_position", attackerPosition);
		ScriptAnalytics.SendEvent(data);
	}
	
	
	static void AddShotEvent(string characterId, string weapon, vector position)
	{
		m_ShotCount++;
	}
	
	static void AddHitEvent(string characterId, string weapon, vector position)
	{
		m_ShotHitCount++;
	}
	
	static void AddMeleeEvent(string characterId, string weapon, vector position)
	{
		m_MeleeCount++;
	}
	
	static void AddMeleeHitEvent(string characterId, string weapon, vector position)
	{
		m_MeleeHitCount++;
	}
	
	static void AddPickUpEvent(string characterId, string item, vector position)
	{
		m_PickupCount++;
	}
	
	static void AddFoodConsumeEvent(string characterId, string consumable, vector position)
	{
		m_FoodConsumeCount++;
	}
	
	
	private static string 	m_MatchId = "undefined";
	private static int 		m_PhaseNumber = 0;
	private static int 		m_TransitionNumber = 0;
	
	private static int 		m_ShotCount = 0;
	private static int 		m_ShotHitCount = 0;
	private static int 		m_MeleeCount = 0;
	private static int 		m_MeleeHitCount = 0;
	private static int 		m_PickupCount = 0;
	private static int 		m_FoodConsumeCount = 0;
}