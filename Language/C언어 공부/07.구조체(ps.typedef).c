#include <stdio.h>
#include <string.h>

struct Person     // 구조체 정의
{
	int age;             // 구조체 멤버 1
	char address[100];   // 구조체 멤버 2
	char name[100];      // 구조체 멤버 3
};

int main()
{
	struct Person p1 = {.age = 5, .address = "경기도 부천시 중동", .name = "왕만두"};  // 이렇게 초기화가 가능하다.

	printf("나이 : %d\n주소 : %s\n이름 : %s\n\n", p1.age, p1.address, p1.name);

	p1.age = 23;
	strcpy(p1.address, "대전광역시 서구 도마동");
	strcpy(p1.name, "선태욱");

	printf("나이 : %d\n주소 : %s\n이름 : %s\n", p1.age, p1.address, p1.name);

	return 0;
}


------------------
  
 typedef를 활용하여 별칭 만들기  typedef ==> type define의 줄임말
 
#include <stdio.h>
#include <string.h>

typedef struct Person_not_soEasy
{
	int age;
	char address[100];
	char name[100];
}Person;        // 별칭 Person

int main()
{
	//struct Person_not_soEasy p1 = {.age = 5, .address = "경기도 부천시 중동", .name = "왕만두"};

	Person p1;  // struct를 안쓰고 별칭으로 구조체 변수 선언

	p1.age = 23; 
	strcpy(p1.address, "대전광역시 서구 도마동");
	strcpy(p1.name, "선태욱");

	printf("나이 : %d\n주소 : %s\n이름 : %s\n", p1.age, p1.address, p1.name);

	return 0;
}
------------------------
  
  int main()
{
	typedef int i;     // int를 i로 정의
	typedef int* p;    // int*를 p로 정의
  
	i hi = 3;     // i == int
	p hi_p = &hi;  // p == int*

	printf("%d\n", hi);
	printf("%d\n", *hi_p);

	return 0;
}



----------------------------
  
  #include <stdio.h>

struct Mapping
{
	int x;
	int y;
};

int main()
{
	struct Mapping map;

	map.x = 10;
	map.y = 20;

	printf("%d %d\n", map.x, map.y);

	return 0;
}

--
  
#include <stdio.h>

typedef struct Mapping
{
	int x;
	int y;
}Map;

int main()
{
	Map map;

	map.x = 10;
	map.y = 20;

	printf("%d %d\n", map.x, map.y);

	return 0;
}
