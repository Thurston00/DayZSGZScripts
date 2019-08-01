modded class ModifiersManager
{	
	override void Init()
	{
		// DayZ Modifiers:
		AddModifier(new ImmuneSystemMdfr); // Used for BrainDiseaseMdfr
		AddModifier(new BrainDiseaseMdfr);
		AddModifier(new MorphineMdfr);
		
		// DayZ Modded Modifiers:
		AddModifier(new StomachMdfr);
		AddModifier(new VomitStuffedMdfr);
		AddModifier(new UnconsciousnessMdfr);		
		
		// SG Modifiers:
	}
}