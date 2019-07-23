class SgSMatchRecorderSerializer<Class T>
{
	static protected ref JsonSerializer 		m_JS = new JsonSerializer();
	
	//--------------------------------------------
	// SaveMatchRecorderEntry
	//--------------------------------------------
	static void SaveMatchRecorderEntry(T objToSerialize, SgMatchRecorderFileHandler fileHandlerWrapper)
	{
		if ( !GetGame().IsMultiplayer() ) { return; }
		
		string jsonContent;
		
		if ( m_JS.WriteToString(objToSerialize, false, jsonContent) )
		{
			if ( fileHandlerWrapper.m_fileHandle != 0)
			{
				FPrintln(fileHandlerWrapper.m_fileHandle, jsonContent);
			}
			else
			{
				Print("[MatchRecorder Save Error] Cannot Open JSON File(.sgz)");
			}
		}
		else
		{
			Print("[MatchRecorder Save Error] Cannot parse " + objToSerialize.ClassName() + "to JSON");
		}
	}
}