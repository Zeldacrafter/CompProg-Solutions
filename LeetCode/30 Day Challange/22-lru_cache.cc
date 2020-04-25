class LRUCache {
    int cap;
    list<pair<int,int>> lru;
    unordered_map<int, list<pair<int,int>>::iterator> m;

    void moveToFront(int k, int v) {
        lru.erase(m[k]);
        lru.push_front(make_pair(k, v));
        m[k] = lru.begin();
    }
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if(!m.count(key))
            return -1;
        int v = (*m[key]).second;
        moveToFront(key, v);
        return (*m[key]).second;
    }
    
    void put( int key, int value ) {
        if(m.count(key)) {
            moveToFront(key, value);
            return;
        }

        lru.push_front(make_pair(key, value));
        m[key] = lru.begin();
        if(m.size() > cap) {
            m.erase(lru.back().first);
            lru.pop_back();
        }
    }
};
