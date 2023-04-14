#include <stdio.h>

int main() {
	int a = 5;
	int b = 3;
	printf("%p\n%p", &a, &b);

	int temp = &a;
	&b = &temp;                   // 오류발생!!!!!!!! 안돼여 ㅇ ㅏㄴ된다.. 안되어여 ㅇ난도 
	&a = &b;
	printf("%p\n%p", &a, &b);

	return 0;  
}

