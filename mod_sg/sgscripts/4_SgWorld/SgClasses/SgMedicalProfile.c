class MedicalProfile
{
	protected float m_PercentageHeal;
	
	void MedicalProfile(float percentageHeal)
	{
		m_PercentageHeal = percentageHeal;
	}
	
	float GetPercentageHeal()
	{
		return m_PercentageHeal;
	}
}