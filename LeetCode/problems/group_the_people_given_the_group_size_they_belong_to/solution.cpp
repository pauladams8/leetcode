class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> people(n + 1), groups;
        for (int i = 0; i < n; i++) {
            int size = groupSizes[i];
            people[size].push_back(i);
            if (people[size].size() == size)
                groups.push_back(move(people[size]));
        }
        return groups;
    }
};