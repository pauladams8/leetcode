class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        return dfs(1, cost).second;
    }
private:
    pair<int, int> dfs(int i, vector<int>& cost) {
        if (i > cost.size())
            return { 0, 0 };
        auto [leftSum, leftDiff] = dfs(2 * i, cost);
        auto [rightSum, rightDiff] = dfs(2 * i + 1, cost);
        return { max(leftSum, rightSum) + cost[i - 1], leftDiff + rightDiff + abs(leftSum - rightSum) };
    }
};