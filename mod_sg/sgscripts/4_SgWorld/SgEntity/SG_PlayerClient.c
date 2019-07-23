modded class PlayerBaseClient
{
	private bool 		m_IsInitialized;

	void PlayerBaseClient()
	{
		if ( GetSgGame().IsClient() )
		{
			SgSClientGame.RegisterClientPlayer(this);
		}
	}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
// Server/Client
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------

	protected		bool						m_IsCollarOn = false;
	protected ref	ScriptedWidgetEventHandler	m_CurrentMenu;
	protected ref	Timer						m_GenericTimer;
	protected ref 	Hud 						m_SgHud;

	void SetHud(Hud hud)
	{
		m_SgHud = hud;
	}

	//===================================
	// EOnFrame
	//===================================
	override void EOnFrame(IEntity other, float timeSlice)
	{
		if ( !m_IsInitialized && GetIdentity() != null )
		{
			SgSSyncEvents.ClientEvent_OnPlayerBaseInitialized( this );

			m_IsInitialized = true;
		}

		if (m_SgHud)
		{
			m_SgHud.Update(timeSlice);
		}
	}

	//===================================
	// GetGenericTimer
	//===================================
	Timer GetGenericTimer()
	{
		if( !m_GenericTimer )
		{
			m_GenericTimer = new Timer(CALL_CATEGORY_SYSTEM);
		}
		return m_GenericTimer;
	}
}
