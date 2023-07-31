#include <iostream>

typedef char BTData;

typedef struct _bTreeNode
{
	BTData data;
	_bTreeNode* left;
	_bTreeNode* right;
} BTreeNode;

/*** BTreeNode 관련 연산들 ****/
BTreeNode* MakeBTreeNode();
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

int main()
{
	return 0;
}

// 어떻게 하나의 노드를 트리 형태로 이어줄 수 있는지 고민 필요.
// 현재는 세개의 노드가 엮인 채로 따로 분리됨.
BTreeNode* MakeBTreeNode(BTData data, BTData Ldata, BTData Rdata)
{
	BTreeNode* root = new BTreeNode;
	root->data = data;

	if (Ldata == '.')
	{
		root->left = NULL;
	}
	else
	{
		root->left = MakeBTreeNode(Ldata, '.', '.');
	}

	if (Rdata == '.')
	{
		root->right = NULL;
	}
	else
	{
		root->right = MakeBTreeNode(Rdata, '.', '.');
	}

	return root;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}
