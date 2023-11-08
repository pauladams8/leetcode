class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int sz = target.size(), next = 1, i = 0;
        vector<string> ans;
        while (i < sz) {
            ans.push_back("Push");
            if (next == target[i]) {
                i++;
            } else {
                ans.push_back("Pop");
            }
            next++;
        }
        return ans;
    }
};