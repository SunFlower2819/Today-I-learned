

#include <stdio.h>

int main()
{
	void a;         // 오류 발생 a에 얼마만큼의 메모리를 할당하는지 모름

	return 0;
}


그렇다면 그렇다면 그렇다면 그렇다면 그렇다면 그렇다면 그렇다면 그렇다면 그렇다면 그렇다면 그렇다면 그렇다면 


#include <stdio.h>

int main()
{
	void *a;       // void* 형은 포인터이기 때문에 메모리 상에 8바이트만큼 지정해둠.

	return 0;
}

            하지만
            
#include <stdio.h>

int main()
{
	void *a;
	int b;
	a = &b;

	printf("%d", *a);     // 오류발생

	return 0;
}                              --> 변수 a을 메모리에서 얼마만큼 할당해야하는지에 대해 알 수 없으므로 오류

                       따라서 void* 형에는 온전히 주소만 보관한다.
              
              
              

            
