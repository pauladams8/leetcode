#include <vector>
#include <iostream>

using namespace std;

bool sumTo(int target, vector<int>& fib, int start, vector<int>& prefix, int sum);

int main() {
    int target;
    cin >> target;
    vector<int> fib = { 1, 2 };
    while (fib.back() < target)
        fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
    vector<int> prefix;
    sumTo(target, fib, 0, prefix, 0);
    for (int n : prefix)
        cout << n << ' ';
    cout << '\n';
}

bool sumTo(int target, vector<int>& fib, int start, vector<int>& prefix, int sum) {
    if (sum >= target)
        return sum == target;
    for (int i = start; i < fib.size(); i++) {
        prefix.push_back(fib[i]);
        sum += fib[i];
        if (sumTo(target, fib, i + 2, prefix, sum))
            return true;
        prefix.pop_back();
        sum -= fib[i];
    }
    return false;
}
