
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

//思路将链表切割成一半的链表，并将后一半的链表逆置(反转)
//然后比较两个链表的节点值是否一样，不一样就证明不是回文结构return false
//就可以得出，链表是否对称，要考虑到奇偶数的问题，涉及到快慢指针和链表逆置的问题。

typedef struct ListNode Node;
class PalindromeList {
public:
    //逆置链表————————把原来链表中的节点拿下来头插到新的头上。
    struct ListNode* reverseList(struct ListNode* head){
      //初始化一些辅助节点
      Node* cur = head;
      Node* next = NULL; //why not Node* next = cur->next;-===>因为当链表为NUll时，NULL->next,程序就崩了
      Node* newHead = NULL;

      while(cur)
      {
          next = cur->next;//(1)

          cur->next = newHead;
          newHead = cur;
          
          cur = next;//(2)
          //(1)(2)就把迭代完成并且先保存next,并且迭代next，有效避免了空指针异常

      }
      return newHead;
 }
    //用快慢指针方法找到中间节点，并将其断开这里肯定要用到中间节点的前一个节点
    bool chkPalindrome(ListNode* A) {
        // write code here
		
        Node* slow = A;
        Node* fast = A;
        Node* prev = NULL;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        Node* head = reverseList(slow);
        //或者让slow重新接收新链表的头
        //slow = reverseList(slow);
        
        while(A)//这里不用加A&&slow的原因是链表长度为奇数的时候，A是较短的那个，为偶数的时候两个链表是相等长度的
        {
            if(A->val!=head->val){
              return false;
            }else{
                A=A->next;
                head=head->next;
            }
        }
        //程序走到走到这里说明A被遍历完，还没有找到不同的====>A->val == head->val;都是满足的所以是回文
        return true; 
    }
};