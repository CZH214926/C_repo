/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//��Ŀ������
//����һ�����ͷָ��ListNode* pHead,����һ��ֵx,��дһ�δ��뽫����С��x�Ľڵ���������ڵ�֮ǰ��
//�Ҳ��ܸı�ԭ�����������˳�򣬷����������к�������ͷָ��
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        ListNode* lessListHead = NULL;
        ListNode* lessListTail = NULL;
        ListNode* greaterListHead = NULL;
        ListNode* greaterListTail = NULL;

        //�ڱ�λ�ڵ�
        lessListHead = lessListTail = (ListNode*)malloc(sizeof(ListNode));
        greaterListHead = greaterListTail = (ListNode*)malloc(sizeof(ListNode));
        
        ListNode* cur = pHead;
        
		//����ԭ��������С��x�Ľڵ�β�嵽lessList�����β���ϣ�ÿ��β��������Ǹ���β�ڵ�lessListTail
		//���ڵ���x�Ľڵ㣬ͬ��β�嵽greaterListHead��β����
        while(cur){
             if(cur->val < x){
                   lessListTail->next = cur;
                   lessListTail = lessListTail->next;
              }else{
                 greaterListTail->next = cur;
                 greaterListTail = greaterListTail->next;
             }
            cur = cur->next;//����ÿ���ڵ�
        }
        greaterListTail->next = NULL;
		//�����ΪNULL����Ϊ�����б�x����ڶ�ڵ������һ������һ����ԭ����������һ���ڵ�
		//���ÿ�����һ�������

		//���ڱ�λ�ڵ�ɾ��������С�������ӣ�����С�����������ͷ�ڵ㡣
       ListNode* greaterListRealHead=greaterListHead->next;
       free(greaterListHead);
       lessListTail->next = greaterListRealHead;
       ListNode* FinalHead = lessListHead->next;
       free(lessListHead);
       return FinalHead;
        
    }
};