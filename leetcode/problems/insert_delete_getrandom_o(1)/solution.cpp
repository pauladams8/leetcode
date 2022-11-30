class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> map;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (map.find(val) != map.end())
            return false;
        map[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end())
            return false;
        int idx = map[val];
        // full credit to @yubad2000, didn't think of this O(1) solution
        if (idx < nums.size() - 1) {
            nums[idx] = nums[nums.size() - 1];
            map[nums[idx]] = idx;
        }
        map.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */