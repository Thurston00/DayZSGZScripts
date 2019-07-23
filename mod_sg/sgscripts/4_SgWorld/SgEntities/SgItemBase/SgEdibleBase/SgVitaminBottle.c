modded class VitaminBottle
{
	override void OnConsume(float amount, PlayerBase consumer)
	{
		
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionFeedVitaminBottle);
		AddAction(ActionEatVitaminBottle);
	}
}