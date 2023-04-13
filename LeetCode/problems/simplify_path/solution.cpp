class Solution {
public:
    string simplifyPath(string path) {
        reverse(path.begin(), path.end());
        stringstream ss(path);
        string segment, ans;
        int skip = 0;
        while (getline(ss, segment, '/')) {
            if (segment.empty())
                continue;
            else if (segment == ".")
                continue;
            else if (segment == "..")
                skip++;
            else if (skip)
                skip--;
            else ans += segment + "/";
        }
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "/" : ans;
    }
};