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

// 맨처음 생성된 루트 노드(A)를 기준으로 
// 노드를 이어주는 연산을 만들면 됨.

// 필요한 연산.
// 0. 맨 처음 노드를 생성해주는 연산
// 1. 두 번째 이후의 노드를 생성해주는 연산
// 2. 중위 순회를 통해 입력된 데이터를 가진 노드를 찾는 연산
// 3. 전위,중위,후위 순회를 하는 연산

void makeBinaryTree(BTNode* bt, BTData rootData, BTData leftData, BTData rightData)
{
	//BTNode* newNode = 중위 순회하여 리턴된 루트 노드(알맞는 데이터 없으면 NULL 반환)

	// 만약 순회하여 리턴된 노드가 없다면, 즉 처음 생성되는 과정이라면
	// newNode가 맨위의 루트 노드를 가리키게 한다.
	
	//if (newNode == NULL)
	//{
	//	newNode = bt;
	//  newNode->data = rootData;
	//}

	// 왼쪽 노드와 오른쪽 노드도 생성해주는 연산이 필요함. 그리고 아래 과정을 거쳐야함.

	// newNode->leftNode = makeNode();
	// newNode->rightNode = makeNode();
	 
	// newNode->leftNode->Data = leftData;
	// newNode->rightNode->Data = rightData;
}

BTNode* makeNode()
{
	// 새로운 노드 생성
	BTNode* newNode = new BTNode;
	
	return newNode;
}

BTNode* findNodeData(BTNode* bt, BTData rootData)
{
	// 순회를 통해 bt->data == rootData 의 조건이 만족되는 노드를 찾음
	// 못찾으면 NULL 반환
}

int main()
{

	return 0;
}

// 생성할 노드를 입력 받는다.
// 노드를 생성하는 함수를 사용하여 루트,왼,오 노드를 반환하여 생성해준다.
