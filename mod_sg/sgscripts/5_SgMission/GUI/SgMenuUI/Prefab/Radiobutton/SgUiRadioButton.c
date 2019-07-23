class SgUiRadioButton extends SgUiMenuPanel
{
	private const int DEFAULT_RADIOBUTTON = 0;
	
	// Widget
	private 	Widget 									m_UiContentGrid;
	private ref array<ref SgUiRadioButtonRow> 			m_UiRadioButtonRows				= new ref array<ref SgUiRadioButtonRow>;
	// Data
	private ref ref array<ref Param2<string, string>>	m_RadioButtonData 				= new ref array<ref Param2<string, string>>;		// Param1 --> user output (rediobutton text), Param2 --> radiobutton value
	private ref ScriptInvoker	 						Event_OnRadioButtonRowChanged 	= new ref ScriptInvoker();
	
	// Constructor
	void SgUiRadioButton(Widget parent_widget, ref array<ref Param2< string, string>> radiobutton_elements)
	{
		m_RadioButtonData = radiobutton_elements;
		
		super.BuildLayout(parent_widget);
	}
		
	// ------------------------------
	// OVERRIDES -- > SgUiMenuPanel
	
	override string GetLayoutPath()
	{
		return "mod_sg/gui/layouts/sg_menu/sg_prefab/sg_radiobutton/sg_radiobutton_base.layout";
	}
	override protected void FindAllWidgets()
	{
		// Find widgets
		m_UiContentGrid 	= FindPanel("ContentGrid");
	}
	override protected void LoadAllWidgets()										
	{
		SetRadioButtonRows();
	}
	override protected void RegisterAllEvents()
	{
		Event_OnRadioButtonRowChanged.Insert(OnRadioButtonChanged);
	}
	// ---------------------------------------------
	
	int GetSelectedRadioButtonIndex()
	{
		int index = 0;
		foreach (SgUiRadioButtonRow row : m_UiRadioButtonRows)
		{
			index++;
			if(row.GetChecked())
			{
				return index;
			}
		}	
		return -1;
	}
	
	string GetSelectedRadioButtonValue()
	{
		foreach (SgUiRadioButtonRow row : m_UiRadioButtonRows)
		{
			if(row.GetChecked())
			{
				return row.GetValue();
			}
		}	
		return "";
	}
	
	SgUiRadioButtonRow GetSelectedRadioButtonRow()
	{
		foreach (SgUiRadioButtonRow row : m_UiRadioButtonRows)
		{
			if(row.GetChecked())
			{
				return row;
			}
		}	
		return null;
	}
	
	// -----------------------------------------------
	
	private void SetRadioButtonRows()
	{		
		for (int i = 0; i < m_RadioButtonData.Count(); i++)
		{
			string output = m_RadioButtonData.Get(i).param1;
			string value = m_RadioButtonData.Get(i).param2; 
			
			m_UiRadioButtonRows.Insert( new SgUiRadioButtonRow( m_UiContentGrid, output, value, Event_OnRadioButtonRowChanged ));
		}
		
		if(m_UiRadioButtonRows.Count())
		{
			this.m_UiRadioButtonRows.Get(DEFAULT_RADIOBUTTON).Check();
		}
	}
	
	// -----------------------------------------------
	
	private void OnRadioButtonChanged(SgUiRadioButtonRow radiobutton)
	{
		if(radiobutton.GetChecked())
		{
			foreach (SgUiRadioButtonRow row : this.m_UiRadioButtonRows)
			{
				if(radiobutton != row)
				{
					row.Uncheck();
				}
			}
		}
	}
}