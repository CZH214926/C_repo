/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param pListHead ListNode类 
 * @param k int整型 
 * @return ListNode类
 */
typedef struct ListNode Node;
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    // write code here
    Node *slow = pListHead;
    Node *fast = pListHead;
    //让fast比slow多k步
    while(k--)
    {
         //万一k大于链表长度
        if(fast)
        {
             fast = fast->next;
        }
        else
        {
            return NULL;
        }
    }
    //开始走
    while(fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}