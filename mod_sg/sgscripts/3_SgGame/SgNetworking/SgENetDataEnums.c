// DESIGN_ID: 0001

/*
	SG enum for different Net Data request/respond results 
*/
enum SgEResult
{
	OK,
	ERROR
}

/*
	SG enum for different
*/
enum SgEAction
{
	OPEN,
	CLOSE
}

/*
	SG enum for different
*/
enum SgETarget
{
	TEAM
	CASTER
}

/*	
	SG enum for different game team size ( how many players are in a team)
*/
enum SgETeamSize
{
	CUSTOM,
	SOLO,
	DUO,
	SQUAD
}

/*
	SG enum for different game modes
*/
enum SgEGameMode
{
	NORMAL,
	RANKED,
	CUSTOM
}

/*
	SG enum for different types of kills (such as a headshot kill, collarshot kill etc..) 
*/
enum SgEKillType
{
	NORMAL,
	HEADSHOT,
	COLLARSHOT
}

enum SgERegion
{
	EU,
	AMERICAS
}