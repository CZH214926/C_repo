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
// ����һ����������������Ƿ��Ǿ���ԳƵ�
class Solution {
public:
    //����1 ���ݹ�
    bool compare(TreeNode* left, TreeNode* right) {
        //1�����ҽ�㶼Ϊ��            true
        if (left == nullptr && right == nullptr) return true;
        //2����Ϊ�գ���Ϊ�ǿ�          false
        if (left == nullptr && right != nullptr) return false;
        //3����Ϊ�ǿգ���Ϊ��          false
        if (left != nullptr && right == nullptr) return false;
        //4�����Ҷ�Ϊ�ǿյ��ǽڵ�ֵ���� false
        if (left->val != right->val) return false;
        // ʣ�µ�������ǵݹ���߼�
        bool outside = compare(left->left,right->right);
        bool inside = compare(left->right,right->left);
        bool isSame = outside && inside;
        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
      // �����������������Ǿ���ԳƵģ�����������Ǿ���ԳƵġ�
      if (root == nullptr) return true;
      return compare(root->left, root->right);
    }

    // ����2 ������
    // ע������͵ݹ�� return true��д��������
    // ʹ�ö��е��� ����ʹ��ջ���������ǿ��Եģ��������붼��һ���� �ս����Ҫ��������
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
                //     //2����Ϊ�գ���Ϊ�ǿ�          false
                // if (leftNode == nullptr && rightNode != nullptr) return false;
                //     //3����Ϊ�ǿգ���Ϊ��          false
                // if (leftNode != nullptr && rightNode == nullptr) return false;
                //     //4�����Ҷ�Ϊ�ǿյ��ǽڵ�ֵ���� false
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
            // ֻҪ��֤���Ž�ջ������ʵ������
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
                    //3����Ϊ�ǿգ���Ϊ��          false
                if (leftNode != nullptr && rightNode == nullptr) return false;
                    //4�����Ҷ�Ϊ�ǿյ��ǽڵ�ֵ���� false
                if (leftNode->val != rightNode->val) return false;
                st.push(leftNode->left);
                st.push(rightNode->right);
                st.push(leftNode->right);
                st.push(rightNode->left);
            }
            return true;
        }
};