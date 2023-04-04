typedef long long ll;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, ll success) {
        sort(potions.begin(), potions.end());
        vector<int> pairs(spells.size());
        for (int i = 0; i < spells.size(); i++) {
            int left = 0, right = potions.size() - 1;
            while (left < right) {
                ll mid = (left + right) / 2, product = (ll) spells[i] * (ll) potions[mid];
                if (product >= success)
                    right = mid;
                else left = mid + 1;
            }
            if (left == right && (ll) spells[i] * (ll) potions[left] >= success)
                pairs[i] = potions.size() - left;
        }
        return pairs;
    }
};