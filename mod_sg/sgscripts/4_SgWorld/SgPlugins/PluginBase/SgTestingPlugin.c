class SgTestingPluginOld
{
	
	void TestFunction()
	{
		GetGame().SelectSpectator( GetGame().GetPlayer().GetIdentity(), "SgCasterCamera", GetGame().GetPlayer().GetPosition() );
	}
	
	void SaveStaticCamera0()
	{
		//SgSResourceHandler.SaveStaticCamera( 0 );
	}
	
	void SaveStaticCamera1()
	{
		//SgSResourceHandler.SaveStaticCamera( 1 );
	}
	
	void SaveStaticCamera2()
	{
		//SgSResourceHandler.SaveStaticCamera( 2 );
	}
	
	void LoadStaticCamera0()
	{
		//SgSResourceHandler.LoadStaticCamera( 0 );
	}
	
	void LoadStaticCamera1()
	{
		//SgSResourceHandler.LoadStaticCamera( 1 );
	}
	
	void LoadStaticCamera2()
	{
		//SgSResourceHandler.LoadStaticCamera( 2 );
	}
	
	void ExitMenu()
	{
		GetGame().GetUIManager().Back();
	}
}
