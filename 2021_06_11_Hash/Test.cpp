#include<iostream>
#include <vector>
#include<string>
#include <unordered_set>
#include <set>

#include <time.h>
using namespace std;

void testop()
{
	int n = 10000;
	vector<int> v;
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		v.push_back(rand());
	}

	set<int> s;
	size_t begin1 = clock();
	for (auto e : v)
	{
		s.insert(e);
	}
	size_t end1 = clock();

	unordered_set<int> us;
	size_t begin2 = clock();
	for (auto e : v)
	{
		us.insert(e);
	}
	size_t end2 = clock();

	cout << "set insert:" << end1 - begin1 << endl;
	cout << "unordered_set insert:" << end2 - begin2 << endl;
}

#include "HashTable.h"
#include "unordered_map.h"
#include "unordered_set.h"
#include "czhSet.h"

int main()
{
	//testop();
	//Close::TestHashTable();
	czh::test_unordered_set();
	czh::test_unordered_map();
	czh::test_czhset();

	return 0;
}