/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//  // 先定义一个子函数：用于查找结点p在root的左树，还是在root的右树
//     bool findNode(TreeNode* root, TreeNode* x)
//     {
//         if (root == nullptr)
//             return false;
        
//         if (root == x)
//             return true;
        
//         return findNode(root->left,x) || findNode(root->right,x);
//     }
//     // 方法1 ： 时间复杂度是 O(N^2),优化到 O(N)===>用空间来换时间===> 请看方法2,
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // 空树返回空，可能是root为空就直接返回空，也可能是直到找到空树也没有找到要找的结点返回空
//         if (root == nullptr)
//             return nullptr;
//         // p 和 q 有一个是根节点则问题就可以直接得出答案===> root 就是最近的公共祖先
//         if (p == root || q == root)
//         {
//             return root;
//         }
//         // 定义4个bool变量分别是，p在root的左树，q在root的左树，则p在root右树，q在root的右树，直接对其取反即可，因为一个节点不可能既在
//         // root的左树，又在root的右树
//         bool qInLeft,qInRight,pInLeft,pInRight;
//         pInLeft = findNode(root->left,p);
//         pInRight = !pInLeft;
//         qInLeft = findNode(root->left,q);
//         qInRight = !qInLeft;

//         // 当一个在左，一个在右的时候，root就是最近公共祖先
//         if ((pInLeft && qInRight) || (qInLeft && pInRight))
//             return root;
//         // 两个都在root的左的时候，则最近公共祖先在root的左子树里
//         else if (pInLeft && qInLeft)
//             return lowestCommonAncestor(root->left,p,q);
//         // 两个都在root的右的时候，则最近公共祖先在root的右子树里
//         else
//             return lowestCommonAncestor(root->right,p,q);
//     }
        bool findPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
        {
            if (root == nullptr)
                return false;
            // 不管3721将root push进path
            path.push(root);
            if (root == x)
                return true;
            // root不返回 true，则root也可能是路径上的一个节点
            // 继续递归想左子树寻找，找到空树，则返回fasle，然后递归向右寻找，找到空树则返回false,root的左树和右树都没有则将root
            // 弹出，并给root的上一层返回false
            if (findPath(root->left,x,path))
                return true;
            if (findPath(root->right,x,path))
                return true;
            
            path.pop();
            return false;
        } 
       TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
       {
           // 方法2 将方法1的时间复杂度优化到O(N)
           // 定义一个子函数，查找结点路径，将结点路径记录在栈里
           // 最后两个栈存储就是两个结点的路径，栈顶就是p或者q，栈底就是root则问题就转化成======> 求链表相交问题了
           stack<TreeNode*> pPath;
           stack<TreeNode*> qPath;

           findPath(root,p,pPath);
           findPath(root,q,qPath);

           // 把较大栈中的元素弹出，直到两个栈大小相等
           while (pPath.size() > qPath.size())
           {
               pPath.pop();
           }
           while (qPath.size() > pPath.size())
           {
               qPath.pop();
           }
           // 此时两个栈中的元素至相同
           while (pPath.top() != qPath.top())
           {
               pPath.pop();
               qPath.pop();
           }
           return pPath.top();
       }
};