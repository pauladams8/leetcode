typedef long long ll;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll leftSum = 0, rightSum = 0, minDiff = INT_MAX, ans = -1;
        for (int i = 0; i < nums.size(); i++)
            rightSum += nums[i];
        for (int i = 0; i < nums.size(); i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            int leftAvg = leftSum / (i + 1), rightAvg = (nums.size() - i - 1 == 0) ? 0 : rightSum / (nums.size() - i - 1), diff = abs(rightAvg - leftAvg);
            if (diff < minDiff) {
                ans = i;
                minDiff = diff;
            }
        }
        return ans;
    }
};