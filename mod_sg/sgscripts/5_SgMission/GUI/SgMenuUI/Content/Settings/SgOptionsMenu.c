/*
	Modded DayZ option class to keep consistency with SG layout 
*/ 
modded class OptionsMenu
{
	private ref KeybindingsGroup m_UiKeybindingGroupTab;
	
	
	// Parent Widget
	private Widget m_ParentWidget;
	// Sg Buttons
	private ref SgUiButtonActionMedium m_UiApplyButton;	
	private ref SgUiButtonActionMedium m_UiResetButton;
	// Sg Button OnClick Events
	private ref ScriptInvoker Event_OnApplyButtonClicked = new ScriptInvoker();
	private ref ScriptInvoker Event_OnResetButtonClicked = new ScriptInvoker();
	
	// -------------------------------------------
	
	Widget SgInit(Widget parent_widget)
	{
		m_ParentWidget = parent_widget;
		return Init();
	}
	
	// Modified Init
	override Widget Init()
	{
		m_Options		= new GameOptions();
		
		// Sg Layout root path
		layoutRoot		= GetGame().GetWorkspace().CreateWidgets( "mod_sg/gui/layouts/sg_menu/sg_content/sg_settings/sg_options_menu.layout", m_ParentWidget );
		
		// Tabs
		layoutRoot.FindAnyWidget( "Tabber" ).GetScript( m_Tabber );
		m_Details		= layoutRoot.FindAnyWidget( "settings_details" );
		m_GameTab		= new OptionsMenuGame( layoutRoot.FindAnyWidget( "Tab_0" ), m_Details, m_Options, this );
		m_SoundsTab		= new OptionsMenuSounds( layoutRoot.FindAnyWidget( "Tab_1" ), m_Details, m_Options, this );
		m_VideoTab		= new OptionsMenuVideo( layoutRoot.FindAnyWidget( "Tab_2" ), m_Details, m_Options, this );
		m_ControlsTab	= new OptionsMenuControls( layoutRoot.FindAnyWidget( "Tab_3" ), m_Details, m_Options, this );
		
		
		Input input	= GetGame().GetInput();
		string group_name;
		input.GetActionGroupName( 0, group_name );
		g_Game.SetKeyboardHandle( this );
		m_UiKeybindingGroupTab = new KeybindingsGroup( 0, input, layoutRoot.FindAnyWidget( "Tab_4" ), null );
		m_UiKeybindingGroupTab.SetOptionsMenu(this);
		m_ControlsTab.SetKeybindingTab(m_UiKeybindingGroupTab);
		
		
		// Dayz Buttons (not in use)
		m_Apply			= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "apply" ) );
		m_Reset			= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "reset" ) );
		// Sg Buttons
		m_UiApplyButton = new SgUiButtonActionMedium( layoutRoot.FindAnyWidget( "ApplyButtonFrame" ), SgCMenuButtonStrings.APPLY_C, Event_OnApplyButtonClicked);
		m_UiApplyButton.Enable(false);
		m_UiResetButton = new SgUiButtonActionMedium( layoutRoot.FindAnyWidget( "DefaultButtonFrame" ), SgCMenuButtonStrings.RESET_C, Event_OnResetButtonClicked );
		// Sg Button OnClick Events
		Event_OnApplyButtonClicked.Insert(Apply);
		Event_OnResetButtonClicked.Insert(Reset);
			
		SetFocus( layoutRoot );
		
		m_Tabber.m_OnTabSwitch.Insert( OnTabSwitch );
				
		OnChanged();
		
		float timeslice;
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater( Update, 50, true, timeslice);
		
		return layoutRoot;
	}
	
	// Modified DayZ OnChanged (it works with SgButton instead of DayZ)
	override void OnChanged()
	{
		bool changed = false;
		if( m_Options.IsChanged() || m_GameTab.IsChanged() || m_SoundsTab.IsChanged() || m_VideoTab.IsChanged() )
		{
			changed = true;
		}
		
		if( changed )
		{
			m_UiApplyButton.Enable(true);
			m_UiResetButton.Enable(true);
		}
		else
		{
			m_UiApplyButton.Enable(false);
		}
	}
	
	// On Apply Button Clicked 
	override void Apply()
	{	
		// Disable Appply button - no need to use it 2x in a row 
		m_UiApplyButton.Enable(false);
		// DayZ apply functionality
	 	super.Apply();
		
		m_UiKeybindingGroupTab.Apply();
	}
	
	// On Reset Button Clicked
	override void Reset()
	{
		// DayZ Reset functionality
		super.Reset();	
		// Disable Apply button - we reseted the settings, why would you want to save no changes? 
		m_UiApplyButton.Enable(false);
		m_UiKeybindingGroupTab.Reset();
	}
	
	override void Update(float timeslice)
	{
		timeslice += 50;
		
		super.Update(timeslice);
		m_UiKeybindingGroupTab.Update(timeslice);
	}
	
	// Modify DayZ highlight colours 
	override void ColorHighlight( Widget w )
	{		
		w.SetColor( ARGB( 255, 0, 0, 0) );
		
		TextWidget text1	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		TextWidget text3	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindAnyWidget( w.GetName() + "_image" ) );
		Widget option		= Widget.Cast( w.FindAnyWidget( w.GetName() + "_option_wrapper" ) );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if( text1 )
		{
			text1.SetColor( SgCMenuColours.COLOUR_YELLOW );
		}
		
		if( text2 )
		{
			text2.SetColor( SgCMenuColours.COLOUR_YELLOW );
		}
		
		if( text3 )
		{
			text3.SetColor( SgCMenuColours.COLOUR_YELLOW );
			w.SetAlpha(1);
		}
		
		if( image )
		{
			image.SetColor( SgCMenuColours.COLOUR_YELLOW );
		}
		
		if ( option )
		{
			option.SetColor( SgCMenuColours.COLOUR_YELLOW );
		}
		
		if ( option_label )
		{
			option_label.SetColor( SgCMenuColours.COLOUR_YELLOW );
		}
	}
	
	override void ColorNormal( Widget w )
	{				
		w.SetColor( ARGB( 0, 0, 0, 0) );
		
		TextWidget text1	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
		TextWidget text3	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindAnyWidget( w.GetName() + "_image" ) );
		Widget option		= w.FindAnyWidget( w.GetName() + "_option_wrapper" );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if( text1 )
		{
			text1.SetColor( ARGB( 255, 255, 255, 255 ) );
		}
		
		if( text2 )
		{
			text2.SetColor( ARGB( 255, 255, 255, 255 ) );
		}
		
		if( text3 )
		{
			text3.SetColor( ARGB( 255, 255, 255, 255 ) );
			w.SetAlpha(0);
		}
		
		if( image )
		{
			image.SetColor( ARGB( 255, 255, 255, 255 ) );
		}
		
		if ( option )
		{
			option.SetColor( ARGB( 150, 255, 255, 255 ) );
		}
		
		if ( option_label )
		{
			option_label.SetColor( ARGB( 255, 255, 255, 255 ) );
		}
	}
	
	void OnTabSwitch( int tab )
	{
		switch( tab )
		{
			case 0:
			{
				m_GameTab.Focus();
				break;
			}
			case 1:
			{
				m_SoundsTab.Focus();
				break;
			}
			case 2:
			{
				m_VideoTab.Focus();
				break;
			}
			case 3:
			{
				m_ControlsTab.Focus();
				break;
			}
			case 4: 
			{
				m_UiKeybindingGroupTab.Focus();
				break;
			}
		}
	}
	
	
	override void Refresh(){}
	
	// Button Manipulation
	void EnableApplyButton(bool enable)
	{
		m_UiApplyButton.Enable(enable);
	}
	void EnableResetButton(bool enable)
	{
		m_UiResetButton.Enable(enable);
	}	
}