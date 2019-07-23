class SgUiContActionPanel extends SgUiHudPanel
{
	// Widgets
	private TextWidget 	m_CountDownLabel;
	
	void SgUiContActionPanel(Widget root)
	{
		BuildLayout(root);
	}

	// ---------------------------------------------
	// OVERRIDES
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_hud/sg_continous_action_panel.layout";
	}
	
	// Find all usable widgets
	override protected void FindAllWidgets()
	{
		m_CountDownLabel = TextWidget.Cast(super.GetRootFrame().FindWidget("CountDownLabel"));
	}
	
	override protected void LoadAllWidgets();
	
	// Register all events used in this class
	override protected void RegisterAllEvents()
	{
		ActionManagerClient.Event_OnContActionStart.Insert(ShowCountDownLabel);			// Action Start
		ActionManagerClient.Event_OnContActionEnd.Insert(HideCountDownLabel);			// Action End	 		
		CAContinuousTime.Event_OnContActionTic.Insert(SetCountDown);					// Action in progress
		CAContinuousRepeat.Event_OnContActionTic.Insert(SetCountDown);					// Action in progress
		CAContinuousQuantityRepeat.Event_OnContActionTic.Insert(SetCountDown);			// Action in progress
		CAContinuousCraft.Event_OnContActionTic.Insert(SetCountDown);					// Action in progress
	}
	// UnRegister all events used in this class
	override protected void UnRegisterAllEvents()
	{
		ActionManagerClient.Event_OnContActionStart.Remove(ShowCountDownLabel);			// Action Start
		ActionManagerClient.Event_OnContActionEnd.Remove(HideCountDownLabel);			// Action End	 		
		CAContinuousTime.Event_OnContActionTic.Remove(SetCountDown);					// Action in progress
		CAContinuousRepeat.Event_OnContActionTic.Remove(SetCountDown);					// Action in progress
		CAContinuousQuantityRepeat.Event_OnContActionTic.Remove(SetCountDown);			// Action in progress
		CAContinuousCraft.Event_OnContActionTic.Remove(SetCountDown);					// Action in progress
	}
	
	// Manage count down label text 
	private void SetCountDown(float remaining_time)
	{
		if(remaining_time >= 0.1)
		{	
			string label_text;
			
			// Round to 1 decimal point
			float rounded_time = Math.Round(remaining_time * 10) / 10; 
		
			// Text formatting
			if(rounded_time == Math.Round(remaining_time))		// If the time ends on real number 
			{
				label_text = rounded_time.ToString() + ".0";		// Add '.0'  behind the number 
			}
			else 												// Otherwise keep the number as it is
			{
				label_text = rounded_time.ToString();
			}
			
			// Update Label with the new number
			m_CountDownLabel.SetText(label_text);				
		}	
		else
		{
			HideCountDownLabel();
		}
	}
	
	// Show text for count down label 
	private void ShowCountDownLabel()
	{		
		if(m_CountDownLabel)
		{
			m_CountDownLabel.Show(true);
		}
	}
	
	// Hide and reset text for count down label
	private void HideCountDownLabel()
	{
		if(m_CountDownLabel)
		{
			m_CountDownLabel.SetText("");
			m_CountDownLabel.Show(false);
		}
	}
}