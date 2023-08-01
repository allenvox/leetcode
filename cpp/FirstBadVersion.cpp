#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 private:
  string boolToS(bool x) {
    if (x) return "bad";
    return "good";
  }

  bool isBadVersion(int n, unordered_map<int, bool> umap) { return umap[n]; }

 public:
  int firstBadVersion(int n, unordered_map<int, bool> umap) {
    int lower = 1, upper = n, mid;
    while (lower < upper) {
      mid = (upper + lower) / 2;
      if (isBadVersion(mid, umap))
        upper = mid;
      else
        lower = mid + 1;
    }
    return lower;
  }

  void output(int n, unordered_map<int, bool> umap) {
    cout << "First bad version in { ";
    for (int i = 1; i <= n; i++) {
      cout << i << ":" << boolToS(umap[i]) << " ";
    }
    cout << "} is " << firstBadVersion(n, umap) << endl;
  }
};

int main() {
  Solution s;
  unordered_map<int, bool> umap1;
  umap1[1] = false;
  umap1[2] = false;
  umap1[3] = false;
  umap1[4] = true;
  umap1[5] = true;
  s.output(5, umap1);
  unordered_map<int, bool> umap2;
  umap2[1] = true;
  s.output(1, umap2);
  return 0;
}