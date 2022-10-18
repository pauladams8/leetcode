class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int best = 0, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right], newDiff = abs(target - sum);
                if (newDiff < diff) {
                    best = sum;
                    diff = newDiff;
                }
                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else return target;
            }
        }
        return best;
    }
};