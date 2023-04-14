      
                          😃 우선 구조체 포인터를 정리하기 전에 주석을 보면서 내가 헷갈렸던 부분을 봐보자.

#include <stdio.h>
#include <string.h>

struct books
{
	char name[30];
	char author[30];
	int borrowed;
};

int main()
{
	//struct books Boo;
	//printf("%p\n", Boo.name);           Boo.name은 배열이기 때문에 그 자체가 포인터 상수
	//printf("%p\n", &Boo.name);      
	//printf("%p\n", Boo.author);         위와 동일
	//printf("%p\n", &Boo.author);
	//printf("%d\n", Boo.borrowed);       Boo.borrowed는 정수값이기 때문에 주소 값이 따로 있음
	//printf("%d\n", &Boo.borrowed);

	struct books Books[3] = { 0 };
	
	for (int i = 0; i < 3; i++)
	{
		printf("책 등록: 제목, 저자 입력 : ");
		scanf("%s %s", Books[i].name, Books[i].author);  //	scanf("%s %s", &Books[i].name, &Books[i].author); 이것도 작동되는 이유는? name과 author 자체가 포인터 상수임
		Books[i].borrowed = 0;
	}

	printf("---------------------------------------------\n");

	for (int i = 0; i < 3; i++)
	{
		printf("책 제목 : %s\n", Books[i].name);
		printf("책 저자 : %s\n", Books[i].author);
		
		if (Books[i].borrowed == 0)
		{
			printf("대출여부 : 가능\n");
		}
		else
		{
			printf("대출여부 : 불가능\n");
		}
		printf("---------------------------------------------\n");
	}

	return 0;
}

--------------------------------------------------------------------------------------
   
             구조체 포인터다.
   
  
#include <stdio.h>

struct test
{
	int a, b;
};

int main()
{
	struct test st;
	struct test* ptr;   // struct test 는 int,double,char과 같은 자료형이라고 생각하면 된다. (ㄹㅇ이렇게 생각하면 쉽다)

	ptr = &st;

	(*ptr).a = 1;
  ptr->a = 5;        // 위와 동일
  
	(*ptr).b = 2;
	ptr->b = 3;        // 위와 동일

	printf("%d\n%d\n", (*ptr).a, (*ptr).b);

	return 0;
}

-------------------------------------실-------(검증된)-------험-----------------------------------
* 실험 1.

#include <stdio.h>

struct test1
{
	int a, b;
};

int letsdoit(struct test1* pt)
{
	pt->a = 50;
	pt->b = 33;
	return (*pt).a + (*pt).b;
}

int main()
{
	struct test1 t1;

	printf("%d", letsdoit(&t1));
	return 0;
}




------------------------------------------------------------------------
* 실험 2.
	
#include <stdio.h>

struct test1
{
	int a, b;

	struct test2
	{
		int c, d;
	};
};


int main()
{
	struct test1 t1;
	struct test2 t2;

	t1.a = 5;
	t1.b = 2;
	t1.c = 3;
	t1.d = 4;

	//t2.a = 5;      당연히 
	//t2.b = 2;
	t2.c = 50;
	t2.d = 30;

	printf("%d\n", t1.a);
	printf("%d\n", t1.b);
	printf("%d\n", t1.c);
	printf("%d\n", t1.d);
	printf("%d\n", t2.c);
	printf("%d\n", t2.d);

	return 0;
}

------------------------------------------------
* 실험 3.
	
#include <stdio.h>

struct test
{
	int a;
	int b;
	int* p;
};

int main()
{
	struct test t1;
	int i = 100;

	t1.a = 500;
	t1.b = 400;
	t1.p = &i;
	*t1.p = 5;

	printf("%d %d %d\n", t1.a, t1.b, *t1.p);




	struct test* tp;
	tp = &t1;

	tp->a = 5;  //(*tp).a = 5;
	tp->b = 3;
	//*tp->p = i; // *(*tp).p = i;   이러면 안되지 *p에는 우선적으로 값을 참조하는 주소 값이 들어가야하는 데 값 부터 넣어버리면 당연히 안되지
	tp->p = &i;

	printf("%d\n", t1.a);
	printf("%d\n", t1.b);
	printf("%d\n", *t1.p);
	printf("%d\n", (*tp).a);
	printf("%d\n", (*tp).b);
	printf("%d\n", *(*tp).p);

	return 0;
}

 -------------------------------------------------
* 실험 4.
	 
#include <stdio.h>

int add(int* p);

struct test
{
	int a;
};

int main()
{
	struct test t;
	struct test* tp;

	t.a = 100;

	printf("%d\n", add(&t.a));

	tp = &t;

	//tp->a = 5; //(*tp).a = 5;       tp.a == &t.a 가 아닌가??    -->   tp는 &t가 맞을 수 있겠지만, tp.a 는 &t.a가 될 수 없다. tp는 구조체 변수가 아니기 때문이다.
	                                                                   따라서 구조체 변수를 가리키는 &(*tp).a가 맞는 표현이다.  ㅡ3ㅡ;

	printf("%d\n", add(&tp->a));  // 왜 tp.a 는 안되고, &(*tp).a는 될까 (혹은 &tp->a)
 
	return 0;                        --> 그 이유는 tp는 절대로 구조체 변수가 아니라 그저 포인터에 불과하기 때문이다.
}                                            .a의 왼쪽에는 구조체 형식이 와야한다.

int add(int* p)
{
	return ++*p;
}

---------------------------------------------------------
* 실험 5.
	
#include <stdio.h>
#include <string.h>

void information(struct Test* growing);

struct Test
{
	int age;
	double tall;
	char name[30];
};

int main()
{
	struct Test itsMe;

	itsMe.age = 3;
	itsMe.tall = 50.52;
	strcpy(itsMe.name, "어린 선태욱");

	printf("나이 : %d\n키 : %.2lf\n이름 : %s\n", itsMe.age, itsMe.tall, itsMe.name);

	information(&itsMe);
	printf("\n그렇게 20년 후..\n\n");

	printf("나이 : %d\n키 : %.1lf\n이름 : %s\n", itsMe.age, itsMe.tall, itsMe.name);

	return 0;
}

void information(struct Test* growing)
{
	growing->age = 23;
	growing->tall = 171.3;
	strcpy(growing->name, "성인 선태욱");
}

----------------------------------------------------------------------




