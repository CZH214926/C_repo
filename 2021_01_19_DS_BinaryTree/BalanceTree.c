/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //�ж�һ�����Ƿ���ƽ�������
typedef struct TreeNode TreeNode;
//����һ���ȶ���һ��������ȵķ���TreeDepth
//�ݹ���ǰ���˼·ȥ�ж�ÿһ������
int TreeDepth(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);

    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
bool isBalanced(struct TreeNode* root){
   //��������Ϊ��ƽ�������
   if(root==NULL)
   {
       return true;
   }
   //�������ĸ߶ȼ�ȥ�������ĸ߶ȴ���1�Ͳ���ƽ�������
   int gap = abs(TreeDepth(root->left) - TreeDepth(root->right));
   if(gap>1)
   {
       return false;
   }
   return isBalanced(root->left) && isBalanced(root->right);
}


//���������Ż�--------------�����ķ�����̫���ظ��ļ��㣬�Ǵ������¼���ģ���̫�����߶ȵ��������
//���Բ���Ҷ�ӽ�����ϱ��������õݹ���������˼·����ȥ������ĸ߶ȼ���
//��������Ż������в��漰����TreeDepth,���õݹ�ķ�ʽȥ�ۼӵĸ߶�
//�ú��������˼������Ż�
_isBalanced(struct TreeNode* root,int* depth)
{
    if(root == NULL)
        return true;
    else
    {
        //������
        int leftDepth = 0;
        if(_isBalanced(root->left,&leftDepth)==false)
        {
            return false;
        }
        int rightDepth = 0;
        if(_isBalanced(root->right,&rightDepth)==false)
        {
            return false;
        }
        if(abs(leftDepth - rightDepth) > 1)
        {
            return false;
        }

        *depth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
        return true;
    }
}

bool isBalanced(struct TreeNode* root){
    //����Ͳ�����
    int depth = 0;
    return _isBalanced(root,&depth);
}