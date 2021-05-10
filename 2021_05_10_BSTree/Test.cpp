#include "BST.h"
#include <iostream>
#include <string>
using namespace std;

void TestBST()
{
	//// 实现电子字典
	//BSTree<string, string> bst;
	//bst.insert("vector", "动态数组");
	//bst.insert("list", "链表");
	//bst.insert("priority_queue", "优先级队列");
	//bst.insert("string", "字符串");

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
	// 找到大家最爱吃的水果
	string fruit[] = { "苹果", "苹果", "苹果", "苹果", "榴莲", "榴莲", "榴莲", "榴莲", "榴莲", "香蕉", "山竹", "橘子" };
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