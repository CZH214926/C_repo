/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
 //��Ŀ������
 //���ƴ����ָ������
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
    if(head==NULL){
        return NULL;
    }
	//1������ÿ���ڵ�Ȼ�����ӵ�ԭ���ڵ�ĺ��棬�õ��µ�����
    Node* cur = head;
    while(cur){
        //���ƽڵ�
        Node* copy = (Node*)malloc(sizeof(Node));
        copy->next = NULL;
        copy->random=NULL;
        copy->val = cur->val;
        //����
        Node* next = cur->next;
        cur->next = copy;
        copy->next=next;
        //����cur
        cur = next;
    }
    //2������ÿ�������ڵ��random
    cur = head;
    while(cur){
        Node* copy = cur->next;
        if(cur->random)
        copy->random = cur->random->next;
        else
        copy->random = NULL;
        //����cur
        cur = copy->next;
    }
    //3����ⳤ�������ظ��������ͷָ�롣
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
        //����cur
        cur = next;
    }
    return copyHead;

}