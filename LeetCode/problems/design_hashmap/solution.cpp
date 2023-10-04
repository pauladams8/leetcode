class MyHashMap {
    vector<vector<pair<int, int>>> arr;
public:
    MyHashMap() : arr(1000) {}
    
    void put(int key, int value) {
        int bucket = key % 1000;
        for (auto& [k, v] : arr[bucket]) {
            if (k == key) {
                v = value;
                return;
            }
        }
        arr[bucket].push_back({ key, value });
    }
    
    int get(int key) {
        int bucket = key % 1000;
        for (auto [k, v] : arr[bucket])
            if (k == key)
                return v;
        return -1;
    }
    
    void remove(int key) {
        int bucket = key % 1000;
        for (auto it = arr[bucket].begin(); it != arr[bucket].end(); it++) {
            auto [k, v] = *it;
            if (k == key) {
                arr[bucket].erase(it);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */