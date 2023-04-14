#include <stdio.h>
#include <string.h>
#include "libraryFunc.h"

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
		if (returnBook[i].borrowed == 0)
		{
			printf("%d.대출 가능 책 : %s\n", i + 1, returnBook[i].bookName);
		}
		else
		{
			printf("%d.빌린 책 : %s\n", i + 1, returnBook[i].bookName);
		}
	}

	int number = 0;

	printf("대출하실 혹은 반납하실 책 번호를 입력해주세요 : ");
	scanf("%d", &number);

	if (returnBook[number - 1].borrowed == 0)
	{
		returnBook[number - 1].borrowed++;
		printf("대출되셨습니다~!\n");
	}
	else
	{
		returnBook[number - 1].borrowed--;
		printf("반납되셨습니다~!\n");
	}
}