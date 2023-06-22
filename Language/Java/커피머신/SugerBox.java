package 커피머신;
import java.awt.Container;

public class SugerBox extends Container {
	private int amount = 5; // 설탕 재료량
	
	// 설탕 재료 사용
	public boolean eject() {
		if(enoughAmount()) {
			amount--;
			return true;
		}
		else
			return false;
	}
	
	// 충분한 설탕이 있는지 확인
	private boolean enoughAmount() {
		if(amount > 0)
			return true;
		else 
			return false;
	}
}
