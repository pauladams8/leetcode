class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        vector<vector<pair<int, int>>> adj(n);
        for (auto flight : flights)
            adj[flight[0]].push_back({ flight[1], flight[2] });
        queue<pair<int, int>> q;
        q.push({ src, 0 });
        int stops = 0;
        while (!q.empty() && stops <= k) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [city, price] = q.front();
                q.pop();
                cout << city << ' ' << prices[city] << '\n';
                for (auto [next, cost] : adj[city]) {
                    if (prices[next] <= price + cost)
                        continue;
                    prices[next] = price + cost;
                    q.push({ next, prices[next] });
                }
            }
            stops++;
        }
        return prices[dst] != INT_MAX ? prices[dst] : -1;
    }
};