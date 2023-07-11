__🎈🎈 우리는 자료구조의 구현 능력을 중요시하는 경향이 있다. 물론 어느 정도 필요한 능력인 것은 맞다. 하지만 절대시할 필요는 없다.__

어쩌면 자료구조를 공부하면서 중요한 건, 사용하고자 하는 자료구조의 ADT, 즉 어떠한 연산과 기능이 있는 지를 잘 파악하고 있는 것이지 않을까??

---

### 원형 연결 리스트의 이해

앞서 우리가 구현한 연결 리스트의 마지막 노드는 NULL을 가리켰다. 바로 이 마지막 노드가 첫 번째 노드를 가리키게 하면 이것이 바로 **'원형 연결 리스트'** 가 된다.


```c
// CLinkedList.h

#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _CLL
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CList;

typedef CList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);
void LInsertFront(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
Data LRemove(List* plist);
int LCount(List* plist);

#endif
```

```c
//CLinkedList.c

#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

// 리스트 초기화
void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

// 맨 앞에 노드 추가
void LInsertFront(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

// 새 노드를 꼬리에 추가
void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;   // tail의 위치를 새로운 노드로 옮겨준다.
		                         // 이렇게 하면 한 번의 이동으로 새 노드를 꼬리에 추가하는 셈이 된다.
	}
	(plist->numOfData)++;
}

// 꼬리의 next, 즉 첫 번째 데이터를 반환
int LFirst(List* plist, Data* pdata)
{
	if (plist->tail == NULL)    // 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

// 첫 번째 데이터 이후의 다음 데이터를 지속적으로 반환이 가능하게 하는 함수
int LNext(List* plist, Data* pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

// 현재 노드를 제거하는 함수
Data LRemove(List* plist)
{
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail)    // 삭제 대상을 tail이 가리킨다면
	{
		if (plist->tail == plist->tail->next)    // 그리고 마지막 남은 노드라면
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}
```

```c
// CLinkedListMain.c

#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	// 원형 연결 리스트의 생성 및 초기화 ///////
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	// 리스트에 5개의 데이터를 저장 /////// 
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// 리스트에 저장된 데이터를 연속 3회 출력 ///////
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < LCount(&list) * 3 - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	// 2의 배수를 찾아서 모두 삭제 ///////
	nodeNum = LCount(&list);

	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (i = 0; i < nodeNum - 1; i++)
		{
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	// 전체 데이터 1회 출력 ///////
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	return 0;
}
```
