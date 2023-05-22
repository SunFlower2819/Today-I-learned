package CoffeeMachine;

abstract class Container 
{
	String name;
	int amount;
	
	abstract void eject();
	abstract boolean enoughAmount();
}