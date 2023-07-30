#include <iostream>

typedef int Data;

class _node
{
public:
	_node* next;
	_node* prev;
	Data data;

	_node()
	{
		next = NULL;
		prev = NULL;
		data = 0;
	}
};

typedef class _node Node;

// 원형 연결 리스트
class _list
{
public:
	Node* head;
	Node* tail;
	Node* cur;
	Data movingCount;  // 총 이동 횟수

	_list()
	{
		head = NULL;
		tail = NULL;
		cur = NULL;
		movingCount = 0;
	}
};

typedef class _list Queue;

// 1부터 n까지 리스트 연결해주는 함수
void QInit(Queue* plist, int n);

// 새로운 노드를 생성해주는 함수 (LInit 함수에서 사용)
void QCreateNode(Queue* plist, Data data);

// 왼쪽 방향으로 num을 찾을 때 이동 횟수
int Qfind_Left(Queue* plist, Data num);

// 오른쪽 방향으로 num을 찾을 때 이동 횟수
int Qfind_Right(Queue* plist, Data num);

// 왼쪽, 오른쪽 비교하고 더 작은 거 더해주는 함수
void Qcompare(Queue* plist, Data num);

// num을 찾고 제거하고 다시 연결해주는 함수
void Qdelete(Queue* plist, Data num);

int main()
{
	int N, M, findNum;
	Queue q;

	std::cin >> N >> M;

	QInit(&q, N);

	for (int i = 0; i < M; i++)
	{
		std::cin >> findNum;
		Qdelete(&q, findNum);
	}

	std::cout << q.movingCount << '\n';

	return 0;
}

void QInit(Queue* plist, int n)
{
	for (int i = 1; i <= n; i++)
	{
		QCreateNode(plist, i);
	}
}

void QCreateNode(Queue* plist, Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	// 첫번째 노드 생성
	if (plist->head == NULL)
	{
		plist->head = newNode;
		plist->tail = newNode;
		newNode->next = newNode;

		// 노드가 한개일 경우 노드 한개의 next와 prev가 자기 자신을 가리키고 있어야한다.
		// 하지만 만약 prev를 설정해주지 않으면
		// Qdelete() 함수에 있는 plist->head->prev = plist->tail; 와 같은 코드는
		// NULL = plist->tail; 과 같은 형태를 띄게 된다.
		// 따라서 아래의 코드를 추가해주지 않아서 런타임 에러 (AccessNullPointer)가 발생한 것이다.
		// 반례로는 노드가 1인 연결리스트에서 1을 찾을 경우를 입력할 때 0이 출력되지 못한다.
		newNode->prev = newNode;
	}
	else // 두번째 노드를 생성할 때로 진입
	{
		// 이중 연결 리스트
		newNode->prev = plist->tail;
		plist->tail->next = newNode;
		plist->tail = newNode;

		// 원형 연결 리스트
		plist->head->prev = plist->tail;
		plist->tail->next = plist->head;
	}
}

int Qfind_Left(Queue* plist, Data num)
{
	int leftCount = 0;
	plist->cur = plist->head;

	for (Queue* q = plist; q->cur->data != num; q->cur = q->cur->prev)
	{
		leftCount += 1;
	}

	return leftCount;
}

int Qfind_Right(Queue* plist, Data num)
{
	int rightCount = 0;
	plist->cur = plist->head;

	for (Queue* q = plist; q->cur->data != num; q->cur = q->cur->next)
	{
		rightCount += 1;
	}

	return rightCount;
}

void Qcompare(Queue* plist, Data num)
{
	int leftCount = Qfind_Left(plist, num);
	int rightCount = Qfind_Right(plist, num);

	if (leftCount == -1 || rightCount == -1)
	{
		std::cout << "오류" << std::endl;
		exit(1);
	}

	// 더 작은 횟수를 더해준다.
	if (leftCount >= rightCount)
		plist->movingCount += rightCount;
	else
		plist->movingCount += leftCount;
}

void Qdelete(Queue* plist, Data num)
{
	// 왼쪽과 오른쪽을 비교한다.
	// 더 작은 수를 plist->movingCount에 더한다.
	Qcompare(plist, num);


	// 연결 리스트를 이어준다.
	Node* delNode = plist->cur;

	plist->tail = plist->cur->prev;
	plist->head = plist->cur->next;

	plist->tail->next = plist->head;
	plist->head->prev = plist->tail;

	delete delNode;
}
