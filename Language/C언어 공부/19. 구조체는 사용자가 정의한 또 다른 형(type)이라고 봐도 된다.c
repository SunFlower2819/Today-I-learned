#include <stdio.h>

struct employee
{
	int age;
	int salary;
};

struct company
{ 
	struct employee data;       // struct employee 형을 가진 변수 data
	char name[30];
};

int main()
{
	struct company person1;   // struct company 형을 가진 변수 person1

	person1.data.age = 35;
	person1.data.salary = 300000000;
	strcpy(person1.name, "선태욱");

	printf("%d\n", person1.data.age);
	printf("%d$\n", person1.data.salary);
	printf("%s\n", person1.name);

	return 0;
}

---------------------------------------------------------------------------------------------------------------------------------
  
	
	
	
        그냥 잊어도 될 듯하다. 
	
	https://hashcode.co.kr/questions/17059/c%EC%96%B8%EC%96%B4-%EA%B5%AC%EC%A1%B0%EC%B2%B4%EC%97%90-%EA%B4%80%ED%95%9C-%EC%A7%88%EB%AC%B8

        그렇다고 한다.
	
	
	
#include <stdio.h>

struct test thisisFunction(int a);

struct test
{
	int a;
};

int main()
{
	struct test num;

	num.a = 5;

	num = thisisFunction(num.a);

	printf("%d\n", num);        // Q. 어떻게 num을 출력한 값도 10이 나오는 걸까..??
	printf("%d\n", num.a);

	return 0;
}

struct test thisisFunction(int a)
{
	struct test funcnum;
	funcnum.a = a + 5;

	return funcnum;       // funcnum.a 의 자료형은 int형이기 때문에 반환이 불가.(함수의 반환형과 다르기 떄문이다.)
} 
  
  
  위의 질문에 대한 실험
  
#include <stdio.h>

struct test
{
	//int a;
	//int c;
	double b;
	double f;
};

int main()
{
	struct test num;

	/*num.a = 5;
	printf("%d\n", num);
	printf("%d\n", num.a);

	num.c = 10;
	printf("%d\n", num);
	printf("%d\n", num.c);*/

	num.b = 3.14;
	printf("%d\n", num);
	printf("%lf\n", num.b);

	num.f = 4.51;
	printf("%d\n", num);
	printf("%lf\n", num.f);

	return 0;
}

  
  



