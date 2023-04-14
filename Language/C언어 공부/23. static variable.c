        
 이 코드를 살펴보자..    
 
#include <stdio.h>

int* function() 
{
	int a = 5;
	return &a;
}

int main()
{
	int* pa = function();
	printf("%d \n", *pa);
}

                            우리는 이 코드에서 우리가 원하는 출력값인 5를 얻지 못한다. (가끔 얻을 수도..)
                              
                              하지만 결고 올바른 방식으로 짜여진 코드가 아니다.
                              
                            그 이유는 
                            
                                        int* function() 
                                        {
                                          int a = 5;
                                          return &a;
                                        }

                                           이 함수에서의 변수 a는 함수가 종료되는 순간 날라가버리기 때문에
                                           변수 a의 주소를 전달하는 건 아무런 의미가 없어지기 때문이다.
                                             
                              그러나 방법은 존재한다. 변수 a를 끝까지 유지시킬 수 있는 방법말이다.
                                            
                                      그건 바로 'static'을 사용하면 된다.
                                             
                      #include <stdio.h>

                      int* function() 
                      { 
                        static int a = 5;        // static 키워드 사용
                        return &a;
                      }

                      int main()
                      {
                        int* pa = function();
                        printf("%d \n", *pa);
                      }

                            static 키워드를 사용하여 선언된 변수는 자신이 선언된 범위를 벗어나더라도 절대로 파괴되지 않는다!!!
                              
                            이는 static 변수 a는 딱 프로그램이 실행되는 순간 딱 한 번만 초기화가 된다는 것을 의미한다.
                              
                            이 말이 무슨 뜻이냐고????????????
                              
                            다음 코드를 봐보자.

                  #include <stdio.h>

                  int* function() 
                  {
                    static int count = 0;
                    count++;
                    return &count;
                  }

                  int main()
                  {
                    int* pa = function();
                    printf("%d \n", *pa);    // 1 출력

                    pa = function();
                    printf("%d \n", *pa);    // 2 출력

                    pa = function();
                    printf("%d \n", *pa);    // 3 출력

                    pa = function();
                    printf("%d \n", *pa);    // 4 출력
                  }

                                이 코드를 보면 정적 변수 count가 함수가 선언될 때마다 매번 초기화 되는 것이 아니라
                                값이 항상 일정하다는 것을 알 수 있따.



