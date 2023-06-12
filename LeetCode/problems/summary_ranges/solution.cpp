class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        int runLength = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 == n || nums[i] + 1 != nums[i + 1]) {
                if (runLength) {
                    ans.push_back(to_string(nums[i] - runLength) + "->" + to_string(nums[i]));
                } else {
                    ans.push_back(to_string(nums[i]));
                }
                runLength = 0;
            } else {
                runLength++;
            }
        }
        return ans;
    }
};