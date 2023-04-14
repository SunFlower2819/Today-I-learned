
#include <stdio.h>
#include <stdlib.h>   // malloc을 쓰기 위한 라이브러리
 
int main()
{
	int* arr;
	int size;

	printf("할당할 메모리의 크기 : ");
	scanf("%d", &size);

	arr = (int*)malloc(sizeof(int) * size);   // size에 5를 입력한다면 20바이트만큼의 메모리 공간을 할당함
	    
	 // 인자로 전달된 크기 만큼의 메모리를 할당 한 후에, 그 메모리의 시작 주소값을 리턴한다.

                                                          ✅ 내가 헷갈린건 "20바이트를 포인터 변수인 arr에 어떻게 넣어주지?"였다.
                                                             근데 생각해보니 포인터 변수는 주소값을 받아야한다.
                                                             결국 malloc 함수는 20바이트짜리 공간을 할당한 후에 그 메모리의 주소를 arr에 넣어주는거였다.

	for (int i = 0; i < 5; i++)   // size에 5 미만의 숫자를 입력하면 경고가 뜬다.
	{                             
		arr[i] = i;
		printf("%d\n", arr[i]);
	}

	printf("할당완료!\n");

	free(arr);   // 할당한 메모리는 반드시 free로 해제해줘야한다.
	

	return 0;
}


--------------------------------------------
  
    따로 추가.  코드출처: https://modoocode.com/243
  
#include <stdio.h>  /* printf, scanf, NULL */
#include <stdlib.h> // malloc, free, exit, rand 추가

int main() 
{
	int i, n;
	char* buffer;

	printf("How long do you want the string? ");
	scanf("%d", &i);

	buffer = (char*)malloc(i + 1);   // '\0'을 위해 +1 을 해줌

	if (buffer == NULL) exit(1);   // exit(1)은 강제종료을 함

	for (n = 0; n < i; n++) 
		buffer[n] = rand() % 26 + 'a';  // 0 ~ 26까지 랜덤으로 숫자 설정 
	                                    // + 'a'를 함으로써 a ~ z 까지의 문자을 얻을 수 있음.
	buffer[i] = '\0';

	printf("Random string: %s\n", buffer);
	free(buffer);

	return 0;
}
