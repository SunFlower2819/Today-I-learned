문제 출처: https://modoocode.com/60  

#include <stdio.h>
#include <string.h>

void book_register(struct library* regiBook, int* bookNum);
void book_search(struct library* searchBook);
void book_return(struct library* returnBook, int* bookNum);


struct library
{
	char bookName[30];
	char author[30];
	char publish[30];
	int borrowed;
};

int main()
{
	struct library Books[100];

	int choice = 0;
	int bookNum = 0;  // 책 번호 (Books[0], Books[1], etc...)

	while (1)
	{
		printf("1.새로운 책 등록\n");
		printf("2.책 검색, 대출\n");
		printf("3.책 반납\n4.전자 도서관 종료(1,2,3,4를 제외한 아무 숫자 입력)\n무엇을 도와드릴까요? : ");
	
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

void book_register(struct library* regiBook, int* bookNum)  // 책 등록
{
	if (*bookNum >= 100)
	{
		printf("책을 더 이상 등록할 수 없습니다.\n");
		return;
	}

	printf("등록할 책 제목 : ");
	scanf("%s", regiBook[*bookNum].bookName);

	printf("등록할 책 저자 : ");
	scanf("%s", regiBook[*bookNum].author);

	printf("등록할 책 출판사 : ");
	scanf("%s", regiBook[*bookNum].publish);

	regiBook[*bookNum].borrowed = 0;  // 대출 안한 책은 0, 대출한 책은 1, 빌리면 +1, 반납하면 다시 -1

	printf("\n등록되었습니다.\n");

	*bookNum = *bookNum + 1;
}

void book_search(struct library* searchBook) // 책 검색 그리고 빌리면 + 1 하는 함수
{
	char searching[30];
	int num = 0;
	printf("검색할 내용\n1.제목\n2.저자\n3.출판사\n입력 : ");
	scanf("%d", &num);

	while (1)
	{
		if (num == 1)
		{
			int cmp;
			printf("제목 입력 : ");
			scanf("%s", searching);
			for (cmp = 0; strcmp(searchBook[cmp].bookName, searching) != 0; cmp++);
			printf("\n찾으시는 책 제목 : %s\n", searchBook[cmp].bookName);
			printf("찾으시는 책 저자 : %s\n", searchBook[cmp].author);
			printf("찾으시는 책 출판사 : %s\n\n", searchBook[cmp].publish);

			num = 0;
			if (searchBook[cmp].borrowed == 0)
			{
				printf("이 책은 대출 가능합니다..! 대출하시겠습니까?\n1.네 2.아니오 : ");
				scanf("%d", &num);

				if (num == 1)
				{
					searchBook[cmp].borrowed++;
					printf("대출되었습니다~\n");
				}
				else
					printf("\n");
			}
			else
			{
				printf("이미 대출되었습니다!\n");
			}

			break;
		}
		else if (num == 2)
		{
			int cmp;
			printf("저자 입력 : ");
			scanf("%s", searching);
			for (cmp = 0; strcmp(searchBook[cmp].author, searching) != 0; cmp++);
			printf("\n찾으시는 책 제목 : %s\n", searchBook[cmp].bookName);
			printf("찾으시는 책 저자 : %s\n", searchBook[cmp].author);
			printf("찾으시는 책 출판사 : %s\n\n", searchBook[cmp].publish);

			num = 0;
			if (searchBook[cmp].borrowed == 0)
			{
				printf("이 책은 대출 가능합니다..! 대출하시겠습니까?\n1.네 2.아니오 : ");
				scanf("%d", &num);

				if (num == 1)
				{
					searchBook[cmp].borrowed++;
					printf("대출되었습니다~\n");
				}
				else
					printf("\n\n");
			}
			else
			{
				printf("이미 대출되었습니다!\n");
			}

			break;
		}
		else if (num == 3)
		{
			int cmp;
			printf("출판사 입력 : ");
			scanf("%s", searching);
			for (cmp = 0; strcmp(searchBook[cmp].publish, searching) != 0; cmp++);
			printf("\n찾으시는 책 제목 : %s\n", searchBook[cmp].bookName);
			printf("찾으시는 책 저자 : %s\n", searchBook[cmp].author);
			printf("찾으시는 책 출판사 : %s\n\n", searchBook[cmp].publish);

			num = 0;
			if (searchBook[cmp].borrowed == 0)
			{
				printf("이 책은 대출 가능합니다..! 대출하시겠습니까?\n1.네 2.아니오 : ");
				scanf("%d", &num);

				if (num == 1)
				{
					searchBook[cmp].borrowed++;
					printf("대출되었습니다~\n");
				}
				else
					printf("\n\n");
			}
			else
			{
				printf("이미 대출되었습니다!\n");
			}

			break;
		}
		else
		{
			printf("다시 입력\n");
			break;
		}
	}
}

void book_return(struct library* returnBook, int* bookNum)
{
	printf("빌린 책 목록\n");

	for (int i = 0; i < *bookNum; i++)
	{
		printf("%d번 책 : %s\n", i + 1, returnBook[i].bookName);
	}

	int number = 0;

	printf("반납할 책 번호를 입력해주세요 : ");
	scanf("%d", &number);

	returnBook[number - 1].borrowed = 0;

	printf("반납이 완료되었습니다! \n\n");
}

