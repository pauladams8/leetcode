class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> pos(26);
        for (int i = 0; i < order.size(); i++)
            pos[order[i] - 'a'] = i;
        for (int i = 1; i < words.size(); i++)
            if (!isAlienSorted(words, pos, i))
                return false;
        return true;
    }
private:
    bool isAlienSorted(vector<string>& words, vector<int>& pos, int i) {
        for (int j = 0; j < words[i].size() && j < words[i - 1].size(); j++)
            if (pos[words[i][j] - 'a'] > pos[words[i - 1][j] - 'a'])
                return true;
            else if (pos[words[i][j] - 'a'] < pos[words[i - 1][j] - 'a'])
                return false;
        return words[i].size() >= words[i - 1].size();
    }
};