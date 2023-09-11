class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), dupes = 0;
        for (int i = 0; i < n; i++) {
            if (i >= dupes + 2 && nums[i] == nums[i - dupes - 2])
                dupes++;
            else nums[i - dupes] = nums[i];
        }
        return n - dupes;
    }
};