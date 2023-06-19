class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0, ans = 0;
        for (int n : gain)
            altitude += n, ans = max(ans, altitude);
        return ans;
    }
};