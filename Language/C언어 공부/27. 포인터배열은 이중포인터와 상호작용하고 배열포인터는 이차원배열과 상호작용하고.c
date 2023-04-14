#include <stdio.h>

int main()
{
		int a = 1;
	int b = 2;
	int c = 3;

	int** pp;    // 이중포인터 pp
	int* pa[3];    // 포인터배열 pa    

	pa[0] = &a;   // p + 0 = &a      pa[0] = *(p + 0) 그니까 애초에 pa[0]부터가 포인터이기 때문에 int* pa[3]은 이중포인터이다.
	pa[1] = &b;   // p + 1 = &b
	pa[2] = &c;   // p + 2 = &c

					// 내가 헷갈렸던건 이중포인터를 선언을 하지 않았는데 어떻게 **pa가 가능하지였다.
					// 그런데 계속해서 생각을 해보니까 애초에 pa[0] 자체가 포인터이다.
					// 따라서 pa[0]이 가지는 값은 &a(a의 주소값), 즉 *pa가 가지는 값이 &a인 것이다.
					// 결국 a의 값을 출력하기 위해서는 *pa가 가지는 주소값이 가리키는 값을 출력해야하는데
					// 그러기 위해서는 이중포인터를 활용하여 **pa을 사용해야한다.

					// 포인터배열에 주소값을 넣은 것 부터가 이중포인터임을 암시한다.

	printf("%d\n", *pa[0]);
	printf("%d\n", *(*(pa + 0)));
	printf("%d\n", **pa);

	printf("%d\n", *pa[1]);
	printf("%d\n", *(*(pa + 1)));

	printf("%d\n", *pa[2]);
	printf("%d\n", *(*(pa + 2)));

	pp = pa; // pa = &pa   

	         // 결국 위의 내용이 성립하기 때문에
	         // pp에 pa(pa는 그자체가 주소)를 대입을 해주면 
	         // 이중포인터인 pp를 포인터배열로써 활용이 가능한 것이다.

	printf("변수 a의 주소값: %p\n", &a);
	printf("pp[0]의 값은 a의 주소값: %p\n", pp[0]);
	printf("%d\n", *pp[0]);

	printf("변수 b의 주소값: %p\n", &b);
	printf("pp[1]의 값은 b의 주소값: %p\n", pp[1]);
	printf("%d\n", *pp[1]);

	printf("변수 c의 주소값: %p\n", &c);
	printf("pp[2]의 값은 c의 주소값: %p\n", pp[2]);
	printf("%d\n", *pp[2]);


	int value = 1000;
	int* pointer = &value;
	int** double_pointer = &pointer;

	printf("변수 value의 주소값: %p\n", &value);
	printf("포인터 변수 pointer의 값, 변수 value의 주소 값: %p\n", pointer);
	printf("포인터 변수 pointer의 주소 값: %p\n", &pointer);
	printf("double_pointer가 담고 있는 pointer의 주소 값: %p\n", double_pointer);
	printf("pointer변수가 담고 있는 value의 주소값이 출력됨: %p\n", *double_pointer);
	printf("이중포인터 double_pointer가 담고 있는 value의 값: %d\n", **double_pointer);

	printf("-------------------------------------------------------------\n\n\n");

	//----------------------------------------------------------------------------------

	int aa[3][3] = { 4,5,6,7,8,9,10,11,12 };    // 2차원 배열 aa
	int(*ppa)[3];  // 배열포인터 ppa

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\n", aa[i][j]);    // 2차원 배열 값 출력
		}
	}

	ppa = aa;     // 배열포인터 ppa에 2차원 배열 aa 대입

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\n", ppa[i][j]);   
		}
	}

	// 배열포인터와 이차원배열은 서로 상호작용이 가능하다.
	// 배열포인터 안에 이차원 배열의 시작 주소를 넣어주면 된다.

	// 배열포인터 ppa에 이차원배열의 aa의 값을 넣어준다.
	// 즉, 배열포인터 ppa에는 &aa[0], &aa[0][0]이 들어간 것과 동일하다.
        // 따라서 ppa[0][2]와 aa[0][2]는 이제 동일한 값을 지목한다.
	
	return 0;
}
