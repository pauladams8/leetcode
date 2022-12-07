typedef long long ll;

class Solution {
public:
    ll dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int sum = skill[0] + skill[skill.size() - 1];
        ll chemistry = 0;
        for (int left = 0, right = skill.size() - 1; left < right; left++, right--)
            if (skill[left] + skill[right] == sum)
                chemistry += skill[left] * skill[right];
            else return -1;
        return chemistry;
    }
};