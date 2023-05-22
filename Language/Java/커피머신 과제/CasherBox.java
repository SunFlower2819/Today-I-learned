package CoffeeMachine;

public class CasherBox 
{
//	String name;
	int balance;
	
	// 잔액을 추가할 때 마다 이 함수가 실행됨
	int addBalance(int k) 
	{
		System.out.println(k + "원이 투입되었습니다.");
		balance += k;
		return balance;
	}
	
	// 잔액보여줌 버튼 인터페이스에 계속 나와야함
	void showBalance() 
	{
		System.out.print("잔액 " + balance + "원");
	}
	
	// 만약 버튼에서 잔액반환(0)을 누르면 이 함수가 실행됨
	void ejectBalance()
	{
		System.out.println("잔액 " + balance + "원이 반환되었습니다.");
	}
}
