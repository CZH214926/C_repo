#include <iostream>
#include "vector.hpp"
#include <algorithm>
#include <string>

using namespace std;

void test_myvector_01()
{
	czh::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(32);
	v.push_back(4);
	auto it = v.begin();
	while (it != v.end()) {
		if (*it % 2 == 0)
		{
			v.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
void test_myvector_02()
{
	czh::vector<string> sv;
	sv.push_back("gfurgu");
	sv.push_back("jfriegj");
	sv.push_back("ffif");
	sv.push_back("WFHIEFI");
	sv.push_back("urghug");
	for (const auto& e : sv)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{

	test_myvector_02();
	return 0;
}