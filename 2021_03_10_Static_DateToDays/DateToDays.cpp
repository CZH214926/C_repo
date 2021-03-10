// 根据输入的日期，计算是这一年的第几天

// 测试用例有多组，注意循环输入

// 数组每个位置i 记录的是1 ~ i 月份的天数之和，13个元素，输入的日期是这一年中的第几天：比如输入的是2021_3_10号，则
// 要算出1 2 月份的天数之和，再加上 10 即可。对于2月这个特殊的月份要判断下闰年。 
#include <iostream>
using namespace std;
int main()
{
    int year, month, day;
    int daysArray[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
    int n;
    while (cin >> year >> month >> day) 
    {
        n = daysArray[month - 1] + day;
        if (n > 2  && ((year % 4 == 0 && year % 100 != 0) || year % 400  == 0))
        {
            n += 1;
        }
        cout << n <<endl;
    }
    return 0;
}
