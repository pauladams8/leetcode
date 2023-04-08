class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> children;
    
    TrieNode() : isWord(false), children(26) {}
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode *root = new TrieNode();
        for (string& word : dictionary) {
            TrieNode *node = root;
            for (char c : word) {
                if (!node->children[c - 'a'])
                    node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->isWord = true;
        }
        stringstream ss(sentence);
        string word, ans;
        if (ss >> word)
            ans += replace(root, word);
        while (ss >> word)
            ans += " " + replace(root, word);
        return ans;
    }
    
    string replace(TrieNode *node, string& word) {
        string ans;
        for (char c : word) {
            node = node->children[c - 'a'];
            if (!node)
                return word;
            ans += c;
            if (node->isWord)
                return ans;
        }
        return word;
    }
};