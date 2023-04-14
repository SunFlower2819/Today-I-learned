
*enumeration : 열거

*열거 : 여러가지 예나 사실을 낱낱이 죽 늘어 놓음.
	
      
	
      참고로 열겨형은 정수형 상수에 이름을 붙이는 기능을 한다.

-----------------------------------

#include <stdio.h>

enum { A, B, C, D };  // 순서대로 A = 0, B = 1, C = 2, D = 3 이다

int main()
{
	int a = D;          // 열겨형을 사용하면 이런식으로 활용 가능.

	printf("%d", a);   // 3 출력

	return 0;
}

-----------------------------------
  
#include <stdio.h>

enum { A = 3, B, C = 9, D };  // 순서대로 A = 3, B = 4, C = 9, D = 10 이다.   이렇게 갑 지정 가능

int main()
{
	int a = B;          // 열겨형을 사용하면 이런식으로 활용 가능.

	printf("%d", a);   // 4 출력

	return 0;
}



사실 열겨형을 사용하지 않고 상수를 활용하여 값을 고정시킬 수도 있다.
  
  예를 들어
  
#include <stdio.h>

const int A = 0;
const int B = 1;
const int C = 2;
const int D = 3;

int main()
{
	int a = D;

	printf("%d", a);  // 3 출력

	return 0;
}                                            이런 식으로 말이다.
                                             하지만
                                             이렇게 많은 상수를 지정하기에는 값이 너무 많고
                                             너무 귀찮다.
                                             그렇기에 열거형을 사용하면 좋은 것이다.
