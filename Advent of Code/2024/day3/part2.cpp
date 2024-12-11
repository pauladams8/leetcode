#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int ans = 0, enabled = true;
  string memory((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
  regex mul("(mul|do|don't)\\(((\\d{1,3}),(\\d{1,3}))?\\)");
  auto begin = sregex_iterator(memory.begin(), memory.end(), mul);
  auto end = sregex_iterator();
  for (auto it = begin; it != end; it++) {
    smatch match = *it;
    string op = match[1].str();
    if (op == "mul" && enabled) {
      int num1 = stoi(match[3].str());
      int num2 = stoi(match[4].str());
      ans += num1 * num2;
    } else {
      enabled = op == "do";
    }
  }
  cout << ans << "\n";
}