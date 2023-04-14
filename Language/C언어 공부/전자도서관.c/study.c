#include <stdio.h>
#include <string.h>
#include "libraryFunc.h"

int main()
{
	struct library Books[100];

	int choice = 0;
	int bookNum = 0;  // 책 번호 (Books[0], Books[1], etc...)

	while (1)
	{
		printf("1.새로운 책 등록\n");
		printf("2.책 검색\n");
		printf("3.책 대출 혹은 반납\n4.전자 도서관 종료(1,2,3,4를 제외한 아무 숫자 입력)\n무엇을 도와드릴까요? : ");

		scanf("%d", &choice);

		printf("\n");

		if (choice == 1)
		{
			// 책 등록 (제목, 저자, 출판사, 빌린여부)
			book_register(Books, &bookNum);
		}
		else if (choice == 2)
		{
			// 책 검색, 대출  (제목, 저자, 출판사 검색) 그리고 대출 여부, 가능하면 대출가능하다고 띄우기
			book_search(Books);
		}
		else if (choice == 3)
		{
			// 책 반납
			book_return(Books, &bookNum);
		}
		else
		{
			printf("전자 도서관을 종료합니다.\n");
			return 0;
		}

		printf("\n");
	}
}