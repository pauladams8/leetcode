typedef long long ll;

class Solution {
public:
    ll countBadPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        ll good = 0;
        for (int i = 0; i < nums.size(); i++)
            good += freq[i - nums[i]], freq[i - nums[i]]++;
        return nums.size() * (nums.size() - 1) / 2 - good;
    }
};