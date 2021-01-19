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
//层序遍历和二叉树的前中后序遍历不一样不需要递归，需要利用到队列
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
	{
		QueueDestory(&q);
		return;
	}
	//不等于NULL就先把root送进队列
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_data);
		//把front的左右孩子也送进队列,空队列的不进入队列了
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
// 判断二叉树是否是完全二叉树
//思路和层序遍历类似 返回1证明是完全二叉树，返回0证明不是完全二叉树
//把NULL也入队列，循环时pop时遇到NULL就break,然后判断队列中剩余数据是否有非NULL的数据
//有的话就不是完全二叉树，没有就是完全二叉树
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
// 二叉树第k层节点个数  和 叶子结点个数一样
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
//求树的深度
int TreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//把左子树和左子树的深度先保存
	//否则重复计算太多
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
	

	printf("树的结点个数为：%d\n", TreeSize(A));
	printf("叶子节点个数为：%d\n", TreeLeafSize(A));
	printf("树的深度为：%d\n", TreeDepth(A));
	printf("树第3层结点个数为：%d\n", BinaryTreeLevelKSize(A,3));

	BinaryTreeLevelOrder(A);
	printf("BinaryTreeComplete：%d\n", BinaryTreeComplete(A));
	system("pause");
	return 0;
}