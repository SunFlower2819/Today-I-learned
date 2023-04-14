#include <stdio.h>

int func(int d, int f);

int main()
{
	int (*func_p)(int, int);  // 함수 포인터 func_p 선언

	printf("%d\n", func(5, 3));
   
	func_p = func;    // func 함수의 메모리 주소룰 func_p에 저장.

	printf("%d\n", func_p(1, 6));   // 7 출력

	return 0;
}

int func(int d, int f)  
{
	return d + f;
}


함수 포인터를 선언할 때는 함수 포인터와 저장될 함수의 반환값 자료형, 매개변수 자료형과 개수가 일치해야 한다.
  
  
#include <stdio.h>

void func()
{
	printf("Hello, this is pointer to function returning void\n");
}

int main()
{
	void (*func_p)();

	func_p = func;

	func_p();

	return 0;
}


------------------------------------------------------------------
	
	* 함수 포인터를 활용한 계산기 프로그램

#include <stdio.h>

int plus(int a, int b);
int minus(int a, int b);
int pro(int a, int b);
int div(int a, int b);
int rem(int a, int b);

int main()
{
	int a = 5, b = 3;
	char op;
	int (*func_cal)(int , int);

	printf("+ - * / %%  골라유: ");
	scanf("%c", &op);

	switch (op)
	{
	case '+':
		func_cal = plus; 
		printf("%d", func_cal(a, b));
		break;
	case '-':
		func_cal = minus; 
		printf("%d", func_cal(a, b));
		break;
	case '*':
		func_cal = pro;
		printf("%d", func_cal(a, b));
		break;
	case '/':
		func_cal = div; 
		printf("%d", func_cal(a, b));
		break;
	case '%':
		func_cal = rem; 
		printf("%d", func_cal(a, b));
		break;
	}

	return 0;
}

int plus(int a, int b)
{
	return a + b;
}

int minus(int a, int b)
{
	return a - b;
}

int pro(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}

int rem(int a, int b)
{
	return a % b;
}


 
