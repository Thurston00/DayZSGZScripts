class SgDebug
{
	private static bool m_IsLogOn 	= false;
	private static bool m_IsDebugOn = true;
	private static bool m_IsErrorOn = true;
	
	// LOG messages
	static 			const string L_CONSTRUCTOR  	= "<constructed>";
	static			const string L_MODULES_START 	= "<Load modules>";
	static			const string L_MODULES_END 		= "</Load modules>";
	// ERROR messages
	static 			const string E_NOT_FOUND_ROOT 	= "Root layout could not be found";
	static 			const string E_NOT_OVERRIDEN	= "This method should be overriden";
	
	private static	const string DEBUG 	= "DEBUG";
	private static 	const string LOG 	= "LOG";
	private static 	const string ERROR 	= "ERROR";
	
	static void Debug(string message, string class_name, string method_name = "")
	{	
		if(m_IsDebugOn)
		{
			Print(string.Format("%1:\t%2 --> %3 --> %4" , DEBUG, class_name + GetTabs(class_name), method_name + GetTabs(method_name), message ));	
		}
	}
	
	static void Error(string message, string class_name, string method_name = "")
	{	
		if(m_IsErrorOn)
		{
			Print(string.Format("%1:\t%2 --> %3 --> %4" , ERROR, class_name + GetTabs(class_name), method_name + GetTabs(method_name), message ));	
		}
	}
	
	static void Log(string message, string class_name, string method_name = "")
	{	
		if(m_IsLogOn)
		{
			Print(string.Format("%1:\t%2 --> %3 --> %4" , LOG , class_name + GetTabs(class_name), method_name + GetTabs(method_name), message ));	
		}
	}
	
	private static string GetTabs(string text)
	{
		if (text.Length() == 0)
		{
			return "";
		}
		else if (text.Length() <= 13)
		{
			return "\t\t";
		}
		else if (text.Length() > 13 && text.Length() < 16)
		{
			return "\t\t";
		}
		return ""; 
	}
}