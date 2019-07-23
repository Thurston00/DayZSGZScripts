modded class Edible_Base
{
	float GetPercentageHeal()
	{
		string class_path = "cfgVehicles " + GetType() + " Medical";
		return GetGame().ConfigGetFloat( class_path + " percentageHeal" );			
	}
}