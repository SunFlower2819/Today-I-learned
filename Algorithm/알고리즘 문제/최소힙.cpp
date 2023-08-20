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
	HeapData hBt[dataSize] = { 0 };
	int numOfData;

	Heap()
	{
		numOfData = 0;
	}
};

// 필요한 연산들.
// 1. IsEmpty()
// 2. IsFull()
// 3. 데이터 추가 연산
// 4. 데이터 삭제 연산

bool IsEmpty(Heap* heap);
bool IsFull(Heap* heap);
void AddData(Heap* heap, int data);
int DeleteData(Heap* heap);

int main()
{
	Heap heap;

	//int N;
	//std::cin >> N;

	//for (int i = 0; i < N; i++)
	//{
	//	int x;
	//	std::cin >> x;

	//	if (x == 0)
	//	{
	//		if (IsEmpty(&heap))
	//			std::cout << "데이터가 없습니다." << std::endl;
	//		else
	//			DeleteData(&heap);
	//	}
	//	else
	//	{
	//		if (IsFull(&heap))
	//			std::cout << "더 이상 데이터를 추가할 수 없습니다." << std::endl;
	//		else
	//			AddData(&heap, x);
	//	}
	//}

	AddData(&heap, 4);
	AddData(&heap, 2);
	AddData(&heap, 5);
	AddData(&heap, 1);
	AddData(&heap, 3);

	return 0;
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
	// 1. 마지막 위치에 노드 삽입
	// 2. 루트 노드와 비교
	// 3. 루트 노드보다 작을 시 값 교환
	// 4. 루트 노드보다 클 시 삽입 완료

	heap->numOfData += 1;
	int index = heap->numOfData;

	// 마지막 위치에 노드 저장
	heap->hBt[index].data = num;
	heap->hBt[index].priority = index;

	// 삽입 노드의 인덱스가 1이면 중지
	while (index != 1)
	{
		// 삽입 노드와 루트 노드 비교 후 삽입 노드가 작으면 값 교환
		// 아니면 삽입 완료
		if (heap->hBt[index].data < heap->hBt[index / 2].data)
		{
			int temp = heap->hBt[index].data;
			heap->hBt[index].data = heap->hBt[index / 2].data;
			heap->hBt[index / 2].data = temp;

			index /= 2;
		}
		else
			break;
	}

	std::cout << heap->hBt[index].data << "삽입 완료" << std::endl;
}

int DeleteData(Heap* heap)
{
	// 1.마지막 노드를 첫 번째 노드 위치로 옮기기
	// 2.그리고 왼쪽 노드와 오른쪽 노드 중 더 작은 노드와 교환 (물론 선택된 노드보다 작아야함)
	// 3.삭제 완료

	int deleteData = heap->hBt[1].data;
	int index = heap->numOfData;

	// 마지막 노드의 데이터를 루트 노드에 넣어준다. 그리고 마지막 노드의 데이터를 0으로 초기화
	heap->hBt[1].data = heap->hBt[index].data;
	heap->hBt[index].data = 0;
	


	// 여기까지 루트 노드에 마지막 노드를 삽입해주는 작업을 맞췄어.
	// 아래부터는 자식 노드와 비교 후 더 작은 값이랑 값을 교환해주는 작업을 해야 돼.

	// 내 생각엔 왼쪽 노드와 오른쪽 노드와 비교후
	// 더 작은 값이랑 루트 노드랑 비교 후 
	// 자식 노드가 더 작을 시 교환해주는 메커니즘을 사용해야 할 거 같아.

	return deleteData;
}
