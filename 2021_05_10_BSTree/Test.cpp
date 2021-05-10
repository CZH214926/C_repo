#include "BST.h"
#include <iostream>
#include <string>
using namespace std;

void TestBST()
{
	//// ʵ�ֵ����ֵ�
	//BSTree<string, string> bst;
	//bst.insert("vector", "��̬����");
	//bst.insert("list", "����");
	//bst.insert("priority_queue", "���ȼ�����");
	//bst.insert("string", "�ַ���");

	//string str;
	//while (cin >> str)
	//{
	//	auto ret = bst.Find(str);
	//	if (ret)
	//	{
	//		cout << ret->_value << endl;
	//	}
	//	else
	//	{
	//		cout << "not found" << endl;
	//	}
	//}
	//
	// �ҵ������Ե�ˮ��
	string fruit[] = { "ƻ��", "ƻ��", "ƻ��", "ƻ��", "����", "����", "����", "����", "����", "�㽶", "ɽ��", "����" };
	BSTree<string, int> bst1;
	for (auto& str : fruit)
	{
		auto ret = bst1.Find(str);
		if (ret == nullptr)
		{
			bst1.insert(str,1);
		}
		else
		{
			(ret->_value)++;
		}
	}
	bst1.Inorder();
}
int main()
{
	TestBST();
	
	return 0;
}