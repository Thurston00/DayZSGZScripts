class SgSStringControl
{
	static string PositionToString(int position)
	{
		switch(position)
		{
			case 1:
				return string.Format("%1st" , position );
			case 2:
				return string.Format("%1nd" , position );
			case 3:
				return string.Format("%1rd" , position );
			default:
				return string.Format("%1th" , position );
		}
		
		return "";
	}
}