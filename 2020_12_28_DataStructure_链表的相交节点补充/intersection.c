/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //明确相交链表只能是Y形状，绝对不能是X形状，因为一个节点可以被多个节点指向，但是一个节点不能指向多个节点。
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
    while(longList && shortList)//此时longList和shortList是同样长链表的头节点，所以只放一个就可以了，当然&&上另一个也没撒问题
    {
        if(longList==shortList)
        {
            return longList;//return shortList->next也可以
        }
        else
        {
            longList  = longList->next;
            shortList = shortList->next;
        }
    }

    return NULL;
}