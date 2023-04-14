#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int main()
{
	int funcNum = 1;
	int a = 5;
	int b = 3;
	int (*funcp)(int, int) = NULL;

	switch (funcNum)                      // switch 문을 활용하여 어떤 함수를 할당할 것인지 선택할 수 있다.
	{
	case 1: funcp = add; break;
	case 2: funcp = sub; break;
	}

	printf("%d", funcp(a, b));

	return 0;
}                 
  
                  이제 이 코드를 포인터 함수 배열 형식으로 바꾸어 보겠다 !!

#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int main()
{
	int a = 5;
	int b = 3;
	int (*funcp[2])(int, int);    // 함수의 포인터의 배열

	funcp[0] = add; 
	funcp[1] = sub;

	printf("%d\n", funcp[0](a, b));   // 8 출력
	printf("%d\n", funcp[1](a, b));   // 2 출력

	return 0;
}
