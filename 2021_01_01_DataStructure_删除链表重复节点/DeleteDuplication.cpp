/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
//要考虑在链表首部分和链表尾部分出现重复节点怎么办，这是两种特殊的情况
//1->2->3->3->4->5->NULL这是最一般的情况要把首尾出现重复节点的情况考虑进去
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
             //三个指针都要迭代
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
               
               //连接prev和next
               if(prev==NULL)
               {
                   //如果程序走到这个分支里，证明在链表的头部分就出现了重复的节点，例如1->1->1->2->3->5->NULL
                    pHead = next;
               }
               else
               {
                    prev->next = next;
               }
               
               //释放重复的节点
               while(cur!=next)
               {
                   ListNode* del = cur;
                   cur = cur->next;
                   free(del);
               }
               
               //此时cur和next就是在一个位置的了
               //更新next
               if(cur)
               {
                  next = cur->next;  
               }
              
           }
        }
        return pHead;
    }
};