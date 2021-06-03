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
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& posti, int inorderBegin, int inorderEnd)
    {
        if (posti < 0)
            return nullptr;
        if (inorderBegin > inorderEnd)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[posti]);

        int rooti = inorderBegin;
        while (inorderBegin <= inorderEnd)
        {
            if (postorder[posti] == inorder[rooti])
                break;
            else
                rooti++;
        }

        posti--;
        // [inorderBegin, rooti - 1] rooti [rooti + 1, inorderEnd]
        root->right = _buildTree(inorder, postorder, posti, rooti + 1, inorderEnd); 
        root->left =  _buildTree(inorder, postorder, posti, inorderBegin, rooti - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posti = postorder.size() - 1;
        return _buildTree(inorder, postorder, posti, 0, inorder.size() - 1);
    }
};