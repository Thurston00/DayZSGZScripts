class SgDeadcam : Camera
{
	static SgPlayerClient	m_TargetPlayer;
	protected float			m_LastPostFrameTickTime;
	
	protected float			m_SendUpdateAcc = 0.0;
	protected float			m_TimeDeadView = 5;
	
	//========================================
	// Constructor
	//========================================
	void SgDeadcam()
	{
		SgSClientGame.SetDeadcam( this );
		
		SetTarget( SgSClientGame.GetPlayer() );
		
		SetEventMask(EntityEvent.POSTFRAME);
		
		GetGame().GetUIManager().ScreenFadeIn(3, "You are dead", FadeColors.BLACK, FadeColors.WHITE);
		
		m_LastPostFrameTickTime = GetGame().GetTime();
	}
	
	//========================================
	// CleanUp
	//========================================
	static void CleanUp()
	{
		m_TargetPlayer = null;
	}
	
	//========================================
	// EOnPostFrame
	//========================================
	override void EOnPostFrame(IEntity other, int extra)
	{
		float delta_time = (GetGame().GetTime() - m_LastPostFrameTickTime) / 1000;
		m_LastPostFrameTickTime = GetGame().GetTime();
		
		if ( m_TargetPlayer.GetPlayerBase() )
		{
			vector new_pos;
			vector new_orient;
						
			PlayerBase ply = m_TargetPlayer.GetPlayerBase();
			int bone_index = ply.GetBoneIndexByName("Face_BrowMiddle");
			if (bone_index != -1)
			{
				//move the camera a bit so the helms do not go into the way
				new_pos = ply.CoordToParent( ply.GetBonePositionMS(bone_index) + "0.1 0.1 0.1" );
				
				float bone_rot[4];
				ply.GetBoneRotationWS( bone_index, bone_rot );
				
				new_orient = Math3D.QuatToAngles(bone_rot);
				
				new_orient[0] = new_orient[0] - 90;
				new_orient[1] = new_orient[2] + 95;
				new_orient[2] = 0;
				
				vector bone_tran[4];
				ply.GetBoneTransformWS( bone_index, bone_tran );
			}
			else
			{
				new_pos = m_TargetPlayer.GetPosition();
				new_pos[1] = new_pos[1] + 1.8;
			}
			
			//vector ply_dir = m_TargetPlayer.GetDirection();
			//vector ply_dir_left = Vector( -ply_dir[2], ply_dir[1], ply_dir[0] );
			//vector ply_dir_up = Vector( ply_dir[0], -ply_dir[2], ply_dir[1] );
			// Right offset
			//new_pos -= ply_dir_left * 0.25;
			// Up offset
			//new_pos -= ply_dir_up * -0.0;
			// Back offset
			//new_pos += -ply_dir * -0.0;
			//new_pos += -ply_dir * 1;
			// Height offet
			//new_pos[1] = new_pos[1] + 1.7;
			
			SetPosition(new_pos);
			SetOrientation(new_orient);		
			
	
			if( m_SendUpdateAcc > 1.0 )
			{
				GetGame().UpdateSpectatorPosition(new_pos);
				m_SendUpdateAcc = 0;
			}
			
			m_SendUpdateAcc = m_SendUpdateAcc + delta_time;
			
			
			if ( m_TimeDeadView > 0 )
			{
				m_TimeDeadView -= delta_time;
				
				if ( m_TimeDeadView <= 0 )
				{
					m_TimeDeadView = -1;
					
					OnDeadFinished();
				}			
			}			
		}
	}
	
	//========================================
	// OnDeadFinished
	//========================================
	void OnDeadFinished()
	{
		SgPlayerClient teammate = SgSClientGame.GetRandomAliveTeammate();
		
		if ( teammate )
		{
			SetTarget( teammate );
			return
		}
		
		
		array<ref SgPlayerClient> players = SgSClientGame.GetPlayers();
		for ( int i = 0; i < players.Count(); ++i )
		{
			if ( players[i].GetPlayerUID() != SgSClientGame.GetPlayer().GetPlayerUID() )
			{
				SetTarget( players[i] );
				return;
			}
		}
	}
	
	//========================================
	// SetTarget
	//========================================
	static void SetTarget( SgPlayerClient player )
	{
		m_TargetPlayer = player;
	}
	
	//========================================
	// GetTarget
	//========================================
	static SgPlayerClient GetTarget()
	{
		return m_TargetPlayer;
	}
	
	void Event_OnSgPlayerKilled()
	{
	
	}
}