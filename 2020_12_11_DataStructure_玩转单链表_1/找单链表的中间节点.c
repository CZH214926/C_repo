/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//�������ָ�룬��ָ�����ָ���һ��
typedef struct ListNode Node;

struct ListNode* middleNode(struct ListNode* head){
      Node* slow = head;
      Node* fast = head;

      while(fast && fast->next)
      {
          slow = slow->next;
          fast = fast->next->next;
      }
      return slow;
}