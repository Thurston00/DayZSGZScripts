class SG_StartBag extends Clothing
{
	void SG_StartBag()
	{
//Print("Starting Bag pack spawned !!!!");
		SetEventMask(EntityEvent.INIT);
	}
	
	override void EOnInit(IEntity other, int extra)
	{
		string cfg_path = "CfgVehicles SG_StartBag StartingItems";
		int child_count = GetGame().ConfigGetChildrenCount(cfg_path);
		int i = 0;
		
		array<int> cat_indexes = new array<int>;
		
		for ( i = 0; i < child_count; ++i )
		{
			cat_indexes.Insert(i);
		}
		
		for ( i = 0; i < child_count; ++i )
		{
//Print("***********");
			
			int arr_random_index = Math.RandomInt(0, cat_indexes.Count() - 1);
			int cat_random_index = cat_indexes[arr_random_index];
			
			cat_indexes.Remove(arr_random_index);
			
			string cat_name;
			GetGame().ConfigGetChildName (cfg_path, cat_random_index, cat_name);
			
//Print("cat_name="+ cat_name);
			
			string cat_path = cfg_path +" "+ cat_name;
			int cat_child_count = GetGame().ConfigGetChildrenCount(cat_path);

//Print("cat_path="+ cat_path);
			
			float picked_odd = Math.RandomFloat01();
			float cat_group_odd = 0;
			
			for ( int ci = 0; ci < cat_child_count; ++ci )
			{
				string cat_group_name;
				GetGame().ConfigGetChildName(cat_path, ci, cat_group_name);

//Print("cat_group_name="+ cat_group_name);
								
				string cat_group_path = cat_path +" "+ cat_group_name;
				cat_group_odd += GetGame().ConfigGetFloat(cat_group_path +" odd");
				
				if ( picked_odd <= cat_group_odd )
				{
					TStringArray items = new TStringArray;
					GetGame().ConfigGetTextArray(cat_group_path +" items", items );
					
					string cat_group_item = items[Math.RandomInt(0, items.Count() - 1)];
					
//Print(cat_name +"."+ cat_group_name +" => "+ cat_group_item);
					
					EntityAI e = EntityAI.Cast( GetGame().CreateObject(cat_group_item, GetPosition() ) );
					
					if( e )
					{
						if ( !PredictiveTakeEntityToCargo(e) )
						{
							GetGame().ObjectDelete(e);
						}
						else
						{
							if ( e.IsInherited(ItemBase) ) 
							{		
								ItemBase item = ItemBase.Cast( e );
								item.SetQuantity(item.GetQuantityMax());
							}
						}
					}
					else
					{
						Print( "D: " + cat_group_item );
					}
					
					
					break;
				}
			}
		}
		
		
//Print("child_count: "+ child_count);
	}
}