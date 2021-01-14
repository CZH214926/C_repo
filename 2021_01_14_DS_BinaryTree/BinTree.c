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
//ǰ��(��)���� �� ������ ������
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
//���򣨸�������  ������ �� ������
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
//���򣨸������� 
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
//�����Ľ�����
int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}
//������Ҷ�ӽڵ����
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
//���������
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
	

	printf("���Ľ�����Ϊ��%d\n", TreeSize(A));
	printf("Ҷ�ӽڵ����Ϊ��%d\n", TreeLeafSize(A));
	printf("�������Ϊ��%d\n", TreeDepth(A));

	system("pause");
	return 0;
}