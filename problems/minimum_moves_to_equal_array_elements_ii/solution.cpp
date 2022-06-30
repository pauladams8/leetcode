class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median;
        if (nums.size() % 2)
            median = nums[nums.size() / 2];
        else
            median = (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;
        int moves = 0;
        for (int n : nums)
            moves += n < median ? median - n : n - median;
        return moves;
    }
};