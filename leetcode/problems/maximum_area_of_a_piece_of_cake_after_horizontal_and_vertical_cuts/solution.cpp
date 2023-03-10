typedef long long ll;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int maxHeight = horizontalCuts.size() ? horizontalCuts[0] : 0, maxWidth = verticalCuts.size() ? verticalCuts[0] : 0;
        const int mod = 1000000007;
        for (int i = 1; i < horizontalCuts.size(); i++)
            maxHeight = max(maxHeight, horizontalCuts[i] - horizontalCuts[i - 1]);
        for (int i = 1; i < verticalCuts.size(); i++)
            maxWidth = max(maxWidth, verticalCuts[i] - verticalCuts[i - 1]);
        return ((ll) maxWidth % mod * (ll) maxHeight % mod) % mod;
    }
};