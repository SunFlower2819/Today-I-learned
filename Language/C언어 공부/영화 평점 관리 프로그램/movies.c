#include <stdio.h>
#include <string.h>
#include "movies.h"

int main()
{
	int choice = 0; // 메뉴 고르기
	char open[20];

	FILE* moviefp = fopen("movies.txt", "r");
	printf("Please input filename to read and press Enter\n>> ");

	scanf("%s", open);

	if (strcmp(open, "movies.txt") != 0)
	{
		printf("ERROR : Cannot open file\n");
		return 0;
	}
	else if (moviefp != NULL)
	{
		itemsCount = fgetc(moviefp) - '0'; // 실수형이므로 54
		printf("%c items have been read from the file.\n\n", itemsCount);
	}

	// 영화 입력----------------------- Movies[0].name : Sector 7, Movies[0].rate : 4.6 ...
	char str[100];
	int index = 0; // 영화 순서 인덱스
	for (int i = 0; i < itemsCount; i++)
	{
		fgets(str, 100, moviefp);
		fgets(str, 100, moviefp);
		if (str != "\n")
		{
			str[strlen(str) - 1] = '\0';
			strcpy(Movies[index].name, str);
			fscanf(moviefp, "%lf", &Movies[index].rate);
			index++;
		}
	}
	//----------------------------------

	while(1)
	{
		printf("Please select an option and press Enter\n");
		printf("1. Print all items\t");
		printf("2. Print an item\n");
		printf("3. Edit an item \t");
		printf("4. Add an item\n");
		printf("5. Insert an item\t");
		printf("6. Delete an item\n");
		printf("7. Delete all items\t");
		printf("8. Save file\n");
		printf("9. Search by name\t");
		printf("10. Quit\n");
		printf(">> ");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1: PrintAllItems(); break;
		case 2: PrintAnItem(); break;
		case 3: EditAnItem(); break;
		case 4: AddAnItem(); break;
		case 5: InsertAnItem(); break;
		case 6: DeleteAnItem(); break;
		case 7: DeleteAllItem(); break;
		case 8: SaveFile(); break;
		case 9: SearchByName(); break;
		case 10: return 0;
		default:
			printf("You choose wrong number.\nPlease try again.\n\n");
			break;
		}
	} 

	fclose(moviefp);

	return 0;
}
