class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 1;
        for (int i = 0; i < furthest && furthest < nums.size(); i++)
            furthest = max(furthest, i + nums[i] + 1);
        return furthest >= nums.size();
    }
};