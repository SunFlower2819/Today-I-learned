package CoffeeMachine;

public class VendingMachine 
{
	public static void main(String[] args) 
	{
		CasherBox cb = new CasherBox();
		CasherBox cb2 = new CasherBox();
		CasherBox cb3 = new CasherBox();
		
		CoffeeBox black_coffee = new CoffeeBox();
		SugerBox suger_coffee = new SugerBox();
		MilkBottle milk_coffee = new MilkBottle();
		
		Button b1 = new Button(black_coffee, suger_coffee, milk_coffee);
		Button b2 = new Button(black_coffee, suger_coffee, milk_coffee);
		Button b3 = new Button(black_coffee, suger_coffee, milk_coffee);
		
		CoffeeInterface CI = new CoffeeInterface();
		
		CI.MachineUX(cb, b1, milk_coffee, suger_coffee, black_coffee);
		CI.MachineUX(cb2, b2, milk_coffee, suger_coffee, black_coffee);
		CI.MachineUX(cb3, b3, milk_coffee, suger_coffee, black_coffee);
		
		CI.scanner.close();
	}
}