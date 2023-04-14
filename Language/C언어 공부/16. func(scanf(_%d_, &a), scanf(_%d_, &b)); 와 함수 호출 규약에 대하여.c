---------------------------------
#include <stdio.h>

int func(int a, int b)
{
	return a + b;
}

int main()
{
	int a, b, sum;
	sum = func(scanf("%d", &a), scanf("%d", &b));     // 5와 3 입력

	printf("%d %d %d\n", a, b, sum);   // 3 5 2 출력
 
}

---------------------------------

       여기서 내가 발견한 이상한 점이 두 가지가 있다.
         
         
      1. 내가 생각한 sum의 값은 8 이었지만, sum의 값은 2 라는 것이다.
         
          사실 이 부분은 내가 잘못 생각한 것이다.
         
          func(scanf("%d", &a), scanf("%d", &b));   이 부분에서 a의 값을 입력해주고 b의 값을 입력해주더라도
          각각 값이 할당은 될지언정 func() 함수에 a와 b의 값을 매개변수로써 전달하라는 명령어는 될 수가 없기 때문이다.
         
          즉, scanf("%d", &a)을 통해 a에 값을 입력을 해줄 수는 있지만, 
          scanf() 함수는 서식 지정을 해서 키보드로부터 입력을 받고, 서식을 제대로 입력받은 횟수를
          반환값으로 반환하기 때문에 func() 함수의 매개변수에 1이 전달된 것이다.
            
          (변수에 값을 할당하는 기능을 하는 함수인 것과, 함수가 끝나고 어떤 값을 반환하는지는 별개의 역할이다.)
            
          이 말마따나 func(scanf("%d %d", &a, &b), scanf("%d", &b)); 이런식으로 코드를 수정할 경우에는
          
          scanf("%d %d", &a, &b) 에서 2를 반환하고
          scanf("%d", &b) 에서 1을 반환하기 때문에
          
          sum의 값은 3이 될 것이다.
         
       2. func(scanf("%d", &a), scanf("%d", &b)); 에서 5와 3을 입력했는데
          printf()에서는 3 5 순서로 출력이 된다는 것이다.
         
          이 말은 즉슨 인자 전달의 순서가 오른쪽 --> 왼쪽으로 진행된다는 것이다.
		  
          여기서 알아야 하는 것이 바로 함수 호출 규약(Calling Convention)이다. 

		  
         * 함수 호출 규약에 대한 설명이 있는 블로그 : https://blog.kimtae.xyz/7 
                                                 : https://blog.naver.com/PostView.naver?blogId=tjdghkgkdl&logNo=10117639381

         
      
