class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);
        for (int i = 0; i < n; i++)
            time[i] = (double) dist[i] / speed[i];
        sort(time.begin(), time.end());
        int ans = 0;
        while (ans < n && ans < time[ans])
            ans++;
        return ans;
    }
};