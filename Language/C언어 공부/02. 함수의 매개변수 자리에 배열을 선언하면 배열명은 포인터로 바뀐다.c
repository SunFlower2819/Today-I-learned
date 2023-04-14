#include <stdio.h>

void numbers(int num[5]);

int main()
{
	int ary[5] = { 1,2,3,4,5 };
	
	numbers(ary);

	return 0;
}

void numbers(int num[5])    // ==> void number(int *num)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d", *(num + i));  // 12345 출력
	}

	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		printf("%d", num[i]);   // 12345 출력
	}
}


