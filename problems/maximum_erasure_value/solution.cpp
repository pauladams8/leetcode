class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> map(1e4 + 1, -1);
        vector<int> sum(nums.size() + 1);
        int max = 0;
        for (int start = 0, end = 0; end < nums.size(); end++) {
            sum[end + 1] = sum[end] + nums[end];
            if (map[nums[end]] != -1)
                start = std::max(start, map[nums[end]] + 1);
            map[nums[end]] = end;
            max = std::max(max, sum[end + 1] - sum[start]);
        }
        return max;
    }
};