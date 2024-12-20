#include <stdio.h>

int main()
{
	char* str1 = "Hello World";
	char* str2 = "Hello World";
  
	printf("%p\n", str1);  // 00007FF76A2CAC20 출력
	printf("%p\n", str2);  // 00007FF76A2CAC20 출력
	 
	return 0;
}  

🎈🎈 위의 코드를 보면 포인터 변수 str1과 str2가 가리키는 주소가 같은걸 확인할 수 있다.
     이것이 뜻하는 의미는 포인터로 초기화를 하면 "Hello World"는 상수형으로 할당된다는 것이다.
  
     이를 바탕으로 아래 코드를 한번 봐보자.

-----------------------
  
#include <stdio.h>

int main()
{
	char* str1 = "Hello World";
	str1[0] = 'V'; // 오류          🎈🎈 여기서 오류가 생기는 이유는 "Hello World"는 상수형이기 때문이다.
	
	char str2[] = "Hello World";
	str2[0] = 'V'; // 성공          🎈🎈 배열은 배열의 원소를 변경할 수 있다.
	 
	return 0;
}                 ✅ 그니까 내가 이해하기론 "Hello World"는 주소 그 자체이다. 따라서 str1[0] = 'V'; 이런 행위는 
                      주소를 바꾸려는 행위와 마찬가지다. 따라서 이건 오류를 범하는 행위인 것이다.
-----------------------
  
  #include <stdio.h>

int main()
{ 
	char* str1 = "Hello World";    
	str1 = "Bye Bye"; // 성공       🎈🎈 포인터 변수는 가리키는 주소를 변경할 수 있음.
	
	char str2[] = "Hello World";
	str2 = "Bye Bye"; // 오류 발생   🎈🎈 str2는 포인터 상수처럼 작동하기 때문에 함부로 주소를 변경할 수 없음.
	                                      (Bye Bye는 주소임)
	return 0;
}


str2는 포인터 상수가 아니다! 물론 str2가 가리키는 주소를 변경할 수 없다는 점에서 포인터 상수처럼 작동하기는 한다.
하지만 배열 이름은 고정된 주소를 가진 메모리 블록의 시작주소를 나타내고, 
str2는 배열 이름으로, 배열의 주소는 컴파일 타임에 고정되기 때문에 str2에 다른 주소를 대입하려고 하면 컴파일 오류가 발생하는 것이다.

요약하자면,
str2와 같은 배열 이름은 포인터처럼 동작하지만, 포인터 상수는 아니다.
* 배열의 시작 주소는 고정되어 변경할 수 없다.
* 배열 이름은 메모리 위치와 크기를 컴파일러가 알고 있는 상수 표현식이다.

포인터 상수(int* const)는 포인터 자체가 상수로, 포인터가 가리키는 주소를 변경할 수 없다.
