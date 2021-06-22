// ʲô��LRU ��
// Cache���������ޣ���˵�Cache����������󣬶������µ�������Ҫ��ӽ���ʱ�� ����Ҫ��ѡ������ԭ��
// �Ĳ������ݣ��Ӷ��ڳ��ռ����������ݡ�LRU Cache ���滻ԭ����ǽ��������ʹ�õ������滻������ʵ��
// LRU������δʹ�û������ ��Ϊ���㷨ÿ���滻���ľ���һ��ʱ�������û��ʹ�ù������ݡ�

// ������ ��
//listβ���������ǲ�������ʹ�õģ�
// �ṹ��ƵĹؼ�����unordered_map �� value ����Ϊ list<pair<int,int>>::iterator����Ϊ�������� get һ������ֵ�Ժ󣬾Ϳ���ֱ���ҵ�
// key �� list �ж�Ӧ�� iterator(������)��Ȼ�����ֵ�ƶ��������ͷ��������LRU��  

class LRUCache {
private:
    // ʹ��һ����ϣ���˫��������ʵ��
    unordered_map<int,list<pair<int,int>>::iterator> _hashmap; // ʹ��unordered_map��ʹ����Ч�ʴﵽO(1)
    list<pair<int,int>> _lrulist;                              // ������ù��������������ͷ���ƶ�
    int _capacity;                                             // ������С������������С��ɾ������β������ 
public:
    LRUCache(int capacity)
        :_capacity(capacity)
     {}
    int get(int key) {
        // ���key��Ӧ��ֵ���ڣ�����Եõ�key��list�ж�Ӧ�ĵ����������䱣�棬ɾ����ͷ�壬ʵ��O(1)������Ų��
        auto ret = _hashmap.find(key);
        if (ret != _hashmap.end())
        {
            // �ҵ��ˣ������ܵ����ķ��أ���Ҫ�ѷ��ʵ��������ᵽ�����ͷ��������LRUcache�����ԣ�list��β�������������õ�����
            auto pos = ret->second;
            pair<int,int> kv = *pos;
            _lrulist.erase(pos);
            _lrulist.push_front(kv);
            //_hashmap[key] = _lrulist.begin();
            ret->second = _lrulist.begin();
            return kv.second;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // 1 �ҵ��ˣ����� ---> // ɾ���鵽�Ľ����Ȼ�󽫽��ͷ�壬���Ҫ����hashmap�еĵ�������ָ�� 
        // 2 û�ҵ�������--->
                           // ����---->��βɾ����ͷ��
                           // û�� --->ֱ��ͷ��
        auto ret = _hashmap.find(key);
        if (ret != _hashmap.end())
        {
            auto pos = ret->second;
            _lrulist.erase(pos);
            _lrulist.push_front(make_pair(key,value));
            //_hashmap.insert(make_pair(key,_lrulist.begin()));
            ret->second = _lrulist.begin();
        }
        else
        {
            // �ж������Ƿ�����
            if (_hashmap.size() >= _capacity)
            {
                //ɾ����������һ��Ԫ��
                pair<int,int> back = _lrulist.back();
                _hashmap.erase(back.first);
                _lrulist.pop_back();
            }
            // �����µ�Ԫ�ص�ͷ��,�����������벻����������������ִ��
            _lrulist.push_front(make_pair(key,value));
            _hashmap.insert(make_pair(key,_lrulist.begin()));
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */