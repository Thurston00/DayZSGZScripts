/*
	Data constant class. The only purpose 
*/
class SgCGunIcon
{
	// Static reference vars
	private static ref array<ref SgCGunIcon> GUNS_LIST;
	private static int id_counter;
	// Data
	private int m_Id;
 	private string m_Name;
	private string m_DisplayName;
	private string m_IconPath;
	
	// ---------------------------------------------
	
	// Constructor
	private void SgCGunIcon(string name, string display_name, string path)
	{
		m_Id = id_counter++;	
		m_Name =  name;
		m_DisplayName = display_name;
		m_IconPath = path;	
	}
	
	// ------------------------------------------------
	// STATIC INIT METHODS
	
	// Check if the gun list is Instantiated and create a new one when/if needed
	private static void InitCheck()
	{
		if (!GUNS_LIST)
		{
			GUNS_LIST = new array<ref SgCGunIcon>;
			LoadGunList();
		}
	}
	// Popuplate gun list
	private static void LoadGunList()
	{
		GUNS_LIST.Insert(new SgCGunIcon("CZ75",		"CR-75", 		string.Format("set:%1 image:%2", "sgz_hud", "gun_cz75")));
		GUNS_LIST.Insert(new SgCGunIcon("MP5K", 	"SG5-K", 		string.Format("set:%1 image:%2", "sgz_hud", "gun_mp5k")));
		GUNS_LIST.Insert(new SgCGunIcon("Mp133",	"BK-133", 		string.Format("set:%1 image:%2", "sgz_hud", "gun_mp133")));
		GUNS_LIST.Insert(new SgCGunIcon("UMP45", 	"USG-45", 		string.Format("set:%1 image:%2", "sgz_hud", "gun_ump45")));
		GUNS_LIST.Insert(new SgCGunIcon("FNX45", 	"FX-45",		string.Format("set:%1 image:%2", "sgz_hud", "gun_fnx45")));
		GUNS_LIST.Insert(new SgCGunIcon("Izh18",	"BK-18", 		string.Format("set:%1 image:%2", "sgz_hud", "gun_izh18")));
		GUNS_LIST.Insert(new SgCGunIcon("AKM", 		"KA-M",			string.Format("set:%1 image:%2", "sgz_hud", "gun_akm")));
		GUNS_LIST.Insert(new SgCGunIcon("SVD", 		"VSD", 			string.Format("set:%1 image:%2", "sgz_hud", "gun_svd")));
		GUNS_LIST.Insert(new SgCGunIcon("M4A1",		"M4-A1",		string.Format("set:%1 image:%2", "sgz_hud", "gun_m4a1")));
		GUNS_LIST.Insert(new SgCGunIcon("Mosin9130","Mosin 91/30", 	string.Format("set:%1 image:%2", "sgz_hud", "gun_mosin9130")));
		GUNS_LIST.Insert(new SgCGunIcon("SKS", 		"SK 59/66", 	string.Format("set:%1 image:%2", "sgz_hud", "gun_sks")));
	}
	
	// -----------------------------------------------------------
	// GETTERS
	int GetID()
	{
		return m_Id;
	}
	string GetName()
	{
		return m_Name;
	}
	string GetDisplayName()
	{
		return m_DisplayName;
	}
	string GetIcon()
	{
		return m_IconPath;
	}
	
	// ----------------------------------------------------------
	// STATIC GETTERS
	
	// Get the whole gun list array 
	static ref array<ref SgCGunIcon> GetGunList()
	{	
		InitCheck();
		return GUNS_LIST;
	}
	// Get the number of entries in the gun list
	static int Count()
	{
		InitCheck();
		return GUNS_LIST.Count();
	}	
	// Find the gun based by its name
	static SgCGunIcon FindGunByName(string name)
	{
		InitCheck();
		foreach (SgCGunIcon gun : GUNS_LIST)
		{
			if (gun.m_Name == name)
			{
				return gun;
			}
		}
		return null;
	}	
	// Find the gun based by its display name
	static SgCGunIcon FindGunByDisplayName(string name)
	{
		InitCheck();
		foreach (SgCGunIcon gun : GUNS_LIST)
		{
			if (gun.m_DisplayName == name)
			{
				return gun;
			}
		}
		return null;
	}	
}