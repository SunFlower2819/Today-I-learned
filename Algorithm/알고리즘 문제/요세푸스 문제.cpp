#include <iostream>

typedef int Data;

class _node
{
public:
	_node* next;
	Data data;
};

typedef class _node Node;

// 원형 연결 리스트
class _list
{
public:
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;

	_list()
	{
		tail = NULL;
		cur = NULL;
		before = NULL;
		numOfData = 0;
	}
};

typedef class _list list;

// 1부터 n까지 리스트 연결해주는 함수
void LInit(list* plist, int n);

// 새로운 노드를 생성해주는 함수 (LInit 함수에서 사용될 예정)
void LCreateNode(list* plist, Data data);

// 리스트가 비었는지 확인하는 함수
bool LEmpty(list* plist);

// n번째 데이터를 반환 
// cur 노드를 시작으로 n번째 노드를 반환
Node* LPick(list* plist, int n);

// n번째 데이터를 제거하고 반환해주는 함수
// LPick이 반환하는 노드를 delete 변수 노드를 따로 만들어 받고 제거
int LDelete(list* plist, int n);

int main()
{
	list L;
	int size, num;

	std::cin >> size;
	LInit(&L, size);

	std::cin >> num;

	std::cout << "<";
	while (!LEmpty(&L))
	{
		if (L.numOfData > 1)
		{
			std::cout << LDelete(&L, num) << ", ";
		}
		else
		{
			std::cout << LDelete(&L, num);
		}
	}
	std::cout << ">";

	return 0;
}

void LInit(list* plist, int n)
{
	for (int i = n; i >= 1; --i)
	{
		LCreateNode(plist, i);
	}
}

void LCreateNode(list* plist, Data data)
{
	// 더미로 하면 안된다.. 그럼 너무 복잡해져..
	Node* newNode = new Node;
	newNode->data = data;

	// 노드 생성
	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else // 2번째 노드를 생성할 때로 진입
	{
		// 새로운 노드가 head 노드를 가리켜 원형리스트를 구현
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;

		// 3(tail)
		// 2 -> 3(tail)
		// 1 -> 2 -> 3(tail)   이렇게 추가됨
	}

	// 리스트의 노드 개수 증가
	(plist->numOfData)++;
}

bool LEmpty(list* plist)
{
	if (plist->numOfData == 0)
		return true;
	else
		return false;
}

Node* LPick(list* plist, int n)
{
	if (plist->cur == NULL)
		plist->cur = plist->tail->next;

	for (int i = 1; i < n; i++)
	{
		// cur 노드를 이동시키기 전 before 노드를 지정해준다.
		plist->before = plist->cur;

		// 현재 cur 노드를 cur의 next노드로 옮긴다.
		plist->cur = plist->cur->next;
	}

	// 리스트 상에 있는 n번째 노드를 반환
	return plist->cur;
}

int LDelete(list* plist, int n)
{
	Node* delNode = LPick(plist, n);
	Data rdata = delNode->data;
	
	// plist->before가 NULL이라는 것은 데이터 삭제 횟수가 1인 요세푸스 순열의 시작이라는 뜻
	// 즉, 이러한 예외 상황을 따로 처리해줘야함
	if (plist->before == NULL)
	{
		// 만약 리스트의 노드가 1개 남았으면 현재 노드가 자기 자신을 가리키게함
		// 이거는 별 이유는 없음, 없는 next노드를 가리키는 것보다는 이게 더 깔끔해보임
		if (plist->numOfData == 1)
			plist->cur = plist->cur;

		// 현재 노드가 다음 노드를 가리키도록 해줌
		plist->cur = plist->cur->next;
	}
	else
	{
		// 삭제 노드를 빼주고 전과 다음 노드를 연결해줌
		plist->before->next = plist->cur->next;
		plist->cur = plist->cur->next;
	}

	free(delNode);
	(plist->numOfData)--;
	return rdata;
}
