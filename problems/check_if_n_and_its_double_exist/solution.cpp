class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int n : arr) {
            if (s.find(n) != s.end())
                return true;
            s.insert(n * 2);
            if (n % 2 == 0)
                s.insert(n / 2);
        }
        return false;
    }
};