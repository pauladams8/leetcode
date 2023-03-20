class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> children;
    
    TrieNode() : isWord(false), children(26) {}
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) {
        TrieNode *node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i])
                node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
private:
    bool search(string& word, int start, TrieNode *node) {
        for (int i = start; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++)
                    if (node->children[j] && search(word, i + 1, node->children[j]))
                        return true;
                return false;
            }
            node = node->children[word[i] - 'a'];
            if (!node) return false;
        }
        return node->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */