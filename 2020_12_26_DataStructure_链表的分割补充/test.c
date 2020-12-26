//题目描述
//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        
        //哨兵位的头节点不存储有效数据
        ListNode* lessListHead,*lessListTail;
        ListNode* greaterListHead,*greaterListTail;
        
        //申请空间
        lessListHead = lessListTail = (ListNode*)malloc(sizeof(ListNode));
        greaterListHead = greaterListTail = (ListNode*)malloc(sizeof(ListNode));
        
        //初始化哨兵位，如果不初始化会产生一系列不可预知的问题
        lessListHead->next = greaterListHead->next = NULL;
        
        ListNode* cur = pHead;
        
        //把小于x的节点尾插到lessListTail后面，同理把大于等于x的节点尾插到greaterListTail后面
        //整个过程用while循环遍历链表
        while(cur){
             if(cur->val < x){
                   lessListTail->next = cur;
                   lessListTail = lessListTail->next;
              }else{
                 greaterListTail->next = cur;
                 greaterListTail = greaterListTail->next;
             }
            cur = cur->next;
        }
        
       //连接两个链表，要注意到哨兵位节点的作用
        lessListTail->next = greaterListHead->next;
        free(greaterListHead);
        
        //这一步骤也很重要，因为greater的最后一个被尾插的节点极有可能不是原链表的最后节点，此时，greaterListTail->next可能指向较短链表的任意
        //一个节点，那么就形成了环，会在while中死循环，最会导致内存超限
        greaterListTail->next = NULL;
        
        //保存新链表的真正头节点，释放哨兵位节点
        ListNode* realHead = lessListHead->next;
        free(lessListHead);
        
        return realHead;
        
        
    }
};