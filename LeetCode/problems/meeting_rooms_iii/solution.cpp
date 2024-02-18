class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n);
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> free, busy;
        for (int i = 0; i < n; i++) {
            free.push({ i, 0 });
        }
        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            while (!busy.empty() && busy.top().first <= start) {
                auto [busy_until, room] = busy.top();
                busy.pop();
                free.push({ room, busy_until });
            }
            if (free.empty()) {
                auto [busy_until, room] = busy.top();
                busy.pop();
                busy_until += end - start;
                busy.push({ busy_until, room });
                cnt[room]++;
            } else {
                auto [room, busy_until] = free.top();
                free.pop();
                busy_until = end;
                busy.push({ busy_until, room });
                cnt[room]++;
            }
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};