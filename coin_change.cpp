#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> map;
        return coinChange(coins, map, amount);
    }
private:
    int coinChange(vector<int>& coins, unordered_map<int, int>& map, int amount) {
        if (amount == 0)
            return 0;
        if (map.find(amount) != map.end())
            return map[amount];
        map[amount] = -1;
        for (int coin : coins) {
            if (coin > amount)
                continue;
            int n = coinChange(coins, map, amount - coin);
            if (n == -1)
                continue;
            if (map[amount] == -1)
                map[amount] = n + 1;
            else
                map[amount] = min(map[amount], n + 1);
        }
        return map[amount];
    }
};
