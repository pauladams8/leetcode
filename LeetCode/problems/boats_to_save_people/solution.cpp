class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1, ans = 0;
        while (i <= j) {
            while (i < j && people[i] + people[j] > limit)
                ans++, j--;
            ans++, i++, j--;
        }
        return ans;
    }
};