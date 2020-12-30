/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
 //题目描述：
 //复制带随机指针链表
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
    if(head==NULL){
        return NULL;
    }
	//1、复制每个节点然后连接到原来节点的后面，得到新的链表
    Node* cur = head;
    while(cur){
        //复制节点
        Node* copy = (Node*)malloc(sizeof(Node));
        copy->next = NULL;
        copy->random=NULL;
        copy->val = cur->val;
        //连接
        Node* next = cur->next;
        cur->next = copy;
        copy->next=next;
        //迭代cur
        cur = next;
    }
    //2、处理每个拷贝节点的random
    cur = head;
    while(cur){
        Node* copy = cur->next;
        if(cur->random)
        copy->random = cur->random->next;
        else
        copy->random = NULL;
        //更新cur
        cur = copy->next;
    }
    //3、拆解长链表，返回复制链表的头指针。
    cur = head;
    Node* copyHead = head->next;
    while(cur){
        Node* copy = cur->next;
        Node* next = copy->next;
        if(next){
           cur->next = next;
           copy->next = next->next;
        }
        else{
            cur->next = next;
            copy->next=NULL;
        }
        //迭代cur
        cur = next;
    }
    return copyHead;

}