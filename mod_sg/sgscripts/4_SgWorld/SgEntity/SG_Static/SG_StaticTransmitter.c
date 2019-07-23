class SG_StaticTransmitter extends SG_Static
{	
	protected const string 			MAT_LIGHT_OFF		= "sg\\entities\\static\\data\\light_off.rvmat";
	protected const string 			MAT_LIGHT_GREEN		= "sg\\entities\\static\\data\\light_green.rvmat";
	protected const string 			MAT_LIGHT_RED		= "sg\\entities\\static\\data\\light_red.rvmat";
	protected const string 			MAT_LIGHT_ORANGE	= "sg\\entities\\static\\data\\light_orange.rvmat";	
	

//--------------------------------------------------------------	
//--------------------------------------------------------------
// Private
//--------------------------------------------------------------
//--------------------------------------------------------------

	//---------------------------------------
	// UpdatePhaseLight
	//---------------------------------------
	private void UpdatePhaseLight()
	{
		/*
		if ( IsAreaOff() )
		{
			SetObjectMaterial( 0, MAT_LIGHT_OFF );
		}
		else if ( IsAreaActive() )
		{
			SetObjectMaterial( 0, MAT_LIGHT_GREEN );
		}
		else if ( IsAreaDeactive() )
		{
			SetObjectMaterial( 0, MAT_LIGHT_RED );
		}
		else if ( IsAreaTransition() )
		{
			SetObjectMaterial( 0, MAT_LIGHT_ORANGE );
		}
		*/
		
		/*
		for ( int i = 0; i < GetSceneObject().GetLinkedSceneObjectsCount(); ++i )
		{
			ref SceneObject linked_obj = GetSceneObject().GetLinkedSceneObject( i );
			if( linked_obj )
			{
				EntityAI linked_entity = linked_obj.GetObject();
	//Print("ObjectName => "+ linked_obj.GetName());
				if ( linked_entity != NULL && linked_entity.IsInherited( SG_StaticAntenna ) )
				{
					SG_StaticAntenna antenna = SG_StaticAntenna.Cast( linked_entity );
					antenna.PhaseSetState( m_AreaState );
				}
			}
		}
		*/
	}
}