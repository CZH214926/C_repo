/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param pListHead ListNode�� 
 * @param k int���� 
 * @return ListNode��
 */
typedef struct ListNode Node;
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    // write code here
    Node *slow = pListHead;
    Node *fast = pListHead;
    //��fast��slow��k��
    while(k--)
    {
         //��һk����������
        if(fast)
        {
             fast = fast->next;
        }
        else
        {
            return NULL;
        }
    }
    //��ʼ��
    while(fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}