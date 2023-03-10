typedef long long ll;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                ll left = j + 1, right = nums.size() - 1, newTarget = (ll) target - nums[i] - nums[j];
                while (left < right) {
                    ll sum = nums[left] + nums[right];
                    if (sum < newTarget)
                        left++;
                    else if (sum > newTarget)
                        right--;
                    else
                        res.push_back({ nums[i], nums[j], nums[left], nums[right] }), left++, right--;
                    while (sum <= newTarget && left < right && nums[left] == nums[left - 1])
                        left++;
                    while (sum >= newTarget && left < right && nums[right] == nums[right + 1])
                        right--;
                }
                while (j + 1 < nums.size() && nums[j + 1] == nums[j])
                    j++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return res;
    }
};