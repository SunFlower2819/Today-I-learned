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

int main()
{

	return 0;
}
