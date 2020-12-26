//��Ŀ����
//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ��
//�Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        
        //�ڱ�λ��ͷ�ڵ㲻�洢��Ч����
        ListNode* lessListHead,*lessListTail;
        ListNode* greaterListHead,*greaterListTail;
        
        //����ռ�
        lessListHead = lessListTail = (ListNode*)malloc(sizeof(ListNode));
        greaterListHead = greaterListTail = (ListNode*)malloc(sizeof(ListNode));
        
        //��ʼ���ڱ�λ���������ʼ�������һϵ�в���Ԥ֪������
        lessListHead->next = greaterListHead->next = NULL;
        
        ListNode* cur = pHead;
        
        //��С��x�Ľڵ�β�嵽lessListTail���棬ͬ��Ѵ��ڵ���x�Ľڵ�β�嵽greaterListTail����
        //����������whileѭ����������
        while(cur){
             if(cur->val < x){
                   lessListTail->next = cur;
                   lessListTail = lessListTail->next;
              }else{
                 greaterListTail->next = cur;
                 greaterListTail = greaterListTail->next;
             }
            cur = cur->next;
        }
        
       //������������Ҫע�⵽�ڱ�λ�ڵ������
        lessListTail->next = greaterListHead->next;
        free(greaterListHead);
        
        //��һ����Ҳ����Ҫ����Ϊgreater�����һ����β��Ľڵ㼫�п��ܲ���ԭ��������ڵ㣬��ʱ��greaterListTail->next����ָ��϶����������
        //һ���ڵ㣬��ô���γ��˻�������while����ѭ������ᵼ���ڴ泬��
        greaterListTail->next = NULL;
        
        //���������������ͷ�ڵ㣬�ͷ��ڱ�λ�ڵ�
        ListNode* realHead = lessListHead->next;
        free(lessListHead);
        
        return realHead;
        
        
    }
};