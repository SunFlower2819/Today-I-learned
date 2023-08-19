#include <iostream>

// 최소 힙. --> 배열로 구현 (완전이진트리)
// 0번 인덱스는 비우기

// 구조체 (우선순위, 데이터)
// 구조체 (힙, 현재 저장된 데이터 수)

const int dataSize = 100000;

class HeapData
{
public:
	int data;
	int priority;  // 데이터 우선순위
};

class Heap
{
public:
	HeapData hBt[dataSize] = {0};
	int numOfData;

	Heap()
	{
		numOfData = 0;
	}
};

// 필요한 연산들.
// 1. 힙 생성 연산
// 2. IsEmpty()
// 3. IsFull()
// 4. 데이터 추가 연산
// 5. 데이터 삭제 연산

void InitHeap(Heap* heap);
bool IsEmpty(Heap* heap);
bool IsFull(Heap* heap);
void AddData(Heap* heap, int data);
int DeleteData(Heap* heap);

int main()
{
	Heap heap;

	return 0;
}

void InitHeap(Heap* heap)
{
	
}

bool IsEmpty(Heap* heap)
{
	if (heap->numOfData == 0)
		return true;
	else
		return false;
}

bool IsFull(Heap* heap)
{
	if (heap->numOfData == dataSize)
		return true;
	else
		return false;
}

// 힙 삽입연산 구현해야함.
void AddData(Heap* heap, int num)
{
	heap->numOfData += 1;
	int lastIndex = heap->numOfData;

	heap->hBt[lastIndex].data = num;

}

int DeleteData(Heap* heap)
{
	int deleteData = 0;

	return deleteData;
}
