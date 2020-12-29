//题目描述：给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//第一种方法
//快慢指针进入环后，二者终会相遇，再相遇节点处断开链表然后就是两个
//链表，此时问题就转换成了求两个链表的相交节点
typedef struct ListNode Node;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //先找到在环中的相遇节点
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                break;
            }
        }
        //如果此时程序进入到if中证明链表无环
        if(fast==NULL || fast->next==NULL){
            return NULL;
        }
        Node* head1 = head;
        //断开链表
        Node* head2 = slow->next;
        slow->next = NULL;
      
       return getIntersectionNode(head1,head2);


    }
    //求两个链表的相交节点的方法
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
};
 


 //第一种方法的变形
 //快慢指针进入环后，二者终会相遇，再相遇节点处逻辑上断开链表其实没有断开，slow->next作为新的头，在计算长度的时候，lenA= lenB
 //要初始化为1
 //链表，此时问题就转换成了求两个链表的相交节点
typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    //此时找到二者相遇的节点slow == fast
    if(fast==NULL || fast->next == NULL){
        return NULL;
    }

    //定义逻辑上两个链表的头节点
    Node* curA = head;

    Node* newHead = slow->next;
    Node* curB = newHead;
    
    int lenA = 1;
    int lenB = 1;

    while(curA != slow){
        lenA++;
        curA= curA->next;
    }
    while(curB != slow){
        lenB++;
        curB = curB->next;
    }

    int gap = abs(lenA - lenB);

    Node* longerList = head;
    Node* shortList = newHead;

    if(lenA < lenB){
        longerList = newHead;
        shortList = head;
    }

    while(gap--){
        longerList = longerList->next;
    }
   //此时long和short链表在同一起跑线上
    while(longerList){//while(shortList)
         if(longerList == shortList){
             return longerList;
         }else{
             longerList = longerList->next;
             shortList = shortList->next;
         }
    }

    return NULL;

}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//方法2：需要推导和证明
//快慢指针加高中物理的相遇问题
typedef struct ListNode Node;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //先找到在环中的相遇节点
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                break;
            }
        }
        //如果此时程序进入到if中证明链表无环
        if(fast==NULL || fast->next==NULL){
            return NULL;
        }
        
        Node* meet  = slow;

        while(head!=meet){
            head=head->next;
            meet = meet->next;
        }
       return meet;


    }

};
