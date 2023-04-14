#include <stdio.h>
                         //배열의 크기는 변수로 지정할 수 없다
int main()
{ 
	int a = 3;
	int b = 1;

	//int* const p = &a;         <-- const 는 포인터 변수 p를 지칭하므로 p = &b; 할시에 오류가 나오지만, *p = b와 같이 int* 값을 변경할 때는 오류가 발생하지 않는다.
	//*p = b;
  
	const int*  p = &a;    <-- const는 int*를 가리키므로 *p = b와 같이 *p의 값을 변경할 때는 오류를 발생시키지만, p = &b 처럼 포인터 변수 p의 값을 변경할 땐 오류가 발생하지 않는다.
	p = &b;

	printf("%d", *p);


	return 0;
}


---
	
	 *p[3]  ==> *(p + 3)
	
	 *3[p]  ==> *(3 + p)
	   
	                이므로 둘은 같다.
	
	
	
