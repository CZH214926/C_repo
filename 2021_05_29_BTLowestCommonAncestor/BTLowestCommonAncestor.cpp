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
//  // �ȶ���һ���Ӻ��������ڲ��ҽ��p��root��������������root������
//     bool findNode(TreeNode* root, TreeNode* x)
//     {
//         if (root == nullptr)
//             return false;
        
//         if (root == x)
//             return true;
        
//         return findNode(root->left,x) || findNode(root->right,x);
//     }
//     // ����1 �� ʱ�临�Ӷ��� O(N^2),�Ż��� O(N)===>�ÿռ�����ʱ��===> �뿴����2,
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // �������ؿգ�������rootΪ�վ�ֱ�ӷ��ؿգ�Ҳ������ֱ���ҵ�����Ҳû���ҵ�Ҫ�ҵĽ�㷵�ؿ�
//         if (root == nullptr)
//             return nullptr;
//         // p �� q ��һ���Ǹ��ڵ�������Ϳ���ֱ�ӵó���===> root ��������Ĺ�������
//         if (p == root || q == root)
//         {
//             return root;
//         }
//         // ����4��bool�����ֱ��ǣ�p��root��������q��root����������p��root������q��root��������ֱ�Ӷ���ȡ�����ɣ���Ϊһ���ڵ㲻���ܼ���
//         // root������������root������
//         bool qInLeft,qInRight,pInLeft,pInRight;
//         pInLeft = findNode(root->left,p);
//         pInRight = !pInLeft;
//         qInLeft = findNode(root->left,q);
//         qInRight = !qInLeft;

//         // ��һ������һ�����ҵ�ʱ��root���������������
//         if ((pInLeft && qInRight) || (qInLeft && pInRight))
//             return root;
//         // ��������root�����ʱ�����������������root����������
//         else if (pInLeft && qInLeft)
//             return lowestCommonAncestor(root->left,p,q);
//         // ��������root���ҵ�ʱ�����������������root����������
//         else
//             return lowestCommonAncestor(root->right,p,q);
//     }
        bool findPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
        {
            if (root == nullptr)
                return false;
            // ����3721��root push��path
            path.push(root);
            if (root == x)
                return true;
            // root������ true����rootҲ������·���ϵ�һ���ڵ�
            // �����ݹ���������Ѱ�ң��ҵ��������򷵻�fasle��Ȼ��ݹ�����Ѱ�ң��ҵ������򷵻�false,root��������������û����root
            // ����������root����һ�㷵��false
            if (findPath(root->left,x,path))
                return true;
            if (findPath(root->right,x,path))
                return true;
            
            path.pop();
            return false;
        } 
       TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
       {
           // ����2 ������1��ʱ�临�Ӷ��Ż���O(N)
           // ����һ���Ӻ��������ҽ��·���������·����¼��ջ��
           // �������ջ�洢������������·����ջ������p����q��ջ�׾���root�������ת����======> �������ཻ������
           stack<TreeNode*> pPath;
           stack<TreeNode*> qPath;

           findPath(root,p,pPath);
           findPath(root,q,qPath);

           // �ѽϴ�ջ�е�Ԫ�ص�����ֱ������ջ��С���
           while (pPath.size() > qPath.size())
           {
               pPath.pop();
           }
           while (qPath.size() > pPath.size())
           {
               qPath.pop();
           }
           // ��ʱ����ջ�е�Ԫ������ͬ
           while (pPath.top() != qPath.top())
           {
               pPath.pop();
               qPath.pop();
           }
           return pPath.top();
       }
};