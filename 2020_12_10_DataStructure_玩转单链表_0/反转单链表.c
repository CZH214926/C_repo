/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//��ת�����ã�������

//����һ������3��ָ�����
struct ListNode* reverseList(struct ListNode* head){
         if(head==NULL || head->next==NULL)
         {
             return head;
         }  
         struct ListNode* n1 = NULL,*n2 = head,*n3 = head->next;
         while(n2)
         {
             n2->next = n1;
             n1 = n2;
             n2 = n3;
             if(n3)
             {
                 n3 = n3->next;
             }
         }
         return n1;
}

//����������������ͷ��
typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head){
      //��ʼ��һЩ�����ڵ�
      Node* cur = head;
      Node* next = NULL; //why not Node* next = cur->next;-===>��Ϊ������ΪNUllʱ��NULL->next,����ͱ���
      Node* newHead = NULL;

      while(cur)
      {
          next = cur->next;//(1)

          cur->next = newHead;
          newHead = cur;
          
          cur = next;//(2)
          //(1)(2)�Ͱѵ�����ɲ����ȱ���next,���ҵ���next����Ч�����˿�ָ���쳣

      }
      return newHead;
 }         


