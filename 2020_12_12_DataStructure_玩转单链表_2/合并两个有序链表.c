/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
         //合并两个有序链表
         if(l1==NULL)
         {
             return l2;
         }
         if(l2==NULL)
         {
             return l1;
         }
         //走到这里两个有序链表一定是非空的
         //定义一个哨兵位节点，专门用来头插
         Node* head = NULL;
         Node* tail = NULL;
         head = tail = (Node*)malloc(sizeof(Node));
         //l1走到链表尾部，或者l2走到链表尾部就结束循环，则继续循环的条件是&&
         while(l1 && l2)
         {
             if(l1->val < l2->val)
             {
                tail->next = l1;
                l1 = l1->next; 
             }
             else
             {
               tail->next = l2;
               l2 = l2->next;
             }
             tail = tail->next;
         }
         if(l1==NULL)
         {
             tail->next = l2;
         }
         else
         {
              tail->next = l1;
         }
         //返回真正的头节点，要把哨兵位节点释放掉，但要记得保存要返回的链表的头节点，才是真正的头节点
         Node* realHead = head->next;
         free(head);//哨兵位头节点不动，尾节点tail别忘记移动
         return realHead;

}