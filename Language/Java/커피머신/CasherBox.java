package 커피머신;

public class CasherBox {
	// 잔액
	private int balance;
	
	// 현금 투입
	public int addBalance(int k) {
		balance = balance + k;
		return balance;
	}
	
	// 잔액 반환
	public int ejectBalance() {
		return balance;
	}
}
