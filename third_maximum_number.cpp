#include <vector>
#include <set>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::set<int> s;
        for (int n : nums) {
            s.insert(n);
            if (s.size() > 3)
                s.erase(s.begin());
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};