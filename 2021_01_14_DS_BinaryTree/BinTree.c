#include<stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef char BinaryTreeDataType;

typedef struct BinaryTreeNode
{
	BinaryTreeDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
} BTNode;
BTNode* CreateBinTreeNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
//前序(根)遍历 根 左子树 右子树
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}
//中序（根）遍历  左子树 根 右子树
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}
//后序（根）遍历 
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}
//求树的结点个数
int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
//求树的叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}
//求树的深度
int TreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return 1+(TreeDepth(root->_left) > TreeDepth(root->_right) ? TreeDepth(root->_left) : TreeDepth(root->_right));
}

int main()
{
	BTNode* A = CreateBinTreeNode('A');
	BTNode* B = CreateBinTreeNode('B');
	BTNode* C = CreateBinTreeNode('C');
	BTNode* D = CreateBinTreeNode('D');
	BTNode* E = CreateBinTreeNode('E');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;


	/*PrevOrder(A);
	
	InOrder(A);
	
	PostOrder(A);*/
	

	printf("树的结点个数为：%d\n", TreeSize(A));
	printf("叶子节点个数为：%d\n", TreeLeafSize(A));
	printf("树的深度为：%d\n", TreeDepth(A));

	system("pause");
	return 0;
}