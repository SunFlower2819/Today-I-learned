#include <iostream>

// 연결리스트로 이진트리 구현
// A B C 입력 받으면 A가 루트노드, B왼쪽, C오른쪽 노드로 연결
// B D E 입력 받으면 B를 기준으로 D왼쪽, E오른쪽 노드로 연결

// 그러면, 어떻게 B 노드를 찾아가고 이어줄 것인가.

// 전위순회를 사용해서 노드의 데이터를 비교하고 같은 노드를 찾으면
// 그 노드 값을 반환하는거?

// 그니까 트리는 만들어지고 값을 찾기 위해서 순회를 하는거지

typedef char BTData;

class BTNode
{
public:
	BTData data;
	BTNode* leftNode;
	BTNode* rightNode;

	BTNode()
	{
		data = '.';
		leftNode = NULL;
		rightNode = NULL;
	}
};

// A노드를 시작으로 트리 형태를 만들어주는 함수
void makeBinaryTree(BTNode* bt, BTData rootData, BTData leftData, BTData rightData);

// 노드 메모리 할당 함수
BTNode* makeNode();

// 루트 노드를 반환해주는 함수
BTNode* findNodeData(BTNode* bt, BTData rootData);

// 전위 순회
void PreorderTraverse(BTNode* bt);

// 중위 순회
void InorderTraverse(BTNode* bt);

// 후위 순회
void PostorderTraverse(BTNode* bt);

int main()
{
	BTNode* bt = NULL;

	int N;
	std::cin >> N;

	char rootData, leftData, rightData;

	for (int i = 0; i < N; i++)
	{
		std::cin >> rootData >> leftData >> rightData;

		if (bt == NULL)
		{
			bt = makeNode();
			bt->data = rootData;

			bt->leftNode = makeNode();
			bt->rightNode = makeNode();

			bt->leftNode->data = leftData;
			bt->rightNode->data = rightData;
		}	
		else
			makeBinaryTree(bt, rootData, leftData, rightData);
	}

	PreorderTraverse(bt);
	std::cout << std::endl;

	InorderTraverse(bt);
	std::cout << std::endl;

	PostorderTraverse(bt);
	std::cout << std::endl;

	return 0;
}

void makeBinaryTree(BTNode* bt, BTData rootData, BTData leftData, BTData rightData)
{
	//BTNode* newNode = 중위 순회하여 리턴된 루트 노드(알맞는 데이터 없으면 NULL 반환)
	BTNode* newNode = findNodeData(bt, rootData);

	// 만약 순회하여 리턴된 노드가 없다면, 즉 처음 생성되는 과정이라면
	// newNode가 맨위의 루트 노드를 가리키게 한다.
	// 왼쪽 노드와 오른쪽 노드도 생성해주는 연산이 필요함. 그리고 아래 과정을 거쳐야함.

	 newNode->leftNode = makeNode();
	 newNode->rightNode = makeNode();
	 
	 newNode->leftNode->data = leftData;
	 newNode->rightNode->data = rightData;
}

BTNode* makeNode()
{
	// 새로운 노드 생성
	BTNode* newNode = new BTNode;
	
	return newNode;
}

// 재귀 함수를 통해 값을 전달하는 과정이다.
// 리턴값을 계속해서 어떻게 전달할지에 대한 고민이 필요하다.
BTNode* findNodeData(BTNode* bt, BTData rootData)
{
	if (bt == NULL) {
		return NULL; // 노드가 없는 경우 NULL 반환
	}

	if (rootData == bt->data)
	{
		return bt; // 노드의 데이터가 일치하는 경우 해당 노드 반환
	}
	else
	{
		BTNode* leftResult = findNodeData(bt->leftNode, rootData);
		if (leftResult != NULL) {
			return leftResult; // 왼쪽 서브트리에서 찾은 경우 해당 노드 반환
		}

		BTNode* rightResult = findNodeData(bt->rightNode, rootData);
		return rightResult; // 오른쪽 서브트리에서 찾은 결과를 반환
	}
}

// 전위
void PreorderTraverse(BTNode* bt)
{
	if(bt->data != '.')
		std::cout << bt->data;
	
	if (bt->leftNode != NULL || bt->rightNode != NULL)
	{
		PreorderTraverse(bt->leftNode);
		PreorderTraverse(bt->rightNode);
	}
}

// 중위
void InorderTraverse(BTNode* bt)
{
	if (bt->leftNode != NULL)
	{
		InorderTraverse(bt->leftNode);
	}

	if (bt->data != '.')
		std::cout << bt->data;

	if (bt->rightNode != NULL)
	{
		InorderTraverse(bt->rightNode);
	}
}

// 후위
void PostorderTraverse(BTNode* bt)
{
	if (bt->leftNode != NULL || bt->rightNode != NULL)
	{
		PostorderTraverse(bt->leftNode);
		PostorderTraverse(bt->rightNode);
	}

	if (bt->data != '.')
		std::cout << bt->data;
}
