#include<stdio.h>
//给定一个先序遍历的字符串，然后前序递归构建二叉树
struct TreeNode{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* CreateTree(char* str,int* pi)
{
    if(str[*pi]=='#')
    {
        ++(*pi);
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = str[*pi];
    ++(*pi);
    root->left = CreateTree(str, pi);
    root->right = CreateTree(str, pi);
    return root;
}
void InOrderTraversal(struct TreeNode* root)
{
     if(root==NULL)
     {
       return;
     }
    InOrderTraversal(root->left);
    printf("%c ",root->val);
    InOrderTraversal(root->right);
}

int main()
{
    char str[100];
    scanf("%s",str);
    int i = 0;
    struct TreeNode* root = CreateTree(str,&i);
    InOrderTraversal(root);
    return 0;
}