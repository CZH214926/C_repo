/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
// ���Ҷ�������·�����ֵ֮��Ϊĳһֵ��ȫ��·��������
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void traversal(TreeNode* cur, int count) {
        // 1���ݹ麯���Ĳ����ͷ���ֵ����Ҫ��������������������Ҫ����ֵ��������Ҫ����
        // 2���ݹ���ֹ����
        // 3������ݹ��߼�
        
        // 2����Ҷ�ӽڵ���� count ����Ϊ0����������Ҫ���·��
        if (cur->left == nullptr && cur->right == nullptr && count == 0) {
            result.push_back(path);
            return;
        }
        if (cur->left == nullptr && cur->right == nullptr) {
            return;
        }
        
        //3������ݹ��߼�
        if (cur->left) {
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);
            //����
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