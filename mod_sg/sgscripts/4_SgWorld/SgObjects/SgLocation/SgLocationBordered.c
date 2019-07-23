class SgLocationBordered : SgLocation
{
	protected const float INNER_BORDER_INSET = 5;
	protected const float BALOON_HEIGHT = 100;
	protected string m_OuterTextures = "";
	
	protected Object m_CenterTower;
	protected ref array<Object> m_BorderObjects = new array<Object>();
	protected ref array<Object> m_BorderObjectsSmallOut = new array<Object>();
	protected ref array<Object> m_BorderObjectsSmallIn = new array<Object>();
	
	//===============================
	// Event_OnGameInitialized
	//===============================
	override void Event_OnGameInitialized( int pg_id )
	{
		super.Event_OnGameInitialized( pg_id );
		
		m_CenterTower = GetGame().CreateObject( "SG_StaticBalloon", GetPosition() );
		SG_StaticBalloon balloon = SG_StaticBalloon.Cast(m_CenterTower);
		balloon.SetLocationType(m_LocationType);
		
		vector position = m_CenterTower.GetPosition();
		position[1] = position[1] + BALOON_HEIGHT;
		m_CenterTower.SetPosition(position);
		
		ref array<string> dragonToothRedTextures = new array<string>;
		GetGame().ConfigGetTextArray( "CfgVehicles SG_StaticDragonTooth_Red " + m_OuterTextures, dragonToothRedTextures );
		
		for ( int i = 0; i < m_BorderPositions.Count(); ++i )
		{
			vector border_point = m_BorderPositions[i];
			
			int next_i = i + 1;
			if ( next_i == m_BorderPositions.Count() )
			{
				next_i = 0;
			}
			vector border_next = m_BorderPositions[ next_i ];
			
			int prev_i = i - 1;
			if ( i == 0 )
			{
				prev_i = m_BorderPositions.Count() - 1;
			}
			vector border_prev = m_BorderPositions[ prev_i ];
			
			float gap = 25;
			vector dir = (border_next - border_point).Normalized();
			float dist = vector.Distance(border_point, border_next);
			float count = Math.Floor( dist / gap );
			gap = dist / count;
			
			vector dir_in;		
			dir_in[0] = dir[2] * -1;
			dir_in[2] = dir[0];
			
			vector dir_prev = (border_point - border_prev).Normalized();
			vector dir_in_prev;
			dir_in_prev[0] = dir_prev[2] * -1;
			dir_in_prev[2] = dir_prev[0];
			
			vector borderAntennaPosition = border_point + dir_in * INNER_BORDER_INSET + dir_in_prev * 5;
			Object obj_edge = GetGame().CreateObject( "SG_StaticDragonTooth_Green", borderAntennaPosition );
			obj_edge.SetOrientation( "0 0 0" );
			
			m_BorderObjects.Insert( obj_edge );
			
			for ( int j = 0; j < count; ++j )
			{
				vector small_pos_out = border_point + ( dir * (j * gap) );
				vector small_pos_in = small_pos_out + ( dir_in * INNER_BORDER_INSET );
				vector small_pos_out_shifted = small_pos_out;
				
				small_pos_out_shifted[0] = small_pos_out_shifted[0] + Math.RandomFloatInclusive(-0.15, 0.15);
				small_pos_out_shifted[2] = small_pos_out_shifted[2] + Math.RandomFloatInclusive(-0.15, 0.15);
				
				// Real border
				EntityAI obj_small_out = EntityAI.Cast(GetGame().CreateObject( "SG_StaticDragonTooth_Red", small_pos_out_shifted ));
				m_BorderObjectsSmallOut.Insert( obj_small_out );
				
				// Visual warning border
				if ( j != 0 )
				{
					vector outToInDirection = (small_pos_out - small_pos_in).Normalized();
					vector outToInDirectionRotation1 = outToInDirection;
					vector outToInDirectionRotation2 = outToInDirection;
					vector small_pos_in_shifted = small_pos_in;
					
					outToInDirectionRotation1[0] = outToInDirectionRotation1[0] + Math.RandomFloatInclusive(-0.4, 0.4);
					outToInDirectionRotation2[0] = outToInDirectionRotation2[0] + Math.RandomFloatInclusive(-0.4, 0.4);
					
					small_pos_in_shifted[0] = small_pos_in_shifted[0] + Math.RandomFloatInclusive(-0.5, 0.5);
					small_pos_in_shifted[2] = small_pos_in_shifted[2] + Math.RandomFloatInclusive(-0.5, 0.5);
					
					EntityAI obj_small_in = EntityAI.Cast( GetGame().CreateObject( "SG_StaticDragonTooth_Green", small_pos_in_shifted ) );
					m_BorderObjectsSmallIn.Insert( obj_small_in );					
					
					obj_small_in.SetDirection( outToInDirectionRotation1 );
					obj_small_out.SetDirection( outToInDirectionRotation2 );
					obj_small_out.SetObjectTexture( 1, dragonToothRedTextures.GetRandomElement() );
				}
				else
				{
					vector outToInDirectionRotation = (small_pos_out - borderAntennaPosition).Normalized();
					outToInDirectionRotation[0] = outToInDirectionRotation[0] + Math.RandomFloatInclusive(-0.4, 0.4);
					
					obj_edge.SetDirection(outToInDirectionRotation);
					obj_small_out.SetDirection( outToInDirectionRotation );
					obj_small_out.SetObjectTexture( 1, dragonToothRedTextures.GetRandomElement() );
				}
			}
		}
	}
}