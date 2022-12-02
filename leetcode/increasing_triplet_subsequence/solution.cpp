class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int a = INT_MAX, b = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > b)
                return true;
            else if (nums[i] > a)
                b = nums[i];
            else
                a = nums[i];
        }
        return false;
    }
};