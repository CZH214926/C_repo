
//��Ŀ�������Ե�������в�������
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//�������������
typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
      if(head == NULL || head->next == NULL){
          return head;
      }
      //��3�д����˳���ǲ����ҵķ���ͻ����while(cur)����ȥ
      //ֻʣ�¸�ͷ
      Node* sorthead = head;
      
      Node* cur = head->next;
      sorthead->next =NULL;

      while(cur){
          Node* next = cur->next;
          // ��cur���뵽sorthead�����в��ұ�������
          //1�����cur->val<=sorthead->val;��ô��curͷ�嵽sorthead
          //��
          if(cur->val <= sorthead->val){
              //ͷ��
              cur->next = sorthead;
              sorthead = cur;
          }
          else{
                //β������м��
                   
                    Node* sortprev = sorthead;
                    Node* sortcur = sortprev->next;
                    //�м��
                    while(sortcur){
                        if(cur->val <= sortcur->val){
                            sortprev->next = cur;
                            cur->next = sortcur;
                            break;
                        }
                        else{
                            sortprev = sortcur;
                            sortcur = sortcur->next;
                        }
                    }
                    //β��
                    if(sortcur==NULL){
                        sortprev->next = cur;
                        cur->next =NULL;//β���ʱ��������ÿգ�������������γɻ�����ѭ��
                    }
            
                }
          //���µ���cur
          cur = next;
      }
      return sorthead;
}