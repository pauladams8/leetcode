class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sortArray(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void sortArray(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;
        int mid = (start + end) / 2;
        sortArray(nums, start, mid);
        sortArray(nums, mid + 1, end);
        vector<int> left(nums.begin() + start, nums.begin() + mid + 1), right(nums.begin() + mid + 1, nums.begin() + end + 1);
        int l = 0, r = 0, i = start;
        while (l < left.size() && r < right.size())
            if (left[l] < right[r])
                nums[i++] = left[l++];
            else nums[i++] = right[r++];
        while (l < left.size())
            nums[i++] = left[l++];
        while (r < right.size())
            nums[i++] = right[r++];
    }
};