package 커피머신;
import java.awt.Container;

public class CoffeeBox extends Container {
	private int amount = 10; // 커피 재료량
	
	// 커피 재료 사용
	public boolean eject() {
		if(enoughAmount()) {
			amount--;
			return true;
		}
		else
			return false;
	}
	
	// 충분한 커피가 있는지 확인
	private boolean enoughAmount() {
		if(amount > 0)
			return true;
		else 
			return false;
	}
}
