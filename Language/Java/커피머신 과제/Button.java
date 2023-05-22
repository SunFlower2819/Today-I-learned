package CoffeeMachine;

public class Button 
{
	CoffeeBox bc;
	SugerBox sc;
	MilkBottle mc;
	
	Button(CoffeeBox bc, SugerBox sc, MilkBottle mc)
	{
		this.bc = bc;
		this.sc = sc;
		this.mc = mc;
	}
	
	void pushButton(CasherBox cash) 
	{
		// 밀크커피 버튼
		if(mc.enoughAmount() == false)
		{
			System.out.print("(x)밀크커피(3백원),");
		}
		else
		{
			if(cash.balance < 300)
				System.out.print("(-)밀크커피(3백원),");
			else
				System.out.print("(1)밀크커피(3백원),");
		}
		
		// 설탕커피 버튼
		if(sc.enoughAmount() == false)
		{
			System.out.print("(x)설탕커피(2백원),");
		}
		else
		{
			if(cash.balance < 200)
				System.out.print("(-)설탕커피(2백원),");
			else
				System.out.print("(2)설탕커피(2백원),");
		}
		
		// 블랙커피 버튼
		if(bc.enoughAmount() == false)
		{
			System.out.print("(x)블랙커피(1백원),");
		}
		else
		{
			if(cash.balance < 100)
				System.out.print("(-)블랙커피(1백원),");
			else
				System.out.print("(3)블랙커피(1백원),");
		}
		
		// 잔액반환
		if(cash.balance > 0)
			System.out.println("(0)잔액반환");
		else
			System.out.println("(-)잔액반환");
	}
}
