class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        vector<int> prefix(n), suffix(n), diff(n);
        vector<bool> seen(51);
        for (int i = 0; i < n; i++) {
            if (!seen[nums[i]]) {
                cnt++;
                seen[nums[i]] = true;
            }
            prefix[i] = cnt;
        }
        cnt = 0;
        fill(seen.begin(), seen.end(), false);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = cnt;
            if (!seen[nums[i]]) {
                cnt++;
                seen[nums[i]] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            diff[i] = prefix[i] -suffix[i];
        }
        return diff;
    }
};