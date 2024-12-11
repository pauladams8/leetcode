#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string input;
  cin >> input;
  long long n = input.size(), cntFree = 0, cnt = 0, sum = 0;
  list<pair<long long, long long>> files;
  for (long long i = 0; i < n; i++) {
    long long size = input[i] - '0';
    if (i % 2 == 0) {
      files.push_back({i / 2, size});
    } else {
      files.push_back({-1, size});
      cntFree++;
    }
  }
  for (auto file = files.rbegin(); file != files.rend(); file++) {
    if (file->first == -1) {
      continue;
    }
    auto free =
        find_if(files.begin(), file.base(), [&](const auto& other) -> bool {
          return other.first == -1 && other.second >= file->second;
        });
    if (free != file.base()) {
      long long leftOver = free->second - file->second;
      *free = *file;
      if (leftOver) {
        files.insert(next(free), {-1, leftOver});
      }
      file->first = -1;
    }
  }
  for (auto it = files.begin(); it != files.end(); it++) {
    auto [id, sz] = *it;
    if (id != -1) {
      // sum += id * cnt + id * cnt + 1 + ... + id * cnt + sz - 1
      // sum += id * (cnt + cnt + 1 + ... + cnt + sz - 1)
      sum += id * (cnt * sz + sz * (sz - 1) / 2);
    }
    cnt += sz;
  }
  cout << sum << "\n";
}