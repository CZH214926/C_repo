/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
         //�ϲ�������������
         if(l1==NULL)
         {
             return l2;
         }
         if(l2==NULL)
         {
             return l1;
         }
         //�ߵ�����������������һ���Ƿǿյ�
         //����һ���ڱ�λ�ڵ㣬ר������ͷ��
         Node* head = NULL;
         Node* tail = NULL;
         head = tail = (Node*)malloc(sizeof(Node));
         //l1�ߵ�����β��������l2�ߵ�����β���ͽ���ѭ���������ѭ����������&&
         while(l1 && l2)
         {
             if(l1->val < l2->val)
             {
                tail->next = l1;
                l1 = l1->next; 
             }
             else
             {
               tail->next = l2;
               l2 = l2->next;
             }
             tail = tail->next;
         }
         if(l1==NULL)
         {
             tail->next = l2;
         }
         else
         {
              tail->next = l1;
         }
         //����������ͷ�ڵ㣬Ҫ���ڱ�λ�ڵ��ͷŵ�����Ҫ�ǵñ���Ҫ���ص������ͷ�ڵ㣬����������ͷ�ڵ�
         Node* realHead = head->next;
         free(head);//�ڱ�λͷ�ڵ㲻����β�ڵ�tail�������ƶ�
         return realHead;

}