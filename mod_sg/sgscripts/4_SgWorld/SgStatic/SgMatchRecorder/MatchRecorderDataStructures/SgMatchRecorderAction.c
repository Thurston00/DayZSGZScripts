// Actions wrapper
class SgMatchRecorderAction<Class T>
{
	protected float 					time; 		// SG_TODO: m_Time
	protected int	 					actionType; // SG_TODO: m_ActionType
	protected ref T						jsnObjData; // SG_TODO: m_JsnObjData
	
	void SgMatchRecorderAction(float time, int actionType, T jsnObjData)
	{
		this.time 		= time;
		this.actionType = actionType;
		this.jsnObjData = jsnObjData;
	}
}