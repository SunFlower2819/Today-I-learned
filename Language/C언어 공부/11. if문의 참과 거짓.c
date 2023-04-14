#include <stdio.h>

int main() {
	int a;
	printf("0은 거짓, 나머지는 다 참 : ");
	scanf("%d", &a);

	if (a)
		printf("참\n");
	else
		printf("거짓\n");

	return 0;
} 
                                 왜 이부분을 제대로 알고 있지 못했지..???????
                                   
                                 0이 거짓이고 나머지 정수 값은 참을 가진다는 건 알고 있었지만
                                 if문이 이런식으로 참과 거짓을 통해 작동한다는 것을 생각하지 못했다.
                                   


#include <stdio.h>
int isdigit(char c);  // c 가 숫자인지 아닌지 판별하는 함수
int main() {
    char input;

    scanf("%c", &input);

    if (isdigit(input)) {
        printf("%c 는 숫자 입니다 \n", input);
    }
    else {
        printf("%c 는 숫자가 아닙니다 \n", input);
    }

    return 0;
}
int isdigit(char c) {             
    if (48 <= c && c <= 57) {
        return 1;             <-- c가 숫자면 1, 즉 참을 반환
    }
    else
        return 0;            <-- c가 숫자가 아니면 0, 즉 거짓을 반환
}
             
                            
                                          코드 출처: https://modoocode.com/27
