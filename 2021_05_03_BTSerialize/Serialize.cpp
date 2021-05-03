//���ݶ����������ʣ�ͨ����ǰ��/����/���� + ��������ܹ�Ψһȷ��һ�ö�������
//��ʵ����һ�ַ�ʽ�������սڵ�ģ�ǰ��/����/���򣩱���Ҳ��Ψһȷ��һ�ö�������
class Codec {
public:
    string res;
    string serialize(TreeNode* root) {          //���л��׶�
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root)                    //��ǰ������ķ�ʽ���л�������
    {
        if (!root) res += "NULL,";              //�սڵ����NULL�ַ���
        else
        {
            res += to_string(root->val) + ',';  //�ǿսڵ�����ַ�����ֵ
            dfs(root->left);                    //����Ҳ��������������
            dfs(root->right);                   //ֻҪ��֤�����л�ʱҲ��ͬ���ķ�ʽ����
        }
    }

    queue<string> q;
    TreeNode* deserialize(string data) {        //�����л��׶�
        int i = 0, j = 0;                       //��˫ָ�밴�ն������ָ��ַ���
        while (i < data.size())                 //�Զ��ŷָ��ַ������������q��
        {
            while (i < data.size() && data[i] != ',') i ++ ;
            string tmp = data.substr(j, i - j);
            q.push(tmp);
            i ++ ;
            j = i;
        }

        return de_dfs();                        //�ݹ齨��
    }

    TreeNode* de_dfs()
    {
        auto t = q.front();
        q.pop();

        if (t == "NULL") return NULL;

        TreeNode* root = new TreeNode(stoi(t)); //��Ȼ��ǰ������ķ�ʽ����������
        root->left = de_dfs();
        root->right = de_dfs();

        return root;
    }
};
