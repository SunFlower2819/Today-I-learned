### 순회의 세 가지 방법

* 전위 순회(Preorder Traversal)  :  루트 노드를 먼저!
* 중위 순회(Inorder Traversal)   :  루트 노드를 중간에!
* 후위 순회(Postorder Traversal) :  루트 노드를 마지막에!

이렇듯 이진 트리를 순회하는 대표적인 방법은 **"루트 노드를 언제 방문하느냐!"** 를 기준으로 나뉜다.

---
 
코드만 봐도 이해될 것이다.

```c
// 전위 순회 ------------------------------------------------------------
void PreorderTraverse(BTreeNode * bt)
{
	if(bt == NULL)
		return;

	printf("%d \n", bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

// 중위 순회 ------------------------------------------------------------
void InorderTraverse(BTreeNode * bt)
{
	if(bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	printf("%d \n", bt->data);
	InorderTraverse(bt->right, action);
}

// 후위 순회 ------------------------------------------------------------
void PostorderTraverse(BTreeNode * bt)
{
	if(bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	printf("%d \n", bt->data);
}
```

---

### 🟠문제 08-1

```c
void DeleteTree(BTreeNode* bt)
{
	if(bt == NULL)
		return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);

	printf("삭제되는 노드의 데이터: %d \n", bt->data);
	free(bt);
}
```

위의 문제의 핵심은 반드시 **후위 순회** 의 과정을 통해서 노드를 소멸을 진행해야 한다는 것이다! <br>
그래야 루트 노드가 마지막에 소멸되기 때문이다!!
