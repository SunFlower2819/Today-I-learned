
* 지역변수
 
   지역 변수와 자동 변수(auto variable)는 같은 용어이다.
   본래 auto 예약어와 함계 함수 안에 지역 변수를 선언한다.
   auto 예약어는 생략할 수 있으며 이 경우 함수 안에 선언된 변수는 자동으로 지역 변수가 된다.

 특징 1. 지역 변수는 사용 범위가 블록 내부로 제한되므로 다른 함수에서는 사용할 수 없다.
  
#include <stdio.h>

void assign(void);

int main()
{
	auto int a = 0;

	assign();
	printf("main 함수 a: %d\n", a);

	return 0;
}

void assign(void)
{
	int a;                              // auto 생략
	
	a = 10;
	printf("assign 함수 a: %d\n", a);
}



 특징 2. 지역 변수는 이름이 같아도 선언된 함수가 다르면 각각 독립된 저장 공간을 갖는다.
   
   --> 함수에 선언된 변수 a는 이름만 같을 뿐 메모리에 별도의 저장 공간을 갖는다.
       따라서 assign 함수가 호출된 이후에도 main 함수에 있는 a의 값은 바뀌지 않는다.
   
      주의할 점.
       ==> 지역 변수가 할당된 저장 공간은 자동으로 초기화되지 않으므로 쓰레기 값이 사용되지 않도록 주의해야 한다.
   
#include <stdio.h>

int main()
{
	int a = 3, b = 5;
   
	{
		int a = 5, b = 3;
		printf("%d %d\n", a, b);         // 5 3 출력
	}

	printf("%d %d", a, b);           // 3 5 출력

	return 0;
}

-----------------------------------------------------
  
* 전역 변수

#include <stdio.h>

void assign10(void);
void assign20(void);

int a;     // 전역 변수는 특별한 값으로 초기화 하지 않아도 0으로 자동 초기화된다.

int main()
{
	printf("함수 호출 전 a 값 : %d\n", a);

	assign10();
	assign20();

	printf("함수 호출 후 a 값 : %d\n", a);

	return 0;
}

void assign10(void)
{
	a = 20;
}

void assign20(void)
{
	int a = 50;
}

      출력결과:
		함수 호출 전 a 값 : 0
		함수 호출 후 a 값 : 20
----------------------------------------------
			
* 정적 지역 변수

  --> 정적 지역 변수의 저장 공간은 프로그램이 실행되는 동안 계속 유지된다.

#include <stdio.h>

void auto_func();
void static_func();

int main()
{
	printf("일반 지역 변수(auto)를 사용하는 함수 \n");
	for (int i = 0; i < 3; i++)
	{
		auto_func();
	}

	printf("정적 지역 변수(static)를 사용하는 함수 \n");
	for (int i = 0; i < 3; i++)
	{
		static_func();
	}

	return 0;
}

void auto_func()
{
	auto int a = 0;

	a++;
	printf("%d\n", a);    // 1 1 1 출력
}

void static_func()
{
	static int a;   // 정적 지역 변수는 초기화하지 않으면 0으로 자동 초기화된다.

	a++;
	printf("%d\n", a);   // 1 2 3 출력
}

------------------------------------------------
	
* 레지스터 변수(register variable)
	 
     --> 레지스터 변수는 CPU 안에 있는 저장 공간인 레지스터를 사용한다.
	 레지스터는 CPU 안에 있어 데이터 처리 속도가 가장 빠른 저장 공간이다.
	
         메인 메모리에 있는 일반 변수의 값은 레지스터로 옮긴 후에 연산 장치에 사용된다.
         따라서 레지스터에 값을 저장하면 메인 메모리에 접근하는 시간을 줄일 수 있다.
	
	 주의1. 전역 변수는 레지스터 변수로 선언할 수 없다.
	
	     --> 전역 변수는 프로그램을 실행하는 동안 계속 저장 공간을 확보해야 하므로 CPU의 자원을 잠깐 빌려오는 레지스터 변수는
	         전역 변수로 선언할 수 없다.
	
	 주의2. 레지스터 변수는 주소를 구할 수 없다.
	
	     --> 레지스터 변수는 저장 공간이 메모리에 있는 것이 아니므로 주소 연산자를 써서 주소를 구할 수 없다.

#include <stdio.h>

int main()
{
	register int i;    // 레지스터 변수
	auto int sum = 0;
	
	for (i = 1; i <= 10000; i++)
		sum += i;

	printf("%d\n", sum);
	
	return 0;
}















