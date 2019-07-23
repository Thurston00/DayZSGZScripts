enum ESgAIGroup
{
	Patrol,
	Guard,
	Static,
	Screamer
}

static string GetNameForAIGroup(ESgAIGroup sgAIGroup) // ? Maybe static class to wrap it?
{
	switch (sgAIGroup)
	{
		case ESgAIGroup.Patrol: 	return "Patrol";
		case ESgAIGroup.Guard:		return "Guard";
		case ESgAIGroup.Static:		return "Static";
		case ESgAIGroup.Screamer: 	return "Screamer";
	}
	
	return "-";
}

static ref array<ESgAIGroup> GetAllAIGroups() // ?
{
	ref array<ESgAIGroup> aiGroups = new ref array<ESgAIGroup>;
	
	aiGroups.Insert(ESgAIGroup.Patrol);
	aiGroups.Insert(ESgAIGroup.Guard);
	aiGroups.Insert(ESgAIGroup.Static);
	aiGroups.Insert(ESgAIGroup.Screamer);
	
	return aiGroups;
}