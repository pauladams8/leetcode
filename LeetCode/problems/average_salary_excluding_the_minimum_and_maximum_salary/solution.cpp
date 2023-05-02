class Solution {
public:
    double average(vector<int>& salary) {
        double mn = DBL_MAX, mx = 0, sum = 0, cnt = 0;
        for (double s : salary)
            mn = min(mn, s), mx = max(mx, s);
        for (double s : salary)
            if (s != mn && s != mx)
                sum += s, cnt++;
        return sum / cnt;
    }
};