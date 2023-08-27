#include <iostream>

const int dataSize = 100000;

struct HeapData
{
	int data;
};

struct Heap
{
	HeapData hBt[dataSize];
	int numOfData = 0;
};

bool IsEmpty(Heap* heap);
bool IsFull(Heap* heap);
void InsertData(Heap* heap, int data);
int GetLowChildIDX(Heap* ph, int idx);  // 더 작은 값을 가진 자식의 인덱스를 가져옴
int DeleteData(Heap* heap);

int main()
{
	Heap heap;

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		std::cin >> x;

		if (x == 0)
		{
			if (IsEmpty(&heap))
				std::cout << 0 << std::endl;
			else
				std::cout << DeleteData(&heap) << std::endl;
		}
		else
		{
			if (IsFull(&heap))
				std::cout << "더 이상 데이터 추가 불가" << std::endl;
			else
				InsertData(&heap, x);
		}
	}

	return 0;
}

bool IsEmpty(Heap* heap)
{
	return heap->numOfData == 0;
}

bool IsFull(Heap* heap)
{
	return heap->numOfData == dataSize;
}

// 힙 삽입연산
void InsertData(Heap* heap, int num)
{
	heap->numOfData += 1;
	int index = heap->numOfData;

	// 마지막 위치에 노드 저장
	heap->hBt[index].data = num;
	//heap->hBt[index].priority = index;

	// 삽입 노드의 인덱스가 1이면 중지
	// 노드를 내려주다가 부모노드가 더 작으면 현재 위치에 노드값 저장
	while (index != 1)
	{
		if (num < heap->hBt[index / 2].data)
		{
			heap->hBt[index].data = heap->hBt[index / 2].data;

			index /= 2;
		}
		else
			break;
	}

	heap->hBt[index].data = num;
}

int GetLowChildIDX(Heap* ph, int idx)
{
	if (idx * 2 > ph->numOfData) // 자식 노드가 존재하지 않는다면,
		return 0;
	else if (idx * 2 == ph->numOfData) // 자식 노드가 왼쪽 자식 노드 하나만 존재한다면
		return idx * 2;
	else // 자식 노드가 둘다 존재한다면
	{
		// 오른쪽 자식 노드의 데이터가 작다면
		if (ph->hBt[idx * 2].data > ph->hBt[idx * 2 + 1].data)
			return idx * 2 + 1; // 오른쪽 자식 노드의 인덱스 값 반환
		else // 왼쪽 자식 노드의 데이터가 작다면
			return idx * 2;		// 왼쪽 자식 노드의 인덱스 값 반환
	}
}

int DeleteData(Heap* heap)
{
	int delData = heap->hBt[1].data;
	HeapData lastElem = heap->hBt[heap->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetLowChildIDX(heap, parentIdx))
	{
		if (lastElem.data <= heap->hBt[childIdx].data)
			break;
		heap->hBt[parentIdx] = heap->hBt[childIdx];
		parentIdx = childIdx;
	}

	heap->hBt[parentIdx] = lastElem;
	heap->numOfData -= 1;

	return delData;
}
