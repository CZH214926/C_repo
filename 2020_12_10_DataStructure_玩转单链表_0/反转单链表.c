/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//反转（逆置）单链表

//方法一：定义3个指针迭代
struct ListNode* reverseList(struct ListNode* head){
         if(head==NULL || head->next==NULL)
         {
             return head;
         }  
         struct ListNode* n1 = NULL,*n2 = head,*n3 = head->next;
         while(n2)
         {
             n2->next = n1;
             n1 = n2;
             n2 = n3;
             if(n3)
             {
                 n3 = n3->next;
             }
         }
         return n1;
}

//方法二：巧妙利用头插
typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head){
      //初始化一些辅助节点
      Node* cur = head;
      Node* next = NULL; //why not Node* next = cur->next;-===>因为当链表为NUll时，NULL->next,程序就崩了
      Node* newHead = NULL;

      while(cur)
      {
          next = cur->next;//(1)

          cur->next = newHead;
          newHead = cur;
          
          cur = next;//(2)
          //(1)(2)就把迭代完成并且先保存next,并且迭代next，有效避免了空指针异常

      }
      return newHead;
 }         


