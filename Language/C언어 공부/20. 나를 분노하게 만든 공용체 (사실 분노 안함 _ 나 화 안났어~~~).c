출처: https://dojang.io/mod/page/view.php?id=454

      *union : 결합, 동맹

-------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>    // strcpy 함수가 선언된 헤더 파일

union Box {    // 공용체 정의
    short candy;     // 2바이트
    float snack;     // 4바이트
    char doll[8];    // 8바이트
};

int main()
{
    union Box b1;   // 공용체 변수 선언

    printf("%d\n", sizeof(b1));  // 8: 공용체의 전체 크기는 가장 큰 자료형의 크기
    printf("%d\n", sizeof(b1.candy)); 
    printf("%d\n", sizeof(b1.snack));  
    printf("%d\n", sizeof(b1.doll));  
  
    strcpy(b1.doll, "bear");     // doll에 문자열 bear 복사

    printf("%d\n", b1.candy);    // 25954
    printf("%f\n", b1.snack);    // 4464428256607938511036928229376.000000
    printf("%s\n", b1.doll);     // bear
  
  ✅ 구조체와 달리 공용체는 멤버 중에서 가장 큰 자료형의 공간을 공유한다.
      따라서 어느 한 멤버에 값을 저장하면 나머지 멤버의 값은 사용할 수 없는 상태가 된다.
      
      아래와 같은 방법으로 정상적으로 사용이 가능하다.
  
  
  //-----------------------------------------------------------------------------------------------
  
    b1.candy = 10;
    printf("%d\n", b1.candy);    // 10: 사용(출력)

    b1.snack = 60000.0f;
    printf("%f\n", b1.snack);    // 60000.00000000: 사용(출력)

    strcpy(b1.doll, "bear");
    printf("%s\n", b1.doll);     // bear: 사용(출력)
  
                                            ✅ 만약 b1.candy, b1.snack, b1.doll을 구조체로 만들었다면 
                                                구조체의 전체 크기는 2 + 4 + 8 = 14바이트입니다(구조체 멤버 정렬이 되면 16바이트). 
                                                공용체로 멤버를 한 번에 하나씩만 쓰는 상황이라면 크기는 8바이트이므로 6바이트 이득입니다.

    return 0;
}



                              
