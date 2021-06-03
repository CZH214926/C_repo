/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& previ, int inorderBegin, int inorderEnd)
    {
        if (previ >= preorder.size())
            return nullptr;
        if (inorderBegin > inorderEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[previ]);
        // 找到在中序数组中的切割点
        int rooti = inorderBegin;
        while (rooti != inorderEnd)
        {
            if (inorder[rooti] == preorder[previ])
            {
                break;
            }
            else
            {
                ++rooti;
            }
        }
        // 此时 rooti 已经被找到
        // [inoerderBegin, rooti - 1] rooti [rooti + 1, inorderEnd]
        ++previ;

        root->left = _buildTree(preorder, inorder, previ, inorderBegin, rooti - 1); 
        root->right = _buildTree(preorder, inorder, previ, rooti + 1, inorderEnd);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int previ = 0;
        return _buildTree(preorder, inorder, previ, 0, inorder.size() - 1);
    }
};