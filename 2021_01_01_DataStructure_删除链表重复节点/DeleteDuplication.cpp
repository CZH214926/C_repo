/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
//Ҫ�����������ײ��ֺ�����β���ֳ����ظ��ڵ���ô�죬����������������
//1->2->3->3->4->5->NULL������һ������Ҫ����β�����ظ��ڵ��������ǽ�ȥ
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL || pHead->next == NULL)
        {
              return pHead;
        }
        ListNode* prev = NULL;
        ListNode* cur = pHead;
        ListNode* next = cur->next;
        
        while(next){
          if(cur->val!=next->val)
          {
             //����ָ�붼Ҫ����
              prev = cur;
              cur = next;
              next = next->next;
          }
           else
           {
                while(next && cur->val == next->val)
                {
                        next = next->next;
                }
               
               //����prev��next
               if(prev==NULL)
               {
                   //��������ߵ������֧�֤���������ͷ���־ͳ������ظ��Ľڵ㣬����1->1->1->2->3->5->NULL
                    pHead = next;
               }
               else
               {
                    prev->next = next;
               }
               
               //�ͷ��ظ��Ľڵ�
               while(cur!=next)
               {
                   ListNode* del = cur;
                   cur = cur->next;
                   free(del);
               }
               
               //��ʱcur��next������һ��λ�õ���
               //����next
               if(cur)
               {
                  next = cur->next;  
               }
              
           }
        }
        return pHead;
    }
};