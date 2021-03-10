// 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）

//考虑用 static 修饰类的成员 
class Sum{
public:
    Sum(){
         //构造方法里做累加
        _ret += _i;
        _i++;
    }
    static int GetRet()
    {
       return _ret;
    }
    static void init(){
        _i = 1;
        _ret = 0;
    }
private:
    static int _i;
    static int _ret;
};
int Sum::_i = 1;
int Sum::_ret = 0;
class Solution {
public:
    int Sum_Solution(int n) {
        Sum::init();
        Sum arr[n];
        return Sum::GetRet();
    }
};