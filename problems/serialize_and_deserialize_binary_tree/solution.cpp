/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    std::string serialize(TreeNode* root) {
        std::stringstream ss;
        std::queue<TreeNode*> q;
        ss << "[";
        if (root) {
            ss << root->val;
            q.push(root->left);
            q.push(root->right);
        }
        while (!q.empty()) {
            root = q.front();
            q.pop();
            ss << ",";
            if (root) {
                ss << root->val;
                q.push(root->left);
                q.push(root->right);
            } else ss << "null";
        }
        ss << "]";
        std::string str = ss.str();
        std::string null = ",null";
        while (str.size() - 2 >= null.size() && str.substr(str.size() - 1 - null.size(), null.size()) == null)
            str.erase(str.size() - 1 - null.size(), null.size());
        return str;
    }

    TreeNode* deserialize(std::string data) {
        if (data[0] == '[') data.erase(data.begin());
        if (data[data.size() - 1] == ']') data.erase(data.end() - 1);
        std::stringstream ss(data);
        std::queue<TreeNode*> q;
        std::string val;
        TreeNode* root = nullptr;
        if (std::getline(ss, val, ',') && val != "null") {
            root = new TreeNode(stoi(val));
            q.push(root);
        }
        while (std::getline(ss, val, ',')) {
            TreeNode* n = q.front();
            q.pop();
            if (val != "null") {
                n->left = new TreeNode(stoi(val));
                q.push(n->left);
            }
            if (std::getline(ss, val, ',') && val != "null") {
                n->right = new TreeNode(stoi(val));
                q.push(n->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));