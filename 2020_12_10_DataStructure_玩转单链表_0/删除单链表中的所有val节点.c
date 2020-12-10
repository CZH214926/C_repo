/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 //删除单链表中所有val值
 //找到要删除的节点和没有找到要删除的节点，pre和cur的更新方式是不一样的
 typedef  struct ListNode Node;
struct ListNode* removeElements(struct ListNode* head, int val){
        Node* pre = NULL,*cur = head;
        while(cur)
        {
            if(cur->val == val)
            {
                //删除节点
                //要删除的节点是头节点
                if(cur == head)//if(prev==NULL)
                {
                    //头删
                    head = cur->next;
                    free(cur);
                    cur = head;
                }
                else
                {
                    //删除非头节点
                    pre->next = cur->next;
                    free(cur);
                    cur = pre->next;
                }
            }
            else
            {
               //迭代
               pre = cur;
               cur = cur->next;
            }
        }
        return head;
}