class SG_StaticAntenna extends SG_Static
{
	protected int m_ID;
	
	void SG_StaticAntenna()
	{
		SetEventMask(EntityEvent.INIT);
	}
	
	override void EOnInit(IEntity other, int extra)
	{
		SetOrientation(Vector(0,0,0));
	}
	

//--------------------------------------------------------------	
//--------------------------------------------------------------
// Protected
//--------------------------------------------------------------
//--------------------------------------------------------------
	/*
	protected const string 	MAT_LIGHT_OFF		= "sg\\entities\\static\\data\\light_off.rvmat";
	protected const string 	MAT_LIGHT_GREEN		= "sg\\entities\\static\\data\\light_green.rvmat";
	protected const string 	MAT_LIGHT_RED		= "sg\\entities\\static\\data\\light_red.rvmat";
	protected const string 	MAT_LIGHT_ORANGE	= "sg\\entities\\static\\data\\light_orange.rvmat";	
	*/
	
	
	//protected const string 	MAT_LIGHT_OFF		= "sg\\entities\\static\\data\\sg_light_beam_white_on.rvmat";
	//protected const string 	MAT_LIGHT_RED		= "sg\\entities\\static\\data\\sg_light_beam_red_on.rvmat";
	protected const string 	MAT_LIGHT_GREEN		= "sg\\entities\\static\\data\\sg_light_beam_green_on.rvmat";
	protected const string 	MAT_LIGHT_ORANGE	= "sg\\entities\\static\\data\\sg_light_beam_yellow_on.rvmat";	
	
	
	protected const string 	MAT_LIGHT_OFF		= "";
	protected const string 	MAT_LIGHT_RED		= "";

	//---------------------------------------
	// UpdatePhaseLight
	//---------------------------------------
	protected void UpdatePhaseLight()
	{
		/*
		if ( m_PhaseState == EPhase.Off )
		{
			SetObjectMaterial( 0, MAT_LIGHT_OFF );
		}
		else if ( m_PhaseState == EPhase.Active )
		{
			SetObjectMaterial( 0, MAT_LIGHT_GREEN );
		}
		else if ( m_PhaseState == EPhase.Deactive )
		{
			SetObjectMaterial( 0, MAT_LIGHT_RED );
		}
		else if ( m_PhaseState == EPhase.Transition )
		{
			SetObjectMaterial( 0, MAT_LIGHT_ORANGE );
		}
		*/
	}
}