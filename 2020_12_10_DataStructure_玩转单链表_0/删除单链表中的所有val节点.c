/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 //ɾ��������������valֵ
 //�ҵ�Ҫɾ���Ľڵ��û���ҵ�Ҫɾ���Ľڵ㣬pre��cur�ĸ��·�ʽ�ǲ�һ����
 typedef  struct ListNode Node;
struct ListNode* removeElements(struct ListNode* head, int val){
        Node* pre = NULL,*cur = head;
        while(cur)
        {
            if(cur->val == val)
            {
                //ɾ���ڵ�
                //Ҫɾ���Ľڵ���ͷ�ڵ�
                if(cur == head)//if(prev==NULL)
                {
                    //ͷɾ
                    head = cur->next;
                    free(cur);
                    cur = head;
                }
                else
                {
                    //ɾ����ͷ�ڵ�
                    pre->next = cur->next;
                    free(cur);
                    cur = pre->next;
                }
            }
            else
            {
               //����
               pre = cur;
               cur = cur->next;
            }
        }
        return head;
}