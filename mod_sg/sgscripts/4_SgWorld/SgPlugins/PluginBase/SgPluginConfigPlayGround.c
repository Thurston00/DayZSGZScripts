class SgPluginConfigPlayground extends PluginConfigHandler
{
	protected static const	string PARAM_PLAYGROUND				= "play_ground_";
	protected static const	string PARAM_PLAYGROUND_ID			= "id";
	protected static const	string PARAM_PLAYGROUND_PLAYERS		= "max_players";
	protected static const	string PARAM_PLAYGROUND_NAME		= "name";
	protected static const	string PARAM_PLAYGROUND_DESCRIPTION	= "description";
	protected static const	string PARAM_PLAYGROUND_DETAILS		= "details";
	protected static const	string PARAM_PLAYGROUND_IMAGE		= "image";
	protected static const	string PARAM_PLAYGROUND_MAP			= "map";
	
	protected static const	string PARAM_PHASE					= "phase_";
	protected static const	string PARAM_PHASE_TIME				= "phase_time";	
	protected static const	string PARAM_PHASE_TRANSITION_TIME	= "transition_time";
	
	protected static const	string PARAM_LOOT_MULTIPLIER		= "multiplier";
	protected static const	string PARAM_LOOT_RATIOS			= "ratios";
	protected static const	string PARAM_LOOT_COUNTS			= "counts";
	
	protected static const	string FOLDER_ROOT					= "mod_sg/SgPlaygrounds";
	protected static const	string FOLDER_PLAYGROUND			= FOLDER_ROOT + "/SgPlayground_";
	protected static const	string FOLDER_PHASE					= "/SgPhase_";
	protected static const	string FILENAME_PLAYGROUNDS			= "/SgPlaygrounds.sg";
	protected static const	string FILENAME_PHASES				= "/SgPhases.sg";
	protected static const	string FILENAME_LOOT				= "/SgLoot.sg";
	protected static const	string FILENAME_SCENE				= "/SgScene.sg";
	
	protected static const	string MISSION_ROOT					= "mod_sg/SgEditor/SgMissions";
	protected static const	string MISSION_LIST					= "/SgMissions.sg";
	
	protected				string m_FileSceneName;
	
	//========================================
	// GetInstance
	//========================================
	static SgPluginConfigPlayground GetInstance()
	{
		return SgPluginConfigPlayground.Cast( GetPlugin( SgPluginConfigPlayground ) );
	}
	
	//========================================
	// OnInit
	//========================================
	override void OnInit()
	{
		super.OnInit();
	}
	
	//========================================
	// GetFileName
	//========================================
	override string GetFileName()
	{
		return m_FileSceneName;
	}
	
	array<string> GetMissionNames()
	{
		m_FileSceneName = MISSION_ROOT + MISSION_LIST;
		LoadConfigFile();
		array<ref CfgParam> params	= GetAllParams();
		
		ref array<string> missions = new array<string>;
		
		for ( int i = 0; i < params.Count(); ++i )
		{
			CfgParamString mission = CfgParamString.Cast( GetParamByName( "Mission_" + i, CFG_TYPE_STRING ) );
			missions.Insert( mission.GetValue() );
		}
		
		return missions;
	}
	
	
}