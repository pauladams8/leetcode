class FrequencyTracker {
    unordered_map<int, int> freq, withFreq;
public:
    FrequencyTracker() {}
    
    void add(int number) {
        withFreq[freq[number]]--;
        freq[number]++;
        withFreq[freq[number]]++;
    }
    
    void deleteOne(int number) {
        if (!freq[number]) return;
        withFreq[freq[number]]--;
        freq[number]--;
        withFreq[freq[number]]++;
    }
    
    bool hasFrequency(int frequency) {
        return withFreq[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */