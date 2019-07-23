modded class MissionBase
{
	override UIScriptedMenu CreateScriptedMenu( int id )
	{
		UIScriptedMenu menu;

		if ( menu == NULL )
		{
			switch (id)
			{					
				case MENU_SG_MAIN_MENU:
				{
					//menu = SgSMenu.GetSgMenu();
					menu = new SGMainMenu;
					break;
				}
				case MENU_SG_PG_EDITOR:
				{
					menu = new SgPlaygroundEditorMenu;
					break;
				}
			}
		}

		if ( menu )
		{
			menu.SetID( id );
		}
		else
		{
			menu = super.CreateScriptedMenu( id );
		}

		return menu;
	}
}
