class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<unordered_map<int, int>> cache(n, unordered_map<int, int>());
        unordered_map<int, int> hasStone;
        for (int i = 0; i < n; i++) {
            hasStone[stones[i]] = i;
        }
        return canCross(hasStone, 0, 0, cache) == 1;
    }
private:
    int canCross(unordered_map<int, int>& stones, int from, int prev, vector<unordered_map<int, int>>& cache) {
        if (stones[from] == stones.size() - 1) {
            return true;
        }
        auto& ans = cache[stones[from]][prev];
        if (ans) {
            return ans;
        }
        for (int jump = prev + 1; jump > max(prev - 2, 0); jump--) {
            int next = from + jump;
            if (stones.find(next) != stones.end() && canCross(stones, next, jump, cache) == 1) {
                return ans = 1;
            }
        }
        return ans = -1;
    }
};