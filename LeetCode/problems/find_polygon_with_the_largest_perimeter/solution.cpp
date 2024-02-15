class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0, ans = -1;
        for (int side : nums) {
            if (sum > side) {
                ans = max(ans, sum + side);
            }
            sum += side;
        }
        return ans;
    }
};