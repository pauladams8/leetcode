#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> anagrams;
        for (string& str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            if (map.find(sorted) != map.end()) {
                anagrams[map[sorted]].push_back(str);
            } else {
                anagrams.push_back({ str });
                map[sorted] = anagrams.size() - 1;
            }
        }
        return anagrams;
    }
};
