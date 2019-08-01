modded class EmoteManager
{
 	override bool PlayEmote( int id )
	{
		if ( id == ID_EMOTE_SUICIDE )
		{
			return false;
		}
		
		return super.PlayEmote(id);
	}
}