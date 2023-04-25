class SmallestInfiniteSet {
    int smallest = 1;
    unordered_set<int> removed;
public:
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        int ans = smallest;
        removed.insert(smallest++);
        while (removed.find(smallest) != removed.end())
            smallest++;
        return ans;
    }
    
    void addBack(int num) {
        smallest = min(smallest, num);
        removed.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */