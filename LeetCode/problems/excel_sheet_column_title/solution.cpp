class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            n--;
            ans += 'A' + n % 26;
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};