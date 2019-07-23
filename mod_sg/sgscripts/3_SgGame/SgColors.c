modded class Colors
{
	static int team_color_1		= 0xFF31A2F2;
	static int team_color_2		= 0xFF9D9D9D;
	static int team_color_3		= 0xFF005784;
	static int team_color_4		= 0xFFBE2633;
	static int team_color_5		= 0xFFE06F8B;
	static int team_color_6		= 0xFFA3CE27;
	static int team_color_7		= 0xFFA46422;
	static int team_color_8		= 0xFFEB8931;
	static int team_color_9		= 0xFFF7E26B;
	static int team_color_10	= 0xFF2F484E;
	static int team_color_11	= 0xFF44891A;
	static int team_color_12	= 0xFF493C2B;
	static int team_color_13	= 0xFF1B2632;
	static int team_color_14	= 0xFFB2DCEF;
	static int team_color_15	= 0xFFE6194B;
	static int team_color_16	= 0xFF000000;

	static int player_color_1	= 0xFFE6194B;
	static int player_color_2	= 0xFF3CB44B;
	static int player_color_3	= 0xFFFFE119;
	static int player_color_4	= 0xFF0082C8;

	// Get a colour hex value based on team slot
	static int GetTeamColor( int id )
	{
		int colour;
		switch(id)
		{
			case 0:
				colour = team_color_1;
			break;
			case 1:
				colour = team_color_2;
			break;
			case 2:
				colour = team_color_3;
			break;
			case 3:
				colour = team_color_4;
			break;
			case 4:
				colour = team_color_5;
			break;
			case 5:
				colour = team_color_6;
			break;
			case 6:
				colour = team_color_7;
			break;
			case 7:
				colour = team_color_8;
			break;
			case 8:
				colour = team_color_9;
			break;
			case 9:
				colour = team_color_10;
			break;
			case 10:
				colour = team_color_11;
			break;
			case 11:
				colour = team_color_12;
			break;
			case 12:
				colour = team_color_13;
			break;
			case 13:
				colour = team_color_14;
			break;
			case 14:
				colour = team_color_15;
			break;
			case 15:
				colour = team_color_16;
			break;
			default:
			{
				colour = GetTeamColor( id % 16);
				break;
			}
		}
		return colour;
	}

	// Get a colour hex value based on teammate slot
	static int GetPlayerColorByTeamSlot( int id )
	{
		int colour;
		switch(id)
		{
			case 0:
				colour = player_color_1;
			break;
			case 1:
				colour = player_color_2;
			break;
			case 2:
				colour = player_color_3;
			break;
			case 3:
				colour = player_color_4;
			break;
			// Error
			default:
			{
				Print("ERROR: SgColors -> GetPlayerColor -> Teammate ID could not be linked to a colour");
				colour = 0;
				break;
			}
		}
		return colour;	
	}
}
