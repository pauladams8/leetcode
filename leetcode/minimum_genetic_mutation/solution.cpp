class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> set;
        for (string& s : bank)
            set.insert(s);
        vector<char> chars = { 'A', 'C', 'G', 'T' };
        queue<string> q;
        q.push(start);
        int steps = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string s = q.front();
                q.pop();
                if (s == end)
                    return steps;
                for (char& c : s) {
                    char original = c;
                    for (char re : chars) {
                        if (re == c)
                            continue;
                        c = re;
                        if (set.find(s) == set.end())
                            continue;
                        set.erase(s);
                        q.push(s);
                    }
                    c = original;
                }
            }
            steps++;
        }
        return -1;
    }
};