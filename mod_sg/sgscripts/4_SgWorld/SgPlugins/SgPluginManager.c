modded class PluginManager
{	
	//=================================
	// Init
	//=================================
	override void Init()
	{
		super.Init();
		
		UnregisterPlugin( "PluginSceneManager" );
		UnregisterPlugin( "PluginConfigScene" );
		
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------------------------------
		//				Module Class Name 				Client	Server	Release(false = Only In Debug )
		//----------------------------------------------------------------------------------------------
		RegisterPlugin( "SgPluginGameServer",			false, 	true, 	true );
		RegisterPlugin( "SgPluginConfigPlayground",		false, 	true, 	true );
		RegisterPlugin( "SgPluginSpawns",				false, 	true, 	true );
		RegisterPlugin( "SgPluginGameLog",				true, 	true, 	true );
		RegisterPlugin( "SgPluginCasterManager",		true,	true,	true );
		
#ifdef DEVELOPER
		// SG Editors
		string editor;
		if ( GetGame().CommandlineGetParam("sgEditor", editor))
		{
			RegisterPluginDebug( "SgPluginEditorLoot",		true, 	false );
			RegisterPluginDebug( "SgPluginPgEditor",		true, 	false );
		}
#endif
		
		GetGame().GetUpdateQueue(CALL_CATEGORY_GAMEPLAY).Insert(this.MainOnUpdate);
	}	
}
