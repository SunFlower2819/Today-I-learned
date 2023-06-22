package 커피머신;

// 커피, 설탕, 우유 공통적으로 쓰이는 변수는 양에 관한 변수
// 그리고 꺼내기 메소드
// 꺼내기 메소드 안에 enoughAmount를 넣어서 참이면 true 아니면 false 반환

public abstract class Cotainer {
	int amount;
	abstract boolean eject();
	abstract boolean enoughAmount(); 
}
