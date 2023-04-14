             
               잘 정리되어 있는 내가 참고한 블로그 : https://blog.naver.com/speciallive/98372211

#include <stdio.h>

int main()
{
	int i = 5;
	int aa[i];

	return 0;
}
                    왜 배열을 이렇게 선언해줄 수 없을까????

               그건 바로 변수 i와 배열 aa가 메모리에 할당되는 순간이 서로 다르기 때문이다.
                      
               배열 aa는 스택과 데이터 영역에 할당되는데,
               aa에 대한 메모리의 크기는 컴파일 타임(컴파일 되는 동안)에
               결정이 되어야 한다.
                 
               이와 반대로 
               
               int i = 5;에서 변수 i가 5로 초기화되는 것은
               컴파일되는 순간이 아닌, 런타임(실행되는 동안)에 결정된다.
                 
               결국엔 배열 aa가 메모리의 크기에 맞게 할당되어야 하는 순간은
               컴파일이 되는 동안이지만,
               변수 i가 초기화 되는 순간은 컴파일이 된 후 실행되는 순간이기 때문에
               
               위의 코드 처럼 배열을 변수로 선언할 수 없는 것이다.
