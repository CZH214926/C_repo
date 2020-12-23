/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//题目描述：
//现有一链表的头指针ListNode* pHead,给定一定值x,编写一段代码将所有小于x的节点排在其余节点之前，
//且不能改变原来的数据相对顺序，返回重新排列后的链表的头指针
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        ListNode* lessListHead = NULL;
        ListNode* lessListTail = NULL;
        ListNode* greaterListHead = NULL;
        ListNode* greaterListTail = NULL;

        //哨兵位节点
        lessListHead = lessListTail = (ListNode*)malloc(sizeof(ListNode));
        greaterListHead = greaterListTail = (ListNode*)malloc(sizeof(ListNode));
        
        ListNode* cur = pHead;
        
		//遍历原来的链表将小于x的节点尾插到lessList链表的尾巴上，每次尾插完别忘记更新尾节点lessListTail
		//大于等于x的节点，同理尾插到greaterListHead的尾巴上
        while(cur){
             if(cur->val < x){
                   lessListTail->next = cur;
                   lessListTail = lessListTail->next;
              }else{
                 greaterListTail->next = cur;
                 greaterListTail = greaterListTail->next;
             }
            cur = cur->next;//遍历每个节点
        }
        greaterListTail->next = NULL;
		//这个置为NULL，因为链表中比x大的众多节点中最后一个并不一定是原来链表的最后一个节点
		//如果每个这个一定会出错

		//将哨兵位节点删除，并大小链表链接，返回小链表的真正的头节点。
       ListNode* greaterListRealHead=greaterListHead->next;
       free(greaterListHead);
       lessListTail->next = greaterListRealHead;
       ListNode* FinalHead = lessListHead->next;
       free(lessListHead);
       return FinalHead;
        
    }
};