#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string files;
  cin >> files;
  vector<long long> blocks;
  long long numFiles = files.size(), cntFiles = 0, cntFreeBlocks = 0;
  for (long long i = 0; i < numFiles; i++) {
    long long size = files[i] - '0';
    if (i % 2 == 0) {
      vector<long long> block(size, cntFiles);
      blocks.insert(blocks.end(), block.begin(), block.end());
      cntFiles++;
    } else {
      vector<long long> block(size, -1);
      blocks.insert(blocks.end(), block.begin(), block.end());
      cntFreeBlocks += size;
    }
  }
  long long numBlocks = blocks.size(), i = 0, j = numBlocks - 1, cntMoved = 0,
            sum = 0;
  while (i < j && cntMoved < cntFreeBlocks) {
    if (blocks[i] != -1) {
      i++;
    } else if (blocks[j] == -1) {
      j--;
    } else {
      swap(blocks[i++], blocks[j--]);
      cntMoved++;
    }
  }
  for (long long i = 0; i < numBlocks && blocks[i] != -1; i++) {
    sum += blocks[i] * i;
  }
  cout << sum << "\n";
}