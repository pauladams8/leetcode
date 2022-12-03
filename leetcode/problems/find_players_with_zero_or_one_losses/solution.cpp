class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        for (vector<int> match : matches)
            losses[match[0]] = losses[match[0]], losses[match[1]]++;
        vector<int> none, one;
        for (auto [player, count] : losses)
            if (count == 0)
                none.push_back(player);
            else if (count == 1)
                one.push_back(player);
        sort(none.begin(), none.end());
        sort(one.begin(), one.end());
        return { none, one };
    }
};