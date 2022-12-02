class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>> freq(img1.size() * 2, vector<int>(img1.size() * 2));
        vector<pair<int, int>> ones;
        for (int i = 0; i < img2.size(); i++)
            for (int j = 0; j < img2[i].size(); j++)
                if (img2[i][j])
                    ones.push_back({ i, j });
        for (int i = 0; i < img1.size(); i++)
            for (int j = 0; j < img1[i].size(); j++)
                if (img1[i][j])
                    for (auto [ii, jj] : ones)
                        freq[ii - i + img1.size()][jj - j + img1.size()]++;
        int ans = 0;
        for (int i = 0; i < freq.size(); i++)
            for (int j = 0; j < freq[i].size(); j++)
                ans = max(ans, freq[i][j]);
        return ans;
    }
};