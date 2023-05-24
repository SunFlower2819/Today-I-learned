package CoffeeMachine;

public class VendingMachine 
{
	public static void main(String[] args) 
	{
		CoffeeInterface CI = new CoffeeInterface();
		
		CasherBox cb = new CasherBox();
		CasherBox cb2 = new CasherBox();
		CasherBox cb3 = new CasherBox();
		
		CoffeeBox black_coffee = new CoffeeBox();
		SugerBox suger_coffee = new SugerBox();
		MilkBottle milk_coffee = new MilkBottle();
		
		Button b = new Button(black_coffee, suger_coffee, milk_coffee);
		
		CI.MachineUX(cb, b, milk_coffee, suger_coffee, black_coffee);
		CI.MachineUX(cb2, b, milk_coffee, suger_coffee, black_coffee);
		CI.MachineUX(cb3, b, milk_coffee, suger_coffee, black_coffee);
		
		CI.scanner.close();
	}
}
