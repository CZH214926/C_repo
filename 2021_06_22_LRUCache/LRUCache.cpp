// 什么是LRU ？
// Cache的容量有限，因此当Cache的容量用完后，而又有新的内容需要添加进来时， 就需要挑选并舍弃原有
// 的部分内容，从而腾出空间来放新内容。LRU Cache 的替换原则就是将最近最少使用的内容替换掉。其实，
// LRU译成最久未使用会更形象， 因为该算法每次替换掉的就是一段时间内最久没有使用过的内容。

// 如何设计 ？
//list尾部的数据是不经常被使用的，
// 结构设计的关键：将unordered_map 的 value 设置为 list<pair<int,int>>::iterator，因为这样，当 get 一个已有值以后，就可以直接找到
// key 在 list 中对应的 iterator(迭代器)，然后将这个值移动到链表的头部，保持LRU。  

class LRUCache {
private:
    // 使用一个哈希表和双向链表来实现
    unordered_map<int,list<pair<int,int>>::iterator> _hashmap; // 使用unordered_map，使搜索效率达到O(1)
    list<pair<int,int>> _lrulist;                              // 将最近用过的数据往链表的头部移动
    int _capacity;                                             // 容量大小，超出容量大小就删除链表尾部数据 
public:
    LRUCache(int capacity)
        :_capacity(capacity)
     {}
    int get(int key) {
        // 如果key对应的值存在，则可以得到key在list中对应的迭代器，将其保存，删除，头插，实现O(1)的数据挪动
        auto ret = _hashmap.find(key);
        if (ret != _hashmap.end())
        {
            // 找到了，并不能单纯的返回，还要把访问到的数据提到链表的头部，保持LRUcache的特性，list的尾部，总是最少用的数据
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
        // 1 找到了，更新 ---> // 删除查到的结果，然后将结果头插，最后都要更新hashmap中的迭代器的指向， 
        // 2 没找到，插入--->
                           // 满了---->先尾删，再头插
                           // 没满 --->直接头插
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
            // 判断容量是否满了
            if (_hashmap.size() >= _capacity)
            {
                //删除链表的最后一个元素
                pair<int,int> back = _lrulist.back();
                _hashmap.erase(back.first);
                _lrulist.pop_back();
            }
            // 插入新的元素到头部,无论链表满与不满这个插入操作都会执行
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