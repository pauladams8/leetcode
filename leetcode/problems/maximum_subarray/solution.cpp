class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        for (int end = 0; end < nums.size(); end++)
            sum = max(sum + nums[end], nums[end]), ans = max(ans, sum);
        return ans;
    }
};