# 깊이 우선 탐색(Depth First Search: DFS)
DFS는 스택을 활용하여 구현한다.   


https://github.com/user-attachments/assets/386118e6-339a-4922-bbb2-7e2a983830c0



아래의 코드를 읽고, 출력결과를 분석해보자.
# Code
### ALGraphDFS.h
```c
#ifndef __AL_GRAPH_DFS__
#define __AL_GRAPH_DFS__

#include "DLinkedList.h" // 연결 리스트를 가져다 쓴다

// 정점의 이름들을 상수화
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;        // 정점의 수
	int numE;        // 간선의 수
	List* adjList;   // 간선의 정보
	int* visitInfo;  // 탐색이 진행된 정점의 정보를 담음
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph* pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph* pg);

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

// 정점의 정보 출력: Depth First Search 기반
void DFShowGraphVertex(ALGraph* pg, int startV);

#endif
```

### ALGraphDFS.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"
#include "ArrayBaseStack.h"
#include "ALGraphDFS.h"

int WhoIsPrecede(int data1, int data2) 
{
	if (data1 > data2)
		return 1;
	else
		return 0;
}

void GraphInit(ALGraph* pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++) 
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	// 정점의 수를 길이로 하여 배열을 할당
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);

	// 배열의 모든 요소를 0으로 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);

	// 할당된 배열 소멸
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph* pg, int fromV, int toV) 
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph* pg) 
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++) 
	{
		printf("%c와 연결된 정점: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx)) 
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx)) 
			{
				printf("%c ", vx + 65);
			}
			printf("\n");
		}
	}
}

// 두 번째 매개변수(int visitV)로 전달된 이름의 정점에 방문!
int VisitVertex(ALGraph* pg, int visitV) 
{
	// visitV에 처음 방문일 때 '참'인 if문
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;  // visitV에 방문한 것으로 기록
		printf("%c ", visitV + 65); // 방문한 정점의 이름 출력
		return TRUE;
	}
	return FALSE;
}

// DFS 기반으로 정의된 함수: 정점의 정보 출력
void DFShowGraphVertex(ALGraph* pg, int startV) // 그래프와 탐색의 시작점을 받음
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);         // DFS를 위한 스택의 초기화
	VisitVertex(pg, visitV);   // 시작 정점을 방문
	SPush(&stack, visitV);     // 시작 정점의 정보를 스택으로!

	// visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while문
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) 
	{
		// visitV와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE) // 방문에 성공했다면,
		{
			SPush(&stack, visitV); // visitV에 담긴 정점의 정보를 PUSH
			visitV = nextV;
			visitFlag = TRUE;
		}
		else // 방문에 실패했다면, 연결된 다른 정점들을 찾는다.
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE) 
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) // 추가로 방문한 정점이 없었다면
		{
			// 스택이 비면 탐색의 시작점으로 되돌아 온 것!
			if (SIsEmpty(&stack) == TRUE) // 시작점으로 되돌아왔음!
				break;
			else
				visitV = SPop(&stack);    // 길을 되돌아 간다.
		}
	}

	// 이후의 탐색을 위해서 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
```

### main.c
```c
#include <stdio.h>
#include "ALGraphDFS.h"

int main() 
{
	ALGraph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B); AddEdge(&graph, A, D);
	AddEdge(&graph, B, C); AddEdge(&graph, D, C);
	AddEdge(&graph, D, E); AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);

	DFShowGraphVertex(&graph, A); printf("\n");
	DFShowGraphVertex(&graph, C); printf("\n");
	DFShowGraphVertex(&graph, E); printf("\n");
	DFShowGraphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
	return 0;
}
```
```
출력결과

A와 연결된 정점: B D
B와 연결된 정점: A C
C와 연결된 정점: B D
D와 연결된 정점: A C E
E와 연결된 정점: D F G
F와 연결된 정점: E
G와 연결된 정점: E

A B C D E F G
C B A D E F G
E D A B C F G
G E D A B C F
```
