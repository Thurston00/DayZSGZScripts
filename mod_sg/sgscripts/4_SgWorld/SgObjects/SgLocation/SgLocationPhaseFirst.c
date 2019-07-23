class SgLocationPhaseFirst : SgLocationBordered
{		
	void SgLocationPhaseFirst()
	{
		m_OuterTextures = "phase1Textures";
		
		SgSManagerEventsServer.Event_OnGameTimeSecond.Insert(Event_OnGameTimeSecond);
	}
	
	//===============================
	// Activate
	//===============================
	override void Activate()
	{
		super.Activate();
		
		SetPhaseBorderLocked(true);
		
		//SgSManagerPlayers.GetSgPlayers()[0].Kill();
	}
	
	//===============================
	// Deactivate
	//===============================
	override void Deactivate()
	{
		super.Deactivate();
		
		SetPhaseBorderLocked(false);
	}
	
	//===============================
	// IsPhaseLocation
	//===============================
	override bool IsPhaseLocation()
	{
		return true;
	}
	
	//-------------------------------
	// Event_OnGameTimeSecond
	//-------------------------------
	protected void Event_OnGameTimeSecond( int time_left )
	{
		if ( IsPhaseBorderLocked() )
		{
			CheckPlayersBorderCross();
		}
	}	
}

