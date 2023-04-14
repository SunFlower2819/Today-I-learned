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