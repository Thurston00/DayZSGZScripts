class SG_Antidote: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(SgActionInjectAntidoteSelf);
	}
};
