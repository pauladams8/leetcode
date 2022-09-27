class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                break;
            if (i && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] < -nums[i])
                    left++;
                else if (nums[left] + nums[right] > -nums[i])
                    right--;
                else {
                    triplets.push_back({ nums[i], nums[left], nums[right] });
                    while (left < right && nums[left + 1] == nums[left])
                        left++;
                    while (left < right && nums[right - 1] == nums[right])
                        right--;
                    left++;
                    right--;
                }
            }
        }
        return triplets;
    }
};