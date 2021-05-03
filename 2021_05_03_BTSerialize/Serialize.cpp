//根据二叉树的性质，通过（前序/后序/层序） + 中序遍历能够唯一确定一棵二叉树。
//其实还有一种方式，即带空节点的（前序/中序/后序）遍历也能唯一确定一棵二叉树。
class Codec {
public:
    string res;
    string serialize(TreeNode* root) {          //序列化阶段
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root)                    //用前序遍历的方式序列化二叉树
    {
        if (!root) res += "NULL,";              //空节点存入NULL字符串
        else
        {
            res += to_string(root->val) + ',';  //非空节点存入字符串数值
            dfs(root->left);                    //这里也可以用中序或后序
            dfs(root->right);                   //只要保证反序列化时也用同样的方式即可
        }
    }

    queue<string> q;
    TreeNode* deserialize(string data) {        //反序列化阶段
        int i = 0, j = 0;                       //用双指针按照逗号来分割字符串
        while (i < data.size())                 //以逗号分割字符串，存入队列q中
        {
            while (i < data.size() && data[i] != ',') i ++ ;
            string tmp = data.substr(j, i - j);
            q.push(tmp);
            i ++ ;
            j = i;
        }

        return de_dfs();                        //递归建树
    }

    TreeNode* de_dfs()
    {
        auto t = q.front();
        q.pop();

        if (t == "NULL") return NULL;

        TreeNode* root = new TreeNode(stoi(t)); //仍然用前序遍历的方式构建二叉树
        root->left = de_dfs();
        root->right = de_dfs();

        return root;
    }
};
