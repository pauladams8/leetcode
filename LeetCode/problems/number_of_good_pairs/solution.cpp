class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq;
        for (int n : nums) {
            ans += freq[n]++;
        }
        return ans;
    }
};