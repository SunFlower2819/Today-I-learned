package CoffeeMachine;

public class MilkBottle extends Container 
{

	MilkBottle()
	{
		this.name = "밀크 커피";
		this.amount = 1;
	}
	@Override
	void eject() 
	{
		this.amount -= 1;
		System.out.println("밀크커피가 나옵니다. 맛있게 드시기 바랍니다");
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
