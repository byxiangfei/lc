class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> cache;  // val is pair<val, iter>
    list<int> recent; 
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(cache.count(key)) {
            //recent.erase(cache[key].second);
            //recent.push_front(key);
            recent.splice(recent.begin(), recent, cache[key].second);
            return cache[key].first;
        }
        return -1;
    }
    void put(int key, int value) {
        if(get(key) == -1) {
            if(recent.size() == cap) {
                int b = recent.back();
                cache.erase(b);
                recent.pop_back();
            }
            recent.push_front(key);  //先put
            cache[key] = make_pair(value, recent.begin());
        } else {
            cache[key].first = value;
        }
    }
};

