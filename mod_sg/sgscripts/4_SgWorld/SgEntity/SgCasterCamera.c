class SgCasterCamera : Camera
{
	protected ESgCasterCameraState	m_CameraState;
	protected SgPlayerClient		m_TargetPlayer;
	protected bool					m_CameraSet = true;
	
	protected float					m_CameraSpeed = 20.0;
	protected float					m_CameraMotorForward = 0;
	protected float					m_CameraMotorStrafe = 0;
	protected float					m_MinCameraSpeed = 1.0;
	protected float					m_SpeedMultiplier = 1.4;
	protected float					m_SendUpdateAcc = 0.0;
	
	protected float 				m_Pitch;
	protected float					m_AngleAroundFollowedObject;
	protected float					m_OrbitRadius = 3;
	protected float					m_MinOrbitRadius = 1;
	protected float					m_MaxOrbitRadius = 45;
	protected float					m_ZoomMultiplier = 1;
	protected float 				m_CameraRaycastHitDistance;
	protected bool					m_IsCameraRaycastHittingObject = true;
	
	protected float					m_LerpConst = 12;
	
	protected vector				m_LastPos;
	protected int					m_LastPostFrameTickTime;
	
	void SgCasterCamera()
	{		
		SetActive( true );
		
		SetEventMask(EntityEvent.POSTFRAME);

		SgSClientCaster.CasterSelect( this );
		m_CameraState = ESgCasterCameraState.Free;
		
		m_LastPostFrameTickTime = GetGame().GetTime();
		
		SgSClientCaster.Event_OnCasterTargetPlayerChanged.Insert( Event_OnCasterTargetPlayerChanged );
	}
	
	void Event_OnCasterTargetPlayerChanged( SgPlayerClient player )
	{
		m_TargetPlayer = player;
		
		if ( player )
		{
			if ( m_CameraState == ESgCasterCameraState.Free )
			{
				m_CameraState = ESgCasterCameraState.Snap;
			}			
			
			SetTarget( m_CameraState, player );
		}
		else
		{
			SetTarget( ESgCasterCameraState.Free, player );
		}
	}
	
	void SetCameraState( ESgCasterCameraState state )
	{
		m_CameraState = state;
	}
	
	ESgCasterCameraState GetCameraState()
	{
		return m_CameraState;
	}
		
	override void EOnPostFrame(IEntity other, int extra)
	{
		float timeSlice = (GetGame().GetTime() - m_LastPostFrameTickTime) / 1000;
		m_LastPostFrameTickTime = GetGame().GetTime();
		
		vector new_pos;
		vector new_orient;
		int bone_index;
		float bone_rot[4];
		vector bone_tran[4];
		PlayerBase player_base;
		new_pos = GetPosition();
		new_orient = GetOrientation();
		switch( m_CameraState )
		{
			case ESgCasterCameraState.Free:
			{
				new_pos = GetPosition();
				new_orient = GetOrientation();
				UpdatePosFromInputFree(new_pos, timeSlice);
				UpdateOrientFromInputFree(new_orient, timeSlice);
				SetPosition(new_pos);
				SetOrientation(new_orient);
				break;
			}
			case ESgCasterCameraState.Snap:
			{
				player_base = m_TargetPlayer.GetPlayerBase();
				
				if ( player_base )
				{
					UpdateFromInputOrbit( player_base, new_orient, new_pos, timeSlice);
				}
				else
				{
					new_pos = m_TargetPlayer.GetPosition();
				}
				
				SetPosition(new_pos);
				SetOrientation(new_orient);
				break;
			}
			case ESgCasterCameraState.ThirdPerson:
			{				
				if ( m_TargetPlayer.GetPlayerBase() )
				{
					player_base = m_TargetPlayer.GetPlayerBase();
					
					bone_index = player_base.GetBoneIndexByName("Face_BrowMiddle");
					if (bone_index != -1)
					{
						new_pos = player_base.GetBonePositionWS(bone_index);
						
						player_base.GetBoneRotationWS( bone_index, bone_rot );
						
						new_orient = Math3D.QuatToAngles(bone_rot);
						
						new_orient[0] = new_orient[0] - 90;
						new_orient[1] = new_orient[2] + 95;
						new_orient[2] = 0;
	
						player_base.GetBoneTransformWS( bone_index, bone_tran );
					}
					
					
					vector ply_dir = player_base.GetDirection();
					vector ply_dir_left = Vector( -ply_dir[2], ply_dir[1], ply_dir[0] );
					vector ply_dir_up = Vector( ply_dir[0], -ply_dir[2], ply_dir[1] );
					// Right offset
					new_pos -= ply_dir_left * 0.35;
					// Up offset
					new_pos += ply_dir_up * 1;
					// Back offset
					new_pos += -ply_dir * 2;
					//new_pos += -ply_dir * 1;
					// Height offet
					//new_pos[1] = new_pos[1] + 1.7;
				}
				else
				{
					new_pos = m_TargetPlayer.GetPosition();
				}
				
				SetPosition(new_pos);
				SetOrientation(new_orient);
				break;
			}
			case ESgCasterCameraState.FirstPerson:
			{
				m_TargetPlayer = SgSClientCaster.GetSelectedPlayer();
				player_base = m_TargetPlayer.GetPlayerBase();
				
				if ( player_base )
				{
					bone_index = player_base.GetBoneIndexByName("Face_BrowMiddle");
					if (bone_index != -1)
					{
						new_pos = player_base.GetBonePositionWS(bone_index);
						
						bone_rot[4];
						player_base.GetBoneRotationWS( bone_index, bone_rot );
						
						new_orient = Math3D.QuatToAngles(bone_rot);
						
						new_orient[0] = new_orient[0] - 90;
						new_orient[1] = new_orient[2] + 95;
						new_orient[2] = 0;
						
						player_base.GetBoneTransformWS( bone_index, bone_tran );
					}
				}
				else
				{
					new_pos = m_TargetPlayer.GetPosition();
				}
				
				SetPosition(new_pos);
				SetOrientation(new_orient);
				break;
			}
		}

		if( m_SendUpdateAcc > 1.0 )
		{
			GetGame().UpdateSpectatorPosition(new_pos);
			m_SendUpdateAcc = 0;
		}
		
		m_SendUpdateAcc = m_SendUpdateAcc + timeSlice;
	}
	
	void UpdatePosFromInputFree( out vector new_pos, float time_slice )
	{
		Input input = GetGame().GetInput();
		
		if (input.LocalRelease( "UANextAction" ))
		{
			m_CameraSpeed /= m_SpeedMultiplier;
		}

		if (input.LocalRelease( "UAPrevAction" ))
		{
			if( m_MinCameraSpeed < m_CameraSpeed )
			{
				m_CameraSpeed *= m_SpeedMultiplier;
			}
			else
			{
				m_CameraSpeed = m_MinCameraSpeed;
			}
		}
		
		float forward = input.LocalValue( "UAMoveForward" ) - input.LocalValue( "UAMoveBack" );
		float strafe = input.LocalValue( "UATurnRight" ) - input.LocalValue( "UATurnLeft" );
		
		float smooth_speed = 0.9;
		if ( forward != 0 && m_CameraMotorForward < 1 )
		{
			m_CameraMotorForward += forward * smooth_speed * time_slice;
			
			if ( m_CameraMotorForward > 1 )
			{
				m_CameraMotorForward = 1;
			}
		}
		else if ( m_CameraMotorForward != 0 )
		{
			if ( m_CameraMotorForward < 0 )
			{
				m_CameraMotorForward += smooth_speed * time_slice;
				
				if ( m_CameraMotorForward > 0 )
				{
					m_CameraMotorForward = 0;
				}
			}
			
			if ( m_CameraMotorForward > 0 )
			{
				m_CameraMotorForward -= smooth_speed * time_slice;
				
				if ( m_CameraMotorForward < 0 )
				{
					m_CameraMotorForward = 0;
				}
			}
		}
		
		
		if ( strafe != 0 && m_CameraMotorStrafe < 1 )
		{
			m_CameraMotorStrafe += strafe * smooth_speed * time_slice;
			
			if ( m_CameraMotorStrafe > 1 )
			{
				m_CameraMotorStrafe = 1;
			}
		}
		else if ( m_CameraMotorStrafe != 0 )
		{
			if ( m_CameraMotorStrafe < 0 )
			{
				m_CameraMotorStrafe += smooth_speed * time_slice;
				
				if ( m_CameraMotorStrafe > 0 )
				{
					m_CameraMotorStrafe = 0;
				}
			}
			
			if ( m_CameraMotorStrafe > 0 )
			{
				m_CameraMotorStrafe -= smooth_speed * time_slice;
				
				if ( m_CameraMotorStrafe < 0 )
				{
					m_CameraMotorStrafe = 0;
				}
			}
		}
		
		float speed = m_CameraSpeed;
		if( input.LocalValue( "UATurbo" ) )
		{
			speed *= 4;
		}		
		
		vector direction = GetDirection();
		vector direction_aside = vector.Up * direction;
		
		vector forward_change = m_CameraMotorForward * time_slice * direction * speed;
		vector strafe_change = m_CameraMotorStrafe * time_slice * direction_aside * speed;
		new_pos = new_pos + forward_change + strafe_change;
		float y_min = GetGame().SurfaceY(new_pos[0], new_pos[2]);
		if( new_pos[1] < y_min+0.1 )
			new_pos[1] = y_min+0.1;
	}
	
	void UpdateOrientFromInputFree( out vector new_orient, float time_slice )
	{
		Input input = GetGame().GetInput();
		float yaw_diff = input.LocalValue( "UAAimHeadLeft" ) - input.LocalValue( "UAAimHeadRight" );
		float pitch_diff = input.LocalValue( "UAAimHeadDown" ) - input.LocalValue( "UAAimHeadUp" );
		
		new_orient[0] = new_orient[0] - Math.RAD2DEG * yaw_diff * time_slice;
		new_orient[1] = new_orient[1] - Math.RAD2DEG * pitch_diff * time_slice;
		if( new_orient[1] < -89 )
			new_orient[1] = -89;
		if( new_orient[1] > 89 )
			new_orient[1] = 89;
	}
	
	float CalculateHorizontalDistance( float pitch )
	{
		return m_OrbitRadius * Math.Cos(pitch);
	}
	
	float CalculateVerticalDistance( float pitch )
	{
		return m_OrbitRadius * Math.Sin(pitch);
	}
	
	vector CalculateCameraPosition( PlayerBase player_base, float horizontal_distance, float vertical_distance, vector followed_object_pos, float time_slice  )
	{
		float theta = m_AngleAroundFollowedObject;
		float offsetX = horizontal_distance * Math.Sin( theta  );
		float offsetZ = horizontal_distance * Math.Cos( theta  );
		
		vector camera_pos;
		camera_pos[0] = followed_object_pos[0] - offsetX;
		camera_pos[2] = followed_object_pos[2] - offsetZ;
		camera_pos[1] = followed_object_pos[1] + vertical_distance;
		
		vector player_to_camera = vector.Direction( followed_object_pos, camera_pos );
		player_to_camera.Normalize();
		
		vector from = followed_object_pos;
		vector to = from + player_to_camera * m_OrbitRadius;
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		set<Object> hit_object = new set<Object>;
		array<ref RaycastRVResult> results = new array<ref RaycastRVResult>;
		RaycastRVParams params_in = new RaycastRVParams(from, to, player_base);
		
		params_in.flags = CollisionFlags.ALLOBJECTS;
		params_in.sorted = true;
		DayZPhysics.RaycastRVProxy( params_in, results );
		
		bool is_ground;
		array<ref RaycastRVResult> ignore_results = new array<ref RaycastRVResult>;
		for ( int i = 0; i < results.Count(); i++ )
		{
			Object obj = results[i].obj;
			if( obj && obj.IsTree() )
			{
				ignore_results.Insert( results[i] );
			}
			
			if( !obj ) //when object is NULL it indicates that it is ground
			{
				is_ground = true;
			}
		}
		
		for ( i = 0; i < ignore_results.Count(); i++ )
		{
			results.RemoveItem( ignore_results[i] );
		}
		
		if( results.Count() > 0 )
		{
			RaycastRVResult first_result = results[results.Count() - 1];
			hit_object.Insert( first_result.obj );
			contact_pos = first_result.pos;
		}
		else
		{
			contact_pos = camera_pos;
		}
		
		m_IsCameraRaycastHittingObject = hit_object.Count() != 0;
		m_CameraRaycastHitDistance = vector.Distance( contact_pos, followed_object_pos );
	
		vector camera_to_player = vector.Direction( contact_pos, followed_object_pos );
		camera_to_player.Normalize();
		
		if( !is_ground )
		{
			contact_pos = contact_pos + camera_to_player * 0.25; //offset camera slighty so it doesn't intersect with geometry
		}
		else
		{
			vector normal = GetGame().SurfaceGetNormal( contact_pos[0], contact_pos[2] );
			contact_pos = contact_pos + normal * 0.25; //offset camera slighty so it doesn't intersect with ground
		}
		
		vector lerped_pos = vector.Lerp( GetPosition(), contact_pos, m_LerpConst * time_slice );
		return lerped_pos;
	}
	
	void UpdateFromInputOrbit( PlayerBase player_base, out vector new_orient, out vector new_pos, float time_slice )
	{
		Input input = GetGame().GetInput();
		
		if( !m_IsCameraRaycastHittingObject )
		{
			if ( input.LocalRelease( "UANextAction" ) )
			{
				m_OrbitRadius += m_ZoomMultiplier;
			}
		}
		
		if ( input.LocalRelease( "UAPrevAction" ) )
		{
			if( m_IsCameraRaycastHittingObject )
			{
				m_OrbitRadius = m_CameraRaycastHitDistance;
			}
			m_OrbitRadius -= m_ZoomMultiplier;
		}
		
		if( m_OrbitRadius < m_MinOrbitRadius )
		{
			m_OrbitRadius = m_MinOrbitRadius;
		}
		
		if( m_OrbitRadius > m_MaxOrbitRadius )
		{
			m_OrbitRadius = m_MaxOrbitRadius;
		}
		
		float yaw_diff = input.LocalValue( "UAAimHeadLeft" ) - input.LocalValue( "UAAimHeadRight" );
		float pitch_diff = input.LocalValue( "UAAimHeadDown" ) - input.LocalValue( "UAAimHeadUp" );
		
		m_Pitch += pitch_diff * time_slice * 1;
		m_AngleAroundFollowedObject += yaw_diff * time_slice * 1;
		if( m_Pitch > 1.5 )
		{
			m_Pitch = 1.5;
		}
		
		if( m_Pitch < -1.5 )
		{
			m_Pitch = -1.5;
		}
		
		float horizontal_distance = CalculateHorizontalDistance( m_Pitch );
		float vertical_distance = CalculateVerticalDistance( m_Pitch );
		
		vector followed_object_pos = m_TargetPlayer.GetPosition();
		followed_object_pos[1] = followed_object_pos[1] +  1.5; //shift y position slighty up, so camera aims at players head
		
		new_pos = CalculateCameraPosition( player_base, horizontal_distance, vertical_distance, followed_object_pos, time_slice );

		new_orient = vector.Direction( new_pos, followed_object_pos );
		new_orient = new_orient.VectorToAngles();
	}
	
	void SetTarget( ESgCasterCameraState state, SgPlayerClient object )
	{
		PlayerBase player;
		if( state != m_CameraState )
		{
			switch( state )
			{
				case ESgCasterCameraState.FirstPerson:
				{
					m_TargetPlayer = object;
					m_CameraState = state;
					m_CameraSet = false;
					break;
				}
				case ESgCasterCameraState.ThirdPerson:
				{
					m_TargetPlayer = object;
					m_CameraState = state;
					m_CameraSet = false;
					break;
				}
				case ESgCasterCameraState.Snap:
				{
					if( object )
					{
						m_TargetPlayer = object;
						m_OrbitRadius		=	3.0;
						player = m_TargetPlayer.GetPlayerBase();
						vector old_pos;
						int bone_index = player.GetBoneIndexByName("Head");
						if (bone_index != -1)
						{
							old_pos	= player.GetBonePositionWS(bone_index);
						}
						float offset		=	m_OrbitRadius/Math.Sqrt(2);
						m_LastPos			=	old_pos;
						old_pos[0]			=	old_pos[0] + offset;
						old_pos[1]			= 	old_pos[1] + offset;
						
						SetPosition( old_pos );
						
						m_CameraState = state;
						m_CameraSet = false;
					}
					break;
				}
				case ESgCasterCameraState.Free:
				{
					m_CameraState = state;
					m_CameraSet = false;
					break;
				}
			}
		}
	}
	
	void TeleportCaster( vector new_pos )
	{
		if( m_CameraState == ESgCasterCameraState.Free )
		{
			SetPosition(new_pos);
			GetGame().UpdateSpectatorPosition(new_pos);
		}
	}
	
	void MatrixFromAxisAngle( out vector mat[3], vector axis, float angle )
	{
	    float c = Math.Cos(angle);
	    float s = Math.Sin(angle);
	    float t = 1.0 - c;
		
		axis.Normalized();
	    mat[0][0] = c + axis[0]*axis[0]*t;
	    mat[1][1] = c + axis[1]*axis[1]*t;
	    mat[2][2] = c + axis[2]*axis[2]*t;
	
	    float tmp1 = axis[0]*axis[1]*t;
	    float tmp2 = axis[2]*s;
	    mat[1][0] = tmp1 + tmp2;
	    mat[0][1] = tmp1 - tmp2;
	    tmp1 = axis[0]*axis[2]*t;
	    tmp2 = axis[1]*s;
	    mat[2][0] = tmp1 - tmp2;
	    mat[0][2] = tmp1 + tmp2;
		tmp1 = axis[1]*axis[2]*t;
	    tmp2 = axis[0]*s;
	    mat[2][1] = tmp1 + tmp2;
	    mat[1][2] = tmp1 - tmp2;
	}
	
	void RotateVectorByMatrix( out vector vect, vector rot[3] )
	{
		vect = vect.Multiply3( rot );
	}
}
