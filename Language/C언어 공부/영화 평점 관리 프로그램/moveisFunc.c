#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movies.h"

void PrintAllItems()
{
	for (int i = 0; i < itemsCount; i++)
	{
		printf("%d : \"%s\", %.1lf\n", i, Movies[i].name, Movies[i].rate);
	}
	printf("\n");
}

void PrintAnItem()
{
	int choice;
	printf("Input the index of item to print.\n>> ");
	scanf("%d", &choice);

	if (choice < 0 || choice >= itemsCount)
		printf("Invalid item.\n\n");
	else
		printf("%d : \"%s\", %.1lf\n\n", choice, Movies[choice].name, Movies[choice].rate);
}

void EditAnItem()
{
	int choice;
	printf("Input the index of item to edit.\n>> ");
	scanf("%d", &choice);

	printf("%d : \"%s\", %.1lf\n", choice, Movies[choice].name, Movies[choice].rate);

	while (getchar() != '\n');

	printf("Input new title and press enter.\n>> ");
	//scanf("%s", &Movies[choice].name);
	gets_s(Movies[choice].name, 100);
	printf("Input new rating and press enter.\n>> ");
	scanf("%lf", &Movies[choice].rate);

	printf("%d : \"%s\", %.1lf\n\n", choice, Movies[choice].name, Movies[choice].rate);
}

void AddAnItem()
{
	itemsCount++;  // 총 영화 개수 증가

	while (getchar() != '\n');

	printf("Input title and press enter.\n>> ");
	//scanf("%s", &Movies[itemsCount - 1].name);
	gets_s(Movies[itemsCount - 1].name, 100);
	printf("Input rating and press enter.\n>> ");
	scanf("%lf", &Movies[itemsCount - 1].rate);

	printf("%d : \"%s\", %.1lf\n\n", itemsCount - 1, Movies[itemsCount - 1].name, Movies[itemsCount - 1].rate);
}

void InsertAnItem()
{
	itemsCount++;
	int index;

	printf("Input the idex of item to insert.\n>> ");
	scanf("%d", &index);


	for (int i = itemsCount - 2; i >= index; i--)
	{
		strcpy(Movies[i + 1].name, Movies[i].name);
		Movies[i + 1].rate = Movies[i].rate;
	}

	while (getchar() != '\n');

	printf("Input title and press enter.\n>> ");
	//scanf("%s", &Movies[index].name);
	gets_s(Movies[index].name, 100);
	printf("Input rating and press enter.\n>> ");
	scanf("%lf", &Movies[index].rate);

	printf("%d : \"%s\", %.1lf\n\n", index, Movies[index].name, Movies[index].rate);
}

void DeleteAnItem()
{
	int index = 0;

	if (itemsCount > 0)
	{
		itemsCount--;

		printf("Input the index of item to delete.\n>> ");
		scanf("%d", &index);

		for (int i = index + 1; i <= itemsCount; i++)
		{
			strcpy(Movies[i - 1].name, Movies[i].name);
			Movies[i - 1].rate = Movies[i].rate;
		}
	}
	else
	{
		printf("There's no movie\n\n");
	}
}

void DeleteAllItem()
{
	itemsCount = 0;
}

void SaveFile()
{
	FILE* fp = NULL;

	char title[100];
	printf("Please input file name to write and press Enter.\n>> ");
	scanf("%s", title);

	fp = fopen(title, "w");
	if (fp == NULL)
	{
		fprintf(stderr, "We can not open this file.\n\n");
		exit(1);
	}

	char moviesCount = itemsCount + '0';

	fputc(moviesCount, fp);

	for (int i = 0; i < itemsCount; i++)
	{
		fprintf(fp, "\n");
		fputs(Movies[i].name, fp);
		fprintf(fp, "\n%lf", Movies[i].rate);
	}

	fclose(fp);
}

void SearchByName()
{
	int i, check = -5;
	char aa[100];

	while (getchar() != '\n'); // 버퍼 비워주기 (위의 메뉴 선택 할떄 남아있는 '\n'제거)

	printf("Input title to search and press enter.\n>> ");

	fgets(aa, 100, stdin);
	aa[strlen(aa) - 1] = '\0';  // 문자열 마지막 개행문자 제거

	for (i = 0; i < itemsCount; i++)
	{
		if (strcmp(aa, Movies[i].name) == 0)
		{
			check = i;
			break;
		}
	}


	if (check != -5)
		printf("%d : \"%s\", %.1lf\n\n", i, Movies[i].name, Movies[i].rate);
	else
		printf("No movie found : %s\n\n", aa);
}
