modded class PluginConfigDebugProfile
{
	protected const string DEFAULT_PLAYGROUND	= "default_playground";
	
	void PluginConfigDebugProfile()
	{
		m_DefaultValues.Insert( DEFAULT_PLAYGROUND, GetNewCfgParamInt( -1 ) );
	}
	
	void SetDefaultPlayground( int id )
	{
		SetInt( DEFAULT_PLAYGROUND, id );
	}
	
	int GetDefaultPlayground()
	{
		return GetInt( DEFAULT_PLAYGROUND );
	}
}