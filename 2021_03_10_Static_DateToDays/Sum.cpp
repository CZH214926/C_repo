// ��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C��

//������ static ������ĳ�Ա 
class Sum{
public:
    Sum(){
         //���췽�������ۼ�
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