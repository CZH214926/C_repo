#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Queue.h"
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
//��������Ͷ�������ǰ�к��������һ������Ҫ�ݹ飬��Ҫ���õ�����
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
	{
		QueueDestory(&q);
		return;
	}
	//������NULL���Ȱ�root�ͽ�����
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_data);
		//��front�����Һ���Ҳ�ͽ�����,�ն��еĲ����������
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
	QueueDestory(&q);
	printf("\n");
}
// �ж϶������Ƿ�����ȫ������
//˼·�Ͳ���������� ����1֤������ȫ������������0֤��������ȫ������
//��NULLҲ����У�ѭ��ʱpopʱ����NULL��break,Ȼ���ж϶�����ʣ�������Ƿ��з�NULL������
//�еĻ��Ͳ�����ȫ��������û�о�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
	{
		QueueDestory(&q);
		return 1;
	}
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePop(&q);
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);

	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front)
		{
			QueueDestory(&q);
			return 0;
		}
		QueuePop(&q);
	}

	QueueDestory(&q);
	return 1;

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
// ��������k��ڵ����  �� Ҷ�ӽ�����һ��
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right,k-1);

}
//���������
int TreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//����������������������ȱ���
	//�����ظ�����̫��
	int leftDepth = TreeDepth(root->_left);
	int rightDepth = TreeDepth(root->_right);

	return 1+(leftDepth > rightDepth ? leftDepth : rightDepth);
}

int main()
{
	BTNode* A = CreateBinTreeNode('A');
	BTNode* B = CreateBinTreeNode('B');
	BTNode* C = CreateBinTreeNode('C');
	BTNode* D = CreateBinTreeNode('D');
	BTNode* E = CreateBinTreeNode('E');
	BTNode* F = CreateBinTreeNode('F');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;
	C->_right = F;

	/*PrevOrder(A);
	
	InOrder(A);
	
	PostOrder(A);*/
	

	printf("���Ľ�����Ϊ��%d\n", TreeSize(A));
	printf("Ҷ�ӽڵ����Ϊ��%d\n", TreeLeafSize(A));
	printf("�������Ϊ��%d\n", TreeDepth(A));
	printf("����3�������Ϊ��%d\n", BinaryTreeLevelKSize(A,3));

	BinaryTreeLevelOrder(A);
	printf("BinaryTreeComplete��%d\n", BinaryTreeComplete(A));
	system("pause");
	return 0;
}