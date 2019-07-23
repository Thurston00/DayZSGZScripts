class SgArray<Class T>
{
	// SG_TODO: Prepisat to nativne do DayZ
	static array<ref T> Copy(array<ref T> arr)
	{
		array<ref T> newArr = new array<ref T>();
		
		foreach( T obj : arr )
		{
			newArr.Insert(obj);
		}
		
		return newArr;
	}
	
	static void Shuffle(notnull array<ref T> arr, int times = 0)
	{	
		int arrCount = arr.Count();
		if ( arrCount < 2 ) { return; }
		if ( times <= 0 ) { times = arrCount * arrCount; }
		
		for (int i = 0; i < times; i++)
		{
			int a = Math.RandomInt(0, arrCount);
			int b = Math.RandomInt(0, arrCount);
			
			SwapItems(arr, a, b);
		}		
	}
	
	static void SwapItems(notnull array<ref T> arr, int item1_index, int item2_index)
	{
		T item1 = arr.Get(item1_index);
		arr.Set(item1_index, arr.Get(item2_index));
		arr.Set(item2_index, item1);
	}
}