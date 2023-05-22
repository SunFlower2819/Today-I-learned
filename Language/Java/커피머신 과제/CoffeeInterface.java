package CoffeeMachine;
import java.util.Scanner;

public class CoffeeInterface 
{
	Scanner scanner = new Scanner(System.in);
	
	void MachineUX(CasherBox cb, Button b, MilkBottle milk_coffee, SugerBox suger_coffee, CoffeeBox black_coffee) 
	{
		
		System.out.println("안녕하세요. 커피자판기를 이용해 주셔서 감사합니다");

		int choice = -1;
		while(choice != 0)
		{
			b.pushButton(cb);
			System.out.print("동전 또는 지폐를 투입해 주세요: ");
			cb.showBalance();
			System.out.print(" >> ");
			
			choice = scanner.nextInt();
			if(choice == 0)
			{
				if(cb.balance > 0) 
					cb.ejectBalance();
				else
					System.out.println("반환할 잔액이 없습니다. 안녕히 가세요.");
			}
			else if(choice == 1)
			{
				if(milk_coffee.enoughAmount())
				{
					if(cb.balance < 300)
					{
						System.out.println("잔액이 부족합니다.");
					}
					else
					{
						milk_coffee.eject();
						cb.balance -= 300;
					}
				}
				else
				{
					System.out.println("재료(밀크)가 부족합니다. 죄송하지만 다음에 이용 부탁 드립니다.");
					cb.ejectBalance();
					System.out.print('\n');
					break;
				}
					
			}
			else if(choice == 2)
			{
				if(suger_coffee.enoughAmount())
				{
					if(cb.balance < 200)
					{
						System.out.println("잔액이 부족합니다.");
					} 
					else
					{
						suger_coffee.eject();
						cb.balance -= 200;
					}
				}
				else
				{
					System.out.println("재료(설탕)가 부족합니다. 죄송하지만 다음에 이용 부탁 드립니다.");
					cb.ejectBalance();
					System.out.print('\n');
					break;
				}
					
			}
			else if(choice == 3)
			{
				if(black_coffee.enoughAmount())
				{
					if(cb.balance < 100) 
					{
						System.out.println("잔액이 부족합니다.");
					}
					else 
					{
						black_coffee.eject();
						cb.balance -= 100;
					}
				}
				else
				{
					System.out.println("재료(커피)가 부족합니다. 죄송하지만 다음에 이용 부탁 드립니다.");
					cb.ejectBalance();
					System.out.print('\n');
					break;
				}
			}
			else
				cb.addBalance(choice);
			System.out.print('\n');
		}
	}
}
