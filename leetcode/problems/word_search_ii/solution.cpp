class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> children;
    
    TrieNode() : isWord(false), children(26) {}
    
    ~TrieNode() {
        for (TrieNode *child : children)
            delete child;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (string& word : words) {
            TrieNode **node = &root;
            for (char c : word) {
                node = &(*node)->children[c - 'a'];
                if (!*node) *node = new TrieNode();
            }
            (*node)->isWord = true;
        }
        vector<string> present;
        vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size()));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                string prefix;
                findWords(board, root, i, j, seen, prefix, present);
            }
        }
        delete root;
        return present;
    }
private:
    void findWords(vector<vector<char>>& board, TrieNode *node, int row, int col, vector<vector<bool>>& seen, string& prefix, vector<string>& present) {
        if (row < 0 || row >= board.size()) return;
        if (col < 0 || col >= board[row].size()) return;
        if (seen[row][col]) return;
        node = node->children[board[row][col] - 'a'];
        if (!node) return;
        prefix += board[row][col];
        seen[row][col] = true;
        if (node->isWord) present.push_back(prefix);
        node->isWord = false;
        findWords(board, node, row - 1, col, seen, prefix, present);
        findWords(board, node, row, col + 1, seen, prefix, present);
        findWords(board, node, row + 1, col, seen, prefix, present);
        findWords(board, node, row, col - 1, seen, prefix, present);
        prefix.pop_back();
        seen[row][col] = false;
    }
};