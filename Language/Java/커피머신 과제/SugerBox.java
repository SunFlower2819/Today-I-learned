package CoffeeMachine;

public class SugerBox extends Container
{
	SugerBox()
	{
		this.name = "설탕 커피";
		this.amount = 3;
	}
	@Override
	void eject() 
	{
		this.amount -= 1;
		System.out.println("설탕커피가 나옵니다. 맛있게 드시기 바랍니다");
	}

	@Override
	boolean enoughAmount() 
	{
		if(this.amount == 0) 
		{
			return false;
		}
		else
			return true;
	}
}
