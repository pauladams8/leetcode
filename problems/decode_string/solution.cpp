class Solution {
public:
    std::string decodeString(std::string s) {
        std::string result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                int kSize = 0;
                for (int j = i - 1; j >= 0 && s[j] - '0' >= 0 && s[j] - '0' <= 9; j--) {
                    result.pop_back();
                    kSize++;
                }
                int k = std::stoi(s.substr(i - kSize, kSize));
                std::cout << "k: " << k;
                std::stack<int> stack;
                stack.push(i);
                int size = 0;
                for (int j = i + 1; j < s.size() && !stack.empty(); j++) {
                    if (s[j] == '[') stack.push(j);
                    if (s[j] == ']') stack.pop();
                    size++;
                }
                std::cout << ", str: " << s.substr(i + 1, size - 1) << '\n';
                std::string decoded = decodeString(s.substr(i + 1, size - 1));
                for (int j = 0; j < k; j++) result += decoded;
                i += size;
            } else result.push_back(s[i]);
        }
        std::cout << "result: " << result << '\n';
        return result;
    }
};