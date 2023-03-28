class Solution {
    vector<int> passes = { 1, 7, 30 };
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> cache(days.size(), INT_MAX);
        return mincostTickets(days, costs, cache, 0);
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs, vector<int>& cache, int start) {
        if (start >= days.size())
            return 0;
        if (cache[start] != INT_MAX)
            return cache[start];
        int end = start;
        for (int i = 0; i < 3; i++) {
            while (end < days.size() && days[end] < days[start] + passes[i])
                end++;
            cache[start] = min(cache[start], costs[i] + mincostTickets(days, costs, cache, end));
        }
        return cache[start];
    }
};