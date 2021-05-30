#include <iostream>
#include <algorithm>
using namespace std;
#include "AVLTree.hpp"

void TestAVLTree()
{
	AVLTree<int, int> t;
	t.insert(make_pair(4, 2));
	t.insert(make_pair(2, 2));
	t.insert(make_pair(6, 2));
	t.insert(make_pair(1, 2));
	t.insert(make_pair(3, 2));
	t.insert(make_pair(5, 2));
	t.insert(make_pair(15, 2));
	t.insert(make_pair(7, 2));
	t.insert(make_pair(16, 2));
	t.insert(make_pair(14, 2));
	t.InOrder();
	if (t.IsBalance())
		cout << "Æ½ºâ" << endl;
}
int main()
{
	TestAVLTree();
	
	return 0;
}