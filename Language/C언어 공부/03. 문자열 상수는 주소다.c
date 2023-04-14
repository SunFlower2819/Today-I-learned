#include <stdio.h>

int main()
{
	printf("apple이 저장된 시작 주소 값: %p\n", "apple");   // 00007FF741349C24 출력
	printf("두 번째 문자의 주소 값: %p\n", "apple" + 1);  // 00007FF741349C25 출력
	printf("첫 번째 문자: %c\n", *"apple");               // 'a' 출력
	printf("두 번째 문자: %c\n", *("apple" + 1));         // 'p' 출력
	printf("다섯 번째 문자: %c\n", "apple"[4]);           // 'e' 출력

	return 0;
}

--------------------------------------
	
#include <stdio.h>

int main()
{
	char* dessert = "apple";

	printf("오늘 후식은 %s 입니다. \n", dessert);
	dessert = "banana";                             // "banana"는 주소이므로 문자형 포인터 dessert에 대입이 가능하다.
	printf("내일 후식은 %s 입니다.\n", dessert);

	return 0;
}

 출력결과:  오늘 후식은 apple 입니다.
	    오늘 후식은 banana 입니다.
	 
	 
	 
	 
