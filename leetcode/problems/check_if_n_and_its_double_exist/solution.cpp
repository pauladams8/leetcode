class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int n : arr) {
            if (s.find(n * 2) != s.end())
                return true;
            if (n % 2 == 0 && s.find(n / 2) != s.end())
                return true;
            s.insert(n);
        }
        return false;
    }
};