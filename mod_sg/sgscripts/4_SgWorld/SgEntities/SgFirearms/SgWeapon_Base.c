modded class Weapon_Base
{
	override float GetChanceToJam() 	
	{ 
		return 0;
	}
	
	override float GetSyncChanceToJam() 
	{ 
		return 0;
	}
	
	override void EEFired (int muzzleType, int mode, string ammoType)
	{
		super.EEFired(muzzleType, mode, ammoType);
		
		if ( GetSgGame().IsServer() )
		{
			PlayerBase player = PlayerBase.Cast( GetHierarchyRootPlayer() );
			if ( player )
			{
				SgSMatchRecorder.OnPlayerFired( player );
				
				//Analytics
				GetSgGame().GetAnalyticsServer().AddShotEvent( player, this );				
			}
		}
	}
	
	// Lift weapon when near an obstackle
	override bool LiftWeaponCheck (PlayerBase player)
	{
		return false; // For the purposes of SGZ, weapon lift is temporarily disabled.
	}
	
	/* 
	/ Desc: 	Get all the ammo int the passed item (check includes chamber and magazine)
	/ Param1: 	EntityAI 	-> a weapon that will be checked
	/ Return:  	int 		-> number of ammuntion
	*/
	int GetClipAmmo()
	{
		int chamber = 0;
		int clip = 0;
		Weapon_Base wpn;
		Magazine mag

		if ( Class.CastTo(wpn, this ) )
		{
			int mi = wpn.GetCurrentMuzzle();
			mag = wpn.GetMagazine(mi);
			if (!wpn.IsChamberFiredOut(mi) && !wpn.IsChamberEmpty(mi))
			{
				chamber = 1;
			}
			if (wpn.IsJammed())
			{
				chamber = 0;
			}
			
			if (mag)
			{
				clip = mag.GetAmmoCount();
			}
			else if (wpn.GetInternalMagazineCartridgeCount(mi) > 0)
			{
				clip = wpn.GetInternalMagazineCartridgeCount(mi);
			}
			
			return (clip + chamber);
		}
		return 0;
	}
	/* 
	/ Desc: 	Get all the ammo in inventory compatible with the passed item
	/ Param1: 	EntityAI 	-> a weapon that is ammo and magazine compared with
	/ Return:  	int 		-> number of ammuntion
	*/
	int GetAllInventoryAmmo()
	{
		Weapon_Base weapon_base = Weapon_Base.Cast( this );
		
		if (weapon_base)
		{
			PlayerBase client_player =  SgSClientGame.GetPlayer().GetPlayerBase();
			string ammo_type = weapon_base.GetChamberAmmoTypeName(0);
			WeaponManager weapon_manager = client_player.GetWeaponManager();	
			int ammo_pile_count;
			
			//Get all magazines in (player) inventory
			for ( int att_i = 0; att_i < client_player.GetInventory().AttachmentCount(); ++att_i )
			{
				EntityAI attachment = client_player.GetInventory().GetAttachmentFromIndex( att_i );
				ref CargoBase attachment_cargo = attachment.GetInventory().GetCargo();
				
				if ( attachment_cargo )
				{
					for ( int cgo_i = 0; cgo_i < attachment_cargo.GetItemCount(); ++cgo_i )
					{
						EntityAI cargo_item = attachment_cargo.GetItem( cgo_i );
						
						//check for proper magazine
						if ( cargo_item.IsMagazine() )
						{
							Magazine magazine = Magazine.Cast( cargo_item );
							
							//magazines (get magazine with max ammo count)
							if ( weapon_manager.CanAttachMagazine( weapon_base, magazine ) || weapon_manager.CanSwapMagazine( weapon_base, magazine ) )
							{
								ammo_pile_count += magazine.GetAmmoCount();		
							}
							//bullets (get ammo pile with min ammo count)
							else if ( weapon_manager.CanLoadBullet( weapon_base, magazine ) )
							{
								ammo_pile_count += magazine.GetAmmoCount();		
							}
							else if ( cargo_item.GetType() == ammo_type)
							{
								ammo_pile_count += magazine.GetAmmoCount();		
							}
						}
					}
				}
			}
		}
		return ammo_pile_count;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(FirearmActionAttachMagazineQuick); // Easy reload
		AddAction(FirearmActionLoadBulletQuick); // Easy reload
	}
}