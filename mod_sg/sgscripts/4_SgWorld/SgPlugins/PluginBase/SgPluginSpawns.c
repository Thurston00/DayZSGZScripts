class SgPluginSpawns extends PluginBase
{
	//==================================
	// GetInstance
	//==================================
	static SgPluginSpawns GetInstance()
	{
		return SgPluginSpawns.Cast( GetPlugin( SgPluginSpawns ) );
	}	
}