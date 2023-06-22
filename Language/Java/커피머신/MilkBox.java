package 커피머신;
import java.awt.Container;

public class MilkBox extends Container {
	private int amount = 3; // 우유 재료량
	
	// 우유 재료 사용
	public boolean eject() {
		if(enoughAmount()) {
			amount--;
			return true;
		}
		else
			return false;
	}
	
	// 충분한 우유가 있는지 확인
	private boolean enoughAmount() {
		if(amount > 0)
			return true;
		else 
			return false;
	}
}