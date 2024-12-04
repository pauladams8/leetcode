#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n1, n2;
    vector<int> list1, list2;
    while (cin >> n1 >> n2) {
        list1.push_back(n1);
        list2.push_back(n2);
    }
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    int n = list1.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(list1[i] - list2[i]);
    }
    cout << ans << "\n";
}