#include <stdio.h>
                         //배열의 크기는 변수로 지정할 수 없다
int main()
{
	int* arr[4];                // arr[0], arr[1], arr[2], arr[3] 각각 포인터 변수처럼 취급        
	int aa[3] = { 1,2,3 };
	int bb[5] = { 0 };
	int cc[6] = { 15,74,34,73 };
	int dd = 5434;

	arr[0] = aa;                  // arr[0] 은 aa를 가리킴
	arr[1] = bb;
	arr[2] = cc;
	arr[3] = &dd;                 // arr[3]은 dd의 주소 값을 가리킴

	for (int i = 0; i < 3; i++)
		printf("%d ", arr[0][i]);           // 1 2 3 출력

	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("%d ", arr[1][i]);          // 0 0 0 0 0 출력

	printf("\n");

	for (int i = 0; i < 6; i++)
		printf("%d ", arr[2][i]);           // 15 74 34 73 0 0 출력 
 
	printf("\n");

	printf("%d", *arr[3]);              // 5434 출력


	return 0;
}

--------------------------
  
#include <stdio.h>
                         //배열의 크기는 변수로 지정할 수 없다
int main()
{
	int (*arr)[4];                 // 배열 포인터 선언
	int aa[3] = { 1,2,3 };
	int bb[5] = { 0 };
	int cc[6] = { 15,74,34,73 };
	int dd = 5434;

	arr = aa;                     // arr에 aa 대입

	for (int i = 0; i < 3; i++)
		printf("%d ", arr[0][i]);

	printf("\n");

	arr = bb;

	for (int i = 0; i < 5; i++)
		printf("%d ", arr[0][i]);

	printf("\n");

	arr = cc;

	for (int i = 0; i < 6; i++)
		printf("%d ", arr[0][i]);

	printf("\n");

	arr = &dd;                   // arr에 &dd 대입

	printf("%d", *arr[0]);


	return 0;
}


--------------
  
#include <stdio.h>
                         //배열의 크기는 변수로 지정할 수 없다
int main()
{
	char* arr[2];
	char aa[6] = "Hello";
	char bb[4] = "ABC";

	arr[0] = aa;
	arr[1] = bb;

	printf("%s\n%s", arr[0], arr[1]);

	return 0;
}


----------------------------------------------------------------------------------------------------------------------------------------
	
	*배열 포인터를 활용한 5명의 학생들의 수학, 국어, 영어 성적의 평균을 구하고 전체 평균과 비교해주는 프로그램
	
#include <stdio.h>

void Input_scores(double(*score)[3]);
void cal_average(double(*average)[3]);

int main()
{
	double students[5][3];

	Input_scores(students);   // A,B,C,D,E 학생의 수국영 점수를 알아낸다.
	cal_average(students);    // A,B,C,D,E 학생의 수국영 점수의 평균을 알아낸다.

	return 0;
}

void Input_scores(double(*score)[3])
{
	for (int i = 0; i < 5; i++)
	{
		printf("%c 의 수학 점수 : ", 'A' + i);
		scanf("%lf", &score[i][0]);
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%c 의 국어 점수 : ", 'A' + i);
		scanf("%lf", &score[i][1]);
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%c 의 영어 점수 : ", 'A' + i);
		scanf("%lf", &score[i][2]);
	}
}

void cal_average(double(*average)[3])
{
	double A_average = 0;
	double B_average = 0;
	double C_average = 0;
	double D_average = 0;
	double E_average = 0;

	for (int i = 0; i < 3; i++)
	{
		A_average += average[0][i];
	}

	A_average = A_average / 3;
	
	for (int i = 0; i < 3; i++)
	{
		B_average += average[1][i];
	}

	B_average = B_average / 3;

	for (int i = 0; i < 3; i++)
	{
		C_average += average[2][i];
	}

	C_average = C_average / 3;

	for (int i = 0; i < 3; i++)
	{
		D_average += average[3][i];
	}

	D_average = D_average / 3;

	for (int i = 0; i < 3; i++)
	{
		E_average += average[4][i];
	}

	E_average = E_average / 3;

	printf("\nA의 평균: %.2lf\n", A_average);
	printf("B의 평균: %.2lf\n", B_average);
	printf("C의 평균: %.2lf\n", C_average);
	printf("D의 평균: %.2lf\n", D_average);
	printf("E의 평균: %.2lf\n\n", E_average);

	double ave = (A_average + B_average + C_average + D_average + E_average) / 5;

	printf("\n전체평균 : %.2lf\n", ave);

	if (A_average >= ave)
		printf("A 합격\n");
	else
		printf("A 불합격\n");

	if (B_average >= ave)
		printf("B 합격\n");
	else
		printf("B 불합격\n");

	if (C_average >= ave)
		printf("C 합격\n");
	else
		printf("C 불합격\n");

	if (D_average >= ave)
		printf("D 합격\n");
	else
		printf("D 불합격\n");

	if (E_average >= ave)
		printf("E 합격\n");
	else
		printf("E 불합격\n");
}
