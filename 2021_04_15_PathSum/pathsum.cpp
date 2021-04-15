/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
// 查找二叉树中路径结点值之和为某一值的全部路径并返回
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void traversal(TreeNode* cur, int count) {
        // 1、递归函数的参数和返回值：需要遍历整个二叉树，不需要返回值，参数需要两个
        // 2、递归终止条件
        // 3、单层递归逻辑
        
        // 2、到叶子节点除且 count 被减为0，就是满足要求的路径
        if (cur->left == nullptr && cur->right == nullptr && count == 0) {
            result.push_back(path);
            return;
        }
        if (cur->left == nullptr && cur->right == nullptr) {
            return;
        }
        
        //3、单层递归逻辑
        if (cur->left) {
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);
            //回溯
            count += cur->left->val;
            path.pop_back();
        }
        if (cur->right) {
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);
            count += cur->right->val;
            path.pop_back();
        }  
        return;
    }
 public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == nullptr) return result;
        path.push_back(root->val);
        traversal(root, expectNumber - root->val);
        return result;
    }
};