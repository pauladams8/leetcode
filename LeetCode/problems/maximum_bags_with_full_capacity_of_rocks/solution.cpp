class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> bags(rocks.size());
        for (int i = 0; i < bags.size(); i++)
            bags[i] = capacity[i] - rocks[i];
        sort(bags.begin(), bags.end());
        int ans = 0;
        while (ans < bags.size() && additionalRocks >= bags[ans])
            additionalRocks -= bags[ans++];
        return ans;
    }
};