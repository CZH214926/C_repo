/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //������������ཻ�ڵ�
 typedef struct ListNode Node;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0;
    int lenB = 0;
    Node* curA = headA;
    Node* curB = headB;
    //���������A��B�ĳ���
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
    //�ó��������ߣ����ߵľ���Ϊ��������ĳ��ȵĲ�ﵽ������ͬһλ�õ�Ŀ�ģ�Ȼ������ͬʱ�߲��໥�Ƚ�ֱ���ҵ��ཻ�ڵ�
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