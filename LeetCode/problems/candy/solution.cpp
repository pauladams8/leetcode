class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n);
        for (int i = 0; i < n; i++)
            candies[i] = max(candies[i], (i > 0 && ratings[i] > ratings[i - 1]) ? candies[i - 1] + 1 : 1);
        for (int i = n - 1; i >= 0; i--)
            candies[i] = max(candies[i], (i + 1 < n && ratings[i] > ratings[i + 1]) ? candies[i + 1] + 1 : 1);
        return accumulate(candies.begin(), candies.end(), 0);
    }
};