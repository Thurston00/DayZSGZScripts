class SgUiButtonRefresh extends SgUiButtonImage
{		
	// Button Animation
	private 		int 		m_RotationValue = 0;
	private const 	int 		m_RotationRefreshRate = 1;	

	// ------------------------------------------
	// Animations
	
	void StartButtonAnimation()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(WaitingAnimation);
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(WaitingAnimation, m_RotationRefreshRate ,true, m_RotationValue);
	}
	
	void StopButtonAnimation()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(WaitingAnimation);
	}
	
	private void WaitingAnimation()
	{
		m_RotationValue -= 3;
		// Set rotation
		m_UiImage.SetRotation( 0, 0, m_RotationValue);
		// Check if rotation is complete
		if (m_RotationValue <= 0){m_RotationValue = 360;}
	}
}