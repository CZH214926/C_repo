/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //求两个链表的相交节点
 typedef struct ListNode Node;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0;
    int lenB = 0;
    Node* curA = headA;
    Node* curB = headB;
    //计算出链表A和B的长度
    while(curA)
    {
        lenA++;
        curA=curA->next;
    }
    while(curB)
    {
        lenB++;
        curB = curB->next;
    }
    //让长链表先走，先走的距离为两个链表的长度的差，达到二者在同一位置的目的，然后两个同时走并相互比较直到找到相交节点
    int gap = abs(lenA-lenB);

    Node *longList = headA,*shortList = headB;
    if(lenA<lenB)
    {
        longList = headB;
        shortList = headA;
    }
    while(gap--)
    {
        longList = longList->next;
    }
    while(longList && shortList)
    {
        if(longList==shortList)
        {
            return longList;//return shortList->next;
        }
        else
        {
            longList  = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;


}