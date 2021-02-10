class Solution {
    //���������ֵ�ĩβ��ʼ��ÿ����Ӷ�Ҫ���Ͻ�λnext��0����1��
    //����ѡ��retstr+=�ķ�ʽβ�壬Ȼ������㷨���е����ã�ʱ�临�Ӷ�ΪO(N)
    //������ѡ��ͷ��ķ�ʽ����ͷ��ķ�ʽ�ƶ�����̫�࣬ʱ�临�Ӷ�ΪO(N^2)��
public:
    string addStrings(string num1, string num2) {
         int end1 = num1.size()-1;
         int end2 = num2.size()-1;
         int next = 0;
         string retstr = "";
         while(end1 >=0 || end2 >=0){
             int val1 = 0,val2 = 0;
             if(end1 >= 0){
                 val1 = num1[end1] - '0';
             }
             if(end2 >= 0){
                 val2 = num2[end2] - '0';
             }
             int ret = val1 + val2 + next;
             if(ret > 9){
                 ret -=10;
                 next = 1;
             }
             else{
                 next = 0;
             }
           retstr += (ret + '0');
           //retstr.insert(retstr.begin(),'0'+ret);
           end1--;
           end2--;
         }

         if(next == 1)
            retstr += '1';
            //retstr.insert(retstr.begin(),'1');
         
         reverse(retstr.begin(),retstr.end());
         return retstr;
    }
};