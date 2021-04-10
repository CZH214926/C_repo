#include <iostream>
#include "List.h"
#include <vector>
#include <algorithm>
using namespace czh;
using std::vector;
// 测试list的构造
void TestList01()
{
	list<int> l1;
	list<int> l2(10, 5);
	//PrintList(l2);
	int array[] = {1,2, 3, 4, 5 };
	vector<int> iv;
	for (int i = 0; i < 10; i++)
	{
		iv.push_back(i);
	}
	list<int> l3(array,array + sizeof(array) / sizeof(array[0]) );
	PrintList(l3);

	list<int> l4 = l3;

	PrintList(l4);

}
//测试pop_back 和 push_back
void TestList02()
{
	list<int> il;
	
	for (int i = 0; i < 10; i++)
	{
		il.push_front(i);
	}
	PrintList(il);
	
	
	PrintList(il);
}
void TestList03()
{
	int array[] = { 1, 2, 3, 4, 5 };
	list<int> il(array, array + sizeof(array) / sizeof(array[0]));
	/*auto pos = il.begin();
	il.insert(pos, 23);
	PrintList(il);
	++pos;
	il.insert(pos, 34);
	PrintList(il);

	il.erase(il.begin());
	il.erase(pos);
	PrintList(il);*/

	

	auto il_it = il.begin();
	while (il_it != il.end())
	{
		il_it = il.erase(il_it);	
	}
	cout << il.size() << endl;
}
int main()
{
	TestList03();
	return 0;
}