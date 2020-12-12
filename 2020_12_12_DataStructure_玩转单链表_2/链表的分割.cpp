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
        ListNode* lessListHead = NULL;
        ListNode* lessListTail = NULL;
        ListNode* greaterListHead = NULL;
        ListNode* greaterListTail = NULL;
        
        lessListHead = lessListTail = (ListNode*)malloc(sizeof(ListNode));
        greaterListHead = greaterListTail = (ListNode*)malloc(sizeof(ListNode));
        
        ListNode* cur = pHead;
        
        while(cur){
             if(cur->val<x){
                   lessListTail->next = cur;
                   lessListTail = lessListTail->next;
              }else{
                 greaterListTail->next = cur;
                 greaterListTail = greaterListTail->next;
             }
            cur = cur->next;
        }
        greaterListTail->next = NULL;
       ListNode* greaterListRealHead=greaterListHead->next;
       free(greaterListHead);
       lessListTail->next = greaterListRealHead;
       ListNode* FinalHead = lessListHead->next;
       free(lessListHead);
       return FinalHead;
        
    }
};