
//题目描述：对单链表进行插入排序
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//单链表插入排序
typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
      if(head == NULL || head->next == NULL){
          return head;
      }
      //这3行代码的顺序是不能乱的否则就会出错，while(cur)进不去
      //只剩下个头
      Node* sorthead = head;
      
      Node* cur = head->next;
      sorthead->next =NULL;

      while(cur){
          Node* next = cur->next;
          // 把cur插入到sorthead链表中并且保持有序
          //1、如果cur->val<=sorthead->val;那么把cur头插到sorthead
          //中
          if(cur->val <= sorthead->val){
              //头插
              cur->next = sorthead;
              sorthead = cur;
          }
          else{
                //尾插或者中间插
                   
                    Node* sortprev = sorthead;
                    Node* sortcur = sortprev->next;
                    //中间插
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
                    //尾插
                    if(sortcur==NULL){
                        sortprev->next = cur;
                        cur->next =NULL;//尾插的时候别忘记置空，否则会链表内形成环，死循环
                    }
            
                }
          //更新迭代cur
          cur = next;
      }
      return sorthead;
}