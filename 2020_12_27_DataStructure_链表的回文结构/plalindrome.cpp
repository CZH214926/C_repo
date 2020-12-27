
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

//˼·�������и��һ�������������һ�����������(��ת)
//Ȼ��Ƚ���������Ľڵ�ֵ�Ƿ�һ������һ����֤�����ǻ��Ľṹreturn false
//�Ϳ��Եó��������Ƿ�Գƣ�Ҫ���ǵ���ż�������⣬�漰������ָ����������õ����⡣

typedef struct ListNode Node;
class PalindromeList {
public:
    //������������������������ԭ�������еĽڵ�������ͷ�嵽�µ�ͷ�ϡ�
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
    //�ÿ���ָ�뷽���ҵ��м�ڵ㣬������Ͽ�����϶�Ҫ�õ��м�ڵ��ǰһ���ڵ�
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
        //������slow���½����������ͷ
        //slow = reverseList(slow);
        
        while(A)//���ﲻ�ü�A&&slow��ԭ����������Ϊ������ʱ��A�ǽ϶̵��Ǹ���Ϊż����ʱ��������������ȳ��ȵ�
        {
            if(A->val!=head->val){
              return false;
            }else{
                A=A->next;
                head=head->next;
            }
        }
        //�����ߵ��ߵ�����˵��A�������꣬��û���ҵ���ͬ��====>A->val == head->val;��������������ǻ���
        return true; 
    }
};