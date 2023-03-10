typedef long long ll;

const int MOD = 1000000007;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, ll> map;
        for (int n : arr)
            map[n] = -1;
        ll count = 0;
        for (int n : arr)
            count += numFactoredBinaryTrees(arr, map, n);
        return count % MOD;
    }
private:
    ll numFactoredBinaryTrees(vector<int>& arr, unordered_map<int, ll>& map, int n) {
        if (map[n] != -1)
            return map[n] % MOD;
        map[n] = 1;
        for (int factor : arr)
            if (n % factor == 0 && map.find(n / factor) != map.end())
                map[n] += (numFactoredBinaryTrees(arr, map, factor) % MOD * numFactoredBinaryTrees(arr, map, n / factor) % MOD) % MOD;
        return map[n] % MOD;
    }
};