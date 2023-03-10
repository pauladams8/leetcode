class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        vector<int> freq(k + 1);
        freq[0] = 1;
        for (int n : nums)
            sum += n, ans += freq[(sum % k + k) % k]++;
        return ans;
    }
};