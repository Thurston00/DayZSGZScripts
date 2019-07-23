modded class PPEffects
{
	static int 	m_CollarColor;
	static int	m_BlurCollar;
	
	static void SgInit()
	{
		// add new blur effects here
		m_BlurCollar 	= RegisterBlurEffect();
		
		// add new color effects here
		m_CollarColor 	= RegisterColorEffect();
	}
	
	//-------------------------------------------------------
	//! Set blur collar effect to a specified 'value' between 0..1
	static void SetBlurCollar(float value)
	{
		SetBlurValue(m_BlurCollar, value);
		UpdateBlur();
	}
	//-------------------------------------------------------
	//! Resets blur Collar effect to 0
	static void ResetBlurCollar()
	{
		SetBlurCollar(0);
	}	
	//-------------------------------------------------------
	
	static void SetColorCollar(float alfa, float overlay)
	{
		SetColorValue(m_CollarColor, 0, 0, 0, alfa, overlay);
		UpdateColor();
	}
	
	static void ResetColorCollar()
	{
		SetColorCollar(0,0);
	}	
	
	override static void SetUnconsciousnessVignette(float value)
	{

	}
};