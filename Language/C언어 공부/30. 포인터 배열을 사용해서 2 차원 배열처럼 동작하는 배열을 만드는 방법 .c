#include <stdio.h>  
#include <stdlib.h> 

int main() 
{   
	// pp[3][4] 형태로 만들거임

	int** pp;

	pp = (int**)malloc(sizeof(int*) * 3); // 이중포인터 pp에 pp[0] pp[1] pp[2] 가 할당된 주소를 저장
	                //(int*)를 사용한 이유는 이중포인터에 저장되는 값 또한 포인터이기 때문이다.

	for (int i = 0; i < 3; i++)
	{
		pp[i] = (int*)malloc(sizeof(int) * 4);
		// pp[i]에 16바이트 만큼의 메모리를 할당하는 주소를 전달
	}

	// 1. 이중포인터 pp에 24바이트 만큼의 메모리 주소 전달(이중포인터로 캐스팅 했기에 주소값을 전달 받는 기능 가능)
	// 2. pp[i]에 16바이트 만큼의 메모리 주소 전달

	// pp -> pp[0], pp[1], pp[2]의 메모리 주소 --> pp[0][0] ~ -pp[2][3]의 메모리 주소

	// 이러한 형태를 이차원배열이라고 말하기는 힘들어보인다.
	// 선형적으로 pp[0][0] pp[0][1] ... pp[2][2] pp[2][3] 처럼 나열되어 있는 것이 아니다.
	// pp의 원소들이 가리키는 메모리 공간이 연속적으로 연달아 존재한다고 보장할 수가 없다.

	// 하지만 알다시피 [] 기호는 변수를 선언할 때를 제외하고는 포인터임을 의미한다.
	// 따라서 pp[1][3] 이러한 형태는 (pp가 이중포인터 변수라는 가정하에)
	// (*(*(pp + 3) + 1)으로 해석이 되기 때문에
	// 이중포인터를 이차원배열 형식으로 사용이 가능한 것이다.

	// 사실 어려운게 너무 없다.
	// 그냥 	pp = (int**)malloc(sizeof(int*) * 3); 
	// 여기에서 (int**)를 해주는건 pp 또한 이중포인터 형식이기에 그렇고
	// malloc 함수로 24바이트만큼의 확보된 메모리의 주소를 전달하여
	// pp가 그만큼의 이중포인터형식의 메모리공간을 사용이 가능한 것이다.

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pp[i][j] = i + j;
			printf("%d ", pp[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 3; i++)  // 당연히 메모리가 연속적으로 배정되어 있는 것이 아니므로
		free(pp[i]);             // 메모리를 할당한 부분을 각각 해제시켜줘야한다.

	free(pp);


	return 0;
}


 출력결과:
	    0 1 2 3
	    1 2 3 4
	    2 3 4 5
		    
		    
--------------------------------------------------------
		    
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** test;
	int subjects;
	int students;

	printf("과목의 수 : ");
	scanf("%d", &subjects);
	printf("학생 수 : ");
	scanf("%d", &students);

	test = (int**)malloc(sizeof(int*) * subjects);

	for (int i = 0; i < subjects; i++)
	{
		test[i] = (int*)malloc(sizeof(int) * students);
	}

	for (int i = 0; i < subjects; i++)
	{
		for (int j = 0; j < students; j++)
		{
			printf("%d 번째 과목에 대한 %d번 학생의 점수: ", i + 1, j + 1);
			scanf("%d", &test[i][j]);
		}
		printf("------------------------------------------\n");
	}

	int sum = 0;

	for (int i = 0; i < students; i++)
	{
		sum = 0;

		for (int j = 0; j < subjects; j++)
		{
			sum += test[j][i];
		}
		printf("%d 번쨰 학생의 평균 : %d\n", i + 1, sum / subjects);
	}

	for (int i = 0; i < subjects; i++)
		free(test[i]);
	
	free(test);

	return 0;
}
