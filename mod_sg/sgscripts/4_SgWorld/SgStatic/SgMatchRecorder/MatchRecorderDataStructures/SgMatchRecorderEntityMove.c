// Moving Entry for entity. Everysecond entry.
class SgMatchRecorderEntityMove
{
	protected float 					time; 		// SG_TODO: m_Time
	protected Vector2	 				position; 	// SG_TODO: m_Position
	protected Vector2	 				direction; 	// SG_TODO: m_Direction
	
	void SgMatchRecorderEntityMove(float time, Vector2 position, Vector2 direction)
	{
		this.time 		= time;
		this.position 	= position;
		this.direction 	= direction;
	}
}