package CoffeeMachine;

public class CoffeeBox extends Container
{
	CoffeeBox() 
	{
		this.name = "블랙 커피";
		this.amount = 10;
	}
	
	@Override
	void eject() 
	{
		this.amount -= 1;
		System.out.println("블랙커피가 나옵니다. 맛있게 드시기 바랍니다");
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