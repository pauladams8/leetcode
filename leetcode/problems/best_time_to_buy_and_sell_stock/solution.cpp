class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, profit = 0;
        for (int price : prices)
            cost = min(cost, price), profit = max(profit, price - cost);
        return profit;
    }
};