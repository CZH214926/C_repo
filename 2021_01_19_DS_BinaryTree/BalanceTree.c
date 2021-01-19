/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //判断一棵树是否是平衡二叉树
typedef struct TreeNode TreeNode;
//方法一、先定义一个求树深度的方法TreeDepth
//递归用前序的思路去判断每一颗子树
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
   //空树被认为是平衡二叉树
   if(root==NULL)
   {
       return true;
   }
   //左子树的高度减去右子树的高度大于1就不是平衡二叉树
   int gap = abs(TreeDepth(root->left) - TreeDepth(root->right));
   if(gap>1)
   {
       return false;
   }
   return isBalanced(root->left) && isBalanced(root->right);
}


//方法二、优化--------------上述的方法有太多重复的计算，是从上向下计算的，有太多计算高度的冗余计算
//所以采用叶子结点向上遍历，采用递归后序遍历的思路可以去除冗余的高度计算
//在下面的优化方法中不涉及方法TreeDepth,是用递归的方式去累加的高度
//用后序遍历的思想进行优化
_isBalanced(struct TreeNode* root,int* depth)
{
    if(root == NULL)
        return true;
    else
    {
        //左子树
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
    //输出型参数，
    int depth = 0;
    return _isBalanced(root,&depth);
}