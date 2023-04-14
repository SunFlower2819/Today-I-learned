#include <stdio.h>

#define ary 10

int main()
{
	int aa[ary] = { 0 };                <--- 이렇게 사용 가능

	for (int i = 0; i < 10; i++)
		printf("%d\n", aa[i]);

	return 0;
}


                        #define 매크로이름 값 
