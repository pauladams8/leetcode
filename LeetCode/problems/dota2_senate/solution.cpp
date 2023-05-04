class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;
        for (int i = 0; i < n; i++)
            if (senate[i] == 'R')
                r.push(i);
            else d.push(i);
        while (!r.empty() && !d.empty()) {
            int i = r.front(), j = d.front();
            r.pop(), d.pop();
            if (i < j)
                r.push(i + n);
            else d.push(j + n);
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};