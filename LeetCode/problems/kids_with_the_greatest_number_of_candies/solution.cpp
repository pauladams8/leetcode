class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> result(n);
        int msf = 0;
        for (int i = 0; i < n; i++)
            msf = max(msf, candies[i]);
        for (int i = 0; i < n; i++)
            result[i] = candies[i] + extraCandies >= msf;
        return result;
    }
};