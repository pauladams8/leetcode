class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> sum(cardPoints.size() + 1);
        for (int i = 0; i < cardPoints.size(); i++)
            sum[i + 1] = sum[i] + cardPoints[i];
        int left = 0, right = cardPoints.size() - k, ans = 0;
        while (left <= right && right <= cardPoints.size()) {
            ans = max(ans, sum[left] + sum[cardPoints.size()] - sum[right]);
            left++;
            right++;
        }
        return ans;
    }
};