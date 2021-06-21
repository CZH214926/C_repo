class UnionFindSet
{
private:
    vector<int> _ufs;
public:
    UnionFindSet(int n)
        :_ufs(n,-1)
    {}
    int FindRoot(int index)
    {
        while (_ufs[index] >= 0)
        {
            index = _ufs[index];
        }
        return index;
    }
    bool Union(int index1, int index2)
    {
        int root1 = FindRoot(index1);
        int root2 = FindRoot(index2);
        if (root1 == root2)
            return false;
        _ufs[root1] += _ufs[root2];
        _ufs[root2] = root1;
        return true;
    }
    int Count()
    {
        int count = 0;
        for (auto& e : _ufs)
        {
            if (e < 0)
            {
                count++;
            }
        }
        return count;
    }

};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFindSet ufs(26);
        for (const auto& str : equations)
        {
            if (str[1] == '=')
            {
                ufs.Union(str[0] - 'a',str[3] - 'a');
            }
        }
        for (const auto& str : equations)
        {
            if (str[1] == '!')
            {
                if (ufs.FindRoot(str[0] - 'a') == ufs.FindRoot(str[3] - 'a'))
                {

                    return false;
                }
            }
        }
        return true;
    }
};