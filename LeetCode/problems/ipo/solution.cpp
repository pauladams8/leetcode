class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> all;
        priority_queue<int> available;
        for (int i = 0; i < profits.size(); i++)
            all.push({ capital[i], profits[i] });
        for (int i = 0; i < k; i++) {
            while (!all.empty() && all.top().first <= w) {
                available.push(all.top().second);
                all.pop();
            }
            if (available.empty())
                break;
            w += available.top();
            available.pop();
        }
        return w;
    }
};