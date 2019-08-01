class SG_InfectedBase extends AnimalBase 
{
	protected int 				m_InstanceId = -1;
	protected const float		NUMBER_OF_DEFAULT_INSTANCES	= 1;
	
	void SG_InfectedBase()
	{	
		RegisterNetSyncVariableInt( "m_InstanceId", 0, GetAnimationInstanceAlternatives().Count() + NUMBER_OF_DEFAULT_INSTANCES );
		
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
		{
			InitRandomInstanceId();
			SetAnimationInstanceByName( GetAnimationInstanceById(GetInstanceId()), GetInstanceId(), 0 );	
		}
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		SetAnimationInstanceByName( GetAnimationInstanceById(GetInstanceId()), GetInstanceId(), 0 );
	}
	
	string GetAnimationInstanceDefault()
	{
		string cfg_path_default = "CfgVehicles " + this.GetType() + " enfanimsys " + "defaultinstance";
		string instance_default;
		GetGame().ConfigGetText( cfg_path_default, instance_default );	
						
		return instance_default;
	}
	
	array<string> GetAnimationInstanceAlternatives()
	{
		string cfg_path_alternatives = "CfgVehicles " + this.GetType() + " enfanimsys " + "alternativeinstancies";
		TStringArray instance_alternatives = new TStringArray;
		GetGame().ConfigGetTextArray( cfg_path_alternatives, instance_alternatives);
		
		return instance_alternatives;
	}
		
	string GetAnimationInstanceById( int instance_id )
	{	
		if ( instance_id > 0 )
		{		
			return GetAnimationInstanceAlternatives().Get(instance_id - 1);
		}
		else
		{
			return GetAnimationInstanceDefault();
		}
	}
	
	void SetInstanceId( int instance_id )
	{
		m_InstanceId = instance_id;
		SetSynchDirty();
	}
	
	int GetInstanceId()
	{
		return m_InstanceId;
	}
	
	void InitRandomInstanceId()
	{
		int random_index = Math.RandomInt( 0, GetAnimationInstanceAlternatives().Count() + NUMBER_OF_DEFAULT_INSTANCES );
		
		SetInstanceId(random_index);
	}
		
	override bool ComputeDamageHitParams(EntityAI source, string dmgZone, string ammo, out int type, out int direction)
	{
		super.ComputeDamageHitParams( source, dmgZone, ammo, type, direction );
		
		type = GetGame().ConfigGetInt("cfgAmmo " + ammo + " hitAnimation");
		
		return true;
	}
	
	override int TranslateHitAngleDegToDirectionIndex(float angleDeg)
	{		
		if ( angleDeg > -45 && angleDeg < 45 )
		{
			//Print( "Direction FRONT: 1" );
			return 1; 
		}
		else if ( angleDeg <= -45 && angleDeg >= -135 )
		{
			//Print( "Direction LEFT: 2" );
			return 2;
		}
		else if ( angleDeg >= 45 && angleDeg <= 135 )
		{
			//Print( "Direction RIGHT: 3" );
			return 3;
		}
		else if (  angleDeg < -135 || angleDeg > 135 )
		{
			//Print(" Direction BACK: 4" );
			return 4;
		}
		else
		{
			//Print("Direction INVALID");
			return 0; 
		}	
	}
	
	override int FindComponentDirectionOffset(string component)
	{
		const int directionCount = 5;
		
		int offset = 0;
		if (component.Length() == 0)
		{
			offset = 0;
			//Print( "Missing component: " + offset );
		}
		//head
		else if (component == "Head")
		{
			offset = directionCount;
			//Print( "Component Head: " + offset );
		}
		//upper body
		else if ( component == "Neck" || component == "Torso" || component == "LeftArm" || component == "RightArm" )
		{
			offset = 2 * directionCount;
			//Print( "Component Upper body: " + offset );
		}
		//lower body
		//else if ( component == "LeftLeg" || component == "RightLeg" || component == "LeftFoot" || component == "RightFoot" )
		else
		{
			offset = 3 * directionCount;
			//Print( "Component Lower body: " + offset );
		}
		
		return offset;
	}
	
	override void EEKilled( Object killer )
	{
		super.EEKilled(killer);
		
		string killerUID = SG_UID_PLACEHOLDER;
		
		if ( killer != null )
		{
			if ( killer.IsInherited( EntityAI ) )
			{
				EntityAI parent = EntityAI.Cast( killer ).GetHierarchyRootPlayer();
				PlayerBase item_owner = PlayerBase.Cast( parent );
				
				if ( item_owner && item_owner.IsInherited( PlayerBase ) )
				{
					PlayerIdentity identity = PlayerBase.Cast( item_owner ).GetIdentity();
					if ( identity != null )
					{
						killerUID = identity.GetId();
					}
				}
			}
		}
		
		SgSManagerEventsServer.Event_OnZombieDied( this, killerUID );
	}
};