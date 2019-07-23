class SgActionDeactivateCollarCB : ActionContinuousBaseCB
{
	private const float TIME_TO_COMPLETE = 4;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(TIME_TO_COMPLETE);
	}
};

class SgActionDeactivateCollar : ActionContinuousBase
{
	void SgActionDeactivateCollar() 
	{
		m_CallbackClass = SgActionDeactivateCollarCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
	}
	
	override string GetText() //text game displays in HUD hint 
	{
		return "Deactivate collars";
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		Object target_object = target.GetObject();
		SG_StaticCollarDeactivator deactivator_target = SG_StaticCollarDeactivator.Cast( target_object );
		
		if( deactivator_target )
		{
			// Server & Client
			return deactivator_target.CanPlayerInteract( player );
		}
		return false;
	}

	override void OnStartClient(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(true);
	}
	
	override void OnStartServer(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(true);
	}
	
	override void OnFinishProgressServer( ActionData action_data ) //method called on succesful finishing of action (after out animation)
	{
		SgSManagerEventsServer.Event_OnSgPlayerCollarDeactivated( action_data.m_Player.GetSgPlayer() );
	}

	override void OnEndClient(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(false);
	}
	
	override void OnEndServer( ActionData action_data )
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(false);
	}
};