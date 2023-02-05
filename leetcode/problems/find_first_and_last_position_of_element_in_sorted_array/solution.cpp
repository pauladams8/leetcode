class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return { findFirst(nums, target), findLast(nums, target) };
    }
    
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
            else if (left != right)
                right = mid;
            else return mid;
        }
        return -1;
    }
    
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right + 1) / 2;
            if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
            else if (left != right) left = mid;
            else return mid;
        }
        return -1;
    }
};