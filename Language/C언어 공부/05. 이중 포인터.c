#include <stdio.h>

int main() {
	int a = 5;
	int* p = &a;
	int** pp = &p;   // **pp는 p의 주소가 가리키는 값을 가리킨다. *pp는 p의 값을 가리킨다.

	printf("a의 값: %d, *p의 값: %d, **pp의 값: %d\n\n", a, *p, **pp);
	printf("a의 주소값: %p, p의 값: %p, *pp의 값: %p\n\n", &a, p, *pp);
	printf("p의 주소값: %p, pp의 값: %p\n", &p, pp);
}

출력결과 :
		a의 값: 5, *p의 값: 5, **pp의 값: 5

		a의 주소값: 00000051E68FF7D4, p의 값: 00000051E68FF7D4, *pp의 값: 00000051E68FF7D4

		p의 주소값: 00000051E68FF7F8, pp의 값: 00000051E68FF7F8

------------------------
int main()
{
	int a = 5;
	int* ap = &a;
	int** app = &ap;

	printf("%d\n", a);    // a의 값 5출력
	printf("%d\n", *ap);  // a의 주소 값이 가르키는 값 5출력
	printf("%d\n", **app);  // ap의 값(변수 a의 주소)가 가르키는 a의 값 5 출력

	return 0;
}

int main()
{
	int a = 5;
	int* ap = &a;
	int* app = &ap;

	printf("%d\n", a);
	printf("%d\n", *ap);
	printf("%d\n", *app);    // 이렇게 하면 ap의 값이 출력(a의 주소)

	return 0;
}

-------------------------------
	
#include <stdio.h>

int pswap(int** pa, int** pb);

int main() {
	int a, b;
	int* pa, * pb;

	pa = &a;   // pa에 a의 주소값
	pb = &b;   // pb에 b의 주소값

	printf("pa 가 가리키는 변수의 주소값 : %p \n", pa);   // a의 주소
	printf("pa 의 주소값 : %p \n \n", &pa);             // pa의 주소
	printf("pb 가 가리키는 변수의 주소값 : %p \n", pb);   // b의 주소
	printf("pb 의 주소값 : %p \n", &pb);         // pb의 주소
	printf(" a 의 주소값 : %p \n", &a);
	printf(" b 의 주소값 : %p \n", &b);

	printf("\n ------------- 호출 -------------- \n");
	pswap(&pa, &pb);
	printf("\n ------------- 호출끝 -------------- \n");

	printf("pa 가 가리키는 변수의 주소값 : %p \n", pa);   // b의 주소값
	printf("pa 의 주소값 : %p \n \n", &pa);  // 그대로 pa의 주소
	printf("pb 가 가리키는 변수의 주소값 : %p \n", pb);   // a의 주소값
	printf("pb 의 주소값 : %p \n", &pb);     // 그대로 pb의 주소
	printf(" a 의 주소값 : %p \n", &a);
	printf(" b 의 주소값 : %p \n", &b);

	return 0;  
}

int pswap(int** ppa, int** ppb) {
	int* temp = *ppa;   // *ppa는 pa의 값(a의 주소)

	printf("ppa 가 가리키는 변수의 주소값 : %p \n", ppa);  // pa의 주소
	printf("ppb 가 가리키는 변수의 주소값 : %p \n", ppb);  // pb의 주소

	*ppa = *ppb;   // *ppa에 pb의 값(b의 주소), *ppb에 pa의 값(a의 주소)
	*ppb = temp;

	return 0;
}

  출력결과: 
		pa 가 가리키는 변수의 주소값 : 0000004E65FDFCA4
		pa 의 주소값 : 0000004E65FDFCE8

		pb 가 가리키는 변수의 주소값 : 0000004E65FDFCC4
		pb 의 주소값 : 0000004E65FDFD08
		 a 의 주소값 : 0000004E65FDFCA4
		 b 의 주소값 : 0000004E65FDFCC4
		 
		 ------------- 호출 --------------
		ppa 가 가리키는 변수의 주소값 : 0000004E65FDFCE8
		ppb 가 가리키는 변수의 주소값 : 0000004E65FDFD08
		 ------------- 호출끝 --------------
			
		pa 가 가리키는 변수의 주소값 : 0000004E65FDFCC4
		pa 의 주소값 : 0000004E65FDFCE8

		pb 가 가리키는 변수의 주소값 : 0000004E65FDFCA4
		pb 의 주소값 : 0000004E65FDFD08
		 a 의 주소값 : 0000004E65FDFCA4
		 b 의 주소값 : 0000004E65FDFCC4
		 
		 
