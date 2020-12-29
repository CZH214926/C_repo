//��Ŀ����������һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//��һ�ַ���
//����ָ����뻷�󣬶����ջ��������������ڵ㴦�Ͽ�����Ȼ���������
//������ʱ�����ת������������������ཻ�ڵ�
typedef struct ListNode Node;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //���ҵ��ڻ��е������ڵ�
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                break;
            }
        }
        //�����ʱ������뵽if��֤�������޻�
        if(fast==NULL || fast->next==NULL){
            return NULL;
        }
        Node* head1 = head;
        //�Ͽ�����
        Node* head2 = slow->next;
        slow->next = NULL;
      
       return getIntersectionNode(head1,head2);


    }
    //������������ཻ�ڵ�ķ���
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
    while(longList && shortList)//��ʱlongList��shortList��ͬ���������ͷ�ڵ㣬����ֻ��һ���Ϳ����ˣ���Ȼ&&����һ��Ҳû������
    {
            if(longList==shortList)
            {
                return longList;//return shortList->nextҲ����
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
 


 //��һ�ַ����ı���
 //����ָ����뻷�󣬶����ջ��������������ڵ㴦�߼��϶Ͽ�������ʵû�жϿ���slow->next��Ϊ�µ�ͷ���ڼ��㳤�ȵ�ʱ��lenA= lenB
 //Ҫ��ʼ��Ϊ1
 //������ʱ�����ת������������������ཻ�ڵ�
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
    //��ʱ�ҵ����������Ľڵ�slow == fast
    if(fast==NULL || fast->next == NULL){
        return NULL;
    }

    //�����߼������������ͷ�ڵ�
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
   //��ʱlong��short������ͬһ��������
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
//����2����Ҫ�Ƶ���֤��
//����ָ��Ӹ����������������
typedef struct ListNode Node;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //���ҵ��ڻ��е������ڵ�
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                break;
            }
        }
        //�����ʱ������뵽if��֤�������޻�
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
