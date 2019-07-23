class SgUiItemActionsWidget extends ScriptedWidgetEventHandler
{
	protected PlayerBase 				m_Player;
	protected EntityAI 					m_EntityInHands;
	protected ActionBase				m_Interact;
	protected ActionBase				m_ContinuousInteract;
	protected ActionBase				m_Single;
	protected ActionBase				m_Continuous;
	protected ActionManagerClient	 	m_AM;

	protected int						m_InteractActionsNum;
	protected int						m_ContinuousInteractActionsNum;
	protected bool						m_QuantityEnabled;
	
	protected ref WidgetFadeTimer		m_FadeTimer;
	protected bool						m_Faded;

	protected Widget					m_Root;

	//! widget width
	protected float m_MaxWidthChild;
	protected float m_RootWidth;
	protected float m_RootHeight;
	
	void SgUiItemActionsWidget()
	{
		m_Interact				= null;
		m_ContinuousInteract 	= null;
		m_Single 				= null;
		m_Continuous 			= null;
		m_AM 					= null;

		m_FadeTimer 			= new WidgetFadeTimer;
		m_Faded 				= true;
		
		m_QuantityEnabled 		= true;

		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Insert(Update);
	}
	
	void ~SgUiItemActionsWidget()
	{
		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Remove(Update);
	}

	protected void OnWidgetScriptInit(Widget w)
	{
		m_Root = w;
		m_Root.SetHandler(this);
		m_Root.Show(false);		
	}

	protected void BuildCursor()
	{	
		SetInteractActionIcon("ia_interact", "ia_interact_icon_frame", "ia_interact_btn_inner_icon", "ia_interact_btn_text");
		SetActionWidget(m_Interact, GetActionDesc(m_Interact), "ia_interact", "ia_interact_action_name");

		SetInteractActionIcon("ia_continuous_interact", "ia_continuous_interact_icon_frame", "ia_continuous_interact_btn_inner_icon", "ia_continuous_interact_btn_text");
		SetActionWidget(m_ContinuousInteract, GetActionDesc(m_ContinuousInteract), "ia_continuous_interact", "ia_continuous_interact_action_name");

		SetActionWidget(m_Single, GetActionDesc(m_Single), "ia_single", "ia_single_action_name");
		SetActionWidget(m_Continuous, GetActionDesc(m_Continuous), "ia_continuous", "ia_continuous_action_name");
		SetMultipleInteractAction("ia_interact_mlt_wrapper");
	}
		
	protected void Update()
	{
		//! don't show crosshair if it's disabled in profile
		if(!g_Game.GetProfileOption(EDayZProfilesOptions.HUD))
		{
			m_Root.Show(false);
			return;
		};

		if(m_Player && !m_Player.IsAlive()) // handle respawn
		{
			m_Player = null;
			m_AM = null;
		}
		if(!m_Player) GetPlayer();
		if(!m_AM) GetActionManager();

		GetEntityInHands();
		GetActions();

		if((m_EntityInHands || m_Interact || m_ContinuousInteract || m_Single || m_Continuous) && GetGame().GetUIManager().GetMenu() == null)
		{
			BuildCursor();
			m_Root.Show(true);
		}
		else
		{
			if (m_Root.IsVisible())
			{
				m_Root.Show(false);
			}
		}

		m_MaxWidthChild = 200;
	}

	// getters
    protected void GetPlayer()
	{
		Class.CastTo( m_Player, GetGame().GetPlayer() );
	}

	protected void GetActionManager()
	{
		if( m_Player && m_Player.IsPlayerSelected() )
			ActionManagerClient.CastTo( m_AM, m_Player.GetActionManager() );
		else
			m_AM = null;
	}

    protected void GetActions()
	{
		m_Interact = null;
		m_ContinuousInteract = null;
		m_Single = null;
		m_Continuous = null;

		if(!m_AM) return;
		if(!m_EntityInHands) return;
		if(m_Player.IsSprinting()) return;
		
		array<ActionBase> possible_interact_actions = m_AM.GetPossibleActions(InteractActionInput);
		int possible_interact_actions_index = m_AM.GetPossibleActionIndex(InteractActionInput);
		array<ActionBase> possible_continuous_interact_actions = m_AM.GetPossibleActions(ContinuousInteractActionInput);
		int possible_continuous_interact_actions_index = m_AM.GetPossibleActionIndex(ContinuousInteractActionInput);
		
		m_InteractActionsNum = possible_interact_actions.Count();
		if ( m_InteractActionsNum > 0 )
		{
			m_Interact = possible_interact_actions[possible_interact_actions_index];
		}
		
		m_ContinuousInteractActionsNum = possible_continuous_interact_actions.Count();
		if ( m_ContinuousInteractActionsNum > 0 )
		{
			m_ContinuousInteract = possible_continuous_interact_actions[possible_continuous_interact_actions_index];
		}
		
		m_Single = m_AM.GetPossibleAction(DefaultActionInput);
		m_Continuous = m_AM.GetPossibleAction(ContinuousDefaultActionInput);
	}

	protected void GetEntityInHands()
	{
		if(!m_Player) return;
		
		EntityAI eai = m_Player.GetHumanInventory().GetEntityInHands();
		
		if (eai && !eai.IsInherited(DummyItem))
		{
			m_EntityInHands = eai;
		}
		else
		{
			m_EntityInHands = null;
		}
	}
	
	protected string GetActionDesc(ActionBase action)
	{
		string desc = "";
		if (action && action.GetText())
		{
			desc = action.GetText();
			return desc;
		}
		return desc;
	}
		
	protected void SetActionWidget(ActionBase action, string descText, string actionWidget, string descWidget)
	{
		Widget widget;
		
		widget = m_Root.FindAnyWidget(actionWidget);

		if(action && (!action.HasTarget()))
		{
			TextWidget actionName;
			Class.CastTo(actionName, widget.FindAnyWidget(descWidget));
			

			if(action.GetInput().GetInputType() == ActionInputType.AIT_CONTINUOUS)
			{
				descText = descText + " " + "#action_target_cursor_hold";
				actionName.SetText(descText);
			}
			else
			{
				actionName.SetText(descText);
			}

			widget.Show(true);
		}
		else
		{
			widget.Show(false);
		}
	}

	//! shows arrows near the interact action if there are more than one available
	protected void SetMultipleInteractAction(string multiActionsWidget)
	{
		Widget widget;

		widget = m_Root.FindAnyWidget(multiActionsWidget);

		if(m_InteractActionsNum > 1)
			widget.Show(true);
		else
			widget.Show(false);
	}
	
	protected void SetInteractActionIcon(string actionWidget, string actionIconFrameWidget, string actionIconWidget, string actionIconTextWidget)
	{
		string keyName = string.Empty;
		Widget widget, frameWidget;
		ImageWidget iconWidget;
		TextWidget textWidget;
		
		widget = m_Root.FindAnyWidget(actionWidget);
		Class.CastTo(frameWidget, widget.FindAnyWidget(actionIconFrameWidget));
		Class.CastTo(iconWidget, widget.FindAnyWidget(actionIconWidget));
		Class.CastTo(textWidget, widget.FindAnyWidget(actionIconTextWidget));

		//! get name of key which is used for UAAction input 
		UAInput i1 = GetUApi().GetInputByName("UAAction"); 
		
		i1.SelectAlternative(0); //! select first alternative (which is the primary bind)
		for( int c = 0; c < i1.BindKeyCount(); c++ )
		{
		  	int _hc = i1.GetBindKey(0);
		  	keyName = GetUApi().GetButtonName(_hc);
		}

		// uses text in floating widget
		iconWidget.Show(false);
		textWidget.SetText(keyName);
#ifdef X1_TODO_TEMP_GUI
		textWidget.SetText("X");
#endif
		//frameWidget.Show(true);
		textWidget.Show(true);	
	}
}