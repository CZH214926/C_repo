#include "string.h"
#include <iostream>
using namespace std;

void TestString01()
{
	czh::string s1("chen");
	czh::string s2("dddd");
	if (s1 > s2) cout << "ด๓" << endl;
	else cout << "ะก" << endl;

	s1.erase(1, 2);
	cout << s1;
}
int main()
{
	TestString01();
	return 0;
}