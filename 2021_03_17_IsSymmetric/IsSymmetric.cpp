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
// 给定一个二叉树，检查它是否是镜像对称的
class Solution {
public:
    //方法1 ：递归
    bool compare(TreeNode* left, TreeNode* right) {
        //1、左右结点都为空            true
        if (left == nullptr && right == nullptr) return true;
        //2、左为空，右为非空          false
        if (left == nullptr && right != nullptr) return false;
        //3、左为非空，右为空          false
        if (left != nullptr && right == nullptr) return false;
        //4、左右都为非空但是节点值不等 false
        if (left->val != right->val) return false;
        // 剩下的情况就是递归的逻辑
        bool outside = compare(left->left,right->right);
        bool inside = compare(left->right,right->left);
        bool isSame = outside && inside;
        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
      // 左子树和右子树都是镜像对称的，则二叉树就是镜像对称的。
      if (root == nullptr) return true;
      return compare(root->left, root->right);
    }

    // 方法2 ：迭代
    // 注意迭代和递归的 return true的写法的区别，
    // 使用队列迭代 或者使用栈来迭代都是可以的，甚至代码都是一样的 空结点是要入容器的
   bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
            queue<TreeNode*> que;
            que.push(root->left);
            que.push(root->right);
            while (!que.empty()) {
                TreeNode* leftNode = que.front(); 
                que.pop();
                TreeNode* rightNode = que.front();
                que.pop();
                if (leftNode == nullptr && rightNode == nullptr) continue;
                //     //2、左为空，右为非空          false
                // if (leftNode == nullptr && rightNode != nullptr) return false;
                //     //3、左为非空，右为空          false
                // if (leftNode != nullptr && rightNode == nullptr) return false;
                //     //4、左右都为非空但是节点值不等 false
                // if (leftNode->val != rightNode->val) return false;
                if (
                    (leftNode == nullptr && rightNode != nullptr) 
                    || 
                    (leftNode != nullptr && rightNode == nullptr)
                    || 
                     (leftNode->val != rightNode->val)
                ) return false;
                que.push(leftNode->left);
                que.push(rightNode->right);
                que.push(leftNode->right);
                que.push(rightNode->left);
            } 

            return true;
        }

        bool isSymmetric(TreeNode* root) {
            // 只要保证挨着进栈左右其实都可以
            if (root == nullptr) return true;
            stack<TreeNode*> st;
            st.push(root->right);
            st.push(root->left);
            while (!st.empty()) {
                TreeNode* leftNode = st.top();
                st.pop();
                TreeNode* rightNode = st.top();
                st.pop();
                if (rightNode == nullptr && leftNode == nullptr) continue;

                if (leftNode == nullptr && rightNode != nullptr) return false;
                    //3、左为非空，右为空          false
                if (leftNode != nullptr && rightNode == nullptr) return false;
                    //4、左右都为非空但是节点值不等 false
                if (leftNode->val != rightNode->val) return false;
                st.push(leftNode->left);
                st.push(rightNode->right);
                st.push(leftNode->right);
                st.push(rightNode->left);
            }
            return true;
        }
};